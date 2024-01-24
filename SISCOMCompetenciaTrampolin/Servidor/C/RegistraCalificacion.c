#include <RegistraCalificacion.h>
void RegistraCalificacion(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQLInsercion[256];
LCamposSiscomPro2 *lLCSiscomPro2Prim,
		  *lLCSiscomPro2Act;
int lintNumRegistros;
lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
lLCSiscomPro2Act=SiscomArgumentoOperacionAct("I_Gimnasio",pSAgsSiscom);
lintNumRegistros=SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom);
sprintf(lchrArrSQLInsercion,
	"insert into calificaciones(idcompetencia,idgimnasta,idjuezdificultad,idjuezejecucion,idaparato) values(%s,%s,%s,%s,%s);",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdCompetencia"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdGimnasta"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdJuezEjecucion"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdJuezDificultad"),
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
