#include <RegistraGimnasta.h>
#include <RegistraPersona.h>
#include <string.h>
#include <ctype.h>

void RegistraGimnasta(SArgsSiscom *pSAgsSiscom)
{
char lchrArrFechaNac[15];
char lchrArrSQLInsercion[256];
LCamposSiscomPro2 *lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
		  *lLCSiscomPro2Act=SiscomArgumentoOperacionAct("I_Gimnasio",pSAgsSiscom);

int lintNumRegistros=SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom);

	ObtenFechaNacimiento(pSAgsSiscom->LCSiscomPro2Dat,lchrArrFechaNac);
	sprintf(lchrArrSQLInsercion,
		"insert into gimnasta(idpersona,idgimnasio,fechanac) values(%s,%s,'%s');",
		SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPersona"),
		SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdGimnasio"),
		lchrArrFechaNac);
	
	  SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNumRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQLInsercion,
			"");




SiscomAsignaArgumentoOperacionAct("I_Gimnasio",lLCSiscomPro2Act,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("I_Gimnasio",lintNumRegistros,pSAgsSiscom);
}
int EsValidaLaFecha(const char *pchrPtrFecha)
{
int lintSi=1;
	for(;*pchrPtrFecha;*pchrPtrFecha++)
	if(*pchrPtrFecha!='-' &&
	   !isdigit(*pchrPtrFecha))
	{
	lintSi=0;
	return  0;
	}
return 1;
}
void ObtenFechaNacimiento(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			  char *pchrPtrFechaNac)
{
	if(!EsValidaLaFecha(SiscomObtenDato(pLCSiscomPro2Dat,"FechaNac")))
	SiscomObtenFechaHoyCharAAAADDMM(pchrPtrFechaNac);
	else
	strcpy(pchrPtrFechaNac,SiscomObtenDato(pLCSiscomPro2Dat,"FechaNac"));
}
