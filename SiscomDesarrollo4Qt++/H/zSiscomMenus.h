#ifndef __ZSISCOMMENUS_H__
#define __ZSISCOMMENUS_H__
#include <zSiscomRegistros.h>
#include <zSiscomMenu.h>

class zSiscomMenus:public zSiscomRegistros
{
public:
	zSiscomMenus(zSiscomMenu *pzSisMenuPopMenu);
	zSiscomMenus &operator<<(zSiscomMenu *);
	const char *PropiedadPopupMenu(const char *pchrPtrPropiedad);
private:
	zSiscomMenu *zSisMenuPopMenu;
};

#endif
