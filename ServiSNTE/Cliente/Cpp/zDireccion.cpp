#include <zDireccion.h>
#include <zSiscomCampo.h>
zDireccion::zDireccion(const char *pchrPtrIdDireccion,
		 const char *pchrPtrCalle,
		 const char *pchrPtrNumInterior,
		 const char *pchrPtrNumExterior,
		 const char *pchrPtrColonia,
		 const char *pchrPtrDelegMunic,
		 const char *pchrPtrEstado,
		 const char *pchrPtrCodigoPostal,
		 const char *pchrPtrReferencias,
		 const char *pchrPtrIdPersona)
{
  (*this) 									<< 
  new zSiscomCampo("IdDireccion",(unsigned char *)pchrPtrIdDireccion) 		<<
  new zSiscomCampo("Calle",(unsigned char *)pchrPtrCalle)       		<<
  new zSiscomCampo("NumInterior",(unsigned char *)pchrPtrNumInterior)		<<
  new zSiscomCampo("NumExterior",(unsigned char *)pchrPtrNumExterior)		<<
  new zSiscomCampo("Colonia",(unsigned char *)pchrPtrColonia)			<<
  new zSiscomCampo("DelegMunic",(unsigned char *)pchrPtrDelegMunic)		<<
  new zSiscomCampo("Estado",(unsigned char *)pchrPtrEstado)			<<
  new zSiscomCampo("CodigoPostal",(unsigned char *)pchrPtrCodigoPostal)		<<
  new zSiscomCampo("Referencias",(unsigned char *)pchrPtrReferencias)		<<
  new zSiscomCampo("IdPersona",(unsigned char *)pchrPtrIdPersona);
}

zDireccion::zDireccion(zSiscomRegistro *pzSisRegDireccion)
{
  (*this) 								<< 
  new zSiscomCampo("IdDireccion",(*pzSisRegDireccion)["iddireccion"]) 	<<
  new zSiscomCampo("Calle",(*pzSisRegDireccion)["calle"])       	<<
  new zSiscomCampo("NumInterior",(*pzSisRegDireccion)["numinterior"])	<<
  new zSiscomCampo("NumExterior",(*pzSisRegDireccion)["numexterior"])	<<
  new zSiscomCampo("Colonia",(*pzSisRegDireccion)["colonia"])		<<
  new zSiscomCampo("DelegMunic",(*pzSisRegDireccion)["delegmunic"])	<<
  new zSiscomCampo("Estado",(*pzSisRegDireccion)["estado"])		<<
  new zSiscomCampo("CodigoPostal",(*pzSisRegDireccion)["codigopostal"])	<<
  new zSiscomCampo("Referencias",(*pzSisRegDireccion)["referencias"])	;
}
const char *zDireccion::IdDireccion()
{
  return (const char *)Campo("IdDireccion");
}


const char *zDireccion::Calle()
{
  return (const char *)Campo("Calle");
}
const char *zDireccion::NumExterior()
{
  return (const char *)Campo("NumExterior");
}
const char *zDireccion::NumInterior()
{
  return (const char *)Campo("NumInterior");
}
const char *zDireccion::Colonia()
{
  return (const char *)Campo("Colonia");
}
const char *zDireccion::Delegacion()
{
  return (const char *)Campo("DelegMunic");
}
const char *zDireccion::Estado()
{
  return (const char *)Campo("Estado");
}
const char *zDireccion::CodigoPostal()
{
  return (const char *)Campo("CodigoPostal");
}
const char *zDireccion::Referencias()
{
  return (const char *)Campo("Referencias");
}
const char *zDireccion::IdPersona()
{
  return (const char *)Campo("IdPersona");
}

int zDireccion::EsValida()
{
return ((*Calle()) 		&& 
	(*NumExterior()) 	&&
	(*Colonia())		&&
	(*Delegacion())		&&
	(*Estado())		&&
	(*CodigoPostal()));
}

void zDireccion::Calle(const char *pchrPtrCalle)
{
   ActualizaCampo("Calle",(const unsigned char *)pchrPtrCalle);
}


void zDireccion::NumExterior(const char *pchrPtrNumExterior)
{
   ActualizaCampo("NumExterior",(const unsigned char *)pchrPtrNumExterior);
}

void zDireccion::NumInterior(const char *pchrPtrNumInterior)
{
   ActualizaCampo("NumInterior",(const unsigned char *)pchrPtrNumInterior);
}

void zDireccion::Colonia(const char *pchrPtrColonia)
{
   ActualizaCampo("Colonia",(const unsigned char *)pchrPtrColonia);
}

void zDireccion::Delegacion(const char *pchrPtrDelegMunic)
{
   ActualizaCampo("DelegMunic",(const unsigned char *)pchrPtrDelegMunic);
}

void zDireccion::Estado(const char *pchrPtrEstado)
{
   ActualizaCampo("Estado",(const unsigned char *)pchrPtrEstado);
}

void zDireccion::CodigoPostal(const char *pchrPtrCodigoPostal)
{
   ActualizaCampo("CodigoPostal",(const unsigned char *)pchrPtrCodigoPostal);
}

void zDireccion::Referencias(const char *pchrPtrReferencias)
{
   ActualizaCampo("Referencias",(const unsigned char *)pchrPtrReferencias);
}

