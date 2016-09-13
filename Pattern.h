DWORD dwSize;
DWORD dwStartAddress;

BOOL bCompare(const BYTE* pData, const BYTE* bMask, const char* szMask)
{
for(;*szMask;++szMask,++pData,++bMask)
{
if(*szMask == 'x' && *pData != *bMask)
return 0;
}
return (*szMask)==NULL;
}


DWORD FindPattern(DWORD dwAddress,DWORD dwLen,BYTE *bMask,char * szMask)
{
for(DWORD i=0; i < dwLen; i++)
if( bCompare( (BYTE*)( dwAddress+i ),bMask,szMask) )
return (DWORD)(dwAddress+i);
return 0;
}
