#ifndef __EMPLEO_H__
#define __EMPLEO_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>
int EnviaEstadoRegistroEmpleo(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaIdEmpresa(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaJefeRFC(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaIdJefe(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaIdEmpleo(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaIdDireccionEmpleo(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaIdCorreoEmpleo(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaIdTelefonoEmpleo(SiscomOperaciones *pSiscomOpePtrDato);

int EnviaRespuestaEmpresaRegistrada(SiscomOperaciones *pSiscomOpePtrDato);
void EnviaEmpresaRegistrada(SiscomRegistroProL *, SiscomOperaciones *pSiscomOpePtrDato);
void EnviaEmpresaNoRegistrada(SiscomOperaciones *pSiscomOpePtrDato);
int EstaLaEmpresaYaRegistrada(SiscomOperaciones *pSiscomOpePtrDato);
int EstaElJefeYaRegistrado(SiscomOperaciones *pSiscomOpePtrDato);
#endif
