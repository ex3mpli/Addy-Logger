#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>


using namespace std;

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
for(int i = strlen(dlldirectory); i > 0; i--) { if(dlldirectory[i] == '\\') { dlldirectory[i+1] = 0; break; } }
ofile.open(GetDirectoryFile("Adresses.txt"), ios::app); // here put the output filename
}
