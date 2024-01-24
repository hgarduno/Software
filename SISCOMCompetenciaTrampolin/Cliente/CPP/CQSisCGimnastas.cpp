#include <CQSisCGimnastas.h>
#include <CQSisCompetencias.h>
#include <CQSisEntrenadores.h>
#include <CQSisClase.h>
#include <CQSisGrupo.h>
#include <CQSisNivel.h>
#include <CQSisGimnasios.h>
#include <CQSisCalificaciones.h>
#include <CQSisAparatoCompetencia.h>
#include <CQSisAparato.h>
#include <CQSisRonda.h>
CQSisGmnCompitiendo::CQSisGmnCompitiendo(CQSisCompitiendo *pCQSCompitiendo):
			CQSCompitiendo(pCQSCompitiendo)
{

}

CQSisCompitiendo *CQSisGmnCompitiendo::ObtenCompitiendo()
{
	return CQSCompitiendo;
}
CQSisLstGmnCompitiendo::CQSisLstGmnCompitiendo()
{

}
CQSisLstGmnCompitiendo &CQSisLstGmnCompitiendo::operator<<(
			CQSisGmnCompitiendo *pCQSGmnCompitiendo)
{
	append(pCQSGmnCompitiendo);
	return *this;
}
CQSisLstLstCompitiendo::CQSisLstLstCompitiendo()
{

}
CQSisLstLstCompitiendo &CQSisLstLstCompitiendo::operator<<
			(CQSisLstCompitiendo *pCQSLCompitiendo)
{
	append(pCQSLCompitiendo);
	return *this;
}
void CQSisLstLstCompitiendo::Clases(CQSisLstClase *pCQSLClases)
{
CQSisLstCompitiendo *lCQSLCompitiendo;
CQSisCompitiendo *lCQSCompitiendo;
for(lCQSLCompitiendo=first();
    lCQSLCompitiendo;
    lCQSLCompitiendo=next())
 for(lCQSCompitiendo=lCQSLCompitiendo->first();
     lCQSCompitiendo;
     lCQSCompitiendo=lCQSLCompitiendo->next())
  if(!(*pCQSLClases)[lCQSCompitiendo->ObtenClase()])
   (*pCQSLClases)<< lCQSCompitiendo->ObtenClase();
}
void CQSisLstLstCompitiendo::Niveles(CQSisClase *pCQSClase,
				     CQSisLstClaseNivel *pCQSLCNivel)
{

CQSisLstCompitiendo *lCQSLCompitiendo;
CQSisCompitiendo *lCQSCompitiendo;
CQSisClaseNivel *lCQSCNivel;
for(lCQSLCompitiendo=first();
    lCQSLCompitiendo;
    lCQSLCompitiendo=next())
 for(lCQSCompitiendo=lCQSLCompitiendo->first();
     lCQSCompitiendo;
     lCQSCompitiendo=lCQSLCompitiendo->next())
 {
   lCQSCNivel=new CQSisClaseNivel(lCQSCompitiendo->ObtenClase(),
   				  lCQSCompitiendo->ObtenNivel());
   if(!(*pCQSLCNivel)[lCQSCNivel])
   (*pCQSLCNivel) << lCQSCNivel;
 }

}
void CQSisLstLstCompitiendo::Grupos(CQSisClaseNivel *pCQSCNivel,
				    CQSisLstGrupo *pCQSLGrupo)
{
CQSisLstCompitiendo *lCQSLCompitiendo;
CQSisCompitiendo *lCQSCompitiendo;
for(lCQSLCompitiendo=first();
    lCQSLCompitiendo;
    lCQSLCompitiendo=next())
for(lCQSCompitiendo=lCQSLCompitiendo->first();
    lCQSCompitiendo;
    lCQSCompitiendo=lCQSLCompitiendo->next())
{

if((*lCQSCompitiendo->ObtenClase())==pCQSCNivel->Clase() &&
   (*lCQSCompitiendo->ObtenNivel())==pCQSCNivel->Nivel() &&
   !(*pCQSLGrupo)[lCQSCompitiendo->ObtenGrupo()])
 (*pCQSLGrupo) << lCQSCompitiendo->ObtenGrupo();
}

}
void CQSisLstLstCompitiendo::Gimnastas(CQSisClaseNivel *pCQSCNivel,
				       CQSisGrupo *pCQSGrupo,
				       CQSisLstLstCompitiendo *pCQSLLCompitiendo)
{
CQSisLstCompitiendo *lCQSLCompitiendo;
CQSisCompitiendo *lCQSCompitiendo;
for(lCQSLCompitiendo=first();
    lCQSLCompitiendo;
    lCQSLCompitiendo=next())
{
lCQSCompitiendo=lCQSLCompitiendo->at(0);

if((*lCQSCompitiendo->ObtenClase())==pCQSCNivel->Clase() &&
   (*lCQSCompitiendo->ObtenNivel())==pCQSCNivel->Nivel() &&
   (*lCQSCompitiendo->ObtenGrupo())==pCQSGrupo)
  (*pCQSLLCompitiendo) << lCQSLCompitiendo;
}
}
void CQSisLstLstCompitiendo::Gimnastas(CQSisClaseNivel *pCQSCNivel,
				       CQSisGrupo *pCQSGrupo,
				       CQSisAparatoCompetencia *pCQSACompetencia,
				       CQSisLstLstCompitiendo *pCQSLLCompitiendo)
{

CQSisLstCompitiendo *lCQSLCompitiendo;
CQSisCompitiendo *lCQSCompitiendo;
for(lCQSLCompitiendo=first();
    lCQSLCompitiendo;
    lCQSLCompitiendo=next())
{
lCQSCompitiendo=lCQSLCompitiendo->at(0);
for(lCQSCompitiendo=lCQSLCompitiendo->first();
    lCQSCompitiendo;
    lCQSCompitiendo=lCQSLCompitiendo->next())
{
if((*lCQSCompitiendo->ObtenClase())==pCQSCNivel->Clase() &&
   (*lCQSCompitiendo->ObtenNivel())==pCQSCNivel->Nivel() &&
   (*lCQSCompitiendo->ObtenGrupo())==pCQSGrupo           &&
   (*lCQSCompitiendo->ObtenCalificacion())==pCQSACompetencia->ObtenAparato())
  (*pCQSLLCompitiendo) << lCQSLCompitiendo;
}
}
}

