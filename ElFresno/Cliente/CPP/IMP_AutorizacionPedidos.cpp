#include <IMP_AutorizacionPedidos.h>
#include <IMP_ChoferYVehiculo.h>
#include <IMP_ModificaPedido.h>
#include <IMP_CapturaFecha.h>
#include <IMP_RangoFechas.h>
#include <IMP_CapturaFormaPago.h>
#include <GeneralBibliotecaSeguridad3.h>
#include <SISCOMComunicaciones++.h>
#include <Vehiculos.h>
#include <Personas.h>
#include <Choferes.h>
#include <Empresas.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qlineedit.h>
#include <qmessagebox.h>

QAutorizacionPedidos *InstanciaAutorizacionPedidos(void *pCSisDatCom,
						   void *pQWParent,
						   const char *pchrPtrName,
						   int pintWFlags)
{
	return new QAutorizacionPedidos((CSISCOMDatComunicaciones *)pCSisDatCom,
					(QWidget *)pQWParent,
					pchrPtrName,
					pintWFlags);
}

QAutorizacionPedidos::QAutorizacionPedidos(CSISCOMDatComunicaciones *pCSisDatCom,
					   QWidget* parent, const char* name, WFlags fl )
    : AutorizacionPedidos( parent, name, fl ),
    CSisDatCom(pCSisDatCom),
   V_Vehiculo(0),
   QWParent(parent),
   QSiscomSeguridad3((AutorizacionPedidos *)this,
		      pCSisDatCom,
		      "ElFresno",
		      pCSisDatCom->ObtenUsuario(),
		      ""),
   chrPtrFechaTrabajoIni(0),
   chrPtrFechaTrabajoFin(0),
   chrPtrFechaTrabajoIniSinAuto(0),
   chrPtrFechaTrabajoFinSinAuto(0),
   P_Pedido(0),
   intEnRuta(0)
{
	IniciaVariables();
	ObtenDatosMatriz();
	ObtenDatosUsuarioFirmado();
	ObtenIdChoferes();
	CargaPedidosPendientesDeAutorizar();
	ConectaSlots();
	
}

