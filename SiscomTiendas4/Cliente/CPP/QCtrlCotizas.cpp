#include <QCtrlCotizas.h>
#include <QCtrlPrecios.h>
#include <QCtrlClientes.h>
#include <QCtrlContactos.h>
#include <QCtrlFormaPago.h>
#include <QCtrlProductos.h>
#include <SISCOMComunicaciones++.h>
#include <CQSisCotizas.h>
#include <CQSisClientes.h>
#include <CQSisProdCotiza.h>
#include <CQSisEmpresas.h>
#include <CQSisContactos.h>
#include <CQSisEmpleados.h>
#include <qlayout.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qlcdnumber.h>


QCtrlCotizas::QCtrlCotizas( QWidget *parent, const char *name )
    : QWidget( parent, name ),
		CQSCliente(0),
		CQSProducto(0),
		CQSFPago(0),
		CQSPrecio(0),
		CQSContacto(0)
{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlCotizas::IniciaVariables()
{
	IniciaInterfaz();

}
void QCtrlCotizas::IniciaInterfaz()
{
QVBoxLayout *lQVBLayout;

QHBoxLayout *lQHBLResultados;
	QGLRegilla=new QGridLayout(this,3,1,5,5,"QGLRegilla");	
	QSHECliCoFPago=new QSisHEspacio(0,5,5,"QSHECliCoFPago");
	QSHEPreProCaImp=new QSisHEspacio(0,5,5,"QSHECliCoFPago");
	QSHEPreProImpProd=new QSisHEspacio(0,5,5,"QSHEPreProImpProd");
	lQVBLayout=new QVBoxLayout(0,0,-1,"lQVBLayout");
	QVBLDisplays=new QVBoxLayout(0,0,-1,"QVBLDisplays");
	lQHBLResultados=new QHBoxLayout(0,0,-1,"lQHBLResultados");
	(*QSHECliCoFPago)+=Clientes();
	(*QSHECliCoFPago)+=Contactos();
	(*QSHECliCoFPago)+=FormaPago();
	(*QSHEPreProCaImp)+=Precios();
	(*QSHEPreProCaImp)+=Productos();
	(*QSHEPreProCaImp)+=SiscomCreaEspacioVerticalEtiquetaEdit(
				this,
				"QVBLCantidad",
				"Cantidad",
				"QLECantidad",
				&QLECantidad,
				&QLCantidad);
	(*QSHEPreProCaImp)+=SiscomCreaEspacioVerticalEtiquetaEdit(
				this,
				"QVBLPImporte",
				"Importe",
				"QLEPImporte",
				&QLEPImporte,
				&QLImporte);

	QLEPImporte->setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));
	QLECantidad->setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));

	(*QSHEPreProImpProd)+=CreaDisplayEtiqueta(
				"QLPreProducto",
				"Precio Producto",
				"QLCDNPrecio",
				&QLCDNPrecio,
				&QLPreProducto);
		
	(*QSHEPreProImpProd)+=CreaDisplayEtiqueta(
				"QLImProducto",
				"Importe Producto",
				"QLCDNImporte",
				&QLCDNImporte,
				&QLImProducto);
	
	QVBLDisplays->addItem(CreaDisplayEtiqueta(
			      "QLExistencia",
			      "Existencia",
			      "QLCDNExistencia",
			      &QLCDNExistencia,
			      &QLExistencia));
	QVBLDisplays->addItem(QSHEPreProImpProd);
	QVBLDisplays->addItem(CreaDisplayEtiqueta(
			      "QLTOrden",
			      "Total",
			      "QLCDNTotal",
			      &QLCDNTotal,
			      &QLTotal));

	lQHBLResultados->addItem(ClienteDescripcion());	
	lQHBLResultados->addItem(QVBLDisplays); 
	QGLRegilla->addItem(QSHECliCoFPago,0,0);
	QGLRegilla->addItem(QSHEPreProCaImp,1,0);
	QGLRegilla->addItem(lQHBLResultados,2,0);
}

void QCtrlCotizas::IniciaControles()
{
	QCtrClientes->PonServidor(SisDatCom);
	QCtrFPago->PonServidor(SisDatCom);
	QCtrPrecios->PonServidor(SisDatCom);
	QCtrProductos->PonServidor(SisDatCom);
	QCtrClientes->IniciaControl();
	QCtrFPago->IniciaControl();
	QCtrPrecios->IniciaControl();
	QCtrProductos->IniciaControl();


}
void QCtrlCotizas::MuestraCotizas()
{
}
void QCtrlCotizas::IniciaControl()
{
	IniciaControles();
/*
	ConsultaCotizas();
	MuestraCotizas();
*/
}
void QCtrlCotizas::ConsultaCotizas()
{
}
void QCtrlCotizas::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}

