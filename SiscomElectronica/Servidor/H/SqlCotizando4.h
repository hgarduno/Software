#ifndef __SQLCOTIZANDO4_H__
#define __SQLCOTIZANDO4_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
int SqlProductosCotizacion(SiscomOperaciones *pSiscomPtrDato,
			   const char *pchrPtrAsociadoRegreso,
			   SiscomRegistroProL *pSiscomRegProLPtrProductos);
int SqlProductosCotizando(SiscomOperaciones *pSiscomOpePtrDato);
#endif
