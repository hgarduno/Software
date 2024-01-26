#ifndef __COTIZANDO_H__
#define __COTIZANDO_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void CotizaProducto(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);
void CotizaOrden(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);


int EnviaProductoCotizado(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaCostoUnitario(SiscomOperaciones *pSiscomOpePtrDato);
int CalculaTotalOrden(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaCampoTotalOrden(SiscomOperaciones *pSiscomOpePtrDato);
int CalculandoCompraACredito(SiscomOperaciones *pSiscomOpePtrDato);

int EnviaTotalesOrden(SiscomOperaciones *pSiscomOpePtrDato);

#endif
