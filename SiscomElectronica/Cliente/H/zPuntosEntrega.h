#ifndef __ZPUNTOSENTREGA_H__
#define __ZPUNTOSENTREGA_H__

#include <zSiscomRegistros.h>
class zPuntoEntrega;
class zDireccion;
class zPuntosEntrega:public zSiscomRegistros
{
public:
	zPuntosEntrega();
	static zPuntosEntrega *DeConsulta(zSiscomRegistros *);
	zPuntoEntrega *PuntoEntrega(int);
	zDireccion *Direccion(int);
	

};

#endif
