#ifndef __ZSISCOMENU_H__
#define __ZSISCOMENU_H__
#include <zSiscomRegistro.h>
class zSiscomMenus;
class zSiscomMenu:public zSiscomRegistro
{
public:
	zSiscomMenu(const char *pchrPtrNombre,const char *pchrPtrClase=0);
	zSiscomMenu(const char *pchrPtrNombre,const char *pchrPtrClase,const char *pchrPtrFuncion);
	void Propiedad(const char *pchrPtrNombre,
		       const char *pchrPtrValor);
	void Propiedad(zSiscomRegistro *pzSisRegistro);
	void Propiedades(zSiscomRegistros *pzSisRegistros);
	void Imagen(const char *pchrPtrImagen);
	void SubMenu(zSiscomMenu *pzSisMenu);
	void SubMenus(zSiscomMenus *pzSisMenus);
	const char *Propiedad(const char *pchrPtrPropiedad);
	int PropiedadAInt(const char *pchrPtrPropiedad);

	const char *Nombre();
	const char *Clase();
	const char *Funcion();
private:
	void Datos();

private:
	const char *chrPtrNombre;
	const char *chrPtrClase;
	const char *chrPtrFuncion;
	zSiscomMenus *zSisMenuSubMenu;
};


#endif
