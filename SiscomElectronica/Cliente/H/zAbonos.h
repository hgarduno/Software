#ifndef __ZABONOS_H__
#define __ZABONOS_H__

#include <zSiscomRegistros.h>


class zAbonoAApartado;

class zAbonos:public zSiscomRegistros
{
public:
	zAbonos();
	void Agrega(zAbonoAApartado *);
	void Abonos(zSiscomRegistros *);
	void AgregaAbonos(zSiscomRegistro *);
};

#endif
