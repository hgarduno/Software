#include <CQSisClase.h>
CQSisClase::CQSisClase(const char *pchrPtrIdClase,
			const char *pchrPtrIdTipoCompetencia,
				   const char *pchrPtrClase):
				chrPtrIdClase(pchrPtrIdClase),
				chrPtrIdTipoCompetencia(pchrPtrIdTipoCompetencia),
				chrPtrClase(pchrPtrClase)
{
	SiscomFormaRegistro();
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SiscomAnexaRegistro();
	SRegistrosPro2.SiscomAnexaRegistro();
	
}
void CQSisClase::SiscomFormaRegistro()
{
	SRegistroPro2 			<<
	"IdClase"			<<
	"IdTipoCompetencia"		<<
	"Clase";
}
void CQSisClase::SiscomAnexaRegistro()
{
	SRegistrosPro2							<<
	SiscomCampoPro2("IdClase",chrPtrIdClase)			<<
	SiscomCampoPro2("IdTipoCompetencia",chrPtrIdTipoCompetencia)	<<
	SiscomCampoPro2("Clase",chrPtrClase);
}
int CQSisClase::operator==(CQSisClase *pCQSClase)
{
return !strcmp((*this)["Clase"],(*pCQSClase)["Clase"]);
}
CQSisLstClase::CQSisLstClase()
{

}
CQSisLstClase &CQSisLstClase::operator<<(CQSisClase *pCQSCompetencia)
{
	append(pCQSCompetencia);
	return *this;
}
int CQSisLstClase::operator[](CQSisClase *pCQSClase)
{
 CQSisClase *lCQSClase;
  for(lCQSClase=first();
      lCQSClase;
      lCQSClase=next())
  if(!strcmp((*lCQSClase)["Clase"],(*pCQSClase)["Clase"]))
   return 1;

   return 0;

}

CQSisOpClase::CQSisOpClase(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{

}

void CQSisOpClase::InsertaCompetencia(CQSisClase *pCQSCompetencia,
					  SiscomRegistrosPro2 **pSRegistrosPro2)
{
/*
	CQSLClase << pCQSCompetencia;
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&CQSLCompetencia);
	SiscomActualiza2SubRegistros("RegistraCompetencia",pSRegistrosPro2);
*/
}
