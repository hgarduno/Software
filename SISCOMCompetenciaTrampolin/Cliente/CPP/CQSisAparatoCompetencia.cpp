#include <CQSisAparatoCompetencia.h>
#include <CQSisAparato.h>
#include <CQSisTipoCompetencia.h>

CQSisAparatoCompetencia::CQSisAparatoCompetencia(
			 CQSisAparato *pCQSAparato,
			 CQSisTipoCompetencia *pCQSTCompetencia):
		CQSAparato(pCQSAparato),
		CQSTCompetencia(pCQSTCompetencia)
{


}

CQSisAparato *CQSisAparatoCompetencia::ObtenAparato()
{
	return CQSAparato;
}
CQSisTipoCompetencia *CQSisAparatoCompetencia::ObtenTipoCompetencia()
{
	return CQSTCompetencia;
}

CQSisLstAparatoCompetencia::CQSisLstAparatoCompetencia()
{

}

CQSisLstAparatoCompetencia &CQSisLstAparatoCompetencia::operator<<(
				CQSisAparatoCompetencia *pCQSACompetencia)
{

	append(pCQSACompetencia);

	return *this;
}
int CQSisLstAparatoCompetencia::operator==(CQSisAparatoCompetencia *pCQSACompetencia)
{
CQSisAparatoCompetencia *lCQSACompetencia;

	for(lCQSACompetencia=first();
	    lCQSACompetencia;
	    lCQSACompetencia=next())
	if(!strcmp(lCQSACompetencia->ObtenAparato()->SRegistrosPro2["Aparato"],
		   pCQSACompetencia->SRegistrosPro2["Aparato"]))
	  return 1;

return 0;


}
