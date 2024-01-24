#include <Pedidos.h>
#include <SQLPedidos.h>
#include <ComunSiscomTiendas4.h>

#include <stdlib.h>
SiscomOperaciones2 *ORegistraPedido()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosPedidos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraPedido,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraPedido,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OPedidoEntregado()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosPedidos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraPedidoEntregado,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraSeguimientoPedido,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraPedido,lSOpOperaciones);
return lSOpOperaciones;
}

void ArgumentosPedidos(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlPedido",pSAgsSiscom);
}
void RegistraPedido(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2SqlPedidoPrim=0,
		  *lLCSiscomPro2SqlPedidoAct=0;
int lintNRegistrosSqlPedido;
SiscomLog("");

SiscomObtenInformacionArgumento(
			"SqlPedido",
			pSAgsSiscom,
			&lLCSiscomPro2SqlPedidoPrim,
			&lLCSiscomPro2SqlPedidoAct,
			&lintNRegistrosSqlPedido);

SiscomEnviaServidorArgumento(pSAgsSiscom,"SqlPedido");
SiscomLog("Los datos de entrada .........");
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomLog("Actualizando............");
SiscomContenidoProtocolo(lLCSiscomPro2SqlPedidoPrim);
}
SiscomOperaciones2 *OPedidosCliente()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlPedidosCliente,lSOpOperaciones);
return lSOpOperaciones;
}


