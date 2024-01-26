#ifndef __PRODUCTOS_H__
#define __PRODUCTOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void AgregaPreciosProducto(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);
void PreciosDescuentosProducto(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void RegistraProducto(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

int RespondeActualizaStock(SiscomOperaciones *pSiscomOpePtrDato);
int EstadoRegistroProducto(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaIdPersonaRegistrada(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaPreciosDescuentosProducto(SiscomOperaciones *pSiscomOpePtrDato);

int EjecutaSumaProductos(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaProductosSumados(SiscomOperaciones *pSiscomOpePtrDato);
int GeneraIdProducto(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaCodigoBarras(SiscomOperaciones *pSiscomOpePtrDato);
int AsignaCantidadEntrada(SiscomRegistroProL *pSiscomRegProLProducto);
int AgregaFecha(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaIdPrecio(SiscomOperaciones *pSiscomOpePtrDato);
int IdDescuento(SiscomOperaciones *pSiscomOpePtrDato);
int IdCosto(SiscomOperaciones *pSiscomOpePtrDato);
#endif
