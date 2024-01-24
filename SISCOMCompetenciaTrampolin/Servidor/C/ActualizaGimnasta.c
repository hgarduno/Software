#include <ActualizaGimnasta.h>


void SQLActualizaNombre(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim,
		  *lLCSiscomPro2Act;

int lintNRegistros;
char lchrArrSQL[256];
lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom);
lLCSiscomPro2Act=SiscomArgumentoOperacionAct("I_Gimnasio",pSAgsSiscom);
lintNRegistros=SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom);
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "SQLActualizaGimnasta");

sprintf(lchrArrSQL,
	"update personas set nombre='%s',		\
			     apaterno='%s',		\
			     amaterno='%s'		\
	 where idpersona=%s",
	 SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Nombre"),
	 SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"APaterno"),
	 SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"AMaterno"),
	 SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPersona"));
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
SiscomAsignaArgumentoOperacionPrim("I_Gimnasio",lLCSiscomPro2Prim,pSAgsSiscom);
SiscomAsignaArgumentoOperacionAct("I_Gimnasio",lLCSiscomPro2Act,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("I_Gimnasio",lintNRegistros,pSAgsSiscom);

}

void SQLActualizaEdad(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim,
		  *lLCSiscomPro2Act;

int lintNRegistros;
char lchrArrSQL[256];
lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom);
lLCSiscomPro2Act=SiscomArgumentoOperacionAct("I_Gimnasio",pSAgsSiscom);
lintNRegistros=SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom);
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "SQLActualizaEdad");

sprintf(lchrArrSQL,
	"update  gimnasta set fechanac='%s'	\
	 where idpersona=%s",
	 SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"FechaNac"),
	 SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPersona"));
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
SiscomAsignaArgumentoOperacionPrim("I_Gimnasio",lLCSiscomPro2Prim,pSAgsSiscom);
SiscomAsignaArgumentoOperacionAct("I_Gimnasio",lLCSiscomPro2Act,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("I_Gimnasio",lintNRegistros,pSAgsSiscom);


}
void SQLActualizaNombreNormalizado(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim,
		  *lLCSiscomPro2Act,
		  *lLCSiscomPro2Normalizada;

int lintNRegistros;
char lchrArrSQL[256];
lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom);
lLCSiscomPro2Act=SiscomArgumentoOperacionAct("I_Gimnasio",pSAgsSiscom);
lintNRegistros=SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom);

lLCSiscomPro2Normalizada=SiscomArgumentoOperacionPrim("C_Normalizado",pSAgsSiscom);
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "SQLActualizaNombreNormalizado");

sprintf(lchrArrSQL,
	"update personanormalizada set nombre='%s',		\
			     apaterno='%s',		\
			     amaterno='%s'		\
	 where idpersona=%s",
	 SiscomObtenDato(lLCSiscomPro2Normalizada,"Nombre"),
	 SiscomObtenDato(lLCSiscomPro2Normalizada,"APaterno"),
	 SiscomObtenDato(lLCSiscomPro2Normalizada,"AMaterno"),
	 SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPersona"));
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
SiscomAsignaArgumentoOperacionPrim("I_Gimnasio",lLCSiscomPro2Prim,pSAgsSiscom);
SiscomAsignaArgumentoOperacionAct("I_Gimnasio",lLCSiscomPro2Act,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("I_Gimnasio",lintNRegistros,pSAgsSiscom);
}
