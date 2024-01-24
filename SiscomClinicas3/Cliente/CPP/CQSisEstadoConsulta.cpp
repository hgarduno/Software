#include <CQSisEstadoConsulta.h>
#include <CQSisCotizando.h>
CQSisEstadoConsulta::CQSisEstadoConsulta(
			const char *pchrPtrIdConsulta,
			const char *pchrPtrIdEstado,
			const char *pchrPtrIdEmpleado,
			const char *pchrPtrFecha)
{
SRegistroPro2 			<<
"IdConsulta"			<<
"IdEdo"				<<
"IdEmpleado"			<<
"Fecha";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2					<<
SiscomCampoPro2("IdConsulta",pchrPtrIdConsulta)	<<
SiscomCampoPro2("IdEdo",pchrPtrIdEstado)	<<
SiscomCampoPro2("IdEmpleado",pchrPtrIdEmpleado)	<<
SiscomCampoPro2("Fecha",pchrPtrFecha);
SRegistrosPro2.SiscomAnexaRegistro();
}

CQSisLstEstadoConsulta::CQSisLstEstadoConsulta()
{

}
CQSisLstEstadoConsulta &CQSisLstEstadoConsulta::operator<<(
			CQSisEstadoConsulta  *pCQSEConsulta)
{
	append(pCQSEConsulta);
	return *this;
}

CQSisOpEstadoConsulta::CQSisOpEstadoConsulta(SiscomDatCom *pSisDatCom):
			SiscomOperaciones(pSisDatCom)
{

}
void CQSisOpEstadoConsulta::EstadoConsulta(
				CQSisEstadoConsulta *pCQSEConsulta,
				SiscomRegistrosPro2 **pSRegistrosPro2)
{
CQSisLstEstadoConsulta lCQSLEConsulta;
lCQSLEConsulta << pCQSEConsulta;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLEConsulta);
SiscomActualiza2SubRegistros("ActualizaEdoConsulta",pSRegistrosPro2);
EliminaLista(&lCQSLEConsulta);
}
void CQSisOpEstadoConsulta::EliminaLista(CQSisLstEstadoConsulta *pCQSLEConsulta)
{
	pCQSLEConsulta->setAutoDelete(true);
	pCQSLEConsulta->clear();
	pCQSLEConsulta->setAutoDelete(false);
}
void CQSisOpEstadoConsulta::TerminaConsulta(const char *pchrPtrIdConsulta,
					    CQSisLstCotizando *pCQSLCotizando)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
pCQSLCotizando->AsignaIdConsulta(pchrPtrIdConsulta);
SiscomPonParametrosConsulta((SiscomInformacionLst *)pCQSLCotizando);
SiscomActualiza2SubRegistros("TerminaConsulta",&lSRegistrosPro2);
}
    
void CQSisOpEstadoConsulta::MaterialServicioHospitalizacion(
				const char *pchrPtrIdConsulta,
				CQSisLstCotizando *pCQSLCotizando)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
pCQSLCotizando->AsignaIdConsulta(pchrPtrIdConsulta);
SiscomPonParametrosConsulta((SiscomInformacionLst *)pCQSLCotizando);
SiscomActualiza2SubRegistros("MaterialServicioHospitalizacion",&lSRegistrosPro2);
}
    
