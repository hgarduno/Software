#ifndef __BUSQUEDAPRODUCTOS_H__
#define __BUSQUEDAPRODUCTOS_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpProductosPorAproximacion();

void EnviaResultadosBusqueda(SArgsSiscom *pSAgsSiscom);
void SeleccionaConsulta(SArgsSiscom *pSAgsSiscom);
SiscomOperaciones2 AnalizaTextoBusqueda(const char *pchrPtrTexto);
void ArgumentosBusquedas(SArgsSiscom *pSAgsSiscom);
SiscomOperaciones2 BusquedaPorAproximacionClave(const char *pchrPtrTexto);
void BuscaEnLasDescripciones(SArgsSiscom *pSAgsSiscom);
#endif
