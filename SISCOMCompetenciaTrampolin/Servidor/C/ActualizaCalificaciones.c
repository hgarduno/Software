#include <ActualizaCalificaciones.h>
#include <ServidorGeneral.h>
void SQLActualizaEjecucion(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQLInsercion[256];
LCamposSiscomPro2 *lLCSiscomPro2Prim,
		  *lLCSiscomPro2Act;
int lintNumRegistros;
lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
lLCSiscomPro2Act=SiscomArgumentoOperacionAct("I_Gimnasio",pSAgsSiscom);
lintNumRegistros=SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom);
sprintf(lchrArrSQLInsercion,
	"update calificaciones set ejecucion=%s 			\
	 where	idCompetencia=%s	and 				\
	 	idGimnasta=%s 		and				\
		idAparato=%s",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Ejecucion"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdCompetencia"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdGimnasta"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdAparato"));
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNumRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQLInsercion,
			"");
SiscomMensajesLog2("%s",lchrArrSQLInsercion);
SiscomAsignaArgumentoOperacionPrim("I_Gimnasio",lLCSiscomPro2Prim,pSAgsSiscom);
SiscomAsignaArgumentoOperacionAct("I_Gimnasio",lLCSiscomPro2Act,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("I_Gimnasio",lintNumRegistros,pSAgsSiscom);
}
void SQLActualizaDificultad(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQLInsercion[256];
LCamposSiscomPro2 *lLCSiscomPro2Prim,
		  *lLCSiscomPro2Act;
int lintNumRegistros;
lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
lLCSiscomPro2Act=SiscomArgumentoOperacionAct("I_Gimnasio",pSAgsSiscom);
lintNumRegistros=SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom);
sprintf(lchrArrSQLInsercion,
	"update calificaciones set dificultad=%s 				\
	 where	idCompetencia=%s		and				\
	 	idGimnasta=%s			and				\
		idAparato=%s",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Dificultad"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdCompetencia"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdGimnasta"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdAparato"));
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNumRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQLInsercion,
			"");
SiscomAsignaArgumentoOperacionPrim("I_Gimnasio",lLCSiscomPro2Prim,pSAgsSiscom);
SiscomAsignaArgumentoOperacionAct("I_Gimnasio",lLCSiscomPro2Act,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("I_Gimnasio",lintNumRegistros,pSAgsSiscom);
}
