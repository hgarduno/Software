#ifndef __RNPEDIDOS_H__
#define __RNPEDIDOS_H__
#include <FuncionesComunes.h>
#define RN_Pedidos_IdClientePedidos			1
#define RN_Pedidos_FirmaVendedorPedidos			2
#define RN_Pedidos_ImporteTotalPedidos			3
#define RN_Pedidos_ProductoPedidos			4
#define RN_Pedidos_CantidadPedidos			5
#define RN_Pedidos_ImportePedidos			6
#define RN_Pedidos_TipoPrecioPedidos			7
#define RN_Pedidos_FechaEntrega				9
#define RN_Pedidos_ContactoCliente			10

const char *ObtenIdClientePedidos(char **);
const char *ObtenFirmaVendedorPedidos(char **);
const char *ObtenImporteTotalPedidos(char **);
const char *ObtenProductoPedidos(char **);
const char *ObtenCantidadPedidos(char **);
const char *ObtenImportePedidos(char **);
const char *ObtenTipoPrecioPedidos(char **);
const char *ObtenContactoClientePedidos(char **);
const char *ObtenFechaEntregaPedidos(char **);

StcLtaRegComSISCOM *OperacionesPedidos(int , const char *, StcLtaRegComSISCOM *, int *);
StcLtaRegComSISCOM *RegistraPedidos(int , const char *, StcLtaRegComSISCOM *, int *);
StcLtaRegComSISCOM *ConsultaPedidos(int , const char *, StcLtaRegComSISCOM *, int *);
StcLtaRegComSISCOM *ActualizaPedido(int , const char *, StcLtaRegComSISCOM *, int *);
StcLtaRegComSISCOM *ActualizaRegistraFechaEntregaPedido(int , const char *, StcLtaRegComSISCOM *, int *);
StcLtaRegComSISCOM *GeneraRespuestaPedidos(int *);


int EsConsultaPedidosSinAutorizarDelDia(char **,char *);
void PedidosSinAutorizarDelDia(int,
			       const char *,
			       const char *,
			       StcLtaRegComSISCOM **,
			       int *);
void RespuestaPedidosSinAutorizacionDelDia(int,
					   const char *,
					   int,
					   StcLtaRegComSISCOM *,
					   StcLtaRegComSISCOM **,
					   int *);

int EsConsultaPedidosDelVehiculo(char **,char *);
void PedidosDelVehiculo(int,
			       const char *,
			       const char *,
			       StcLtaRegComSISCOM **,
			       int *);
void RespuestaPedidosDelVehiculo(int,
					   const char *,
					   int,
					   StcLtaRegComSISCOM *,
					   StcLtaRegComSISCOM **,
					   int *);

int EsAsignacionDelVehiculo(char **,char *);
void AsignaVehiculoAlPedido(int,
			       const char *,
			       const char *,
			       StcLtaRegComSISCOM **,
			       int *);
void RespuestaAsignaVehiculoAlPedido(int,
					   const char *,
					   int,
					   StcLtaRegComSISCOM *,
					   StcLtaRegComSISCOM **,
					   int *);

int EsConsultaDetalleDelPedido(char **,char *);
void DetalleDelPedido(int,
			       const char *,
			       const char *,
			       StcLtaRegComSISCOM **,
			       int *);
void RespuestaDetalleDelPedido(int,
					   const char *,
					   int,
					   StcLtaRegComSISCOM *,
					   StcLtaRegComSISCOM **,
					   int *);
int EsActualizaFechaEntrega(char **,char *);
void ActualizaFechaEntrega(int,
			       const char *,
			       const char *,
			       StcLtaRegComSISCOM **,
			       int *);
void RespuestaFechaEntrega(int,
					   const char *,
					   int,
					   StcLtaRegComSISCOM *,
					   StcLtaRegComSISCOM **,
					   int *);
int EsActualizaEstadoPedido(char **,char *,StcLtaRegComSISCOM *,StcLtaRegComSISCOM **,int *);
void ActualizaEstadoPedido(int,
			   const char *,
			   const char *,
			   StcLtaRegComSISCOM *,
			   int ,
			   StcLtaRegComSISCOM **,
			   int *);
void RespuestaActualizaEstadoPedido(int,
				    const char *,
				    int,
				    StcLtaRegComSISCOM *,
				    StcLtaRegComSISCOM **,
				    int *);
					
int EsActualizaImportePedido(char **,char *,StcLtaRegComSISCOM *,StcLtaRegComSISCOM **,int *);
int EsActualizaFormaPago(char **,char *,StcLtaRegComSISCOM *,StcLtaRegComSISCOM **,int *);
#endif
