/***********************************************
char *GetDirectoryFile(char *filename);
void __cdecl Writelog (const char * fmt, ...);
void logging(HMODULE hDll);
***********************************************/
#pragma once

#include "stdafx.h"

class Log
{
public:
	Log(char* filename, bool enabled);
	~Log();
	void Close();
	void Write(const char* message, LogLevel level = kInfo);
	void Writef(const char* format, uint32_t value);

private:
	static char* ToString(LogLevel level);
	static LogLevel FromString(const std::string& level);
	static void NowTimeString(char* out);

private:
	bool logging_enabled_;
	std::ofstream out_file_stream_;
};
