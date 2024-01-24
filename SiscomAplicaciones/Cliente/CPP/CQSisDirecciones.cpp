#include <CQSisDirecciones.h>
#include <CQSisObjetosAplicaciones.h>
#include <SisDirecciones.h>
CQSisDireccion::CQSisDireccion(
		const char *pchrPtrCalle,
		const char *pchrPtrNumero,
		const char *pchrPtrReferencias,
		const char *pchrPtrAsentamiento,
		const char *pchrPtrTipoAsentamiento,
		const char *pchrPtrEstado,
		const char *pchrPtrMunicipio)
{
SRegistroPro2		<<
"Calle"			<<
"Numero"		<<
"Referencias"		<<
"Asentamiento"		<<
"TipoAsentamiento"	<<
"Estado"		<<
"Municipio";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2 							<<
SiscomCampoPro2("Calle",pchrPtrCalle)				<<
SiscomCampoPro2("Numero",pchrPtrNumero)				<<
SiscomCampoPro2("Referencias",pchrPtrReferencias)		<<
SiscomCampoPro2("Asentamiento",pchrPtrAsentamiento)		<<
SiscomCampoPro2("TipoAsentamiento",pchrPtrTipoAsentamiento)	<<
SiscomCampoPro2("Estado",pchrPtrEstado)				<<
SiscomCampoPro2("Municipio",pchrPtrMunicipio);
SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisDireccion::CQSisDireccion(const char *pchrPtrCalle,
			       const char *pchrPtrNumero,
			       const char *pchrPtrReferencias,
			       const char *pchrPtrIdAsentamiento,
			       const char *pchrPtrIdPersona)
{
SRegistroPro2			<<
"Calle"				<<
"Numero"			<<
"Referencias"			<<
"IdAsentamiento"		<<
"IdPersona";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2						<<
SiscomCampoPro2("Calle",pchrPtrCalle)			<<
SiscomCampoPro2("Numero",pchrPtrNumero)			<<
SiscomCampoPro2("Referencias",pchrPtrReferencias)	<<
SiscomCampoPro2("IdAsentamiento",pchrPtrIdAsentamiento)	<<
SiscomCampoPro2("IdPersona",pchrPtrIdPersona);

SRegistrosPro2.SiscomAnexaRegistro();


}
CQSisLstDireccion::CQSisLstDireccion()
{

}
CQSisLstDireccion &CQSisLstDireccion::operator<<(CQSisDireccion *pCQSDireccion)
{
	append(pCQSDireccion);
	return *this;
}
CQSisOpDireccion::CQSisOpDireccion(SiscomDatCom *pSisDatCom,
				   const char *pchrPtrSistemaConsulta):
		SiscomOperaciones(pSisDatCom),
		chrPtrSistemaConsulta(pchrPtrSistemaConsulta)
{


}

CQSisOpDireccion::CQSisOpDireccion(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{


}
void CQSisOpDireccion::DireccionesPersona(
			const char *pchrPtrIdPersona,
			CQSisLstDireccion *pCQSLDireccion)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s",
			 "DireccionesPersona",
			 pchrPtrIdPersona);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta(chrPtrSistemaConsulta,&lSRegistrosPro2);
CQSisObjetosAplicaciones::Direcciones(lSRegistrosPro2,pCQSLDireccion);
}
void CQSisOpDireccion::Registra(CQSisDireccion *pCQSDireccion)
{
CQSisLstDireccion lCQSLDireccion;

SiscomRegistrosPro2 *lSRegistrosPro2;
lCQSLDireccion	<< pCQSDireccion;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLDireccion);
SiscomActualiza2SubRegistros("RegistraDireccion",&lSRegistrosPro2);
}
