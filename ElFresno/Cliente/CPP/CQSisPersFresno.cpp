#include <CQSisPersFresno.h>
#include <CQSisObjetosFresno.h>
CQSisPersFresno::CQSisPersFresno(
		   const char *pchrPtrNombre,
		   const char *pchrPtrAPaterno,
		   const char *pchrPtrAMaterno,
		   const char *pchrPtrRFC,
		   const char *pchrPtrIdPersona,
		   const char *pchrPtrIdTipoPersona,
		   const char *pchrPtrTipoPersona)
{

SRegistroPro2 		<<
"Nombre"		<<
"APaterno"		<<
"AMaterno"		<<
"RFC"			<<
"IdPersona"		<<
"IdTipoPersona"		<<
"TipoPersona";

SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

SRegistrosPro2					<<
SiscomCampoPro2("Nombre",pchrPtrNombre)		<<
SiscomCampoPro2("APaterno",pchrPtrAPaterno)	<<
SiscomCampoPro2("AMaterno",pchrPtrAMaterno)	<<
SiscomCampoPro2("RFC",pchrPtrRFC)		<<
SiscomCampoPro2("IdPersona",pchrPtrIdPersona)	<<
SiscomCampoPro2("IdTipoPersona",pchrPtrIdTipoPersona)	<<
SiscomCampoPro2("TipoPersona",pchrPtrTipoPersona);
SRegistrosPro2.SiscomAnexaRegistro();

}

CQSisPersFresnoLst::CQSisPersFresnoLst()
{

}
CQSisPersFresnoLst &CQSisPersFresnoLst::operator<<(CQSisPersFresno *pCQSPersF)
{
append(pCQSPersF);
return *this;
}

CQSisPersFresnoO::CQSisPersFresnoO(SiscomDatCom *pSisDatCom):
			SiscomOperaciones(pSisDatCom)
{


}
void CQSisPersFresnoO::Empleados(CQSisPersFresnoLst *pCQSPersFLst)
{

SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s",
			 "Empleados");
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultasElFresno",&lSRegistrosPro2);
CQSisObjetosFresno::Personas(lSRegistrosPro2,pCQSPersFLst);
}
void CQSisPersFresnoO::Borra(CQSisPersFresno *pCQSPersFresno)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisPersFresnoLst lCQSPersFLst;
	lCQSPersFLst << pCQSPersFresno;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSPersFLst);
SiscomActualiza2SubRegistros("BorraEmpleado",&lSRegistrosPro2);
}
