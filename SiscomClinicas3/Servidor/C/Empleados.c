#include <Empleados.h>
#include <SiscomAplicaciones.h>
#include <ComunClinicas3.h>

#include <SQLEmpleados.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

SiscomOperaciones2 *OPEmpleadosRegistrados()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLEmpleadosRegistrados,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OPEmpleado()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomArgumentosPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomGeneraIdPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomValidaNombreVacio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomNormalizaPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomPersonaEnNormalizados,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersonaEnNormalizados,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomVerificaPassword,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomPasswordVacio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLUsuario,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLFirma,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLPersonaPerfil,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLAdicionales,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraEmpleado,lSOpOperaciones);
return lSOpOperaciones;

}


void RegistraEmpleado(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRespuesta;
SiscomMensajesLog2("RegistraAlumna");
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "SisSQLPersona",
				 &lLCSiscomPro2Reg,
				 &lintNRegRespuesta);
SiscomImprimeContenidoProtocolo2("",
				 pSAgsSiscom->LCSiscomPro2Dat);

SiscomImprimeContenidoProtocolo2("",
                                 SiscomArgumentoOperacionPrim("SisSQLPersona",
				 pSAgsSiscom));
SiscomMensajesLog2("RegistraAlumno:Termino");
}
