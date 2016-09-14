DWORD zSize;
DWORD zStartAddress;

BOOL bCompare(const BYTE* zData, const BYTE* bMask, const char* zzMask)
{
for(;*zzMask;++zzMask,++zData,++bMask)
{
if(*zzMask == 'x' && *zData != *bMask)
return false;
}
return (*zzMask)==NULL;
}


DWORD FindPattern(DWORD zAddress,DWORD zLen,BYTE *bMask,char * zzMask)
{
for(DWORD j = 0; j < zLen; j++)
if( bCompare((BYTE*)(zwAddress+j),bMask,zzMask))
return (DWORD)(zAddress+j);
return false;
}
