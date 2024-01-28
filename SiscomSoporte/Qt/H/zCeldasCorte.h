#ifndef __ZCELDASCORTE_H__
#define __ZCELDASCORTE_H__

#include <zSiscomRegistros.h>

class zCeldaCorte;
class zCeldasCorte:public zSiscomRegistros
{
public:
	zCeldasCorte();
	void CeldaCorte(zCeldaCorte *);
	zCeldasCorte &operator<<(zCeldaCorte *);
};


#endif
