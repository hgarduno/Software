#ifndef __ZDIRECCIONES_H__
#define __ZDIRECCIONES_H__

#include <zSiscomRegistros.h>

class zDireccion;

class zDirecciones:public zSiscomRegistros
{
public:
	zDirecciones();
	zDirecciones(zSiscomRegistros *);
	zDireccion *Direccion(int pintNDireccion);
};

#endif
