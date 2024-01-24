#include <CQSisConsultas.h>
#include <CQSisPersonas.h>
#include <CQSisObjetos.h>
CQSisConsulta::CQSisConsulta(
		const char *pchrPtrIdConsulta,
		const char *pchrPtrIdMedico,
		const char *pchrPtrIdEmpleado,
		const char *pchrPtrIdPaciente,
		const char *pchrPtrFecha,
		const char *pchrPtrIdEdo)
{
SRegistroPro2 		<<
"IdConsulta"		<<
"IdMedico"		<<
"IdEmpleado"		<<
"IdPaciente"		<<
"Fecha"			<<
"IdEdo"			<<
"Estado"		<<
"NoConsulta";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2			<<
SiscomCampoPro2("IdConsulta",pchrPtrIdConsulta)	<<
SiscomCampoPro2("IdMedico",pchrPtrIdMedico)	<<
SiscomCampoPro2("IdEmpleado",pchrPtrIdEmpleado)	<<
SiscomCampoPro2("IdPaciente",pchrPtrIdPaciente)	<<
SiscomCampoPro2("Fecha",pchrPtrFecha)	<<
SiscomCampoPro2("IdEdo",pchrPtrIdEdo)	<<
SiscomCampoPro2("Estado","")		<<
SiscomCampoPro2("NoConsulta","");
SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisConsulta::CQSisConsulta(
		const char *pchrPtrIdConsulta,
		CQSisPersona *pCQSPPaciente,
		CQSisPersona *pCQSPMedico,
		CQSisPersona *pCQSPEmpleado,
		const char *pchrPtrFecha,
		const char *pchrPtrNoConsulta,
		const char *pchrPtrIdEdo,
		const char *pchrPtrEstado):
		CQSPPaciente(pCQSPPaciente),
		CQSPMedico(pCQSPMedico),
		CQSPEmpleado(pCQSPEmpleado)
{
SRegistroPro2 		<<
"IdConsulta"		<<
"Fecha"			<<
"IdEdo"			<<
"Estado"		<<
"NoConsulta";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2			<<
SiscomCampoPro2("IdConsulta",pchrPtrIdConsulta)	<<
SiscomCampoPro2("Fecha",pchrPtrFecha)	<<
SiscomCampoPro2("IdEdo",pchrPtrIdEdo)	<<
SiscomCampoPro2("Estado",pchrPtrEstado)		<<
SiscomCampoPro2("NoConsulta",pchrPtrNoConsulta);
SRegistrosPro2.SiscomAnexaRegistro();
}

CQSisPersona *CQSisConsulta::Medico()
{
	return CQSPMedico;
}
CQSisPersona *CQSisConsulta::Paciente()
{
	return CQSPPaciente;
}
CQSisPersona *CQSisConsulta::Empleado()
{
	return CQSPEmpleado;
}

			
CQSisLstConsulta::CQSisLstConsulta()
{

}
CQSisLstConsulta &CQSisLstConsulta::operator<<(CQSisConsulta *pCQSConsulta)
{
	append(pCQSConsulta);
	return *this;
}

CQSisOpConsulta::CQSisOpConsulta(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{

}
void CQSisOpConsulta::Consulta(CQSisConsulta *pCQSConsulta,
			       SiscomRegistrosPro2 **pSRegistrosPro2)
{
CQSisLstConsulta lCQSLConsulta;
	lCQSLConsulta << pCQSConsulta;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLConsulta);
SiscomActualiza2SubRegistros("RegistraConsulta",pSRegistrosPro2);
}

void CQSisOpConsulta::ConsultasPendientesMedico(
			const char *pchrPtrIdMedico,
			const char *pchrPtrFechaIni,
			const char *pchrPtrFechaFin,
			char *pchrPtrNoConsultas)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s%s%s",
			 "ConsultasPendientesMedico",
			 pchrPtrIdMedico,
			 pchrPtrFechaIni,
			 pchrPtrFechaFin);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultasClinicas3",&lSRegistrosPro2);
strcpy(pchrPtrNoConsultas,(*lSRegistrosPro2)["NoConsultas"]);
}
void CQSisOpConsulta::Consultas(
			const char *pchrPtrConsulta,
			const char *pchrPtrFechaIni,
			const char *pchrPtrFechaFin,
			const char *pchrPtrEstado,
			const char *pchrPtrIdMedico,
			CQSisLstConsulta *pCQSLConsultas)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s%s%s%s%s",
			 "Consultas",
			 pchrPtrConsulta,
			 pchrPtrFechaIni,
			 pchrPtrFechaFin,
			 pchrPtrEstado,
			 pchrPtrIdMedico);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
EliminaConsulta(pCQSLConsultas);
SiscomConsulta("ConsultasClinicas3",&lSRegistrosPro2);
CQSisObjetos::Consultas(lSRegistrosPro2,pCQSLConsultas);
}
void CQSisOpConsulta::ConsultaActualMedico(const char *pchrPtrIdMedico,
					   CQSisLstConsulta *pCQSLConsultas)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s",
			 "ConsultaActualMedico",
			 pchrPtrIdMedico);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
EliminaConsulta(pCQSLConsultas);
SiscomConsulta("ConsultasClinicas3",&lSRegistrosPro2);
CQSisObjetos::Consultas(lSRegistrosPro2,pCQSLConsultas);
}
void CQSisOpConsulta::EliminaConsulta(CQSisLstConsulta *pCQSLConsulta)
{
pCQSLConsulta->setAutoDelete(true);
pCQSLConsulta->clear();
pCQSLConsulta->setAutoDelete(false);
}
