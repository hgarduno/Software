#ifndef __INICIAEXPENDIOS_H__
#define __INICIAEXPENDIOS_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpIniciaDatosExpendio();
void IniciaDatosExpendio(SArgsSiscom *pSArgsSiscom);
void ArgumentosIniciaExpendios(SArgsSiscom *pSAgsSiscom);

void EjecutandoRegistro(SArgsSiscom *pSAgsSiscom);

void ObtenComunicacionExpendio(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			       char *pchrPtrDirIp,
			       int *pintPtrPuerto);
#endif
