#include <ResultadosCompetencia.h>
#include <ClasificaGimnastas.h>
#include <ServidorGeneral.h>
#include <stdlib.h>
#include <string.h>
SiscomOperaciones2 *TablaResultados()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(AsignaArgumentosClasificacion,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(SQLTablaResultados,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ObtenGrupos,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ObtenNiveles,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ObtenClases,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(EjecutaClasificacionGimnastas,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ActualizaRangoEdad,lSOpPtrGimnasio);  
SiscomAnexaOperacionAlArreglo2(EnviaInformacionCliente,lSOpPtrGimnasio);
return lSOpPtrGimnasio;

}
SiscomOperaciones2 *CompetenciaGeneral()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(AsignaArgumentosClasificacion,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(SQLCompetenciaGeneral,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ObtenGrupos,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ObtenNiveles,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ObtenClases,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(EjecutaClasificacionGimnastas,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ActualizaRangoEdad,lSOpPtrGimnasio);  
SiscomAnexaOperacionAlArreglo2(EnviaInformacionCliente,lSOpPtrGimnasio);
return lSOpPtrGimnasio;
}
SiscomOperaciones2 *ResultadosPorAparato()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(AsignaArgumentosClasificacion,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(SQLResultadoAparatos,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ObtenGrupos,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ObtenNiveles,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ObtenClases,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ObtenAparatos,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(EjecutaResultadosPorAparato,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ActualizaRangoEdad,lSOpPtrGimnasio);  
SiscomAnexaOperacionAlArreglo2(EnviaInformacionCliente,lSOpPtrGimnasio);
return lSOpPtrGimnasio;
}
void SQLCompetenciaGeneral(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Regreso=0;
int lintNRegRespuesta=0;
char lchrArrConsultaSQL[2048];
sprintf(lchrArrConsultaSQL,"								\
select	a.idCompetencia,								\
	a.idGimnasta,									\
	b.Nombre		as NmbGimnasta,						\
       	b.APaterno		as APatGimnasta,					\
       	b.AMaterno		as AMatGimnasta,					\
       	d.idClase,									\
       	d.Clase,									\
       	e.idNivel,									\
       	e.nivel,									\
       	idgimnasio,									\
       	f.nombre		as gimnasio,						\
	g.idgrupo,									\
       	g.edadinf,									\
       	g.edadsup,									\
       	g.grupo,									\
	''			as rangoedad,						\
	sum(h.ejecucion-h.dificultad) as notafinal					\
from	compitiendo		as a							\
	inner join personas	as b on (idgimnasta=b.idpersona)			\
	inner join catclase	as d using(idclase) 					\
	inner join catnivel	as e on (a.idclase=e.idclase and 			\
	                                 a.idnivel=e.idnivel   )			\
	inner join gimnasio 	as f on (idgimnasiopqc=idgimnasio)			\
	inner join grupos	as g using(idgrupo)					\
	inner join calificaciones as h on (a.idgimnasta=h.idgimnasta and		\
	                                        a.idcompetencia=h.idcompetencia)	\
	inner join aparatos	as i using(idAparato)					\
where 	a.idCompetencia=%s								\
group by										\
	a.idCompetencia,								\
	a.idGimnasta,									\
	b.Nombre,									\
       	b.APaterno,									\
       	b.AMaterno,									\
       	d.idClase,									\
       	d.Clase,									\
       	e.idNivel,									\
       	e.nivel,									\
       	idgimnasio,									\
       	f.nombre,									\
	g.idgrupo,									\
       	g.edadinf,									\
       	g.edadsup,									\
       	g.grupo										\
order by d.clase,									\
	 e.nivel,									\
	 g.idgrupo,									\
	 notafinal desc",
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomConsultaBaseDatosSinDatosConexion(
	lchrArrConsultaSQL,
	gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
	gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	&lLCSiscomPro2Regreso,
	&lintNRegRespuesta);
SiscomAsignaArgumentoOperacionPrim("GimCompetencia",lLCSiscomPro2Regreso,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("GimCompetetencia",lintNRegRespuesta,pSAgsSiscom);
}
void SQLResultadoAparatos(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Regreso=0;
int lintNRegRespuesta=0;
char lchrArrConsultaSQL[2048];
sprintf(lchrArrConsultaSQL,"								\
select	a.idCompetencia,								\
	a.idGimnasta,									\
	b.Nombre		as NmbGimnasta,						\
       	b.APaterno		as APatGimnasta,					\
       	b.AMaterno		as AMatGimnasta,					\
       	d.idClase,									\
       	d.Clase,									\
       	e.idNivel,									\
       	e.nivel,									\
       	idgimnasio,									\
       	f.nombre		as gimnasio,						\
	g.idgrupo,									\
       	g.edadinf,									\
       	g.edadsup,									\
       	g.grupo,									\
	''			as rangoedad,						\
	i.aparato,									\
	h.ejecucion-h.dificultad as notafinal						\
from	compitiendo		as a							\
	inner join personas	as b on (idgimnasta=b.idpersona)			\
	inner join catclase	as d using(idclase) 					\
	inner join catnivel	as e on (a.idclase=e.idclase and 			\
	                                 a.idnivel=e.idnivel   )			\
	inner join gimnasio 	as f on (idgimnasiopqc=idgimnasio)			\
	inner join grupos	as g using(idgrupo)					\
	inner join calificaciones as h on (a.idgimnasta=h.idgimnasta and		\
	                                        a.idcompetencia=h.idcompetencia)	\
	inner join aparatos	as i using(idAparato)					\
where 	a.idCompetencia=%s								\
group by a.idCompetencia,								\
	a.idGimnasta,									\
	b.Nombre,									\
       	b.APaterno,									\
       	b.AMaterno,									\
       	d.idClase,									\
       	d.Clase,									\
       	e.idNivel,									\
       	e.nivel,									\
       	idgimnasio,									\
       	f.nombre,									\
	g.idgrupo,									\
       	g.edadinf,									\
       	g.edadsup,									\
       	g.grupo,									\
	i.aparato,									\
	h.ejecucion,									\
	h.dificultad									\
order by d.clase,									\
	 e.nivel,									\
	 g.idgrupo,									\
	 i.aparato,									\
	 notafinal desc",
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomConsultaBaseDatosSinDatosConexion(
	lchrArrConsultaSQL,
	gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
	gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	&lLCSiscomPro2Regreso,
	&lintNRegRespuesta);
SiscomAsignaArgumentoOperacionPrim("GimCompetencia",lLCSiscomPro2Regreso,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("GimCompetetencia",lintNRegRespuesta,pSAgsSiscom);
}

void SQLTablaResultados(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Regreso=0;
int lintNRegRespuesta=0;
char lchrArrConsultaSQL[2048];
sprintf(lchrArrConsultaSQL,"								\
select	a.idCompetencia,								\
	a.idGimnasta,									\
	b.Nombre		as NmbGimnasta,						\
       	b.APaterno		as APatGimnasta,					\
       	b.AMaterno		as AMatGimnasta,					\
       	d.idClase,									\
       	d.Clase,									\
       	e.idNivel,									\
       	e.nivel,									\
       	idgimnasio,									\
       	f.nombre		as gimnasio,						\
	g.idgrupo,									\
       	g.edadinf,									\
       	g.edadsup,									\
       	g.grupo,									\
	''			as rangoedad,						\
	i.aparato,									\
	h.ejecucion-h.dificultad as notafinal						\
from	compitiendo		as a							\
	inner join personas	as b on (idgimnasta=b.idpersona)			\
	inner join catclase	as d using(idclase) 					\
	inner join catnivel	as e on (a.idclase=e.idclase and 			\
	                                 a.idnivel=e.idnivel   )			\
	inner join gimnasio 	as f on (idgimnasiopqc=idgimnasio)			\
	inner join grupos	as g using(idgrupo)					\
	inner join calificaciones as h on (a.idgimnasta=h.idgimnasta and		\
	                                        a.idcompetencia=h.idcompetencia)	\
	inner join aparatos	as i using(idAparato)					\
where 	a.idCompetencia=%s								\
group by a.idCompetencia,								\
	a.idGimnasta,									\
	b.Nombre,									\
       	b.APaterno,									\
       	b.AMaterno,									\
       	d.idClase,									\
       	d.Clase,									\
       	e.idNivel,									\
       	e.nivel,									\
       	idgimnasio,									\
       	f.nombre,									\
	g.idgrupo,									\
       	g.edadinf,									\
       	g.edadsup,									\
       	g.grupo,									\
	i.aparato,									\
	h.ejecucion,									\
	h.dificultad									\
order by d.clase,									\
	 e.nivel,									\
	 g.idgrupo,									\
	 i.aparato,									\
	 b.APaterno,									\
	 b.AMaterno,									\
	 b.Nombre",
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomConsultaBaseDatosSinDatosConexion(
	lchrArrConsultaSQL,
	gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
	gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	&lLCSiscomPro2Regreso,
	&lintNRegRespuesta);
SiscomAsignaArgumentoOperacionPrim("GimCompetencia",lLCSiscomPro2Regreso,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("GimCompetetencia",lintNRegRespuesta,pSAgsSiscom);
}
void ObtenAparatos(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Regreso=0;
char lchrArrSQL[1024];
int lintNRegRespuesta;
	sprintf(lchrArrSQL,
		"select idaparato,							\
			aparato 							\
		 from	aparatoscompetencia inner join 					\
		 	aparatos using(idaparato) 					\
		where idtipocompetencia in (select idtipocompetencia 			\
					    from competencia 				\
					    where idcompetencia=%s)",
		pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomConsultaBaseDatosSinDatosConexion(lchrArrSQL,
					gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
					gSSiscomConfiguracionSvr.intPtoAccesoDatos,
					&lLCSiscomPro2Regreso,
					&lintNRegRespuesta);
SiscomAsignaArgumentoOperacionPrim("GimAparatos",lLCSiscomPro2Regreso,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("GimAparatos",lintNRegRespuesta,pSAgsSiscom);
}


void EjecutaResultadosPorAparato(SArgsSiscom *pSAgsSiscom)
{
StcSisFormaRegistro lSSFormaRegClases;
LCamposSiscomPro2ConSubReg lLCSiscomPro2SClases;
LCamposSiscomPro2ConSubReg *lLCSiscomPro2SubNiveles;
LCamposSiscomPro2ConSubReg lLCSiscomPro2SGrupos[100];
LCamposSiscomPro2ConSubReg lLCSiscomPro2SAparatos[100];
LCamposSiscomPro2 *lLCSiscomPro2GmnsReg;
LCamposSiscomPro2 *lLCSiscomPro2Niveles;
LCamposSiscomPro2 *lLCSiscomPro2Clases;
LCamposSiscomPro2 *lLCSiscomPro2Aparatos;
LCamposSiscomPro2 *lLCSiscomPro2Contador;
int lintNumGrupos=SiscomArgumentosNumeroRegistros("GimGrupos",pSAgsSiscom);
int lintNumClases=SiscomArgumentosNumeroRegistros("GimClases",pSAgsSiscom);
int lintNumNiveles=SiscomArgumentosNumeroRegistros("GimNiveles",pSAgsSiscom);
int lintNumAparatos=SiscomArgumentosNumeroRegistros("GimAparatos",pSAgsSiscom);
int lintContador;
int lintContadorJ;
int lintNumSubGrupos;
int lintNumGrupoAparato;

lLCSiscomPro2GmnsReg=SiscomArgumentoOperacionPrim("GimCompetencia",pSAgsSiscom);
lLCSiscomPro2Niveles=SiscomArgumentoOperacionPrim("GimNiveles",pSAgsSiscom);
lLCSiscomPro2Clases=SiscomArgumentoOperacionPrim("GimClases",pSAgsSiscom);
lLCSiscomPro2Aparatos=SiscomArgumentoOperacionPrim("GimAparatos",pSAgsSiscom);
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
	ClasificaGruposPorAparato(lintNumGrupos,
				  lintNumSubGrupos,
				  lLCSiscomPro2Aparatos,
				  lLCSiscomPro2SGrupos,
				  lLCSiscomPro2SAparatos,
				  &lintNumGrupoAparato);
	FormaRespuestaResultadosAparatos(lintNumGrupoAparato,
					 lintNumAparatos,
					 lLCSiscomPro2SAparatos,
					 pSAgsSiscom);
	
}
void FormaRespuestaResultadosAparatos(int pintNGrupoAparato,
				      int pintNumAparatos,
				      LCamposSiscomPro2ConSubReg *pLCSiscomPro2CSRA,
				      SArgsSiscom *pSAgsSiscom)
{
int lintAparato;
int lintContador;
LCamposSiscomPro2 *lLCSiscomPro2Grupo;
LCamposSiscomPro2 *lLCSiscomPro2Contador;
LCamposSiscomPro2 *lLCSiscomPro2ResPrim=0;
LCamposSiscomPro2 *lLCSiscomPro2ResAct=0;
int lintNumRes=0;

	for(lintContador=0;
	    lintContador<pintNGrupoAparato;
	    lintContador++)
	 for(lintAparato=0;
	     lintAparato<pintNumAparatos;
	     lintAparato++)
	  if((lLCSiscomPro2Grupo=(pLCSiscomPro2CSRA+lintContador)->LCSiscomSubReg[lintAparato].LCSiscomPro2Prim))
	  {

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
	
SiscomAsignaArgumentoOperacionPrim("GimClasificadas",lLCSiscomPro2ResPrim,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("GimClasificadas",lintNumRes,pSAgsSiscom);
}
void FormaEstructuraSubAparatos(LCamposSiscomPro2 *pLCSiscomPro2Aparatos,
				StcSisFormaRegistro *pSSFormaReg)
{
int lintContador;

	memset(pSSFormaReg,0,sizeof(StcSisFormaRegistro));
	pSSFormaReg->chrPtrCampo=strdup("aparato");
	for(lintContador=0;
	    pLCSiscomPro2Aparatos;
	    pLCSiscomPro2Aparatos=pLCSiscomPro2Aparatos->SCP2PtrSig,
	    lintContador++)
	{
		pSSFormaReg->SSRegistro[lintContador].chrPtrCampo=strdup("aparato");
		pSSFormaReg->SSRegistro[lintContador].chrPtrValor=
						SiscomObtenDato(pLCSiscomPro2Aparatos,
								"aparato");
	}
}
void ClasificaGruposPorAparato(int pintNGrupos,
			       int pintNSubGrupos,
			       LCamposSiscomPro2 *pLCSiscomPro2Aparatos,
			       LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRGrupos,
			       LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRAparatos,
			       int *pintPtrNGrupoAparato)
{
int lintGrupos;
int lintSubGrupos;
int lintContador=0;
StcSisFormaRegistro lSSFormaReg;
LCamposSiscomPro2 *lLCSiscomPro2Grupo;
	FormaEstructuraSubAparatos(pLCSiscomPro2Aparatos,
				   &lSSFormaReg);

	for(lintSubGrupos=0;
	    lintSubGrupos<pintNSubGrupos;
	    lintSubGrupos++)
	for(lintGrupos=0;
	    lintGrupos<pintNGrupos;
	    lintGrupos++)
	if((lLCSiscomPro2Grupo=(pLCSiscomPro2SRGrupos+lintSubGrupos)->LCSiscomSubReg[lintGrupos].LCSiscomPro2Prim))
	{
	    SiscomLeeConSubRegistros(
	    		lLCSiscomPro2Grupo,
			&lSSFormaReg,
			(pLCSiscomPro2SRAparatos+lintContador));
	    lintContador++;
	
	}
	*pintPtrNGrupoAparato=lintContador;	
}
