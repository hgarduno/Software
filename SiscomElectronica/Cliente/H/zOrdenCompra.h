#ifndef __ZORDENCOMPRA_H__
#define __ZORDENCOMPRA_H__

#include <zSiscomRegistro.h>

class zEmpresa;
class zOrdenCompra:public zSiscomRegistro
{
public:
	zOrdenCompra();
	
	void IdCompra(const char *pchrPtrIdCompra);
	void Proveedor(zEmpresa *pzEmpresa);

};


#endif
