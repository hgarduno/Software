#include <RegistraMedioComunicacion.h>
#include <ServidorGeneral.h>
#include <string.h>
/*
 *
 * Esta funcion debera tomar la informacion de los medios de comunicacion
 * de una estructura de argumento con nombre Medios
 *
 *
 */
void RegistraMedioComunicacion2(SArgsSiscom *pSAgsSiscom)
{
char lchrArrIdMedio[12];
char lchrArrSQLInsercion[256];
LCamposSiscomPro2 *lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
		  *lLCSiscomPro2Act=SiscomArgumentoOperacionAct("I_Gimnasio",pSAgsSiscom);
int lintNumRegistros=SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom);
LCamposSiscomPro2 *lLCSiscomPro2Med=SiscomArgumentoOperacionPrim("Medios",pSAgsSiscom);

SiscomMensajesLog(gPtrFleArchivoLog,"RegistraMedioComunicacion2");
for(;
     lLCSiscomPro2Med;
     lLCSiscomPro2Med=lLCSiscomPro2Med->SCP2PtrSig)
if(ObtenIdMedioComunicacion(lLCSiscomPro2Med,lchrArrIdMedio) &&
   ValidaMedioComunicacionNoVacio(lLCSiscomPro2Med))
{
	sprintf(lchrArrSQLInsercion,
		"insert into comunicacionpersona values(%s,%s,'%s','%s');",
		SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPersona"),
		lchrArrIdMedio,
		SiscomObtenDato(lLCSiscomPro2Med,"Dato"),
		SiscomObtenDato(lLCSiscomPro2Med,"Descripcion"));
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

}
void RegistraMedioComunicacion(SArgsSiscom *pSAgsSiscom)
{
char lchrArrIdMedio[12];
char lchrArrSQLInsercion[256];
LCamposSiscomPro2 *lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
		  *lLCSiscomPro2Act=SiscomArgumentoOperacionAct("I_Gimnasio",pSAgsSiscom);
int lintNumRegistros=SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom);

SiscomMensajesLog(gPtrFleArchivoLog,"RegistraMedioComunicacion");
if(ObtenIdMedioComunicacion(pSAgsSiscom->LCSiscomPro2Dat,lchrArrIdMedio))
{
	sprintf(lchrArrSQLInsercion,
		"insert into comunicacionpersona values(%s,%s,'%s','%s');",
		SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPersona"),
		lchrArrIdMedio,
		SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Dato"),
		SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Descripcion"));
	SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNumRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQLInsercion,
			"");

SiscomAsignaArgumentoOperacionAct("I_Gimnasio",lLCSiscomPro2Act,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("I_Gimnasio",lintNumRegistros,pSAgsSiscom);
}

}
int ObtenIdMedioComunicacion(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			      char *pchrPtrIdMedio)
{
char lchrArrCadena[256];
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNumRegRespuesta;
	sprintf(lchrArrCadena,
		"select *				\
		 from catmediocomunicacion		\
		 where medio='%s'",
		 SiscomObtenDato(pLCSiscomPro2Dat,"Medio"));

	SiscomConsultaBaseDatosSinDatosConexion(lchrArrCadena,
						gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
						gSSiscomConfiguracionSvr.intPtoAccesoDatos,
						&lLCSiscomPro2Reg,
						&lintNumRegRespuesta);
	if(lLCSiscomPro2Reg)
	 strcpy(pchrPtrIdMedio,SiscomObtenDato(lLCSiscomPro2Reg,"idmedio"));
	 else
	 SiscomMensajesLog(gPtrFleArchivoLog,
	 		   "ObtenIdMedioComunicacion:El Medio %s, no esta en catalogo",
			   SiscomObtenDato(pLCSiscomPro2Dat,"Medio"));

	return lLCSiscomPro2Reg ? 1 : 0;

}
int ValidaMedioComunicacionNoVacio(LCamposSiscomPro2 *pLCSiscomPro2)
{
	return	SiscomObtenDato(pLCSiscomPro2,"Medio")[0] &&
		SiscomObtenDato(pLCSiscomPro2,"Dato")[0] ;
}

void AnexaComunicacionPersona(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaArgumentoOperacionPrim("Medios",pSAgsSiscom->LCSiscomPro2Dat,pSAgsSiscom);
}
