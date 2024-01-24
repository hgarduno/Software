#include <Servicios.h>
#include <ComunClinicas3.h>
#include <SQLServicios.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

SiscomOperaciones2 *OPServiciosMedicoRegistrados()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLServiciosMedicoRegistrados,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OPServiciosRegistrados()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLServiciosRegistrados,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OPServicio()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosServicio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(GeneraIdServicio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLServicio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLAnexaPreciosServicio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraServicio,lSOpOperaciones);
return lSOpOperaciones;

}
SiscomOperaciones2 *OPServiciosMedico()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosServicio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(GeneraIdServicio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLServicioMedico,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLAnexaPreciosServicioMedico,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraServicio,lSOpOperaciones);
return lSOpOperaciones;

}

SiscomOperaciones2 *OPPerfilServicioMedico()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosServicio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLPerfilServicioMedico,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraServicio,lSOpOperaciones);
return lSOpOperaciones;

}

void GeneraIdServicio(SArgsSiscom *pSAgsSiscom)
{

LCamposSiscomPro2 *lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Dat;
char lchrArrIdServicio[12];
  SiscomObtenNumeroUnicoChar(lchrArrIdServicio);
  SiscomAsignaDatoCampo2("IdServicio",	
  			 lchrArrIdServicio,
			 lLCSiscomPro2Dat);
}
void ArgumentosServicio(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"Servicios",pSAgsSiscom);
}

void RegistraServicio(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRespuesta;
SiscomMensajesLog2("RegistraAlumna");
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "Servicios",
				 &lLCSiscomPro2Reg,
				 &lintNRegRespuesta);
SiscomImprimeContenidoProtocolo2("",
				 pSAgsSiscom->LCSiscomPro2Dat);

SiscomImprimeContenidoProtocolo2("",
                                 SiscomArgumentoOperacionPrim("Servicios",
				 pSAgsSiscom));
SiscomMensajesLog2("RegistraAlumno:Termino");
}
