#ifndef __CLIENTES_H__
#define __CLIENTES_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void ConsultaClienteCompras(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviaComprasCliente(SiscomOperaciones *pSiscomOpePtrDato);
void VerificaSiSePuedeVenderACredito(SiscomOperaciones *pSiscomOpePtrDato);
void ClienteNoRegistrado(SiscomOperaciones *pSiscomOpePtrDato);


int ComprasPorFinanciera(SiscomOperaciones *pSiscomOpePtrDato);
#endif
