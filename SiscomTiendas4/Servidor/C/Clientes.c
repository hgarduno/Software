#include <Clientes.h>
#include <SQLClientes.h>

#include <ComunSiscomTiendas4.h>
#include <SiscomAplicaciones.h> 
#include <string.h> 
#include <stdlib.h>


SiscomOperaciones2 *OPDireccionesCliente()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlDireccionesCliente,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OPClientesRegistrados()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLClientesRegistrados,lSOpOperaciones);
return lSOpOperaciones;
}


SiscomOperaciones2 *ORegistraClienteFisica()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomArgumentosPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SiscomGeneraIdPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomValidaNombreVacio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomNormalizaPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersonaEnNormalizados,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomPersonaEnNormalizados,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlRegistraTipoPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraClienteFisica,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraClientes,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *ORegistraPropietarioVehiculo()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomArgumentosPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SiscomNormalizaPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomPersonaEnNormalizados,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SiscomGeneraIdPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomValidaNombreVacio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersonaEnNormalizados,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraTipoPersonaPropVehiculo,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraClienteFisica,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraClientes,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *ORegistraResponsableVehiculo()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomArgumentosPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SiscomNormalizaPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomPersonaEnNormalizados,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SiscomGeneraIdPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomValidaNombreVacio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersonaEnNormalizados,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraTipoPersonaRespVehiculo,lSOpOperaciones);
/*
SiscomAnexaOperacionAlArreglo2(SqlRegistraClienteFisica,lSOpOperaciones);

*/
SiscomAnexaOperacionAlArreglo2(SqlRegistraCargoRespVehiculo,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraClientes,lSOpOperaciones);
return lSOpOperaciones;
}
void ArgumentosDirecciones2(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlDirecciones2",pSAgsSiscom);
}
SiscomOperaciones2 *ORegistraDireccion2()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosDirecciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlRegistraDirecciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraDirecciones2,lSOpOperaciones);
return lSOpOperaciones;
}
void RegistraDirecciones2(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaServidorArgumento(pSAgsSiscom,"SqlDirecciones2");
}
void RegistraClientes(SArgsSiscom *pSAgsSiscom)
{
SiscomLog("");
SiscomEnviaServidorArgumento(pSAgsSiscom,"SisSQLPersona");
SiscomLog("El Codigo de retorno:%d",pSAgsSiscom->intCodigoRetorno);
}