void CQSisLstLstCompitiendo::Gimnastas(CQSisClaseNivel *pCQSCNivel,
				       CQSisGrupo *pCQSGrupo,
				       CQSisAparatoCompetencia *pCQSACompetencia,
				       CQSisLstCompitiendo *pCQSLCompitiendo)
{

CQSisLstCompitiendo *lCQSLCompitiendo;
CQSisCompitiendo *lCQSCompitiendo;
CQSisLstCompitiendo *lCQSLCompitiendoRegreso;
/*
printf("Buscando %s\t%s\t%s\t%s\n",
	(*pCQSCNivel->Clase())["Clase"],
	(*pCQSCNivel->Nivel())["Nivel"],
	(*pCQSGrupo)["RangoEdad"],
	(*pCQSACompetencia->ObtenAparato())["Aparato"]);
*/
for(lCQSLCompitiendo=first();
    lCQSLCompitiendo;
    lCQSLCompitiendo=next())
{
for(lCQSCompitiendo=lCQSLCompitiendo->first();
    lCQSCompitiendo;
    lCQSCompitiendo=lCQSLCompitiendo->next())
{
if((*lCQSCompitiendo->ObtenClase())==pCQSCNivel->Clase() &&
   (*lCQSCompitiendo->ObtenNivel())==pCQSCNivel->Nivel() &&
   (*lCQSCompitiendo->ObtenGrupo())==pCQSGrupo           &&
   (*lCQSCompitiendo->ObtenCalificacion())==pCQSACompetencia->ObtenAparato())
{
 /*printf("\t%s\n",(*lCQSCompitiendo->ObtenGimnasta())["Nombre"]); */
  (*pCQSLCompitiendo) << lCQSCompitiendo;

}
}
}
}

