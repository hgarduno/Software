#ifndef __ZPRODUCTOIMPORTADOINF_H__
#define __ZPRODUCTOIMPORTADOINF_H__
#include <zProductoImportado.h>

class zCompraImportacion;
class zProductoImportadoInf:public zProductoImportado
{
public:
	zProductoImportadoInf();
	void Actualiza(zSiscomRegistro *);
	zCompraImportacion *Compra();
private:
	void ActualizaUltimaCompra(zSiscomRegistro *);
	void ActualizaPeso(zSiscomRegistro *);
	void ActualizaClaveProveedor(zSiscomRegistro *);
};

#endif
