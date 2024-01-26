#ifndef __ZPRECIO_H__
#define __ZPRECIO_H__

#include <zSiscomRegistro.h>

class zPrecio:public zSiscomRegistro
{
public:
	zPrecio(const char *pchrPtrIdPrecio,
		const char *pchrPtrPrecio,
		const char *pchrPtrMargen);
	void Precio(const unsigned char *pchrPtrPrecio);
	const char *Precio();

};

#endif
