#include <CQSisExpedientes.h>
#include <CQSisObjetos.h>
#include <CQSisPersonas.h>

CQSisExpediente::CQSisExpediente(CQSisPersona *pCQSMedico,
				const char *pchrPtrObservaciones,
				const char *pchrPtrFecha):
				CQSMedico(pCQSMedico)
{
SRegistroPro2		<<
"Observaciones"		<<
"Fecha";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2						<<
SiscomCampoPro2("Observaciones",pchrPtrObservaciones)	<<
SiscomCampoPro2("Fecha",pchrPtrFecha);
SRegistrosPro2.SiscomAnexaRegistro();


}
CQSisExpediente::CQSisExpediente(
			const char *pchrPtrIdConsulta,
			const char *pchrPtrObservaciones,
			const char *pchrPtrFecha)
{

SRegistroPro2		<<
"IdConsulta"		<<
"Observaciones"		<<
"Fecha";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2						<<
SiscomCampoPro2("IdConsulta",pchrPtrIdConsulta)		<<
SiscomCampoPro2("Observaciones",pchrPtrObservaciones)	<<
SiscomCampoPro2("Fecha",pchrPtrFecha);
SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisPersona *CQSisExpediente::Medico()
{
	return CQSMedico;
}
CQSisLstExpediente::CQSisLstExpediente()
{

}
CQSisLstExpediente &CQSisLstExpediente::operator<<(CQSisExpediente *pCQSExpediente)
{
	append(pCQSExpediente);
	return *this;
}
CQSisOpExpediente::CQSisOpExpediente(SiscomDatCom *pSisDatCom):
			SiscomOperaciones(pSisDatCom)
{

}
void CQSisOpExpediente::Elimina(CQSisLstExpediente *pCQSLExpediente)
{
pCQSLExpediente->setAutoDelete(true);
pCQSLExpediente->clear();
pCQSLExpediente->setAutoDelete(false);
}
void CQSisOpExpediente::RegistraConsulta(
			CQSisExpediente *pCQSExpediente,
			SiscomRegistrosPro2 **pSRegistrosPro2)
{
CQSisLstExpediente lCQSLExpediente;

lCQSLExpediente << pCQSExpediente;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLExpediente);
SiscomActualiza2SubRegistros("RegistraExpediente",pSRegistrosPro2);
Elimina(&lCQSLExpediente);
}

void CQSisOpExpediente::ActualizaObservaciones(
			CQSisExpediente *pCQSExpediente,
			SiscomRegistrosPro2 **pSRegistrosPro2)
{
CQSisLstExpediente lCQSLExpediente;

lCQSLExpediente << pCQSExpediente;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLExpediente);
SiscomActualiza2SubRegistros("ActualizaObservaciones",pSRegistrosPro2);
Elimina(&lCQSLExpediente);
}
void CQSisOpExpediente::ObservacionesConsulta(
			const char *pchrPtrIdConsulta,
			CQSisLstExpediente *pCQSLExpediente)
{
SiscomRegistrosPro2 *lSRegistrosPro2;

SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s",
			 "ObservacionesConsulta",
			 pchrPtrIdConsulta);
Elimina(pCQSLExpediente);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultasClinicas3",&lSRegistrosPro2);
CQSisObjetos::Expedientes(lSRegistrosPro2,pCQSLExpediente);
}


void CQSisOpExpediente::Expediente(
			const char *pchrPtrIdPaciente,
			CQSisLstExpediente *pCQSLExpediente)
{
SiscomRegistrosPro2 *lSRegistrosPro2;

SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s",
			 "Expediente",
			 pchrPtrIdPaciente);
Elimina(pCQSLExpediente);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultasClinicas3",&lSRegistrosPro2);
CQSisObjetos::Expedientes2(lSRegistrosPro2,pCQSLExpediente);
}
