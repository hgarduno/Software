#include <IMP_PedidoMaterial4.h>

#include <QCtrlProductosSE.h>

#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <zProductoPedido.h>

#include <qtextedit.h>
#include <qlineedit.h>
#include <qlcdnumber.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qmessagebox.h>

QPedidoMaterial4 *InstanciaPedidoMaterial4(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QPedidoMaterial4((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QPedidoMaterial4::QPedidoMaterial4(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				PedidoMaterial4(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				intActualizando(0),
				intActualizandoObsPedido(0)
{
IniciaVariables();
ConectaSlots();
}

QPedidoMaterial4::~QPedidoMaterial4()
{

}


void QPedidoMaterial4::ConectaSlots()
{
connect(QCtrProductos,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotSeleccionoProducto(zSiscomRegistro *)));
connect(QLECantidad,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoAAnexar()));
connect(QPBAnexar,
	SIGNAL(clicked()),
	SLOT(SlotAnexarProducto()));
connect(QTProductos,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionaProducto(int,int,int,const QPoint &)));
connect(QPBEliminaProducto,
	SIGNAL(clicked()),
	SLOT(SlotEliminaProducto()));
connect(QPBActualizar,
	SIGNAL(clicked()),
	SLOT(SlotActualizaProducto()));
connect(QPBRegistraPedido,
	SIGNAL(clicked()),
	SLOT(SlotRegistraPedido()));
connect(QPBActualizaObsPedido,
	SIGNAL(clicked()),
	SLOT(SlotActualizaObservacionesPedido()));
connect(QTEObservacionesPedido,
	SIGNAL(clicked(int,int)),
	SLOT(SlotActualizaObsProducto(int,int)));
}
void QPedidoMaterial4::SlotActualizaObsProducto(int ,int )
{
 if(!intActualizandoObsPedido)
 {
 QPBActualizaObsPedido->setEnabled(true);
 intActualizandoObsPedido=1;
 InterfazActualizandoObsPedido(true);
 }
}
void QPedidoMaterial4::SlotActualizaObservacionesPedido()
{
      if(intActualizandoObsPedido)
    {
	InterfazActualizandoObsPedido(false);
	ActualizandoObservacionesPedido();
	intActualizandoObsPedido=0;
    }
}
void QPedidoMaterial4::SlotRegistraPedido()
{
	RegistrandoPedido();
	ConsultandoPedidoHoy();
}
void QPedidoMaterial4::SlotActualizaProducto()
{
	if(!intActualizando)
	{
	intActualizando=1;
	InterfazActualizandoProducto(true);
	PreparaCantidadParaActualizar();
	}
	else
	{
	ActualizaProducto();
	ConsultandoPedidoHoy();
	InterfazActualizandoProducto(false);
	zSiscomQt3::Foco(QCtrProductos);
	QPBActualizar->setEnabled(false);
	QPBEliminaProducto->setEnabled(false);
	intActualizando=0;
	}

}
void QPedidoMaterial4::SlotEliminaProducto()
{
   EliminandoProducto();
   ConsultandoPedidoHoy();
}
void QPedidoMaterial4::SlotSeleccionaProducto(int pintFila,
					      int,
					      int,
					      const QPoint &)
{
	if(pintFila!=-1)
	{
	QTProductos->selectRow(pintFila);
	intProductoSeleccionado=pintFila;
	HabilitaEliminar();
	HabilitaActualizar();
	}

}
void QPedidoMaterial4::SlotAnexarProducto()
{
	ProductoAPedidoExpendio();
	ReIniciaCaptura();
	ConsultandoPedidoHoy();
}
void QPedidoMaterial4::SlotFocoAAnexar()
{
	AnexandoProducto();	
}
void QPedidoMaterial4::SlotSeleccionoProducto(zSiscomRegistro *pzSisRegProducto)
{
	if((zSisRegProducto=pzSisRegProducto))
	{
	  ProductoSeleccionado();
	}

}
void QPedidoMaterial4::IniciaVariables()
{
   QCtrProductos->Servidor(zSisConexion);
   QCtrProductos->IniciaControl();
   ConsultandoPedidoHoy();
   zSiscomQt3::Foco(QCtrProductos);
}
void QPedidoMaterial4::ConsultandoPedidoHoy()
{
 	if(ConsultaPedidoHoy()==100)
	IniciandoPedidoExpendioHoy();
	else
	MuestraPedidoHoy();
}
int QPedidoMaterial4::ConsultaPedidoHoy()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"PedidoExpendioHoy");
return lzSisElectronica.PedidoExpendioHoy(*chrPtrArgumentos,&zPedExpendio);
}
void QPedidoMaterial4::MuestraPedidoHoy()
{
MuestraPedido();
MuestraProductos();
}
void QPedidoMaterial4::ProductoSeleccionado()
{
	QTEDescripcion->setText((const char *)(*zSisRegProducto)["dscproducto"]);
	QLECantidad->setEnabled(true);
	zSiscomQt3::Foco(QLECantidad);
}
void QPedidoMaterial4::AnexandoProducto()
{
  if(!intActualizando)
  {
  QPBAnexar->setEnabled(true);
  zSiscomQt3::Foco(QPBAnexar);
  }
}
void QPedidoMaterial4::ProductoAPedidoExpendio()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ProductoAPedidoExpendio");
zProductoPedido lzProdPedido((const char *)(*zSisRegProducto)["cveproducto"]);
Producto(&lzProdPedido);
lzSisElectronica.ProductoAPedidoExpendioHoy(&lzProdPedido);
}
void QPedidoMaterial4::Producto(zProductoPedido *pzProdPedido)
{
pzProdPedido->Cantidad(zSiscomQt3::Texto(QLECantidad));
pzProdPedido->IdPedido(zPedExpendio.IdPedido());
pzProdPedido->ObsProducto(zSiscomQt3::Texto(QTEObsProducto));
}
void QPedidoMaterial4::IniciandoPedidoExpendioHoy()
{
 IniciaPedidoExpendioHoy();
}
void QPedidoMaterial4::IniciaPedidoExpendioHoy()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"IniciaPedidoExpendioHoy");
lzSisElectronica.IniciaPedidoExpendioHoy(*chrPtrArgumentos);
}
void QPedidoMaterial4::MuestraPedido()
{
QTEObservacionesPedido->setText(zPedExpendio.Observaciones());
}
void QPedidoMaterial4::MuestraProductos()
{
const char *lchrPtrCampos[]={"estado","cveproducto","cantidad","observacion",0};
zSiscomRegistros *lzSisRegsProductos;
if((lzSisRegsProductos=zPedExpendio.Productos()))
{
zSiscomQt3::LlenaTabla(lchrPtrCampos,lzSisRegsProductos,QTProductos);
zSiscomQt3::AjustaFilasTabla(QTProductos);
}
}
void QPedidoMaterial4::ReIniciaCaptura()
{
  QTEObsProducto->clear();
  zSiscomQt3::Foco(QCtrProductos);
}
void QPedidoMaterial4::HabilitaEliminar()
{
	QPBEliminaProducto->setEnabled(true);
}

