#ifndef __BF3D_Common_Log_Header__
#define __BF3D_Common_Log_Header__

#include <stdio.h>
#include <time.h>
#include <string.h>

#include <iostream>
#include <iomanip>

using namespace std;

#pragma warning(disable:4996)

const char LOG_FILE_NAME[] = "WeNext.log";

#define DEBUG_OUT_TO_CONSOLE
#define DEBUG_OUT_TO_LOG_FILE


/**
* Log
*/
inline void Log(char* buf)
{
	char tmp_buf[10000];

#ifdef DEBUG_OUT_TO_LOG_FILE
	FILE *fp = NULL;

	time_t tval;
	time(&tval);
	struct tm *currTM = localtime(&tval);

	//-=-=-=-= File -=-=-=-=//
	fp = fopen(LOG_FILE_NAME, "at");

	if (!fp){
		return;
	} //if

	sprintf(tmp_buf, "[%d/%02d/%02d %02d:%02d:%02d] %s\n", currTM->tm_year + 1900,
		currTM->tm_mon + 1, currTM->tm_mday, currTM->tm_hour, currTM->tm_min, currTM->tm_sec, buf);

	fprintf(fp, tmp_buf);

	//-=-=-=-= Close -=-=-=-=-=//
	fclose(fp);
#endif // #ifdef DEBUG_OUT_TO_LOG_FILE

#ifdef DEBUG_OUT_TO_CONSOLE
	std::cout << buf << endl;
#endif // #ifdef DEBUG_OUT_TO_CONSOLE
} //Log

#endif

