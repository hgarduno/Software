#include <CQSisConsultas.h>
#include <CQSisNivel.h>
#include <CQSisGrupo.h>
#include <CQSisClase.h>
#include <CQSisCompetencias.h>
#include <CQSisEntrenadores.h>
#include <CQSisCompitiendo.h>
#include <CQSisGimnasios.h>
#include <CQSisCalificaciones.h>
#include <CQSisTipoCompetencia.h>
#include <CQSisAparatoCompetencia.h>
#include <CQSisAparato.h>
#include <SisPersonas.h>
#include <SisDirecciones.h>

CQSisLstLstGrupo::CQSisLstLstGrupo()
{

}
CQSisLstLstGrupo &CQSisLstLstGrupo::operator<<(CQSisLstGrupo *pCQSLGrupo)
{
	append(pCQSLGrupo);
	return *this;
}

CQSisOpConsultas::CQSisOpConsultas(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{


}

void CQSisOpConsultas::ObtenClases(const char *pchrPtrIdTipoCompetencia,
				   CQSisLstClase *pCQSLClase)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
	pCQSLClase->clear();
	SPConsulta.clear();
	SPConsulta							<<
	new SiscomParametroConsulta("ClasesRegistradas")		<<
	new SiscomParametroConsulta(pchrPtrIdTipoCompetencia);
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaGimnasio",&lSRegistrosPro2);
	FormaClases(lSRegistrosPro2,pCQSLClase);
}
void CQSisOpConsultas::ObtenNiveles(CQSisClase *pCQSClase,
				    CQSisLstNivel *pCQSLNivel)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
		pCQSLNivel->clear();
		SPConsulta.clear();
		SPConsulta						<<
		new SiscomParametroConsulta("NivelesRegistrados")	<<
		new SiscomParametroConsulta(pCQSClase->SRegistrosPro2["IdClase"]); 
		SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
		SiscomConsulta("ConsultaGimnasio",&lSRegistrosPro2);
		FormaNiveles(lSRegistrosPro2,pCQSLNivel);
		delete lSRegistrosPro2;

}
void CQSisOpConsultas::ObtenGrupos(CQSisLstGrupo *pCQSLGrupo)
{


}
void CQSisOpConsultas::ObtenGrupos(const char *pchrPtrIdTipoCompetencia,
				   CQSisLstLstGrupo *pCQSLstLstGrupo)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
	pCQSLstLstGrupo->clear();
	SPConsulta.clear();
	SPConsulta			<<
	new SiscomParametroConsulta("GruposRegistrados") <<
	new SiscomParametroConsulta(pchrPtrIdTipoCompetencia);
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaGimnasio",&lSRegistrosPro2);
	FormaGrupos(lSRegistrosPro2,pCQSLstLstGrupo);
}
void CQSisOpConsultas::ObtenCompetencias(CQSisLstCompetencia *pCQSLCompetencias)
{

SiscomRegistrosPro2 *lSRegistrosPro2;
/*
 *
 * Se debe de anexar a la clase QCtrlCompetencias el rango de fechas
 * en las que se debera realizar la busqueda
 *
 */
	pCQSLCompetencias->clear();
	SPConsulta.clear();
	SPConsulta			<<
	new SiscomParametroConsulta("CompetenciasRegistradas");
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaGimnasio",&lSRegistrosPro2);
	FormaCompetencias(lSRegistrosPro2,pCQSLCompetencias);
		

}


void CQSisOpConsultas::ConsultaPersonasNombre(
					const char *pchrPtrPersona,
					const char *pchrPtrNombre,
					const char *pchrPtrAPaterno,
					const char *pchrPtrAMaterno,
					SisLstPersona *pSLstPersona)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
	pSLstPersona->clear();
		SPConsulta.clear();
	FormaConsultaPorNombre(pchrPtrPersona,
				pchrPtrNombre,
				pchrPtrAPaterno,
				pchrPtrAMaterno);
	SiscomConsulta("ConsultaGimnasio",&lSRegistrosPro2);
	FormaPersonas(lSRegistrosPro2,pSLstPersona);
}
void CQSisOpConsultas::ConsultaPersonasNombre(
					const char *pchrPtrPersona,
					const char *pchrPtrNombre,
					const char *pchrPtrAPaterno,
					const char *pchrPtrAMaterno,
					CQSisLstEntrenador *pCQSLEntrenador)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
	pCQSLEntrenador->clear();
		SPConsulta.clear();
	FormaConsultaPorNombre(pchrPtrPersona,
				pchrPtrNombre,
				pchrPtrAPaterno,
				pchrPtrAMaterno);
	SiscomConsulta("ConsultaGimnasio",&lSRegistrosPro2);
	FormaEntrenadores(lSRegistrosPro2,pCQSLEntrenador);
}
void CQSisOpConsultas::ConsultaTipoCompetencia(
			CQSisLstTipoCompetencia *pCQSLTipoCompetencia)
{
SiscomRegistrosPro2 *lSRegistrosPro2;

	pCQSLTipoCompetencia->clear();
		SPConsulta.clear();
	SPConsulta					<<
	new SiscomParametroConsulta("TiposCompetencia");	
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaGimnasio",&lSRegistrosPro2);
	FormaTipoCompetencia(lSRegistrosPro2,pCQSLTipoCompetencia);
	
}
void CQSisOpConsultas::GimnastasCompetencia(CQSisCompetencia *pCQSCompetencia,
					    CQSisAparato *pCQSAparato,
					    CQSisLstCompitiendo *pCQSLCompitiendo)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