void QPedidoMaterial4::HabilitaActualizar()
{
	QPBActualizar->setEnabled(true);
}
void QPedidoMaterial4::EliminandoProducto()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"EliminaProductoPedido");
lzSisElectronica.EliminaProductoPedido(zPedExpendio.IdPedido(),
				       zPedExpendio.IdProducto(intProductoSeleccionado));
}

void QPedidoMaterial4::InterfazActualizandoProducto(bool pbActualizando)
{
   QTProductos->setEnabled(!pbActualizando);
   QCtrProductos->setEnabled(!pbActualizando);
   QPBAnexar->setEnabled(!pbActualizando);
   QPBEliminaProducto->setEnabled(!pbActualizando);
   QPBRegistraPedido->setEnabled(!pbActualizando);
}
void QPedidoMaterial4::PreparaCantidadParaActualizar()
{
QLECantidad->setEnabled(true);
zSiscomQt3::Foco(QLECantidad);

}
void QPedidoMaterial4::ActualizaProducto()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ActualizaProductoPedido");
zProductoPedido lzProdPedido(zPedExpendio.Clave(intProductoSeleccionado));
Producto(&lzProdPedido);
lzProdPedido.IdProducto(zPedExpendio.IdProducto(intProductoSeleccionado));
lzSisElectronica.ProductoAPedidoExpendioHoy(&lzProdPedido);
}
void QPedidoMaterial4::RegistrandoPedido()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"RegistraPedido");
lzSisElectronica.RegistrandoPedido(&zPedExpendio);
}
void QPedidoMaterial4::InterfazActualizandoObsPedido(bool pbModal)
{
	InterfazActualizandoProducto(pbModal);
	QTEObsProducto->setEnabled(!pbModal);
}
void QPedidoMaterial4::ActualizandoObservacionesPedido()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ActualizaObservacionesPedido");
lzSisElectronica.ActualizaObservacionesPedido(&zPedExpendio,zSiscomQt3::Texto(QTEObservacionesPedido));
}
