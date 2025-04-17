#ifndef __CARGANOMINAEMPLEADOS_H__
#define __CARGANOMINAEMPLEADOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>
#include <stdio.h>

typedef enum{q0, q1, q2, q3, q4, q5, q6, q7, q8, q9} estados;

void CargaNominaEmpleados(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);
int EnviaNominaEmpleados(SiscomOperaciones *pSiscomOpePtrDat);
int RecibeArchivoNomina(SiscomOperaciones *pSiscomOpePtrDat);
int ProcesaArchivoNomina(SiscomOperaciones *pSiscomOpePtrDat);
int EscribeArchivoNomina(SiscomOperaciones *pSiscomOpePtrDat);
int ProcesaNomina(SiscomOperaciones *pSiscomOpePtrDat);

void ObtenDatosArchivoMaestros(FILE *pFltPtrArchivo,
        SiscomRegistroProL **pSiscomRegProLPtrMaestrosPrim,
        SiscomRegistroProL **pSiscomRegProLPtrMaestrosAct);
int rfc_regex(char * );
int subString(char *, const char *, unsigned int, unsigned int );
void normalizarNombrePropio(char *, char *, char *, char *);

void NombreArchivo(const char *pchrPtrArchivo,
		   char *pchrPtrArchivoSalida);
#endif
