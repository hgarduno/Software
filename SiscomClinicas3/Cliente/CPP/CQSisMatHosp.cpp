#include <CQSisMatHosp.h>
#include <CQSisPersonas.h>
#include <CQSisConsultas.h>
#include <CQSisObjetos.h>
#include <Seguridad3Protocolo2.h>

CQSisMatHosp::CQSisMatHosp(CQSisConsulta *pCQSConsulta,
			   SisUsuarioSeg3 *pSUSeg3Firmado,
			   const char *pchrPtrIdSerProd,
			   const char *pchrPtrIdPrecio,
			   const char *pchrPtrFecha,
			   const char *pchrPtrCantidad):
		CQSConsulta(pCQSConsulta),
		SUSeg3Firmado(pSUSeg3Firmado)
{

SRegistroPro2		<<
"IdConsulta"		<<
"IdPersona"		<<
"IdSerProd"		<<
"IdPrecio"		<<
"Fecha"			<<
"Cantidad";

SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

SRegistrosPro2							<<
SiscomCampoPro2("IdConsulta",(*CQSConsulta)["IdConsulta"])	<<
SiscomCampoPro2("IdPersona",(*SUSeg3Firmado)["IdPersona"])	<<
SiscomCampoPro2("IdSerProd",pchrPtrIdSerProd)			<<
SiscomCampoPro2("IdPrecio",pchrPtrIdPrecio)			<<
SiscomCampoPro2("Fecha",pchrPtrFecha)				<<
SiscomCampoPro2("Cantidad",pchrPtrCantidad);
SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisMatHosp::CQSisMatHosp(
		const char *pchrPtrIdConsulta,
		const char *pchrPtrIdServicio,
		const char *pchrPtrClave,
		const char *pchrPtrDescripcion,
		const char *pchrPtrIdEmpleado,
		const char *pchrPtrNmbEmpleado,
		const char *pchrPtrAPatEmpleado,
		const char *pchrPtrAMatEmpleado,
		const char *pchrPtrFecha,
		const char *pchrPtrCantidad)
{
SRegistroPro2			<<
"IdConsulta"			<<
"IdServicio"			<<
"Clave"				<<
"Descripcion"			<<
"IdEmpleado"			<<
"Nombre"			<<
"APaterno"			<<
"AMaterno"			<<
"Fecha"				<<
"Cantidad";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2						<<
SiscomCampoPro2("IdConsulta",pchrPtrIdConsulta)		<<
SiscomCampoPro2("IdServicio",pchrPtrIdServicio)		<<
SiscomCampoPro2("Clave",pchrPtrClave)			<<
SiscomCampoPro2("Descripcion",pchrPtrDescripcion)	<<
SiscomCampoPro2("IdEmpleado",pchrPtrIdEmpleado)		<<
SiscomCampoPro2("Nombre",pchrPtrNmbEmpleado)		<<
SiscomCampoPro2("APaterno",pchrPtrAPatEmpleado)		<<
SiscomCampoPro2("AMaterno",pchrPtrAMatEmpleado)		<<
SiscomCampoPro2("Fecha",pchrPtrFecha)			<<
SiscomCampoPro2("Cantidad",pchrPtrCantidad);
SRegistrosPro2.SiscomAnexaRegistro();
}
			
CQSisLstMatHosp::CQSisLstMatHosp()
{

}

CQSisLstMatHosp &CQSisLstMatHosp::operator<<(CQSisMatHosp *pCQSMHosp)
{
	append(pCQSMHosp);
	return *this;
}

CQSisOpMatHosp::CQSisOpMatHosp(SiscomDatCom *pSisDatCom):
			SiscomOperaciones(pSisDatCom)
{

}

void CQSisOpMatHosp::MatHosp(CQSisLstMatHosp *pCQSLMHosp)
{
SiscomRegistrosPro2 *lSRegistrosPro2;

SiscomPonParametrosConsulta((SiscomInformacionLst *)pCQSLMHosp);
SiscomActualiza2SubRegistros("MaterialHospitalizacion",&lSRegistrosPro2);
}
void CQSisOpMatHosp::MatHosp(const char *pchrPtrIdConsulta,
			     CQSisLstMatHosp *pCQSLMHosp)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s",
			 "MaterialHospitalizado",
			 pchrPtrIdConsulta);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultasClinicas3",&lSRegistrosPro2);
CQSisObjetos::MaterialesHospitalizado(lSRegistrosPro2,pCQSLMHosp);
}
