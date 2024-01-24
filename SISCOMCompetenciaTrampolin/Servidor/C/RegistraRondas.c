#include <RegistraRondas.h>
int GeneraRegistro(LCamposSiscomPro2 *pLCSiscomPro2Dat)
{

return SiscomObtenDato(pLCSiscomPro2Dat,"IdCompetencia")[0] &&
       SiscomObtenDato(pLCSiscomPro2Dat,"IdGimnasta")[0];


}
void SQLDetalleRonda(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Contador;
LCamposSiscomPro2 *lLCSiscomPro2Prim,
		  *lLCSiscomPro2Act;
int lintNumRegs=0;
char lchrArrSQL[256];
lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("Rondas",pSAgsSiscom);
lLCSiscomPro2Act=SiscomArgumentoOperacionAct("Rondas",pSAgsSiscom);
lintNumRegs=SiscomArgumentosNumeroRegistros("Rondas",pSAgsSiscom);
lLCSiscomPro2Contador=pSAgsSiscom->LCSiscomPro2Dat;
for(;
	lLCSiscomPro2Contador;
   	lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
if(GeneraRegistro(lLCSiscomPro2Contador))
{
sprintf(lchrArrSQL,
	"insert into detalleronda values(%s,%s,%s);",
	SiscomObtenDato(lLCSiscomPro2Contador,"IdRonda"),
	SiscomObtenDato(lLCSiscomPro2Contador,"IdGimnasta"),
	SiscomObtenDato(lLCSiscomPro2Contador,"IdAparato"));
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNumRegs,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
}
SiscomAsignaArgumentoOperacionPrim("Rondas",lLCSiscomPro2Prim,pSAgsSiscom);
SiscomAsignaArgumentoOperacionAct("Rondas",lLCSiscomPro2Act,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("Rondas",lintNumRegs,pSAgsSiscom);
}
void SQLRonda(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim,
		  *lLCSiscomPro2Act;
LCamposSiscomPro2 *lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Dat;
int lintNumRegs=0;
char lchrArrSQL[256];
char lchrArrIdRonda[15];
const char *lchrPtrRonda;
SiscomImprimeContenidoProtocolo2("SQLRonda",pSAgsSiscom->LCSiscomPro2Dat);
lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("Rondas",pSAgsSiscom);
lLCSiscomPro2Act=SiscomArgumentoOperacionAct("Rondas",pSAgsSiscom);
lintNumRegs=SiscomArgumentosNumeroRegistros("Rondas",pSAgsSiscom);

lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig;

while(lLCSiscomPro2Dat)
{
lchrPtrRonda=SiscomObtenDato(lLCSiscomPro2Dat,"Ronda");
sprintf(lchrArrSQL,
	"insert into Rondas values(%s,'%s',%s);",
	SiscomObtenDato(lLCSiscomPro2Dat,"IdRonda"),
	SiscomObtenDato(lLCSiscomPro2Dat,"Ronda"),
	SiscomObtenDato(lLCSiscomPro2Dat,"IdCompetencia"));
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNumRegs,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
for(;
    lLCSiscomPro2Dat &&
    !strcmp(lchrPtrRonda,
    	   SiscomObtenDato(lLCSiscomPro2Dat,"Ronda"));
    lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig);
}
SiscomAsignaArgumentoOperacionPrim("Rondas",lLCSiscomPro2Prim,pSAgsSiscom);
SiscomAsignaArgumentoOperacionAct("Rondas",lLCSiscomPro2Act,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("Rondas",lintNumRegs,pSAgsSiscom);
}

void SqlEliminaRonda(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim,
		  *lLCSiscomPro2Act;
LCamposSiscomPro2 *lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Dat;
int lintNumRegs=0;
char lchrArrSQL[256];
char lchrArrIdRonda[15];
lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("Rondas",pSAgsSiscom);
lLCSiscomPro2Act=SiscomArgumentoOperacionAct("Rondas",pSAgsSiscom);
lintNumRegs=SiscomArgumentosNumeroRegistros("Rondas",pSAgsSiscom);
lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig;
SiscomImprimeContenidoProtocolo2("SqlEliminaRondas",lLCSiscomPro2Dat);
sprintf(lchrArrSQL,
	"delete from rondas where idronda=%s;",
	SiscomObtenDato(lLCSiscomPro2Dat,"IdRonda"));
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNumRegs,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
SiscomAsignaArgumentoOperacionPrim("Rondas",lLCSiscomPro2Prim,pSAgsSiscom);
SiscomAsignaArgumentoOperacionAct("Rondas",lLCSiscomPro2Act,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("Rondas",lintNumRegs,pSAgsSiscom);
}

void SqlEliminaDetalleRonda(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim,
		  *lLCSiscomPro2Act;
LCamposSiscomPro2 *lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Dat;
int lintNumRegs=0;
char lchrArrSQL[256];
char lchrArrIdRonda[15];
lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("Rondas",pSAgsSiscom);
lLCSiscomPro2Act=SiscomArgumentoOperacionAct("Rondas",pSAgsSiscom);
lintNumRegs=SiscomArgumentosNumeroRegistros("Rondas",pSAgsSiscom);
lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig;

sprintf(lchrArrSQL,
	"delete from detalleronda 			\
	 where idronda in(select idronda 		\
	                  from rondas 			\
			  where idcompetencia=%s);",
	SiscomObtenDato(lLCSiscomPro2Dat,"IdCompetencia"));
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNumRegs,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
SiscomAsignaArgumentoOperacionPrim("Rondas",lLCSiscomPro2Prim,pSAgsSiscom);
SiscomAsignaArgumentoOperacionAct("Rondas",lLCSiscomPro2Act,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("Rondas",lintNumRegs,pSAgsSiscom);
}

