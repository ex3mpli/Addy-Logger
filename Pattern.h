DWORD zSize;
DWORD zStartAddress;

BOOL bCompare(const BYTE* zData, const BYTE* zMask, const char* zzMask)
{
for(;*zzMask;++zzMask,++zData,++zMask)
{
if(*zzMask == 'x' && *zData != *zMask)
return false;
}
return (*zzMask)==NULL;
}


DWORD FindPattern(DWORD zAddress,DWORD zLen,BYTE *zMask,char * zzMask)
{
for(DWORD j = 0; j < zLen; j++)
if( bCompare((BYTE*)(dwAddress+j),zMask,zzMask))
return (DWORD)(zAddress+j);
return false;
}
