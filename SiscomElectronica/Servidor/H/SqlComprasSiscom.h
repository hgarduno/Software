#ifndef __SQLCOMPRASSISCOM_H__
#define __SQLCOMPRASSISCOM_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
int SqlComprasSiscom(SiscomOperaciones *pSiscomOpePtrDato);

void SqlConsultaComprasPeriodo(SiscomOperaciones *pSisOpePtrDato,
			       char *pchrPtrSql);

void SqlConsultaDetalleComprasPeriodo(SiscomOperaciones *pSisOpePtrDato,
			       char *pchrPtrSql);
#endif 
