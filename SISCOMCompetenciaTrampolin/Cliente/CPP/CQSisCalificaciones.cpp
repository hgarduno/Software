#include <CQSisCalificaciones.h>

#include <CQSisEntrenadores.h>
#include <CQSisCompetencias.h>
#include <CQSisJueces.h>
#include <CQSisCompitiendo.h>
#include <CQSisAparato.h>
CQSisCalificacion::CQSisCalificacion(CQSisAparato *pCQSAparato,
				     CQSisCompetencia *pCQSCompetencia,
				     CQSisEntrenador *pCQSGimnasta,
				     CQSisJuez *pCQSJuezEjecucion,
				     CQSisJuez *pCQSJuezDificultad):
		CQSAparato(pCQSAparato),
		CQSCompetencia(pCQSCompetencia),
		CQSEGimnasta(pCQSGimnasta),
		CQSJuezEjecucion(pCQSJuezEjecucion),
		CQSJuezDificultad(pCQSJuezDificultad),
		chrPtrDificultad("0.0"),
		chrPtrEjecucion("0.0"),
		chrPtrNotaFinal("0.0")
{
	SiscomAsignaInformacion();

}
CQSisCalificacion::CQSisCalificacion(CQSisAparato *pCQSAparato,
				     const char *pchrPtrDificultad,
				     const char *pchrPtrEjecucion,
				     const char *pchrPtrNotaFinal):
				 CQSAparato(pCQSAparato),
				 CQSCompetencia(0),
				 CQSEGimnasta(0),
				 CQSJuezEjecucion(0),
				 CQSJuezDificultad(0),
				 chrPtrDificultad(pchrPtrDificultad),
				 chrPtrEjecucion(pchrPtrEjecucion),
				 chrPtrNotaFinal(pchrPtrNotaFinal)
{
	SiscomAsignaInformacion();
}
void CQSisCalificacion::SiscomAsignaInformacion()
{

	SiscomFormaRegistro();
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SiscomAnexaRegistro();  
	SRegistrosPro2.SiscomAnexaRegistro();
}
void CQSisCalificacion::SiscomFormaRegistro()
{
	SRegistroPro2		<<
	"IdCompetencia"		<<
	"IdGimnasta"		<<
	"IdJuezEjecucion"	<<
	"IdJuezDificultad"	<<
	"Dificultad"		<<
	"Ejecucion"		<<
	"NotaFinal"		<<
	"IdAparato";


}
void CQSisCalificacion::SiscomAnexaRegistro()
{
if(CQSCompetencia &&
   CQSEGimnasta   &&
   CQSJuezEjecucion &&
   CQSJuezDificultad)
SRegistrosPro2		<<
SiscomCampoPro2("IdCompetencia",CQSCompetencia->SRegistrosPro2["IdCompetencia"]) <<
SiscomCampoPro2("IdGimnasta",CQSEGimnasta->SRegistrosPro2["IdPersona"])	 <<
SiscomCampoPro2("IdJuezEjecucion",CQSJuezEjecucion->SRegistrosPro2["IdPersona"])		 <<
SiscomCampoPro2("IdJuezDificultad",CQSJuezDificultad->SRegistrosPro2["IdPersona"])		 <<
SiscomCampoPro2("Dificultad",chrPtrDificultad)				 <<
SiscomCampoPro2("Ejecucion",chrPtrEjecucion)				 <<
SiscomCampoPro2("NotaFinal",chrPtrNotaFinal)				 <<
SiscomCampoPro2("IdAparato",CQSAparato->SRegistrosPro2["IdAparato"]);
else
SRegistrosPro2					<<
SiscomCampoPro2("IdCompetencia","")		<<
SiscomCampoPro2("IdGimnasta","")		<<
SiscomCampoPro2("IdJuezEjecucion","")		<<
SiscomCampoPro2("IdJuezDificultad","")		<<
SiscomCampoPro2("Dificultad",chrPtrDificultad)	<<
SiscomCampoPro2("Ejecucion",chrPtrEjecucion)	<<
SiscomCampoPro2("NotaFinal",chrPtrNotaFinal)	<<
SiscomCampoPro2("IdAparato",CQSAparato->SRegistrosPro2["IdAparato"]);


}
int CQSisCalificacion::operator==(CQSisAparato *pCQSAparato)
{
return *CQSAparato==pCQSAparato; 
}
void CQSisCalificacion::PonEjecucion(const char *pchrPtrEjecucion)
{
	SRegistrosPro2.SiscomActualizaCampo("Ejecucion",pchrPtrEjecucion);
}
void CQSisCalificacion::PonDificultad(const char *pchrPtrDificultad)
{
	SRegistrosPro2.SiscomActualizaCampo("Dificultad",pchrPtrDificultad);
}
CQSisCompetencia *CQSisCalificacion::ObtenCompetencia()
{
	return CQSCompetencia;
}
CQSisEntrenador *CQSisCalificacion::ObtenGimnasta()
{
	return CQSEGimnasta;
}
CQSisAparato *CQSisCalificacion::ObtenAparato()
{
	return CQSAparato;
}
CQSisLstCalificacion::CQSisLstCalificacion()

