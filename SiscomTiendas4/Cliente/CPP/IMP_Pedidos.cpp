#include <IMP_Pedidos.h>
#include <IMP_InformacionPedido.h>
#include<SISCOMComunicaciones++.h>
#include <QCtrlCotizas.h>
#include <QSisDirecciones.h>
#include <CQSisProdCotiza.h>
#include <CQSisProductos.h>
#include <CQSisObjetosTiendas4.h>
#include <CQSisClientes.h>
#include <CQSisVentas.h>
#include <SisPersonas.h>
QPedidos *InstanciaPedidos(void *pSisDatCom,
			   char **pchrPtrArgumentos,
			   void *pQWParent,
			   const char *pchrPtrName,
			   int pintWFlags)
{

	return new QPedidos((SiscomDatCom *)pSisDatCom,
			    pchrPtrArgumentos,
			    (QWidget *)pQWParent,
			    pchrPtrName,
			    pintWFlags);
}
QPedidos::QPedidos(SiscomDatCom *pSisDatCom, 
		   char **pchrPtrArgumentos, 
		   SiscomRegistrosPro2 *pSRegistrosPro2,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Pedidos(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				SRegistrosPro2(pSRegistrosPro2)
{
ConectaSlots();
IniciaVariablesPedidoAnterior();
show();
}
QPedidos::QPedidos(SiscomDatCom *pSisDatCom, 
		   char **pchrPtrArgumentos, 
		   QWidget *pQWParent,       
		   const char *pchrPtrName,
		   WFlags pWFlags):	      
				Pedidos(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				SRegistrosPro2(0)
{
IniciaVariablesPedidoNuevo();
ConectaSlots();
}
QPedidos::~QPedidos()
{

}

void QPedidos::ConectaSlots()
{
connect(QCCotizando,
	SIGNAL(SignalCotizacion(CQSisCliente *,
	                        CQSisFormaPago *,
				CQSisPrecio *,
				CQSisProducto *,
				CQSisProdCotiza *,
				CQSisContacto *)),
	SLOT(SlotCotizando(CQSisCliente *,
			   CQSisFormaPago *,
			   CQSisPrecio *,
			   CQSisProducto *,
			   CQSisProdCotiza *,
			   CQSisContacto *)));
connect(QCCotizando,
	SIGNAL(SignalClienteFisica(CQSisCliente *)),
	SLOT(SlotClienteFisica(CQSisCliente *)));
connect(QPBAnexar,
	SIGNAL(clicked()),
	SLOT(SlotAnexar()));
connect(QPBRegistrar,
	SIGNAL(clicked()),
	SLOT(SlotRegistrar()));


}
void QPedidos::SlotClienteFisica(CQSisCliente *pCQSCliente)
{
if(pCQSCliente)
{
SisPersona *lSPCliente=pCQSCliente->Persona();
QSDirecciones->IdPersona((*lSPCliente)["IdPersona"]);	
QSDirecciones->DireccionesPersona();
CQSCliente=pCQSCliente;
}
}
void QPedidos::SlotRegistrar()
{
RegistraVenta();
RegistraPedido();
}
void QPedidos::SlotAnexar()
{
CQSLProdCotizar << CQSPCotizado;
CotizandoPedido();
QCCotizando->setFocus();
}
void QPedidos::SlotCotizando(CQSisCliente *pCQSCliente,
			     CQSisFormaPago *,
			     CQSisPrecio *,
			     CQSisProducto *,
			     CQSisProdCotiza *pCQSPCotiza,
			     CQSisContacto *)
{
SiscomPasaFocoControl(QPBAnexar);
CQSPCotizado=pCQSPCotiza;
CQSPCotizado->SiscomActualizaCampo("EdoVenta","0");
}
void QPedidos::CotizandoPedido()
{
	CotizaPedido();
	MuestraPedido();
}
void QPedidos::CotizaPedido()
{
CQSisOpCotiza lCQSOCotiza(SisDatCom);
lCQSOCotiza.CotizaProductos(&CQSLProdCotizar);
}
void QPedidos::MuestraPedido()
{
int lintContador;
CQSisProdCotiza *lCQSPCotiza;
CQSisProducto *lCQSProducto;
QTProductos->setNumRows(CQSLProdCotizar.count());
for(lintContador=0,
    lCQSPCotiza=CQSLProdCotizar.first();
    lCQSPCotiza;
    lCQSPCotiza=CQSLProdCotizar.next(),
    lintContador++)
{
lCQSProducto=lCQSPCotiza->Producto();
SiscomAnexarRegistroALaTabla(lintContador,
			     QTProductos,
			     QStringList() 			<<
			     (*lCQSProducto)["Dsc"]		<<
			     (*lCQSPCotiza)["Cantidad"]		<<
			     (*lCQSPCotiza)["Precio"]		<<
			     (*lCQSPCotiza)["Total"]);
}

SiscomAjustaColumnas(QTProductos);
SiscomAjustaFilas(QTProductos);
}
void QPedidos::IniciaVariablesPedidoAnterior()
{
QCCotizando->PonServidor(SisDatCom);
QCCotizando->IniciaControl();
QSDirecciones->Servidor(SisDatCom);
QSDirecciones->SistemaConsulta("ConsultaTiendas4");
QSDirecciones->IdPersona((*SRegistrosPro2)["idpersona"]);
QSDirecciones->IniciaControl();
QSDirecciones->DireccionesPersona();
QLEFecha->setText((*SRegistrosPro2)["pedidofechaentrega"]);
QTEComentario->setText((*SRegistrosPro2)["comentario"]);
QCCotizando->ConElCliente((*SRegistrosPro2)["idpersona"]);
++(*SRegistrosPro2);
++(*SRegistrosPro2);
ObjetosTiendas4::ProdsCotiza(SRegistrosPro2,&CQSLProdCPedidoA);
MuestraPedidoAnterior();
}
void QPedidos::IniciaVariablesPedidoNuevo()
{
QCCotizando->PonServidor(SisDatCom);
QCCotizando->IniciaControl();
QSDirecciones->Servidor(SisDatCom);
QSDirecciones->SistemaConsulta("ConsultaTiendas4");
QSDirecciones->IniciaControl();
}

void QPedidos::MuestraPedidoAnterior()
{
CQSisProdCotiza *lCQSPCotiza;
CQSisProducto *lCQSProducto;
int lintContador;
QTPedidoAnterior->setNumRows(CQSLProdCPedidoA.count());
for(lintContador=0,
    lCQSPCotiza=CQSLProdCPedidoA.first();
    lCQSPCotiza;
    lCQSPCotiza=CQSLProdCPedidoA.next(),
    lintContador++)
{
lCQSProducto=lCQSPCotiza->Producto();
 SiscomAnexarRegistroALaTabla(
 	lintContador,
	QTPedidoAnterior,
	QStringList () 				<<
	(*lCQSProducto)["Dsc"]			<<
	(*lCQSPCotiza)["Cantidad"]		<<
	(*lCQSPCotiza)["Precio"]		<<
	(*lCQSPCotiza)["Importe"]);
}
SiscomAjustaColumnas(QTPedidoAnterior);
SiscomAjustaFilas(QTPedidoAnterior);
}

void QPedidos::RegistraVenta()
{
GeneraIdPedido();
CQSisOpVenta lCQSOVenta(SisDatCom);
lCQSOVenta.RegistraVenta(&CQSLProdCotizar);
}

void QPedidos::GeneraIdPedido()
{
CQSisOpCotiza lCQSOCotiza(SisDatCom);
lCQSOCotiza.GeneraIdentificador(&CQSLProdCotizar);
}
void QPedidos::RegistraPedido()
{
const char *lchrPtrIdPedido;
CQSisProdCotiza *lCQSProdCotiza;
lCQSProdCotiza=CQSLProdCotizar.at(0);
lchrPtrIdPedido=(*lCQSProdCotiza)["IdCotizacion"];
QInformacionPedido lQInfoPedido(lchrPtrIdPedido,SisDatCom,chrPtrArgumentos);
}

void QPedidos::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
