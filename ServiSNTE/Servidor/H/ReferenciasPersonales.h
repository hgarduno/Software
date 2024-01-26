#ifndef __REFERENCIASPERSONALES_H__
#define __REFERENCIASPERSONALES_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>
int EnviaEstadoRegistroReferenciasPersonales(SiscomOperaciones *pSiscomOpePtrDato);
int ValidaEstadoInsercionReferenciasPersonales(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdReferenciaPersonal(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdTelefonosReferencia(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdDireccionesReferencia(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdPersonasReferencia(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraRFCPersonasReferencia(SiscomOperaciones *pSiscomOpePtrDato);

#endif
