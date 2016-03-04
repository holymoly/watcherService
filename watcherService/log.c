#pragma once
#include "stdafx.h"
#include "log.h"

FILE *fp = NULL;

int logStart(char *filename, enum FileOptions option)
{
	returnStatus = RET_OK;
	if (option == FILE_APPEND)
	{
		fp = fopen(filename, "a");
	}
	else 
	{
		fp = fopen(filename, "w");
	}
	if (!fp) 
	{
		returnStatus = RET_ERROR; // fp could not open file
		return returnStatus;
	}
	logWriteLine(MSG_INFO, "Start Logging\n");

	return returnStatus;
}

int logEnd() 
{
	logWriteLine(MSG_INFO, "End of logging\n");
	fclose(fp);

	if(!fp)
	{
		returnStatus = RET_OK; // fp closed file
	}
	else
	{
		returnStatus = RET_ERROR; // fp could not close file
	}
	return returnStatus;
}    

// Writes Date to file
int logGetDate() 
{
	returnStatus = RET_OK;
	time_t now = time(NULL);
	char *dt = ctime(&now);
	//remove linefeed
	dt[strlen(dt) - 1] = '\0';
	fprintf(fp, "%s : " , dt);
	return returnStatus;
}

int logWriteLine(enum MsgType msgType, char *message)
{
	logGetDate();
	fprintf(fp, "%d :%s", msgType, message);
	returnStatus = RET_OK;
	return returnStatus;
}