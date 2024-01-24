#include <ConsultasGimnasio.h>
#include <Gimnasios.h>
#include <ClasificaGimnastas.h>
#include <Grupos.h>
#include <GimnastasCompetencia01.h>

#include <ServidorGeneral.h>
#include <stdlib.h>
void ConsultaDireccionesPersona(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[256];
sprintf(lchrArrSQL,
	"SELECT * 							\
	 from	direcciones inner join 					\
	 	asentamientos using(idasentamiento) inner join 		\
		estados using(numestado) inner join 			\
		municipios using(nummunicipio)				\
	 where idpersona=%s",
	 pSAgsSiscom->chrPtrArgConsulta[1]);
EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}
void ConsultaMediosPersona(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[256];

SiscomMensajesLog(gPtrFleArchivoLog,"ConsultaClases");
sprintf(lchrArrSQL,
	"SELECT * 						\
	 from	comunicacionpersona inner join 			\
	 	catmediocomunicacion using(idmedio)		\
	 where idpersona=%s					\
	 order by idMedio",
	 pSAgsSiscom->chrPtrArgConsulta[1]);
EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}
void ConsultaGimnasiosRegistrados(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Regreso=0;
int lintNRegRespuesta=0;
	SiscomLog("");
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "ConsultaGimnasiosRegistrados");

	SiscomConsultaBaseDatosSinDatosConexion(
		"select * 			\
		from gimnasio 			\
		order by nombre",
		gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
		gSSiscomConfiguracionSvr.intPtoAccesoDatos,
		&lLCSiscomPro2Regreso,
		&lintNRegRespuesta);

	SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
			      lintNRegRespuesta,
			      "Respuesta",
			      lLCSiscomPro2Regreso);

	
}
void ConsultaClases(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[256];

SiscomMensajesLog(gPtrFleArchivoLog,"ConsultaClases");
sprintf(lchrArrSQL,
	"select * 			\
	 from catclase			\
	 where idtipocompetencia=%s",
	 pSAgsSiscom->chrPtrArgConsulta[1]);
EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}
void ConsultaNiveles(SArgsSiscom *pSAgsSiscom)
{
char lchrArrConsultaSQL[256];

SiscomMensajesLog(gPtrFleArchivoLog,"ConsultaNiveles");
	sprintf(lchrArrConsultaSQL,
		"select * 			\
		 from catnivel			\
		 where idclase=%s",
		 pSAgsSiscom->chrPtrArgConsulta[1]);

	EjecutaConsultaYResponde(pSAgsSiscom,lchrArrConsultaSQL);
		 
}
void ConsultaGrupos(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[256];
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNumRegRes;
SiscomMensajesLog(gPtrFleArchivoLog,"ConsultaGrupos");
sprintf(lchrArrSQL,
	"select *			\
	 from grupos			\
	 where idtipocompetencia=%s",
	 pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomConsultaBaseDatosSinDatosConexion(
	lchrArrSQL,
	gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
	gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	&lLCSiscomPro2Reg,
	&lintNumRegRes);
SiscomAsignaArgumentoOperacionPrim("GimResGrupos",lLCSiscomPro2Reg,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("GimResGrupos",lintNumRegRes,pSAgsSiscom);
}
void ConsultaCompetencias(SArgsSiscom *pSAgsSiscom)
{
SiscomMensajesLog(gPtrFleArchivoLog,"ConsultaCompetencias");
EjecutaConsultaYResponde(pSAgsSiscom,"select * from competencia");
}
void ConsultaCalificacionesGimnasta(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[256];

	FormaCadenaConsultaCalificacionesGimnasta(
		pSAgsSiscom->chrPtrArgConsulta[1],
		pSAgsSiscom->chrPtrArgConsulta[2],
		lchrArrSQL);

	EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}
SiscomOperaciones2 *DireccionesPersona()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(ConsultaDireccionesPersona,lSOpPtrGimnasio);
return lSOpPtrGimnasio;

}
SiscomOperaciones2 *MediosPersona()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(ConsultaMediosPersona,lSOpPtrGimnasio);
return lSOpPtrGimnasio;

}
SiscomOperaciones2 *GimnasiosRegistrados()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(ConsultaGimnasiosRegistrados,lSOpPtrGimnasio);
return lSOpPtrGimnasio;


}

