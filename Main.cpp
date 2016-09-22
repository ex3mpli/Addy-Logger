#include <windows.h>
#include <stdio.h>
#include "Log.h"
#include "Pattern.h"

bool ExempliReady() {
  if (GetModuleHandleA("ClientFx.fxd") != NULL && GetModuleHandleA("CShell.dll") != NULL)
    return true;
  return false;
}

void Exempli() {
while(!ExempliReady()) {
  Sleep(100);
} while(1) {
  dwSize = 0x500000; 
  
  DWORD CShell    = (DWORD)GetModuleHandle("CShell.dll");
  DWORD Crossfire = (DWORD)GetModuleHandle("crossfire.exe");
  
  DWORD WeaponMgr = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\x8B\x04\xB1\xD9\xE8","00????00000") - CShell;
  //WeaponMgr = *(DWORD*)(WeaponMgr + 0x2) - CShell;
  
  DWORD PlayerBasicInfo = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\x83\xC4\x04\x69\xC0\x00\x00\x00\x00", "00????00000????") - CShell;
  
  DWORD WallArray = FindPattern((DWORD)GetModuleHanl("crossfire.exe"),0xFFFFFF,(PBYTE)"\x75\x00\x83\x0D\x00\x00\x00\x00\x01\xB8\x00\x00\x00\x00\xE8","0?00????00????0") - Crossfire;
  //WallArray = *(DWORD*)(WallArray + 0xA) - Crossfire;
  
  DWORD DamageZone = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\x68\x00\x00\x00\x00\x8D\x4C\x24\x24\x51\x8D\x54\x24\x34\x52","0????0000000000") - CShell;
  
  DWORD ModelNode = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\x83\xC4\x04\x89\x44\x0F\x54\x8B\x15\x00\x00\x00\x00\x8B\x04\x17\x3B\xC3\x7C\x0C\x83\xF8\x64\x7D\x07","00????000000000????000000000000") - CShell;
  //ModelNode = *(DWORD*)(ModelNode + 0x2)  - CShell;
  
  DWORD NoReload = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\xD9\x98\x00\x00\x00\x00\x55\xE8\x00\x00\x00\x00", "00????00????") - CShell;
  
  DWORD SeeGhost = FindPattern((DWORD)GetModuleHanl("crossfire.exe"), 0xFFFFFF, (BYTE *)"\x75\xFF\x83\x0D\xFF\xFF\xFF\xFF\x01\xB8\xFF\xFF\xFF\xFF\xE8","0?00????00????0") - Crossfire;
  //SeeGhost = *(DWORD*)(SeeGhost + 0xA)  - Crossfire;
  
  DWORD aLTClientShell = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0xFFFFFF, (PBYTE)"\x8B\x0D\x00\x00\x00\x00\x50\x8D\x44\x24\x10\x50\x81\xC1\x00\x00\x00\x00","00????00000000????") - CShell;
  //aLTClientShell = *(DWORD*)(aLTClientShell + 0x2)  - CShell;
  
  DWORD CPlayerStart = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\x0F\xB6\x8E\x00\x00\x00\x00\x69\xC9\x00\x00\x00\x00\x8A\x84\x31\x00\x00\x00\x00\x5E\xC3","000????00????000????00") - CShell;
  //CPlayerStart = *(DWORD*)(CPlayerStart + 0x3)  - CShell;
  
  DWORD MEOffset = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\x8A\x84\x31\x00\x00\x00\x00\x5E\xC3","000????00") - CShell;
  //MEOffset = *(DWORD*)(MEOffset + 0x3)  - CShell;
  
  DWORD CPlayerSize = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\x69\xC9\x00\x00\x00\x00\x8A\x84\x31\x00\x00\x00\x00\x5E\xC3","00????000????00") - CShell;
  //CPlayerSize = *(DWORD*)(CPlayerSize + 0x2)  - CShell;
  
  DWORD aLTModel = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0xFFFFFF, (PBYTE)"\x8B\x0D\x00\x00\x00\x00\x8B\x44\x24\x0C\x8B\x11","00????000000") - CShell;
  //aLTModel = *(DWORD*)(aLTModel + 0x2)  - CShell;
  
  DWORD aCLTPlayerClient = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0xFFFFFF, (PBYTE)"\xB9\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x68\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x59\xC3\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\x6A\x04\x68\x00\x00\x00\x00","0????0????0????0????000000000000000????") - CShell;
  //aCLTPlayerClient = *(DWORD*)(aCLTPlayerClient + 0x1)  - CShell;
  
  DWORD oCLTPlayerClient = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0xFFFFFF, (PBYTE)"\x39\x55\x00\x74\x00\x8B\x4D\x00\x8B\x01\x8B\x90\x00\x00\x00\x00\xFF\xD2","00?0?00?0000????00") - CShell;
  
  DWORD C4PlantTime = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0xFFFFFF, (PBYTE)"\xD9\x5C\x08\x7C\x8B\x4C\x24\x30", "00000000") - CShell;
  //C4PlantTime = *(DWORD *)(C4PlantTime + 0x03)  - CShell;
  
  DWORD PlayerMgr = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0xFFFFFF, (PBYTE)"\x8B\x0D\x00\x00\x00\x00\x83\xC4\x04\x69\xC0\x00\x00\x00\x00\xD9\x5C\x08\x0C\x8B\x4C\x24\x30", "00????00000????00000000") - CShell;
  //PlayerMgr = (DWORD)*(DWORD *)(PlayerMgr + 0x2)  - CShell;
  
  DWORD BagMgr = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0xFFFFFF,(PBYTE)"\x89\x3D\x00\x00\x00\x00\x68\x00\x00\x00\x00", "00????0????") - CShell;
  //BagMgr = *(DWORD*)(BagMgr + 0x2)  - CShell;

  DWORD FastChange        = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\xD9\x9A\x00\x00\x00\x00\x55\xE8\x00\x00\x00\x00","00????00????") - CShell;
  DWORD FastKnife1        = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\xD9\x9C\xB9\x00\x00\x00\x00\x83\xC7\x01\x83\xC4\x04\x3B\x7D\x00\x72\xA6","000????00000000000") - CShell;
  DWORD FastKnife2        = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\xD9\x9C\xB8\x00\x00\x00\x00\x8B\x4C\x24\x14","000????0000") - CShell;
  DWORD AmmoDamage        = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\x68\x00\x00\x00\x00\x8B\xCE\xE8\x00\x00\x00\x00\xD9\x83\x00\x00\x00\x00\x51\x8B\xCE\xD9\x1C\x24\xE8\x00\x00\x00\x00\x8B\xCE\xE8\x00\x00\x00\x00\x8B\xCE\xE8\x00\x00\x00\x00\x6A\x00","0????000????00????0000000????000????000????00") - CShell;
  DWORD NoSpread          = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0xFFFFFF, (PBYTE)"\xD9\x9C\x39\xAC\x26\x00\x00","00000??") - CShell;
  DWORD NoWeight          = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0xFFFFFF, (PBYTE)"\xD9\x99\xCC\x0A\x00\x00", "0000??") - CShell;
  DWORD Overlay           = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0xFFFFFF, (PBYTE)"\xD9\x9C\xB9\x28\x24\x00\x00", "00000??") - CShell;
  DWORD pCrouchSpeed      = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0xFFFFFF, (PBYTE)"\xD9\x5C\x08\x0C", "0000") - CShell;
  DWORD KnifeRange        = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0xFFFFFF, (PBYTE)"\xD9\x9C\xB9\x28\x0A\x00\x00", "00000??") - CShell;
  DWORD KnifeDamage       = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0xFFFFFF, (PBYTE)"\x8B\x94\x39\xB4\xF5\xFF\xFF", "0000000") - CShell;
  DWORD NoKnockBack       = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0xFFFFFF, (PBYTE)"\xD9\x9C\xBA\x00\x00\x00\x00\x83\xC7\x01\x83\xC4\x04\x3B\x7D\x00\x72\x9D",  "000????00000000000") - CShell;
  DWORD GutlingDelay      = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0xFFFFFF, (PBYTE)"\xD9\x99\x00\x00\x00\x00\x83\xC4\x04\x68\x00\x00\x00\x00\x53\xE8\x00\x00\x00\x00\x83\xC4\x08\x85\xC0\x74\x42","00????0000????00????0000000") - CShell;
  
  DWORD aIntersectSegment = FindPattern((DWORD)GetModuleHanl("crossfire.exe"),0xFFFFFF, (PBYTE)"\x5D\xC3\xCC\x55\x8B\xEC\x8B\x45\x0C\x50\x8B\x4D\x08\x51\x8B\x15\x00\x00\x00\x00","0000000000000000????") - Crossfire;
  
  DWORD aILTClient        = FindPattern((DWORD)GetModuleHandleA("CShell.dll"), 0xFFFFFF, (PBYTE)"\x8B\x0D\x00\x00\x00\x00\x8B\x11\x8B\x82\x00\x00\x00\x00","00????0000????") - CShell;
  
  DWORD PTCOffset         = FindPattern((DWORD)GetModuleHandleA("CShell.dll"),0xFFFFFF,(PBYTE)"\x8B\x88\x00\x00\x00\x00\x68\x00\x00\x00\x00\xFF\xD1\x8B\x0D\x00\x00\x00\x00\x8B\x11\x8B\x82\x00\x00\x00\x00","00????0????0000????0000????") - CShell;
  
  Writelog("    //==============================================\\");
  Writelog("   //============ Crossfire Philippines =============\\");
  Writelog("  //================= Exempli Logger =================\\");
  Writelog(" //============== Crossfire Philippines ===============\\");
  Writelog("//======================================================\\");
  Writelog("");
  Writelog("//=================== Crossfire Engine ===================\\");
  Writelog("");
  Writelog("  #define WallArray \t0x00%X",WallArray);
  Writelog("  #define SeeGhost \t0x00%X",SeeGhost);
  Writelog("  #define aIntersectSegment \t0x00%X",aIntersectSegment);
  Writelog("");
  Writelog("//===================== Push To Console =====================\\");
  Writelog(" ");
  Writelog("  #define aILTClient \t0x00%X",aILTClient);
  Writelog("  #define PTCOffset \t0x00%X",PTCOffset);
  Writelog("");
  Writelog("//===================== PlayerBasicInfo =====================\\");
  Writelog("");
  Writelog("  #define PlayerBasicInfo \t0x00%X",PlayerBasicInfo);
  Writelog("  #define C4PlantTime \t0x00%X",C4PlantTime);
  Writelog("  #define PlayerMgr \t0x00%X",PlayerMgr);
  Writelog("");
  Writelog("//=========================== ESP ===========================\\");
  Writelog(" ");
  Writelog("  #define aLTClientShell \t0x00%X",aLTClientShell);
  Writelog("  #define CPlayerStart \t0x00%X",CPlayerStart);
  Writelog("  #define MEOffset \t0x00%X",MEOffset);
  Writelog("  #define CPlayerSize \t0x00%X",CPlayerSize);
  Writelog("  #define aLTModel \t0x00%X",aLTModel);
  Writelog("  #define aCLTPlayerClient \t0x00%X",aCLTPlayerClient);
  Writelog("  #define oCLTPlayerClient \t0x00%X",oCLTPlayerClient);
  Writelog("");
  Writelog("//======================== Weapon Log ========================\\");
  Writelog("");
  Writelog("  #define WeaponMgr \t0x00%X",WeaponMgr);
  Writelog("  #define NoReload \t0x00%X",NoReload);
  Writelog("  #deinfe FastChange \t0x00%X",FastChange);
  Writelog("  #define FastKnife1 \t0x00%X",FastKnife1);
  Writelog("  #define FastKnife2 \t0x00%X",FastKnife2);
  Writelog("  #define AmmoDamge \t0x00%X",AmmoDamage);
  Writelog("  #define NoSpread \t0x00%X",NoSpread);
  Writelog("  #define NoWeight \t0x00%X",NoWeight);
  Writelog("  #define Overlay \t0x00%X",Overlay);
  Writelog("  #define PlayerCrouchSpeed \t0x00%X",pCrouchSpeed);
  Writelog("  #define KnifeRange \t0x00%X",KnifeRange);
  Writelog("  #define KnifeDamage \t0x00%X",KnifeDamage);
  Writelog("  #define GutlingDelay \t0x00%X",GutlingDelay);
  Writelog("");
  Writelog("//=========================== Other ===========================\\");
  Writelog(" ");
  Writelog("  #define ModelNode \t0x00%X",ModelNode);
  Writelog("  #define BagMgr 0x00%X",BagMgr);
  Writelog("  #define DamageZone \t0x00%X",DamageZone);
  Writelog("  #define NoKnockBack \t0x00%X",NoKnockBack);
  ExitProcess(0);
  }
}

extern "C" __declspec(dllexport) BOOL WINAPI DllMain (HMODULE hDll, DWORD wReason, LPVOID lpReserved) {
  DisableThreadLibraryCalls(hDll);
  if (wReason==DLL_PROCESS_ATTACH) {
  logging(hDll);
  CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)Exempli,NULL,NULL,NULL);
}
  return TRUE;
}
