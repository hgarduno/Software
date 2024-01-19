#ifndef __SISCOMMANEJOLOG_H__
#define __SISCOMMANEJOLOG_H__
#include <stdio.h>
#include <SiscomArchivosIni.h>
#include <SiscomProtocoloComunicaciones.h>
extern FILE *gPtrFleArchivoLog;

void SiscomMensajesLog4(const char *pchrPtrArchivo,
			 const char *pchrPtrFuncion,
			 int pintNoLinea,
			 char *pzCadenaFormato,...);
void SiscomArregloCadenasLog(const char *pchrPtrArchivo,
			     const char *pchrPtrFuncion,
			     int pintNoLinea,
			     char **pchrPtrCadenas);
void SiscomVariablesIniLog(const char *pchrPtrArchivo,
			   const char *pchrPtrFuncion,
			   int pintNLinea,
			   const SiscomVariablesIniL *pSiscomVILPtrDatos);
void SiscomVariablesArregloIniLog(const char *pchrPtrArchivo,
				  const char *pchrPtrFuncion,
				  int pintNLinea,
				  const SiscomVariableIniArregloL *pSiscomVIALPtrDato);

void SiscomMuestraCamposProtocolo(const char *pchrPtrArchivo,
			   const char *pchrPtrFuncion,
			   int pintNLinea,
			   const SiscomCampoProL *pSiscomCamProLPtrDato);
void SiscomMuestraCamposProtocolo2(const char *pchrPtrArchivo,
				   const char *pchrPtrFuncion,
				   int pintNLinea,
				   const SiscomRegistroProL *pSiscomRegProLPtrDat);
void SiscomMuestraRegistrosProtocolo(const char *pchrPtrArchivo,
			      const char *pchrPtrFuncion,
			      int pintNLinea,
			      char *pchrPtrBuffer,
			      const SiscomRegistroProL *pSiscomRegProLPtrDat);

void SiscomMuestraRegistrosAsociados(const char *pchrPtrArchivo,
				     const char *pchrPtrFuncion,
				     int pintNoLinea,
				     char *pchrPtrBuffer,
				     const char *pchrPtrCampo,
				     SiscomRegistroProL *pSiscomRegProLPtrAct);
void SiscomFormaEncabezadoRegistroLog(
		const SiscomCampoProL *pSiscomCamProLPtrDato,
		char *pchrPtrBuffer);

void SiscomFormaRegistroADesplegarLog(
	const SiscomCampoProL *pSiscomCamProLPtrDato,
	char *pchrPtrBuffer);

void SiscomSocketProtocolo(const char *pchrPtrArchivo,
			   const char *pchrPtrFuncion,
			   int pintLinea,
			   const char *pchrPtrFormato,
			   ...);


#endif
