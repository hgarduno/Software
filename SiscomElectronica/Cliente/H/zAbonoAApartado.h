#ifndef __ZABONOAAPARTADO_H__
#define __ZABONOAAPARTADO_H__

#include <zSiscomRegistro.h> 



class zAbonoAApartado:public zSiscomRegistro
{
public:
	zAbonoAApartado(const char *pchrPtrIdVenta);
	zAbonoAApartado(zSiscomRegistro *);
	void Fecha(const char *);
	void Importe(const char *);



};

#endif
