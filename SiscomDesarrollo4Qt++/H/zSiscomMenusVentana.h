#ifndef __ZSISCOMMENUSVENTANA_H__
#define __ZSISCOMMENUSVENTANA_H__
#include <zSiscomMenus.h>
class zSiscomMenusVentana:public zSisLista<zSiscomMenus>
{
public:
	zSiscomMenusVentana();
	zSiscomMenusVentana &operator<<(zSiscomMenus *);
};

#endif
