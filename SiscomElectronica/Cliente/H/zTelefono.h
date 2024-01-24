#ifndef __ZTELEFONO_H__
#define __ZTELEFONO_H__

#include <zSiscomRegistro.h>

class zTelefono:public zSiscomRegistro
{
public:
	zTelefono(const char *pchrPtrIdTelefono,
		  const char *pchrPtrTelefono);
	zTelefono(zSiscomRegistro *pzSisRegTelefono);
	const char *Telefono();

};

#endif
