#include <ClavesProveedores.h>
#include <SqlClavesProveedores.h>
#include <ComunElectronica2.h>
#include <stdlib.h>
SiscomOperaciones2 *OpClavesProveedores()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*200);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(ArgumentosClavesProveedores,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlClavesProveedores,lSOpOperaciones); 
return lSOpOperaciones;
}

SiscomOperaciones2 *OpActualizaClaveProveedor()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*220);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(ArgumentosClavesProveedores,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlInsertaClaveProveedor,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlActualizaClaveProveedor,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(ActualizaClaveProveedor,lSOpOperaciones); 
return lSOpOperaciones;
}

void ArgumentosClavesProveedores(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlClavesProveedores",pSAgsSiscom);
}

void ActualizaClaveProveedor(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaServidorArgumento(pSAgsSiscom,"SqlClavesProveedores");
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomImprimeArgumento("SqlClavesProveedores",pSAgsSiscom);
}


