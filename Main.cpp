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
  
	aIntersectSegment 			= FindPattern2(Crossfire, 0xFFFFFF, (PBYTE)"\x5D\xC3\xCC\x55\x8B\xEC\x8B\x45\x0C\x50\x8B\x4D\x08\x51\x8B\x15\x00\x00\x00\x00","0000000000000000????");
	aIntersectSegment 			= (aIntersectSegment + 0x3) - CShell;
  EndSceneEngine 					= FindPattern2(Crossfire, 0xFFFFFF,(PBYTE)"\x8B\x08\x8B\x91\x00\x00\x00\x00\x50\xFF\xD2\x85\xC0\x8D\x4C\x24\x00\x0F\x94\xC3\xE8\x00\x00\x00\x00\x8A\xC3\x8B", "0000????00000000?0000????000") - Crossfire;
	MidFuncEngine 					= FindPattern2(Crossfire, 0xFFFFFF,(PBYTE)"\x8B\x08\x8B\x91\x00\x00\x00\x00\x57\x6A\x00\x53\x6A\x00\x6A\x00\x6A\x00\x50\xFF\xD2\x5F\x5E\x5D\x5B\xC2\x00\x00", "0000????00?00?0?0?00000000??") - Crossfire;
  
	DWORD WallArray 				= FindPattern2(Crossfire, 0xFFFFFF,(PBYTE)"\x75\x00\x83\x0D\x00\x00\x00\x00\x01\xB8\x00\x00\x00\x00\xE8","0?00????00????0");
  WallArray 							= *(DWORD*)(WallArray + 0xA) - Crossfire;
	
  DWORD WeaponMgr 				= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\x8B\x04\xB1\xD9\xE8","00????00000");
  WeaponMgr 							= *(DWORD*)(WeaponMgr + 0x2) - CShell;
  
	ModelNode 							= FindPattern2(CShell,0xFFFFFF,(PBYTE)"\x8B\x15\x00\x00\x00\x00\x83\xC4\x20\x33\xED\x33\xFF\x8B\x4C\x24\x30\x3B\xCB","00????0000000000000");
	ModelNode 							= *(DWORD*)(ModelNode + 0x2) - CShell;
  
	DWORD SeeGhost 					= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\x75\xFF\x83\x0D\xFF\xFF\xFF\xFF\x01\xB8\xFF\xFF\xFF\xFF\xE8","0?00????00????0");
  SeeGhost 								= *(DWORD*)(SeeGhost + 0xA)  - Crossfire;
  
	DWORD aLTClientShell 		= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\x50\x8D\x44\x24\x10\x50\x81\xC1\x00\x00\x00\x00","00????00000000????");
  aLTClientShell 					= *(DWORD*)(aLTClientShell + 0x2)  - CShell;
  
	DWORD CPlayerStart 			= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\x0F\xB6\x8E\x00\x00\x00\x00\x69\xC9\x00\x00\x00\x00\x8A\x84\x31\x00\x00\x00\x00\x5E\xC3","000????00????000????00");
  CPlayerStart 						= *(DWORD*)(CPlayerStart + 0x3)  - CShell;
  
	DWORD MEOffset 					= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\x8A\x84\x31\x00\x00\x00\x00\x5E\xC3","000????00");
  MEOffset 								= *(DWORD*)(MEOffset + 0x3)  - CShell;
  
	DWORD CPlayerSize 			= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\x69\xC9\x00\x00\x00\x00\x8A\x84\x31\x00\x00\x00\x00\x5E\xC3","00????000????00");
  CPlayerSize	 						= *(DWORD*)(CPlayerSize + 0x2)  - CShell;
  
	DWORD aLTModel 					= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\x8B\x44\x24\x0C\x8B\x11","00????000000");
  aLTModel 								= *(DWORD*)(aLTModel + 0x2)  - CShell;
  
	DWORD aCLTPlayerClient 	= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\xB9\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x68\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x59\xC3\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\x6A\x04\x68\x00\x00\x00\x00","0????0????0????0????000000000000000????");
  aCLTPlayerClient 				= *(DWORD*)(aCLTPlayerClient + 0x1)  - CShell;
  
	DWORD C4PlantTime	 			= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\xD9\x5C\x08\x7C\x8B\x4C\x24\x30", "00000000");
  C4PlantTime 						= *(DWORD *)(C4PlantTime + 0x03)  - CShell;
 
	DWORD PlayerMgr 				= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\x83\xC4\x04\x69\xC0\x00\x00\x00\x00\xD9\x5C\x08\x0C\x8B\x4C\x24\x30", "00????00000????00000000");
  PlayerMgr 							= (DWORD)*(DWORD *)(PlayerMgr + 0x2)  - CShell;
  
	DWORD BagMgr 						= FindPattern2(CShell, 0xFFFFFF, (PBYTE)"\x89\x3D\x00\x00\x00\x00\x68\x00\x00\x00\x00", "00????0????");
	if(BagMgr) BagMgr				= *(DWORD*) (BagMgr + 0x2)  - CShell;
  
	DWORD Bypass28_3 				= FindPattern2(CShell,0xFFFFFF, (PBYTE)"\x8B\x44\x24\x04\x81\xEC\x00\x00\x00\x00\x83\xF8\xFF\x0F\x84\x00\x00\x00\x00\x56\x50\xE8\x00\x00\x00\x00", "000000????00000????000????");
  Bypass28_3 							= (Bypass28_3 + 0x15) - CShell;
	
	DWORD AmmoDamage 				= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\xD9\x5C\x24\x18\xD9\x44\x24\x18\x8B\x06\xD9\x98",  "000000000000");
	AmmoDamage 							=  *(DWORD*)(AmmoDamage + 12) - CShell;
	
	DWORD Offset_Yaw 				= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\xD9\x81\x00\x00\x00\x00\xD9\x58\x04\xD9\x81\x00\x00\x00\x00\xD9\x58\x08\xC2\x04\x00", "00????00000????000000");
	Offset_Yaw 							= *(DWORD*) (Offset_Yaw + 2) - CShell;
	
	DWORD Offset_Pitch			= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\xD9\x81\x00\x00\x00\x00\xD9\x18\xD9\x81\x00\x00\x00\x00\xD9\x58\x04\xD9\x81\x00\x00\x00\x00\xD9\x58\x08\xC2\x04\x00", "00????0000????00000????000000");
	Offset_Pitch 						= *(DWORD*) (Offset_Pitch + 2) - CShell;
	
	DWORD DamagePerMeter 		= FindPattern2(CShell,0xFFFFFF,(PBYTE)"\xA1\x00\x00\x00\x00\xD9\x58\x00\x83\xC4\x00","0????00?00?");
	DamagePerMeter 					= *(DWORD*)(DamagePerMeter + 0x1) - CShell;
	
	DWORD aILTClient 				= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\x8B\x11\x8B\x82\x00\x00\x00\x00", "00????0000????");
	if(aILTClient)aILTClient= *(DWORD*) (aILTClient + 0x2) - CShell;
	
	DWORD PTCOffset 				= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\x8B\x88\x00\x00\x00\x00\x68\x00\x00\x00\x00\xFF\xD1\x8B\x0D\x00\x00\x00\x00\x8B\x11\x8B\x82\x00\x00\x00\x00", "00????0????0000????0000????");
	if(PTCOffset)PTCOffset 	= *(DWORD*) (PTCOffset + 0x2) - CShell;
	
	DWORD Bypass31_0 				= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\xE8\x00\x00\x00\x00\x83\xC4\x04\x85\xC0\x74\x48\x8B\x0D\x00\x00\x00\x00\x8B\x11", "0????000000000????00");
	DWORD FastChange        = FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\xD9\x9A\x00\x00\x00\x00\x55\xE8\x00\x00\x00\x00","00????00????") - CShell;
  DWORD FastKnife1        = FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\xD9\x9C\xB9\x00\x00\x00\x00\x83\xC7\x01\x83\xC4\x04\x3B\x7D\x00\x72\xA6","000????00000000000") - CShell;
  DWORD FastKnife2        = FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\xD9\x9C\xB8\x00\x00\x00\x00\x8B\x4C\x24\x14","000????0000") - CShell;
  DWORD NoSpread          = FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\xD9\x9C\x39\xAC\x26\x00\x00","00000??") - CShell;
  DWORD NoWeight          = FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\xD9\x99\xCC\x0A\x00\x00", "0000??") - CShell;
  DWORD Overlay           = FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\xD9\x9C\xB9\x28\x24\x00\x00", "00000??") - CShell;
  DWORD pCrouchSpeed      = FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\xD9\x5C\x08\x0C", "0000") - CShell;
  DWORD KnifeRange        = FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\xD9\x9C\xB9\x28\x0A\x00\x00", "00000??") - CShell;
  DWORD KnifeDamage       = FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\x8B\x94\x39\xB4\xF5\xFF\xFF", "0000000") - CShell;
  DWORD NoKnockBack       = FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\xD9\x9C\xBA\x00\x00\x00\x00\x83\xC7\x01\x83\xC4\x04\x3B\x7D\x00\x72\x9D",  "000????00000000000") - CShell;
  DWORD GutlingDelay      = FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\xD9\x99\x00\x00\x00\x00\x83\xC4\x04\x68\x00\x00\x00\x00\x53\xE8\x00\x00\x00\x00\x83\xC4\x08\x85\xC0\x74\x42","00????0000????00????0000000") - CShell;
  MoveSpeedPenalty        = FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\xD9\x9A\x00\x00\x00\x00\x55\xE8\x00\x00\x00\x00\x83\xC4\x08\x85\xC0","00????00????00000") - CShell;
  VisibleZoneIndex        = FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\x56\x69\x73\x69\x62\x6C\x65\x5A\x6F\x6E\x65\x49\x6E\x64\x65\x78","0000000000000000")- CShell;
  DamagePerSec    	 			= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\x44\x61\x6D\x61\x67\x65\x50\x65\x72\x53\x65\x63","000000000000") - CShell;
  DWORD oCLTPlayerClient 	= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\x39\x55\x00\x74\x00\x8B\x4D\x00\x8B\x01\x8B\x90\x00\x00\x00\x00\xFF\xD2","00?0?00?0000????00") - CShell;
	DWORD NoReload 					= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\xD9\x98\x00\x00\x00\x00\x55\xE8\x00\x00\x00\x00", "00????00????") - CShell;
	DWORD PlayerBasicInfo 	= FindPattern2(CShell, 0xFFFFFF,(PBYTE)"\x8B\x0D\x00\x00\x00\x00\x83\xC4\x04\x69\xC0\x00\x00\x00\x00", "00????00000????") - CShell;
  DamageZone       				= FindPattern2(CShell, 0xFFFFFF, (PBYTE)"\x44\x61\x6D\x61\x67\x65\x5A\x6F\x6E\x65","0000000000") - CShell;
	
	
  Writelog("    //==============================================\\");
  Writelog("   //============ Crossfire Philippines =============\\");
  Writelog("  //================= Exempli Logger =================\\");
  Writelog(" //============== Crossfire Philippines ===============\\");
  Writelog("//======================================================\\");
  Writelog("");
  Writelog("//=================== Crossfire Engine ===================\\");
  Writelog("");
  Writelog("  #define WallArray \t0x00%X ",WallArray);
  Writelog("  #define SeeGhost \t0x00%X ",SeeGhost);
  Writelog("  #define aIntersectSegment \t0x00%X ",aIntersectSegment);
  Writelog("  #define EndSceneEngine \t0x00%X ",EndSceneEngine);
  Writelog("  #define MidFuncEngine \t0x00%X ",MidFuncEngine);
  Writelog("");
  Writelog("//===================== Push To Console =====================\\");
  Writelog(" ");
  Writelog("  #define aILTClient \t0x00%X ",aILTClient);
  Writelog("  #define PTCOffset \t0x00%X ",PTCOffset);
  Writelog("");
  Writelog("//===================== PlayerBasicInfo =====================\\");
  Writelog("");
  Writelog("  #define PlayerBasicInfo \t0x00%X ",PlayerBasicInfo);
  Writelog("  #define C4PlantTime \t0x00%X ",C4PlantTime);
  Writelog("  #define PlayerMgr \t0x00%X ",PlayerMgr);
  Writelog("");
  Writelog("//=========================== ESP ===========================\\");
  Writelog(" ");
  Writelog("  #define aLTClientShell \t0x00%X ",aLTClientShell);
  Writelog("  #define CPlayerStart \t0x00%X ",CPlayerStart);
  Writelog("  #define MEOffset \t0x00%X ",MEOffset);
  Writelog("  #define CPlayerSize \t0x00%X ",CPlayerSize);
  Writelog("  #define aLTModel \t0x00%X ",aLTModel);
  Writelog("  #define aCLTPlayerClient \t0x00%X ",aCLTPlayerClient);
  Writelog("  #define oCLTPlayerClient \t0x00%X ",oCLTPlayerClient);
  Writelog("");
  Writelog("//======================== Weapon Log ========================\\");
  Writelog("");
  Writelog("  #define WeaponMgr \t0x%.8X ",WeaponMgr);
  Writelog("  #define NoReload \t0x00%X ",NoReload);
  Writelog("  #deinfe FastChange \t0x00%X ",FastChange);
  Writelog("  #define FastKnife1 \t0x00%X ",FastKnife1);
  Writelog("  #define FastKnife2 \t0x00%X ",FastKnife2);
  Writelog("  #define AmmoDamge \t0x00%X ",AmmoDamage);
  Writelog("  #define NoSpread \t0x00%X ",NoSpread);
  Writelog("  #define NoWeight \t0x00%X ",NoWeight);
  Writelog("  #define Overlay \t0x00%X ",Overlay);
  Writelog("  #define PlayerCrouchSpeed \t0x00%X ",pCrouchSpeed);
  Writelog("  #define KnifeRange \t0x00%X ",KnifeRange);
  Writelog("  #define KnifeDamage \t0x00%X ",KnifeDamage);
  Writelog("  #define GutlingDelay \t0x00%X ",GutlingDelay);
  Writelog("");
  Writelog("//=========================== Other ===========================\\");
  Writelog(" ");
  Writelog("  #define ModelNode \t0x00%X ",ModelNode);
  Writelog("  #define BagMgr 0x00%X ",BagMgr);
  Writelog("  #define DamageZone \t0x00%X ",DamageZone);
  Writelog("  #define NoKnockBack \t0x00%X ",NoKnockBack);
  Writelog("  #define Bypass28_3 \t0x00%X ",Bypass28_3);
	Writelog("  #define Bypass31_0 \t0x00%X ",Bypass31_0);
  Writelog("  #define MoveSpeedPenalty \t0x00%X ",MoveSpeedPenalty);
  Writelog("  #define VisibleZoneIndex \t0x00%X ",VisibleZoneIndex);
  Writelog("  #define DamagePerSec \t0x00%X ",DamagePerSec);
  Writelog("  #define DamagePerMeter \t0x00%X ",DamagePerMeter);
  Writelog("  #define Offset_Yaw \t0x00%X ",Offset_Yaw);
  Writelog("  #define Offset_Pitch \t0x00%X ",Offset_Pitch);
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
