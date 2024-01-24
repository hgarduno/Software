#include <Gimnastas.h>
#include <Gimnasios.h>
#include <Entrenadores.h>
#include <RegistraPersona.h>
#include <RegistraDireccion.h>
#include <RegistraMedioComunicacion.h>
#include <RegistraGimnasio.h>
#include <RegistraGimnasta.h>
#include <ActualizaGimnasta.h>
#include <ServidorGeneral.h>
#include <stdlib.h>
void InsertaGimnasta(SArgsSiscom *pSAgsSiscom)
{

char *lchrPtrEdoConexion;
int lintSocket;
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "InsertaGimnasta");

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

SiscomOperaciones2 *GeneraOperacionesGimnasta()
{

SiscomOperaciones2 *lSOpPtrEntrenador=0;
SiscomLog("");
lSOpPtrEntrenador=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(ArmaEnvioErrores,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(AsignaArgumentosEntrenador,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(ObtenInformacionConSubRegistros,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(GeneraIdentificadores,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(NormalizaContacto,lSOpPtrEntrenador); 
SiscomAnexaOperacionAlArreglo2(RegistraPersona,lSOpPtrEntrenador); 
SiscomAnexaOperacionAlArreglo2(RegistraMedioComunicacion2,lSOpPtrEntrenador); 
SiscomAnexaOperacionAlArreglo2(RegistraGimnasta,lSOpPtrEntrenador); 
SiscomAnexaOperacionAlArreglo2(InsertaGimnasta,lSOpPtrEntrenador);
return  lSOpPtrEntrenador;
}

SiscomOperaciones2 *OperacionesActualizaGimnasta()
{
SiscomOperaciones2 *lSOpPtrEntrenador=0;
lSOpPtrEntrenador=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);

SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(AsignaArgumentosEntrenador,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(NormalizaContacto,lSOpPtrEntrenador); 
SiscomAnexaOperacionAlArreglo2(SQLActualizaNombre,lSOpPtrEntrenador); 
SiscomAnexaOperacionAlArreglo2(SQLActualizaEdad,lSOpPtrEntrenador); 
SiscomAnexaOperacionAlArreglo2(SQLActualizaNombreNormalizado,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(InsertaGimnasta,lSOpPtrEntrenador);
return  lSOpPtrEntrenador;
}

SiscomOperaciones2 *AnexaComunicacionGimnasta()
{
SiscomOperaciones2 *lSOpPtrEntrenador=0;
lSOpPtrEntrenador=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);

SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(AsignaArgumentosEntrenador,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(AnexaComunicacionPersona,lSOpPtrEntrenador);
SiscomAnexaOperacionAlArreglo2(RegistraMedioComunicacion2,lSOpPtrEntrenador); 
SiscomAnexaOperacionAlArreglo2(InsertaGimnasta,lSOpPtrEntrenador);

return  lSOpPtrEntrenador;
}

