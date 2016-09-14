#include <windows.h>
#include <stdio.h>
#include "Log.h"
#include "Pattern.h"

bool ex3mpliReady() {
  if (GetModuleHandleA( "ClientFx.fxd" ) != NULL && GetModuleHandleA( "CShell.dll" ) != NULL)
    return true;
  return false;
}

void ex3mpli()
{
  while (!ex3mpliReady()) {
  Sleep(100);
}
  while(1) {
  dwSize = 0x500000; 
  
  DWORD aIntersectSegment       = FindPattern((DWORD)GetModuleHandleA("crossfire.exe"),0xFFFFFF,(PBYTE)"\x5D\xC3\xCC\x55\x8B\xEC\x8B\x45\x0C\x50\x8B\x4D\x08\x51\x8B\x15\x00\x00\x00\x00","xxxxxxxxxxxxxxxx????");
  DWORD NoReload                = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\x75\x21\x80\x7B\x00\x00","xxxx??");
  DWORD NoFallDamage            = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\x75\x05\xBD\x00\x00\x00\x00\x8B\x17","xxx????xx");
  DWORD WeaponMgr               = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\x8B\x04\xB1\xD9\xE8","xx????xxxxx");
  DWORD WallArray               = FindPattern(0x400000,0xFFFFFF,(PBYTE)"\x75\x00\x83\x0D\x00\x00\x00\x00\x01\xB8\x00\x00\x00\x00\xE8","x?xx????xx????x");
  DWORD PlayerMgr               = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\x8B\x15\x00\x00\x00\x00\xD9\x80\x00\x00\x00\x00\xD9\x9C\x16\x00\x00\x00\x00\xD9\x80\x00\x00\x00\x00\xA1\x00\x00\x00\x00","xx????xx????xxx????xx????x????");
  DWORD DamageZone              = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\x68\x00\x00\x00\x00\x8D\x4C\x24\x24\x51\x8D\x54\x24\x34\x52","x????xxxxxxxxxx");
  DWORD ChangeWeaponAnimRatio   = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\xD9\x9A\x00\x00\x00\x00\x55","xx????x");
  DWORD ModelNode               = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\x83\xC4\x04\x89\x44\x0F\x54\x8B\x15\x00\x00\x00\x00\x8B\x04\x17\x3B\xC3\x7C\x0C\x83\xF8\x64\x7D\x07","xx????xxxxxxxxx????xxxxxxxxxxxx");
  
  Writelog("\t\t----------| Crossfire Philippines |----------");
  Writelog("\t\t--------------| ex3mpli Logger |--------------");
  Writelog("");
  Writelog("");
  Writelog("\t\t-----------| CShell |---------");
  Writelog("\t\t#define ModelNode 0x%X",ModelNode);
  Writelog("\t\t#define ChangeWeaponAnimRatio 0x%X",ChangeWeaponAnimRatio);
  Writelog("\t\t#define DamageZone 0x%X",DamageZone);
  Writelog("\t\t#define PlayerMgr 0x%X",PlayerMgr);
  Writelog("\t\t#define WeaponMgr 0x%X",WeaponMgr);
  Writelog("\t\t#define NoReload 0x%X",NoReload);
  Writelog("\t\t#define FallDamage 0x%X",FallDamage);
  Writelog("");
  Writelog("\t\t-----------| Crossfire |---------");
  Writelog("\t\t#define WallArray 0x%%X",WallArray);
  Writelog("\t\t-----------| ex3mpli Logger END! |---------");
  ExitProcess(false);
  }
}



extern "C" __declspec(dllexport) BOOL WINAPI DllMain ( HMODULE hDll, DWORD dwReason, LPVOID lpReserved ) {
  DisableThreadLibraryCalls(hDll);
  if (dwReason==DLL_PROCESS_ATTACH) {
  logging(hDll);
  CreateThread(0,0,(LPTHREAD_START_ROUTINE)ex3mpli,0,0,0);
}
  if(dwReason==DLL_PROCESS_DETACH) {
    exit(0);
  }
  return TRUE;
}
