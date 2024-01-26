#ifndef __ZEMPRESA_H__
#define __ZEMPRESA_H__
#include <zSiscomRegistro.h>

class zDireccion;
class zTelefonos;
class zCorreo;
class zEmpresa:public zSiscomRegistro
{
public:
	zEmpresa(const char *pchrPtrIdEmpresa);
	zEmpresa();
	zEmpresa *DesdeDatosEmpleo(zSiscomRegistro *pzSisRegEmpleo);
	zDireccion *Direccion();
	zTelefonos *Telefonos();
	zCorreo *Correo();
	const char *Giro();
	void IdEmpresa(const char *pchrPtrIdEmpresa);
	void RazonSocial(const char *pchrPtrRazonSocial);
	void Direccion(zDireccion *pzDireccion);
	void Telefonos(zTelefonos *pzTelefonos);
	void Correos(zCorreo *pzCorreo);
	void Giro(const char *pchrPtrGiro);
	/* Para saber si la empresa esta registrada o no en la base */
	void EdoRegistro(const char *pchrPtrEdoRegistro);
};

#endif
