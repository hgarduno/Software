#ifndef __COMPRAS_H__
#define __COMPRAS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void RegistraCompra(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviaIdCompraRegistrada(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraFechaCompra(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdCompra(SiscomOperaciones *pSiscomOpePtrDato);
int OrdenCompra(SiscomOperaciones *pSiscomOpePtrDato);
int SumatoriaCompra(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaTotalesCompra(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaEstadoRegistroPrecioCompra(SiscomOperaciones *pSiscomOpePtrDato);
int PreparaDatosCosto(SiscomOperaciones *pSiscomOpePtrDato);
#endif
