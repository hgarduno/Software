#include <Clientes.h>
#include <SqlClientes.h>
#include <SqlEmpresas.h>
#include <SqlCorreos.h>
#include <SqlTelefonos.h>
#include <SiscomAplicaciones.h>
#include <ComunElectronica2.h>
#include <stdlib.h>
SiscomOperaciones2 *OpClientes()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlClientes,lSOpOperaciones2);
return lSOpOperaciones2;
}
 
SiscomOperaciones2 *OPRegistraCliente()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomArgumentosPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomGeneraIdPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomValidaNombreVacio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomNormalizaPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomPersonaEnNormalizados,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersonaEnNormalizados,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaDireccionCliente,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlActualizaRFC,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraTelefonoFisica,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraCorreoFisica,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraCliente,lSOpOperaciones);
return lSOpOperaciones;

}
/*
 *  Queretaro a 16 de octubre del 2015
 *  Falta integrar la funcionalidad para validar
 *  los registros similares, que ya se encuentran en 
 *  NOrmalizados etc 
 *  En el directorio SiscomPersonas.h y .c se empezo a 
 *  agregar las funciones
 *  Normalizar RFC
 *
 *
 *  Los clientes se deben registrar en la matriz ...
 */

SiscomOperaciones2 *OPRegistraClienteMoral()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*200);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
/*SiscomAnexaOperacionAlArreglo2(SiscomArgumentosPersonaMoral,lSOpOperaciones); */
SiscomAnexaOperacionAlArreglo2(SiscomGeneraIdPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraEmpresa,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaDireccionClienteMoral,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraTelefonoMoral,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraCorreoMoral,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraClienteMoral,lSOpOperaciones);
return lSOpOperaciones;

}

void RegistraCliente(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRespuesta;
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "SisSQLPersona",
				 &lLCSiscomPro2Reg,
				 &lintNRegRespuesta);
}


void RegistraClienteMoral(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRespuesta;
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "SisSQLPersona",
				 &lLCSiscomPro2Reg,
				 &lintNRegRespuesta);
/*
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomImprimeArgumento("SisSQLPersona",pSAgsSiscom); 
*/
}

