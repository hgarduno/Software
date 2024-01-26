#ifndef __ZOTROSINGRESOS_H__
#define __ZOTROSINGRESOS_H__
#include <zSiscomRegistro.h>

class zOtrosIngresos:public zSiscomRegistro
{

public:
	zOtrosIngresos(const char *pchrPtrIdPersona);
	zOtrosIngresos();
	zOtrosIngresos *DesdeDatosEmpleo(zSiscomRegistro *pzSisRegEmpleo);
	void Monto(const char *pchrPtrMonto);
	void Descripcion(const char *pchrPtrMonto);
};

#endif
