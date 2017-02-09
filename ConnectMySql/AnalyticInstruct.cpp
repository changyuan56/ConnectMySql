//     文件名: AnalyticInstruct。     
//      作者： 常远         
//      描述:  解析字符串        
//      版本:  V1.0.0    
//      日期:  2014/11/08   
/////////////////////////////////////////////////////////////////////     
#include"AnalyticInstruct.h"


AnalyticInstruct::AnalyticInstruct()
{
	// 构造函数
}

AnalyticInstruct::~AnalyticInstruct()
{
	// 析构函数
}

int AnalyticInstruct::cstringToInt(CString str)
{
	str = str.Trim();
	CString temp = str.SpanIncluding("0123456789");
	if(temp != "")
	{
		return atoi(str);
	}
	else
	{
		return -1;
	}
}
bool AnalyticInstruct::AnalyticHex_00(char * source,char *des)
{
	// $EST627,6094652149436,00,2,00\r\n

	// y

	return true;
}


// 车辆启动提醒 命令字：02
bool AnalyticInstruct::AnalyticHex_02(CString obdCode,CString source,char *des)
{
	// $EST627,0123456789ABC,02,19,2014-05-27 09:32:29\r\n
	// insert into carinfo (obdcode,starttime,updatedate,createdate) VALUES ('obdcode','time',now(),now())
	CString temp = source;
	CString tempReturn = "insert into carinfo (obdcode,starttime,updatedate,createdate) values ('";
	int contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	// 消息体长度
	int length = cstringToInt(source.Left(contentLength));
	if(length < 0)
	{
		return false;
	}
	// 开始时间
	source = source.Mid(contentLength + 1);
	CString starttime = source.Trim();

	// 返回SQL文
	tempReturn = tempReturn + obdCode + "','" + starttime + "',now(),now()) ";
	strcpy( des, tempReturn.GetBuffer(tempReturn.GetLength()) );

	return true;
}

// 车辆熄火提醒 命令字：03
bool AnalyticInstruct::AnalyticHex_03(CString obdCode,CString source,char *des)
{
	// :$EST627,0123456789ABC,03,19,2014-05-27 09:38:49, (1,113.999091,22.660566)\r\n
	// insert into carinfo (obdcode,endtime,endposition，updatedate,createdate) VALUES ('obdcode','endtime','endposition',now(),now())
	CString temp = source;
	CString tempReturn = "insert into carinfo (obdcode,endtime,endposition,updatedate,createdate) values ('";
	int contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	// 消息体长度
	int length = cstringToInt(source.Left(contentLength));
	if(length < 0)
	{
		return false;
	}

	// 熄火时间
	source = source.Mid(contentLength + 1);
	contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	CString endtime = source.Mid(0,contentLength).Trim();

	// 熄火位置
	source = source.Mid(contentLength + 1).Trim();
	CString endposition = source;

	// 返回SQL文
	tempReturn = tempReturn + obdCode + "','" + endtime + "','" + endposition+"',now(),now()) ";
	strcpy( des, tempReturn.GetBuffer(tempReturn.GetLength()) );

	return true;
}

// 终端准备进入休眠提醒 命令字：04
bool AnalyticInstruct::AnalyticHex_04(CString obdCode,CString source,char *des)
{
	// :$EST627,0123456789ABC,04,19,2014-05-27 09:43:49\r\n
	// insert into carinfo (obdcode,dormanttime,updatedate,createdate) VALUES ('obdcode','dormanttime',now(),now())
	CString temp = source;
	CString tempReturn = "insert into carinfo (obdcode,dormanttime,updatedate,createdate) values ('";
	int contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	// 消息体长度
	int length = cstringToInt(source.Left(contentLength));
	if(length < 0)
	{
		return false;
	}
	// 开始时间
	source = source.Mid(contentLength + 1);
	CString dormanttime = source.Trim();

	// 返回SQL文
	tempReturn = tempReturn + obdCode + "','" + dormanttime + "',now(),now()) ";
	strcpy( des, tempReturn.GetBuffer(tempReturn.GetLength()) );

	return true;
}

// 终端掉电提醒 命令字：05
bool AnalyticInstruct::AnalyticHex_05(CString obdCode,CString source,char *des)
{
	// :$EST627,0123456789ABC,05,46,2014-05-27 10:24:49,(1,113.999091,22.660566)\r\n
	// insert into carinfo (obdcode,powerdowntime,powerdownposition，updatedate,createdate) VALUES ('obdcode','powerdowntime','powerdownposition',now(),now())
	CString temp = source;
	CString tempReturn = "insert into carinfo (obdcode,powerdowntime,powerdownposition,updatedate,createdate) values ('";
	int contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	// 消息体长度
	int length = cstringToInt(source.Left(contentLength));
	if(length < 0)
	{
		return false;
	}

	// 掉电时间
	source = source.Mid(contentLength + 1);
	contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	CString powerdowntime = source.Mid(0,contentLength).Trim();

	// 掉电位置
	source = source.Mid(contentLength + 1).Trim();
	CString powerdownposition = source;

	// 返回SQL文
	tempReturn = tempReturn + obdCode + "','" + powerdowntime + "','" + powerdownposition+"',now(),now()) ";
	strcpy( des, tempReturn.GetBuffer(tempReturn.GetLength()) );

	return true;
}

