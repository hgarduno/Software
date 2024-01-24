#include <SiscomDirecciones.h>
#include <SQLDirecciones.h>
#include <ServidorGeneral.h>

#include <stdlib.h>
#include <string.h>
SiscomOperaciones2 *OPSiscomAplicacionesDirecciones()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLSiscomDireccionesReg,lSOpOperaciones);
return lSOpOperaciones;

}
void SiscomComunicacionAD(SArgsSiscom *pSAgsSiscom)
{
pSAgsSiscom->intPtoComAD=gSSiscomConfiguracionSvr.intPtoAccesoDatos;
strcpy(pSAgsSiscom->chrArrDirIpAD,
       gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos);
}


SiscomOperaciones2 *OPSiscomAplicacionesRegistraDireccion()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosDireccion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLSiscomRegistraDireccion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraDireccion,lSOpOperaciones);
return lSOpOperaciones;
}
void ArgumentosDireccion(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SQLDireccion",pSAgsSiscom);
}

void RegistraDireccion(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRespuesta;
SiscomMensajesLog2("RegistraDireccion");
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "SQLDireccion",
				 &lLCSiscomPro2Reg,
				 &lintNRegRespuesta);
SiscomImprimeContenidoProtocolo2("",
				 pSAgsSiscom->LCSiscomPro2Dat);

SiscomImprimeContenidoProtocolo2("",
                                 SiscomArgumentoOperacionPrim("SQLDireccion",
				 pSAgsSiscom));
SiscomMensajesLog2("RegistraAlumno:Termino");
SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
		      1,
		      "Respuesta",
		      pSAgsSiscom->LCSiscomPro2Dat);

}
