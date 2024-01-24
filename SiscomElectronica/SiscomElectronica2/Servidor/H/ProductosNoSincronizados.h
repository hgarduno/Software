#ifndef __PRODUCTOSNOSINCRONIZADOS_H__
#define __PRODUCTOSNOSINCRONIZADOS_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OPProductosNoSincronizados();
SiscomOperaciones2 *OpEnviaSincronizacionProductos();


void ArgumentosSincronizacionProductos(SArgsSiscom *pSAgsSiscom);
void SincronizandoProductos(SArgsSiscom *pSAgsSiscom);
void EnviaProductosNoSincronizados(SArgsSiscom *pSAgsSiscom);

#endif
