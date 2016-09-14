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
  dwSize = 0x400000; 

//Example DWORD dwPlayerPointer = FindPattern((PBYTE)"\x00\x00\x00\x00\x00\x00\x00};", "x????xxxx", 1, true);

  DWORD nametags1 = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0x9c0000, (PBYTE)"\x75\x21\x80\x7B\x00\x00", "xxxx??");
  DWORD nametags2 = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0x9c0000, (PBYTE)"\x75\x05\xBD\x00\x00\x00\x00\x8B\x17", "xxx????xx");
//-------------------------------------------------------------//
  Writelog("//=================== ex3mpli Logger ===================\\");
  Writelog("//============== Created and developed by: ==============\\");
  Writelog("//====================== ex3mpli ===================\\");
  Writelog("//====================== Crossfire ===================\\");
  Writelog("//====================== Philippines ===================\\");
  Writelog("");
  Writelog("#define NoReload 0x%X",NoReload);
  Writelog("#define FallDamage 0x%X",FallDamage);


  Writelog("");
  Writelog("//*************************Next log*********************************");



  ExitProcess(false);
  }
}

extern "C" __declspec(dllexport) BOOL WINAPI DllMain ( HMODULE hDll, DWORD dwReason, LPVOID lpReserved ) {
  DisableThreadLibraryCalls(hDll);
  if (dwReason==DLL_PROCESS_ATTACH) {
  logging(hDll);
  CreateThread(0,0,(LPTHREAD_START_ROUTINE)SearchPatterns,0,0,0);
}
  return TRUE;
}
