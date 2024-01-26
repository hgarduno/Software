#include <zCamion.h>
#include <zSiscomCampo.h>
zCamion::zCamion(const char *pchrPtrIdCamion,
		 const char *pchrPtrNombre,
		 const char *pchrPtrMarca,
		 const char *pchrPtrTipo,
		 const char *pchrPtrModelo,
		 const char *pchrPtrPlacas)
{
  (*this) 							<< 
  new zSiscomCampo("IdCamion",(unsigned char *)pchrPtrIdCamion) 	<<
  new zSiscomCampo("Nombre",(unsigned char *)pchrPtrNombre)       	<<
  new zSiscomCampo("Marca",(unsigned char *)pchrPtrMarca)	<<
  new zSiscomCampo("Tipo",(unsigned char *)pchrPtrTipo)	<<
  new zSiscomCampo("Modelo",(unsigned char *)pchrPtrModelo)	<<
  new zSiscomCampo("Placas",(unsigned char *)pchrPtrPlacas) ;
}