void QCtrlCotizas::ConectaSlots()
{
	connect(QCtrClientes,
		SIGNAL(SignalFisica(CQSisCliente *)),
		SLOT(SlotFisica(CQSisCliente *)));
	connect(QCtrClientes,
		SIGNAL(SignalMoral(CQSisCliente *)),
		SLOT(SlotMoral(CQSisCliente *)));
	
	connect(QCtrFPago,
		SIGNAL(SignalFormaPago(CQSisFormaPago *)),
		SLOT(SlotFormaPago(CQSisFormaPago *)));
	
	connect(QCtrPrecios,
		SIGNAL(SignalPrecio(CQSisPrecio *)),
		SLOT(SlotPrecio(CQSisPrecio *)));
	
	connect(QCtrProductos,
		SIGNAL(SignalProductos(CQSisProducto *)),
		SLOT(SlotProducto(CQSisProducto *)));
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(SlotCotiza()));
}

void QCtrlCotizas::SlotCotiza()
{
Cotiza();
}
void QCtrlCotizas::SlotProducto(CQSisProducto *pCQSProducto)
{
	CQSProducto=pCQSProducto;
	SiscomPasaFocoControl(QLECantidad);
	MuestraDescripcion();
}
void QCtrlCotizas::SlotPrecio(CQSisPrecio *pCQSPrecio)
{
	CQSPrecio=pCQSPrecio;
	QCtrProductos->setFocus();
}
void QCtrlCotizas::SlotFormaPago(CQSisFormaPago *pCQSFPago)
{
	CQSFPago=pCQSFPago;
	QCtrPrecios->setFocus();

}
void QCtrlCotizas::SlotFisica(CQSisCliente *pCQSCliente)
{
      CQSCliente=pCQSCliente;
      QCtrFPago->setFocus();
      emit SignalClienteFisica(CQSCliente);
}
void QCtrlCotizas::SlotMoral(CQSisCliente *pCQSCliente)
{
	CQSCliente=pCQSCliente;
	MuestraContactos();
}
void QCtrlCotizas::setFocus()
{
	QCtrProductos->setFocus();	
}
void QCtrlCotizas::LimpiaSeleccion()
{
}
void QCtrlCotizas::Limpia()
{
}


void QCtrlCotizas::MuestraContactos()
{
QCtrContactos->setEnabled(true);
QCtrContactos->setFocus();
QCtrContactos->PonEmpresa(CQSCliente->Empresa());
QCtrContactos->IniciaControl();
}


void QCtrlCotizas::MuestraDescripcion()
{
	QTEDsc->setText(CQSProducto->SRegistrosPro2["Dsc"]);

}


void QCtrlCotizas::Cotiza()
{
CQSisOpCotiza lCQSOCotiza(SisDatCom);
CQSPCotiza=ProductoCotiza();
lCQSOCotiza.CotizaProducto(CQSPCotiza);
MuestraCotizacion();
emit SignalCotizacion(CQSCliente,
		      CQSFPago,
		      CQSPrecio,
		      CQSProducto,
		      CQSPCotiza,
		      CQSContacto);
}

CQSisProdCotiza *QCtrlCotizas::ProductoCotiza()
{
return new CQSisProdCotiza(
		CQSProducto,
		CQSPrecio,
		CQSFPago,
		new CQSisEmpresa("0",""),
		CQSCliente,
		CQSContacto,
		new CQSisEmpleado(
			new SisPersona("","","","")
			),
		SiscomObtenInformacionDelEdit(QLECantidad),
		"",
		"",
		SiscomObtenInformacionDelEdit(QLEPImporte),
		"",
		"",
		"0");
}

void QCtrlCotizas::MuestraCotizacion()
{
QLCDNExistencia->display(CQSPCotiza->SRegistrosPro2["Existencia"]);
QLCDNPrecio->display(CQSPCotiza->SRegistrosPro2["Precio"]);
QLCDNImporte->display(CQSPCotiza->SRegistrosPro2["Total"]);
QLECantidad->setText(CQSPCotiza->SRegistrosPro2["Cantidad"]);

}


