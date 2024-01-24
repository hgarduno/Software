#ifndef __SINCRONIZAEXPENDIO_H__
#define __SINCRONIZAEXPENDIO_H__

#include <SiscomDesarrollo2.h>


SiscomOperaciones2 *OpSincronizaExpendio();

void SincronizaExpendio(SArgsSiscom *pSAgsSiscom);

void ProductosMatriz(const char *pchrPtrIp,
		     int pintPuerto,
		     LCamposSiscomPro2 **pLCSiscomPro2Reg);
#endif
