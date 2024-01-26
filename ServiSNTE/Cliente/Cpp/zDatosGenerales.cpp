#include <zDatosGenerales.h>
#include <zSiscomCampo.h>
zDatosGenerales::zDatosGenerales(const char *pchrPtrIdPersona)
{
  (*this)					<<
  new zSiscomCampo("IdPersona",(const unsigned char *)pchrPtrIdPersona) <<
  new zSiscomCampo("CURP")			<<
  new zSiscomCampo("EstadoNacimiento")	<<
  new zSiscomCampo("PaisNacimiento")		<<
  new zSiscomCampo("Genero")			<<
  new zSiscomCampo("EstadoCivil")		<<
  new zSiscomCampo("Edad")			<<
  new zSiscomCampo("FechaNacimiento")		<<
  new zSiscomCampo("Identificacion")		<<
  new zSiscomCampo("NoIdentificacion")	<<
  new zSiscomCampo("Ocupacion")		<<
  new zSiscomCampo("Nacionalidad");
}
zDatosGenerales::zDatosGenerales(zSiscomRegistro *pzSisRegRegreso)
{
  (*this)								<<
  new zSiscomCampo("IdPersona",(*pzSisRegRegreso)["idpersona"]) 	<<
  new zSiscomCampo("CURP",(*pzSisRegRegreso)["curp"])			<<
  new zSiscomCampo("EstadoNacimiento",(*pzSisRegRegreso)["estado"])	<<
  new zSiscomCampo("PaisNacimiento",(*pzSisRegRegreso)["pais"])		<<
  new zSiscomCampo("Genero",(*pzSisRegRegreso)["sexo"])			<<
  new zSiscomCampo("EstadoCivil",(*pzSisRegRegreso)["estadocivil"])	<<
  new zSiscomCampo("Edad",(*pzSisRegRegreso)["edad"])			<<
  new zSiscomCampo("FechaNacimiento",(*pzSisRegRegreso)["fecha"])	<<
  new zSiscomCampo("Identificacion")					<<
  new zSiscomCampo("NoIdentificacion")				<<
  new zSiscomCampo("Ocupacion",(*pzSisRegRegreso)["ocupacion"])		<<
  new zSiscomCampo("Nacionalidad",(*pzSisRegRegreso)["nacionalidad"]);
}

void zDatosGenerales::CURP(const char *pchrPtrCURP)
{
	ActualizaCampo("CURP",(unsigned char *)pchrPtrCURP);
}


void zDatosGenerales::EstadoNacimiento(const char *pchrPtrEstadoNacimiento)
{
	ActualizaCampo("EstadoNacimiento",(unsigned char *)pchrPtrEstadoNacimiento);
}
void zDatosGenerales::PaisNacimiento(const char *pchrPtrPaisNacimiento)
{
	ActualizaCampo("PaisNacimiento",(unsigned char *)pchrPtrPaisNacimiento);
}
void zDatosGenerales::Genero(const char *pchrPtrGenero)
{
	ActualizaCampo("Genero",(unsigned char *)pchrPtrGenero);
}
void zDatosGenerales::EstadoCivil(const char *pchrPtrEstadoCivil)
{
	ActualizaCampo("EstadoCivil",(unsigned char *)pchrPtrEstadoCivil);
}
void zDatosGenerales::Edad(const char *pchrPtrEdad)
{
	ActualizaCampo("Edad",(unsigned char *)pchrPtrEdad);
}
void zDatosGenerales::FechaNacimiento(const char *pchrPtrFechaNacimiento)
{
	ActualizaCampo("FechaNacimiento",(unsigned char *)pchrPtrFechaNacimiento);
}
void zDatosGenerales::Identificacion(const char *pchrPtrIdentificacion)
{
ActualizaCampo("Identificacion",(unsigned char *)pchrPtrIdentificacion);
}
void zDatosGenerales::NoIdentificacion(const char *pchrPtrNoIdentificacion)
{
ActualizaCampo("NoIdentificacion",(unsigned char *)pchrPtrNoIdentificacion);
}

void zDatosGenerales::Ocupacion(const char *pchrPtrOcupacion)
{
	ActualizaCampo("Ocupacion",(unsigned char *)pchrPtrOcupacion);
}
void zDatosGenerales::Nacionalidad(const char *pchrPtrNacionalidad)
{
	ActualizaCampo("Nacionalidad",(unsigned char *)pchrPtrNacionalidad);
}
