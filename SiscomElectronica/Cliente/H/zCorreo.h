#ifndef __ZCORREO_H__
#define __ZCORREO_H__
#include <zSiscomRegistro.h>


class zCorreo:public zSiscomRegistro
{
public:
	zCorreo(const char *pchrPtrIdCorreo,
		const char *pchrPtrCorreo);
	zCorreo(zSiscomRegistro *pzSisRegRegreso);
	const char *Correo();		

};
#endif
