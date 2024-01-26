#ifndef __CARGANOMINAEMPLEADOS_H__
#define __CARGANOMINAEMPLEADOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>
#include <stdio.h>

void CargaBaseDeDatosMaestros(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);
int EnviaBaseDeDatosMaestros(SiscomOperaciones *pSiscomOpePtrDat);
int RecibeArchivoBaseDeDatos(SiscomOperaciones *pSiscomOpePtrDat);
int ProcesaArchivoBaseDeDatos(SiscomOperaciones *pSiscomOpePtrDat);
int EscribeArchivoBaseDeDatos(SiscomOperaciones *pSiscomOpePtrDat);
int ProcesaBaseDeDatos(SiscomOperaciones *pSiscomOpePtrDat);

//void ObtenDatosArchivoMaestros(FILE *pFltPtrArchivo,
//        SiscomRegistroProL **pSiscomRegProLPtrMaestrosPrim,
//        SiscomRegistroProL **pSiscomRegProLPtrMaestrosAct);
//int subString(char *, const char *, unsigned int, unsigned int );

#endif
