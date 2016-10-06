DWORD dwSize;
DWORD dwStartAddress;

BOOL bCompare(const BYTE* pData, const BYTE* bMask, const char* szMask)
{
for(;*szMask;++szMask,++pData,++bMask)
{
if(*szMask == '0' && *pData != *bMask)
return 0;
}
return (*szMask)==0;
}
DWORD FindPattern2(BYTE *bMask, char * szMask, int codeOffset, BOOL extract)
{
for(DWORD i = 0; i < dwSize; i++)
{
if(bCompare((BYTE*)(dwStartAddress + i),bMask,szMask))
{
if(extract) 
{
return *(DWORD*)(dwStartAddress + i + codeOffset);
}
else 
{
return (DWORD)(dwStartAddress + i + codeOffset);
}
}
}
return NULL;
}
