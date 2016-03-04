#include "stdafx.h"
#include "namepipe_srv.h"
#include "log.h"

int startServer()
{
	HANDLE	hPipe;				// HANDLE of pipe
	char	buffer[1024];		// Read buffer
	DWORD	dwRead;				// Contains Numbers of bytes read
	DWORD	dwWritten;			// Contains Numbers of bytes written

	hPipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\Pipe"),
		PIPE_ACCESS_DUPLEX,
		PIPE_TYPE_MESSAGE |
		PIPE_READMODE_MESSAGE |   // FILE_FLAG_FIRST_PIPE_INSTANCE is not needed but forces CreateNamedPipe(..) to fail if the pipe already exists...
		PIPE_WAIT,
		10,
		1024 * 16,
		1024 * 16,
		NMPWAIT_USE_DEFAULT_WAIT,
		NULL);

	while (hPipe != INVALID_HANDLE_VALUE)
	{
		if (ConnectNamedPipe(hPipe, NULL) != FALSE)   // wait for someone to connect to the pipe
		{
			while (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL) != FALSE)
			{
				/* add terminating zero */
				buffer[dwRead] = '\0';

				/* do something with data in buffer */
				printf("%s", buffer);
				logWriteLine(MSG_INFO, buffer);

				WriteFile(hPipe,
					"Hello Pipe\n",
					12,   // = length of string + terminating '\0' !!!
					&dwWritten,
					NULL);
				FlushFileBuffers(hPipe);
				DisconnectNamedPipe(hPipe);
			}
		}

	}

	return 0;
}