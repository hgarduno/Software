#ifndef __EXISTENCIABODEGAORIDES_H__
#define __EXISTENCIABODEGAORIDES_H__
#include <zSiscomRegistro.h>


class zExistenciaBodega;
class zExistenciaBodegaOriDes:public zSiscomRegistro
{
public:
	zExistenciaBodegaOriDes(zExistenciaBodega *,
				zExistenciaBodega *);

	zExistenciaBodega *BodegaO();
 	zExistenciaBodega *BodegaD();	
};

#endif
