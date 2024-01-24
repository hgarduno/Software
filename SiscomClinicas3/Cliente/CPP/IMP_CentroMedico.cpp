#include <IMP_CentroMedico.h>
#include <IMP_ObservacionesConsulta.h>
#include <IMP_RecetasConsulta.h>
#include <IMP_Expedientes.h>
#include <IMP_BuscaPersonas.h>
#include<SISCOMComunicaciones++.h>
#include <Seguridad3Protocolo2.h>
#include <QCtrlServicios.h>
#include <QCtrlPrecios.h>
#include <QCtrlCotizas.h>
#include <QCtrlRecetas.h>
#include <QSisEstsMedico.h>
#include <CQSisConsultas.h>
#include <CQSisObjetos.h>
#include <CQSisServicios.h>
#include <CQSisEstadoConsulta.h>
#include <CQSisProdCotiza.h>
#include <CQSisBuscaPersonas.h>
#include <CQSisPersonas.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>
#include <qmessagebox.h>
QCentroMedico::QCentroMedico(CQSisConsulta *pCQSConsulta,
				SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				CentroMedico(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				QWParent(pQWParent),
				CQSConsulta(pCQSConsulta),
				intRecetas(0),
				intObservaciones(0)
{
IniciaVariables();
ConectaSlots();
IniciaPrecios();
RecetasObservaciones();
}
QCentroMedico::~QCentroMedico()
{

	EliminaConsultaActual();
}
void QCentroMedico::show()
{
char lchrArrPaciente[150];
	CQSisObjetos::NombreCompleto(CQSConsulta->Paciente(),
				     lchrArrPaciente);
	QLEPaciente->setText(lchrArrPaciente);
	CotizaPerfilMedico();
	CotizandoConsulta();
	HabilitaTerminar();
	QWidget::show();
}
void QCentroMedico::ConectaSlots()
{
	connect(QPBOConsulta,
		SIGNAL(clicked()),
		SLOT(SlotObservaciones()));
	connect(QCtrSMedico,
		SIGNAL(SignalServicio(CQSisServicio *)),
		SLOT(SlotServicioMedico(CQSisServicio *)));
	connect(QCtrSGenerales,
		SIGNAL(SignalServicio(CQSisServicio *)),
		SLOT(SlotServicioGeneral(CQSisServicio *)));
	connect(QCtrPrecios,
		SIGNAL(SignalPrecio(CQSisPrecio *)),
		SLOT(SlotPrecio(CQSisPrecio *)));
	connect(QPBTerminar,
		SIGNAL(clicked()),
		SLOT(SlotTerminaConsulta()));
	connect(QPBReceta,
		SIGNAL(clicked()),
		SLOT(SlotReceta()));
	connect(QCtrCFarmacia,
		SIGNAL(SignalCotizacion(CQSisCliente *,
				    CQSisFormaPago *,
				    CQSisPrecio *,
				    CQSisProducto *,
				    CQSisProdCotiza *,
				    CQSisContacto *)),
		SLOT(SlotCotiza(CQSisCliente *,
				CQSisFormaPago *,
				CQSisPrecio *,
				CQSisProducto *,
				CQSisProdCotiza *,
				CQSisContacto *)));
	 connect(QPBAnexar,
	 	SIGNAL(clicked()),
		SLOT(SlotAnexarProductoFarmacia()));
	connect(QPBExpediente,
		SIGNAL(clicked()),
		SLOT(SlotExpediente()));
	connect(QTDetalle,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionandoDetalle(int,int,int,const QPoint &)));
	connect(QPBEliminar,
		SIGNAL(clicked()),
		SLOT(SlotEliminarServicio()));
}
void QCentroMedico::SlotEliminarServicio()
{
	if(CQSLCotizando.count())
	{
	CQSLCotizando.remove(intProdServSeleccionado);	
	CotizandoConsulta();
	HabilitaTerminar();
	SiscomAjustaFilas(QTDetalle);
	}
 else
 QMessageBox::information(
 		this,
		"Siscom Clinicas3",
		"El medico no tiene un paciente en consulta");
}
void QCentroMedico::SlotSeleccionandoDetalle(int pintNDetalle,
					     int,
					     int,
					     const QPoint &)
{
	if(pintNDetalle!=-1)
	{
	 intProdServSeleccionado=pintNDetalle;
	 QTDetalle->selectRow(pintNDetalle);
	}
}
void QCentroMedico::SlotExpediente()
{
 if(CQSConsulta)
 Expedientes(CQSConsulta->Paciente());
 else
 QMessageBox::information(
 		this,
		"Siscom Clinicas3",
		"El medico no tiene un paciente en consulta");
}
void QCentroMedico::SlotAnexarProductoFarmacia()
{

	CQSLCotizando << Servicio(CQSPCFarmacia);	
	CotizandoConsulta();
	HabilitaTerminar();
	SiscomAjustaFilas(QTDetalle);
	QCtrCFarmacia->setFocus();

}
void QCentroMedico::SlotCotiza(CQSisCliente *,
			       CQSisFormaPago *,
			       CQSisPrecio *,
			       CQSisProducto *,
			       CQSisProdCotiza *pCQSPCProducto,
			       CQSisContacto *)
{
int lintSePuedeVender;
lintSePuedeVender=!strcmp((*pCQSPCProducto)["SePuedeVender"],"Si");
QPBAnexar->setEnabled(lintSePuedeVender);
if(lintSePuedeVender)
{
CQSPCFarmacia=pCQSPCProducto;
SiscomPasaFocoControl(QPBAnexar);
}

}
void QCentroMedico::SlotReceta()
{
	if(CQSConsulta)
	QRecetasConsulta lQRConsulta(
				CQSConsulta,
				SisDatCom,
				chrPtrArgumentos,
				0);
 else
 QMessageBox::information(
 		this,
		"Siscom Clinicas3",
		"El medico no tiene un paciente en consulta");
HabilitaTerminar();
}
void QCentroMedico::SlotTerminaConsulta()
{
	TerminaConsulta();
	emit SignalTerminar(this);
}
void QCentroMedico::SlotPrecio(CQSisPrecio *pCQSPrecio)
{
	CQSPrecio=pCQSPrecio;
}
void QCentroMedico::SlotServicioGeneral(CQSisServicio *pCQSServicio)
{
	CQSLCotizando << Servicio(pCQSServicio);	
	CotizandoConsulta();
	HabilitaTerminar();
	SiscomAjustaFilas(QTDetalle);
}
void QCentroMedico::SlotServicioMedico(CQSisServicio *pCQSServicio)
{
	CQSLCotizando << Servicio(pCQSServicio);
	CotizandoConsulta();
	HabilitaTerminar();
	SiscomAjustaFilas(QTDetalle);
}
void QCentroMedico::SlotObservaciones()
{
if(CQSConsulta)
QObservacionesConsulta lQOConsulta(
		CQSConsulta,
		SisDatCom,
		chrPtrArgumentos,
		0);
 else
 QMessageBox::information(
 		this,
		"Siscom Clinicas3",
		"El medico no tiene un paciente en consulta");
HabilitaTerminar();
}
void QCentroMedico::IniciaServicios()
{
	QCtrSGenerales->PonServidor(SisDatCom);
	QCtrSGenerales->TipoServicio("ServiciosGenerales");
	QCtrSGenerales->IdMedico("");
	QCtrSGenerales->IniciaControl();

	QCtrSMedico->PonServidor(SisDatCom);
	QCtrSMedico->TipoServicio("ServiciosMedico");
	QCtrSMedico->IdMedico((*SUSeg3Firmado)["IdPersona"]);
	QCtrSMedico->IniciaControl();

}
void QCentroMedico::IniciaVariables()
{
	SUSeg3Firmado=(SisUsuarioSeg3 *)chrPtrArgumentos[0];
	IniciaServicios();
	QCtrCFarmacia->PonServidor(SisDatCom);
	QCtrCFarmacia->IniciaControl();

}
void QCentroMedico::MuestraCotizacion()
{
CQSisCotizando *lCQSCotizando;
int lintContador;
int lintNumRegistros;
lintNumRegistros=CQSLCotizando.count();
QTDetalle->setNumRows(lintNumRegistros);
for(lCQSCotizando=CQSLCotizando.first(),
    lintContador=0;
    lintContador<lintNumRegistros;
    lCQSCotizando=CQSLCotizando.next(),
    lintContador++)
SiscomAnexarRegistroALaTabla(
	lintContador,
	QTDetalle,
	QStringList() <<
	(*lCQSCotizando)["Clave"] 		<<
	(*lCQSCotizando)["Descripcion"]		<<
	(*lCQSCotizando)["Cantidad"]		<<
	(*lCQSCotizando)["Precio"]		<<
	(*lCQSCotizando)["Importe"]);
SiscomAjustaColumnas(QTDetalle);
QLCDNTConsulta->display(CQSLCotizando.ImporteTotal());
}
void QCentroMedico::CotizandoConsulta()
{
CotizaConsulta();
MuestraCotizacion();
}
void QCentroMedico::CotizaConsulta()
{
CQSisOpCotizando lCQSOCotizando(SisDatCom);
lCQSOCotizando.CotizaConsulta(&CQSLCotizando);
}
void QCentroMedico::IniciaPrecios()
{
QCtrPrecios->PonServidor(SisDatCom);
QCtrPrecios->IniciaControl();
}
CQSisCotizando *QCentroMedico::Servicio(CQSisServicio *pCQSServicio)
{

return new CQSisCotizando(
		(*pCQSServicio)["IdServicio"],
		"",
		"",
		(*SUSeg3Firmado)["IdPersona"],
		(*CQSPrecio)["IdPrecio"],
		"",
		"",
		"1",
		"",
		"");
}
CQSisCotizando *QCentroMedico::Servicio(CQSisProdCotiza *pCQSPCotiza)
{

return new CQSisCotizando(
		(*pCQSPCotiza)["IdProducto"],
		"",
		"",
		(*SUSeg3Firmado)["IdPersona"],
		(*CQSPrecio)["IdPrecio"],
		"",
		"",
		(*pCQSPCotiza)["Cantidad"],
		"",
		"");
}
void QCentroMedico::CotizaPerfilMedico()
{
CQSisOpCotizando lCQSOCotizando(SisDatCom);
lCQSOCotizando.CotizaPerfilMedico((*SUSeg3Firmado)["IdPersona"],
				  (*CQSPrecio)["IdPrecio"],
				  &CQSLCotizando);
QLCDNTConsulta->display(CQSLCotizando.ImporteTotal());
}
void QCentroMedico::TerminaConsulta()
{
CQSisOpEstadoConsulta lCQSOEConsulta(SisDatCom);
lCQSOEConsulta.TerminaConsulta((*CQSConsulta)["IdConsulta"],
				&CQSLCotizando);
}
void QCentroMedico::EliminaConsultaActual()
{

	QTDetalle->setNumRows(0);
	CQSLCotizando.setAutoDelete(true);
	CQSLCotizando.clear();
	CQSLCotizando.setAutoDelete(false);
	CQSConsulta=0;

}
void QCentroMedico::HabilitaBotones()
{

}
void QCentroMedico::Expedientes(CQSisPersona *pCQSPersona)
{

	QExpediente=new QExpedientes(SisDatCom,
				     chrPtrArgumentos,
				     QWParent);
	QExpediente->Paciente(pCQSPersona);
	QExpediente->Expediente();
	connect(QExpediente,
		SIGNAL(SignalCerroExpediente(CQSisPersona *)),
		SLOT(SlotCerroExpediente(CQSisPersona *)));
}
void QCentroMedico::SlotCerroExpediente(CQSisPersona *)
{
	delete QExpediente;
}
void QCentroMedico::HabilitaTerminar()
{
RecetasObservaciones();
	QPBTerminar->setEnabled(CQSLCotizando.count() &&
	                        intRecetas	      &&
				intObservaciones);
}
void QCentroMedico::RecetasObservaciones()
{
intObservaciones=QObservacionesConsulta::HayObservaciones(
					  SisDatCom,
					  (*CQSConsulta)["IdConsulta"]);
intRecetas=QCtrlRecetas::HayRecetas(SisDatCom,
				    (*CQSConsulta)["IdConsulta"]);
}
