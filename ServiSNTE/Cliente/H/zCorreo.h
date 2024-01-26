#ifndef __ZCORREO_H__
#define __ZCORREO_H__
#include <zSiscomRegistro.h>


class zCorreo:public zSiscomRegistro
{
public:
	zCorreo();
	zCorreo(zSiscomRegistro *pzSisRegCorreo);
	const char *Correo();
	void IdCorreo(const char *pchrPtrIdCorreo);
	void Correo(const char *pchrPtrCorreo);
	void Descripcion(const char *pchrPtrDescripcion);
};

#endif
