#include<stdio.h>
#include "AnalyticInstruct.h"

void main()
{

	// HEX = 02
	//char *src = "$EST627,0123456789ABC,02,19,2014-05-27 09:32:29\r\n";
	// HEX = 03
	//char *src = ":$EST627,0123456789ABC,03,19,2014-05-27 09:38:49, (1,113.999091,22.660566)\r\n";
	// HEX = 04
	//char *src = "$EST627,0123456789ABC,04,19,2014-05-27 09:43:49\r\n";
	// HEX = 05
	//char *src = "$EST627,0123456789ABC,05,46,2014-05-27 10:24:49,(1,113.999091,22.660566)\r\n";
	//// HEX = 06
	//char *src = "$EST627,0123456789ABC,02,19,2014-05-27 09:32:29\r\n";
	//// HEX = 07
	//char *src = "$EST627,0123456789ABC,07,46,92,2014-05-27 10:49:18,(1,113.999091,22.660566)\r\n";
	//// HEX = 08
	char *src = "$EST627,0123456789ABC,08,48,10.8,2014-05-27 10:49:18,(1,113.999091,22.660566)\r\n";
	//// HEX = 09
	//char *src = "$EST627,0123456789ABC,02,19,2014-05-27 09:32:29\r\n";
	//// HEX = 10
	//char *src = "$EST627,0123456789ABC,02,19,2014-05-27 09:32:29\r\n";
	//// HEX = 11
	//char *src = "$EST627,0123456789ABC,02,19,2014-05-27 09:32:29\r\n";

	char *des = (char*)malloc(1024);
	int te = sizeof(des);
	te = strlen(des);
	memset(des,0x00,1024);

	AnalyticInstruct  *test = new AnalyticInstruct();

	bool test1 = test->AnalyticHex(src,des);
}