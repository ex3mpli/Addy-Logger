DWORD dwSize;
DWORD dwStartAddress;

bool bCompare2(const BYTE* pData, const BYTE* bMask, const char* szMask)
{
  for(; *szMask; ++szMask, ++pData, ++bMask)
  if(*szMask=='0' && *pData != *bMask)
  return false;
  return (*szMask) == 0;
}
/*************************************************************************
DWORD FindPattern2(DWORD dwAddress,DWORD dwLen,BYTE *bMask,char * szMask)
{
  for(DWORD i = 0; i < dwLen; i++)
  if (bCompare2((BYTE*)(dwAddress + i), bMask, szMask))
  return (DWORD)(dwAddress + i);
  return false;
}
*************************************************************************/

DWORD FindPattern2(BYTE *bMask, char * szMask, int codeOffset, BOOL extract)
{
  for(DWORD i = 0; i < dwSize; i++) {
    if(bCompare2((BYTE*)(dwStartAddress + i), bMask, szMask) {
      if(extract) {
        return *(DWORD*)(dwStartAddress + i + codeOffset);
      }
      else {
        return (DWORD)(dwStartAddress + i + codeOffset);
      }
    }
  }
       return false;
}
