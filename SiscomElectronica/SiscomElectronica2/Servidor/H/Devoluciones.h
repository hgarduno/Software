#ifndef __DEVOLUCIONES_H__
#define __DEVOLUCIONES_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpCalculaDevolucion();
SiscomOperaciones2 *OpEjecutaDevolucion();
void CalculaDevolucion(SArgsSiscom *pSAgsSiscom);
void EjecutaDevolucion(SArgsSiscom *pSAgsSiscom);
void ArgumentosDevolucion(SArgsSiscom *pSAgsSiscom);
#endif
