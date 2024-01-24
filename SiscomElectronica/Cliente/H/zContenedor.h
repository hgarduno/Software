#ifndef __ZCONTENEDOR_H__
#define __ZCONTENEDOR_H__
#include <zSiscomRegistro.h>

class zCompraImportacion;
class zContenedor:public zSiscomRegistro
{
public:
	zContenedor();
	void AgregaCompra(zCompraImportacion *);

};

#endif
