#include <zCajaMaterial.h>

#include <zSiscomCampo.h>
zCajaMaterial::zCajaMaterial()
{
(*this) 			<< 
new zSiscomCampo("IdCaja")	<<
new zSiscomCampo("Caja")	<<
new zSiscomCampo("Descripcion") ;

}

zCajaMaterial::zCajaMaterial(zSiscomRegistro *pzSisRegRegistro)
{

(*this) 			<< 
new zSiscomCampo("IdCaja")	<<
new zSiscomCampo("Caja")	<<
new zSiscomCampo("Descripcion") ;

  IdCajaMaterial((const char *)(*pzSisRegRegistro)["idcaja"]);
  Caja((const char *)(*pzSisRegRegistro)["caja"]);
}
void zCajaMaterial::IdCajaMaterial(const char *pchrPtrIdCaja)
{
   ActualizaCampo("IdCaja",(const unsigned char *)pchrPtrIdCaja);
}
void zCajaMaterial::Caja(const char *pchrPtrCaja)
{
  ActualizaCampo("Caja",(const unsigned char *)pchrPtrCaja);
}
void zCajaMaterial::Descripcion(const char *pchrPtrDescripcion)
{
  ActualizaCampo("Descripcion",(const unsigned char *)pchrPtrDescripcion);
}
const char *zCajaMaterial::Caja()
{
  return (const char *)Campo("Caja");
}
