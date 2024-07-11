#ifndef __ZDENOMINACIONES_H__
#define __ZDENOMINACIONES_H__
#include <zSiscomRegistros.h>


class zDenominacion;
class zDenominaciones:public zSiscomRegistros
{
public:
	zDenominaciones();
	zDenominaciones(zSiscomRegistros *);
	zDenominaciones &operator<<(zDenominacion *);
	void Actualiza(zSiscomRegistros *);
	int Actualiza(zDenominacion *,zSiscomRegistros *);
	zDenominacion *Denominacion(int pintFila,int pintColumna);

	void ActualizaCantidades(zDenominaciones *);
	void ActualizaCantidad(zDenominacion *,zDenominaciones *);
	
	void ActualizaImportes(zDenominaciones *);
	void ActualizaImporte(zDenominacion *,zDenominaciones *);
	
};
#endif
