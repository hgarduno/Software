#ifndef __ZSISCOMMODULOMENU_H__
#define __ZSISCOMMODULOMENU_H__
#include <zSisListas.h>
class QLibrary;
class QWidget;
typedef QWidget *(*zSiscomFuncionMenu)(QWidget *,const char *);
class zSiscomModuloMenu:public zSisLista<QLibrary>
{
public:
	zSiscomModuloMenu(QLibrary *,const char *pchrPtrModulo);
	zSiscomFuncionMenu Ventana(const char *pchrPtrFuncion);
	const char *Modulo();
	bool operator==(zSiscomModuloMenu *);
private:
	const char *chrPtrModulo;
};

#endif