void CQSisOpGmnCompitiendo::TablaResultados(
		CQSisCompetencia *pCQSCompetencia,
		CQSisLstLstCompitiendo *pCQSLLCompitiendo)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
	pCQSLLCompitiendo->clear();
	SPConsulta						<<
	new SiscomParametroConsulta("TablaResultados")	<<
	new SiscomParametroConsulta(pCQSCompetencia->SRegistrosPro2["IdCompetencia"]) <<
	new SiscomParametroConsulta(pCQSCompetencia->SRegistrosPro2["IdTipoCompetencia"]);
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaGimnasio",&lSRegistrosPro2);
	FormaClasificacion(lSRegistrosPro2,pCQSLLCompitiendo);
}
CQSisOpGmnCompitiendo::CQSisOpGmnCompitiendo(SiscomDatCom *pSisDatCom):
			SiscomOperaciones(pSisDatCom)
{

}

					
void CQSisOpGmnCompitiendo::ObtenClasificacionGmn(
		CQSisCompetencia *pCQSCompetencia,
		CQSisAparatoCompetencia *pCQSACompetencia,
		CQSisLstLstCompitiendo *pCQSLLCompitiendo)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SPConsulta						<<
new SiscomParametroConsulta("ClasificaGimnastas")	<<
new SiscomParametroConsulta(pCQSCompetencia->SRegistrosPro2["IdCompetencia"])	<<
new SiscomParametroConsulta(pCQSCompetencia->SRegistrosPro2["IdTipoCompetencia"]) <<
new SiscomParametroConsulta(pCQSACompetencia->ObtenAparato()->SRegistrosPro2["IdAparato"]);
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaGimnasio",&lSRegistrosPro2);
	FormaClasificacion(lSRegistrosPro2,pCQSLLCompitiendo);
}
void CQSisOpGmnCompitiendo::ObtenCompetenciaGeneral(
		CQSisCompetencia *pCQSCompetencia,
		CQSisLstLstCompitiendo *pCQSLLCompitiendo)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
	pCQSLLCompitiendo->clear();
	SPConsulta						<<
	new SiscomParametroConsulta("CompetenciaGeneral")	<<
	new SiscomParametroConsulta(pCQSCompetencia->SRegistrosPro2["IdCompetencia"]) <<
	new SiscomParametroConsulta(pCQSCompetencia->SRegistrosPro2["IdTipoCompetencia"]);
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaGimnasio",&lSRegistrosPro2);
	FormaClasificacion(lSRegistrosPro2,pCQSLLCompitiendo);
}
void CQSisOpGmnCompitiendo::ObtenResultadosPorAparato(
		CQSisCompetencia *pCQSCompetencia,
		CQSisLstLstCompitiendo *pCQSLLCompitiendo)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
	pCQSLLCompitiendo->clear();
	SPConsulta						<<
	new SiscomParametroConsulta("ResultadosPorAparato")	<<
	new SiscomParametroConsulta(pCQSCompetencia->SRegistrosPro2["IdCompetencia"]) <<
	new SiscomParametroConsulta(pCQSCompetencia->SRegistrosPro2["IdTipoCompetencia"]);
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaGimnasio",&lSRegistrosPro2);
	FormaClasificacion(lSRegistrosPro2,pCQSLLCompitiendo);
}
void CQSisOpGmnCompitiendo::CalificaRonda(
			CQSisCompetencia *pCQSCompetencia,
			CQSisLstLstRonda *pCQSLLRonda)
{

SiscomRegistrosPro2 *lSRegistrosPro2;

SPConsulta					<<
new SiscomParametroConsulta("CalificaRonda")	<<
new SiscomParametroConsulta(pCQSCompetencia->SRegistrosPro2["IdCompetencia"]);

SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultaGimnasio",&lSRegistrosPro2);
	FormaRondas(lSRegistrosPro2,pCQSLLRonda);
}
void CQSisOpGmnCompitiendo::FormaRondas(SiscomRegistrosPro2 *pSRegistrosPro2,
					CQSisLstLstRonda *pCQSLLRonda)
{
CQSisLstRonda *lCQSLRonda;
CQSisLstCompitiendo *lCQSLCompitiendo;
CQSisCompitiendo *lCQSCompitiendo;
CQSisCalificacion *lCQSCalificacion;
CQSisAparatoCompetencia *lCQSACompetencia;
CQSisAparato *lCQSAparato;
const char *lchrPtrIdRonda;
const char *lchrPtrRonda;
const char *lchrPtrIdCompetencia;
	for(;
	    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	    ++(*pSRegistrosPro2))
	{
	   ++(*pSRegistrosPro2); 
	   lCQSLRonda=new CQSisLstRonda;
	    lchrPtrIdRonda=(*pSRegistrosPro2)["idronda"];
	    lchrPtrRonda=(*pSRegistrosPro2)["nmbronda"];
	    printf("%s [%s]\n",
	           lchrPtrIdRonda,
		   lchrPtrRonda);
	  for(;
	       !pSRegistrosPro2->SiscomEsElUltimoRegistro()&&
	       !EsFinDeLaRonda(pSRegistrosPro2);
	       ++(*pSRegistrosPro2))
	 {
	   lCQSLCompitiendo=new CQSisLstCompitiendo;
	   lCQSAparato=new CQSisAparato(
				   (*pSRegistrosPro2)["idaparato"],
				   (*pSRegistrosPro2)["aparato"],
				   "");
	   printf("\t%s\n",(*pSRegistrosPro2)["aparato"]);
	    /*
	    lchrPtrIdRonda=(*pSRegistrosPro2)["idronda"];
	    lchrPtrRonda=(*pSRegistrosPro2)["nmbronda"];
	    */
	   ++(*pSRegistrosPro2); 
	   for(;
	   	!pSRegistrosPro2->SiscomEsElUltimoRegistro() &&
		!EsFinGimnastaAparato(pSRegistrosPro2);
		++(*pSRegistrosPro2))
	   {
	   printf("%s\t%s\t%s\n",
				(*pSRegistrosPro2)["nmbgimnasta"],
				(*pSRegistrosPro2)["apatgimnasta"],
				(*pSRegistrosPro2)["amatgimnasta"]);
	   	  
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
				"",
				"",
				(*pSRegistrosPro2)["edadinf"],
				(*pSRegistrosPro2)["edadsup"],
				(*pSRegistrosPro2)["grupo"],
				(*pSRegistrosPro2)["rangoedad"]),
			new CQSisEntrenador(
				(*pSRegistrosPro2)["nmbentrenador"],
				(*pSRegistrosPro2)["apatentrenador"],
				(*pSRegistrosPro2)["amatentrenador"],
				""),
			"");

		lCQSCalificacion=new CQSisCalificacion(
				new CQSisAparato(
				   (*pSRegistrosPro2)["idaparato"],
				   (*pSRegistrosPro2)["aparato"],
				   ""),
				(*pSRegistrosPro2)["dificultad"],
				(*pSRegistrosPro2)["ejecucion"],
				(*pSRegistrosPro2)["notafinal"]);
		lCQSCompitiendo->PonCalificacion(lCQSCalificacion);
		(*lCQSLCompitiendo) << lCQSCompitiendo;	
	   }
	    lCQSACompetencia=new CQSisAparatoCompetencia(lCQSAparato,0),
	    (*lCQSLRonda) << new CQSisRonda(
	    			 lchrPtrIdRonda,
				 lchrPtrRonda,
				 "",
				 lCQSACompetencia,
				 lCQSLCompitiendo);
	    lCQSLRonda->AnexaAparato(lCQSACompetencia);
	    				
	}
	    (*pCQSLLRonda) << lCQSLRonda;
	}
}
void CQSisOpGmnCompitiendo::FormaClasificacion(
		SiscomRegistrosPro2 *pSRegistrosPro2,
		CQSisLstLstCompitiendo *pCQSLLCompitiendo)
{
CQSisLstCompitiendo *lCQSLCompitiendo;
CQSisCompitiendo *lCQSCompitiendo;
CQSisCalificacion *lCQSCalificacion;
CQSisAparatoCompetencia *lCQSACompetencia;
	
	for(;
	    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	    ++(*pSRegistrosPro2))
	{
	   ++(*pSRegistrosPro2);
	   lCQSLCompitiendo=new CQSisLstCompitiendo;
	   for(;
	  	!pSRegistrosPro2->SiscomEsElUltimoRegistro() &&
		!EsFinClaseNivel(pSRegistrosPro2);
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
				"",
				"",
				(*pSRegistrosPro2)["edadinf"],
				(*pSRegistrosPro2)["edadsup"],
				(*pSRegistrosPro2)["grupo"],
				(*pSRegistrosPro2)["rangoedad"]),
			new CQSisEntrenador(
				(*pSRegistrosPro2)["nmbentrenador"],
				(*pSRegistrosPro2)["apatentrenador"],
				(*pSRegistrosPro2)["amatentrenador"],
				""),
			"");
		lCQSCalificacion=new CQSisCalificacion(
				new CQSisAparato(
				   (*pSRegistrosPro2)["idaparato"],
				   (*pSRegistrosPro2)["aparato"],
				   ""),
				(*pSRegistrosPro2)["dificultad"],
				(*pSRegistrosPro2)["ejecucion"],
				(*pSRegistrosPro2)["notafinal"]);
		lCQSCompitiendo->PonCalificacion(lCQSCalificacion);
		(*lCQSLCompitiendo) << lCQSCompitiendo;	
	   }
	   (*pCQSLLCompitiendo) << lCQSLCompitiendo;
	}
}
int CQSisOpGmnCompitiendo::EsFinClaseNivel(SiscomRegistrosPro2 *pSRegistrosPro2)
{

return !(*pSRegistrosPro2)["nmbgimnasta"][0] 	&&
       !(*pSRegistrosPro2)["apatgimnasta"][0] 	&&
       !(*pSRegistrosPro2)["amatgimnasta"][0] 	&&
       !(*pSRegistrosPro2)["clase"][0]		&&
       !(*pSRegistrosPro2)["nivel"][0];

}
int CQSisOpGmnCompitiendo::EsFinGimnastaAparato(SiscomRegistrosPro2 *pSRegistrosPro2)
{
return !(*pSRegistrosPro2)["idaparato"][0] &&
       !(*pSRegistrosPro2)["aparato"][0];  
}
int CQSisOpGmnCompitiendo::EsFinDeLaRonda(SiscomRegistrosPro2 *pSRegistrosPro2)
{
	return !(*pSRegistrosPro2)["idronda"][0] &&
	       !(*pSRegistrosPro2)["nmbronda"][0];
}