SiscomOperaciones2 *ClasesRegistradas()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(ConsultaClases,lSOpPtrGimnasio);
return lSOpPtrGimnasio;
}
SiscomOperaciones2 *NivelesRegistrados()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(ConsultaNiveles,lSOpPtrGimnasio);
return lSOpPtrGimnasio;


}
SiscomOperaciones2 *GruposRegistrados()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(AsignaArgumentosGrupos,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ConsultaGrupos,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ObtenNombresGrupos,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ClasificaGruposPorGrupo,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(EnviaGrupos,lSOpPtrGimnasio);

return lSOpPtrGimnasio;
}
SiscomOperaciones2 *CompetenciasRegistradas()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(ConsultaCompetencias,lSOpPtrGimnasio);
return lSOpPtrGimnasio;
}
SiscomOperaciones2 *PersonasRegistradas()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(AsignaArgumentosPersonas,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(CopiaParametrosAFormatoPersonas,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(NormalizaContacto,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ConsultaPersonas,lSOpPtrGimnasio);
return lSOpPtrGimnasio;
}
SiscomOperaciones2 *GimnastasCompetencia()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(ConsultaGimnastasCompetencia,lSOpPtrGimnasio);
return lSOpPtrGimnasio;
}
SiscomOperaciones2 *GimnastasCompetencia01()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(AsignaArgumentosGimnastasCompetencia01,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ConsultaGimnastasCompetencia01,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ActualizaRangoEdad,lSOpPtrGimnasio); 
SiscomAnexaOperacionAlArreglo2(EnviaGimnastasCompetencia01,lSOpPtrGimnasio);
return lSOpPtrGimnasio;
}
SiscomOperaciones2 *CalificacionesGimnasta()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(ConsultaCalificacionesGimnasta,lSOpPtrGimnasio);
return lSOpPtrGimnasio;
}
SiscomOperaciones2 *TiposCompetencia()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomLog("");
SiscomAnexaOperacionAlArreglo2(ConsultaTiposCompetencia,lSOpPtrGimnasio);
return lSOpPtrGimnasio;
}
SiscomOperaciones2 *AparatosCompetencia()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(ConsultaAparatosCompetencia,lSOpPtrGimnasio);
return lSOpPtrGimnasio;
}
void FormaCadenaConsultaCalificacionesGimnasta(const char *pchrPtrIdGimnasta,
					       const char *pchrPtrIdCompetencia,
					       char *pchrPtrCadena)
{
	sprintf(pchrPtrCadena,
		"select idcompetencia,				\
			idgimnasta,				\
			idjuezdificultad,			\
			idjuezejecucion,			\
			dificultad,				\
			ejecucion,				\
			dificultad+ejecucion as notafinal	\
		 from calificaciones				\
		 where idcompetencia=%s and 			\
		       idgimnasta=%s",
		 pchrPtrIdCompetencia,
		 pchrPtrIdGimnasta);

}

