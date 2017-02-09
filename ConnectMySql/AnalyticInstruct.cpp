//     �ļ���: AnalyticInstruct��     
//      ���ߣ� ��Զ         
//      ����:  �����ַ���        
//      �汾:  V1.0.0    
//      ����:  2014/11/08   
/////////////////////////////////////////////////////////////////////     
#include"AnalyticInstruct.h"


AnalyticInstruct::AnalyticInstruct()
{
	// ���캯��
}

AnalyticInstruct::~AnalyticInstruct()
{
	// ��������
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


// ������������ �����֣�02
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
	// ��Ϣ�峤��
	int length = cstringToInt(source.Left(contentLength));
	if(length < 0)
	{
		return false;
	}
	// ��ʼʱ��
	source = source.Mid(contentLength + 1);
	CString starttime = source.Trim();

	// ����SQL��
	tempReturn = tempReturn + obdCode + "','" + starttime + "',now(),now()) ";
	strcpy( des, tempReturn.GetBuffer(tempReturn.GetLength()) );

	return true;
}

// ����Ϩ������ �����֣�03
bool AnalyticInstruct::AnalyticHex_03(CString obdCode,CString source,char *des)
{
	// :$EST627,0123456789ABC,03,19,2014-05-27 09:38:49, (1,113.999091,22.660566)\r\n
	// insert into carinfo (obdcode,endtime,endposition��updatedate,createdate) VALUES ('obdcode','endtime','endposition',now(),now())
	CString temp = source;
	CString tempReturn = "insert into carinfo (obdcode,endtime,endposition,updatedate,createdate) values ('";
	int contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	// ��Ϣ�峤��
	int length = cstringToInt(source.Left(contentLength));
	if(length < 0)
	{
		return false;
	}

	// Ϩ��ʱ��
	source = source.Mid(contentLength + 1);
	contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	CString endtime = source.Mid(0,contentLength).Trim();

	// Ϩ��λ��
	source = source.Mid(contentLength + 1).Trim();
	CString endposition = source;

	// ����SQL��
	tempReturn = tempReturn + obdCode + "','" + endtime + "','" + endposition+"',now(),now()) ";
	strcpy( des, tempReturn.GetBuffer(tempReturn.GetLength()) );

	return true;
}

// �ն�׼�������������� �����֣�04
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
	// ��Ϣ�峤��
	int length = cstringToInt(source.Left(contentLength));
	if(length < 0)
	{
		return false;
	}
	// ��ʼʱ��
	source = source.Mid(contentLength + 1);
	CString dormanttime = source.Trim();

	// ����SQL��
	tempReturn = tempReturn + obdCode + "','" + dormanttime + "',now(),now()) ";
	strcpy( des, tempReturn.GetBuffer(tempReturn.GetLength()) );

	return true;
}

// �ն˵������� �����֣�05
bool AnalyticInstruct::AnalyticHex_05(CString obdCode,CString source,char *des)
{
	// :$EST627,0123456789ABC,05,46,2014-05-27 10:24:49,(1,113.999091,22.660566)\r\n
	// insert into carinfo (obdcode,powerdowntime,powerdownposition��updatedate,createdate) VALUES ('obdcode','powerdowntime','powerdownposition',now(),now())
	CString temp = source;
	CString tempReturn = "insert into carinfo (obdcode,powerdowntime,powerdownposition,updatedate,createdate) values ('";
	int contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	// ��Ϣ�峤��
	int length = cstringToInt(source.Left(contentLength));
	if(length < 0)
	{
		return false;
	}

	// ����ʱ��
	source = source.Mid(contentLength + 1);
	contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	CString powerdowntime = source.Mid(0,contentLength).Trim();

	// ����λ��
	source = source.Mid(contentLength + 1).Trim();
	CString powerdownposition = source;

	// ����SQL��
	tempReturn = tempReturn + obdCode + "','" + powerdowntime + "','" + powerdownposition+"',now(),now()) ";
	strcpy( des, tempReturn.GetBuffer(tempReturn.GetLength()) );

	return true;
}

