#include <Pacientes.h>
#include <SiscomAplicaciones.h>
#include <ComunClinicas3.h>

#include <SQLEmpleados.h> 

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*
 *
 *
SiscomOperaciones2 *OPPacientesRegistrados()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLPacientesRegistrados,lSOpOperaciones);
return lSOpOperaciones;
}
*/

SiscomOperaciones2 *OPBuscaPersonasSimilares()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomArgumentosPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomGeneraIdPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomNormalizaPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomPersonasSimilares,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(PacientesSimilares,lSOpOperaciones);
return lSOpOperaciones;

}

SiscomOperaciones2 *OPPaciente()
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
SiscomAnexaOperacionAlArreglo2(SQLPersonaPerfil,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLAdicionales,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraPaciente,lSOpOperaciones);
return lSOpOperaciones;

}

SiscomOperaciones2 *OPActualizaPersonales()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomArgumentosPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomValidaNombreVacio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomNormalizaPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomActualizaPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomActualizaPersonaNormalizada,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraPaciente,lSOpOperaciones);
return lSOpOperaciones;

}
SiscomOperaciones2 *OPBuscaPersonas()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomArgumentosPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomNormalizaPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomBusquedaPersonas,lSOpOperaciones);
return lSOpOperaciones;

}

void RegistraPaciente(SArgsSiscom *pSAgsSiscom)
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
SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
		      1,
		      "Respuesta",
		      pSAgsSiscom->LCSiscomPro2Dat);

}
void PacientesSimilares(SArgsSiscom *pSAgsSiscom)
{
SiscomMensajesLog2("PacientesSimilares");


}
