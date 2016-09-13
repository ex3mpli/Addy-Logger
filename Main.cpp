#include <windows.h>
#include <stdio.h>
#include "Log.h"
#include "Pattern.h"

bool IsGameReadyForHook()
{
if( GetModuleHandleA( "ClientFX.fxd" ) != NULL 
&& GetModuleHandleA( "CShell.dll" ) != NULL )
return true;

return false;
}

void SearchPatterns(void)
{
while (!IsGameReadyForHook()){
Sleep(50);
}
while(true){
dwSize = 0x500000; 

//Example DWORD dwPlayerPointer = FindPattern((PBYTE)"\x00\x00\x00\x00\x00\x00\x00};", "x????xxxx", 1, true);

DWORD nametags1 = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0x9c0000, (PBYTE)"\x75\x21\x80\x7B\x00\x00", "xxxx??");
DWORD nametags2 = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0x9c0000, (PBYTE)"\x75\x05\xBD\x00\x00\x00\x00\x8B\x17", "xxx????xx");
//-------------------------------------------------------------//
Writelog("//==============Dean-Wingess N3x0n Logger==============\\");
Writelog("//==============Created and developed by:==============\\");
Writelog("//======================Dean-Wingess===================\\");
Writelog("//====================== Neo I.I.I ===================\\");
Writelog("//====================== FlaVour ===================\\");
Writelog("");
Writelog("#define NoReload 0x%X",NoReload);
Writelog("#define FallDamage 0x%X",FallDamage);


Writelog("");
Writelog("//*************************Next log*********************************");



ExitProcess(0);
}
}

BOOL WINAPI DllMain ( HMODULE hDll, DWORD dwReason, LPVOID lpReserved )
{
DisableThreadLibraryCalls(hDll);
if (dwReason==DLL_PROCESS_ATTACH)
{
logging(hDll);
ShellExecuteA(0,"open","http://mpgh.net",0,0,SW_MINIMIZE);
CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)SearchPatterns, NULL, NULL, NULL);
}
return TRUE;
}
