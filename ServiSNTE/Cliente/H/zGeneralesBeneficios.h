#ifndef __ZGENERALESBENEFICIOS_H__
#define __ZGENERALESBENEFICIOS_H__

#include <zSiscomRegistro.h>

class zGeneralesBeneficios:public zSiscomRegistro
{
public:
	zGeneralesBeneficios(const char *pchrPtrIdVenta);
	zGeneralesBeneficios(zSiscomRegistro *pzSisRegRegreso);
	void Fecha(const char *pchrPtrFecha);
	void Lugar(const char *pchrPtrLugar);

};

#endif
