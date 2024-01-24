#include <CQSisEmpleados.h>
CQSisEmpleado::CQSisEmpleado(const char *pchrPtrIdPersona,
			     const char *pchrPtrNombre,
			     const char *pchrPtrAPaterno,
			     const char *pchrPtrAMaterno,
			     const char *pchrPtrFirma,
			     const char *pchrPtrPassword,
			     const char *pchrPtrRePassword,
			     const char *pchrPtrIdPerfil,
			     const char *pchrPtrIdAplicacion)
{
SRegistroPro2	<<
"IdPersona"	<<
"Nombre"	<<
"APaterno"	<<
"AMaterno"	<<
"Firma"		<<
"Password"	<<
"RePassword"	<<
"IdPerfil"	<<
"IdAplicacion";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2					<<
SiscomCampoPro2("IdPersona",pchrPtrIdPersona)	<<
SiscomCampoPro2("Nombre",pchrPtrNombre)		<<
SiscomCampoPro2("APaterno",pchrPtrAPaterno)	<<
SiscomCampoPro2("AMaterno",pchrPtrAMaterno)	<<
SiscomCampoPro2("Firma",pchrPtrFirma)		<<
SiscomCampoPro2("Password",pchrPtrPassword)	<<
SiscomCampoPro2("RePassword",pchrPtrRePassword)	<<
SiscomCampoPro2("IdPerfil",pchrPtrIdPerfil)	<<
SiscomCampoPro2("IdAplicacion",pchrPtrIdAplicacion);
SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisEmpleado::CQSisEmpleado()
{

}
CQSisEmpleado::CQSisEmpleado(SisPersona *pSPersona):
			SPersona(pSPersona)
{

}
SisPersona *CQSisEmpleado::Persona()
{
	return SPersona;
}


CQSisLstEmpleado::CQSisLstEmpleado()
{
}
CQSisLstEmpleado &CQSisLstEmpleado::operator<<(CQSisEmpleado *pCQSEmpleado)
{
	append(pCQSEmpleado);
	return *this;
}
