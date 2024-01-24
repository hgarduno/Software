#include <IMP_AdministradorPedidos.h>
#include <IMP_QControlFecha.h>

#include <zSiscomElectronica.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>
#include <zSiscomDesarrollo4.h>
#include <zOrdenVenta.h>
#include <zOrdenes.h>
#include <zOpsAdministradorPedidos.h>

QAdministradorPedidos *InstanciaAdministradorPedidos(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QAdministradorPedidos((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QAdministradorPedidos::QAdministradorPedidos(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
		QtAdministradorPedidos((zSiscomConexion *)gzSiscomConexion,
				       pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)
{

QtAdministradorPedidos::Iniciando();

}
QAdministradorPedidos::~QAdministradorPedidos()
{

}
void QAdministradorPedidos::SlotActualizaEstado()
{
 ActualizaEstado();
}
void QAdministradorPedidos::SlotConsultar()
{
  Consultando();
}
void QAdministradorPedidos::Consultando()
{
 Consulta();
 QtAdministradorPedidos::Ordenes(zOrdsRegistradas);
 QtAdministradorPedidos::MuestraOrdenes();
}
void QAdministradorPedidos::Consulta()
{
zSiscomElectronica lzSisElecOrdenes(zSisConexion,"OrdenesVendidas2");
zOrdsRegistradas=lzSisElecOrdenes.Ordenes(Condicion());

}
void QAdministradorPedidos::ActualizaEstado()
{
zOpsAdministradorPedidos lzOpsAdmPedidos(zSisConexion,"ActualizaEstadoPedidoCliente");
lzOpsAdmPedidos.ActualizaEstadoPedido(Orden()->IdVenta(),IdNuevoEstado());
}
void QAdministradorPedidos::SlotImprimir()
{
Orden()->IdExpendio(*(chrPtrArgumentos+0));
zSiscomElectronica lzSisElectronica(zSisConexion,"ImprimeTicketVenta4");
lzSisElectronica.ImprimeTicketVenta(Orden());
}
