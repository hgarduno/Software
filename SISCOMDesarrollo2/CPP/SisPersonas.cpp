#include <SisPersonas.h>
SisPersona::SisPersona(const char *pchrPtrNombre,
		       const char *pchrPtrAPaterno,
		       const char *pchrPtrAMaterno,
		       const char *pchrPtrIdPersona):
		     chrPtrNombre(pchrPtrNombre),
		     chrPtrAPaterno(pchrPtrAPaterno),
		     chrPtrAMaterno(pchrPtrAMaterno),
		     chrPtrIdPersona(pchrPtrIdPersona)
{

	SiscomAsignaInformacion();

}

void SisPersona::SiscomFormaRegistro()
{

	SRegistroPro2 			<<
	"Nombre"			<<
	"APaterno"			<<
	"AMaterno"			<<
	"IdPersona";
}
void SisPersona::SiscomAnexaRegistro()
{
	SRegistrosPro2 					<<
	SiscomCampoPro2("Nombre",chrPtrNombre)		<<
	SiscomCampoPro2("APaterno",chrPtrAPaterno)	<<
	SiscomCampoPro2("AMaterno",chrPtrAMaterno)	<<
	SiscomCampoPro2("IdPersona",chrPtrIdPersona);
}

SisLstPersona::SisLstPersona()
{

}
SisLstPersona &SisLstPersona::operator<<(SisPersona *pSisPersona)
{
	append(pSisPersona);
	return *this;
}
