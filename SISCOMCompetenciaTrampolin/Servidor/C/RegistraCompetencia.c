#include <RegistraCompetencia.h>

void RegistraCompetencia(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQLInsercion[256];
LCamposSiscomPro2 *lLCSiscomPro2Prim,
		  *lLCSiscomPro2Act;
int lintNumRegistros;
lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
lLCSiscomPro2Act=SiscomArgumentoOperacionAct("I_Gimnasio",pSAgsSiscom);
lintNumRegistros=SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom);
SiscomImprimeContenidoProtocolo2("",pSAgsSiscom->LCSiscomPro2Dat);
sprintf(lchrArrSQLInsercion,
	"insert into competencia values('%s',%s,%s,'%s');",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Fecha"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdCompetencia"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdTipoCompetencia"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Competencia"));
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNumRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQLInsercion,
			"");
sprintf(lchrArrSQLInsercion,
	"insert into detallecompetencia values(%s,'%s','%s','%s','%s');",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdCompetencia"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Descripcion"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Bases"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"FecIniInsc"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"FecFinInsc"));
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

