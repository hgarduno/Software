#include <zSiscomModulosMenus.h>
#include <string.h>
zSiscomModulosMenus::zSiscomModulosMenus()
{
}

zSiscomModulosMenus &zSiscomModulosMenus::operator<<(zSiscomModuloMenu *pzSisModMenu)
{
      if(!YaEstaElModulo(pzSisModMenu))
      Agrega(pzSisModMenu);
 return (*this);
}

int zSiscomModulosMenus::YaEstaElModulo(zSiscomModuloMenu *pzSisModMenu)
{
zSiscomModuloMenu *lzSisModMenu;
  for(lzSisModMenu=Primer();lzSisModMenu;lzSisModMenu=Siguiente())
  {
       if((*lzSisModMenu)==pzSisModMenu)
       return 1;
  }
return 0;
}
zSiscomFuncionMenu zSiscomModulosMenus::Funcion(const char *pchrPtrModulo,
						const char *pchrPtrFuncion)
{
zSiscomModuloMenu *lzSisModMenu;
   for(lzSisModMenu=Primer();lzSisModMenu;lzSisModMenu=Siguiente())
  {
      if(!strcmp(lzSisModMenu->Modulo(),pchrPtrModulo))
       return lzSisModMenu->Ventana(pchrPtrFuncion);
  }


return 0;
}
