#include <zFolio.h>
#include <zSiscomCampo.h>
zFolio::zFolio()
{
 (*this)				<<
 new zSiscomCampo("IdFolio")		<<
 new zSiscomCampo("IdTienda")		<<
 new zSiscomCampo("IdTipoFolio")	<<
 new zSiscomCampo("FolioInicio")	<<
 new zSiscomCampo("FolioFin");
}


zFolio::zFolio(zSiscomRegistro *pzSisRegTienda,
	       zSiscomRegistro *pzSisRegTipoFolio,
	       const char *pchrPtrFolioInicio,
	       const char *pchrPtrFolioFin):
		zSisRegTienda(pzSisRegTienda)
{
  (*this) << 
  new zSiscomCampo("IdFolio")							<<
  new zSiscomCampo("IdTienda",(*pzSisRegTienda)["idtienda"])			<<
  new zSiscomCampo("IdTipoFolio",(*pzSisRegTipoFolio)["idtipofolio"])		<<
  new zSiscomCampo("Inicio",(const unsigned char *)pchrPtrFolioInicio)		<<
  new zSiscomCampo("Fin",(const unsigned char *)pchrPtrFolioFin);
}

			
