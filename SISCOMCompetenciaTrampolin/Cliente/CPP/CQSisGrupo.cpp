#include <CQSisGrupo.h>
CQSisGrupo::CQSisGrupo(const char *pchrPtrIdGrupo,
		       const char *pchrPtrIdTipoCompetencia,
				   const char *pchrPtrEdadIni,
				   const char *pchrPtrEdadFin,
				   const char *pchrPtrGrupo,
				   const char *pchrPtrRangoEdad):
				chrPtrIdGrupo(pchrPtrIdGrupo),
				chrPtrIdTipoCompetencia(pchrPtrIdTipoCompetencia),
				chrPtrEdadIni(pchrPtrEdadIni),
				chrPtrEdadFin(pchrPtrEdadFin),
				chrPtrGrupo(pchrPtrGrupo),
				chrPtrRangoEdad(pchrPtrRangoEdad)
{
	SiscomFormaRegistro();
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SiscomAnexaRegistro();
	SRegistrosPro2.SiscomAnexaRegistro();
	
}
void CQSisGrupo::SiscomFormaRegistro()
{
	SRegistroPro2 			<<
	"IdGrupo"			<<
	"IdTipoCompetencia"		<<
	"EdadIni"			<<
	"EdadFin"			<<
	"Grupo"				<<
	"RangoEdad";
}
void CQSisGrupo::SiscomAnexaRegistro()
{
	SRegistrosPro2							<<
	SiscomCampoPro2("IdGrupo",chrPtrIdGrupo)			<<
	SiscomCampoPro2("IdTipoCompetencia",chrPtrIdTipoCompetencia)	<<
	SiscomCampoPro2("EdadIni",chrPtrEdadIni)			<<
	SiscomCampoPro2("EdadFin",chrPtrEdadFin)			<<
	SiscomCampoPro2("Grupo",chrPtrGrupo)				<<
	SiscomCampoPro2("RangoEdad",chrPtrRangoEdad);
}
int CQSisGrupo::operator==(CQSisGrupo *pCQSGrupo)
{
return !strcmp((*this)["Grupo"],(*pCQSGrupo)["Grupo"]) 		&&
       !strcmp((*this)["EdadIni"],(*pCQSGrupo)["EdadIni"]) 	&&
       !strcmp((*this)["EdadFin"],(*pCQSGrupo)["EdadFin"]);
}
CQSisLstGrupo::CQSisLstGrupo()
{

}
CQSisLstGrupo &CQSisLstGrupo::operator<<(CQSisGrupo *pCQSCompetencia)
{
	append(pCQSCompetencia);
	return *this;
}
int CQSisLstGrupo::operator[](CQSisGrupo *pCQSGrupo)
{
CQSisGrupo *lCQSGrupo;
for(lCQSGrupo=first();
    lCQSGrupo;
    lCQSGrupo=next())
if((*lCQSGrupo)==pCQSGrupo)
return 1;

return 0;
}
CQSisOpGrupo::CQSisOpGrupo(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{

}

void CQSisOpGrupo::InsertaCompetencia(CQSisGrupo *pCQSCompetencia,
					  SiscomRegistrosPro2 **pSRegistrosPro2)
{
/*
	CQSLClase << pCQSCompetencia;
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&CQSLCompetencia);
	SiscomActualiza2SubRegistros("RegistraCompetencia",pSRegistrosPro2);
*/
}
