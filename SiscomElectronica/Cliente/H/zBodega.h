#ifndef __ZBODEGA_H__
#define __ZBODEGA_H__

#include <zSiscomRegistro.h>


class zExpendio;
class zBodega:public zSiscomRegistro
{
public:
	zBodega(const char *,const char *);
	zBodega(zSiscomRegistro *);
	void Expendio(zExpendio *);
	const char *Bodega();
	zExpendio *Expendio();

};

#endif
