#include <zSiscomAdministracionSeguridad.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <zSiscomMenu.h>
#include <zSiscomMenus.h>
#include <zSiscomMenusVentana.h>

#include <zSiscomDesarrollo4.h>
zSiscomAdministracionSeguridad::zSiscomAdministracionSeguridad(zSiscomConexion *pzSiscomConexion,
							       const char *pchrPtrFuncion,
							       const char *pchrPtrModulo):
							  zSiscomOperaciones(pzSiscomConexion,
							  		    pchrPtrModulo,
									    pchrPtrFuncion)
{


}
zSiscomRegistros *zSiscomAdministracionSeguridad::SiscomMenusSistema(const char *pchrPtrUsuario,
								     const char *pchrPtrPassword)
{
zSiscomRegistros *lSisRegsRegreso;
zSiscomRegistro *lSisRegInformacion;
    AgregaEnvio(zSiscomRegistro().Registro("%s [Usuario] %s[Password]",
    					   pchrPtrUsuario,
					   pchrPtrPassword));
    if((lSisRegsRegreso=EnviaRecibe()))
    {
      if((lSisRegInformacion=lSisRegsRegreso->Primer()))
        if(!lSisRegInformacion->EstaElCampoEnElRegistro("EdoRegreso"))
	 return lSisRegsRegreso;
	else 
	 return 0;
    }
    else
    return 0;
}

void zSiscomAdministracionSeguridad::SiscomMenusSistema(const char *pchrPtrUsuario,
							 const char *pchrPtrPassword,
							 zSiscomMenusVentana *pzSisMenusVentana)
{
zSiscomRegistros *lzSisRegsMenusSistema;
zSiscomRegistro *lzSisRegPopupMenu;
zSiscomMenu *lzSiscomMenuPopup;
zSiscomMenus *lzSisMenusSistema;

if((lzSisRegsMenusSistema=SiscomMenusSistema(pchrPtrUsuario,pchrPtrPassword)))
{
SiscomRegistrosLog(lzSisRegsMenusSistema);
for(lzSisRegPopupMenu=lzSisRegsMenusSistema->Primer();
    lzSisRegPopupMenu;
    lzSisRegPopupMenu=lzSisRegsMenusSistema->Siguiente())
{
    LogSiscom("%s",(const char *)(*lzSisRegPopupMenu)["Nombre"]);
    lzSiscomMenuPopup=new zSiscomMenu((const char *)(*lzSisRegPopupMenu)["Nombre"]);
    AgregaPropiedadesPopupMenu(lzSisRegPopupMenu,lzSiscomMenuPopup);
    lzSisMenusSistema=new zSiscomMenus(lzSiscomMenuPopup);
    AgregaMenusAlPopupMenu(lzSisRegPopupMenu,lzSisMenusSistema);
    (*pzSisMenusVentana) << lzSisMenusSistema;
}
}
}

void zSiscomAdministracionSeguridad::AgregaPropiedadesPopupMenu(zSiscomRegistro *pzSisRegPopupMenu,
				zSiscomMenu *pzSiscomMenuPopup)
{
zSiscomRegistros *lzSisRegsPropiedades=pzSisRegPopupMenu->AsociadosDelCampo("Propiedades");
zSiscomRegistro *lzSisRegPropiedad;
SiscomRegistrosLog(lzSisRegsPropiedades);
for(lzSisRegPropiedad=lzSisRegsPropiedades->Primer();
    lzSisRegPropiedad;
    lzSisRegPropiedad=lzSisRegsPropiedades->Siguiente())
    pzSiscomMenuPopup->Propiedad((const char *)(*lzSisRegPropiedad)["Nombre"],
    				 (const char *)(*lzSisRegPropiedad)["Valor"]);
}
void zSiscomAdministracionSeguridad::AgregaPropiedadesQAction(zSiscomRegistros *pzSisRegsPropiedades,
							      zSiscomMenu *pzSiscomMenu)
{
zSiscomRegistro *lzSisRegPropiedad;
for(lzSisRegPropiedad=pzSisRegsPropiedades->Primer();
    lzSisRegPropiedad;
    lzSisRegPropiedad=pzSisRegsPropiedades->Siguiente())
        pzSiscomMenu->Propiedad((const char *)(*lzSisRegPropiedad)["Nombre"],
	                        (const char *)(*lzSisRegPropiedad)["Valor"]);
}

void zSiscomAdministracionSeguridad::AgregaMenusAlPopupMenu(zSiscomRegistro *pzSisRegPopupMenu,
			    zSiscomMenus *pzSisMenus)
{
zSiscomRegistros *lzSisRegsMenus=pzSisRegPopupMenu->AsociadosDelCampo("Menus");
zSiscomRegistro *lzSisRegMenu;
zSiscomMenu *lzSisMenu;
SiscomRegistrosLog(lzSisRegsMenus);
for(lzSisRegMenu=lzSisRegsMenus->Primer();
    lzSisRegMenu;
    lzSisRegMenu=lzSisRegsMenus->Siguiente())
{
      lzSisMenu=new zSiscomMenu((const char *)(*lzSisRegMenu)["QAction"],
                                (const char *)(*lzSisRegMenu)["Modulo"],
				(const char *)(*lzSisRegMenu)["Funcion"]);
      AgregaPropiedadesQAction(lzSisRegMenu->AsociadosDelCampo("Propiedades"),lzSisMenu);
      (*pzSisMenus) << lzSisMenu;
}
}
