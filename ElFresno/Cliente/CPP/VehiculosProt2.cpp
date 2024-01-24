#include <VehiculosProt2.h>
VehiculoProt2::VehiculoProt2(const char *pchrPtrIdVehiculo,
			     const char *pchrPtrPlacas,
			     const char *pchrPtrDescripcion)
{
	SRegistroPro2 <<
	"IdVehiculo"  <<
	"Placas"      <<
	"Descripcion" ;

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2 <<
	SiscomCampoPro2("IdVehiculo",pchrPtrIdVehiculo) <<
	SiscomCampoPro2("Placas",pchrPtrPlacas) <<
	SiscomCampoPro2("Descripcion",pchrPtrDescripcion);

	SRegistrosPro2.SiscomAnexaRegistro();
}
Vehiculos2::Vehiculos2()
{


}
void Vehiculos2::GeneraRegistros(const SiscomComunicaSrv *pSComunicaSrv)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);	

	for(;
	     !lSRegistrosPro2.SiscomEsElUltimoRegistro();
	     ++lSRegistrosPro2)
	  append(new Vehiculo(lSRegistrosPro2["idvehiculo"],
	  		      lSRegistrosPro2["placas"],
			      lSRegistrosPro2["dscvehiculo"]));
}