pCQSLCompitiendo->clear();
		SPConsulta.clear();
SPConsulta						<<
new SiscomParametroConsulta("GimnastasCompetencia")	<<
new SiscomParametroConsulta(pCQSCompetencia->SRegistrosPro2["IdCompetencia"])	<<
new SiscomParametroConsulta(pCQSAparato->SRegistrosPro2["IdAparato"]);
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaGimnasio",&lSRegistrosPro2);
	FormaGimnastasCompetencia(lSRegistrosPro2,pCQSLCompitiendo);
}
void CQSisOpConsultas::GimnastasCompetencia(CQSisCompetencia *pCQSCompetencia,
					    CQSisLstCompitiendo *pCQSLCompitiendo)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
pCQSLCompitiendo->clear();
		SPConsulta.clear();
SPConsulta						<<
new SiscomParametroConsulta("GimnastasCompetencia01")	<<
new SiscomParametroConsulta(pCQSCompetencia->SRegistrosPro2["IdCompetencia"]);
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaGimnasio",&lSRegistrosPro2);
	FormaGimnastasCompetencia(lSRegistrosPro2,pCQSLCompitiendo);
}
void CQSisOpConsultas::ConsultaAparatosCompetencia(
				CQSisCompetencia *pCQSCompetencia,
				CQSisLstAparatoCompetencia *pCQSLACompetencia)
{
SiscomRegistrosPro2 *lSRegistrosPro2;

	pCQSLACompetencia->clear();
		SPConsulta.clear();

	SPConsulta						<<
	new SiscomParametroConsulta("AparatosCompetencia")	<<
	new SiscomParametroConsulta(pCQSCompetencia->SRegistrosPro2["IdCompetencia"]);

	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaGimnasio",&lSRegistrosPro2);
	FormaAparatoCompetencia(lSRegistrosPro2,pCQSLACompetencia);

	
}
void CQSisOpConsultas::ConsultaMediosPersona(
			CQSisEntrenador *pCQSEPersona,
			SisLstMedCom *pSLMedCom)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
		SPConsulta.clear();
	SPConsulta					<<
	new SiscomParametroConsulta("MediosPersona")	<<
	new SiscomParametroConsulta(pCQSEPersona->SRegistrosPro2["IdPersona"]);
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaGimnasio",&lSRegistrosPro2);
	FormaMedioComunicacion(lSRegistrosPro2,
			       pSLMedCom);

}
void CQSisOpConsultas::DireccionesPersona(
			CQSisEntrenador *pCQSEPersona,
			SisLstDireccion *pSLDireccion)
{
SiscomRegistrosPro2 *lSRegistrosPro2;

		SPConsulta.clear();
	SPConsulta						<<
	new SiscomParametroConsulta("DireccionesPersona")	<<
	new SiscomParametroConsulta(pCQSEPersona->SRegistrosPro2["IdPersona"]);
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaGimnasio",&lSRegistrosPro2);
	FormaDireccionesPersona(lSRegistrosPro2,pSLDireccion);

}
void CQSisOpConsultas::FormaDireccionesPersona(
			SiscomRegistrosPro2 *pSRegistrosPro2,
			SisLstDireccion *pSLDireccion)
{

	for(;
	    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	    ++(*pSRegistrosPro2))
	{
	  
	  (*pSLDireccion)	<<
	  	new SisDireccion(
			(*pSRegistrosPro2)["calle"],
			(*pSRegistrosPro2)["numero"],
			"",
			(*pSRegistrosPro2)["idasentamiento"],
			(*pSRegistrosPro2)["asentamiento"],
			(*pSRegistrosPro2)["estado"],
			(*pSRegistrosPro2)["municipio"]);

	}


}
void CQSisOpConsultas::FormaAparatoCompetencia(
			SiscomRegistrosPro2 *pSRegistrosPro2,
			CQSisLstAparatoCompetencia *pCQSLACompetencia)
{
	for(;
	    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	    ++(*pSRegistrosPro2))
	   (*pCQSLACompetencia) <<  
	   	new CQSisAparatoCompetencia(
	   		new CQSisAparato(
				(*pSRegistrosPro2)["idaparato"],
				(*pSRegistrosPro2)["aparato"],
				""),
			new CQSisTipoCompetencia(
				(*pSRegistrosPro2)["idtipocompetencia"],
				""));
}
void CQSisOpConsultas::FormaTipoCompetencia(
			SiscomRegistrosPro2 *pSRegistrosPro2,
			CQSisLstTipoCompetencia *pCQSLTipoCompetencia)
{


	for(;
	     !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	     ++(*pSRegistrosPro2))
	 (*pCQSLTipoCompetencia) << new 
	 			CQSisTipoCompetencia(
	 			 (*pSRegistrosPro2)["idtipocompetencia"],
				 (*pSRegistrosPro2)["competencia"]);

}
void CQSisOpConsultas::FormaEntrenadores(SiscomRegistrosPro2 *pSRegistrosPro2,
					 CQSisLstEntrenador *pCQSLEntrenador)
{
CQSisEntrenador *lCQSEntrenador;
	for(;
		!pSRegistrosPro2->SiscomEsElUltimoRegistro();
	     ++(*pSRegistrosPro2))
	{
	    lCQSEntrenador=new CQSisEntrenador(
	    				(*pSRegistrosPro2)["nombre"],
					(*pSRegistrosPro2)["apaterno"],
					(*pSRegistrosPro2)["amaterno"],
					(*pSRegistrosPro2)["idpersona"]);
	    lCQSEntrenador->PonFechaNac((*pSRegistrosPro2)["fechanac"]);
	    lCQSEntrenador->PonEdad((*pSRegistrosPro2)["edad"]);
	    (*pCQSLEntrenador) << lCQSEntrenador;
	}

}
void CQSisOpConsultas::FormaPersonas(SiscomRegistrosPro2 *pSRegistrosPro2,
				     SisLstPersona *pSLstPersona)
{

	for(;
		!pSRegistrosPro2->SiscomEsElUltimoRegistro();
	     ++(*pSRegistrosPro2))
	  (*pSLstPersona) << new SisPersona((*pSRegistrosPro2)["nombre"],
	  				    (*pSRegistrosPro2)["apaterno"],
					    (*pSRegistrosPro2)["amaterno"],
					    (*pSRegistrosPro2)["idpersona"]);
}
void CQSisOpConsultas::FormaClases(SiscomRegistrosPro2 *pSRegistrosPro2,
				   CQSisLstClase *pCQSLClase)
{
	for(;
	     !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	     ++(*pSRegistrosPro2))
	 (*pCQSLClase)<< new CQSisClase((*pSRegistrosPro2)["idclase"],
	 				(*pSRegistrosPro2)["idtipocompetencia"],
	 				(*pSRegistrosPro2)["clase"]);

}
void CQSisOpConsultas::FormaNiveles(SiscomRegistrosPro2 *pSRegistrosPro2,
				    CQSisLstNivel *pCQSLNivel)
{

	for(;
	     !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	     ++(*pSRegistrosPro2))
	    (*pCQSLNivel) << new CQSisNivel((*pSRegistrosPro2)["idnivel"],
	    				    (*pSRegistrosPro2)["nivel"],
					    (*pSRegistrosPro2)["descripcion"]);
}
int CQSisOpConsultas::EsElUltimoGrupo(SiscomRegistrosPro2 *pSRegistrosPro2)
{

	return 	!(*pSRegistrosPro2)["idgrupo"][0];  
		
}
void CQSisOpConsultas::FormaGrupos(SiscomRegistrosPro2 *pSRegistrosPro2,
				   CQSisLstLstGrupo *pCQSLstLstGrupo)
{
QString lQSGrupo;
CQSisGrupo *lCQSGrupo;
CQSisLstGrupo *lCQSLGrupo;
	pCQSLstLstGrupo->clear();
	for(;
	     !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	     ++(*pSRegistrosPro2))
	{
	
	  lQSGrupo=(*pSRegistrosPro2)["grupo"];
	  lCQSLGrupo=new CQSisLstGrupo;
	  ++(*pSRegistrosPro2); 
	 for(;
	     !pSRegistrosPro2->SiscomEsElUltimoRegistro() &&
	     !EsElUltimoGrupo(pSRegistrosPro2);
	     ++(*pSRegistrosPro2))
	 {
	   lCQSGrupo=new CQSisGrupo((*pSRegistrosPro2)["idgrupo"],
	   			    (*pSRegistrosPro2)["idtipocompetencia"],
	   			    (*pSRegistrosPro2)["edadinf"],
				    (*pSRegistrosPro2)["edadsup"],
				    (*pSRegistrosPro2)["grupo"]);
	    (*lCQSLGrupo) << lCQSGrupo;

	 }
	  (*pCQSLstLstGrupo) << lCQSLGrupo;
	}

}

