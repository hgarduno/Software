#include <zPuntoEntrega.h>
#include <zSiscomCampo.h>
#include <zDireccion.h>
zPuntoEntrega::zPuntoEntrega(const char *pchrPtrIdPEntrega,
			     const char *pchrPtrPEntrega,
			     zDireccion *pzDireccion)
{
  (*this) 									<< 
   new zSiscomCampo("IdPuntoEntrega",(unsigned char *)pchrPtrIdPEntrega)	<<
   new zSiscomCampo("PuntoEntrega",(unsigned char *)pchrPtrPEntrega) 		<<
   new zSiscomCampo("Direccion",pzDireccion);
}

zPuntoEntrega *zPuntoEntrega::PuntoEntrega(zSiscomRegistro *pzSisRegConsulta)
{
zPuntoEntrega *lzPEntrega;
lzPEntrega=new zPuntoEntrega(pzSisRegConsulta->CampoConstChar("idpuntoentrega"),
			     pzSisRegConsulta->CampoConstChar("nombre"),
			     zDireccion::Direccion(pzSisRegConsulta));
return lzPEntrega;
}
void  zPuntoEntrega::Direccion(zDireccion *pzDireccion)
{
  ActualizaCampo("Direccion",pzDireccion);
}
const char *zPuntoEntrega::PuntoEntrega()
{
	return CampoConstChar("PuntoEntrega");
}
zDireccion *zPuntoEntrega::Direccion()
{
    return (zDireccion *)AsociadoDelCampo("Direccion");
}

