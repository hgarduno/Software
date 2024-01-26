#include <zCliente.h>
#include <zSiscomCampo.h>
zCliente::zCliente():zPersona()
{
  (*this)				<<
  new zSiscomCampo("Direccion")		<<
  new zSiscomCampo("Telefonos")		<<
  new zSiscomCampo("SePuedeVender")	<<
  new zSiscomCampo("Compras");
}
zCliente::zCliente(const char *pchrPtrIdPersona,
		   const char *pchrPtrNombre,
		   const char *pchrPtrAPaterno,
		   const char *pchrPtrAMaterno,
		   const char *pchrPtrRFC):
		   zPersona(pchrPtrIdPersona,
		   	    pchrPtrNombre,
			    pchrPtrAPaterno,
			    pchrPtrAMaterno,
			    pchrPtrRFC)
{

  (*this)				<<
  new zSiscomCampo("Direccion")		<<
  new zSiscomCampo("Telefonos")		<<
  new zSiscomCampo("SePuedeVender")	<<
  new zSiscomCampo("Compras");


}

void zCliente::ClientePorComprasRegistradas(zSiscomRegistro *pzSisRegistro)
{
  Cliente(pzSisRegistro->AsociadoDelCampo("Cliente"));
  if(pzSisRegistro->AsociadoDelCampo("Direcciones"))
  Direccion(pzSisRegistro->AsociadoDelCampo("Direcciones"));
  AsociadosAlCampo("Compras",pzSisRegistro->AsociadosDelCampo("Compras"));
  ActualizaCampo("SePuedeVender",pzSisRegistro->CampoAsociado("Cliente","SePuedeVender"));
}
void zCliente::Cliente(zSiscomRegistro *pzSisRegistro)
{

ActualizaCampo("IdPersona",(*pzSisRegistro)["idpersona"]);
ActualizaCampo("Nombre",(*pzSisRegistro)["nombre"]);
ActualizaCampo("APaterno",(*pzSisRegistro)["apaterno"]);
ActualizaCampo("AMaterno",(*pzSisRegistro)["amaterno"]);
ActualizaCampo("RFC",(*pzSisRegistro)["rfc"]);

  (*this)				<<
  new zSiscomCampo("Direccion")		<<
  new zSiscomCampo("Telefonos")		<<
  new zSiscomCampo("SePuedeVender")	<<
  new zSiscomCampo("Compras");

}
