#ifndef __ZCOSTO_H__
#define __ZCOSTO_H__

#include <zSiscomRegistro.h>


class zCosto:public zSiscomRegistro
{
public:
	zCosto(const char *pchrPtrIdCosto,
	       const char *pchrPtrCosto,
	       const char *pchrPtrCostoMIva,
	       const char *pchrPtrCostoIva,
	       const char *pchrPtrIva,
	       const char *pchrPtrFecha);
	zCosto(zCosto *);
	const char *CostoNeto();
	void CostoNeto(const unsigned char *);
};

#endif
