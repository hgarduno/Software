#include <Calificaciones.h>
#include <ActualizaCalificaciones.h>
#include <RegistraCalificacion.h>
#include <ServidorGeneral.h>

#include <stdlib.h>
void IniciaCalificacion(SArgsSiscom *pSAgsSiscom)
{

char *lchrPtrEdoConexion;
int lintSocket;
LCamposSiscomPro2 *lLCSiscomPro2Res=0;
int lintNRes;
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "InsertaCompetencia");
SiscomMensajesLog(gPtrFleArchivoLog,"IniciaCalificacion");
SiscomImprimeContenidoProtocolo(
		"",	
		gPtrFleArchivoLog,
		SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom));
/*
SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
			  gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
			  "Inserciones",
			  SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom),
			  SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
			  &lchrPtrEdoConexion,
			  &lintSocket);
*/

SiscomInformacionServidorConRespuesta(
			gSSiscomConfiguracionSvr.intPtoAccesoDatos,
			gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
			"Inserciones",
			SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom),
			SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
			&lchrPtrEdoConexion,
			&lintSocket,
			&lLCSiscomPro2Res,
			&lintNRes);
SiscomImprimeContenidoProtocolo2("",lLCSiscomPro2Res);
}
void ActualizaCalificacion(SArgsSiscom *pSAgsSiscom)
{
char *lchrPtrEdoConexion;
int lintSocket;
int lintNRegRespuesta;
LCamposSiscomPro2 *lLCSiscomPro2Res;
SiscomMensajesLog2("ActualizaCalificacion");
SiscomImprimeContenidoProtocolo2(
		"",	
		SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom));

SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
			  gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
			  "Inserciones",
			  SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom),
			  SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
			  &lchrPtrEdoConexion,
			  &lintSocket);
SiscomLeeInformacionRespuesta(lintSocket,
			      &lintNRegRespuesta,
			      &lLCSiscomPro2Res);
}
void ArgumentosCalificacion(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(3,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"I_Gimnasio",pSAgsSiscom);
}
SiscomOperaciones2 *OperacionesIniciaCalificacion()
{
SiscomOperaciones2 *lSOpPtrEntrenador=0;
lSOpPtrEntrenador=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);

SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(ArgumentosCalificacion,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(RegistraCalificacion,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(IniciaCalificacion,lSOpPtrEntrenador);

return  lSOpPtrEntrenador;

}
SiscomOperaciones2 *OperacionesActualizaEjecucion()
{
SiscomOperaciones2 *lSOpPtrEntrenador=0;
lSOpPtrEntrenador=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(ArgumentosCalificacion,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(SQLActualizaEjecucion,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(ActualizaCalificacion,lSOpPtrEntrenador);
return  lSOpPtrEntrenador;

}
SiscomOperaciones2 *OperacionesActualizaDificultad()
{
SiscomOperaciones2 *lSOpPtrEntrenador=0;
lSOpPtrEntrenador=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(ArgumentosCalificacion,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(SQLActualizaDificultad,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(ActualizaCalificacion,lSOpPtrEntrenador);
return  lSOpPtrEntrenador;

}
