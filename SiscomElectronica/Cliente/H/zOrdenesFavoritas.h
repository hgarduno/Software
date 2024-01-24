#ifndef __ZORDENESFAVORITAS_H__
#define __ZORDENESFAVORITAS_H__
#include <zSiscomRegistros.h>


class zOrdenFavorita;
class zOrdenesFavoritas:public zSiscomRegistros
{
public:
	zOrdenesFavoritas();
  	void OrdenesFavoritas(zSiscomRegistros *);		

	zOrdenesFavoritas &operator<<(zOrdenFavorita *);
};
#endif