void FormaCadenaConsultaGimnasta(const char *pchrPtrNombre,
				 const char *pchrPtrAPaterno,
				 const char *pchrPtrAMaterno,
				 char *pchrPtrCadena)
{
char lchrArrFechaHoy[15];

	SiscomObtenFechaHoyCharAAAADDMM(lchrArrFechaHoy);
	if(pchrPtrNombre[0] 	&&
	   pchrPtrAPaterno[0] 	&&
	   pchrPtrAMaterno[0])
	  sprintf(pchrPtrCadena,
	  	 "select c.*,						\
		 	 b.fechanac,					\
			 ('%s'::date-b.fechanac::date)/365 as edad	\
	 	 from	personanormalizada as a				\
		 	inner join gimnasta as b using(idPersona)	\
			inner join personas as c using(idPersona)	\
		 where	a.nombre='%s' 	and				\
		 	a.apaterno='%s' and				\
			a.amaterno='%s'					\
		order by a.apaterno,					\
		         a.amaterno,					\
			 a.nombre",			
		lchrArrFechaHoy,
		pchrPtrNombre,
		pchrPtrAPaterno,
		pchrPtrAMaterno);
	else
	if(pchrPtrNombre[0]	&&
	   pchrPtrAPaterno[0]	&&
	   !pchrPtrAMaterno[0])
	sprintf(pchrPtrCadena,
	  	 "select c.*,						\
		 	 b.fechanac,					\
			 ('%s'::date-b.fechanac::date)/365 as edad	\
	 	 from	personanormalizada as a				\
		 	inner join gimnasta as b using(idPersona)	\
			inner join personas as c using(idPersona)	\
		 where	a.nombre='%s' 	and				\
		 	a.apaterno='%s'					\
		order by a.apaterno,					\
		         a.amaterno,					\
			 a.nombre",			
		lchrArrFechaHoy,
		pchrPtrNombre,
		pchrPtrAPaterno);
	else
	if(!pchrPtrNombre[0]		&&
	    pchrPtrAPaterno[0]		&&
	   !pchrPtrAMaterno[0]	)
	sprintf(pchrPtrCadena,
	  	 "select c.*,						\
		 	 b.fechanac,					\
			 ('%s'::date-b.fechanac::date)/365 as edad	\
	 	 from	personanormalizada as a				\
		 	inner join gimnasta as b using(idPersona)	\
			inner join personas as c using(idPersona)	\
		 where  a.apaterno='%s'					\
		order by a.apaterno,					\
		         a.amaterno,					\
			 a.nombre",
		lchrArrFechaHoy,
		pchrPtrAPaterno);
	else
	sprintf(pchrPtrCadena,
	  	 "select c.*,						\
		 	 b.fechanac,					\
			 ('%s'::date-b.fechanac::date)/365 as edad	\
	 	 from	personanormalizada as a				\
		 	inner join gimnasta as b using(idPersona)	\
			inner join personas as c using(idPersona)	\
		order by a.apaterno,					\
		         a.amaterno,					\
			 a.nombre",
		 lchrArrFechaHoy);

}
void FormaCadenaConsultaEntrenador(const char *pchrPtrNombre,
				   const char *pchrPtrAPaterno,
				   const char *pchrPtrAMaterno,
				   char *pchrPtrCadena)
{
	if(pchrPtrNombre[0]	&&
	   pchrPtrAPaterno[0]	&&
	   pchrPtrAMaterno[0]	)
	  sprintf(pchrPtrCadena,
	  	  "select c.*						\
		   from personanormalizada as a				\
		   	inner join entrenadores as b using(idPersona)	\
			inner join personas as c using(idPersona)	\
		   where a.nombre='%s'  and				\
		   	 a.apaterno='%s'  and				\
			 a.amaterno='%s'",
		 pchrPtrNombre,
		 pchrPtrAPaterno,
		 pchrPtrAMaterno);
	  else
	 if(pchrPtrNombre[0]	&&
	   pchrPtrAPaterno[0]	&&
	   !pchrPtrAMaterno[0]	)
	  sprintf(pchrPtrCadena,
	  	  "select c.*						\
		   from personanormalizada as a				\
		   	inner join entrenadores as b using(idPersona)	\
			inner join personas as c using(idPersona)	\
		   where a.nombre='%s'  and				\
		   	 a.apaterno='%s'", 
		 pchrPtrNombre,
		 pchrPtrAPaterno);
	 else
	if(!pchrPtrNombre[0]	&&
	   pchrPtrAPaterno[0]	&&
	   !pchrPtrAMaterno[0]	)
	  sprintf(pchrPtrCadena,
	  	  "select c.*						\
		   from personanormalizada as a				\
		   	inner join entrenadores as b using(idPersona)	\
			inner join personas as c using(idPersona)	\
		   where a.apaterno='%s'", 
		 pchrPtrAPaterno);
	 else
	 	sprintf(pchrPtrCadena,
	  	  "select c.*						\
		   from personanormalizada as a				\
		   	inner join entrenadores as b using(idPersona)	\
			inner join personas as c using(idPersona)");
}
void GeneraCadenaConsulta(const char *pchrPtrPersona,
			  LCamposSiscomPro2 *pLCSiscomPro2Dat,
			  char *pchrPtrCadena)
{
const char *lchrPtrNombre,
	   *lchrPtrAPaterno,
	   *lchrPtrAMaterno;

lchrPtrNombre=SiscomObtenDato(pLCSiscomPro2Dat,"Nombre");
lchrPtrAPaterno=SiscomObtenDato(pLCSiscomPro2Dat,"APaterno");
lchrPtrAMaterno=SiscomObtenDato(pLCSiscomPro2Dat,"AMaterno");


	if(!strcmp(pchrPtrPersona,"gimnasta"))
	 FormaCadenaConsultaGimnasta(lchrPtrNombre,
	 			     lchrPtrAPaterno,
				     lchrPtrAMaterno,
				     pchrPtrCadena);
	else
	if(!strcmp(pchrPtrPersona,"entrenador"))
	FormaCadenaConsultaEntrenador(lchrPtrNombre,
				      lchrPtrAPaterno,
				      lchrPtrAMaterno,
				      pchrPtrCadena);
	 		


}
void ConsultaPersonas(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[512];
LCamposSiscomPro2 *lLCSiscomPro2Dat=0;
const char *lchrPtrNombre,
	   *lchrPtrAPaterno;
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "ConsultaPersonas");
	lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim("C_Normalizado",pSAgsSiscom);
	GeneraCadenaConsulta(pSAgsSiscom->chrPtrArgConsulta[1],
			     lLCSiscomPro2Dat,
			     lchrArrSQL);
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "%s",
			  lchrArrSQL);
	EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}
