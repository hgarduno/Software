#ifndef __ZPRECIOS_H__
#define __ZPRECIOS_H__

#include <zSiscomRegistros.h>

class zPrecio;
class zPrecios:public zSiscomRegistros
{
public:
	zPrecios();
	zPrecios &operator<<(zPrecio *);

};

#endif
