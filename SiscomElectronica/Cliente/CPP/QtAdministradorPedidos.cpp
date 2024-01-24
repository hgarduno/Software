#include <QtAdministradorPedidos.h>
#include <IMP_QControlFecha.h>
#include <QCtrlEstadosPedidosClienteSE.h>
#include <IMP_QControlFecha.h>
#include <IMP_CapturaRangoHora.h>

#include <zOrdenes.h>
#include <zOrdenVenta.h>
#include <zSiscomQt3.h>
#include <zClienteSiscom.h>
#include <zSiscomDesarrollo4.h>
#include <zPedido.h>
#include <zPuntoEntrega.h>
#include <zDireccion.h>
#include <zEstadoPedido.h>
#include <zCondicionConsultaOrdenes.h>

#include <qpushbutton.h>
#include <qtable.h>
#include <qbuttongroup.h>

QtAdministradorPedidos::QtAdministradorPedidos(zSiscomConexion *pzSisConexion,
						QWidget *pQWParent,
					       const char *pchrPtrName,
					       WFlags pWFlags):
			AdministradorPedidos(pQWParent,pchrPtrName,pWFlags),
			zSisConexion(pzSisConexion),
			zSisRegEstado(0)
{

}
void QtAdministradorPedidos::Iniciando()
{
   IniciaVariables();
   ConectaSlots();
}
void QtAdministradorPedidos::ConectaSlots()
{
 ConectaBotones();
 ConectaTabla();
 ConectaOtros();
}
void QtAdministradorPedidos::IniciaVariables()
{
QCtrFechaFin->ColocaFechaHoy();
QCtrFechaIni->ColocaFechaHoy();
QCtrEstadosPedido->Servidor(zSisConexion);
QCtrEstadosPedido->IniciaControl();
zSiscomQt3::Foco(QCtrFechaIni);
IniciandoConsultas();
}
void QtAdministradorPedidos::ConectaOtros()
{
connect(QCtrEstadosPedido,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotSeleccionoEstado(zSiscomRegistro *)));

