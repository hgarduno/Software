#include <Contactos.h>

Contacto::Contacto(const char *pchrPtrNombre,
		   const char *pchrPtrAPaterno,
		   const char *pchrPtrAMaterno,
		   const char *pchrPtrRFC,
		   const char *pchrPtrIdPersona,
		   const char *pchrPtrDescripcion,
		   const char *pchrPtrIdEmpresa)
{
	SRegistroPro2			<<
	"Nombre"			<<
	"APaterno"			<<
	"AMaterno"			<<
	"RFC"				<<
	"IdPersona"			<<
	"Descripcion"			<<
	"IdEmpresa";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2						<<
	SiscomCampoPro2("Nombre",pchrPtrNombre)			<<
	SiscomCampoPro2("APaterno",pchrPtrAPaterno)		<<
	SiscomCampoPro2("AMaterno",pchrPtrAMaterno)		<<
	SiscomCampoPro2("RFC",pchrPtrRFC)			<<
	SiscomCampoPro2("IdPersona",pchrPtrIdPersona)		<<
	SiscomCampoPro2("Descripcion",pchrPtrDescripcion)	<<
	SiscomCampoPro2("IdEmpresa",pchrPtrIdEmpresa);	
	SRegistrosPro2.SiscomAnexaRegistro();


}
