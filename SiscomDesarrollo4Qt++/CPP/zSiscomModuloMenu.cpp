#include <zSiscomModuloMenu.h>
#include <zSiscomCampo.h>
#include <zSiscomDesarrollo4.h>
#include <qlibrary.h>
#include <qwidget.h>
#include <string.h>

zSiscomModuloMenu::zSiscomModuloMenu(QLibrary *pQLibModulo,
				     const char *pchrPtrModulo):
				     chrPtrModulo(pchrPtrModulo)
{
    Agrega(pQLibModulo); 
}

zSiscomFuncionMenu zSiscomModuloMenu::Ventana(const  char *pchrPtrFuncion)
{
zSiscomFuncionMenu lzSisFuncionMenu;
QLibrary *lQLibModOpcion=Primer();
if((lzSisFuncionMenu=(zSiscomFuncionMenu )lQLibModOpcion->resolve(pchrPtrFuncion)))
return lzSisFuncionMenu;
else
return 0;
}
const char *zSiscomModuloMenu::Modulo()
{
   return chrPtrModulo;
}

bool zSiscomModuloMenu::operator==(zSiscomModuloMenu *pzSisModulo)
{
  return !strcmp(Modulo(),pzSisModulo->Modulo());
}
