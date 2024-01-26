#ifndef __CONTRATOSBENEFICIOS_H__
#define __CONTRATOSBENEFICIOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void RegistraContratoBeneficios(int pintSocket,
       void *pvidPtrAncla,
       const SiscomRegistroProL *pSiscomRegProLPtrPrim,
       const SiscomRegistroProL *pSiscomRegProLPtrAct);

void ConsultaContratosBeneficios(int pintSocket,
       void *pvidPtrAncla,
       const SiscomRegistroProL *pSiscomRegProLPtrPrim,
       const SiscomRegistroProL *pSiscomRegProLPtrAct);

void ConsultaContenidoContratoBeneficios(int pintSocket,
       void *pvidPtrAncla,
       const SiscomRegistroProL *pSiscomRegProLPtrPrim,
       const SiscomRegistroProL *pSiscomRegProLPtrAct);

void ActualizaEstadoContratoBeneficios(int pintSocket,
       void *pvidPtrAncla,
       const SiscomRegistroProL *pSiscomRegProLPtrPrim,
       const SiscomRegistroProL *pSiscomRegProLPtrAct);

void RecibeContratoBeneficios(int pintSocket,
       void *pvidPtrAncla,
       const SiscomRegistroProL *pSiscomRegProLPtrPrim,
       const SiscomRegistroProL *pSiscomRegProLPtrAct);

void RecibeContratoBeneficiosParcial(int pintSocket,
       void *pvidPtrAncla,
       const SiscomRegistroProL *pSiscomRegProLPtrPrim,
       const SiscomRegistroProL *pSiscomRegProLPtrAct);

void RecibeContratoBeneficiosParcialNueva(int pintSocket,
       void *pvidPtrAncla,
       const SiscomRegistroProL *pSiscomRegProLPtrPrim,
       const SiscomRegistroProL *pSiscomRegProLPtrAct);


void ConsultaContratoBeneficios(int pintSocket,
       void *pvidPtrAncla,
       const SiscomRegistroProL *pSiscomRegProLPtrPrim,
       const SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviaIdContratoBeneficiosRegistrada(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaIdContratoBeneficiosActualizada(SiscomOperaciones *pSiscomOpePtrDato);
int ContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraFechaContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDato);
int PreparaActualizacionContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDato);
int PreparaActualizacionContratoBeneficiosParcial(SiscomOperaciones *pSiscomOpePtrDato);
int EjecutaContratoBeneficiosATienda(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaContratosBeneficios(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaContenidoContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaContenidoContratoBeneficiosPrueba(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaCreditosBeneficiosIntegrales(SiscomOperaciones *pSiscomOpePtrDato);


#endif
