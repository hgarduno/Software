#ifndef __TRANSFERENCIAS_H__
#define __TRANSFERENCIAS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void RegistraTransferencia(int pintSocket,
       void *pvidPtrAncla,
       const SiscomRegistroProL *pSiscomRegProLPtrPrim,
       const SiscomRegistroProL *pSiscomRegProLPtrAct);

void ConsultaTransferencias(int pintSocket,
       void *pvidPtrAncla,
       const SiscomRegistroProL *pSiscomRegProLPtrPrim,
       const SiscomRegistroProL *pSiscomRegProLPtrAct);

void ConsultaContenidoTransferencia(int pintSocket,
       void *pvidPtrAncla,
       const SiscomRegistroProL *pSiscomRegProLPtrPrim,
       const SiscomRegistroProL *pSiscomRegProLPtrAct);

void ActualizaEstadoTransferencia(int pintSocket,
       void *pvidPtrAncla,
       const SiscomRegistroProL *pSiscomRegProLPtrPrim,
       const SiscomRegistroProL *pSiscomRegProLPtrAct);

void RecibeTransferencia(int pintSocket,
       void *pvidPtrAncla,
       const SiscomRegistroProL *pSiscomRegProLPtrPrim,
       const SiscomRegistroProL *pSiscomRegProLPtrAct);

void RecibeTransferenciaParcial(int pintSocket,
       void *pvidPtrAncla,
       const SiscomRegistroProL *pSiscomRegProLPtrPrim,
       const SiscomRegistroProL *pSiscomRegProLPtrAct);

void RecibeTransferenciaParcialNueva(int pintSocket,
       void *pvidPtrAncla,
       const SiscomRegistroProL *pSiscomRegProLPtrPrim,
       const SiscomRegistroProL *pSiscomRegProLPtrAct);

void TransferenciasEnviadas(int pintSocket,
       void *pvidPtrAncla,
       const SiscomRegistroProL *pSiscomRegProLPtrPrim,
       const SiscomRegistroProL *pSiscomRegProLPtrAct);

void DetalleTransferencia(int pintSocket,
       void *pvidPtrAncla,
       const SiscomRegistroProL *pSiscomRegProLPtrPrim,
       const SiscomRegistroProL *pSiscomRegProLPtrAct);

void FormaCondicionConsultaPrecioCosto(SiscomOperaciones *pSiscomOpePtrDato,
				       char **pchrPtrCondicion);

int EnviaIdTransferenciaRegistrada(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaIdTransferenciaActualizada(SiscomOperaciones *pSiscomOpePtrDato);
int Transferencia(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdTransferencia(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraFechaTransferencia(SiscomOperaciones *pSiscomOpePtrDato);
int PreparaActualizacionTransferencia(SiscomOperaciones *pSiscomOpePtrDato);
int PreparaActualizacionTransferenciaParcial(SiscomOperaciones *pSiscomOpePtrDato);
int EjecutaTransferenciaATienda(SiscomOperaciones *pSiscomOpePtrDato);
int EjecutaActEstadoATienda(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaTransferencias(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaContenidoTransferencia(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaContenidoTransferenciaPrueba(SiscomOperaciones *pSiscomOpePtrDat);

int SeTransfiereAPiso(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaCostoPrecioTransferencia(SiscomOperaciones *pSiscomOpePtrDato);

#endif
