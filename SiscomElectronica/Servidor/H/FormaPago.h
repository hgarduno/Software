#ifndef __FORMAPAGO_H__
#define __FORMAPAGO_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void YaSeReflejoTransferencia(int pintSocket,
		   SiscomRegistroProL *pSiscomRegProLPtrPrim,
		   SiscomRegistroProL *pSiscomRegProLPtrAct);


int ActualizaEstadoPagoTransferencia(SiscomOperaciones *pSisOpPtrDato);
int ArgumentoPagoTransferencia(SiscomOperaciones *pSiscomOpePtrDato);

#endif

