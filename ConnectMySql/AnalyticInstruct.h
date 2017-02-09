/////////////////////////////////////////////////////////////////////     
//     文件名: AnalyticInstruct。     
//      作者： 常远         
//      描述:  解析字符串        
//      版本:  V1.0.0    
//      日期:  2014/11/08   
///////////////////////////////////////////////////////////////////// 
#ifndef _ANALYTIC_INSTRUCT_H
#define _ANALYTIC_INSTRUCT_H

#include <afx.h>
#include "CommonConstant.h" 
#include <memory>



class AnalyticInstruct
{
	public:
		AnalyticInstruct();
		virtual ~AnalyticInstruct();
private:
	static int  cstringToInt(CString str);
	static bool  AnalyticHex_00(char *source,char *des);
	static bool  AnalyticHex_02(CString obdCode,CString src,char *des);
	static bool  AnalyticHex_03(CString obdCode,CString src,char *des);
	static bool  AnalyticHex_04(CString obdCode,CString src,char *des);
	static bool  AnalyticHex_05(CString obdCode,CString src,char *des);
	static bool  AnalyticHex_07(CString obdCode,CString src,char *des);
	static bool  AnalyticHex_08(CString obdCode,CString src,char *des);
public:
	static bool AnalyticHex(char *source,char *des);
};

#endif