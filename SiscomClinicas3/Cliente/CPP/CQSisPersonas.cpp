#include <CQSisPersonas.h>
#include <CQSisObjetos.h>
CQSisPersona::CQSisPersona(const char *pchrPtrIdPersona,
			   const char *pchrPtrNombre,
			   const char *pchrPtrAPaterno,
			   const char *pchrPtrAMaterno,
			   const char *pchrPtrRFC,
			   const char *pchrPtrFirma,
			   const char *pchrPtrPassword,
			   const char *pchrPtrRePassword,
			   const char *pchrPtrIdPerfil)
{
SRegistroPro2			<<
"IdPersona"			<<
"Nombre"			<<
"APaterno"			<<
"AMaterno"			<<
"RFC"				<<
"Firma"				<<
"Password"			<<
"RePassword"			<<
"IdPerfil";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2					<<
SiscomCampoPro2("IdPersona",pchrPtrIdPersona)	<<
SiscomCampoPro2("Nombre",pchrPtrNombre)		<<
SiscomCampoPro2("APaterno",pchrPtrAPaterno)	<<
SiscomCampoPro2("AMaterno",pchrPtrAMaterno)	<<
SiscomCampoPro2("RFC",pchrPtrRFC)		<<
SiscomCampoPro2("Firma",pchrPtrFirma)		<<
SiscomCampoPro2("Password",pchrPtrPassword)	<<
SiscomCampoPro2("RePassword",pchrPtrRePassword)	<<
SiscomCampoPro2("IdPerfil",pchrPtrIdPerfil);
SRegistrosPro2.SiscomAnexaRegistro();
}

CQSisLstPersona::CQSisLstPersona()
{

}
CQSisLstPersona &CQSisLstPersona::operator<<(CQSisPersona *pCQSPersona)
{
	append(pCQSPersona);
	return *this;
}
CQSisOpPersona::CQSisOpPersona(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{

}

void CQSisOpPersona::Empleado(CQSisPersona *pCQSPersona,
			      SiscomRegistrosPro2 **pSRegistrosPro2)
{
CQSisLstPersona lCQSLPersona;
		lCQSLPersona << pCQSPersona;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLPersona);
SiscomActualiza2SubRegistros("RegistraEmpleado",pSRegistrosPro2);
}

void CQSisOpPersona::Empleados(const char *pchrPtrPerfil,
				CQSisLstPersona *pCQSLPersona)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s",
			 "Empleados",
			 pchrPtrPerfil);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
EliminaPersonas(pCQSLPersona);
SiscomConsulta("ConsultasClinicas3",&lSRegistrosPro2);
CQSisObjetos::Personas(lSRegistrosPro2,pCQSLPersona);
}
void CQSisOpPersona::EliminaPersonas(CQSisLstPersona *pCQSLPersonas)
{
	pCQSLPersonas->setAutoDelete(true);
	pCQSLPersonas->clear();
	pCQSLPersonas->setAutoDelete(false);
}

void CQSisOpPersona::Paciente(CQSisPersona *pCQSPersona,
			      SiscomRegistrosPro2 **pSRegistrosPro2)
{
CQSisLstPersona lCQSLPersona;
		lCQSLPersona << pCQSPersona;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLPersona);
SiscomActualiza2SubRegistros("RegistraPaciente",pSRegistrosPro2);
}

void CQSisOpPersona::PacientesSimilares(CQSisPersona *pCQSPersona,
			      SiscomRegistrosPro2 **pSRegistrosPro2)
{
CQSisLstPersona lCQSLPersona;
		lCQSLPersona << pCQSPersona;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLPersona);
SiscomActualiza2SubRegistros("PacientesSimilares",pSRegistrosPro2);
}

void CQSisOpPersona::ActualizaNombre(CQSisPersona *pCQSPersona,
				     SiscomRegistrosPro2 **pSRegistrosPro2)
{
CQSisLstPersona lCQSLPersona;
		lCQSLPersona << pCQSPersona;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLPersona);
SiscomActualiza2SubRegistros("ActualizaPersona",pSRegistrosPro2);

}
