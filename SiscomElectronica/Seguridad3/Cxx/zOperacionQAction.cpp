#include <zOperacionQAction.h>

#include <zSiscomCampo.h>
#include <zMenus.h>
zOperacionQAction::zOperacionQAction(zSiscomConexion *pzSisConexion,
			             zMenu *pzMenu):
			zSiscomOperaciones(pzSisConexion)
{
 PreparaEnvio();
 Primer()->AsociadoAlCampo("Envio",pzMenu); 
}

void zOperacionQAction::PreparaEnvio()
{
zSiscomRegistro *lzSisReg;
lzSisReg=new zSiscomRegistro;
(*lzSisReg) << new zSiscomCampo("Envio");
  (*this) <<  lzSisReg;
}
