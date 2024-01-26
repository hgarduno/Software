#include <zSiscomMenu.h>
#include <zSiscomMenus.h>
#include <zSiscomCampo.h>
#include <zSiscomDesarrollo4.h>
#include <stdlib.h>
zSiscomMenu::zSiscomMenu(const char *pchrPtrNombre,
			 const char *pchrPtrClase):
			chrPtrNombre(pchrPtrNombre),
			chrPtrClase(pchrPtrClase)
{
  Datos();
}

zSiscomMenu::zSiscomMenu(const char *pchrPtrNombre,
			 const char *pchrPtrClase,
			 const char *pchrPtrFuncion):
			chrPtrNombre(pchrPtrNombre),
			chrPtrClase(pchrPtrClase),
			chrPtrFuncion(pchrPtrFuncion)
{
  Datos();
}
void zSiscomMenu::Datos()
{
 AgregaCampo(new zSiscomCampo("Nombre",(const unsigned char *)chrPtrNombre));
 AgregaCampo(new zSiscomCampo("Propiedades"));
 AgregaCampo(new zSiscomCampo("Clase",(const unsigned char *)chrPtrClase));
 AgregaCampo(new zSiscomCampo("Funcion",(const unsigned char *)chrPtrFuncion));
 AgregaCampo(new zSiscomCampo("Imagen"));
 AgregaCampo(new zSiscomCampo("SubMenu"));
}
void zSiscomMenu::Propiedad(const char *pchrPtrNombre,
			    const char *pchrPtrValor)
{
    AsociadoAlCampo("Propiedades",Registro("%s[Nombre] %s[Valor]",pchrPtrNombre,pchrPtrValor)); 
}
void zSiscomMenu::Propiedad(zSiscomRegistro *pzSisRegPropiedad)
{
   AsociadoAlCampo("Propiedades",pzSisRegPropiedad);
}
void zSiscomMenu::Propiedades(zSiscomRegistros *pzSisRegsPropiedades)
{

}
void zSiscomMenu::Imagen(const char *pchrPtrImagen)
{

}
void zSiscomMenu::SubMenu(zSiscomMenu *pzSisMenu)
{


}
void zSiscomMenu::SubMenus(zSiscomMenus *pzSisMenSubMenus)
{
zSisMenuSubMenu=pzSisMenSubMenus;
}
const char *zSiscomMenu::Propiedad(const char *pchrPtrPropiedad)
{
zSiscomRegistros *lzSisRegsPropiedades=AsociadosDelCampo("Propiedades");
zSiscomRegistro *lzSisRegistro=lzSisRegsPropiedades->PorCampoDato("Nombre",(const unsigned char *)pchrPtrPropiedad);
if(lzSisRegistro)
return (const char *)lzSisRegistro->Campo("Valor");
else
return "";
}

int zSiscomMenu::PropiedadAInt(const char *pchrPtrPropiedad)
{
return atoi(Propiedad(pchrPtrPropiedad));
}

const char *zSiscomMenu::Nombre()
{
 return chrPtrNombre;
}

const char *zSiscomMenu::Clase()
{
 return chrPtrClase;
}
const char *zSiscomMenu::Funcion()
{
return chrPtrFuncion;
}
