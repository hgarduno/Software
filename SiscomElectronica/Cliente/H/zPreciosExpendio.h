#ifndef __ZPRECIOSEXPENDIO_H__
#define __ZPRECIOSEXPENDIO_H__
#include <zSiscomRegistro.h>
class zEmpresa;
class zSiscomRegistros;

class zPreciosExpendio:public zSiscomRegistro
{
public:
	zPreciosExpendio(zEmpresa *pzEmExpendio);
  	zEmpresa *Expendio();	
	void ProductosPrecio(zSiscomRegistros *pzSisRegProductosPre);
	zSiscomRegistros *Precios();
};
#endif
