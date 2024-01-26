#include <zSiscomQAction.h>
#include <zSiscomMenu.h>
#include <zSiscomRegistros.h>
#include <zSiscomCampo.h>
#include <qvariant.h>
#include <qworkspace.h>
zSiscomQAction::zSiscomQAction(QObject *pQOParent,
			       zSiscomMenu *pzSisMenu):
			       QAction(pQOParent),
				zSisMenu(pzSisMenu)
{
AsignaPropiedades();
ConectaSlots();

}
void zSiscomQAction::ConectaSlots()
{
     connect(this,
     	     SIGNAL(activated()),
	     SLOT(SlotSelecciono()));
}
void zSiscomQAction::SlotSelecciono()
{
  emit SignalSelecciono(this);
}
void zSiscomQAction::AsignaPropiedades()
{
zSiscomRegistro *lzSisRegPropiedad;
zSiscomRegistros *lzSisRegPropiedades=zSisMenu->AsociadosDelCampo("Propiedades");
for(lzSisRegPropiedad=lzSisRegPropiedades->Primer();
    lzSisRegPropiedad;
    lzSisRegPropiedad=lzSisRegPropiedades->Siguiente())
   setProperty((const char *)lzSisRegPropiedad->CampoDato("Nombre")->Dato(),
   		QVariant((const char *)lzSisRegPropiedad->CampoDato("Valor")->Dato()));
}
zSiscomMenu *zSiscomQAction::Menu()
{
 return zSisMenu;
}
void zSiscomQAction::AreaTrabajo(QWorkspace *pQWSAreaTrabajo)
{
   QWSAreaTrabajo=pQWSAreaTrabajo;
}
