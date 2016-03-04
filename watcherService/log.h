enum FileOptions
{
	FILE_UNINITIALIZED,
	FILE_APPEND, 
	FILE_OVERWRITE
}option;

enum ReturnStatus
{
	RET_UNINITIALIZED,
	RET_OK,
	RET_ERROR
}returnStatus;

enum MsgType
{
	MSG_UNINITIALIZED,
	MSG_INFO,
	MSG_WARNING,
	MSG_ERROR,
	MSG_DEBUG
}msgType;

char logfilePath;								//Path to .log including File and Path

int logStart(char *filename, enum FileOptions); // Opens File on Path and appends or overwrites the old File
int logEnd();	                    // Ends logging
int logGetDate();								// Returns time
int logWriteLine(enum MsgType , char *message);			    // Writes text to log file and insert a line break 

