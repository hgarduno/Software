#ifndef __ORDENCOMPRAIMPORTACION_H__
#define __ORDENCOMPRAIMPORTACION_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
void ProductoCompraImportacion(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);

void CalculandoPesoImporteTotal(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);


int ObtenProductoCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int CalculaPesoImporteTotal(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaCampoCompras(SiscomOperaciones *pSiscomOpePtrDato);
#endif
