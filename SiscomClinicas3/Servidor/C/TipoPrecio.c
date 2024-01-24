#include <TipoPrecio.h>
#include <SQLTipoPrecio.h>

#include <ComunClinicas3.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SiscomOperaciones2 *OPTipoPrecioRegistrados()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLTipoPrecioRegistrados,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OPTipoPrecio()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosTipoPrecio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(GeneraIdPrecio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLTipoPrecio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLAnexaTipoPrecioServicios,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLAnexaTipoPrecioServiciosMedico,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraTipoPrecio,lSOpOperaciones);
return lSOpOperaciones;

}

void GeneraIdPrecio(SArgsSiscom *pSAgsSiscom)
{

LCamposSiscomPro2 *lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Dat;
char lchrArrIdPrecio[12];
  SiscomObtenNumeroUnicoChar(lchrArrIdPrecio);
  SiscomAsignaDatoCampo2("IdPrecio",	
  			 lchrArrIdPrecio,
			 lLCSiscomPro2Dat);
}
void ArgumentosTipoPrecio(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"TipoPrecio",pSAgsSiscom);
}

void RegistraTipoPrecio(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRespuesta;
SiscomMensajesLog2("RegistraTipoPrecio");
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "TipoPrecio",
				 &lLCSiscomPro2Reg,
				 &lintNRegRespuesta);
SiscomImprimeContenidoProtocolo2("",
				 pSAgsSiscom->LCSiscomPro2Dat);

SiscomImprimeContenidoProtocolo2("",
                                 SiscomArgumentoOperacionPrim("TipoPrecio",
				 pSAgsSiscom));
SiscomMensajesLog2("RegistraTipoPrecio:Termino");
}
