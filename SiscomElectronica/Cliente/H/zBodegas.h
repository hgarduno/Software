#ifndef __ZBODEGAS_H__
#define __ZBODEGAS_H__
#include <zSiscomRegistros.h>


class zBodega;
class zBodegas:public zSiscomRegistros
{
public:
	zBodegas();
	void Agrega(zBodega *);
	void BodegasExpendios(zSiscomRegistros *);
	void ObtenBodegasExpendios(zSiscomRegistros *);

};

#endif
