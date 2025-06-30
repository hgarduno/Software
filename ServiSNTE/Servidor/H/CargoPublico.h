#ifndef __CARGOPUBLICO_H__
#define __CARGOPUBLICO_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>
int EnviaEstadoRegistroCargoPublico(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaIdCargoPublico(SiscomOperaciones *pSiscomOpePtrDato);
int ValidaEstadoInsercionCargoPublico(SiscomOperaciones *pSiscomOpePtrDato);
int ValidaEstadoRegistroCargoPublico(SiscomOperaciones *pSiscomOpePtrDato);
#endif
