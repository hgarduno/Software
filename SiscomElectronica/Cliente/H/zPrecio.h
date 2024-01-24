#ifndef __ZPRECIO_H__
#define __ZPRECIO_H__

#include <zSiscomRegistro.h>

class TipoPrecio;

class zPrecio:public zSiscomRegistro
{
public:
	zPrecio(const char *,const char *);
	void Precio(const char *);


	static zPrecio *DeTipoPrecio(TipoPrecio *pTPrecio);

};

#endif
