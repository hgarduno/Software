#include <Jueces.h>

#include <Entrenadores.h>
#include <Gimnasios.h>
#include <RegistraJuez.h>
#include <RegistraPersona.h>
#include <RegistraMedioComunicacion.h>
#include <ServidorGeneral.h>
#include <stdlib.h>
void InsertaJuez(SArgsSiscom *pSAgsSiscom)
{

char *lchrPtrEdoConexion;
int lintSocket;

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

SiscomOperaciones2 *OperacionesJuez()
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
SiscomAnexaOperacionAlArreglo2(RegistraJuez,lSOpPtrEntrenador); 
SiscomAnexaOperacionAlArreglo2(InsertaJuez,lSOpPtrEntrenador);


return lSOpPtrEntrenador;
}
