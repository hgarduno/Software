#include <QtSiscomServiSNTE.h>
#include <zSiscomConexion.h>
QtSiscomServiSNTE::QtSiscomServiSNTE(zSiscomConexion *pzSisConexion,
						zSiscomMenusVentana *pzSisMenusV):
			zSiscomVentana(pzSisConexion)
{
  AreaTrabajo();
  Menus(pzSisMenusV);
  MuestraMenus();
}