// 超速报警 命令字：07
bool AnalyticInstruct::AnalyticHex_07(CString obdCode,CString source,char *des)
{
	// :$EST627,0123456789ABC,07,46,92,2014-05-27 10:49:18,(1,113.999091,22.660566)\r\n
	// insert into carinfo (obdcode,overspeed,overspeedtime,overspeedposition，updatedate,createdate) VALUES ('obdcode','overspeed',overspeedtime,'overspeedposition',now(),now())
	CString temp = source;
	CString tempReturn = "insert into carinfo (obdcode,overspeed,overspeedtime,overspeedposition,updatedate,createdate) values ('";
	int contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	// 消息体长度
	int length = cstringToInt(source.Left(contentLength));
	if(length < 0)
	{
		return false;
	}

	// 超速车速
	source = source.Mid(contentLength + 1);
	contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	CString overspeed = source.Mid(0,contentLength).Trim();

	// 超速时间
	source = source.Mid(contentLength + 1);
	contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	CString overspeedtime = source.Mid(0,contentLength).Trim();

	// 超速位置
	source = source.Mid(contentLength + 1).Trim();
	CString overspeedposition = source;

	// 返回SQL文
	tempReturn = tempReturn + obdCode + "','" + overspeed + "','"  + overspeedtime + "','"+ overspeedposition+"',now(),now()) ";
	strcpy( des, tempReturn.GetBuffer(tempReturn.GetLength()) );

	return true;
}

// 低电压报警 命令字：08
bool AnalyticInstruct::AnalyticHex_08(CString obdCode,CString source,char *des)
{
	// $EST627,0123456789ABC,08,48,10.8,2014-05-27 10:49:18,(1,113.999091,22.660566)\r\n
	// insert into carinfo (obdcode,currentvoltage,lowvoltagetime,lowvoltageposition，updatedate,createdate) VALUES ('obdcode','currentvoltage',lowvoltagetime,'lowvoltageposition',now(),now())
	CString temp = source;
	CString tempReturn = "insert into carinfo (obdcode,currentvoltage,lowvoltagetime,lowvoltageposition,updatedate,createdate) values ('";
	int contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	// 消息体长度
	int length = cstringToInt(source.Left(contentLength));
	if(length < 0)
	{
		return false;
	}

	// 低电压电压
	source = source.Mid(contentLength + 1);
	contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	CString currentvoltage = source.Mid(0,contentLength).Trim();

	// 低电压时间
	source = source.Mid(contentLength + 1);
	contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	CString lowvoltagetime = source.Mid(0,contentLength).Trim();

	// 低电压位置
	source = source.Mid(contentLength + 1).Trim();
	CString lowvoltageposition = source;

	// 返回SQL文
	tempReturn = tempReturn + obdCode + "','" + currentvoltage + "','"  + lowvoltagetime + "','"+ lowvoltageposition+"',now(),now()) ";
	strcpy( des, tempReturn.GetBuffer(tempReturn.GetLength()) );

	return true;
}

bool AnalyticInstruct::AnalyticHex(char *source,char *des)
{
	char startSymbol[7+1] ;    // 起始符
	char obdSn[13+1];          // 设备号
	char hex[2+1];             // 命令字
	CString obdConetnt;
	CString obdCode;

	// 初始化数据
	memset(startSymbol,0x00,sizeof(startSymbol));
	memset(obdSn,0x00,sizeof(obdSn));
	memset(hex,0x00,sizeof(hex));
	obdConetnt = source;

	// 取得数据
	memcpy(startSymbol,source,sizeof(startSymbol)-1);
	memcpy(obdSn,source + sizeof(startSymbol),sizeof(obdSn)-1);
	memcpy(hex,source+sizeof(startSymbol)+sizeof(obdSn),sizeof(hex)-1);
	obdCode = obdSn;

	// 检测起始符号
	if(strncmp(startSymbol,START_SYMBOL,strlen(START_SYMBOL)) != 0)
	{
		return false;
	}
	obdConetnt = obdConetnt.Right(obdConetnt.GetLength()-OBD_START_LENGTH);

	if(strncmp(hex,HEX_00,strlen(HEX_00)) == 0)
	{
		// // $EST627,6094652149436,00,2,00\r\n
	}
	else if(strncmp(hex,HEX_01,strlen(HEX_01)) == 0)
	{

	}
	else if(strncmp(hex,HEX_02,strlen(HEX_02)) == 0)
	{		
	    if(AnalyticHex_02(obdCode,obdConetnt,des))
		{
			return true;
		}
	}
	else if(strncmp(hex,HEX_03,strlen(HEX_03)) == 0)
	{		
		if(AnalyticHex_03(obdCode,obdConetnt,des))
		{
			return true;
		}
	}
	else if(strncmp(hex,HEX_04,strlen(HEX_04)) == 0)
	{		
		if(AnalyticHex_04(obdCode,obdConetnt,des))
		{
			return true;
		}
	}
	else if(strncmp(hex,HEX_05,strlen(HEX_05)) == 0)
	{		
		if(AnalyticHex_05(obdCode,obdConetnt,des))
		{
			return true;
		}
	}
	else if(strncmp(hex,HEX_07,strlen(HEX_07)) == 0)
	{		
		if(AnalyticHex_07(obdCode,obdConetnt,des))
		{
			return true;
		}
	}
	else if(strncmp(hex,HEX_08,strlen(HEX_08)) == 0)
	{		
		if(AnalyticHex_08(obdCode,obdConetnt,des))
		{
			return true;
		}
	}

	return true;
}