#include <CQSisCompetencias.h>
CQSisCompetencia::CQSisCompetencia():
		chrPtrNombre(""),
		chrPtrFecha(""),
		chrPtrIdCompetencia(""),
		chrPtrIdTipoCompetencia("")
{
	SiscomFormaRegistro();
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SiscomAnexaRegistro();
	SRegistrosPro2.SiscomAnexaRegistro();

}
CQSisCompetencia::CQSisCompetencia(const char *pchrPtrNombre,
				   const char *pchrPtrFecha,
				   const char *pchrPtrIdCompetencia,
				   const char *pchrPtrIdTipoCompetencia):
				chrPtrNombre(pchrPtrNombre),
				chrPtrFecha(pchrPtrFecha),
				chrPtrIdCompetencia(pchrPtrIdCompetencia),
				chrPtrIdTipoCompetencia(pchrPtrIdTipoCompetencia)
{
/*
	SiscomAsignaInformacion();
*/
	SiscomFormaRegistro();
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SiscomAnexaRegistro();
	SRegistrosPro2.SiscomAnexaRegistro();
	
}
void CQSisCompetencia::SiscomFormaRegistro()
{
	SRegistroPro2 			<<
	"Competencia"			<<
	"Fecha"				<<
	"IdCompetencia"			<<
	"IdTipoCompetencia"		<<
	"Descripcion"			<<
	"Bases"				<<
	"FecIniInsc"			<<
	"FecFinInsc";
}
void CQSisCompetencia::SiscomAnexaRegistro()
{

	SRegistrosPro2							<<
	SiscomCampoPro2("Competencia",chrPtrNombre)			<<
	SiscomCampoPro2("Fecha",chrPtrFecha)				<<
	SiscomCampoPro2("IdCompetencia",chrPtrIdCompetencia)		<<
	SiscomCampoPro2("IdTipoCompetencia",chrPtrIdTipoCompetencia)	<<
	SiscomCampoPro2("Descripcion","")				<<
	SiscomCampoPro2("Bases","")					<<
	SiscomCampoPro2("FecIniInsc","")				<<
	SiscomCampoPro2("FecFinInsc","");
}
void CQSisCompetencia::PonFechaIniInscripcion(const char *pchrPtrFecha)
{
	SRegistrosPro2.SiscomActualizaCampo("FecIniInsc",pchrPtrFecha);
}
void CQSisCompetencia::PonFechaFinInscripcion(const char *pchrPtrFecha)
{
	SRegistrosPro2.SiscomActualizaCampo("FecFinInsc",pchrPtrFecha);
}
void CQSisCompetencia::PonDescripcion(const char *pchrPtrDescripcion)
{
	SRegistrosPro2.SiscomActualizaCampo("Descripcion",pchrPtrDescripcion);
}
void CQSisCompetencia::PonBases(const char *pchrPtrBases)
{
	SRegistrosPro2.SiscomActualizaCampo("Bases",pchrPtrBases);
}

CQSisLstCompetencia::CQSisLstCompetencia()
{

}
CQSisLstCompetencia &CQSisLstCompetencia::operator<<(CQSisCompetencia *pCQSCompetencia)
{
	append(pCQSCompetencia);
	return *this;
}

CQSisOpCompetencia::CQSisOpCompetencia(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{

}

void CQSisOpCompetencia::InsertaCompetencia(CQSisCompetencia *pCQSCompetencia,
					  SiscomRegistrosPro2 **pSRegistrosPro2)
{

	CQSLCompetencia << pCQSCompetencia;
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&CQSLCompetencia);
	SiscomActualiza2SubRegistros("RegistraCompetencia",pSRegistrosPro2);

}
