#ifndef __SQLEXISTENCIAEXPENDIOS_H__
#define __SQLEXISTENCIAEXPENDIOS_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
int SqlExistenciaExpendios(SiscomOperaciones *pSiscomOpePtrDatos);
int SqlExistenciasVentasExpendios(SiscomOperaciones *pSiscomOpePtrDatos);
int SqlExistenciasVentasExpendiosT(SiscomOperaciones *pSiscomOpePtrDatos);

void SqlConsultaExistenciaProducto(SiscomOperaciones *pSiscomOpePtrDatos,
				   SiscomRegistroProL *pSiscomRegProLPtrProductos,
					   char **pchrPtrSql);

#endif