connect(QCtrFechaIni,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAFechaFin()));
connect(QCtrFechaFin,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAConsultar()));
connect(QBGTipoOrden,SIGNAL(clicked(int)),SLOT(SlotComoConsulto(int)));
}
void QtAdministradorPedidos::SlotComoConsulto(int pintNBoton)
{
   zConConsOrdenes=(this->*Consultas[pintNBoton])(); 

}
void QtAdministradorPedidos::SlotFocoAFechaFin()
{
    zSiscomQt3::Foco(QCtrFechaFin);
}
void QtAdministradorPedidos::SlotFocoAConsultar()
{
	zSiscomQt3::Foco(QPBConsultar);
}
void QtAdministradorPedidos::SlotSeleccionoEstado(zSiscomRegistro *pzSisRegEstado)
{
 zSisRegEstado=pzSisRegEstado;
}
void QtAdministradorPedidos::ConectaTabla()
{
 connect(QTOrdenes,SIGNAL(currentChanged(int,int)),SLOT(SlotSelecciona(int,int)));
 connect(QTOrdenes,
 	SIGNAL(clicked(int,int,int,const QPoint &)),
 	SLOT(SlotSelecciona(int,int,int,const QPoint &)));
}
void QtAdministradorPedidos::SlotSelecciona(int pintFila,
					    int pintColumna,
					    int ,
					    const QPoint &)
{
  QTOrdenes->selectRow(pintFila);
  TextoABotonActualizaEstado(Orden(pintFila));
  HabilitaImpresion();
}
void QtAdministradorPedidos::SlotSelecciona(int pintFila,
					    int pintColumna)
{
  SlotSelecciona(pintFila,pintColumna,0,QPoint() ); 
}
void QtAdministradorPedidos::ConectaBotones()
{
Clicked(QPBConsultar,SLOT(SlotConsultar()));
Clicked(QPBActualizaEstado,SLOT(SlotActualizaEstado()));
Clicked(QPBImprimir,SLOT(SlotImprimir()));
}
void QtAdministradorPedidos::SlotActualizaEstado()
{

}
void QtAdministradorPedidos::SlotConsultar()
{
}
void QtAdministradorPedidos::SlotImprimir()
{

}
void QtAdministradorPedidos::Clicked(QPushButton *pQPButton,const char *pchrPtrSlot)
{
connect(pQPButton,SIGNAL(clicked()),pchrPtrSlot);
}
void QtAdministradorPedidos::MuestraOrdenes()
{
   MuestraOrdenes(Ordenes());
}
void QtAdministradorPedidos::TextoABotonActualizaEstado(zOrdenVenta *pzOrden)
{
QString lQStrTexto;
if(pzOrden->Pedido()->TipoEntregaInt())
lQStrTexto=QString("Actualiza estado pedido")	+
		   "\n"					+
		   pzOrden->Cliente()->Nombre()	     	+
		   " "					+
		   pzOrden->Cliente()->APaterno()	+
		   " "					+
		   "$" +				+
		   pzOrden->ImporteOrden();
else
lQStrTexto=QString("Actualiza estado pedido");
QPBActualizaEstado->setText(lQStrTexto);
QPBActualizaEstado->setEnabled(pzOrden->Pedido()->TipoEntregaInt()&&zSisRegEstado);
}
void QtAdministradorPedidos::MuestraOrdenes(zOrdenes *pzOrdenes)
{
int lintContador=0;
zOrdenVenta *lzOrdenV;
QTOrdenes->setNumRows(pzOrdenes->NNodos());
for(lzOrdenV=(zOrdenVenta *)pzOrdenes->Primer();
    lzOrdenV;
    lzOrdenV=(zOrdenVenta *)pzOrdenes->Siguiente(),
    lintContador++)
 MuestraOrden(lintContador,lzOrdenV);
 zSiscomQt3::AjustaFilasTabla(QTOrdenes);
 zSiscomQt3::AjustaColumnasTabla(QTOrdenes);
}
void QtAdministradorPedidos::MuestraOrden(int pintFila,zOrdenVenta *pzOrdenV)
{
QTOrdenes->setText(pintFila,0,TextoOrden(pzOrdenV));
}
const QString QtAdministradorPedidos::TextoDireccionCliente(zOrdenVenta *pzOrden)
{
return QString(pzOrden->Pedido()->PuntoEntrega()->Direccion()->Calle()) 	+
	      " " 								+
	      pzOrden->Pedido()->PuntoEntrega()->Direccion()->Numero()		+
	      ","								+
	      pzOrden->Pedido()->PuntoEntrega()->Direccion()->Delegacion()	+
	      " "								+
	      pzOrden->Pedido()->PuntoEntrega()->Direccion()->CP()		+
	      "\n\n";
}
const QString QtAdministradorPedidos::TextoEstadoPedido(zOrdenVenta *pzOrden)
{
 return QString(pzOrden->Pedido()->EstadoPedido()->Accion())		+
 	"\n\n";
}
const QString QtAdministradorPedidos::TextoPuntoEntrega(zOrdenVenta *pzOrdenV)
{
QString lQStrRegreso;

   if(pzOrdenV->Pedido()->TipoEntregaInt())  
    lQStrRegreso=QString("El pedido se envia a la direccion del cliente\n") 	+
    		 TextoDireccionCliente(pzOrdenV)				+
		 TextoEstadoPedido(pzOrdenV);
    else
    lQStrRegreso=QString("El pedido se envia a ")				+
    		 pzOrdenV->Pedido()->PuntoEntrega()->PuntoEntrega()		+
		 "\n";
 
 return lQStrRegreso;
}
const QString QtAdministradorPedidos::TextoCliente(zOrdenVenta *pzOrdenV)
{
return QString(pzOrdenV->Cliente()->Nombre()) 	+ 
       " " 					+
       pzOrdenV->Cliente()->APaterno()		+
       "\n\n";
}
const QString QtAdministradorPedidos::TextoCostoCambio(zOrdenVenta *pzOrden)
{
   if(pzOrden->Pedido()->TipoEntregaInt())
    return QString("Importe $")				+
    		  pzOrden->ImporteOrden() 		+
		  "\n";
    else
    return QString("Importe $")				+
    		  pzOrden->ImporteOrden() 		+
		  "\n"					+
		  "Se paga con $"			+
		  pzOrden->Pedido()->SePagaCon()	+
		  "\n"					+
		  "se entrega cambio de $"		+
		  pzOrden->Pedido()->Cambio()		+
		  "\n";
}
const QString QtAdministradorPedidos::TextoHoraEntrega(zOrdenVenta *pzOrden)
{
   
   if(!pzOrden->Pedido()->TipoEntregaInt())
	return QString("Se entrega a las  ") +	
		pzOrden->Pedido()->FechaHoraE() +
		QString("\n\n");

    else
    return QString("\n");
}
const QString QtAdministradorPedidos::TextoOrden(zOrdenVenta *pzOrden)
{
    return TextoCliente(pzOrden) 	+
	   TextoPuntoEntrega(pzOrden)	+
	   TextoCostoCambio(pzOrden)    +
	   TextoHoraEntrega(pzOrden);
}
void QtAdministradorPedidos::Ordenes(zOrdenes *pzOrdenes)
{
	zOrdsPedidos=pzOrdenes;
}
zOrdenes *QtAdministradorPedidos::Ordenes()
{
	return zOrdsPedidos;
}
const QString QtAdministradorPedidos::TextoBotonActualiza(zOrdenVenta *pzOrden)
{
  return QString(pzOrden->Cliente()->Nombre());
}
zOrdenVenta *QtAdministradorPedidos::Orden(int pintNOrden)
{
     return (zOrdenV=(zOrdenVenta *)(*zOrdsPedidos)[pintNOrden]);
}
zOrdenVenta *QtAdministradorPedidos::Orden()
{
   return zOrdenV;
}
const char *QtAdministradorPedidos::IdNuevoEstado()
{
   return zSisRegEstado->CampoConstChar("idedopedido");
}

