#ifndef __ZTELEFONOS_H__
#define __ZTELEFONOS_H__
#include <zSiscomRegistros.h>

class zTelefono;
class zTelefonos:public zSiscomRegistros
{
public:
	zTelefonos();
	zTelefonos(zSiscomRegistros *);
	const char *Telefono();
private:	

};

#endif
