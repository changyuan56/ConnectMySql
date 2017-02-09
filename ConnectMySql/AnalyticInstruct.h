/////////////////////////////////////////////////////////////////////     
//     �ļ���: AnalyticInstruct��     
//      ���ߣ� ��Զ         
//      ����:  �����ַ���        
//      �汾:  V1.0.0    
//      ����:  2014/11/08   
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