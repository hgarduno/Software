#ifndef __ZUBICACION_H__
#define __ZUBICACION_H__
#include <zSiscomRegistro.h>

class zCajaMaterial;
class zEstante;
class zUbicacion:public zSiscomRegistro
{

public:
	zUbicacion(zSiscomRegistro *);
	~zUbicacion();
	zUbicacion();
	zCajaMaterial *Caja();
	zEstante *Estante();

	
};

#endif
