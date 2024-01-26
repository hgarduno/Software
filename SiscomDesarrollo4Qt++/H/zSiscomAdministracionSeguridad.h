#ifndef __ZSISCOMADMINISTRACIONSEGURIDAD_H__
#define __ZSISCOMADMINISTRACIONSEGURIDAD_H__
#include <zSiscomOperaciones.h>


class zSiscomRegistro;
class zSiscomRegistros;
class zSiscomMenusVentana;
class zSiscomMenu;
class zSiscomMenus;
class zSiscomAdministracionSeguridad:public zSiscomOperaciones
{
public:
	zSiscomAdministracionSeguridad(zSiscomConexion *pzSiscomConexion,
				      const char *pchrPtrFuncion,
				      const char *pchrPtrModulo);
	zSiscomRegistros *SiscomMenusSistema(const char *pchrPtrUsuario,
					     const char *pchrPtrPassword);
	void SiscomMenusSistema(const char *pchrPtrUsuario,
				const char *pchrPtrPassword,
				zSiscomMenusVentana *);
private:

	void AgregaMenusAlPopupMenu(zSiscomRegistro *pzSisRegPopupMenu,
				    zSiscomMenus *pzSisMenus);
	void AgregaPropiedadesPopupMenu(zSiscomRegistro *,zSiscomMenu *);
	void AgregaPropiedadesQAction(zSiscomRegistros *,zSiscomMenu *);
};

#endif
