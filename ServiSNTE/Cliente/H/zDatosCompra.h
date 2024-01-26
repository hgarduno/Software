#ifndef __ZDATOSCOMPRA_H__
#define __ZDATOSCOMPRA_H__
#include <zSiscomRegistros.h>

class zDatosCompra:public zSiscomRegistros
{
public:
	zDatosCompra();
	zSiscomRegistro *Proveedor();
	zSiscomRegistros *Productos();
	zSiscomRegistros *Telefonos();
	void IniciaDatos();
private:
	zSiscomRegistros *zSisRegsDatCompra;
	zSiscomRegistro *zSisRegProveedor;
	zSiscomRegistros *zSisRegsTelefonos;

	


};

#endif
