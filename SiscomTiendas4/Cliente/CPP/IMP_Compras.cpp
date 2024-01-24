#include <IMP_Compras.h>
#include<SISCOMComunicaciones++.h>

#include <QCtrlProductos.h>
#include <QCtrlEmpresas.h>
#include <QCtrlContactos.h>
#include <QCtrlFormaPago.h>

#include <CQSisProductos.h>
#include <CQSisEmpresas.h>
#include <CQSisContactos.h>
#include <CQSisFormaPago.h>

#include <qtable.h>
#include <qpushbutton.h>
QCompras *InstanciaCompras(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QCompras((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QCompras::QCompras(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Compras(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QCompras::~QCompras()
{

}

void QCompras::ConectaSlots()
{
	connect(QCtrProductos,
		SIGNAL(SignalProductos(CQSisProducto *)),
		SLOT(SlotProducto(CQSisProducto *)));
	connect(QCtrProveedores,
		SIGNAL(SignalEmpresas(CQSisEmpresa *)),
		SLOT(SlotEmpresa(CQSisEmpresa *)));
	connect(QCtrContactos,
		SIGNAL(SignalContactos(CQSisContacto *)),
		SLOT(SlotContacto(CQSisContacto *)));
	
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoPrecioCompra()));
	connect(QLEPrecio,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoNFactura()));
	connect(QLENFactura,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAnexarCompra()));
	connect(QCtrFPago,
		SIGNAL(SignalFormaPago(CQSisFormaPago *)),
		SLOT(SlotFormaPago(CQSisFormaPago *)));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(SlotAnexar()));
	connect(QPBRegistra,
		SIGNAL(clicked()),
		SLOT(SlotRegistra()));

}
void QCompras::SlotRegistra()
{
Registra();
ReIniciaCompra();
}
void QCompras::SlotAnexar()
{
	AnexaCompra();
	QCtrProductos->setFocus();
}
void QCompras::SlotFormaPago(CQSisFormaPago *pCQSFPago)
{
	CQSFPago=pCQSFPago;
	SiscomPasaFocoControl(QLECantidad);
}
void QCompras::SlotPasaFocoPrecioCompra()
{
	SiscomPasaFocoControl(QLEPrecio);
}
void QCompras::SlotPasaFocoNFactura()
{
	SiscomPasaFocoControl(QLENFactura);
}
void QCompras::SlotPasaFocoAnexarCompra()
{
	SiscomPasaFocoControl(QPBAnexar);
}
void QCompras::SlotContacto(CQSisContacto *pCQSContacto)
{
	CQSContacto=pCQSContacto;
	QCtrFPago->setFocus();
}
void QCompras::SlotEmpresa(CQSisEmpresa *pCQSEProveedor)
{
	CQSEProveedor=pCQSEProveedor;
	QCtrContactos->PonServidor(SisDatCom);
	QCtrContactos->PonEmpresa(CQSEProveedor);
	QCtrContactos->IniciaControl();
	QCtrContactos->setFocus();
}
void QCompras::SlotProducto(CQSisProducto *pCQSProducto)
{
	CQSProducto=pCQSProducto;
	QCtrProveedores->setFocus();
	EjecutaUltimaCompra();
}
void QCompras::EjecutaUltimaCompra()
{
	UltimaCompra();
	MuestraUltimaCompra();
}
void QCompras::IniciaVariables()
{
	QCtrProductos->PonServidor(SisDatCom);
	QCtrProductos->IniciaControl();
	QCtrProductos->setFocus();
	QCtrProveedores->PonServidor(SisDatCom);
	QCtrProveedores->IniciaControl();
	QCtrFPago->PonServidor(SisDatCom);
	QCtrFPago->IniciaControl();
}

CQSisCompra *QCompras::FormaCompra()
{
return new CQSisCompra(
		CQSProducto,
		CQSEProveedor,
		CQSContacto,
		CQSFPago,
		"",
		SiscomObtenInformacionDelEdit(QLECantidad),
		SiscomObtenInformacionDelEdit(QLEPrecio),
		SiscomObtenInformacionDelEdit(QLENFactura),
		"",
		"");
}
void QCompras::AnexaCompra()
{
int lintNFila=QTDatos->numRows();
CQSisCompra *lCQSCompra;
	QTDatos->setNumRows(lintNFila+1);
	lCQSCompra=FormaCompra();
	SiscomAnexarRegistroALaTabla(
		lintNFila,
		QTDatos,
		QStringList () 		<<
		lCQSCompra->Producto()->SRegistrosPro2["Clave"]	<<
		lCQSCompra->SRegistrosPro2["Cantidad"]		<<
		lCQSCompra->SRegistrosPro2["Precio"]		<<
		lCQSCompra->SRegistrosPro2["Factura"]		<<
		lCQSCompra->Proveedor()->SRegistrosPro2["RazonSocial"]	<<
		QString(lCQSCompra->Contacto()->ObtenPersona()->SRegistrosPro2["Nombre"])	+
		" "								+
		lCQSCompra->Contacto()->ObtenPersona()->SRegistrosPro2["APaterno"]);
	CQSLCompra << lCQSCompra;
	HabilitaRegistrar();

}
void QCompras::Registra()
{
CQSisOpCompras lCQSCompra(SisDatCom);
	lCQSCompra.Registra(&CQSLCompra);
	CQSLCompra.clear(); 
}
void QCompras::ReIniciaCompra()
{
int lintContador;
QCtrProductos->setFocus();
SiscomEliminaFilasTabla(QTDatos);
 HabilitaRegistrar();
}
void QCompras::UltimaCompra()
{
CQSLUCompra.clear();
CQSisOpCompras lCQSOUCompra(SisDatCom);
lCQSOUCompra.UltimaCompraProducto(
		new CQSisEmpresa("0",""),
		CQSProducto,
		&CQSLUCompra);
}
void QCompras::MuestraUltimaCompra()
{
CQSisCompra *lCQSCUCompra=CQSLUCompra.first();
if(lCQSCUCompra)
{
QLEUCProducto->setText(lCQSCUCompra->Producto()->SRegistrosPro2["Clave"]);
QLEUCCantidad->setText(lCQSCUCompra->SRegistrosPro2["Cantidad"]);
QLEUCPrecio->setText(lCQSCUCompra->SRegistrosPro2["Precio"]);
QLEUCProveedor->setText(lCQSCUCompra->Proveedor()->SRegistrosPro2["RazonSocial"]);
QLEUCContacto->setText(
		QString(lCQSCUCompra->Contacto()->ObtenPersona()->SRegistrosPro2["Nombre"])	+
		" "								+
		lCQSCUCompra->Contacto()->ObtenPersona()->SRegistrosPro2["APaterno"]);
QLEUCFactura->setText(lCQSCUCompra->SRegistrosPro2["Factura"]);
QLEUCFecha->setText(lCQSCUCompra->SRegistrosPro2["Fecha"]);
QLECantidad->setText(lCQSCUCompra->SRegistrosPro2["Cantidad"]);
QLEPrecio->setText(lCQSCUCompra->SRegistrosPro2["Precio"]);
}
else
{
QLEUCProducto->clear();
QLEUCCantidad->clear();
QLEUCPrecio->clear();
QLEUCProveedor->clear();
QLEUCContacto->clear();
QLEUCFactura->clear();
QLEUCFecha->clear();
}
}
void QCompras::HabilitaRegistrar()
{
	QPBRegistra->setEnabled(QTDatos->numRows());
}
void QCompras::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
