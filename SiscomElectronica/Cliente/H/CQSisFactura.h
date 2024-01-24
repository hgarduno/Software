#ifndef __CQSISFACTURA_H__
#define __CQSISFACTURA_H__
#include <SiscomRegistros4.h>
#include <SiscomOperaciones3.h>
class CQSisFactura:public SiscomRegistro4
{
public:
	CQSisFactura(SiscomRegistro3 *pSisReg3Cliente,
		     SiscomRegistro3Lst *pSisReg3LstProductos,
		     SiscomRegistro3Lst *pSisReg3LstOrdenes);

};


class CQSisOpRegistraFactura:public SiscomOperaciones3
{
public:
	CQSisOpRegistraFactura(SiscomDatCom *pSisDatCom);
	void Registra(CQSisFactura *pCQSisFactura);

};
#endif
