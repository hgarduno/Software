#include <CQSisAlumnos.h>

CQSisAlumno::CQSisAlumno(const char *pchrPtrIdPersona,
		         const char *pchrPtrIdExpendio,
		         const char *pchrPtrIdEscuela,
			 const char *pchrPtrNombre,
			 const char *pchrPtrAMaterno,
			 const char *pchrPtrAPaterno,
			 const char *pchrPtrGrupo)
{
	SRegistroPro2		<<
	"IdPersona"		<<
	"IdExpendio"		<<
	"IdEscuela"		<<
	"Nombre"		<<
	"APaterno"		<<
	"AMaterno"		<<
	"Grupo";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2						<<
	SiscomCampoPro2("IdPersona",pchrPtrIdPersona)		<<
	SiscomCampoPro2("IdExpendio",pchrPtrIdExpendio)		<<
	SiscomCampoPro2("IdEscuela",pchrPtrIdEscuela)		<<
	SiscomCampoPro2("Nombre",pchrPtrNombre)			<<
	SiscomCampoPro2("APaterno",pchrPtrAPaterno)		<<
	SiscomCampoPro2("AMaterno",pchrPtrAMaterno)		<<
	SiscomCampoPro2("Grupo",pchrPtrGrupo);
	SRegistrosPro2.SiscomAnexaRegistro();

}

CQSisLstAlumno::CQSisLstAlumno()
{

}
CQSisLstAlumno &CQSisLstAlumno::operator<<(CQSisAlumno *pCQSAlumno)
{
	append(pCQSAlumno);
	return *this;
}
CQSisOpAlumnos::CQSisOpAlumnos(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{


}

void CQSisOpAlumnos::RegistraAlumno(CQSisAlumno *pCQSAlumno,
				    SiscomRegistrosPro2 **pSRegistrosPro2)
{
CQSisLstAlumno lCQSLAlumno;

	lCQSLAlumno << pCQSAlumno;

	SiscomPonParametrosConsulta((SiscomInformacionLst*)&lCQSLAlumno);
	SiscomActualiza2SubRegistros("RegistraAlumno",pSRegistrosPro2);
}
