#ifndef __SALDOSMOVIMIENTOS_H__
#define __SALDOSMOVIMIENTOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

int EnviaSaldosMovimientosMes(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaConceptosSaldosMovimientos(SiscomOperaciones *pSiscomOpePtrDato);
#endif
