#include <IMP_PedidosPendientes.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSisPedidoMaterial.h>
#include <SiscomRegistros3.h>

#include <qtable.h>
#include <qpushbutton.h>
QPedidosPendientes::QPedidosPendientes(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				PedidosPendientes(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QPedidosPendientes::~QPedidosPendientes()
{

}

void QPedidosPendientes::ConectaSlots()
{
connect(QTPedidos,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionoPedido(int,int,int,const QPoint &)));
connect(QPBEnviarAMatriz,
	SIGNAL(clicked()),
	SLOT(SlotEnviarAMatriz()));
}
void QPedidosPendientes::SlotEnviarAMatriz()
{
SiscomEscribeLog3Qt("Depurando ....");
EnviarAMatriz();
}
void QPedidosPendientes::SlotSeleccionoPedido(int pintNPedido,
					      int,
					      int,
					      const QPoint &)
{
 SisReg3Pedido=SisReg3LstPedidos[pintNPedido];
ConsultandoDetallePedido(SisReg3Pedido);
}
void QPedidosPendientes::IniciaVariables()
{
Consultando();
}
void QPedidosPendientes::Consultando()
{
Consulta();
Muestra();
}

void QPedidosPendientes::Consulta()
{
CQSisPedidoMaterialOp lCQSPedMaterialOp(SisDatCom);
lCQSPedMaterialOp.PedidosPendientesPorEnviaAMatriz("","",&SisReg3LstPedidos);
}
void QPedidosPendientes::Muestra()
{
const char *lchrPtrArgumentos[]={"fecha","observaciones","idpedido",0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrArgumentos,
					QTPedidos,
					&SisReg3LstPedidos);
}
void QPedidosPendientes::ConsultandoDetallePedido(SiscomRegistro3 *pSisReg3Pedido)
{
SiscomRegistro3Lst lSisReg3LstDetallePedido;
  ConsultaDetallePedido(pSisReg3Pedido,&lSisReg3LstDetallePedido);
   MuestraDetallePedido(&lSisReg3LstDetallePedido);
}
void QPedidosPendientes::ConsultaDetallePedido(SiscomRegistro3 *pSisReg3Pedido,
					      SiscomRegistro3Lst *pSisReg3LstDetallePedido)
{
CQSisPedidoMaterialOp lCQSPedidoMaterial(SisDatCom);
lCQSPedidoMaterial.DetallePedidoPendientePorEnviarAMatriz((*pSisReg3Pedido)["idpedido"],
							  pSisReg3LstDetallePedido);
}
void QPedidosPendientes::MuestraDetallePedido(SiscomRegistro3Lst *pSisReg3LstDetallePedido)
{
const char *lchrPtrCampos[]={"cantidad","cveproducto","observacion",0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
					QTDetallePedido,
					pSisReg3LstDetallePedido);
}
void QPedidosPendientes::EnviarAMatriz()
{
CQSisPedidoMaterialOp lCQSPedidoMaterial(SisDatCom);
lCQSPedidoMaterial.EnviaPedidoPendientePorEnviarAMatriz(SisReg3Pedido);
}
