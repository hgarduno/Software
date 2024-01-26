#ifndef __ZPROVEEDORES_H__
#define __ZPROVEEDORES_H__
#include <zSiscomRegistros.h>

class zSiscomRegistro;

class zProveedores:public zSiscomRegistros
{
public:
	zProveedores();
	void Inicia();
	zSiscomRegistro *Proveedor();
	zSiscomRegistro *Telefono();
	int SiguienteProveedor();
	int SiguienteTelefono();

private:
	zSiscomRegistros *zSisRegsTelefonos;
	zSiscomRegistro *zSisRegProveedor;
	zSiscomRegistro *zSisRegTelefono;
	
};

#endif