void CQSisOpConsultas::FormaCompetencias(SiscomRegistrosPro2 *pSRegistrosPro2,
					 CQSisLstCompetencia *pCQSLCompetencia)
{
	for(;
	    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	    ++(*pSRegistrosPro2))
	 (*pCQSLCompetencia) 	<< new 
	 	CQSisCompetencia((*pSRegistrosPro2)["nombre"],
	 			 (*pSRegistrosPro2)["fecha"],
				 (*pSRegistrosPro2)["idcompetencia"],
				 (*pSRegistrosPro2)["idtipocompetencia"]);


}

void CQSisOpConsultas::FormaConsultaPorNombre(
					const char *pchrPtrPersona,
					const char *pchrPtrNombre,
					const char *pchrPtrAPaterno,
					const char *pchrPtrAMaterno)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
	SPConsulta						<<
	new SiscomParametroConsulta("PersonasRegistradas")	<<
	new SiscomParametroConsulta(pchrPtrPersona)		<<
	new SiscomParametroConsulta(pchrPtrNombre)		<<
	new SiscomParametroConsulta(pchrPtrAPaterno)		<<
	new SiscomParametroConsulta(pchrPtrAMaterno);
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
}

void CQSisOpConsultas::FormaMedioComunicacion(
			SiscomRegistrosPro2 *pSRegistrosPro2,
			SisLstMedCom *pSLMCom)
{
SisMedCom *lSMCom;

	for(;
		!pSRegistrosPro2->SiscomEsElUltimoRegistro();
		++(*pSRegistrosPro2))
	  (*pSLMCom) << new SisMedCom(
	  			(*pSRegistrosPro2)["idmedio"],
	  			(*pSRegistrosPro2)["medio"],
	  			(*pSRegistrosPro2)["dato"],
	  			(*pSRegistrosPro2)["descripcion"]);
}
	
