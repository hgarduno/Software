#ifndef __TRANSFERENCIASBODEGABODEGA_H__
#define __TRANSFERENCIASBODEGABODEGA_H__
#include <zSiscomRegistros.h>

class zExistenciaBodegaOriDes;
class zExistenciaBodega;
class zTransferenciasBodegaBodega:public zSiscomRegistros
{
public:
	zTransferenciasBodegaBodega();
	void Agrega(zExistenciaBodegaOriDes *pzExistenciaBodOriDes);
	zExistenciaBodega *TransferenciaO(int );	
	zExistenciaBodega *TransferenciaD(int );	
	const char *BodegaO(int );
	const char *BodegaD(int );
	const char *ExistenciaO(int);
	const char *ExistenciaD(int);
	const char *Producto(int);
	const char *Cantidad(int);


};

#endif
