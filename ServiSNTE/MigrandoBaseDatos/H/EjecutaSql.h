#ifndef __EJECUTASQL_H__
#define __EJECUTASQL_H__
#include <stdio.h>
#include <SiscomProtocoloComunicaciones.h>

int ArchivosDirectorio(const char *pchrPtrDirectorio,
			SiscomRegistroProL **pSiscomRegProLPtrPrim,
			SiscomRegistroProL **pSiscomRegProLPtrAct);
int DatosDesdeArchivo(const char *pchrPtrArchivo,
		     SiscomRegistroProL **pSiscomRegProLPtrPrim,
		     SiscomRegistroProL **pSiscomRegProLPtrAct);
int EjecutaSql(const char *pchrPtrArchivo,
	       const char *pchrPtrSql,
	       SiscomRegistroProL **pSiscomRegProLPtrPrim,
	       SiscomRegistroProL **pSiscomRegProLPtrAct);
const char *FormaComando(const char *pchrPtrArchivo,
			 const char *pchrPtrSql);

void ObtenCampos(const char *pchrPtrLinea,
		 char ***pchrPtrCampos);

void AgregaRegistroRegreso(char **pchrPtrCampos,
			   char **pchrPtrDatos,
			   SiscomRegistroProL **pSiscomRegProLPtrPrim,
			   SiscomRegistroProL **pSiscomRegProLPtrActual);
void EjecutandoSql(const char *pchrPtrArchivo,
		   const char *pchrPtrFuncion,
		   int pintNoLinea,
		   const char *pchrPtrSql);

#define EjecutaSentenciaSql(pchrPtrSql) \
	EjecutandoSql(__FILE__,		\
		      __FUNCTION__,	\
		      __LINE__,		\
		      pchrPtrSql);
#endif
