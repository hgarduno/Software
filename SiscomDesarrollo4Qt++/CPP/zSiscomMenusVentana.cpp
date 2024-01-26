#include <zSiscomMenusVentana.h>

zSiscomMenusVentana::zSiscomMenusVentana()
{

}
zSiscomMenusVentana &zSiscomMenusVentana::operator<<(zSiscomMenus *pzSisMenus)
{
   Agrega(pzSisMenus);
   return *this;
}
