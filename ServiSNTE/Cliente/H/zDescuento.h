#ifndef __ZDESCUENTO_H__
#define __ZDESCUENTO_H__

#include <zSiscomRegistro.h>


class zDescuento:public zSiscomRegistro
{
public:
	zDescuento(const char *pchrPtrIdDescuento,
	       const char *pchrPtrD1,
	       const char *pchrPtrD2,
	       const char *pchrPtrD3,
	       const char *pchrPtrD4,
	       const char *pchrPtrFecha);

};

#endif

