#ifndef __VENTAS_H__
#define __VENTAS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void RegistraVenta(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviaIdVentaRegistrada(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraFechaVenta(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdTelefonoCliente(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdVenta(SiscomOperaciones *pSiscomOpePtrDato);
int OrdenVenta(SiscomOperaciones *pSiscomOpePtrDato);

void AgregandoTiendaVenta(SiscomRegistroProL *pSiscomRegProLPtrRegreso,
			  SiscomOperaciones *pSiscomOpePtrDato);
#endif
