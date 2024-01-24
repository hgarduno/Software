#include <zClaveSat.h>
#include <zSiscomCampo.h>

zClaveSat::zClaveSat()
{
	(*this) 			<< 
	new zSiscomCampo("Id")		<<
	new zSiscomCampo("Clave") 	<<
	new zSiscomCampo("Sat")		<<
	new zSiscomCampo("PalabraClave");
}
void zClaveSat::Id(const char *pchrPtrId)
{
	ActualizaCampo("Id",(const unsigned char *)pchrPtrId);
}
void zClaveSat::Clave(const char *pchrPtrClave)
{
	ActualizaCampo("Clave",(const unsigned char *)pchrPtrClave);
}

void zClaveSat::Sat(const char *pchrPtrSat)
{
	ActualizaCampo("Sat",(const unsigned char *)pchrPtrSat);
}
void zClaveSat::PalabraClave(const char *pchrPtrPalabraClave)
{
	ActualizaCampo("PalabraClave",(const unsigned char *)pchrPtrPalabraClave);
}
const char *zClaveSat::Sat()
{
	return (const char *)(*this)["Sat"];
}
const char *zClaveSat::PalabraClave()
{
	return (const char *)(*this)["PalabraClave"];
}
