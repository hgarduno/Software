#ifndef __CONTABILIDAD_H__
#define __CONTABILIDAD_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h> 

void OrdenesTransferenciaTarjeta(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);

void FacturaPublicaEnGeneralPE(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);

int ConsultaOrdenesTarjetaTransferencia(SiscomOperaciones *pSiscomOpePtrDat);
int AgregaCamposExpendioComoPago(SiscomOperaciones *pSisOpePtrDatos);
int AgregaArgumentoSqlContabilidad(SiscomOperaciones *pSisOpePtrDatos);
int FacturandoPublicoEnGeneralPe(SiscomOperaciones *pSisOpePtrDato);

#endif