QAutorizacionPedidos::~QAutorizacionPedidos()
{
}
void QAutorizacionPedidos::IniciaVariables()
{
}
void QAutorizacionPedidos::ConectaSlots()
{
	connect(QPBAChoferYVehiculo,
		SIGNAL(clicked()),
		SLOT(S_AsignaChoferYVehiculo()));
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(S_SeleccionoPedido(int,int,int,const QPoint &)));
	connect(QPBActulizarInf,
		SIGNAL(clicked()),
		SLOT(S_ActualizaInformacion()));
	connect(QTDatos,
		SIGNAL(doubleClicked(int,int,int,const QPoint &)),
		SLOT(S_ModificaPedido(int,int,int,const QPoint &)));
	connect(QPBFechaEntrega,
		SIGNAL(clicked()),
		SLOT(S_FechaEntrega()));
	connect(QPBAutorizaPedido,
		SIGNAL(clicked()),
		SLOT(S_AutorizoPedido()));
	connect(QPBFFechaTrabajo,
		SIGNAL(clicked()),
		SLOT(S_FFechaTrabajo()));
	connect(QPBPAutorizados,
		SIGNAL(clicked()),
		SLOT(S_PedidosAutorizados()));
	connect(QPBSeCargaPedido,
		SIGNAL(clicked()),
		SLOT(S_SeCargaElPedido()));
	connect(QPBPEnCarga,
		SIGNAL(clicked()),
		SLOT(S_PedidosCargandose()));
	connect(QPBSalPedido,
		SIGNAL(clicked()),
		SLOT(S_SalioElPedido()));
	connect(QPBPEnRuta,
		SIGNAL(clicked()),
		SLOT(S_PedidosEnRuta()));
	connect(QPBPEntregado,
		SIGNAL(clicked()),
		SLOT(S_PedidoEntregado()));
	connect(QPBPEntregados,
		SIGNAL(clicked()),
		SLOT(S_PedidosEntregados()));
	connect(QPBPRevAlChofer,
		SIGNAL(clicked()),
		SLOT(S_PedidoRevisadoAlChofer()));
	connect(QPBPedidosRevisadosAlChofer,
		SIGNAL(clicked()),
		SLOT(S_PedidosRevisadosALosChoferes()));
	connect(QPBFormaPago,
		SIGNAL(clicked()),
		SLOT(S_CapturaFormaPago()));
	connect(QTDatos,
		SIGNAL(currentChanged(int,int)),
		SLOT(S_SeleccionandoPedidos(int,int)));
	connect(QPBFFTrabajoSinAut,
		SIGNAL(clicked()),
		SLOT(S_FijaFechaTrabajoPedSinAutorizar()));

}
void QAutorizacionPedidos::S_FijaFechaTrabajoPedSinAutorizar()
{
QRangoFechas lQRFechas;

		if(lQRFechas.ObtenSeleccion()==QRangoFechas::Aceptar)
		{
			lQRFechas.ObtenRangoFechas(&chrPtrFechaTrabajoIniSinAuto,
						   &chrPtrFechaTrabajoFinSinAuto);
			chrPtrFechaTrabajoIni=chrPtrFechaTrabajoIniSinAuto;
			chrPtrFechaTrabajoFin=chrPtrFechaTrabajoFinSinAuto;
		}
}
void QAutorizacionPedidos::S_CapturaFormaPago()
{
QCapturaFormaPago lQCFPago;
char lchrArrFPago[125],
     lchrArrFechaPago[25];
	if(lQCFPago.ObtenOpcion()==SISCOMGlobales::Aceptar)
	{
	  lQCFPago.ObtenFormaPago(lchrArrFPago,
				  lchrArrFechaPago);
	  CQCtrPedidos lCQCFormaPago(CSisDatCom,
				      CQCtrPedidos::OperacionPedidos,
				     QStringList () <<
				     QString("ActualizaFormaPago") <<
				     P_Pedido->ObtenNumPedido() <<
				     lchrArrFPago <<
				     lchrArrFechaPago <<
				     P_Pedido->ObtenImporteDelPedido() ,
				     &CQPPedidos);
	 CargaPedidosRevisadosALosChoferes();
	}
	
}
void QAutorizacionPedidos::S_PedidosRevisadosALosChoferes()
{
CargaPedidosRevisadosALosChoferes();
	HabilitaDesHabilitaControles("%W0%W0%W0%W0",
				      QPBSalPedido,
				      QPBPRevAlChofer,
				      QPBPEntregado,
				      QPBSeCargaPedido);
	setCaption(QString("Manejador De Pedidos: ") +
	           "[Pedidos Revisados Al Chofer]");
SiscomAjustaColumnas(QTDatos);
}
void QAutorizacionPedidos::S_PedidoRevisadoAlChofer()
{
CQCtrPedidos lCQCPedidosAutoriza(CSisDatCom,
					 CQCtrPedidos::OperacionPedidos,  
					 QStringList() <<
					 QString("ActualizaEstadoPedido") <<
					 P_Pedido->ObtenNumPedido() <<
					 "5" <<
					 "6" <<               
					 CQPUFirmado->ObtenIdPersona(),
					 &CQPPedidos);
CargaPedidosEntregados();

SiscomAjustaColumnas(QTDatos);

}
void QAutorizacionPedidos::S_PedidosEntregados()
{
	CargaPedidosEntregados();
	HabilitaDesHabilitaControles("%W0%W1%W0%W0",
				      QPBSalPedido,
				      QPBPRevAlChofer,
				      QPBPEntregado,
				      QPBSeCargaPedido);
	setCaption(QString("Manejador De Pedidos: ") +
		   "[Pedidos Entregados]");
	intEnRuta=0;

SiscomAjustaColumnas(QTDatos);
}
void QAutorizacionPedidos::S_PedidoEntregado()
{
CQCtrPedidos lCQCPedidosAutoriza(CSisDatCom,
					 CQCtrPedidos::OperacionPedidos,  
					 QStringList() <<
					 QString("ActualizaEstadoPedido") <<
					 P_Pedido->ObtenNumPedido() <<
					 "4" <<
					 "5" <<               
					 "QuienAutoriza",
					 &CQPPedidos);
CargaPedidosEnRuta();

SiscomAjustaColumnas(QTDatos);
}
void QAutorizacionPedidos::S_PedidosEnRuta()
{
	CargaPedidosEnRuta();
	HabilitaDesHabilitaControles("%W0%W0%W1%W0",
				      QPBSalPedido,
				      QPBPRevAlChofer,
				      QPBPEntregado,
				      QPBSeCargaPedido);
	setCaption(QString("Manejador De Pedidos: ")+
		   "[Pedidos En Ruta]");
	intEnRuta=1;

}
void QAutorizacionPedidos::S_SalioElPedido()
{
CQCtrPedidos lCQCPedidosAutoriza(CSisDatCom,
					 CQCtrPedidos::OperacionPedidos,  
					 QStringList() <<
					 QString("ActualizaEstadoPedido") <<
					 P_Pedido->ObtenNumPedido() <<
					 "3" <<
					 "4" <<               
					 "QuienAutoriza",
					 &CQPPedidos);
CargaPedidosCargandose();
SiscomAjustaColumnas(QTDatos);
}
void QAutorizacionPedidos::S_PedidosCargandose()
{
	CargaPedidosCargandose();
	HabilitaDesHabilitaControles("%W1%W0%W0%W0",
				      QPBSalPedido,
				      QPBPRevAlChofer,
				      QPBPEntregado,
				      QPBSeCargaPedido);
	setCaption(QString("Manejador De Pedidos: ")+
		   "[Pedidos Cargandose]");
	intEnRuta=0;
		  
SiscomAjustaColumnas(QTDatos);

}