void ConsultaClasificaGimnastasCompetencia(SArgsSiscom *pSAgsSiscom)
{
char lchrArrConsultaSQL[2048];
	sprintf(lchrArrConsultaSQL,"							\
select	a.idCompetencia,								\
	a.idGimnasta,									\
	b.Nombre		as NmbGimnasta,						\
       	b.APaterno	as APatGimnasta,						\
       	b.AMaterno	as AMatGimnasta,						\
       	c.Nombre		as NmbEntrenador,					\
       	c.APaterno	as APatEntrenador,						\
       	c.AMaterno	as AMatEntrenador,						\
       	d.idClase,									\
       	d.Clase,									\
       	e.idNivel,									\
       	e.nivel,									\
       	idgimnasio,									\
       	f.nombre		as gimnasio,						\
       	g.edadinf,									\
       	g.edadsup,									\
       	g.grupo,									\
	h.ejecucion,									\
	h.dificultad,									\
	h.ejecucion+h.dificultad as notafinal						\
from	compitiendo		as a							\
	inner join personas	as b on (idgimnasta=b.idpersona)			\
	inner join personas	as c on (identrenador=c.idpersona)			\
	inner join catclase	as d using(idclase) 					\
	inner join catnivel	as e on (a.idclase=e.idclase and 			\
	                                 a.idnivel=e.idnivel   )			\
	inner join gimnasio 	as f on (idgimnasiopqc=idgimnasio)			\
	inner join grupos	as g using(idgrupo)					\
	left outer join calificaciones as h on (a.idgimnasta=h.idgimnasta and		\
	                                        a.idcompetencia=h.idcompetencia)	\
where 	a.idCompetencia=%s	and							\
	h.idaparato=%s									\
order by d.clase,									\
	 e.nivel,									\
	 g.grupo,									\
	 notafinal,									\
	 h.idaparato",
pSAgsSiscom->chrPtrArgConsulta[1],
pSAgsSiscom->chrPtrArgConsulta[2]);


}
void ConsultaAparatosCompetencia(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[1024];
	sprintf(lchrArrSQL,
	"								\
select idTipoCompetencia,						\
       Aparato,								\
       idAparato							\
from	competencia inner join 						\
	aparatoscompetencia using(idTipoCompetencia) inner join		\
	aparatos using(idaparato)					\
where idCompetencia=%s							\
order by ordenolimpico asc",
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomMensajesLog2("%s",lchrArrSQL);
EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}
void ConsultaTiposCompetencia(SArgsSiscom *pSAgsSiscom)
{
SiscomLog("");
	EjecutaConsultaYResponde(pSAgsSiscom,"select * from tipocompetencia");
}
void ConsultaGimnastasCompetencia01(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Regreso=0;
int lintNRegRespuesta=0;
char lchrArrConsultaSQL[2048];
	sprintf(lchrArrConsultaSQL,"							\
select	a.idCompetencia,								\
	a.idGimnasta,									\
	b.Nombre		as NmbGimnasta,						\
       	b.APaterno	as APatGimnasta,						\
       	b.AMaterno	as AMatGimnasta,						\
       	c.Nombre		as NmbEntrenador,					\
       	c.APaterno	as APatEntrenador,						\
       	c.AMaterno	as AMatEntrenador,						\
	a.identrenador,									\
       	d.idClase,									\
       	d.Clase,									\
       	e.idNivel,									\
       	e.nivel,									\
       	idgimnasio,									\
       	f.nombre		as gimnasio,						\
       	g.edadinf,									\
       	g.edadsup,									\
       	g.grupo,									\
	g.idgrupo,									\
	h.idtipocompetencia,								\
	'' as rangoedad,								\
	'' as idaparato,								\
	'' as aparato,									\
	'' as dificultad,								\
	'' as ejecucion,								\
	'' as notafinal									\
from	compitiendo		as a							\
	inner join personas	as b on (idgimnasta=b.idpersona)			\
	inner join personas	as c on (identrenador=c.idpersona)			\
	inner join catclase	as d using(idclase) 					\
	inner join catnivel	as e on (a.idclase=e.idclase and 			\
	                                 a.idnivel=e.idnivel   )			\
	inner join gimnasio 	as f on (idgimnasiopqc=idgimnasio)			\
	inner join grupos	as g using(idgrupo)					\
	inner join competencia as h using(idCompetencia)				\
where 	a.idCompetencia=%s								\
order by f.nombre,									\
         d.clase,									\
	 e.nivel,									\
	 g.grupo,									\
	 b.APaterno,									\
	 b.AMaterno,									\
	 b.nombre",
pSAgsSiscom->chrPtrArgConsulta[1]);
/*
 * Queretaro 25 De Noviembre 2008
 * En la ventana de Gimnastas Por Competencia
 * se cambio la forma de ordenar de 
  order by d.clase,									\
	 e.nivel,									\
	 g.grupo,									\
	 b.AMaterno,									\
	 b.APaterno,									\
	 b.Nombre",
 * al codigo actual
 */
SiscomConsultaBaseDatosSinDatosConexion(lchrArrConsultaSQL,
						gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
						gSSiscomConfiguracionSvr.intPtoAccesoDatos,
						&lLCSiscomPro2Regreso,
						&lintNRegRespuesta);
SiscomAsignaArgumentoOperacionPrim("GimClasificadas",lLCSiscomPro2Regreso,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("GimClasificadas",lintNRegRespuesta,pSAgsSiscom);
}
void ConsultaGimnastasCompetencia(SArgsSiscom *pSAgsSiscom)
{
char lchrArrConsultaSQL[2048];
	sprintf(lchrArrConsultaSQL,"							\
select	a.idCompetencia,								\
	a.idGimnasta,									\
	b.Nombre		as NmbGimnasta,						\
       	b.APaterno	as APatGimnasta,						\
       	b.AMaterno	as AMatGimnasta,						\
       	c.Nombre		as NmbEntrenador,					\
       	c.APaterno	as APatEntrenador,						\
       	c.AMaterno	as AMatEntrenador,						\
	a.identrenador,									\
       	d.idClase,									\
       	d.Clase,									\
       	e.idNivel,									\
       	e.nivel,									\
       	idgimnasio,									\
       	f.nombre		as gimnasio,						\
       	g.edadinf,									\
       	g.edadsup,									\
       	g.grupo,									\
	g.idgrupo,									\
	h.ejecucion,									\
	h.dificultad,									\
	h.ejecucion+h.dificultad as notafinal						\
from	compitiendo		as a							\
	inner join personas	as b on (idgimnasta=b.idpersona)			\
	inner join personas	as c on (identrenador=c.idpersona)			\
	inner join catclase	as d using(idclase) 					\
	inner join catnivel	as e on (a.idclase=e.idclase and 			\
	                                 a.idnivel=e.idnivel   )			\
	inner join gimnasio 	as f on (idgimnasiopqc=idgimnasio)			\
	inner join grupos	as g using(idgrupo)					\
	left outer join calificaciones as h on (a.idgimnasta=h.idgimnasta and		\
	                                        a.idcompetencia=h.idcompetencia)	\
where 	a.idCompetencia=%s and								\
	a.idAparato=%s									\
order by d.clase,									\
	 e.nivel,									\
	 g.grupo,									\
	 notafinal",
pSAgsSiscom->chrPtrArgConsulta[1],
pSAgsSiscom->chrPtrArgConsulta[2]);
	EjecutaConsultaYResponde(pSAgsSiscom,lchrArrConsultaSQL);
	

}
void EjecutaConsultaYResponde(SArgsSiscom *pSAgsSiscom,
			      const char *pchrPtrConsultaSQL)
{
LCamposSiscomPro2 *lLCSiscomPro2Regreso=0;
int lintNRegRespuesta=0;
SiscomLog("Antes");
	SiscomConsultaBaseDatosSinDatosConexion(
		pchrPtrConsultaSQL,
		gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
		gSSiscomConfiguracionSvr.intPtoAccesoDatos,
		&lLCSiscomPro2Regreso,
		&lintNRegRespuesta);

	SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
			      lintNRegRespuesta,
			      "Respuesta",
			      lLCSiscomPro2Regreso);
	SiscomLog("%s",pchrPtrConsultaSQL);
	SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,lLCSiscomPro2Regreso);  

}
