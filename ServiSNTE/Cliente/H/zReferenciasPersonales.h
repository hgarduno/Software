#ifndef __ZREFERENCIASPERSONALES_H__
#define __ZREFERENCIASPERSONALES_H__
#include <zSiscomRegistro.h>

class zDireccion;
class zPersona;
class zParentesco;
class zTelefonos;
class zSiscomRegistros;
class zReferenciasPersonales:public zSiscomRegistro
{
public:
	zReferenciasPersonales(const char *pchrPtrIdCliente);
	zReferenciasPersonales(zSiscomRegistros *pzSisRegsReferencias);
	void Direccion(zDireccion *pzDireccion);
	void Nombre(zPersona *pzPersona);
	void Parentesco(zParentesco *pzParentesco);
	void Telefonos(zTelefonos *pzTelefonos);
	zSiscomRegistros *Direcciones();
	zSiscomRegistros *Nombres();
	zSiscomRegistros *Parentescos();
	zSiscomRegistros *Telefonos();
private:
	void Campos();
};

#endif
