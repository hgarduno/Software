#ifndef __ZCOSTODESCUENTO_H__
#define __ZCOSTODESCUENTO_H__
#include <zSiscomRegistro.h>

class zCosto;
class zDescuento;
class zCostoDescuento:public zSiscomRegistro
{

public:
	zCostoDescuento(zCosto *pzCosto,
			zDescuento *pzDescuento);

};

#endif
