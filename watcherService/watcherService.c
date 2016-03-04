// watcherService.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "stdafx.h"
#include "watcherService.h"
#include "log.h"
#include "namepipe_srv.h"

#define APP_NAME "watcher"
#define APP_VERSION "0.1"

// Pfad und Name der exe-Datei
char lifebeat_filename[MAX_PATH];
// Pfad und Name der ini-Datei
char logFilename[MAX_PATH];
// Overwrite or append to logfile
enum FileOptions logFileOption = FILE_OVERWRITE;
// Message Buffer
char msgBuffer[MAX_PATH];
// Handle of the server thread
HANDLE  namedpipe_server_handle;	

int main()
{
	printf(make_family_filename(logFilename, MAX_PATH, "gol"));
	printf("\r\n");
	printf(make_app_filename(lifebeat_filename, MAX_PATH, "LIFEBEAT.TXT"));
	printf("\r\n");
	Sleep(1000);

	logStart(logFilename, logFileOption);
	strcpy(msgBuffer, "Test of writing\n");
	logWriteLine(MSG_INFO, msgBuffer);
	
	strcpy(msgBuffer, "Start Server\n");
	logWriteLine(MSG_INFO, msgBuffer);
	startServer();
	//namedpipe_server_handle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)startServer, NULL, CREATE_SUSPENDED, NULL);
	logEnd();
    return 0;
}