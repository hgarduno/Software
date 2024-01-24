#ifndef __ZTRANSFIEREBODEGABODEGA_H__
#define __ZTRANSFIEREBODEGABODEGA_H__
#include <zSiscomRegistro.h>
class zBodega;
class zTransfiereBodegaBodega:public zSiscomRegistro
{
public:
	zTransfiereBodegaBodega();
	zTransfiereBodegaBodega(zBodega *pzBodegaO,
				   zBodega *pzBodegaD,
				   const char *pchrPtrCantidad);

	void BodegaD(zBodega *);
	void BodegaO(zBodega *);
	void Cantidad(const char *);
	void CveProducto(const char *);
	
};


#endif
