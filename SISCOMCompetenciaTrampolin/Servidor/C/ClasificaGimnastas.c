#include <ClasificaGimnastas.h>
#include <stdlib.h>
#include <string.h>
#include <ServidorGeneral.h>
void EnviaInformacionCliente(SArgsSiscom *pSAgsSiscom)
{

	SiscomEnviaAlServidor(
		pSAgsSiscom->intSocketCliente,
		SiscomArgumentosNumeroRegistros("GimClasificadas" ,pSAgsSiscom),
		"Respuesta",
		SiscomArgumentoOperacionPrim("GimClasificadas",pSAgsSiscom));
}
SiscomOperaciones2 *ClasificaGimnastas()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(AsignaArgumentosClasificacion,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(SQLClasificaGimnastas,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ObtenGrupos,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ObtenNiveles,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ObtenClases,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(EjecutaClasificacionGimnastas,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ActualizaRangoEdad,lSOpPtrGimnasio);  
SiscomAnexaOperacionAlArreglo2(EnviaInformacionCliente,lSOpPtrGimnasio);

return lSOpPtrGimnasio;
}
void FormaEstructuraClases(LCamposSiscomPro2 *pLCSiscomPro2Clases,
			   StcSisFormaRegistro *pSSFormaReg)
{
int lintContador;

	memset(pSSFormaReg,0,sizeof(StcSisFormaRegistro));
	pSSFormaReg->chrPtrCampo=strdup("idcompetencia");
	for(lintContador=0;
	    pLCSiscomPro2Clases;
	    pLCSiscomPro2Clases=pLCSiscomPro2Clases->SCP2PtrSig,
	    lintContador++)
	 {
	   pSSFormaReg->SSRegistro[lintContador].chrPtrCampo=strdup("clase");
	   pSSFormaReg->SSRegistro[lintContador].chrPtrValor=SiscomObtenDato(
	   						pLCSiscomPro2Clases,
							"clase");

	 }

}
void FormaEstructuraSubRegistro(LCamposSiscomPro2 *pLCSiscomPro2Grupos,
				LCamposSiscomPro2 *pLCSiscomPro2,
				StcSisFormaRegistro *pSSForReg)
{
int lintContador;

	memset(pSSForReg,0,sizeof(StcSisFormaRegistro));
	pSSForReg->chrPtrCampo=strdup("idcompetencia");
	for(lintContador=0;
	    pLCSiscomPro2Grupos;
	    pLCSiscomPro2Grupos=pLCSiscomPro2Grupos->SCP2PtrSig,
	    lintContador++)
	{
	    pSSForReg->SSRegistro[lintContador].chrPtrCampo=strdup("grupo");
	    pSSForReg->SSRegistro[lintContador].chrPtrValor=SiscomObtenDato(
	    					pLCSiscomPro2Grupos,
						"grupo");
	}	
}
void FormaEstructuraSubNiveles(LCamposSiscomPro2 *pLCSiscomPro2Niveles,
			       StcSisFormaRegistro *pSSForReg)
{
int lintContador;
	memset(pSSForReg,0,sizeof(StcSisFormaRegistro));
	pSSForReg->chrPtrCampo=strdup("idcompetencia");
	for(lintContador=0;
	    pLCSiscomPro2Niveles;
	    lintContador++,
	    pLCSiscomPro2Niveles=pLCSiscomPro2Niveles->SCP2PtrSig)
	{
		pSSForReg->SSRegistro[lintContador].chrPtrCampo=strdup("nivel");
		pSSForReg->SSRegistro[lintContador].chrPtrValor=SiscomObtenDato(
							pLCSiscomPro2Niveles,
							"nivel");
	}
}
void ClasificaPorNiveles(int pintNumGrupos,
			 LCamposSiscomPro2 *pLCSiscomPro2Niveles,
			 LCamposSiscomPro2ConSubReg *pLCSiscomPro2SubG,
			 LCamposSiscomPro2ConSubReg **pLCSiscomPro2SubNiveles)
{
int lintContador;
StcSisFormaRegistro lSSFormaReg;

		FormaEstructuraSubNiveles(pLCSiscomPro2Niveles,&lSSFormaReg);
		*pLCSiscomPro2SubNiveles=(LCamposSiscomPro2ConSubReg *)malloc(
					sizeof(LCamposSiscomPro2ConSubReg)*
					(pintNumGrupos+1));
	for(lintContador=0;
	    lintContador<pintNumGrupos;
	    lintContador++)
	{
	   SiscomLeeConSubRegistros(
	   	pLCSiscomPro2SubG->LCSiscomSubReg[lintContador].LCSiscomPro2Prim,
		&lSSFormaReg,
		(*pLCSiscomPro2SubNiveles)+lintContador);
	}
}
void FormaRespuestaClasificacionClaseNivel(LCamposSiscomPro2 *pLCSiscomPro2Clases,
					   LCamposSiscomPro2 *pLCSiscomPro2Niveles,
					   LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRClases,
					   SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2ResPrim=0,
		  *lLCSiscomPro2ResAct=0;
LCamposSiscomPro2 *lLCSiscomPro2Niveles=pLCSiscomPro2Niveles;
LCamposSiscomPro2 *lLCSiscomPro2Contador;
int lintClases;
int lintNiveles;
int lintNumRegRespuesta=0;
SCampoSiscomPro2 *lSCSiscomPro2Dat;

for(lintClases=0;
	pLCSiscomPro2Clases;
    pLCSiscomPro2Clases=pLCSiscomPro2Clases->SCP2PtrSig,
    lintClases++)
{
/*
  SiscomMensajesLog(gPtrFleArchivoLog,"%s",SiscomObtenDato(pLCSiscomPro2Clases,"clase"));
  */
  for(lLCSiscomPro2Niveles=pLCSiscomPro2Niveles,
      lintNiveles=0;
      lLCSiscomPro2Niveles;
      lintNiveles++,
      lLCSiscomPro2Niveles=lLCSiscomPro2Niveles->SCP2PtrSig)
  {
      if((lLCSiscomPro2Contador=(pLCSiscomPro2SRClases+lintClases)->LCSiscomSubReg[lintNiveles].LCSiscomPro2Prim))
      {
       lSCSiscomPro2Dat=lLCSiscomPro2Contador->SCSiscomPro2;
       AnexaRegistroInicioClaseNivel(SiscomObtenDato(pLCSiscomPro2Clases,"clase"),
       				     SiscomObtenDato(lLCSiscomPro2Niveles,"nivel"),
				     lLCSiscomPro2Contador->SCSiscomPro2,
				     &lLCSiscomPro2ResPrim,
				     &lLCSiscomPro2ResAct,
				     &lintNumRegRespuesta);
/*
    SiscomMensajesLog(gPtrFleArchivoLog,
    		      "Nivel %s",
		      SiscomObtenDato(lLCSiscomPro2Niveles,"nivel"));
*/
	for(;
	    lLCSiscomPro2Contador;
	    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
	{
	/*
	  SiscomMuestraContenidoRegistro("Prueba",
	  				 gPtrFleArchivoLog,
					 lLCSiscomPro2Contador->SCSiscomPro2);
	*/
	  SiscomCreaListaCamposPro2(lLCSiscomPro2Contador->SCSiscomPro2,
	  			    &lLCSiscomPro2ResPrim,
				    &lLCSiscomPro2ResAct);
	  lintNumRegRespuesta++;
	}
	AnexaRegistroInicioClaseNivel("",
       				     "",
				     lSCSiscomPro2Dat,
				     &lLCSiscomPro2ResPrim,
				     &lLCSiscomPro2ResAct,
				     &lintNumRegRespuesta);

      }

  }
}
/*
SiscomMensajesLog2("La Respuesta");
SiscomImprimeContenidoProtocolo2("",lLCSiscomPro2ResPrim); 

*/

SiscomAsignaArgumentoOperacionPrim("GimClasificadas",lLCSiscomPro2ResPrim,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("GimClasificadas",lintNumRegRespuesta,pSAgsSiscom);

}


void EjecutaClasificacionGimnastas(SArgsSiscom *pSAgsSiscom)
{
StcSisFormaRegistro lSSFormaRegClases;
LCamposSiscomPro2ConSubReg lLCSiscomPro2SClases;
LCamposSiscomPro2ConSubReg *lLCSiscomPro2SubNiveles;
LCamposSiscomPro2ConSubReg lLCSiscomPro2SGrupos[200];
LCamposSiscomPro2 *lLCSiscomPro2GmnsReg;
LCamposSiscomPro2 *lLCSiscomPro2Niveles;
LCamposSiscomPro2 *lLCSiscomPro2Clases;
LCamposSiscomPro2 *lLCSiscomPro2Contador;
int lintNumGrupos=SiscomArgumentosNumeroRegistros("GimGrupos",pSAgsSiscom);
int lintNumClases=SiscomArgumentosNumeroRegistros("GimClases",pSAgsSiscom);
int lintNumNiveles=SiscomArgumentosNumeroRegistros("GimNiveles",pSAgsSiscom);
int lintContador;
int lintContadorJ;
int lintNumSubGrupos;

lLCSiscomPro2GmnsReg=SiscomArgumentoOperacionPrim("GimCompetencia",pSAgsSiscom);
lLCSiscomPro2Niveles=SiscomArgumentoOperacionPrim("GimNiveles",pSAgsSiscom);
lLCSiscomPro2Clases=SiscomArgumentoOperacionPrim("GimClases",pSAgsSiscom);
	memset(lLCSiscomPro2SGrupos,0,sizeof(LCamposSiscomPro2ConSubReg)*100);
	FormaEstructuraClases(
		lLCSiscomPro2Clases,
		&lSSFormaRegClases);
	SiscomLeeConSubRegistros(lLCSiscomPro2GmnsReg,
				 &lSSFormaRegClases,
				 &lLCSiscomPro2SClases);
	ClasificaPorNiveles(lintNumClases,
			    lLCSiscomPro2Niveles,
			    &lLCSiscomPro2SClases,
			    &lLCSiscomPro2SubNiveles);
	ClasificaPorGrupos(lintNumClases,
			   lintNumNiveles,
			   lintNumGrupos,
			   lLCSiscomPro2SubNiveles,
			   pSAgsSiscom,
			   lLCSiscomPro2SGrupos,
			   &lintNumSubGrupos);
	FormaRespuestaClasificacion(lintNumGrupos,
				    lintNumSubGrupos,
				     lLCSiscomPro2SGrupos,
				     pSAgsSiscom);
}
void FormaRespuestaClasificacion(int pintNumGrupos,
				 int pintNumSubGrupos,
				 LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRGrupos,
				 SArgsSiscom *pSAgsSiscom)
{
int lintGrupos;
int lintContador;
LCamposSiscomPro2 *lLCSiscomPro2Grupo;
LCamposSiscomPro2 *lLCSiscomPro2Contador;
LCamposSiscomPro2 *lLCSiscomPro2ResPrim=0,
                  *lLCSiscomPro2ResAct=0;
int lintNumRes=0;
	for(lintContador=0;
	    lintContador<pintNumSubGrupos;
	    lintContador++)
	{
	for(lintGrupos=0;
	    lintGrupos<pintNumGrupos;
	    lintGrupos++)
	if((lLCSiscomPro2Grupo=(pLCSiscomPro2SRGrupos+lintContador)->LCSiscomSubReg[lintGrupos].LCSiscomPro2Prim))
	{
	/*
	  SiscomMensajesLog2("%s %s",
	  		     SiscomObtenDato(lLCSiscomPro2Grupo,"clase"),
			     SiscomObtenDato(lLCSiscomPro2Grupo,"nivel"));
	*/
	  AnexaRegistroInicioClaseNivel(SiscomObtenDato(lLCSiscomPro2Grupo,"clase"),
	  				SiscomObtenDato(lLCSiscomPro2Grupo,"nivel"),
					lLCSiscomPro2Grupo->SCSiscomPro2,
					&lLCSiscomPro2ResPrim,
					&lLCSiscomPro2ResAct,
					&lintNumRes);
	
	  for(lLCSiscomPro2Contador=lLCSiscomPro2Grupo;
	      lLCSiscomPro2Contador;
	      lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
	  {
		SiscomCreaListaCamposPro2(
				lLCSiscomPro2Contador->SCSiscomPro2,
				&lLCSiscomPro2ResPrim,
				&lLCSiscomPro2ResAct);
		lintNumRes++;
		
	  }
	  AnexaRegistroInicioClaseNivel("",
	  				"",
					lLCSiscomPro2Grupo->SCSiscomPro2,
					&lLCSiscomPro2ResPrim,
					&lLCSiscomPro2ResAct,
					&lintNumRes);


	}
	}
SiscomAsignaArgumentoOperacionPrim("GimClasificadas",lLCSiscomPro2ResPrim,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("GimClasificadas",lintNumRes,pSAgsSiscom);
}
void SQLClasificaGimnastas(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Regreso=0;
int lintNRegRespuesta=0;
char lchrArrConsultaSQL[2048];
	sprintf(lchrArrConsultaSQL,"							\
select	a.idCompetencia,								\
	a.idGimnasta,									\
	b.Nombre	as NmbGimnasta,							\
       	b.APaterno	as APatGimnasta,						\
       	b.AMaterno	as AMatGimnasta,						\
       	c.Nombre	as NmbEntrenador,						\
       	c.APaterno	as APatEntrenador,						\
       	c.AMaterno	as AMatEntrenador,						\
       	d.idClase,									\
       	d.Clase,									\
       	e.idNivel,									\
       	e.nivel,									\
       	idgimnasio,									\
       	f.nombre	as gimnasio,							\
	g.idgrupo,									\
       	g.edadinf,									\
       	g.edadsup,									\
       	g.grupo,									\
	''		as rangoedad,							\
	h.ejecucion,									\
	h.dificultad,									\
	h.ejecucion-h.dificultad as notafinal,						\
	'' as idtipocompetencia,							\
	'' as idaparato,								\
	'' as aparato									\
from	compitiendo		as a							\
	inner join personas	as b on (idgimnasta=b.idpersona)			\
	inner join personas	as c on (identrenador=c.idpersona)			\
	inner join catclase	as d using(idclase) 					\
	inner join catnivel	as e on (a.idclase=e.idclase and 			\
	                                 a.idnivel=e.idnivel   )			\
	inner join gimnasio 	as f on (idgimnasiopqc=idgimnasio)			\
	inner join grupos	as g using(idgrupo)					\
	inner join calificaciones as h on (a.idgimnasta=h.idgimnasta and		\
	                                   a.idcompetencia=h.idcompetencia)		\
	inner join aparatos	as i using(idAparato)					\
where 	a.idCompetencia=%s	and							\
	h.idAparato=%s									\
order by d.clase,									\
	 e.nivel,									\
	 g.idgrupo,									\
	 b.APaterno,									\
	 b.AMaterno,									\
	 b.Nombre",
pSAgsSiscom->chrPtrArgConsulta[1],
pSAgsSiscom->chrPtrArgConsulta[3]);
SiscomConsultaBaseDatosSinDatosConexion(
	lchrArrConsultaSQL,
	gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
	gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	&lLCSiscomPro2Regreso,
	&lintNRegRespuesta);
SiscomAsignaArgumentoOperacionPrim("GimCompetencia",lLCSiscomPro2Regreso,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("GimCompetetencia",lintNRegRespuesta,pSAgsSiscom);
}
void AsignaArgumentosClasificacion(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(6,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"GimCompetencia",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"GimClasificadas",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"GimGrupos",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(3,"GimNiveles",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(4,"GimClases",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(5,"GimAparatos",pSAgsSiscom);
}
void ObtenGrupos(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Regreso=0;
char lchrArrSQL[125];
int lintNRegRespuesta;
	sprintf(lchrArrSQL,
		"select distinct * 		\
		 from grupos 			\
		 where idtipocompetencia=%s",
	pSAgsSiscom->chrPtrArgConsulta[2]);
SiscomConsultaBaseDatosSinDatosConexion(lchrArrSQL,
					gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
					gSSiscomConfiguracionSvr.intPtoAccesoDatos,
					&lLCSiscomPro2Regreso,
					&lintNRegRespuesta);
SiscomAsignaArgumentoOperacionPrim("GimGrupos",lLCSiscomPro2Regreso,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("GimGrupos",lintNRegRespuesta,pSAgsSiscom);
}
void ObtenClases(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Regreso=0;
char lchrArrSQL[125];
int lintNRegRespuesta;
	sprintf(lchrArrSQL,
		"SELECT * 			\
		from catclase			\
		where idtipocompetencia=%s",
	pSAgsSiscom->chrPtrArgConsulta[2]);
SiscomConsultaBaseDatosSinDatosConexion(lchrArrSQL,
					gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
					gSSiscomConfiguracionSvr.intPtoAccesoDatos,
					&lLCSiscomPro2Regreso,
					&lintNRegRespuesta);
SiscomAsignaArgumentoOperacionPrim("GimClases",lLCSiscomPro2Regreso,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("GimClases",lintNRegRespuesta,pSAgsSiscom);
}
void GeneraRangoEdad(LCamposSiscomPro2 *pLCSiscomPro2,
		     char *pchrPtrRangoEdad)
{
const char *lchrPtrEdadInf=SiscomObtenDato(pLCSiscomPro2,"edadinf");
const char *lchrPtrEdadSup=SiscomObtenDato(pLCSiscomPro2,"edadsup");

	if(SiscomObtenDato(pLCSiscomPro2,"idgimnasta")[0])
	{
	if(!strcmp(lchrPtrEdadInf,"-1") &&
	   !strcmp(lchrPtrEdadSup,"-1"))
	 strcpy(pchrPtrRangoEdad,"Opcional");
	 else
	 {
	if(!strcmp(lchrPtrEdadInf,"-1"))
	 lchrPtrEdadInf="Mas";
	if(!strcmp(lchrPtrEdadSup,"-1"))
	lchrPtrEdadSup="Mas";
	sprintf(pchrPtrRangoEdad,
		" [%s-%s A]",
		lchrPtrEdadInf,
		lchrPtrEdadSup);
	}
	}
}
void ActualizaRangoEdad(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2;
char lchrArrRangoEdad[20];
lLCSiscomPro2=SiscomArgumentoOperacionPrim("GimClasificadas",pSAgsSiscom);
for(;
    lLCSiscomPro2;
    lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
{
	GeneraRangoEdad(lLCSiscomPro2,lchrArrRangoEdad);
	SiscomAsignaDatoCampo2("rangoedad",lchrArrRangoEdad,lLCSiscomPro2); 
}
}
void ObtenNiveles(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Regreso=0;
char lchrArrSQL[125];
int lintNRegRespuesta;
	sprintf(lchrArrSQL,
		"SELECT distinct nivel from catnivel;");
SiscomConsultaBaseDatosSinDatosConexion(lchrArrSQL,
					gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
					gSSiscomConfiguracionSvr.intPtoAccesoDatos,
					&lLCSiscomPro2Regreso,
					&lintNRegRespuesta);
SiscomAsignaArgumentoOperacionPrim("GimNiveles",lLCSiscomPro2Regreso,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("GimNiveles",lintNRegRespuesta,pSAgsSiscom);
}
void FormaEstructuraSubGrupos(LCamposSiscomPro2 *pLCSiscomPro2Grupos,
			      StcSisFormaRegistro *pSSForReg)
{
int lintContador;

	memset(pSSForReg,0,sizeof(StcSisFormaRegistro));
	pSSForReg->chrPtrCampo=strdup("idcompetencia");

	for(lintContador=0;
	    pLCSiscomPro2Grupos;
	    lintContador++,
	    pLCSiscomPro2Grupos=pLCSiscomPro2Grupos->SCP2PtrSig)
	{
	   pSSForReg->SSRegistro[lintContador].chrPtrCampo=strdup("idgrupo");
	   pSSForReg->SSRegistro[lintContador].chrPtrValor=SiscomObtenDato(
	   					pLCSiscomPro2Grupos,
						"idgrupo");

	}

}
void ClasificaPorGrupos(int pintNumClases,
			int pintNumNiveles,
			int pintNumGrupos,
			LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRClases,
			SArgsSiscom *pSAgsSiscom,
			LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRGrupos,
			int *pintPtrResultados)
{
int lintClases;
int lintNiveles;
int lintGrupos;
int lintContador=0;
StcSisFormaRegistro lSSFormaGrupos;
LCamposSiscomPro2 *lLCSiscomPro2SubNivel;

	FormaEstructuraSubGrupos(
		SiscomArgumentoOperacionPrim("GimGrupos",pSAgsSiscom),
		&lSSFormaGrupos);
for(lintClases=0;
    lintClases<pintNumClases;
    lintClases++)
{
 for(lintNiveles=0;
     lintNiveles<pintNumNiveles;
     lintNiveles++)
{
   if((lLCSiscomPro2SubNivel=(pLCSiscomPro2SRClases+lintClases)->LCSiscomSubReg[lintNiveles].LCSiscomPro2Prim))
   {
       SiscomLeeConSubRegistros(
       		lLCSiscomPro2SubNivel,
		&lSSFormaGrupos,
		(pLCSiscomPro2SRGrupos+lintContador));
	lintContador++;
   }
}
}
*pintPtrResultados=lintContador;
}

void AnexaRegistroInicioClaseNivel(const char *pchrPtrClase,
				   const char *pchrPtrNivel,
				   SCampoSiscomPro2 *pSCSiscomPro2Dat,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNCampos)
{
int lintContador;
SCampoSiscomPro2 *lSCSiscomPro2;
	SiscomCopiaCampos(pSCSiscomPro2Dat,
			  &lSCSiscomPro2);
	SiscomAsignaDatoCampo2A("clase",pchrPtrClase,lSCSiscomPro2);
	SiscomAsignaDatoCampo2A("nivel",pchrPtrNivel,lSCSiscomPro2);
	SiscomAsignaDatoCampo2A("idcompetencia","0",lSCSiscomPro2);
	SiscomCreaListaCamposPro2(lSCSiscomPro2,
				  pLCSiscomPro2Prim,
				  pLCSiscomPro2Act);
	(*pintPtrNCampos)++;

}
