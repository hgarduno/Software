#include <AsignaAsesor.h>
#include <ComunSiscomTiendas4.h>
#include <SQLAsignaAsesor.h>
#include <SQLVentas.h>
#include <stdlib.h>
SiscomOperaciones2 *OAsignaAsesor()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosAsesores,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlClientePorNumeroTelefonico,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlObtenDetalleVenta,lSOpOperaciones);
/*SiscomAnexaOperacionAlArreglo2(EnviaDatosAlAsesor,lSOpOperaciones);*/
SiscomAnexaOperacionAlArreglo2(DetalleUltimoPedido,lSOpOperaciones);

return lSOpOperaciones;
}
/*
 *
 * En este punto, es importante poder enviar la informacion del detalle
 * del pedido, es decir los productos que se compraron, para lo que 
 * se procedera de la siguiente forma, se realizaran ambas consultas,
 * primero se envia la informacion del pedido, datos del cliente, etc
 * en el segundo envio la informacion del detalle del pedido.
 * 
 */ 
void EnviaDatosAlAsesor(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2SqlClientePrim=0,
		  *lLCSiscomPro2SqlClienteAct=0;
int lintNRegistrosSql;
char *lchrPtrEdoConexion;
int lintSocket;
SiscomLog("");
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);

SiscomObtenInformacionArgumento("SQLCliente",
				pSAgsSiscom,
				&lLCSiscomPro2SqlClientePrim,
				&lLCSiscomPro2SqlClienteAct,
				&lintNRegistrosSql);
SiscomContenidoProtocolo(lLCSiscomPro2SqlClientePrim);

SiscomInformacionServidor(
	atoi(SiscomObtenDato(lLCSiscomPro2SqlClientePrim,"puerto")),
	SiscomObtenDato(lLCSiscomPro2SqlClientePrim,"direccion"),
	"AnalizaMensaje",
	lintNRegistrosSql,
	lLCSiscomPro2SqlClientePrim,
	&lchrPtrEdoConexion,
	&pSAgsSiscom->intSocketAccesoDatos);


}
void SiscomSumaListas2(LCamposSiscomPro2 *pLCSiscomPro2Uno,
		       LCamposSiscomPro2 *pLCSiscomPro2Dos)
{
LCamposSiscomPro2 *lLCSiscomPro2Ultimo;
LCamposSiscomPro2 *lLCSiscomPro2UltimoActual=0;
int lintNRegistros=0;
SiscomLog("");
for(;
     pLCSiscomPro2Uno;
     pLCSiscomPro2Uno=pLCSiscomPro2Uno->SCP2PtrSig)
{
    lLCSiscomPro2Ultimo=pLCSiscomPro2Uno;
}
lLCSiscomPro2UltimoActual=lLCSiscomPro2Ultimo;
SiscomAnexaRegistroPro2(&lLCSiscomPro2Ultimo,
			&lLCSiscomPro2UltimoActual,
			&lintNRegistros,
			"Fin,Registro",
			"",
			"");
lLCSiscomPro2UltimoActual->SCP2PtrSig=pLCSiscomPro2Dos;

}
		   
void DetalleUltimoPedido(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2SqlDetallePrim=0,
		  *lLCSiscomPro2SqlDetalleAct=0;
LCamposSiscomPro2 *lLCSiscomPro2SqlPedidoPrim=0,
		  *lLCSiscomPro2SqlPedidoAct=0;
LCamposSiscomPro2 *lLCSiscomPro2SqlClienteNuevoPrim=0,
		  *lLCSiscomPro2SqlClienteNuevoAct=0;
int lintNRegistrosDetalle;
int lintNRegistrosPedido;
int lintNRegistrosSql;
int lintNClienteNuevoSql;
char *lchrPtrEdoConexion;
SiscomObtenInformacionArgumento("SqlDetallePedido",
				pSAgsSiscom,
				&lLCSiscomPro2SqlDetallePrim,
				&lLCSiscomPro2SqlDetalleAct,
				&lintNRegistrosDetalle);

SiscomObtenInformacionArgumento("SQLCliente",
				pSAgsSiscom,
				&lLCSiscomPro2SqlPedidoPrim,
				&lLCSiscomPro2SqlPedidoAct,
				&lintNRegistrosPedido);
if(lLCSiscomPro2SqlPedidoPrim &&
   lLCSiscomPro2SqlDetallePrim)
{
SiscomSumaListas2(lLCSiscomPro2SqlPedidoPrim,lLCSiscomPro2SqlDetallePrim);
SiscomContenidoProtocolo(lLCSiscomPro2SqlPedidoPrim);
lintNRegistrosSql=lintNRegistrosDetalle+lintNRegistrosPedido+1;
SiscomInformacionServidor(
	atoi(SiscomObtenDato(lLCSiscomPro2SqlPedidoPrim,"puerto")),
	SiscomObtenDato(lLCSiscomPro2SqlPedidoPrim,"direccion"),
	"ClienteRegistrado",
	lintNRegistrosSql,
	lLCSiscomPro2SqlPedidoPrim,
	&lchrPtrEdoConexion,
	&pSAgsSiscom->intSocketAccesoDatos);
}
else
{
SiscomObtenInformacionArgumento("SqlClienteNuevo",
				pSAgsSiscom,
				&lLCSiscomPro2SqlClienteNuevoPrim,
				&lLCSiscomPro2SqlClienteNuevoAct,
				&lintNClienteNuevoSql);
SiscomInformacionServidor(
	atoi(SiscomObtenDato(lLCSiscomPro2SqlClienteNuevoPrim,"puerto")),
	SiscomObtenDato(lLCSiscomPro2SqlClienteNuevoPrim,"direccion"),
	"ClienteNuevo",
	lintNClienteNuevoSql,
	lLCSiscomPro2SqlClienteNuevoPrim,
	&lchrPtrEdoConexion,
	&pSAgsSiscom->intSocketAccesoDatos);


}

}
void ArgumentosAsesores(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(3,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SQLCliente",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlDetallePedido",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"SqlClienteNuevo",pSAgsSiscom);
}
