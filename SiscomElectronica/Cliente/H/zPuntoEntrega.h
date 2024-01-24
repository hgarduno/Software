#ifndef __ZPUNTOENTREGA_H__
#define __ZPUNTOENTREGA_H__
#include  <zSiscomRegistro.h>

class zDireccion;

class zPuntoEntrega:public zSiscomRegistro
{
public:
	zPuntoEntrega(const char *,const char *,zDireccion *);
	const char *PuntoEntrega();
	zDireccion *Direccion();
	void Direccion(zDireccion *);
public:
	static zPuntoEntrega *PuntoEntrega(zSiscomRegistro *);
	
};

#endif
