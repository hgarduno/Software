#ifndef __ZMENUS_H__
#define __ZMENUS_H__

#include <zSiscomRegistro.h>

class zQAction;
class zMenu:public zSiscomRegistro
{
public:
	zMenu();
	void AgregaQAction(zQAction *);
	zSiscomRegistros *QActions();

};


#endif

