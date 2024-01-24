#include <Compitiendo.h>
#include <RegistraCompetidor.h>
#include <ServidorGeneral.h>
#include <stdlib.h>
#include <string.h>
void InsertaGimnastaCompitiendo(SArgsSiscom *pSAgsSiscom)
{
char *lchrPtrEdoConexion;
int lintSocket;
SiscomMensajesLog(gPtrFleArchivoLog,
		  "Los Resultados");
SiscomImprimeContenidoProtocolo("",
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
void AsignaArgumentosCompitiendo(SArgsSiscom *pSAgsSiscom)
{
SiscomMensajesLog(gPtrFleArchivoLog,
		  "AsignaArgumentosCompitiendo");
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"I_Gimnasio",pSAgsSiscom);
SiscomAsignaArgumentoOperacionAct("I_Gimnasio",0,pSAgsSiscom);
SiscomAsignaArgumentoOperacionPrim("I_Gimnasio",0,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("I_Gimnasio",0,pSAgsSiscom);
}
SiscomOperaciones2 *OperacionesCompitiendo()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;

lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(AsignaArgumentosCompitiendo,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(RegistraCompetidor,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(IniciaCalificaciones,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(InsertaGimnastaCompitiendo,lSOpPtrGimnasio);


return lSOpPtrGimnasio;
}
SiscomOperaciones2 *OperacionesActDatCompGimnasta()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;

lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(AsignaArgumentosCompitiendo,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(ActualizaCompetidor,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(InsertaGimnastaCompitiendo,lSOpPtrGimnasio);


return lSOpPtrGimnasio;
}
