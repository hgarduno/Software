#ifndef __TRANSFERENCIASEXPENDIOAEXPENDIO_H__
#define __TRANSFERENCIASEXPENDIOAEXPENDIO_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void ExistenciaExpendioOrigenDestino(int pintSocket,
				     SiscomRegistroProL *pSisRegProLPtrPrim,
				     SiscomRegistroProL *pSisRegProLPtrAct);
void ValidandoTransferenciaExpendioOrigen(int pintSocket,
				     SiscomRegistroProL *pSisRegProLPtrPrim,
				     SiscomRegistroProL *pSisRegProLPtrAct);

void TransfiereExpendioAExpendio(int pintSocket,
				     SiscomRegistroProL *pSiscomRegProLPtrPrim,
				     SiscomRegistroProL *pSiscomRegProLPtrAct);

void TransferenciaOtrosExpendios(int pintSocket,
				     SiscomRegistroProL *pSiscomRegProLPtrPrim,
				     SiscomRegistroProL *pSiscomRegProLPtrAct);
int ObteniendoExistenciaExpendioOrigenDestino(SiscomOperaciones *pSisOpePtrDato);
int ValidaTransferenciaExpendioOrigen(SiscomOperaciones *pSisOpePtrDato);
int TransfiriendoExpendioAExpendio(SiscomOperaciones *pSisOpePtrDato);
int CreaArgumentoExpendioOrigen(SiscomOperaciones *pSiscomOpePtrDato);
int CreaArgumentoExpendioDestino(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaIdTransferencia(SiscomOperaciones *pSisOpePtrDato);
int ProductosTransferenciaOtrosExpendios(SiscomOperaciones *pSisOpePtrDato);
int AsignaFechaHoyProductosOtrosExpendios(SiscomOperaciones *pSiscomOpePtrDato);
int ErrorConexionExpendioTransferencia(SiscomRegistroProL *pSiscomRegProLPtrMemoria,
			  const char *pchrPtrCampo,
			  SiscomOperaciones *pSiscomOpePtrDatos);
int MensajeConexionExpendioTransferencia(SiscomRegistroProL *,
				         const char *,
					 SiscomOperaciones *);

int ConexionExpendioTransferencia(SiscomRegistroProL *,const char *,SiscomOperaciones *);


int ExpendioOrigenSinConexion(SiscomOperaciones *);
int ExpendioDestinoSinConexion(SiscomOperaciones *);
#endif