void QtAdministradorPedidos::HabilitaImpresion()
{
  QPBImprimir->setEnabled(true);
}
zCondicionConsultaOrdenes *QtAdministradorPedidos::ConsultaPedidosPorFechas()
{
zCondicionConsultaFechaEntrega *lzConConsFechaE;
lzConConsFechaE=new zCondicionConsultaFechaEntrega;
lzConConsFechaE->IdTipoOrden("4");
lzConConsFechaE->FechaInicio((const char *)QCtrFechaIni->ObtenFecha());
lzConConsFechaE->FechaFin((const char *)QCtrFechaFin->ObtenFecha());
lzConConsFechaE->ComoConsulto("PorRangoFechas");
return lzConConsFechaE;

}
zCondicionConsultaHoraEntrega *QtAdministradorPedidos::ConsultaHoraEntrega(
				const char *pchrPtrHoraInicio,
				const char *pchrPtrHoraFin)
{
zCondicionConsultaHoraEntrega *lzConConsHoraEntrega;
lzConConsHoraEntrega=new zCondicionConsultaHoraEntrega;
lzConConsHoraEntrega->HoraInicio(pchrPtrHoraInicio);
lzConConsHoraEntrega->HoraFin(pchrPtrHoraFin);
lzConConsHoraEntrega->FechaInicio((const char *)QCtrFechaIni->ObtenFecha());
lzConConsHoraEntrega->FechaFin((const char *)QCtrFechaFin->ObtenFecha());
lzConConsHoraEntrega->ComoConsulto("PorHoraEntrega");
return lzConConsHoraEntrega;

}
zCondicionConsultaOrdenes *QtAdministradorPedidos::PedidosPorFechas()
{
QPBConsultar->setEnabled(true);
zSiscomQt3::Foco(QPBConsultar);
return ConsultaPedidosPorFechas();
}
zCondicionConsultaOrdenes *QtAdministradorPedidos::PedidosPorHora()
{
char lchrArrHoraInicio[25],lchrArrHoraFin[25];
 if(CapturandoHoraEntrega(lchrArrHoraInicio,lchrArrHoraFin))
 {
  QPBConsultar->setEnabled(true);
  zSiscomQt3::Foco(QPBConsultar);
  return ConsultaHoraEntrega(lchrArrHoraInicio,lchrArrHoraFin);
 }
}
int QtAdministradorPedidos::CapturandoHoraEntrega(char *pchrPtrHoraInicio,
						   char *pchrPtrHoraFin)
{
QCapturaRangoHora lQCHoraE(0);
if(lQCHoraE.Aceptar())
{
    lQCHoraE.Horas(pchrPtrHoraInicio,pchrPtrHoraFin);
    return 1;
}
else 
return 0;
}

void QtAdministradorPedidos::IniciandoConsultas()
{
Consultas[0]=&QtAdministradorPedidos::PedidosPorFechas;
Consultas[12]=&QtAdministradorPedidos::PedidosPorHora;
}

zCondicionConsultaOrdenes *QtAdministradorPedidos::Condicion()
{
   return zConConsOrdenes;
}
