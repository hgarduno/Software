#ifndef __PRODUCTOSSE_H__
#define __PRODUCTOSSE_H_
#include <SiscomDesarrollo4/H/SiscomFuncionesComunes.h>
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
int EnviandoProductosSE(SiscomOperaciones *pSiscomOpePtrDato);
int EnviandoTiposProductoSE(SiscomOperaciones *pSiscomOpePtrDato);
int EnviandoDefinicionProductoSE(SiscomOperaciones *pSiscomOpePtrDato);
int NOSeEncontraronProductosSimilares(SiscomOperaciones *pSiscomOpePtrDato);
void TiposProductoSE(int pintSocket,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct);

void ProductosSE(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);

void ObtenDefinicionProducto(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);
int LlegoCriterioBusqueda(SiscomOperaciones *pSiscomOpePtrDato);
SiscomRegistroProL *ArmaRespuestaProductosSimilares(SiscomOperaciones *pSiscomOpePtrDato);
#endif
