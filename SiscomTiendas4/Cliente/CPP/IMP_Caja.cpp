#include <IMP_Caja.h>
#include <IMP_Ventas.h>
#include<SiscomDesarrollo3Qt++.h>
#include <IMP_QControlFecha.h>
#include <QCtrlOrdenes.h>
#include <CQSisEmpresas.h>
#include <CQSisOrdenes.h>
#include <CQSisOrVendidas.h>
#include <CQSisProductos.h>
#include <CQSisEmpleados.h>
#include <CQSisClientes.h>
#include <CQSisVentas.h>

#include <qpushbutton.h>
#include <qlcdnumber.h>
QCaja *InstanciaCaja(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QCaja((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QCaja::QCaja(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Caja(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				QWParent(pQWParent)

{
IniciaVariables();
ConectaSlots();
}

QCaja::~QCaja()
{

}

void QCaja::ConectaSlots()
{

	connect(QPBOrdenes,
		SIGNAL(clicked()),
		SLOT(SlotOrdenes()));
	connect(QCtrOrdenes,
		SIGNAL(SignalOrden(CQSisOrden *)),
		SLOT(SlotOrden(CQSisOrden *)));
	connect(QPBMOrden,
		SIGNAL(clicked()),
		SLOT(SlotMOrden()));
	connect(QPBRVenta,
		SIGNAL(clicked()),
		SLOT(SlotRegistraVenta()));
	connect(QCtrFechaIni,
		SIGNAL(Signal_EnterA_o()),
		SLOT(SlotPasaFocoFechaFin()));

	connect(QCtrFechaFin,
		SIGNAL(Signal_EnterA_o()),
		SLOT(SlotPasaFocoOrdenes()));

}
void QCaja::SlotPasaFocoFechaFin()
{
	
QCtrFechaFin->setFocus();
}
void QCaja::SlotPasaFocoOrdenes()
{
SiscomPasaFocoControl(QPBOrdenes);
}
void QCaja::SlotRegistraVenta()
{
RegistraVenta();
}
void QCaja::SlotMOrden()
{
	QVOrden=new QVentas(SisDatCom,
			chrPtrArgumentos,
			CQSOrden,
			&CQSLPCotiza,
			QWParent);
	connect(QVOrden,
		SIGNAL(SignalRealizoOperacion(QVentas *)),
		SLOT(SlotRealizoOperacion(QVentas *)));
}
void QCaja::SlotRealizoOperacion(QVentas *pQVentas)
{
   delete pQVentas;
   SlotOrdenes();
   ConsultandoOrden();
}
void QCaja::SlotOrden(CQSisOrden *pCQSOrden)
{
	CQSOrden=pCQSOrden;
	ConsultandoOrden();
}
void QCaja::IniciaVariables()
{
	QCtrFechaIni->ColocaFechaHoy();
	QCtrFechaFin->ColocaFechaHoy();
	QCtrFechaIni->setFocus();
	HabilitaBotones();
	CQSEmpleado=(CQSisEmpleado *)chrPtrArgumentos[0];
	/*
	IniciaSistemaSeguridad3();
	*/
}
void QCaja::SlotOrdenes()
{
QCtrOrdenes->PonRangoFecha(strdup((const char *)QCtrFechaIni->ObtenFecha()),
			   strdup((const char *)QCtrFechaFin->ObtenFecha()));
QCtrOrdenes->PonServidor(SisDatCom);
QCtrOrdenes->PonExpendio(new CQSisEmpresa("0",""));
QCtrOrdenes->PonEdoVenta("1");
QCtrOrdenes->IniciaControl();
}
void QCaja::ConsultandoOrden()
{
	ConsultaOrden();
	MuestraOrden();
}
void QCaja::ConsultaOrden()
{
CQSisOpOrdenes lCQSOOrdenes(SisDatCom);
		lCQSOOrdenes.Orden(
			CQSOrden->SRegistrosPro2["IdVenta"],
			new CQSisEmpresa("0",""),
			CQSOrden->FormaPago(),
			CQSOrden->Cliente(),
			new CQSisEmpleado(new SisPersona("","","","")),
			&CQSLPCotiza);
HabilitaBotones();
}

void QCaja::MuestraOrden()
{
CQSisProdCotiza *lCQSPCotiza;
int lintNFilas=CQSLPCotiza.count()-1;
int lintContador;
	QTDatos->setNumRows(lintNFilas);
	for(lintContador=0,
	    lCQSPCotiza=CQSLPCotiza.first();
	    lintContador<lintNFilas;
	    lintContador++,
	    lCQSPCotiza=CQSLPCotiza.next())
	 SiscomAnexarRegistroALaTabla(
	 	lintContador,
		QTDatos,
		QStringList()						<<
		lCQSPCotiza->Producto()->SRegistrosPro2["Clave"]	<<
		lCQSPCotiza->SRegistrosPro2["Cantidad"]			<<
		lCQSPCotiza->SRegistrosPro2["Precio"]			<<
		lCQSPCotiza->SRegistrosPro2["Total"]);
QLCDNTotal->display(lCQSPCotiza->SRegistrosPro2["Total"]);
SiscomAjustaColumnas(QTDatos);
}
void QCaja::RegistraVenta()
{
CQSisProdCotiza *lCQSPCotiza;
for(lCQSPCotiza=CQSLPCotiza.first();
    lCQSPCotiza;
    lCQSPCotiza=CQSLPCotiza.next())
 lCQSPCotiza->SiscomActualizaCampo("EdoVenta","3");

CQSisOpVenta lCQSOVenta(SisDatCom);
lCQSOVenta.RegistraVenta(&CQSLPCotiza);
CQSLPCotiza.setAutoDelete(true);
CQSLPCotiza.clear();
CQSLPCotiza.setAutoDelete(false);
QTDatos->setNumRows(0);
SlotOrdenes();
HabilitaBotones();
}
void QCaja::HabilitaBotones()
{

	if(intSePuedeMOrden)
	QPBMOrden->setEnabled(CQSLPCotiza.count());
	QPBRVenta->setEnabled(CQSLPCotiza.count());

}
void QCaja::IniciaSistemaSeguridad3()
{
Seguridad3Protocolo2 lS3Protocolo2(getenv("Aplicacion"),
				   (*CQSEmpleado)["IdPerfil"],
				   SisDatCom,
				   (Caja *)this);
intSePuedeMOrden=QPBMOrden->isEnabled();
}
void QCaja::closeEvent(QCloseEvent *)
{
 emit SignalTerminar(this);
}
