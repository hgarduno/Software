#include <IMP_ChoferYVehiculo.h>
#include <Vehiculos.h>
#include <Pedidos.h>
#include <Personas.h>
#include <Choferes.h>
#include <CQSiscomCom.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

QChoferYVehiculo::QChoferYVehiculo(const char *pchrPtrIdChoferes,
			        const char *pchrPtrFechaIni,
				const char *pchrPtrFechaFin,
				CSISCOMDatComunicaciones *pCSisDatCom,
				   QWidget* parent, const char* name, bool modal, WFlags fl )
    : ChoferYVehiculo( parent, name, modal, fl ),
	CSisDatCom(pCSisDatCom),
	QWParent(parent),
	chrPtrIdChoferes(pchrPtrIdChoferes),
	chrPtrFechaIni(pchrPtrFechaIni),
	chrPtrFechaFin(pchrPtrFechaFin)

{
	ConectaSlots();
	IniciaVariables();
	exec();
}

QChoferYVehiculo::~QChoferYVehiculo()
{
}

void QChoferYVehiculo::IniciaVariables()
{
	QLECChofer=ColocaLineEditAlCombo(QCBChofer,"QLECChofer");
	QLECPlacas=ColocaLineEditAlCombo(QCBVehiculo,"QLECPlacas");
	PasaFocoControl(QLECPlacas);
	CQSVehiculo=new CQSeleccionaVehiculo(CSisDatCom,
					     QWParent,
					     "CQSVehiculo",
					     QLECPlacas,
					     QLEDescripcion,
					     QCBVehiculo); 
	
	CQSChofer=new CQSeleccionaChoferes(chrPtrIdChoferes,
					 CSisDatCom,
					 QWParent,
					 "CQSChoferes",
					 QLECChofer,
					 QLENmbCompleto,
					 QCBChofer);
	connect(CQSVehiculo,
		SIGNAL(Signal_Vehiculo(Vehiculo *)),
		SLOT(S_Vehiculo(Vehiculo *)));
	connect(CQSChofer,
		SIGNAL(Signal_Chofer(Chofer *)),
		SLOT(S_Chofer(Chofer *)));


	QPBSeleccionar->setEnabled(false);

				

}
void QChoferYVehiculo::S_Chofer(Chofer *pChofer)
{
	C_Chofer=pChofer;
	PasaFocoControl(QPBSeleccionar);
	QPBSeleccionar->setEnabled(C_Chofer && V_Vehiculo);
}
Chofer *QChoferYVehiculo::ObtenChofer()
{
	return C_Chofer;
}
void QChoferYVehiculo::ConectaSlots()
{
	connect(QPBSeleccionar,
		SIGNAL(clicked()),
		SLOT(S_Seleccionar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));
}
void QChoferYVehiculo::S_Cancelar()
{

	BTN_Seleccion=QChoferYVehiculo::BTN_Cancelar;
	done(1);

}
void QChoferYVehiculo::S_Seleccionar()
{
	BTN_Seleccion=QChoferYVehiculo::BTN_Aceptar;
	done(1);
}
void QChoferYVehiculo::S_Vehiculo(Vehiculo *pVehiculo)
{
	if((V_Vehiculo=pVehiculo))
	{
	PasaFocoControl(QLECChofer);
	PedidosAsignadosAlVehiculo();
	}

}
void QChoferYVehiculo::PedidosAsignadosAlVehiculo()
{
CQPedidos lCQPedidos;
Pedido *lP_Pedido;
CQCtrPedidos lCQCPVehiculos(CSisDatCom,
			    CQCtrPedidos::PedidosDelVehiculo,
			    QStringList() << 
			    "ObtenPedidosDelVehiculo" 	  <<
			    V_Vehiculo->ObtenIdVehiculo() <<
			    chrPtrFechaIni			  <<
			    chrPtrFechaFin,
			    &lCQPedidos);
	QTVehiculoPedido->setNumRows(0);
	for(lP_Pedido=lCQPedidos.first();
	    lP_Pedido;
	    lP_Pedido=lCQPedidos.next())
	 AnexarRegistroALaTabla(QTVehiculoPedido,
			       QStringList()                                     <<
                                  QString(lP_Pedido->ObtenCliente()->ObtenNombre()) +
                                  " "                                               +
                                  lP_Pedido->ObtenCliente()->ObtenAPaterno()        +
                                  " "                                               +
                                  lP_Pedido->ObtenCliente()->ObtenAMaterno()        <<
                                  lP_Pedido->ObtenNumPedido()                       <<
                                  lP_Pedido->ObtenImporteDelPedido()); 



}
Vehiculo *QChoferYVehiculo::ObtenVehiculo()
{
	return V_Vehiculo;

}
QChoferYVehiculo::BTN_Opciones QChoferYVehiculo::ObtenSeleccion()
{
	return BTN_Seleccion;
}
