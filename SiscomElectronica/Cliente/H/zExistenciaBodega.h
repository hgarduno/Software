#ifndef __EXISTENCIABODEGA_H__
#define __EXISTENCIABODEGA_H__

#include <zSiscomRegistro.h>

class zBodega;

class zExistenciaBodega:public zSiscomRegistro
{
public:
	zExistenciaBodega(zBodega *,const char *,const char *);
	zExistenciaBodega(zBodega *);
	zExistenciaBodega();
	

	void Producto(const char *);
	void Bodega(zBodega *);
	void Existencia(const char *);
	void Cantidad(const char *);

	zBodega *Bodega();
	const char *Existencia();
	const char *Cantidad();
	const char *Producto();
};

#endif
