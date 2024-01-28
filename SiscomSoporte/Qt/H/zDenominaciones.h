#ifndef __ZDENOMINACIONES_H__
#define __ZDENOMINACIONES_H__
#include <zSiscomRegistros.h>


class zDenominacion;
class zDenominaciones:public zSiscomRegistros
{
public:
	zDenominaciones();
	zDenominaciones &operator<<(zDenominacion *);
	void Actualiza(zSiscomRegistros *);
	int Actualiza(zDenominacion *,zSiscomRegistros *);
	zDenominacion *Denominacion(int pintFila,int pintColumna);
	
};
#endif
