#include <zMenus.h>
#include <zQAction.h>
#include <zSiscomCampo.h>

zMenu::zMenu()
{
 (*this) 				<< 
 	new zSiscomCampo("Perfil") ;
}
void zMenu::AgregaQAction(zQAction *pzQAction)
{
  AsociadoAlCampo("Perfil",pzQAction);
}
zSiscomRegistros *zMenu::QActions()
{
   return AsociadosDelCampo("Perfil");
}
