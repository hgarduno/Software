#ifndef __CQSISVENTASCAJA_H__
#define __CQSISVENTASCAJA_H__
#include <SiscomRegistros3.h>

class ProductosE;
class CQSisVentaCaja:public SiscomRegistro3
{
public:
	CQSisVentaCaja(const char *pchrPtrIdEmpleado,
		       const char *pchrPtrIdCaja,
		       const ProductosE *pPProductos);
};

#endif
