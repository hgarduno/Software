#include <CQSisServicios.h>
#include <CQSisObjetos.h>
CQSisServicio::CQSisServicio(const char *pchrPtrIdServicio,
			     const char *pchrPtrClave,
			     const char *pchrPtrDescripcion,
			     const char *pchrPtrTipo,
			     const char *pchrPtrIdMedico)
{

SRegistroPro2	<<
"IdServicio"	<<
"Clave"		<<
"Descripcion"	<<
"Tipo"		<<
"IdMedico";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2						<<
SiscomCampoPro2("IdServicio",pchrPtrIdServicio)		<<
SiscomCampoPro2("Clave",pchrPtrClave)			<<
SiscomCampoPro2("Descripcion",pchrPtrDescripcion)	<<
SiscomCampoPro2("Tipo",pchrPtrTipo)			<<
SiscomCampoPro2("IdMedico",pchrPtrIdMedico);
SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisLstServicio::CQSisLstServicio()
{


}
CQSisLstServicio &CQSisLstServicio::operator<<(CQSisServicio *pCQSServicio)
{
	append(pCQSServicio);
	return *this;
}
CQSisOpServicio::CQSisOpServicio(SiscomDatCom *pSisDatCom):
			SiscomOperaciones(pSisDatCom)
{


}

void CQSisOpServicio::Servicio(CQSisServicio *pCQSServicio,
			       SiscomRegistrosPro2 **pSRegistrosPro2)
{
CQSisLstServicio lCQSLServicio;
lCQSLServicio << pCQSServicio;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLServicio);
SiscomActualiza2SubRegistros(pCQSServicio->SRegistrosPro2["Tipo"],
			     pSRegistrosPro2);
}

void CQSisOpServicio::Servicio(const char *pchrPtrTipo,
			       const char *pchrPtrIdMedico,
			       CQSisLstServicio *pCQSLServicio)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s",
			 pchrPtrTipo,
			 pchrPtrIdMedico);
EliminaServicios(pCQSLServicio);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultasClinicas3",&lSRegistrosPro2);
CQSisObjetos::Servicios(lSRegistrosPro2,pCQSLServicio);
}
void CQSisOpServicio::EliminaServicios(CQSisLstServicio *pCQSLServicio)
{
pCQSLServicio->setAutoDelete(true);
pCQSLServicio->clear();
pCQSLServicio->setAutoDelete(false);


}

void CQSisOpServicio::PerfilServicioMedico(
			CQSisLstServicio *pCQSLServicio,
			SiscomRegistrosPro2 **pSRegistrosPro2)
{
SiscomPonParametrosConsulta((SiscomInformacionLst *)pCQSLServicio);
SiscomActualiza2SubRegistros("RegistraPerfilMedico",pSRegistrosPro2);
}

/*
void CQSisOpServicio::PreciosServicios(CQSisLstServicio *pCQSLServicio)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(&SPConsulta,
			 "%s",
			 "PreciosServicioGeneral");
EliminaServicios(pCQSLServicio);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultasClinicas3",&lSRegistrosPro2);
}

void CQSisOpServicio::PreciosServicios(const char *pchrPtrIdMedico,
					CQSisLstServicio *pCQSLServicio)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s",
			 "PreciosServicioMedico",
			 pchrPtrIdMedico);
EliminaServicios(pCQSLServicio);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultasClinicas3",&lSRegistrosPro2);
}


*/