CQSisClaseNivel::CQSisClaseNivel(CQSisClase *pCQSClase,
				 CQSisNivel *pCQSNivel):
			CQSClase(pCQSClase),
			CQSNivel(pCQSNivel)
{

}
CQSisClase *CQSisClaseNivel::Clase()
{
return CQSClase;
}
CQSisNivel *CQSisClaseNivel::Nivel()
{
return CQSNivel;
}
int CQSisClaseNivel::operator==(CQSisClaseNivel *pCQSClaseNivel)
{
return (*CQSClase)==pCQSClaseNivel->Clase() &&
       (*CQSNivel)==pCQSClaseNivel->Nivel();
}
int CQSisClaseNivel::operator==(const char *pchrPtrClase)
{
   return !strcmp((*CQSClase)["Clase"],pchrPtrClase);
}
CQSisLstClaseNivel::CQSisLstClaseNivel()
{

}
CQSisLstClaseNivel &CQSisLstClaseNivel::operator<<(CQSisClaseNivel *pCQCNivel)
{
	append(pCQCNivel);
	return *this;
}
int CQSisLstClaseNivel::operator[](CQSisClaseNivel *pCQSCNivel)
{
CQSisClaseNivel *lCQSCNivel;
for(lCQSCNivel=first();
    lCQSCNivel;
    lCQSCNivel=next())
if((*lCQSCNivel)==pCQSCNivel)
 return 1;

 return 0;
}
CQSisLstClaseNivel *CQSisLstClaseNivel::operator[](const char *pchrPtrClase)
{
CQSisLstClaseNivel *lCQSLCNivel=new CQSisLstClaseNivel;
CQSisClaseNivel *lCQSCNivel;
for(lCQSCNivel=first();
    lCQSCNivel;
    lCQSCNivel=next())
if((*lCQSCNivel)==pchrPtrClase)
(*lCQSLCNivel) << lCQSCNivel;


return lCQSLCNivel;


}
