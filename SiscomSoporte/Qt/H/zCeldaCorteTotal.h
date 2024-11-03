#ifndef __ZCELDACORTETOTAL_H__
#define __ZCELDACORTETOTAL_H__
#include <zCeldaCorte.h>


class zCeldaCorteTotal:public zCeldaCorte
{
public:
	zCeldaCorteTotal(int pintFila,
			 int pintColumna,
			 const char *pchrPtrColor="white");


};

#endif
