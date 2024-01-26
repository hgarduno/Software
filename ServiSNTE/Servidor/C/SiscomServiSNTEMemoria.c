#include <SiscomServiSNTEMemoria.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>
#include <ComunSiscomServiSNTE.h>
#include <SqlServidores.h>
#include <string.h>

void MemoriaSiscomServiSNTE()
{
char lchrArrBuffer[256];
SiscomOperaciones lSiscomOpePtrDat;
memset(&lSiscomOpePtrDat,0,sizeof(SiscomOperaciones));
ComunicacionAccesoDatos(&lSiscomOpePtrDat);
SqlServidores(&lSiscomOpePtrDat);
gSiscomRegProLPtrMemoria=lSiscomOpePtrDat.SiscomRegProLPtrPrimRes;
}