void CQSisOpConsultas::FormaGimnastasCompetencia(
			SiscomRegistrosPro2 *pSRegistrosPro2,
			CQSisLstCompitiendo *pCQSLCompitiendo)
{
CQSisCompitiendo *lCQSCompitiendo;
	for(;
	    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	    ++(*pSRegistrosPro2))
	 {
		lCQSCompitiendo=new CQSisCompitiendo(
		new CQSisCompetencia(
			"",
			"",
			(*pSRegistrosPro2)["idcompetencia"],
			(*pSRegistrosPro2)["idtipocompetencia"]),
		new CQSisEntrenador(
			(*pSRegistrosPro2)["nmbgimnasta"],
			(*pSRegistrosPro2)["apatgimnasta"],
			(*pSRegistrosPro2)["amatgimnasta"],
			(*pSRegistrosPro2)["idgimnasta"]),
		new CQSisGimnasio(
			(*pSRegistrosPro2)["idgimnasio"],
			(*pSRegistrosPro2)["gimnasio"]),
		new CQSisClase(
			(*pSRegistrosPro2)["idclase"],
			(*pSRegistrosPro2)["idtipocompetencia"],
			(*pSRegistrosPro2)["clase"]),
		new CQSisNivel(
			(*pSRegistrosPro2)["idnivel"],
			(*pSRegistrosPro2)["nivel"],
			""),
		new CQSisGrupo(
			(*pSRegistrosPro2)["idgrupo"],
			"",
			(*pSRegistrosPro2)["edadinf"],
			(*pSRegistrosPro2)["edadsup"],
			(*pSRegistrosPro2)["grupo"],
			(*pSRegistrosPro2)["rangoedad"]),
		new CQSisEntrenador(
			(*pSRegistrosPro2)["nmbentrenador"],
			(*pSRegistrosPro2)["apatentrenador"],
			(*pSRegistrosPro2)["amatentrenador"],
			(*pSRegistrosPro2)["identrenador"]),
		"");
	    lCQSCompitiendo->PonCalificacion(new CQSisCalificacion(
	    					  new CQSisAparato(
						     (*pSRegistrosPro2)["idaparato"],
						     (*pSRegistrosPro2)["aparato"],
						     ""),
	    					  (*pSRegistrosPro2)["dificultad"],
						  (*pSRegistrosPro2)["ejecucion"],
						  (*pSRegistrosPro2)["notafinal"]));
	    (*pCQSLCompitiendo) << lCQSCompitiendo; 
	}
}


