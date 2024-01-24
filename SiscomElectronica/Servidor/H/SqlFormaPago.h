#ifndef __SQLFORMAPAGO_H__
#define __SQLFORMAPAGO_H__

#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

int SqlActualizaPagoTransferencia(SiscomOperaciones *pSisOpePtrDato);
void UpdatePagoTransferencia(SiscomOperaciones *pSisOpePtrDato,
			     SiscomRegistroProL *pSisRegProLPtrDato,
			     char *pchrPtrSql);

#endif

