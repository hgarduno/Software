#include <zCargoPublico.h>
#include <zSiscomCampo.h>
zCargoPublico::zCargoPublico(const char *pchrPtrIdPersona)
{
 (*this) 									<<
 new zSiscomCampo("IdPersona",(const unsigned char *)pchrPtrIdPersona)		<<
 new zSiscomCampo("IdCargoPublico")						<<
 new zSiscomCampo("Descripcion")						<<
 new zSiscomCampo("Dependencia")						<<
 new zSiscomCampo("Puesto")							<<
 new zSiscomCampo("Funciones")						<<
 new zSiscomCampo("Periodo");
}
void zCargoPublico::IdCargoPublico(const char *pchrPtrIdCargoPublico)
{
	ActualizaCampo("IdCargoPublico",(const unsigned char *)pchrPtrIdCargoPublico);
}
void zCargoPublico::Descripcion(const char *pchrPtrDescripcion)
{
	ActualizaCampo("Descripcion",(const unsigned char *)pchrPtrDescripcion);
}


void zCargoPublico::Dependencia(const char *pchrPtrDependencia)
{
	ActualizaCampo("Dependencia",(const unsigned char *)pchrPtrDependencia);
}
void zCargoPublico::Puesto(const char *pchrPtrPuesto)
{
	ActualizaCampo("Puesto",(const unsigned char *)pchrPtrPuesto);
}
void zCargoPublico::Funciones(const char *pchrPtrFunciones)
{
	ActualizaCampo("Funciones",(const unsigned char *)pchrPtrFunciones);
}
void zCargoPublico::Periodo(const char *pchrPtrPeriodo)
{
	ActualizaCampo("Periodo",(const unsigned char *)pchrPtrPeriodo);
}
