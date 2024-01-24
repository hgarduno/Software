#ifndef __ACTUALIZAEXPENDIO_H__
#define __ACTUALIZAEXPENDIO_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpProductosNoExpendio();
SiscomOperaciones2 *OpSincronizaProductosNoExpendio();
void ArgumentosProductosNoExpendio(SArgsSiscom *pSAgsSiscom);
void ProductosNoExpendio(SArgsSiscom *pSAgsSiscom);
void SincronizaProductosNoExpendio(SArgsSiscom *pSAgsSiscom);

void ObtenProductosNoExpendio(SArgsSiscom *pSAgsSiscom);
void CopiaProductosParaRegresar(LCamposSiscomPro2 *pLCSiscomPro2NoExpendio,
				SArgsSiscom *pSAgsSiscom);
void EnviaProductosSincronizados(SArgsSiscom *pSAgsSiscom);
#endif
