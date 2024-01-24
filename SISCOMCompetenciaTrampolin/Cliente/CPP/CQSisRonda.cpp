#include <CQSisRonda.h>
#include <CQSisCompitiendo.h>
#include <CQSisAparatoCompetencia.h>
#include <CQSisCompetencias.h>
#include <CQSisEntrenadores.h>
#include <CQSisAparato.h>
#include <CQSisCompitiendo.h>
CQSisRonda::CQSisRonda(const char *pchrPtrIdRonda,
		       const char *pchrPtrRonda,
		       const char *pchrPtrIdCompetencia,
		       const char *pchrPtrIdGimnasta,
		       const char *pchrPtrIdAparato)
{

SRegistroPro2		<<
"IdRonda"		<<
"Ronda"			<<
"IdCompetencia"		<<
"IdGimnasta"		<<
"IdAparato";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2							<<
SiscomCampoPro2("IdRonda",pchrPtrIdRonda)			<<
SiscomCampoPro2("Ronda",pchrPtrRonda)				<<
SiscomCampoPro2("IdCompetencia",pchrPtrIdCompetencia)		<<
SiscomCampoPro2("IdGimnasta",pchrPtrIdGimnasta)		 	<<
SiscomCampoPro2("IdAparato",pchrPtrIdAparato);		
SRegistrosPro2.SiscomAnexaRegistro();

}
CQSisRonda::CQSisRonda(const char *pchrPtrIdRonda,
		       const char *pchrPtrRonda,
		       const char *pchrPtrIdCompetencia,
		       CQSisAparatoCompetencia *pCQSACompetencia,
		       CQSisLstCompitiendo *pCQSLCompitiendo):
		     CQSLCompitiendo(pCQSLCompitiendo),
		     CQSACompetencia(pCQSACompetencia)
{

	SRegistroPro2		<<
	"IdRonda"		<<
	"Ronda"			<<
	"IdCompetencia"		<<
	"IdGimnasta"		<<
	"IdAparato";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2			<<
	SiscomCampoPro2("IdRonda",pchrPtrIdRonda)	<<
	SiscomCampoPro2("Ronda",pchrPtrRonda)		<<
	SiscomCampoPro2("IdCompetencia",pchrPtrIdCompetencia)				<<
	SiscomCampoPro2("IdGimnasta","")			 <<
	SiscomCampoPro2("IdAparato",pCQSACompetencia->ObtenAparato()->SRegistrosPro2["IdAparato"]);		
	SRegistrosPro2.SiscomAnexaRegistro();
	AnexaGimnastas(pchrPtrIdRonda,pchrPtrRonda);
}
void CQSisRonda::AnexaGimnastas(const char *pchrPtrIdRonda,
				const char *pchrPtrRonda)
{
CQSisCompitiendo *lCQSCompitiendo;
for(lCQSCompitiendo=CQSLCompitiendo->first();
    lCQSCompitiendo;
    lCQSCompitiendo=CQSLCompitiendo->next())
{
SRegistrosPro2.SiscomAnexaRegistro(
 CQSisRonda(
	pchrPtrIdRonda,
        pchrPtrRonda,
	lCQSCompitiendo->ObtenCompetencia()->SRegistrosPro2["IdCompetencia"],
	lCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["IdPersona"],
	SRegistrosPro2["IdAparato"]).SRegistrosPro2);
	}
}
CQSisLstCompitiendo *CQSisRonda::Compitiendo()
{
 return CQSLCompitiendo;
}
CQSisAparatoCompetencia *CQSisRonda::Aparato()
{
return CQSACompetencia;
}
CQSisLstRonda::CQSisLstRonda()
{

}
int CQSisLstRonda::operator==(CQSisLstRonda *pCQSLRonda)
{
return !strcmp(pCQSLRonda->Nombre(),Nombre());
}
CQSisLstRonda &CQSisLstRonda::operator<<(CQSisRonda *pCQSRonda)
{
	chrPtrNombre=(*pCQSRonda)["Ronda"];
	chrPtrIdRonda=(*pCQSRonda)["IdRonda"];
	append(pCQSRonda);
	return *this;
}
const char *CQSisLstRonda::IdRonda()
{
return chrPtrIdRonda;
}
const char *CQSisLstRonda::Nombre()
{
return chrPtrNombre;
}
void CQSisLstRonda::AnexaAparato(CQSisAparatoCompetencia *pCQSACompetencia)
{
  CQSLACompetencia << pCQSACompetencia;
}
CQSisLstAparatoCompetencia &CQSisLstRonda::Aparatos()
{
	return CQSLACompetencia;
}
CQSisOpRonda::CQSisOpRonda(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{

}

void CQSisOpRonda::RegistraRondas(CQSisLstRonda *pCQSLRonda)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomPonParametrosConsulta((SiscomInformacionLst *)pCQSLRonda);
SiscomActualiza2SubRegistros("RegistraRondas",&lSRegistrosPro2);
}


CQSisLstLstRonda::CQSisLstLstRonda()
{

}
CQSisAparatoCompetencia *CQSisLstLstRonda::AparatoGimnasta(CQSisCompitiendo *pCQSCompitiendo)
{
CQSisLstRonda *lCQSLRonda;
CQSisRonda *lCQSRonda;
CQSisCompitiendo *lCQSCompitiendo;
for(lCQSLRonda=first();
    lCQSLRonda;
    lCQSLRonda=next())
{
 for(lCQSRonda=lCQSLRonda->first();
     lCQSRonda;
     lCQSRonda=lCQSLRonda->next())
 {
   for(lCQSCompitiendo=lCQSRonda->Compitiendo()->first();
       lCQSCompitiendo;
       lCQSCompitiendo=lCQSRonda->Compitiendo()->next())
   {
	if(*lCQSCompitiendo==pCQSCompitiendo)
	  return lCQSRonda->Aparato();
   }
 }

}
return 0;
}
CQSisLstLstRonda &CQSisLstLstRonda::operator<<(CQSisLstRonda *pCQSLRonda)
{
	append(pCQSLRonda);
	return *this;
}
