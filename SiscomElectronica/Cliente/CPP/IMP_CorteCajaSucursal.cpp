#include <IMP_CorteCajaSucursal.h>
#include <IMP_CambioEnCaja.h>

#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zCambioCaja.h>
#include <zCorteCajaO.h>
#include <zCajas.h>
#include <zCaja.h>

#include <QtCorteCajaImp.h>

#include <qpushbutton.h>

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
QtCCaja->IniciaControl(1,0);
}

void QCorteCajaSucursal::ConectaSlots()
{
connect(QtCCaja,
	SIGNAL(SignalCapturoCantidadDenominacion()),
	SLOT(SlotCapturoCantidad()));
connect(QtCCaja,
	SIGNAL(SignalActualizaImporteGasto()),SLOT(SlotActualizaCorteCaja()));
connect(QtCCaja,SIGNAL(SignalPagoTarjeta()),SLOT(SlotActualizaCorteCaja()));
connect(QPBRegCambio,SIGNAL(clicked()),SLOT(SlotRegistraCambio()));
connect(QPBRealizarC,SIGNAL(clicked()),SLOT(SlotRegistraCorte()));
connect(QPBActualizar,SIGNAL(clicked()),SLOT(SlotActualiza()));
}
void QCorteCajaSucursal::SlotActualiza()
{
  RegistrandoCorteDia();
}
void QCorteCajaSucursal::SlotRegistraCorte()
{
	SeleccionaCambioCaja();   
	RegistrandoCorteDia();

	HabilitaDesHabilitaRegistroCambio(false);
}
void QCorteCajaSucursal::SlotRegistraCambio()
{
     RegistrandoCambio();

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
   HabilitaDesHabilitaRegistroCambio(true);
}
void QCorteCajaSucursal::HabilitaDesHabilitaRegistroCambio(bool pbEstado)
{
   QPBRegCambio->setEnabled(pbEstado);
}
void QCorteCajaSucursal::CalculandoCorteCaja()
{
zSiscomElectronica lzSisElectro(zSisConexion,"CalculaCorteCaja");
lzSisElectro.CalculaCorteCaja(QtCCaja->Cajas());
}
void QCorteCajaSucursal::RegistraCambio()
{
zSiscomElectronica lzSisElec(zSisConexion,"RegistraCambioCaja");
lzSisElec.RegistraCambioCaja(QtCCaja->Cajas());
}
void QCorteCajaSucursal::RegistrandoCambio()
{
   RegistraCambio();
   QPBRegCambio->setEnabled(false);
}
void QCorteCajaSucursal::HabilitaDesHabilitaControles(bool pbEstado)
{

}
void QCorteCajaSucursal::SeleccionaCambioCaja()
{
QCambioEnCaja lQCambioC;
zCambioCaja *lzCambioC;
if((lzCambioC=lQCambioC.CambioCaja()))
 ConsultandoCambioCaja(lzCambioC);


}
void QCorteCajaSucursal::ConsultandoCambioCaja(zCambioCaja *pzCambioC)
{
    ConsultaCambioCaja(pzCambioC);
    ActualizaCambioCaja(pzCambioC);
}
void QCorteCajaSucursal::ConsultaCambioCaja(zCambioCaja *pzCambioC)
{
zSiscomElectronica lzSiscomE(zSiscomDesarrollo4::Conexion(),"ConsultaCambioCaja");
lzSiscomE.CambioCaja(pzCambioC);
}
void QCorteCajaSucursal::ActualizaCambioCaja(zCambioCaja *pzCambioC)
{
QtCCaja->ActualizaTotalCajaCambio(pzCambioC->Importe());
QtCCaja->ActualizaCantidadesCambio(pzCambioC->Dinero());
QtCCaja->ActualizandoGui();
}

void QCorteCajaSucursal::RegistrosDia()
{
zCorteCajaO lzCorteCO(zSiscomDesarrollo4::Conexion(),"RegistraCorteCaja");
lzCorteCO.RealizaCorte("",&zCCaja);
}
zCorteCaja &QCorteCajaSucursal::CorteCaja()
{
 return  zCCaja;
}
void QCorteCajaSucursal::ImportesDia()
{
  QtCCaja->Cajas()->Principal()->Transferencias(CorteCaja().Transferencias());
  QtCCaja->Cajas()->Principal()->TotalEfectivo(CorteCaja().DineroEntroCaja());
  QtCCaja->ActualizandoGui();
}
void QCorteCajaSucursal::RegistrandoCorteDia()
{
  RegistrosDia();
  ImportesDia();
}
