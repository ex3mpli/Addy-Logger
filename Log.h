#include <Windows.h>

BOOL zCompare(CONST BYTE *zData, CONST BYTE *zMask, CONST CHAR *zzMask)
{
	for(;*zzMask;++zzMask,++zData,++zMask)
	if(*zzMask=='x' && *zData!=*zMask)
	return 0;
	return(*zzMask) == NULL;
}

DWORD FindPattern(DWORD zAddress, DWORD zLen, BYTE *zMask, CHAR *zzMask)
{
	for(DWORD j=0; j<zLen; j++)
	if(zCompare((BYTE*)(zAddress+j),zMask,zzMask))
	return(DWORD)(zAddress+j);	
	return 0;
}

void ex3mpli()
{
  static DWORD CShell, Crossfire;
  
  do {
    xCShell      =   (DWORD)GetModuleHandleW("CShell.dll");
    xCrossfire   =   (DWORD)GetModuleHandleW("crossfire.exe");
  }
  
  while(!xChsell && !xCrossfire);
  
  DWORD Wallhack;
  WallHack = FindPattern((DWORD)GetModuleHandleA("crossfire.exe"), 0x467F74, (PBYTE)"\xB8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\x06\x8B\x50\x18\x8D\x4C\x24\x58", "x????x????xxxxxxxxx");
  WallHack = *(DWORD *)(WallHack + 0x01);
  WallHack + 0xA4;
}

bool ex3mpliReady() {
  if(GetModuleHandleA("CShell.dll") != NULL && GetModuleHandleA("ClientFx.fxd") != NULL)
    return true;
  return 0;
}

void ex3mpliWait() {
  while(!ex3mpliReady())
  Sleep(100);
    while(1) {
	  ex3mpli();
    }
  }

extern "C" __declspec(dllexport) BOOL WINAPI DllMain (HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
  if(dwReason == DLL_PROCESS_ATTACH) {
    DisableThreadLibraryCalls(hDll);
	MessageBoxA(0,"ex3mpli wallhack v1",0,0);
    CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)ex3mpliWait,NULL,NULL,NULL);
    ShellExecute(0,0,L"www.ex3mpli.weebly.com",0,0,SW_SHOW);
  }
  return TRUE;
}
