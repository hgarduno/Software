#ifndef __ZSISCOMMODULOSMENUS_H__
#define __ZSISCOMMODULOSMENUS_H__
#include <zSiscomModuloMenu.h>

class zSiscomModulosMenus:public zSisLista<zSiscomModuloMenu>
{
public:
	zSiscomModulosMenus();
	zSiscomModulosMenus &operator<<(zSiscomModuloMenu *);
	zSiscomFuncionMenu Funcion(const char *pchrPtrModulo,const char *pchrPtrFuncion);
private:
	int YaEstaElModulo(zSiscomModuloMenu *);
};

#endif
