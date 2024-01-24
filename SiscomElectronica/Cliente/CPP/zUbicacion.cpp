#include <zUbicacion.h>
#include <zSiscomCampo.h>
#include <zCajaMaterial.h>
#include <zEstante.h>
zUbicacion::zUbicacion()
{
  (*this) << 
  new zSiscomCampo("CajaMaterial") <<
  new zSiscomCampo("Estante");
}
zUbicacion::~zUbicacion()
{

}
zUbicacion::zUbicacion(zSiscomRegistro *pzSisRegRegistro)
{
zCajaMaterial *lzCajaMaterial=0;
zEstante *lzEstante=0;
if((*pzSisRegRegistro)["idcaja"])
 lzCajaMaterial=new zCajaMaterial(pzSisRegRegistro);
if((*pzSisRegRegistro)["idestante"])
 lzEstante=new zEstante(pzSisRegRegistro);

  (*this) 								<<
  new zSiscomCampo("CajaMaterial",lzCajaMaterial) 			<<
  new zSiscomCampo("Estante",lzEstante);

}
zCajaMaterial *zUbicacion::Caja()
{
   return (zCajaMaterial *)AsociadoDelCampo("CajaMaterial");
}
zEstante *zUbicacion::Estante()
{

   return (zEstante *)AsociadoDelCampo("Estante");
}
