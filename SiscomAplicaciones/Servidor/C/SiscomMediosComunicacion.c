#include <SiscomMediosComunicacion.h>
#include <SQLMediosComunicacion.h>
#include <ServidorGeneral.h>
#include <SiscomDirecciones.h>

#include <stdlib.h>
#include <string.h>
SiscomOperaciones2 *OPSiscomAplicacionesMediosComunicacion()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLSiscomMediosComunicacionReg,lSOpOperaciones);
return lSOpOperaciones;

}

SiscomOperaciones2 *OPSiscomAplicacionesRegistraMedioComunicacion()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosMedioComunicacion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLSiscomRegistraMedioComunicacion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraMedioComunicacion,lSOpOperaciones);
return lSOpOperaciones;
}
void ArgumentosMedioComunicacion(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SQLMedioComunicacion",pSAgsSiscom);
}

void RegistraMedioComunicacion(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRespuesta;
SiscomLog("RegistraMedioComunicacion");
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "SQLMedioComunicacion",
				 &lLCSiscomPro2Reg,
				 &lintNRegRespuesta);
SiscomImprimeContenidoProtocolo2("",
				 pSAgsSiscom->LCSiscomPro2Dat);

SiscomImprimeContenidoProtocolo2(
	"",
        SiscomArgumentoOperacionPrim("SQLMedioComunicacion",pSAgsSiscom));

SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
		      1,
		      "Respuesta",
		      pSAgsSiscom->LCSiscomPro2Dat);

}
