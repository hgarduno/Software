#ifndef __ZCOTIZACIONESIMPORTACION_H__
#define __ZCOTIZACIONESIMPORTACION_H__
#include <zSiscomRegistros.h>


class zSiscomRegistros;
class zCotizacionesImportacion:public zSiscomRegistros
{
public:
	zCotizacionesImportacion();
	void AgregaCotizacionConsultada(zSiscomRegistro *);	
	void AgregaCotizaciones(zSiscomRegistros *pzSisRegsCotizaciones);
private:


};

#endif
