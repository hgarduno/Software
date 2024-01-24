#ifndef __ANALISISORDENCOMPRA_H__
#define __ANALISISORDENCOMPRA_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpDatosComprasProducto();
void ArgumentosDatosComprasProducto(SArgsSiscom *pSAgsSiscom);
void EnviaDatosComprasProducto(SArgsSiscom *pSAgsSiscom);
void GeneraFechasSemestre(SArgsSiscom *pSAgsSiscom);

#endif
