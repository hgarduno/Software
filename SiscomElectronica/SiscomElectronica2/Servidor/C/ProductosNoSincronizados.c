#include <ProductosNoSincronizados.h>
#include <ComunElectronica2.h>
#include <SqlProductosNoSincronizados.h>
SiscomOperaciones2 *OPProductosNoSincronizados()
{

SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(200,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOpSubRegistros,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendio3,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosSincronizacionProductos,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlProductosNoSincronizados,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(EnviaProductosNoSincronizados,lSOpOperaciones2);
return lSOpOperaciones2;
}


SiscomOperaciones2 *OpEnviaSincronizacionProductos()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOpSubRegistros,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendio3,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosSincronizacionProductos,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlProductosParaSincronizar,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlExpendiosASincronizar,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SincronizandoProductos,lSOpOperaciones2);
return lSOpOperaciones2;
}
void EnviaProductosNoSincronizados(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaArgumentoCliente("SqlProductosASincronizar",pSAgsSiscom);
}
void SincronizandoProductos(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Productos,
		  *lLCSiscomPro2Expendios;
SiscomLog("Sincronizando los productos");
lLCSiscomPro2Productos=SiscomArgumentoOperacionPrim("SqlProductosASincronizar",pSAgsSiscom);
lLCSiscomPro2Expendios=SiscomArgumentoOperacionPrim("SqlExpendiosASincronizar",pSAgsSiscom);
/*
SiscomImprimeArgumento("SqlProductosASincronizar",pSAgsSiscom);
SiscomImprimeArgumento("SqlExpendiosASincronizar",pSAgsSiscom);
*/
RegistrandoProductos(lLCSiscomPro2Productos,lLCSiscomPro2Expendios,0);
}
void ArgumentosSincronizacionProductos(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(3,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlSincronizacion",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlProductosASincronizar",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"SqlExpendiosASincronizar",pSAgsSiscom);
}
