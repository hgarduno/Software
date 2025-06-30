#ifndef __CENTROTRABAJO_H__
#define __CENTROTRABAJO_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
int EnviaEstadoRegistroCentroTrabajo(SiscomOperaciones *pSiscomOpePtrDato);
void EnviaRegistroExitosoCentroTrabajo(SiscomOperaciones *pSiscomOpePtrDato);
int ValidaEstadoRegistroCentroTrabajo(SiscomOperaciones *pSiscomOpePtrDato);
#endif
