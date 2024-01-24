#include <Precios.h>
#include <ComunClinicas3.h>
#include <SQLPrecios.h>

#include <string.h>
#include <stdlib.h>

SiscomOperaciones2 *OPPreciosServicioMedico()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLConsultaPreciosServicioMedico,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OPPreciosServicio()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLConsultaPreciosServicio,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OPActualizaPrecioServicioGeneral()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosPreciosClinicas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLActualizaPrecioServicioGeneral,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraPrecioClinicas,lSOpOperaciones);
return lSOpOperaciones;
}


SiscomOperaciones2 *OPActualizaPrecioServicioMedico()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosPreciosClinicas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLActualizaPrecioServicioMedico,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraPrecioClinicas,lSOpOperaciones);
return lSOpOperaciones;
}
void ArgumentosPreciosClinicas(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SQLPrecios",pSAgsSiscom);
}
void RegistraPrecioClinicas(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRespuesta;
SiscomMensajesLog2("RegistraPrecioClinicass");
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "SQLPrecios",
				 &lLCSiscomPro2Reg,
				 &lintNRegRespuesta);
SiscomImprimeContenidoProtocolo2("",
				 pSAgsSiscom->LCSiscomPro2Dat);

SiscomImprimeContenidoProtocolo2("",
                                 SiscomArgumentoOperacionPrim("SQLPrecios",
				 pSAgsSiscom));
SiscomMensajesLog2("RegistraAlumno:Termino");
SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
		      1,
		      "Respuesta",
		      pSAgsSiscom->LCSiscomPro2Dat);

}
