#include <CQSisTipoCompetencia.h>

CQSisTipoCompetencia::CQSisTipoCompetencia(const char *pchrPtrIdCompetencia,
					   const char *pchrPtrCompetencia)
{
	SRegistroPro2								<<
	"IdTipoCompetencia"							<<
	"Competencia";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2								<<
	SiscomCampoPro2("IdTipoCompetencia",pchrPtrIdCompetencia)		<<
	SiscomCampoPro2("Competencia",pchrPtrCompetencia);
	SRegistrosPro2.SiscomAnexaRegistro();
}

CQSisLstTipoCompetencia::CQSisLstTipoCompetencia()
{

}
CQSisLstTipoCompetencia &CQSisLstTipoCompetencia::operator<<(CQSisTipoCompetencia *pCQSTCompetencia)
{
	append(pCQSTCompetencia);
	return *this;
}
