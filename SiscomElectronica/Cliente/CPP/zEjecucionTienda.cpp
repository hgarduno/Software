#include <zEjecucionTienda.h>
#include <zSiscomCampo.h>
zEjecucionTienda::zEjecucionTienda(const char *pchrPtrNombre,
				   const char *pchrPtrPid)
{
  (*this) 								<< 
  new zSiscomCampo("Nombre",(const unsigned char *)pchrPtrNombre) 	<<
  new zSiscomCampo("Pid",(const unsigned char *)pchrPtrPid)		<<
  new zSiscomCampo("Geometria");
}

