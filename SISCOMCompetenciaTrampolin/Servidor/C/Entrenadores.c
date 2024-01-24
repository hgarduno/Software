#include <Entrenadores.h>
#include <Gimnasios.h>
#include <RegistraPersona.h>
#include <RegistraMedioComunicacion.h>
#include <ServidorGeneral.h>
#include <stdlib.h>
#include <string.h>

void InsertaEntrenador(SArgsSiscom *pSAgsSiscom)
{
char *lchrPtrEdoConexion;
int lintSocket;
SiscomMensajesLog(gPtrFleArchivoLog,
		  "InsertaEntrenador");

SiscomImprimeContenidoProtocolo("",
				gPtrFleArchivoLog,
				SiscomArgumentoOperacionPrim("General",pSAgsSiscom));

SiscomImprimeContenidoProtocolo("",
				gPtrFleArchivoLog,
				SiscomArgumentoOperacionPrim("Medios",pSAgsSiscom));
SiscomImprimeContenidoProtocolo("",
				gPtrFleArchivoLog,
				SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom));
SiscomMensajesLog(gPtrFleArchivoLog,
		  "Se enviaran %d Registros",
		  SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom));

SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
			  gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
			  "Inserciones",
			  SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom),
			  SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
			  &lchrPtrEdoConexion,
			  &lintSocket);
}
void AsignaArgumentosEntrenador(SArgsSiscom *pSAgsSiscom)
{
SiscomMensajesLog(gPtrFleArchivoLog,"AsignaArgumentosEntrenador");
SiscomAsignaMemoriaArgumentosOperaciones(5,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"C_Normalizado",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"General",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"Medios",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(3,"I_Gimnasio",pSAgsSiscom);
SiscomImprimeContenidoProtocolo("",
                                gPtrFleArchivoLog,
				pSAgsSiscom->LCSiscomPro2Dat);

}
SiscomOperaciones2 *GeneraOperacionesEntrenador()
{
SiscomOperaciones2 *lSOpPtrEntrenador;


lSOpPtrEntrenador=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*10);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(AsignaArgumentosEntrenador,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(ObtenInformacionConSubRegistros,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(GeneraIdentificadores,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(NormalizaContacto,lSOpPtrEntrenador); 
SiscomAnexaOperacionAlArreglo2(RegistraPersona,lSOpPtrEntrenador); 
SiscomAnexaOperacionAlArreglo2(RegistraMedioComunicacion2,lSOpPtrEntrenador); 
SiscomAnexaOperacionAlArreglo2(RegistraEntrenador,lSOpPtrEntrenador); 
SiscomAnexaOperacionAlArreglo2(InsertaEntrenador,lSOpPtrEntrenador);


return lSOpPtrEntrenador;

}
void ObtenInformacionConSubRegistros(SArgsSiscom *pSAgsSiscom)
{
StcSisFormaRegistro lSSFormaReg={ "IdGimnasio",
				 {
				    {"IdMedio","MEDCOM"},
				    {0,0}
				 }
				  
				};
LCamposSiscomPro2ConSubReg lLCSiscomPro2CSR;
	SiscomLeeConSubRegistros(pSAgsSiscom->LCSiscomPro2Dat,
				 &lSSFormaReg,
				 &lLCSiscomPro2CSR);
	SiscomAsignaArgumentoOperacionPrim(
		"General",
		lLCSiscomPro2CSR.LCSiscomPro2Prim,
		pSAgsSiscom);
	SiscomAsignaArgumentoOperacionPrim(
		"Medios",
		lLCSiscomPro2CSR.LCSiscomSubReg[0].LCSiscomPro2Prim,
		pSAgsSiscom);

}
void GeneraIdentificadores(SArgsSiscom *pSAgsSiscom)
{
char lchrArrIdPersona[12];
	SiscomObtenNumeroUnicoChar(lchrArrIdPersona);
	SiscomAsignaDatoCampo2("IdPersona",lchrArrIdPersona,pSAgsSiscom->LCSiscomPro2Dat);
}

void RegistraEntrenador(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[256];
LCamposSiscomPro2 *lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
		  *lLCSiscomPro2Act=SiscomArgumentoOperacionAct("I_Gimnasio",pSAgsSiscom);
int lintNumRegistros=SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom);
	sprintf(lchrArrSQL,
		"insert into entrenadores values(%s,%s);",
		SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPersona"),
		SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdGimnasio"));
	SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
				&lLCSiscomPro2Act,
				&lintNumRegistros,
				"ComandoSQL,EdoRegistro",
				lchrArrSQL,
				"");

SiscomAsignaArgumentoOperacionAct("I_Gimnasio",lLCSiscomPro2Act,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("I_Gimnasio",lintNumRegistros,pSAgsSiscom);
}
