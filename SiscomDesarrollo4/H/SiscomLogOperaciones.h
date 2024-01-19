#ifndef __SISCOMLOGOPERACIONES_H__
#define __SISCOMLOGOPERACIONES_H__
#include <SiscomOperaciones.h>
void SiscomMuestraAsociadosArgumento(const char *pchrPtrArchivo,
				     const char *pchrPtrFuncion,
				     int pintNLinea,
				     const char *pchrPtrArgumento,
				     const char *pchrPtrAsociado,
				     char *pchrPtrBuffer,
				     SiscomOperaciones *pSiscomOpPtrDat);

void SiscomMuestraArgumento(const char *pchrPtrArchivo,
				     const char *pchrPtrFuncion,
				     int pintNLinea,
				     const char *pchrPtrArgumento,
				     char *pchrPtrBuffer,
				     SiscomOperaciones *pSiscomOpPtrDat);

void SiscomAsociadoRespuesta(const char *pchrPtrArchivo,
				     const char *pchrPtrFuncion,
				     int pintNLinea,
				     const char *pchrPtrAsociado,
				     char *pchrPtrBuffer,
				     SiscomOperaciones *pSiscomOpePtrDat);
void SiscomAsociadoEntrada(const char *pchrPtrArchivo,
				     const char *pchrPtrFuncion,
				     int pintNLinea,
				     const char *pchrPtrAsociado,
				     char *pchrPtrBuffer,
				     SiscomOperaciones *pSiscomOpePtrDat);

void SiscomRegistroEntrada(const char *pchrPtrArchivo,
			   const char *pchrPtrFuncion,
			   int pintNLinea,
			   char *pchrPtrBuffer,
			   SiscomOperaciones *pSiscomOpePtrDat);

void SiscomRegistroRegreso(const char *pchrPtrArchivo,
			   const char *pchrPtrFuncion,
			   int pintNLinea,
			   char *pchrPtrBuffer,
			   SiscomOperaciones *pSiscomOpePtrDat);

void SiscomAsociadoAsociadoEntradaAlLog(const char *pchrPtrCampo,
				      const char *pchrPtrAsociado,
				      const char *pchrPtrArchivo,
				      const char *pchrPtrFuncion,
				      int pintNLinea,
				      char *pchrPtrBuffer,
				      SiscomOperaciones *pSisOpePtrDato);

#endif
