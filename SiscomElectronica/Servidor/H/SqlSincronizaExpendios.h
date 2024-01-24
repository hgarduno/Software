#ifndef __SQLSINCRONIZAEXPENDIOS_H__
#define __SQLSINCRONIZAEXPENDIOS_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
int SqlProductosMatriz(SiscomOperaciones *pSisOpePtrDato);
int SqlProductosExpendio(SiscomOperaciones *pSisOpePtrDato);
int SqlLasBodegasDelExpendio(SiscomOperaciones *pSisOpePtrDato);
int SqlInsertaProductoExpendioSincroniza(SiscomOperaciones *pSisOpePtrDato);

void SqlConsultaProductosExpendios(const char *pchrPtrIdExpendio,char *pchrPtrSql);
void SqlConsultaBodegasExpendio(char *pchrPtrSql);

void SqlConsultandoProductosExpendio(const char *pchrPtrIdExpendio,
			  char *pchrPtrAArgumento,
			  SiscomOperaciones *pSisOpePtrDato);


void ObtenDatosComunicacionExpendio(SiscomOperaciones *pSisOpePtrDato,
			    char **pchrPtrDirIp,
			    char **pchrPtrBaseDatos,
			    char **pchrPtrPuertoBaseDatos,
			    int *pintPtrPuertoAD);
void InsertIntoProductos(SiscomRegistroProL *pSisRegProLPtrProducto,char *pchrPtrSql);
void InsertIntoPrecios(SiscomRegistroProL *pSisRegProLPtrProducto,char *pchrPtrSql);

void InsertIntoExistencias(const char *pchrPtrIdExpendio,
			   SiscomRegistroProL *pSisRegProLPtrProducto,
			   char *pchrPtrSql);

void InsertIntoMaterialBodegaSincronizaE(const char *pchrPtrIdBodega,
					 SiscomRegistroProL *pSisRegProLPtrProducto,
					 char *pchrPtrSql);
#endif
