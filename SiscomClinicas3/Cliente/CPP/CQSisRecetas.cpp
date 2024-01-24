#include <CQSisRecetas.h>
#include <CQSisObjetos.h>
CQSisReceta::CQSisReceta(
			 const char *pchrPtrIdConsulta,
			 const char *pchrPtrFecha,
			 const char *pchrPtrFolio,
			 const char *pchrPtrFolioRegistrado,
			 const char *pchrPtrReceta)
{
SRegistroPro2			<<
"IdConsulta"			<<
"Fecha"				<<
"Folio"				<<
"FolioRegistrado"		<<
"Receta";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2 							<<
SiscomCampoPro2("IdConsulta",pchrPtrIdConsulta)			<<
SiscomCampoPro2("Fecha",pchrPtrFecha)				<<
SiscomCampoPro2("Folio",pchrPtrFolio)				<<
SiscomCampoPro2("FolioRegistrado",pchrPtrFolioRegistrado)	<<
SiscomCampoPro2("Receta",pchrPtrReceta);
SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisLstReceta::CQSisLstReceta()
{

}
CQSisLstReceta &CQSisLstReceta::operator<<(CQSisReceta *pCQSReceta)
{
	append(pCQSReceta);
	return *this;

}
CQSisOpReceta::CQSisOpReceta(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{

}
void CQSisOpReceta::Registra(CQSisReceta *pCQSReceta)
{
CQSisLstReceta lCQSLReceta;
SiscomRegistrosPro2 *lSRegistrosPro2;
	lCQSLReceta << pCQSReceta;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLReceta);
SiscomActualiza2SubRegistros("RegistraReceta",&lSRegistrosPro2);
Elimina(&lCQSLReceta);
}
void CQSisOpReceta::Actualiza(CQSisReceta *pCQSReceta)
{
CQSisLstReceta lCQSLReceta;
SiscomRegistrosPro2 *lSRegistrosPro2;
	lCQSLReceta << pCQSReceta;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLReceta);
SiscomActualiza2SubRegistros("ActualizaReceta",&lSRegistrosPro2);
Elimina(&lCQSLReceta);
}
void CQSisOpReceta::Receta(const char *pchrPtrIdConsulta,
			   CQSisLstReceta *pCQSLReceta)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s",
			 "RecetaConsulta",
			 pchrPtrIdConsulta);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultasClinicas3",&lSRegistrosPro2);
CQSisObjetos::Recetas(lSRegistrosPro2,pCQSLReceta);
}

void CQSisOpReceta::Recetas(const char *pchrPtrIdPaciente,
			   CQSisLstReceta *pCQSLReceta)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s",
			 "RecetasPaciente",
			 pchrPtrIdPaciente);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultasClinicas3",&lSRegistrosPro2);
CQSisObjetos::Recetas(lSRegistrosPro2,pCQSLReceta);
}
void CQSisOpReceta::Elimina(CQSisLstReceta *pCQSLReceta)
{
 pCQSLReceta->setAutoDelete(true);
 pCQSLReceta->clear();
 pCQSLReceta->setAutoDelete(false);
}


