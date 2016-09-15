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
  zSize = 0x500000; 
  DWORD CShell      = (DWORD)GetModuleHandleA("CShell.dll");
  DWORD Crossfire   = (DWORD)GetModuleHandleA("crossfire.exe");
  
  DWORD WeaponMgr         = FindPattern(CShell,0xFFFFFF,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\x8B\x04\xB1\xD9\xE8","xx????xxxxx");
  DWORD PlayerBasicInfo   = FindPattern(CShell,0xFFFFFF,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\x83\xC4\x04\x69\xC0\x00\x00\x00\x00", "xx????xxxxx????");
  DWORD WallArray         = FindPattern(0x400000,0xFFFFFF,(PBYTE)"\x75\x00\x83\x0D\x00\x00\x00\x00\x01\xB8\x00\x00\x00\x00\xE8","x?xx????xx????x");
  DWORD DamageZone        = FindPattern(CShell,0xFFFFFF,(PBYTE)"\x68\x00\x00\x00\x00\x8D\x4C\x24\x24\x51\x8D\x54\x24\x34\x52","x????xxxxxxxxxx");
  DWORD ModelNode         = FindPattern(CShell,0xFFFFFF,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\x83\xC4\x04\x89\x44\x0F\x54\x8B\x15\x00\x00\x00\x00\x8B\x04\x17\x3B\xC3\x7C\x0C\x83\xF8\x64\x7D\x07","xx????xxxxxxxxx????xxxxxxxxxxxx");
  DWORD NoReload          = FindPattern(CShell,0xFFFFFF,(PBYTE)"\xD9\x98\x00\x00\x00\x00\x55\xE8\x00\x00\x00\x00", "xx????xx????");
  DWORD FastChange        = FindPattern(CShell,0xFFFFFF,(PBYTE)"\xD9\x9A\x00\x00\x00\x00\x55\xE8\x00\x00\x00\x00","xx????xx????");
  DWORD FastKnife1        = FindPattern(CShell,0xFFFFFF,(PBYTE)"\xD9\x9C\xB9\x00\x00\x00\x00\x83\xC7\x01\x83\xC4\x04\x3B\x7D\x00\x72\xA6","xxx????xxxxxxxxxxx");
  DWORD FastKnife2        = FindPattern(CShell,0xFFFFFF,(PBYTE)"\xD9\x9C\xB8\x00\x00\x00\x00\x8B\x4C\x24\x14","xxx????xxxx");
  DWORD AmmoDamage        = FindPattern(CShell,0xFFFFFF,(PBYTE)"\x68\x00\x00\x00\x00\x8B\xCE\xE8\x00\x00\x00\x00\xD9\x83\x00\x00\x00\x00\x51\x8B\xCE\xD9\x1C\x24\xE8\x00\x00\x00\x00\x8B\xCE\xE8\x00\x00\x00\x00\x8B\xCE\xE8\x00\x00\x00\x00\x6A\x00","x????xxx????xx????xxxxxxx????xxx????xxx????xx");
  
  Writelog("_______________________________________________");
  Writelog("|         | Crossfire Philippines |           |");
  Writelog("|         |    ex3mpli Logger     |           |");
  Writelog("|         | Crossfire Philippines |           |");
  Writelog("_______________________________________________");
  Writelog("");
  Writelog("#define WallArray \t0x00%X",WallArray);
  Writelog("");
  Writelog("#define NoReload \t0x00%X",NoReload);
  Writelog("#define DamageZone \t0x00%X",DamageZone);
  Writelog("#define WeaponMgr \t0x00%X",WeaponMgr);
  Writelog("#define ModelNode \t0x00%X" ModelNode);
  Writelog("#define PlayerBasicInfo \t0x00%X",PlayerBasicInfo);
  Writelog("#deinfe FastChange \t0x00%X",FastChange);
  Writelog("#define FastKnife1 \t0x00%X",FastKnife1);
  Writelog("#define FastKnife2 \t0x00%X",FastKnife2);
  Writelog("#define AmmoDamge \t0x00%X",AmmoDamage);
  ExitProcess(false);
  }
}

extern "C" __declspec(dllexport) BOOL WINAPI DllMain ( HMODULE hDll, DWORD dwReason, LPVOID lpReserved ) {
  DisableThreadLibraryCalls(hDll);
  if (dwReason==DLL_PROCESS_ATTACH) {
  logging(hDll);
  CreateThread(0,0,(LPTHREAD_START_ROUTINE)ex3mpli,0,0,0);
}
  return TRUE;
}
