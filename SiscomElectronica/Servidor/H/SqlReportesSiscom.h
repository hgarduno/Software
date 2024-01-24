#ifndef __SQLREPORTESSISCOM_H__
#define __SQLREPORTESSISCOM_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>


int SqlReporteVentas4(SiscomOperaciones *pSiscomOpePtrDato);
int SqlVentasSiscom(SiscomOperaciones *pSiscomOpePtrDato);
int SqlExpendiosSiscom(SiscomOperaciones *pSiscomOpePtrDato);
int SqlCierraDia(SiscomOperaciones *pSiscomOpePtrDato);

void SqlImporteTotalEnCaja(SiscomOperaciones *pSiscomOpePtrDato,
			   char *pchrPtrSql);
void SqlVentasTotales(SiscomOperaciones *pSiscomOpePtrDato,
		      const char *pchrPtrNombre,
		      const char *pchrPtrEdoVenta,
		      char *pchrPtrSql);


void SqlVentaPorEscuela(SiscomOperaciones *pSiscomOpePtrDato,
			  const char *pchrPtrEdoVenta,
			  char *pchrPtrSql);

void SqlTotalVentas(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql);
void SqlTotalTotalVentas(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql);
void SqlTotales(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql);
void SqlMaterialEscuela(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSqlMaterialEscuela);

int ExpendioParaConsultar(const char *pchrPtrIdServidor,
		    const char *pchrPtrArgumento,
		    SiscomOperaciones *pSiscomOpePtrDato,
		    int *pintPtrPuerto,
		    char **pchrPtrDirIp);
#endif
