#ifndef __APARTADOS_H__
#define __APARTADOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void ApartadosCliente(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void CancelaApartado(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void AbonoAApartado(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void CancelaAApartado(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void ConsultaAbonosVenta(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviaApartadosCliente(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaAbonosVenta(SiscomOperaciones *pSiscomOpePtrDato);
int EstadoAbonoAApartado(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaCampoFecha(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaFechaRespuestaApartadosCliente(SiscomOperaciones *pSiscomOpePtrDato);
#endif