// ���ٱ��� �����֣�07
bool AnalyticInstruct::AnalyticHex_07(CString obdCode,CString source,char *des)
{
	// :$EST627,0123456789ABC,07,46,92,2014-05-27 10:49:18,(1,113.999091,22.660566)\r\n
	// insert into carinfo (obdcode,overspeed,overspeedtime,overspeedposition��updatedate,createdate) VALUES ('obdcode','overspeed',overspeedtime,'overspeedposition',now(),now())
	CString temp = source;
	CString tempReturn = "insert into carinfo (obdcode,overspeed,overspeedtime,overspeedposition,updatedate,createdate) values ('";
	int contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	// ��Ϣ�峤��
	int length = cstringToInt(source.Left(contentLength));
	if(length < 0)
	{
		return false;
	}

	// ���ٳ���
	source = source.Mid(contentLength + 1);
	contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	CString overspeed = source.Mid(0,contentLength).Trim();

	// ����ʱ��
	source = source.Mid(contentLength + 1);
	contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	CString overspeedtime = source.Mid(0,contentLength).Trim();

	// ����λ��
	source = source.Mid(contentLength + 1).Trim();
	CString overspeedposition = source;

	// ����SQL��
	tempReturn = tempReturn + obdCode + "','" + overspeed + "','"  + overspeedtime + "','"+ overspeedposition+"',now(),now()) ";
	strcpy( des, tempReturn.GetBuffer(tempReturn.GetLength()) );

	return true;
}

// �͵�ѹ���� �����֣�08
bool AnalyticInstruct::AnalyticHex_08(CString obdCode,CString source,char *des)
{
	// $EST627,0123456789ABC,08,48,10.8,2014-05-27 10:49:18,(1,113.999091,22.660566)\r\n
	// insert into carinfo (obdcode,currentvoltage,lowvoltagetime,lowvoltageposition��updatedate,createdate) VALUES ('obdcode','currentvoltage',lowvoltagetime,'lowvoltageposition',now(),now())
	CString temp = source;
	CString tempReturn = "insert into carinfo (obdcode,currentvoltage,lowvoltagetime,lowvoltageposition,updatedate,createdate) values ('";
	int contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	// ��Ϣ�峤��
	int length = cstringToInt(source.Left(contentLength));
	if(length < 0)
	{
		return false;
	}

	// �͵�ѹ��ѹ
	source = source.Mid(contentLength + 1);
	contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	CString currentvoltage = source.Mid(0,contentLength).Trim();

	// �͵�ѹʱ��
	source = source.Mid(contentLength + 1);
	contentLength = source.Find(',');
	if(contentLength < 0)
	{
		return false;
	}
	CString lowvoltagetime = source.Mid(0,contentLength).Trim();

	// �͵�ѹλ��
	source = source.Mid(contentLength + 1).Trim();
	CString lowvoltageposition = source;

	// ����SQL��
	tempReturn = tempReturn + obdCode + "','" + currentvoltage + "','"  + lowvoltagetime + "','"+ lowvoltageposition+"',now(),now()) ";
	strcpy( des, tempReturn.GetBuffer(tempReturn.GetLength()) );

	return true;
}

bool AnalyticInstruct::AnalyticHex(char *source,char *des)
{
	char startSymbol[7+1] ;    // ��ʼ��
	char obdSn[13+1];          // �豸��
	char hex[2+1];             // ������
	CString obdConetnt;
	CString obdCode;

	// ��ʼ������
	memset(startSymbol,0x00,sizeof(startSymbol));
	memset(obdSn,0x00,sizeof(obdSn));
	memset(hex,0x00,sizeof(hex));
	obdConetnt = source;

	// ȡ������
	memcpy(startSymbol,source,sizeof(startSymbol)-1);
	memcpy(obdSn,source + sizeof(startSymbol),sizeof(obdSn)-1);
	memcpy(hex,source+sizeof(startSymbol)+sizeof(obdSn),sizeof(hex)-1);
	obdCode = obdSn;

	// �����ʼ����
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