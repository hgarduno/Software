#include <RegistraDireccion.h>
void RegistraDireccion(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
		  *lLCSiscomPro2Act=SiscomArgumentoOperacionAct("I_Gimnasio",pSAgsSiscom);
int lintNumRegistros=SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom);
char lchrArrSQLInsercion[256];

sprintf(lchrArrSQLInsercion,
	"insert into direcciones values('%s','%s','%s',%s,%s);",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Calle"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Numero"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"ComoLlegar"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdAsentamiento"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdGimnasio"));

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