void QAutorizacionPedidos::S_SeCargaElPedido()
{
CQCtrPedidos lCQCPedidosAutoriza(CSisDatCom,
					 CQCtrPedidos::OperacionPedidos,  
					 QStringList() <<
					 QString("ActualizaEstadoPedido") <<
					 P_Pedido->ObtenNumPedido() <<
					 "2" <<
					 "3" <<               
					 "QuienAutoriza",
					 &CQPPedidos);
	CargaPedidosAutorizados();
SiscomAjustaColumnas(QTDatos);
}
void QAutorizacionPedidos::S_PedidosAutorizados()
{

	CargaPedidosAutorizados();
	HabilitaDesHabilitaControles("%W0%W0%W0%W1",
				      QPBSalPedido,
				      QPBPRevAlChofer,
				      QPBPEntregado,
				      QPBSeCargaPedido);
	setCaption(QString("Manejador De Pedidos: ") +
		   "[Pedidos Autorizados]");
	intEnRuta=0;
SiscomAjustaColumnas(QTDatos);
}
void QAutorizacionPedidos::S_FFechaTrabajo()
{
QRangoFechas lQRFechas;

		if(lQRFechas.ObtenSeleccion()==QRangoFechas::Aceptar)
		{
			lQRFechas.ObtenRangoFechas(&chrPtrFechaTrabajoIni,
						   &chrPtrFechaTrabajoFin);
		}

}
void QAutorizacionPedidos::S_AutorizoPedido()
{
	CQCtrPedidos lCQCPedidosAutoriza(CSisDatCom,
					 CQCtrPedidos::OperacionPedidos,  
					 QStringList() <<
					 QString("ActualizaEstadoPedido") <<
					 P_Pedido->ObtenNumPedido() <<
					 "1" <<
					 "2" <<               
					 CQPUFirmado->ObtenIdPersona(),
					 &CQPPedidos);
	CargaPedidosPendientesDeAutorizar();
}
void QAutorizacionPedidos::S_FechaEntrega()
{
QCapturaFecha lQCFecha;

	     if(lQCFecha.ObtenSeleccion()==QCapturaFecha::Aceptar)
		CQCtrPedidos lCQCPedidosFEntrega(CSisDatCom,
						 CQCtrPedidos::ActualizaFechaEntrega,
						 QStringList() <<
						 QString("ActualizaFechaEntrega") <<
						 P_Pedido->ObtenNumPedido() <<
						 lQCFecha.ObtenFecha() ,
						 &CQPPedidos);
	CargaPedidosPendientesDeAutorizar();
SiscomAjustaColumnas(QTDatos);
}
void QAutorizacionPedidos::S_ModificaPedido(int pintNPedido,
					    int pintNColumna,
					    int ,
					    const QPoint &)
{
///if(QTDatos->numRows() && !intEnRuta)
if(QTDatos->numRows() &&pintNPedido!=-1)
{
Pedido *lP_Pedido=CQPPedidos.at(pintNPedido);
QModificaPedido *lQMPedido =new QModificaPedido(E_Matriz,
						CQPPedidos.at(pintNPedido)->ObtenNumPedido(),
						CSisDatCom,
						QWParent,
						"lQMPedido",
						0);
		lQMPedido->PonModificarDatos(!intEnRuta);
		connect(lQMPedido,
			SIGNAL(Signal_ModificoPedido()),
			SLOT(S_ModificoPedido()));
		lQMPedido->show();
}


}
void QAutorizacionPedidos::S_ModificoPedido()
{
	S_PedidosRevisadosALosChoferes();
	intEnRuta=0;
}
void QAutorizacionPedidos::S_ActualizaInformacion()
{
	CargaPedidosPendientesDeAutorizar();
	setCaption(QString("Manejador De Pedidos: ")+
		   "[Pedidos Pendientes Por Autorizar]");
}
void QAutorizacionPedidos::S_SeleccionandoPedidos(int pintNFila,
						  int )
{
	if(QTDatos->numRows())
	if((P_Pedido=CQPPedidos.at(pintNFila)))
	MuestraDatosChoferEtc();
}
void QAutorizacionPedidos::S_SeleccionoPedido(int pintNPedido,
					      int,
					      int,
					      const QPoint &)
{
	if(QTDatos->numRows())
	{
	if((P_Pedido=CQPPedidos.at(pintNPedido)))
	{
	
	QTDatos->selectCells(pintNPedido,0,pintNPedido,QTDatos->numCols());
	MuestraDatosChoferEtc();
	}
	}

}
void QAutorizacionPedidos::ObtenIdChoferes()
{
CQPerfiles *lCQPerfiles;

	lCQPerfiles=QSiscomSeguridad3::ObtenPerfilesDeLaAplicacion(CSisDatCom);
	if(!(*lCQPerfiles)["Choferes"])
	QMessageBox::information(this,
				 "El Fresno",
				 "No se ha encontrado en la base de datos El Perfil Choferes");
	else
	chrPtrIdPerfilChoferes=(*lCQPerfiles)["Choferes"]->ObtenIdPerfil();

	


}