QLabel *QCtrlCotizas::CreaEtiqueta(const char *pchrPtrDato,
				   const char *pchrPtrNombre)
{
QLabel *lQLEtiqueta;
lQLEtiqueta=new QLabel(pchrPtrDato,
		       this,
		       pchrPtrNombre,
		       0);
lQLEtiqueta->setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));
return lQLEtiqueta;
}
QVBoxLayout *QCtrlCotizas::Clientes()
{
QVBoxLayout *lQVBLClientes=new QVBoxLayout(0,0,-1,"lQVBLClientes");
QLClientes=CreaEtiqueta("Clientes","QLClientes");
QCtrClientes=new QCtrlClientes(this,"QCtrClientes");
QCtrClientes->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed));
lQVBLClientes->addWidget(QLClientes);
lQVBLClientes->addWidget(QCtrClientes);
return lQVBLClientes;
}
QVBoxLayout *QCtrlCotizas::Contactos()
{
QVBoxLayout *lQVBLContactos=new QVBoxLayout(0,0,-1,"lQVBLContactos");
QLContactos=CreaEtiqueta("Contactos","QLContactos");
QCtrContactos=new QCtrlContactos(this,"QCtrContactos");
QCtrContactos->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed));
lQVBLContactos->addWidget(QLContactos);
lQVBLContactos->addWidget(QCtrContactos);
return lQVBLContactos;
}
QVBoxLayout *QCtrlCotizas::FormaPago()
{
QVBoxLayout *lQVBLFPago=new QVBoxLayout(0,0,-1,"lQVBLFPago");
QLFPago=CreaEtiqueta("Forma De Pago","QLFPago");
QCtrFPago=new QCtrlFormaPago(this,"QCtrFPago");
QCtrFPago->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed));
lQVBLFPago->addWidget(QLFPago);
lQVBLFPago->addWidget(QCtrFPago);
return lQVBLFPago;
}

QVBoxLayout *QCtrlCotizas::Productos()
{
QVBoxLayout *lQVBLProductos=new QVBoxLayout(0,0,-1,"lQVBLProductos");
QLProductos=CreaEtiqueta("Productos","QLProductos");
QCtrProductos=new QCtrlProductos(this,"QCtrProductos");
QCtrProductos->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed));
lQVBLProductos->addWidget(QLProductos);
lQVBLProductos->addWidget(QCtrProductos);
return lQVBLProductos;
}

QVBoxLayout *QCtrlCotizas::Precios()
{
QVBoxLayout *lQVBLPrecios=new QVBoxLayout(0,0,-1,"lQVBLPrecios");
QLPrecios=CreaEtiqueta("Precios","QLPrecios");
QCtrPrecios=new QCtrlPrecios(this,"QCtrPrecios");
QCtrPrecios->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed));
lQVBLPrecios->addWidget(QLPrecios);
lQVBLPrecios->addWidget(QCtrPrecios);
return lQVBLPrecios;
}
QVBoxLayout *QCtrlCotizas::ClienteDescripcion()
{
QVBoxLayout *lQVBLCliDescripcion;
lQVBLCliDescripcion=new QVBoxLayout(0,0,-1,"lQVBLCliDescripcion");
QLCliente=CreaEtiqueta("Cliente","QLCliente");
QLDescripcion=CreaEtiqueta("Descripcion","QLDescripcion");
QLECliente=CreaEdit("QLECliente");
QTEDsc=CreaTextEdit("QTEDsc");
lQVBLCliDescripcion->addWidget(QLCliente);
lQVBLCliDescripcion->addWidget(QLECliente);
lQVBLCliDescripcion->addWidget(QLDescripcion);
lQVBLCliDescripcion->addWidget(QTEDsc);
return lQVBLCliDescripcion;
}
QTextEdit *QCtrlCotizas::CreaTextEdit(const char *pchrPtrNombre)
{
QTextEdit *lQTEEdit;
lQTEEdit=new QTextEdit(this,pchrPtrNombre);
lQTEEdit->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding));
return lQTEEdit;
}

QLineEdit *QCtrlCotizas::CreaEdit(const char *pchrPtrNombre)
{
QLineEdit *lQLEEdit;
lQLEEdit=new QLineEdit(this,pchrPtrNombre);
lQLEEdit->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed));
return lQLEEdit;
}
QVBoxLayout *QCtrlCotizas::CreaDisplayEtiqueta(
				const char *pchrPtrNmbEtiqueta,
				const char *pchrPtrTextoEtiqueta,
				const char *pchrPtrNmbDisplay,
				QLCDNumber **pQLCDNDisplay,
				QLabel **pQLEtiqueta)
{
QVBoxLayout *lQLVLayout;
lQLVLayout=new QVBoxLayout(0,0,-1,"lQLVLayout");
*pQLEtiqueta=CreaEtiqueta(pchrPtrTextoEtiqueta,pchrPtrNmbEtiqueta);
*pQLCDNDisplay=new QLCDNumber(this,pchrPtrNmbDisplay);
lQLVLayout->addWidget(*pQLEtiqueta);
lQLVLayout->addWidget(*pQLCDNDisplay);
(*pQLCDNDisplay)->setNumDigits(8);
return lQLVLayout;
}

void QCtrlCotizas::ConElCliente(const char *pchrPtrCliente)
{
	QCtrClientes->ConElCliente(pchrPtrCliente);
}
