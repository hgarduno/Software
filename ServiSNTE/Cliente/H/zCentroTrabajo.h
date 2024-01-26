#ifndef __ZCENTROTRABAJO_H__
#define __ZCENTROTRABAJO_H__
#include <zSiscomRegistro.h>

class zCentroTrabajo:public zSiscomRegistro
{
public:
	zCentroTrabajo();
	zCentroTrabajo(zSiscomRegistro *pzSisRegTrabajo);
	zCentroTrabajo(const char *pchrPtrIdPersona,
		       const char *pchrPtrCentroTrabajo,
		       const char *pchrPtrClavePresupuestal);
};

#endif
