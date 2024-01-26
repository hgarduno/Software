#include <zSiscomMenus.h>

zSiscomMenus::zSiscomMenus(zSiscomMenu *pzSisMenuPopMenu):
			zSisMenuPopMenu(pzSisMenuPopMenu)
{

}

zSiscomMenus &zSiscomMenus::operator<<(zSiscomMenu *pzSisMenu)
{
Agrega(pzSisMenu);
return *this;
}

const char *zSiscomMenus::PropiedadPopupMenu(const char *pchrPtrPropiedad)
{
   return zSisMenuPopMenu->Propiedad(pchrPtrPropiedad);
}
