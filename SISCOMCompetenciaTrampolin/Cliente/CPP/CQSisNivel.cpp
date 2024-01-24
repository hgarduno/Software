#include <CQSisNivel.h>
CQSisNivel::CQSisNivel(const char *pchrPtrIdNivel,
				   const char *pchrPtrNivel,
				   const char *pchrPtrDescripcion):
				chrPtrIdNivel(pchrPtrIdNivel),
				chrPtrNivel(pchrPtrNivel),
				chrPtrDescripcion(pchrPtrDescripcion)
{
	SiscomFormaRegistro();
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SiscomAnexaRegistro();
	SRegistrosPro2.SiscomAnexaRegistro();
	
}
void CQSisNivel::SiscomFormaRegistro()
{
	SRegistroPro2 			<<
	"IdNivel"			<<
	"Nivel"				<<
	"Descripcion";
}
void CQSisNivel::SiscomAnexaRegistro()
{

	SRegistrosPro2						<<
	SiscomCampoPro2("IdNivel",chrPtrIdNivel)			<<
	SiscomCampoPro2("Nivel",chrPtrNivel)			<<
	SiscomCampoPro2("Descripcion",chrPtrDescripcion);
}
int CQSisNivel::operator==(CQSisNivel *pCQSNivel)
{
return !strcmp((*this)["Nivel"],
       (*pCQSNivel)["Nivel"]);
}
CQSisLstNivel::CQSisLstNivel()
{

}
CQSisLstNivel &CQSisLstNivel::operator<<(CQSisNivel *pCQSCompetencia)
{
	append(pCQSCompetencia);
	return *this;
}

CQSisOpNivel::CQSisOpNivel(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{

}

void CQSisOpNivel::InsertaCompetencia(CQSisNivel *pCQSCompetencia,
					  SiscomRegistrosPro2 **pSRegistrosPro2)
{
/*
	CQSLClase << pCQSCompetencia;
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&CQSLCompetencia);
	SiscomActualiza2SubRegistros("RegistraCompetencia",pSRegistrosPro2);
*/
}
