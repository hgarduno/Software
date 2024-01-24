#ifndef __ZCOTIZACION_H__
#define __ZCOTIZACION_H__
#include <zSiscomRegistro.h>


class zCotizacion:public zSiscomRegistro
{
public:
	zCotizacion();
	zCotizacion(zSiscomRegistro *pzSisRegCotizacion);
	void Descripcion(const char *pchrPtrDescripcion);
	const char *Descripcion();
	int DescripcionValida();
};

#endif
