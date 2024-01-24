#include <IMP_CorteCajaSucursal.h>


#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>


#include <QtCorteCajaImp.h>
QCorteCajaSucursal *InstanciaCorteCajaSucursal(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QCorteCajaSucursal((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QCorteCajaSucursal::QCorteCajaSucursal(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				CorteCajaSucursal(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)
{
IniciaVariables();
ConectaSlots();
}

QCorteCajaSucursal::~QCorteCajaSucursal()
{

}

void QCorteCajaSucursal::IniciaVariables()
{

QtCCaja->setNumRows(25);
QtCCaja->setNumCols(15);
QtCCaja->IniciaControl(1,1);
}

void QCorteCajaSucursal::ConectaSlots()
{
connect(QtCCaja,
	SIGNAL(SignalCapturoCantidadDenominacion()),
	SLOT(SlotCapturoCantidad()));
connect(QtCCaja,
	SIGNAL(SignalActualizaImporteGasto()),SLOT(SlotActualizaCorteCaja()));
connect(QtCCaja,SIGNAL(SignalPagoTarjeta()),SLOT(SlotActualizaCorteCaja()));
}
void QCorteCajaSucursal::SlotActualizaCorteCaja()
{
   CalculandoCorteCaja();
   QtCCaja->ActualizandoGui();
}
void QCorteCajaSucursal::SlotCapturoCantidad()
{
   CalculandoCorteCaja();
   QtCCaja->ActualizandoGui();
}
void QCorteCajaSucursal::CalculandoCorteCaja()
{
zSiscomElectronica lzSisElectro(zSisConexion,"CalculaCorteCaja");
lzSisElectro.CalculaCorteCaja(QtCCaja->Cajas());
}
