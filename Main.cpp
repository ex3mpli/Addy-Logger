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
  DWORD CShell      = (DWORD)GetModuleHandleA("CShell.dll");
  DWORD Crossfire   = (DWORD)GetModuleHandleA("crossfire.exe");
  
  DWORD WeaponMgr = FindPattern(CShell,0xFFFFFF,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\x8B\x04\xB1\xD9\xE8","xx????xxxxx");
  WeaponMgr = *(DWORD*)(WeaponMgr + 0x2) - CShell;
 
  DWORD WallArray = FindPattern(0x400000,0xFFFFFF,(PBYTE)"\x75\x00\x83\x0D\x00\x00\x00\x00\x01\xB8\x00\x00\x00\x00\xE8","x?xx????xx????x");
  WallArray = *(DWORD*)(WallArray + 0xA) - Crossfire;
 
  DWORD PlayerMgr = FindPattern(CShell,0xFFFFFF,(PBYTE)"\x8B\x15\x00\x00\x00\x00\xD9\x80\x00\x00\x00\x00\xD9\x9C\x16\x00\x00\x00\x00\xD9\x80\x00\x00\x00\x00\xA1\x00\x00\x00\x00","xx????xx????xxx????xx????x????");
  PlayerMgr = *(DWORD *)(PlayerMgr + 0x03) - CShell;

  DWORD DamageZone  = FindPattern(CShell,0xFFFFFF,(PBYTE)"\x68\x00\x00\x00\x00\x8D\x4C\x24\x24\x51\x8D\x54\x24\x34\x52","x????xxxxxxxxxx");
  
  DWORD ModelNode = FindPattern(CShell,0xFFFFFF,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\x83\xC4\x04\x89\x44\x0F\x54\x8B\x15\x00\x00\x00\x00\x8B\x04\x17\x3B\xC3\x7C\x0C\x83\xF8\x64\x7D\x07","00????000000000????000000000000");
  ModelNode = *(DWORD*)(ModelNode + 0x2) - CShell;
  
  Writelog("----------------| Crossfire Philippines |----------------");
  Writelog("-----------------| ex3mpli Addy Logger |-----------------");
  Writelog("-----------------------| CShell |---------------------");
  Writelog("#define ChangeWeaponAnimRatio 0x%X",ChangeWeaponAnimRatio);
  Writelog("#define DamageZone \t\t0x00%X",DamageZone);
  Writelog("#define PlayerMgr \t\t0x00%X",PlayerMgr);
  Writelog("#define WeaponMgr \t\t0x00%X",WeaponMgr);
  Writelog("#define ModelNode \t\t0x00%X" ModelNode);
  Writelog("");
  Writelog("-----------------------| Crossfire |---------------------");
  Writelog("#define WallArray \t\t0x00%X",WallArray+0xA4);
  Writelog("------------------| ex3mpli Logger END! |----------------");
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
