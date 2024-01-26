#ifndef __PERSONAS_H__
#define __PERSONAS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void CalculaCostoCantidad(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviaCalculoCostoCantidad(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaCalculoDescuento(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaCalculoCostoProducto(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaCalculoPreciosProducto(SiscomOperaciones *pSiscomOpePtrDato);


int CalculoCostoProductoProveedor(SiscomOperaciones *pSiscomOpePtrDato);
int CalculoPreciosProducto(SiscomOperaciones *pSiscomOpePtrDato);

int AgregaFechaHoy(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaFechaHoyCostoDescuento(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdCosto(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdDescuento(SiscomOperaciones *pSiscomOpePtrDato);
int FormaCamposRespuesta(SiscomOperaciones *pSiscomOpePtrDato);
int FormaCamposCalculoPrecios(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaCalculoPorcentajeGanancia(SiscomOperaciones *pSiscomOpePtrDato);
void GeneraValorCosto(SiscomOperaciones *,char *,char *);
#endif
