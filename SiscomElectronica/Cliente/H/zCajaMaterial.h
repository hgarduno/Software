#ifndef __ZCAJAMATERIAL_H__
#define __ZCAJAMATERIAL_H__
#include <zSiscomRegistro.h>


class zCajaMaterial:public zSiscomRegistro
{
public:
	zCajaMaterial();
	zCajaMaterial(zSiscomRegistro *pzSisRegProducto);
	void IdCajaMaterial(const char *pchrPtrIdCajaMaterial);
	void Caja(const char *pchrPtrCaja);
	void Descripcion(const char *pchrPtrDescripcion);
	const char *Caja();
};

#endif
