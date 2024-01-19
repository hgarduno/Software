#ifndef __SISCOMINSERCIONESSQL_H__
#define __SISCOMINSERCIONESSQL_H__
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>



void SiscomAgregaArgumentoInsercionSql(const char *pchrPtrNombre,	
				       const char *pchrPtrBaseDatos,
				       const char *pchrPtrPuertoDB,
				       char *pchrPtrBuffer,
				       SiscomOperaciones *pSiscomOperPtrDat);
void SiscomAgregaArgumentoInsercionSql2(const char *pchrPtrNombre,
					char *pchrPtrBuffer,
					SiscomOperaciones *pSiscomOpePtrDat);

void SiscomAgregaSentenciasSqlDelAsociado(
		const char *pchrPtrArgumento,
		const char *pchrPtrAsociado,
		char *pchrPtrBuffer,
		char *pchrPtrBufferSql,
		SiscomOperaciones *pSiscomOperPtrDat,
		void (SiscomSql)(SiscomOperaciones *,SiscomRegistroProL *,char *));
		


void SiscomEnviaRegistrosAlServidorBD(const char *pchrPtrArgumento,
				      char *pchrPtrBuffer,
				      SiscomOperaciones *pSiscomOpPtrDat);

int SiscomEnviaRegistrosBD(const char *pchrPtrDirIp,
			    int pintPuerto,
			    const char *pchrPtrArgumento,
			    char *pchrPtrBuffer,
			    SiscomOperaciones *pSiscomOpPtrDat);

void SiscomEnviaRegistrosAlServidorBD2(SiscomRegistroProL *pSisRegProLPtrDat,
				      char *pchrPtrBuffer,
				      SiscomOperaciones *pSiscomOpPtrDat);

void SiscomRegistroEnvioBaseDatos(const char *pchrPtrBaseDatos,
				  const char *pchrPtrPuertoBase,
				  const char *pchrPtrOperacion,
				  char *pchrPtrBuffer,
				  SiscomRegistroProL **pSiscomRegProLPtrPrim,
				  SiscomRegistroProL **pSiscomRegProLPtrAct);

void SiscomAgregaSentenciasSqlCampoAsociado(
		const char *pchrPtrArgumento,
		const char *pchrPtrCampo,
		const char *pchrPtrAsociado,
		char *pchrPtrBuffer,
		char *pchrPtrBufferSql,
		SiscomOperaciones *pSiscomOperPtrDat,
		void (SiscomSql)(SiscomOperaciones *,SiscomRegistroProL *,char *));

void SiscomAgregaSentenciaSqlArgumento(
	const char *pchrPtrArgumentoSql,
	const char *pchrPtrArgumento,
	char *pchrPtrBuffer,
	char *pchrPtrBufferSql,
	SiscomOperaciones *pSisOpePtrDato,
	void (SiscomSql)(SiscomOperaciones *,SiscomRegistroProL *,char *));

void SiscomAgregaSentenciasSqlRegistros(const char *pchrPtrArgumento,
					char *pchrPtrBuffer,
					char *pchrPtrBufferSql,
					SiscomRegistroProL *pSiscomRegProLPtrDatos,
					SiscomOperaciones *pSiscomOpePtrDat,
					void (SiscomSql)(SiscomOperaciones *,SiscomRegistroProL *,char *));
extern SiscomDatosIni gSiscomDatIni;
#endif
