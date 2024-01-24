#ifndef __CQSISKITS_H__
#define __CQSISKITS_H__
#include <SiscomRegistros4.h>

#include <SiscomOperaciones3.h>

class ProductoE;
class CQSisKitsOp:public SiscomOperaciones3
{
public:
	CQSisKitsOp(SiscomDatCom *pSisDatCom);
	const char *RegistraKit(ProductoE *pProductoE,const char *pchrPtrIdTipoProducto);

};

#endif