{

}
CQSisLstCalificacion &CQSisLstCalificacion::operator<<(CQSisCalificacion *pCQSCalificacion)
{
	append(pCQSCalificacion);
	return *this;
}
CQSisOpCalificacion::CQSisOpCalificacion(SiscomDatCom *pSisDatCom):
			SiscomOperaciones(pSisDatCom)
{


}

void CQSisOpCalificacion::IniciaCalificacion(CQSisCalificacion *pCQSCalificacion,
					     SiscomRegistrosPro2 **pSRegistrosPro2)
{

	CQSLCalificacion << pCQSCalificacion;
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&CQSLCalificacion);
	SiscomActualiza2SubRegistros("IniciaCalificacion",
			 pSRegistrosPro2);
}
void CQSisOpCalificacion::ActualizaEjecucion(CQSisCalificacion *pCQSCalificacion,
					     SiscomRegistrosPro2 **pSRegistrosPro2)
{
	CQSLCalificacion << pCQSCalificacion;
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&CQSLCalificacion);
	SiscomActualiza2SubRegistros("ActualizaEjecucion",
			 pSRegistrosPro2);

}
void CQSisOpCalificacion::ActualizaDificultad(CQSisCalificacion *pCQSCalificacion,
					     SiscomRegistrosPro2 **pSRegistrosPro2)
{
CQSLCalificacion << pCQSCalificacion;
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&CQSLCalificacion);
	SiscomActualiza2SubRegistros("ActualizaDificultad",
			 pSRegistrosPro2);

}

void CQSisOpCalificacion::ObtenCalificaciones(
			CQSisCompitiendo *pCQSCompitiendo,
			CQSisCalificacion **pCQSCalificacion)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
const char *lchrPtrIdPersona;
const char *lchrPtrIdCompetencia;

lchrPtrIdPersona=pCQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["IdPersona"];
lchrPtrIdCompetencia=pCQSCompitiendo->ObtenCompetencia()->SRegistrosPro2["IdCompetencia"];
SPConsulta						<<
new SiscomParametroConsulta("CalificacionGimnasta")	<< 
new SiscomParametroConsulta(lchrPtrIdPersona)		<<
new SiscomParametroConsulta(lchrPtrIdCompetencia);

	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaGimnasio",&lSRegistrosPro2);
	FormaCalificacion(lSRegistrosPro2,pCQSCalificacion);

}
void CQSisOpCalificacion::FormaCalificacion(SiscomRegistrosPro2 *pSRegistrosPro2,
					    CQSisCalificacion **pCQSCalificacion)
{
	if(!pSRegistrosPro2->SiscomEsElUltimoRegistro())
	*pCQSCalificacion=new CQSisCalificacion(
				new CQSisAparato(
				   (*pSRegistrosPro2)["idaparato"],
				   (*pSRegistrosPro2)["aparato"],
				   ""),
				(*pSRegistrosPro2)["dificultad"],
				(*pSRegistrosPro2)["ejecucion"],
				(*pSRegistrosPro2)["notafinal"]
				
				);
}
