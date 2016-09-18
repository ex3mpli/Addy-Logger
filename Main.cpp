#include <windows.h>
#include <stdio.h>
#include "Log.h"
#include "Pattern.h"

bool ex3mpliReady() {
  if (GetModuleHandleA("ClientFx.fxd") != 0 && GetModuleHandleA("CShell.dll") != 0)
    return 1;
  return 0;
}

void ex3mpli() {
while(!ex3mpliReady) {
  Sleep(100)
} while(1) {
  zSize = 0x500000; 
  
  DWORD WeaponMgr = FindPattern(CShell,0xFFFFFF,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\x8B\x04\xB1\xD9\xE8","xx????xxxxx");
  WeaponMgr = *(DWORD*)(WeaponMgr + 0x2);
  
  DWORD PlayerBasicInfo = FindPattern(CShell,0xFFFFFF,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\x83\xC4\x04\x69\xC0\x00\x00\x00\x00", "xx????xxxxx????");
  
  DWORD WallArray = FindPattern(0x400000,0xFFFFFF,(PBYTE)"\x75\x00\x83\x0D\x00\x00\x00\x00\x01\xB8\x00\x00\x00\x00\xE8","x?xx????xx????x");
  WallArray = *(DWORD*)(WallArray + 0xA);
  
  DWORD DamageZone = FindPattern(CShell,0xFFFFFF,(PBYTE)"\x68\x00\x00\x00\x00\x8D\x4C\x24\x24\x51\x8D\x54\x24\x34\x52","x????xxxxxxxxxx");
  
  DWORD ModelNode = FindPattern(CShell,0xFFFFFF,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\x83\xC4\x04\x89\x44\x0F\x54\x8B\x15\x00\x00\x00\x00\x8B\x04\x17\x3B\xC3\x7C\x0C\x83\xF8\x64\x7D\x07","xx????xxxxxxxxx????xxxxxxxxxxxx");
  ModelNode = *(DWORD*)(ModelNode + 0x2);
  
  DWORD NoReload = FindPattern(CShell,0xFFFFFF,(PBYTE)"\xD9\x98\x00\x00\x00\x00\x55\xE8\x00\x00\x00\x00", "xx????xx????");
  
  DWORD SeeGhost = FindPattern(Crossfire, 0xFFFFFF, (BYTE *)"\x75\xFF\x83\x0D\xFF\xFF\xFF\xFF\x01\xB8\xFF\xFF\xFF\xFF\xE8","x?xx????xx????x");
  SeeGhost = *(DWORD*)(SeeGhost + 0xA);
  
  DWORD aLTClientShell = FindPattern(CShell, 0xFFFFFF, (PBYTE)"\x8B\x0D\x00\x00\x00\x00\x50\x8D\x44\x24\x10\x50\x81\xC1\x00\x00\x00\x00","xx????xxxxxxxx????");
  aLTClientShell = *(DWORD*)(aLTClientShell + 0x2);
  
  DWORD CPlayerStart = FindPattern(CShell,0xFFFFFF,(PBYTE)"\x0F\xB6\x8E\x00\x00\x00\x00\x69\xC9\x00\x00\x00\x00\x8A\x84\x31\x00\x00\x00\x00\x5E\xC3","xxx????xx????xxx????xx");
  CPlayerStart = *(DWORD*)(CPlayerStart + 0x3);
  
  DWORD MEOffset = FindPattern(CShell,0xFFFFFF,(PBYTE)"\x8A\x84\x31\x00\x00\x00\x00\x5E\xC3","xxx????xx");
  MEOffset = *(DWORD*)(MEOffset + 0x3);
  
  DWORD CPlayerSize = FindPattern(CShell,0xFFFFFF,(PBYTE)"\x69\xC9\x00\x00\x00\x00\x8A\x84\x31\x00\x00\x00\x00\x5E\xC3","xx????xxx????xx");
  CPlayerSize = *(DWORD*)(CPlayerSize + 0x2);
  
  DWORD aLTModel = FindPattern(CShell, 0xFFFFFF, (PBYTE)"\x8B\x0D\x00\x00\x00\x00\x8B\x44\x24\x0C\x8B\x11","xx????xxxxxx");
  aLTModel = *(DWORD*)(aLTModel + 0x2);
  
  DWORD aCLTPlayerClient = FindPattern(CShell, 0xFFFFFF, (PBYTE)"\xB9\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x68\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x59\xC3\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\x6A\x04\x68\x00\x00\x00\x00","x????x????x????x????xxxxxxxxxxxxxxx????");
  aCLTPlayerClient = *(DWORD*)(aCLTPlayerClient + 0x1);
  
  DWORD oCLTPlayerClient = FindPattern(CShell, 0xFFFFFF, (PBYTE)"\x39\x55\x00\x74\x00\x8B\x4D\x00\x8B\x01\x8B\x90\x00\x00\x00\x00\xFF\xD2","xx?x?xx?xxxx????xx");
  
  DWORD C4PlantTime = FindPattern(CShell, 0xFFFFFF, (PBYTE)"\xD9\x5C\x08\x7C\x8B\x4C\x24\x30", "xxxxxxxx");
  C4PlantTime = *(DWORD *)(C4PlantTime + 0x03);
  
  DWORD PlayerMgr = FindPattern(CShell, 0xFFFFFF, (PBYTE)"\x8B\x0D\x00\x00\x00\x00\x83\xC4\x04\x69\xC0\x00\x00\x00\x00\xD9\x5C\x08\x0C\x8B\x4C\x24\x30", "xx????xxxxx????xxxxxxxx");
  PlayerMgr = (DWORD)*(DWORD *)(PlayerMgr + 0x2);
  
  DWORD BagMgr = FindPattern(CShell, 0xFFFFFF,(PBYTE)"\x89\x3D\x00\x00\x00\x00\x68\x00\x00\x00\x00", "xx????x????");
  BagMgr = *(DWORD*)(BagMgr + 0x2);

  DWORD FastChange        = FindPattern(CShell,0xFFFFFF,(PBYTE)"\xD9\x9A\x00\x00\x00\x00\x55\xE8\x00\x00\x00\x00","xx????xx????");
  DWORD FastKnife1        = FindPattern(CShell,0xFFFFFF,(PBYTE)"\xD9\x9C\xB9\x00\x00\x00\x00\x83\xC7\x01\x83\xC4\x04\x3B\x7D\x00\x72\xA6","xxx????xxxxxxxxxxx");
  DWORD FastKnife2        = FindPattern(CShell,0xFFFFFF,(PBYTE)"\xD9\x9C\xB8\x00\x00\x00\x00\x8B\x4C\x24\x14","xxx????xxxx");
  DWORD AmmoDamage        = FindPattern(CShell,0xFFFFFF,(PBYTE)"\x68\x00\x00\x00\x00\x8B\xCE\xE8\x00\x00\x00\x00\xD9\x83\x00\x00\x00\x00\x51\x8B\xCE\xD9\x1C\x24\xE8\x00\x00\x00\x00\x8B\xCE\xE8\x00\x00\x00\x00\x8B\xCE\xE8\x00\x00\x00\x00\x6A\x00","x????xxx????xx????xxxxxxx????xxx????xxx????xx");
  DWORD NoSpread          = FindPattern(CShell, 0xFFFFFF, (PBYTE)"\xD9\x9C\x39\xAC\x26\x00\x00","xxxxx??");
  DWORD NoWeight          = (CShell, 0xFFFFFF, (PBYTE)"\xD9\x99\xCC\x0A\x00\x00", "xxxx??");
  DWORD Overlay           = (CShell, 0xFFFFFF, (PBYTE)"\xD9\x9C\xB9\x28\x24\x00\x00", "xxxxx??");
  DWORD pCrouchSpeed      = (CShell, 0xFFFFFF, (PBYTE)"\xD9\x5C\x08\x0C", "xxxx");
  DWORD KnifeRange        = (CShell, 0xFFFFFF, (PBYTE)"\xD9\x9C\xB9\x28\x0A\x00\x00", "xxxxx??");
  DWORD KnifeDamage       = (CShell, 0xFFFFFF, (PBYTE)"\x8B\x94\x39\xB4\xF5\xFF\xFF", "xxxxxxx");
  DWORD NoKnockBack       = (CShell, 0xFFFFFF, (PBYTE)"\xD9\x9C\xBA\x00\x00\x00\x00\x83\xC7\x01\x83\xC4\x04\x3B\x7D\x00\x72\x9D",  "xxx????xxxxxxxxxxx");
  DWORD GutlingDelay      = (CShell, 0xFFFFFF, (PBYTE)"\xD9\x99\x00\x00\x00\x00\x83\xC4\x04\x68\x00\x00\x00\x00\x53\xE8\x00\x00\x00\x00\x83\xC4\x08\x85\xC0\x74\x42","xx????xxxx????xx????xxxxxxx");
  
  DWORD aIntersectSegment = FindPattern(Crossfire,0xFFFFFF, (PBYTE)"\x5D\xC3\xCC\x55\x8B\xEC\x8B\x45\x0C\x50\x8B\x4D\x08\x51\x8B\x15\x00\x00\x00\x00","xxxxxxxxxxxxxxxx????");
  
  DWORD aILTClient        = FindPattern(CShell, 0xFFFFFF, (PBYTE)"\x8B\x0D\x00\x00\x00\x00\x8B\x11\x8B\x82\x00\x00\x00\x00","xx????xxxx????");
  
  DWORD PTCOffset         = FindPattern(CShell,0xFFFFFF,(PBYTE)"\x8B\x88\x00\x00\x00\x00\x68\x00\x00\x00\x00\xFF\xD1\x8B\x0D\x00\x00\x00\x00\x8B\x11\x8B\x82\x00\x00\x00\x00","xx????x????xxxx????xxxx????");
  
  Writelog("    //==============================================\\");
  Writelog("   //============ Crossfire Philippines =============\\");
  Writelog("  //================= Exempli Logger =================\\");
  Writelog(" //============== Crossfire Philippines ===============\\");
  Writelog("//======================================================\\");
  Writelog("");
  Writelog("//=================== Crossfire Engine ===================\\");
  Writelog("");
  Writelog("  #define WallArray \t0x00%X",WallArray) - Crossfire;
  Writelog("  #define SeeGhost \t0x00%X",SeeGhost) - Crossfire;
  Writelog("  #define aIntersectSegment \t0x00%X",aIntersectSegment) - Crossfire;
  Writelog("");
  Writelog("//===================== Push To Console =====================\\");
  Writelog(" ");
  Writelog("  #define aILTClient \t0x00%X",aILTClient) - CShell;
  Writelog("  #define PTCOffset \t0x00%X",PTCOffset) - CShell;
  Writelog("");
  Writelog("//===================== PlayerBasicInfo =====================\\");
  Writelog("");
  Writelog("  #define PlayerBasicInfo \t0x00%X",PlayerBasicInfo) - CShell - CShell;
  Writelog("  #define C4PlantTime \t0x00%X",C4PlantTime) - CShell;
  Writelog("  #define PlayerMgr \t0x00%X",PlayerMgr) - CShell;
  Writelog("");
  Writelog("//=========================== ESP ===========================\\");
  Writelog(" ");
  Writelog("  #define aLTClientShell \t0x00%X",aLTClientShell) - CShell;
  Writelog("  #define CPlayerStart \t0x00%X",CPlayerStart) - CShell;
  Writelog("  #define MEOffset \t0x00%X",MEOffset) - CShell;
  Writelog("  #define CPlayerSize \t0x00%X",CPlayerSize) - CShell;
  Writelog("  #define aLTModel \t0x00%X",aLTModel) - CShell;
  Writelog("  #define aCLTPlayerClient \t0x00%X",aCLTPlayerClient) - CShell;
  Writelog("  #define oCLTPlayerClient \t0x00%X",oCLTPlayerClient) - CShell;
  Writelog("");
  Writelog("//======================== Weapon Log ========================\\");
  Writelog("");
  Writelog("  #define WeaponMgr \t0x00%X",WeaponMgr) - CShell;
  Writelog("  #define NoReload \t0x00%X",NoReload) - CShell;
  Writelog("  #deinfe FastChange \t0x00%X",FastChange) - CShell;
  Writelog("  #define FastKnife1 \t0x00%X",FastKnife1) - CShell;
  Writelog("  #define FastKnife2 \t0x00%X",FastKnife2) - CShell;
  Writelog("  #define AmmoDamge \t0x00%X",AmmoDamage) - CShell;
  Writelog("  #define NoSpread \t0x00%X",NoSpread) - CShell;
  Writelog("  #define NoWeight \t0x00%X",NoWeight) - CShell;
  Writelog("  #define Overlay \t0x00%X",Overlay) - CShell;
  Writelog("  #define PlayerCrouchSpeed \t0x00%X",pCrouchSpeed) - CShell;
  Writelog("  #define KnifeRange \t0x00%X",KnifeRange) - CShell;
  Writelog("  #define KnifeDamage \t0x00%X",KnifeDamage) - CShell;
  Writelog("  #define GutlingDelay \t0x00%X",GutlingDelay) - CShell;
  Writelog("");
  Writelog("//=========================== Other ===========================\\");
  Writelog(" ");
  Writelog("  #define ModelNode \t0x00%X",ModelNode) - CShell;
  Writelog("  #define BagMgr 0x00%X",BagMgr) - CShell;
  Writelog("  #define DamageZone \t0x00%X",DamageZone) - CShell;
  Writelog("  #define NoKnockBack \t0x00%X",NoKnockBack) - CShell;
  ExitProcess(0);
  }
}

extern "C" __declspec(dllexport) BOOL WINAPI DllMain (HMODULE hDll, DWORD dwReason, LPVOID lpReserved) {
  DisableThreadLibraryCalls(hDll);
  if (dwReason==DLL_PROCESS_ATTACH) {
  logging(hDll);
  CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)ex3mpli,NULL,NULL,NULL);
}
  return TRUE;
}
