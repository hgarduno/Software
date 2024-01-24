#include <RegistraCompetidor.h>
void RegistraCompetidor(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQLInsercion[512];
char lchrArrFechaHoy[35];
LCamposSiscomPro2 *lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
		  *lLCSiscomPro2Act=SiscomArgumentoOperacionAct("I_Gimnasio",pSAgsSiscom);
int lintNumRegistros=SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom);
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
sprintf(lchrArrSQLInsercion,
	"insert into Compitiendo values(%s,%s,%s,%s,%s,%s,%s,'%s');",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdCompetencia"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdGimnasta"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdGimnasio"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdClase"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdNivel"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdGrupo"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdEntrenador"),
	lchrArrFechaHoy);
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNumRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQLInsercion,
			"");
SiscomAsignaArgumentoOperacionAct("I_Gimnasio",lLCSiscomPro2Act,pSAgsSiscom);
SiscomAsignaArgumentoOperacionPrim("I_Gimnasio",lLCSiscomPro2Prim,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("I_Gimnasio",lintNumRegistros,pSAgsSiscom);
}
void ActualizaCompetidor(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQLInsercion[512];
char lchrArrFechaHoy[35];
SiscomMensajesLog(gPtrFleArchivoLog,
		  "RegistraCompetidor");
LCamposSiscomPro2 *lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
		  *lLCSiscomPro2Act=SiscomArgumentoOperacionAct("I_Gimnasio",pSAgsSiscom);
int lintNumRegistros=SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom);
/* Es necesario saber donde se inician a cero 
 * todas los campos del argumento pSAgsSiscom 
 *
 */
lintNumRegistros=0;
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
sprintf(lchrArrSQLInsercion,
	"update compitiendo set idgimnasiopqc=%s,		\
				idclase=%s,			\
				idnivel=%s,			\
				idgrupo=%s,			\
				identrenador=%s,		\
				fecharegistro='%s'		\
	where idCompetencia=%s	and				\
	      idGimnasta=%s",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdGimnasio"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdClase"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdNivel"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdGrupo"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdEntrenador"),
	lchrArrFechaHoy,
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdCompetencia"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdGimnasta"));
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNumRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQLInsercion,
			"");
SiscomAsignaArgumentoOperacionAct("I_Gimnasio",lLCSiscomPro2Act,pSAgsSiscom);
SiscomAsignaArgumentoOperacionPrim("I_Gimnasio",lLCSiscomPro2Prim,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("I_Gimnasio",lintNumRegistros,pSAgsSiscom);
}
void IniciaCalificaciones(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQLInsercion[512];
LCamposSiscomPro2 *lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
		  *lLCSiscomPro2Act=SiscomArgumentoOperacionAct("I_Gimnasio",pSAgsSiscom);
int lintNumRegistros=SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom);
/*
sprintf(lchrArrSQLInsercion,
	"insert into Compitiendo values(%s,%s,%s,%s,%s,%s,%s,'%s');",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdCompetencia"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdGimnasta"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdGimnasio"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdClase"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdNivel"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdGrupo"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdEntrenador"),
	lchrArrFechaHoy);
*/
sprintf(lchrArrSQLInsercion,
	"insert into Calificaciones 					\
	 select %s,idaparato,%s,0,0,0,0,0				\
	 from aparatoscompetencia					\
	 where idtipoCompetencia=(select idTipoCompetencia		\
	 			  from competencia 			\
				  where idCompetencia=%s)",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdCompetencia"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdGimnasta"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdCompetencia"));
	
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNumRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQLInsercion,
			"");
SiscomAsignaArgumentoOperacionAct("I_Gimnasio",lLCSiscomPro2Act,pSAgsSiscom);
SiscomAsignaArgumentoOperacionPrim("I_Gimnasio",lLCSiscomPro2Prim,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("I_Gimnasio",lintNumRegistros,pSAgsSiscom);
}
