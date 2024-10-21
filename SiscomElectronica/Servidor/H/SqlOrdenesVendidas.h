#ifndef __SQLORDENESVENDIDAS_H__
#define __SQLORDENESVENDIDAS_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
int SqlOrdenesVendidas(SiscomOperaciones *pSiscomOpePtrDato);
int SqlOrdenesVendidas2(SiscomOperaciones *pSiscomOpePtrDato);
int SqlOrdenesParaFacturar(SiscomOperaciones *pSiscomOpePtrDato);
int SqlOrdenParaFacturar(SiscomOperaciones *pSiscomOpePtrDato);
int SqlConsultaApartados(SiscomOperaciones *pSiscomOpePtrDato);
int SqlProductoEnApartados(SiscomOperaciones *pSiscomOpePtrDato);
int SqlConsultaOrden(SiscomOperaciones *pSiscomOpePtrDato);
int SqlCompletaCotizaciones(SiscomOperaciones *pSiscomOpePtrDato);
int SqlCompletaPedidos(SiscomOperaciones *pSiscomOpePtrDato);
int SqlCompletaVentas(SiscomOperaciones *pSiscomOpePtrDato);
void SqlClienteEscuela(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql);

#endif
