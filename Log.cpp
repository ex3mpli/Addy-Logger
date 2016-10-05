#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>

using namespace std;
/*****************************
ofstream ofile;
char dlldirectory[320];

char *GetDirectoryFile(char *filename)
{
static char path[320];
strcpy(path, dlldirectory);
strcat(path, filename);
return path;
}

void __cdecl Writelog(const char *fmt, ...)
{
if(ofile != NULL)
{
if(!fmt) { return; }
va_list va_alist;
char logbuf[256] = {0};
va_start (va_alist, fmt);
_vsnprintf (logbuf+strlen(logbuf), sizeof(logbuf) - strlen(logbuf), fmt, va_alist);
va_end (va_alist);
ofile << logbuf << endl;
}}

void logging(HMODULE hDll){
DisableThreadLibraryCalls(hDll);
GetModuleFileNameA(hDll, dlldirectory, 512);
for(int j = strlen(dlldirectory); j > 0; j--) { if(dlldirectory[j] == '\\') { dlldirectory[j+1] = 0; break; } }
ofile.open(GetDirectoryFile("Logger.txt"), ios::app);
}
**************************/

Log::Log(char* filename, bool enabled)
{
	// might disable this in releases, they don't have to know everything
	this->logging_enabled_ = enabled;
	this->out_file_stream_.open(filename, std::fstream::out);
}

Log::~Log()
{
	this->Close();
}

void Log::Close()
{
	this->out_file_stream_.close();
}

void Log::Write(const char* message, LogLevel level)
{
	if (!this->logging_enabled_)
		return;

	char buffer[200];
	Log::NowTimeString(buffer);
	this->out_file_stream_ << "- " << buffer;
	this->out_file_stream_ << " " << Log::ToString(level) << ":\t";
	this->out_file_stream_ << message << std::endl;
	this->out_file_stream_.flush();
}

void Log::Writef(const char* format, uint32_t value)
{
	if (!this->logging_enabled_)
		return;

	char buffer[1024];

	sprintf_s(buffer, format, value);

	this->Write(buffer, kInfo);
}

char* Log::ToString(LogLevel level)
{
	static char* const buffer[] = { "ERROR", "WARNING", "INFO", "DEBUG" };
	return buffer[level];
}

LogLevel Log::FromString(const std::string& level)
{
	if (level == "DEBUG")
		return kDebug;
	if (level == "INFO")
		return kInfo;
	if (level == "WARNING")
		return kWarning;
	if (level == "ERROR")
		return kError;
	
	// use info if something unknown was specified
	return kInfo;
}

void Log::NowTimeString(char* out)
{
	char buffer[200];
	if (!GetTimeFormatA(LOCALE_INVARIANT, 0, 0, "HH':'mm':'ss", buffer, 200))
		return;

	static DWORD first = GetTickCount();
	sprintf_s(out, 100, "%s.%03ld", buffer, (int32_t)(GetTickCount() - first) % 1000);
}
