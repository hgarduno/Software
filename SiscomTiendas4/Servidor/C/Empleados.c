#include <Empleados.h>
#include <ComunSiscomTiendas4.h>
#include <stdlib.h>

#include <SiscomAplicaciones.h>

SiscomOperaciones2 *OPRegistraEmpleado()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomArgumentosPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomGeneraIdPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomValidaNombreVacio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomNormalizaPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomPersonaEnNormalizados,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomPasswordVacio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomVerificaPassword,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomFirmaYaRegistrada,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersonaEnNormalizados,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraUsuario,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraFirma,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraEmpleado,lSOpOperaciones);
return lSOpOperaciones;

}

void RegistraEmpleado(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg;
int lintNRegRespuesta;
SiscomEjecutaRegistroInformacion(
		pSAgsSiscom,
		"SisSQLPersona",
		&lLCSiscomPro2Reg,
		&lintNRegRespuesta);

}