void QAutorizacionPedidos::S_AsignaChoferYVehiculo()
{
printf("La Fecha:%s %s\n",
	chrPtrFechaTrabajoIniSinAuto,
	chrPtrFechaTrabajoFinSinAuto);
if(P_Pedido && QTDatos->currentRow()>=0)
{
 QChoferYVehiculo lQCYVehiculo(
 		chrPtrIdPerfilChoferes,
		(chrPtrFechaTrabajoIniSinAuto ? chrPtrFechaTrabajoIniSinAuto:""),
		(chrPtrFechaTrabajoFinSinAuto ? chrPtrFechaTrabajoFinSinAuto:"") ,
 		CSisDatCom);
CQPedidos lCQPedidos;
	if(lQCYVehiculo.ObtenSeleccion()==QChoferYVehiculo::BTN_Aceptar)
	{
	V_Vehiculo=lQCYVehiculo.ObtenVehiculo();
        C_Chofer=lQCYVehiculo.ObtenChofer();
	CQCtrPedidos lCQCPedidosAsignaVehiculoYChofer(CSisDatCom,
						      CQCtrPedidos::PedidosDelVehiculo, /* Curioso pero es alta */
						      QStringList () <<	
						      "AsignaVehiculoAlPedido" <<
						      V_Vehiculo->ObtenIdVehiculo() <<
						      CQPPedidos.at(QTDatos->currentRow())->ObtenNumPedido() <<
						      C_Chofer->ObtenChofer()->ObtenIdPersona() , 
						      &lCQPedidos);
	CargaPedidosPendientesDeAutorizar();
				
	}
}
else
QMessageBox::information(this,
		         "El Fresno",
			 "No se ha seleccionado ningun pedido");
}
void QAutorizacionPedidos::CargaPedidosCargandose()
{
CQPPedidos.clear();
CQCtrPedidos lCQCPedidos(CSisDatCom,
			 CQCtrPedidos::PedidosSinAutorizarDelDia,
			 QStringList() 					   <<
			 QString("")       				   <<
		         "3"           					   <<
			 (chrPtrFechaTrabajoIni ? chrPtrFechaTrabajoIni:"") <<
			 (chrPtrFechaTrabajoFin ? chrPtrFechaTrabajoFin:"") ,
			&CQPPedidos);
MuestraPedidos();

}
void QAutorizacionPedidos::CargaPedidosAutorizados()
{
CQPPedidos.clear();
CQCtrPedidos lCQCPedidos(CSisDatCom,
			 CQCtrPedidos::PedidosSinAutorizarDelDia,
			 QStringList() 					   <<
			 QString("")       				   <<
		         "2"           					   <<
			 (chrPtrFechaTrabajoIni ? chrPtrFechaTrabajoIni:"") <<
			 (chrPtrFechaTrabajoFin ? chrPtrFechaTrabajoFin:"") ,
			&CQPPedidos);
MuestraPedidos();

}
void QAutorizacionPedidos::CargaPedidosRevisadosALosChoferes()
{
CQPPedidos.clear();
CQCtrPedidos lCQCPedidos(CSisDatCom,
			 CQCtrPedidos::PedidosSinAutorizarDelDia,
			 QStringList() 					   <<
			 QString("")       				   <<
		         "6"           					   <<
			 (chrPtrFechaTrabajoIni ? chrPtrFechaTrabajoIni:"") <<
			 (chrPtrFechaTrabajoFin ? chrPtrFechaTrabajoFin:"") ,
			&CQPPedidos);
intEnRuta=1;
MuestraPedidos();

}
void QAutorizacionPedidos::CargaPedidosEntregados()
{
CQPPedidos.clear();
CQCtrPedidos lCQCPedidos(CSisDatCom,
			 CQCtrPedidos::PedidosSinAutorizarDelDia,
			 QStringList() 					   <<
			 QString("")       				   <<
		         "5"           					   <<
			 (chrPtrFechaTrabajoIni ? chrPtrFechaTrabajoIni:"") <<
			 (chrPtrFechaTrabajoFin ? chrPtrFechaTrabajoFin:"") ,
			&CQPPedidos);
MuestraPedidos();

}
void QAutorizacionPedidos::CargaPedidosEnRuta()
{
CQPPedidos.clear();
CQCtrPedidos lCQCPedidos(CSisDatCom,
			 CQCtrPedidos::PedidosSinAutorizarDelDia,
			 QStringList() 					   <<
			 QString("")       				   <<
		         "4"           					   <<
			 (chrPtrFechaTrabajoIni ? chrPtrFechaTrabajoIni:"") <<
			 (chrPtrFechaTrabajoFin ? chrPtrFechaTrabajoFin:"") ,
			&CQPPedidos);
MuestraPedidos();

}
void QAutorizacionPedidos::CargaPedidosPendientesDeAutorizar()
{
CQPPedidos.clear();
/*
CQCtrPedidos lCQCPedidos(CSisDatCom,
			 CQCtrPedidos::PedidosSinAutorizarDelDia,
			 QStringList() <<
			 ""	       <<
		         "1" 	       << 
			 ""	       <<
			 "",
			&CQPPedidos);
*/
CQCtrPedidos lCQCPedidos(CSisDatCom,
			 CQCtrPedidos::PedidosSinAutorizarDelDia,
			 QStringList() 					   <<
			 QString("")       				   <<
		         "1"           					   <<
			 (chrPtrFechaTrabajoIniSinAuto ? chrPtrFechaTrabajoIniSinAuto:"") <<
			 (chrPtrFechaTrabajoFinSinAuto ? chrPtrFechaTrabajoFinSinAuto:"") ,
			&CQPPedidos);
MuestraPedidos();


}
void QAutorizacionPedidos::MuestraPedidos()
{
Pedido *lP_Pedido;

	QTDatos->setNumRows(0);
	for(lP_Pedido=CQPPedidos.first();
	    lP_Pedido;
	    lP_Pedido=CQPPedidos.next())
	{
	   AnexarRegistroALaTabla(QTDatos,
				  QStringList()                                     <<
				  QString(lP_Pedido->ObtenCliente()->ObtenNombre()) + 
				  " "						    +
				  lP_Pedido->ObtenCliente()->ObtenAPaterno()        +
				  " "						    +
				  lP_Pedido->ObtenCliente()->ObtenAMaterno()        <<
				  lP_Pedido->ObtenNumPedido()                       <<
				  lP_Pedido->ObtenImporteDelPedido()                <<
				  lP_Pedido->ObtenTipoPrecio()                       <<
				  lP_Pedido->ObtenFechaRegistro()                   <<
				  lP_Pedido->ObtenFechaEntrega()                    <<
				  QString(lP_Pedido->ObtenChofer()->ObtenNombre())  +
				  lP_Pedido->ObtenChofer()->ObtenAPaterno()         +
				  lP_Pedido->ObtenChofer()->ObtenAMaterno()         <<
				  QString(lP_Pedido->ObtenVehiculo()->ObtenDescripcion())+
				  "["						    +
				  lP_Pedido->ObtenVehiculo()->ObtenPlacas()         +
				  "]" <<
				  lP_Pedido->ObtenFormaPago() <<
				  lP_Pedido->ObtenContactoCliente());
	   			 /*<<
				  QString(lP_Pedido->ObtenRevPedChofer()->ObtenNombre())  +
				  " "							  +
				  lP_Pedido->ObtenRevPedChofer()->ObtenAPaterno()         +
				  " "							  +
				  lP_Pedido->ObtenRevPedChofer()->ObtenAMaterno());
				  */
	}
/*
	QPBAChoferYVehiculo->setEnabled(QTDatos->numRows());	
	QPBFechaEntrega->setEnabled(QTDatos->numRows());
*/
}
void QAutorizacionPedidos::MuestraDatosChoferEtc()
{

	QPBAutorizaPedido->setEnabled((P_Pedido->ObtenChofer()->ObtenIdPersona()[0] &&
	                               P_Pedido->ObtenVehiculo()->ObtenDescripcion()[0] &&
				       P_Pedido->ObtenFechaEntrega()[0]) );

	QLEAutorizo->setText(QString(P_Pedido->ObtenAutorizo()->ObtenNombre()) +
			     " "					       +
			     P_Pedido->ObtenAutorizo()->ObtenAPaterno()        +
			     " "					       +
			     P_Pedido->ObtenAutorizo()->ObtenAMaterno() );
	QLERPedido->setText(QString(P_Pedido->ObtenVendedor()->ObtenNombre()) +
			    " "						      +
			    P_Pedido->ObtenVendedor()->ObtenAPaterno()        +
			    " "						      +
			    P_Pedido->ObtenVendedor()->ObtenAMaterno() );
	QLERAlChofer->setText(QString(P_Pedido->ObtenRevPedChofer()->ObtenNombre()) +
			      " "						   +
			      P_Pedido->ObtenRevPedChofer()->ObtenAPaterno()       +
			      " "						   +
			      P_Pedido->ObtenRevPedChofer()->ObtenAMaterno());
	QPBFormaPago->setEnabled(!P_Pedido->ObtenFormaPago()[0]);



			    
			   
	
			   

}
void QAutorizacionPedidos::ObtenDatosMatriz()
{
CQEmpresas lCQERegreso;
CQCtrEmpresas lCQCMatriz(CSisDatCom,
			 QStringList() <<
			 QString("ConsultaEmpresas") <<
			 "Matriz",
			 &lCQERegreso);
E_Matriz=lCQERegreso.at(0);
}
void QAutorizacionPedidos::ObtenDatosUsuarioFirmado()
{
CQ_Personas lCQPRegreso;
CQCtrPersonas lCQCPersonas(CSisDatCom,
			   QStringList() <<
			   QString("ConsultarPersonas") <<
			   "ConsultaPersonaPorFirma" <<
			   CSisDatCom->ObtenUsuario() <<
			   "" <<
			   "" <<
			   "" <<
			   "", 
			   &lCQPRegreso);

CQPUFirmado=lCQPRegreso.at(0);
}
