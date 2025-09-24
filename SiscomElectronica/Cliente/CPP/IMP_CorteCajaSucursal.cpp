#include <IMP_CorteCajaSucursal.h>
#include <IMP_DatosCorteCaja.h>
#include <IMP_QControlFecha.h>

#include <zSiscomQt3.h>

#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zCambioCaja.h>
#include <zCorteCajaO.h>
#include <zCajas.h>
#include <zCaja.h>
#include <zCeldaCambioDiaAnterior.h>

#include <QtCorteCajaImp.h>

#include <qpushbutton.h>
#include <qmessagebox.h>

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
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				intRegistroC(0)
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
IniciandoFechas();
CorteCaja().Cajas(QtCCaja->Cajas());
}
void QCorteCajaSucursal::IniciandoFechas()
{
QCFInicio->ColocaFechaHoy();
QCFFinal->ColocaFechaHoy();
zSiscomQt3::Foco(QCFInicio);
}
void QCorteCajaSucursal::ConectaSlots()
{
connect(QtCCaja,
	SIGNAL(SignalCapturoCantidadDenominacion()),
	SLOT(SlotCapturoCantidad()));
connect(QtCCaja,
	SIGNAL(SignalActualizaImporteGasto()),SLOT(SlotActualiza()));
connect(QtCCaja,SIGNAL(SignalPagoTarjeta()),SLOT(SlotActualiza()));
connect(QPBRegCambio,SIGNAL(clicked()),SLOT(SlotRegistraCambio()));
connect(QPBSCambio,SIGNAL(clicked()),SLOT(SlotSeleccionaCambio()));
connect(QPBActualizar,SIGNAL(clicked()),SLOT(SlotActualiza()));

connect(QCFInicio,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAFFin()));
connect(QCFFinal,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAActualiza()));
connect(QPBRegistraCorte,SIGNAL(clicked()),SLOT(SlotRegistraCorte()));
}
void QCorteCajaSucursal::SlotRegistraCorte()
{
RegistraCorte();
intRegistroC=1;
 QPBRegistraCorte->setEnabled(false);
}
void QCorteCajaSucursal::SlotRegistraCambio()
{
 RegistraCambio();
 HabilitaDesHabilitaRegistroCambio(false);

/* QPBSCambio->setEnabled(false); */
 QPBRegistraCorte->setEnabled(true);
 QPBActualizar->setEnabled(true);
}
void QCorteCajaSucursal::SlotFocoAFFin()
{
zSiscomQt3::Foco(QCFFinal);
}
void QCorteCajaSucursal::SlotFocoAActualiza()
{
 zSiscomQt3::Foco(QPBActualizar);
}
void QCorteCajaSucursal::SlotActualiza()
{
   CalculandoCorteCaja();
  ImportesDia();
}
void QCorteCajaSucursal::SlotSeleccionaCambio()
{
	SeleccionaCambioCaja();   
	CambioDiaAnterior();
	HabilitaDesHabilitaRegistroCambio(false);
}
void QCorteCajaSucursal::SlotActualizaCorteCaja()
{
   CalculandoCorteCaja();
   QtCCaja->ActualizandoGui();
}
void QCorteCajaSucursal::SlotCapturoCantidad()
{
   CalculandoCorteCaja();
   ImportesDia();
   HabilitaDesHabilitaRegistroCambio(CorteCaja().EdoCuentaCambioInt());
   QtCCaja->ActualizandoGui();
}
void QCorteCajaSucursal::HabilitaDesHabilitaRegistroCambio(bool pbEstado)
{
   QPBRegCambio->setEnabled(pbEstado);
}
void QCorteCajaSucursal::CalculandoCorteCaja()
{
zSiscomElectronica lzSisElectro(zSisConexion,"CalculaCorteCaja");
CorteCaja().FechaInicio(QCFInicio->ObtenFecha());
CorteCaja().FechaFin(QCFFinal->ObtenFecha());
lzSisElectro.CalculaCorteCaja(&CorteCaja());
}
void QCorteCajaSucursal::RegistraCambio()
{
zSiscomElectronica lzSisElec(zSisConexion,"RegistraCambioCaja");
lzSisElec.RegistraCambioCaja(QtCCaja->Cajas());
}
void QCorteCajaSucursal::RegistrandoCambio()
{
   RegistraCambio();
}
void QCorteCajaSucursal::HabilitaDesHabilitaControles(bool pbEstado)
{

}
void QCorteCajaSucursal::SeleccionaCambioCaja()
{
QDatosCorteCaja lQCambioC;
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
QtCCaja->ActualizaCambioDiaAnterior(pzCambioC->Importe());
CorteCaja().CambioDiaAnterior(pzCambioC->Importe());
QtCCaja->ActualizandoGui();
}

void QCorteCajaSucursal::CambiosRegistrados()
{
zCorteCajaO lzCorteCO(zSiscomDesarrollo4::Conexion(),"CambiosRegistrados");
lzCorteCO.CambiosRegistrados((const char *)QCFInicio->ObtenFecha(),
		       (const char *)QCFFinal->ObtenFecha(),
		       &zCCaja);
}
zCorteCaja &QCorteCajaSucursal::CorteCaja()
{
 return  zCCaja;
}
void QCorteCajaSucursal::ImportesDia()
{
 SiscomRegistroLog2(&CorteCaja());
  QtCCaja->Cajas()->Principal()->Transferencias(CorteCaja().Transferencias());
  QtCCaja->Cajas()->Principal()->PagoTarjeta(CorteCaja().Tarjeta());
  QtCCaja->Cajas()->Principal()->TotalEfectivo(CorteCaja().DineroEntroCaja());
  QtCCaja->Cajas()->Principal()->VentasTotales(CorteCaja().VentasTotales());
  QtCCaja->Cajas()->Principal()->CalculandoCorte(CorteCaja().CalculandoCorte());
  QtCCaja->Cajas()->Principal()->TotalGastos(CorteCaja().TotalGastos());
  QtCCaja->Cajas()->Principal()->CorteTotal(CorteCaja().CorteTotal());
  QtCCaja->ActualizandoGui();
}
void QCorteCajaSucursal::CambioDiaAnterior()
{
  CambiosRegistrados();
  ImportesDia();
}

void QCorteCajaSucursal::RegistraCorte()
{
  zCorteCajaO lzCorteCO(zSiscomDesarrollo4::Conexion(),"RegistraCorteCajaSucursal");
  lzCorteCO.RegistraCorte(&CorteCaja());
}

void QCorteCajaSucursal::closeEvent(QCloseEvent *pQCEvent)
{
   if(!intRegistroC)
   QMessageBox::information(this,
   			    "Aviso Sistema",
			    "No Se Ha Registrado el CORTE");
    else
	pQCEvent->accept();
}
