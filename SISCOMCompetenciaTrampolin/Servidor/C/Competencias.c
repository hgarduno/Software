#include <Competencias.h>
#include <RegistraCompetencia.h>
#include <ServidorGeneral.h>
#include <stdlib.h>
/*
 * Se tiene considerado integrar al proceso de registro 
 * de la competencia la informacion referente a los 
 * contactos y sus medios de comunicacion 
 * con los cuales se podra pedir informacion 
 * de la competencia, para esta fase solo es para registrar 
 * la competencia
 *
 */


void InsertaCompetencia(SArgsSiscom *pSAgsSiscom)
{
char *lchrPtrEdoConexion;
int lintSocket;
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "InsertaCompetencia");
SiscomImprimeContenidoProtocolo(
		"",	
		gPtrFleArchivoLog,
		SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom));

SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
			  gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
			  "Inserciones",
			  SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom),
			  SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
			  &lchrPtrEdoConexion,
			  &lintSocket);
}
void ColocaIdentificador(SArgsSiscom *pSAgsSiscom)
{
char lchrArrIdCompetencia[12];
	SiscomObtenNumeroUnicoChar(lchrArrIdCompetencia);
	SiscomAsignaDatoCampo2(
			"IdCompetencia",
			lchrArrIdCompetencia,
			pSAgsSiscom->LCSiscomPro2Dat);

	SiscomImprimeContenidoProtocolo(
			"",
			gPtrFleArchivoLog,
			pSAgsSiscom->LCSiscomPro2Dat);
					
}
void AsignaArgumentosCompetencia(SArgsSiscom *pSAgsSiscom)
{
SiscomMensajesLog(gPtrFleArchivoLog,"AsignaArgumentosCompetencia");
SiscomAsignaMemoriaArgumentosOperaciones(5,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"C_Normalizado",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"General",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"Medios",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(3,"I_Gimnasio",pSAgsSiscom);
}
SiscomOperaciones2 *OperacionesCompetencia()
{
SiscomOperaciones2 *lSOpPtrEntrenador=0;
lSOpPtrEntrenador=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*10);

SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(ColocaIdentificador,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(AsignaArgumentosCompetencia,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(RegistraCompetencia,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(InsertaCompetencia,lSOpPtrEntrenador);

return  lSOpPtrEntrenador;

}
