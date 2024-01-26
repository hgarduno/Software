#ifndef __ZCAMION_H__
#define __ZCAMION_H__

#include <zSiscomRegistro.h>


class zCamion:public zSiscomRegistro
{
public:
	zCamion(const char *pchrPtrIdCamion,
		 const char *pchrPtrNombre,
		 const char *pchrPtrMarca,
		 const char *pchrPtrTipo,
		 const char *pchrPtrModelo,
		 const char *pchrPtrPlacas);

};

#endif
