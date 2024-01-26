#ifndef __POSICIONESIMPRESION_H__
#define __POSICIONESIMPRESION_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>
int EnviaPosiciones(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaPosicionesReciboApartado(SiscomOperaciones *pSiscomOpePtrDato);
int ArmaRespuestaPosiciones(SiscomOperaciones *pSiscomOpePtrDato);

#endif
