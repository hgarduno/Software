#include <RegistraJuez.h>
void RegistraJuez(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQLInsercion[256];
LCamposSiscomPro2 *lLCSiscomPro2Prim,
		  *lLCSiscomPro2Act;
int lintNumRegistros;
lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
lLCSiscomPro2Act=SiscomArgumentoOperacionAct("I_Gimnasio",pSAgsSiscom);
lintNumRegistros=SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom);
SiscomMensajesLog(gPtrFleArchivoLog,"RegistraJuez");
sprintf(lchrArrSQLInsercion,
	"insert into jueces values(%s);",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPersona"));
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
