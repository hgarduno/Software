#include <IMP_Ventas.h>
#include <IMP_CapturaCantidad.h>

#include <CQSisClientes.h>
#include <CQSisProductos.h>
#include <CQSisEmpresas.h>
#include <CQSisEmpleados.h>
#include <CQSisVentas.h>
#include <QCtrlClientes.h>
#include <QCtrlProductos.h>
#include <QCtrlPrecios.h>
#include <QCtrlFormaPago.h>
#include <QCtrlContactos.h>
#include <QCtrlContactos.h>
#include <CQSisProdCotiza.h>
#include <CQSisOrdenes.h>
#include <CQSisPreciosTabla.h>
#include <CQSisPrecios.h>
#include <CQSisImprimeTicket.h>

#include <CQSisPerfilUtilizacion.h>
#include<SISCOMComunicaciones++.h>

#include <qlcdnumber.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
QVentas *InstanciaVentas(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QVentas((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QVentas::QVentas(SiscomDatCom *pSisDatCom, 
		char **pchrPtrArgumentos, 
		CQSisOrden *pCQSOrden,
		CQSisLstProdCotiza *pCQSLPCotiza,
		QWidget *pQWParent,       
		const char *pchrPtrName,
		WFlags pWFlags):	      
		Ventas(pQWParent,pchrPtrName,pWFlags),
		SisDatCom(pSisDatCom),
		chrPtrArgumentos(pchrPtrArgumentos),
		CQSOrden(pCQSOrden),
		CQSContacto(0),
		CQSCliente(0),
		CQSProducto(0),
		CQSFPago(0),
		CQSPrecio(0),
		CQSPTabla(0)


{
CQSisProdCotiza *lCQSPCotiza;
int lintNDatos;
int lintContador;
MuestraArgumentos();
ConectaSlots();
IniciaVariables();
MuestraCotizacionOrden();
lintNDatos=pCQSLPCotiza->count()-1;
for(lintContador=0;
    lintContador<lintNDatos;
    lintContador++)
{
  lCQSPCotiza=pCQSLPCotiza->at(lintContador);
  lCQSPCotiza->SiscomActualizaCampo("EdoVenta",chrPtrArgumentos[10]);
 CQSLPCotiza<<lCQSPCotiza;

}
lCQSPCotiza=pCQSLPCotiza->at(lintContador);
CQSLPCotiza.PonTotalOrden(lCQSPCotiza->SRegistrosPro2["Total"]);
 CQSCliente=CQSOrden->Cliente();
 CQSContacto=CQSCliente->Contacto();
 CQSFPago=CQSOrden->FormaPago();
ActivaImprimirEliminar();
MuestraCotizacionOrden();
show();
}
void QVentas::closeEvent(QCloseEvent *pQCEvent)
{
   emit SignalTerminar(this);
}
QVentas::QVentas(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Ventas(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				CQSContacto(0),
				CQSCliente(0),
				CQSProducto(0),
				CQSFPago(0),
				CQSPrecio(0)


{
MuestraArgumentos();
ConectaSlots();
IniciaVariables();
}
QVentas::~QVentas()
{

}

void QVentas::ConectaSlots()
{
	connect(QCtrClientes,
		SIGNAL(SignalFisica(CQSisCliente *)),
		SLOT(SlotFisica(CQSisCliente *)));
	connect(QCtrClientes,
		SIGNAL(SignalMoral(CQSisCliente *)),
		SLOT(SlotMoral(CQSisCliente *)));
	connect(QCtrProductos,
		SIGNAL(SignalProductos(CQSisProducto *)),
		SLOT(SlotProducto(CQSisProducto *)));
	connect(QCtrProductos,
		SIGNAL(SignalSeleccionandoProducto(CQSisProducto *)),
		SLOT(SlotSeleccionandoProducto(CQSisProducto *)));
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(SlotCotiza()));
	connect(QCtrPrecios,
		SIGNAL(SignalPrecio(CQSisPrecio *)),
		SLOT(SlotPrecio(CQSisPrecio *)));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(SlotAnexar()));

	connect(QCtrContactos,
		SIGNAL(SignalContactos(CQSisContacto *)),
		SLOT(SlotContacto(CQSisContacto *)));
	connect(QCtrFPago,
		SIGNAL(SignalFormaPago(CQSisFormaPago *)),
		SLOT(SlotFormaPago(CQSisFormaPago *)));
	connect(QPBRegistra,
		SIGNAL(clicked()),
		SLOT(SlotRegistra()));
	connect(QPBImprimir,
		SIGNAL(clicked()),
		SLOT(SlotImprime()));
	connect(QPBEliminar,
		SIGNAL(clicked()),
		SLOT(SlotEliminar()));
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotCambiaDato(int,int,int,const QPoint &)));
	connect(QLEImporte,
		SIGNAL(returnPressed()),
		SLOT(SlotCalculaCantidad()));

}
void QVentas::SlotSeleccionandoProducto(CQSisProducto *pCQSProducto)
{
QTEDescripcion->setText((*pCQSProducto)["Dsc"]);
}
void QVentas::SlotCalculaCantidad()
{
	QLECantidad->setText("Calcula");	
	SlotCotiza();

}
void QVentas::SlotCambiaDato(int pintNProducto,
			     int pintNColumna,
			     int,
			     const QPoint &)
{
	(this->*CambiaDatos[pintNColumna])(
			CQSLPCotiza.at(pintNProducto),
			pintNProducto,
			pintNColumna);
}
void QVentas::SlotEliminar()
{
	Eliminar();
}
void QVentas::SlotImprime()
{
	if(chrPtrArgumentos[10][0]!='2')
	GeneraIdVenta();
	QPBImprimir->setEnabled(false);
	QPBRegistra->setEnabled(true);
	/*
	QPBEliminar->setEnabled(false);
	*/
	CQSisImprimeTicket lCQSITicket(&CQSLPCotiza,CQSCliente,CQSOrden);
}
void QVentas::SlotRegistra()
{
	Registra();
	IniciaOtraVenta();
	emit SignalRealizoOperacion(this);
}
void QVentas::SlotFormaPago(CQSisFormaPago *pCQSFPago)
{
	CQSFPago=pCQSFPago;
	QCtrPrecios->setFocus();

}
void QVentas::SlotContacto(CQSisContacto *pCQSContacto)
{
	CQSContacto=pCQSContacto;
	QCtrFPago->setFocus();
}
void QVentas::SlotFisica(CQSisCliente *pCQSCliente)
{
      CQSCliente=pCQSCliente;
      QCtrFPago->setFocus();
}
void QVentas::SlotMoral(CQSisCliente *pCQSCliente)
{
	CQSCliente=pCQSCliente;
	MuestraContactos();
}
void QVentas::SlotAnexar()
{
	CQSLPCotiza << CQSPCotiza;
	CotizaOrden();
	MuestraCotizacionOrden();
	QPBAnexar->setEnabled(false);
	ActivaImprimirEliminar();	
}
void QVentas::SlotPrecio(CQSisPrecio *pCQSPrecio)
{
	CQSPrecio=pCQSPrecio;
	QCtrProductos->setFocus();
}
void QVentas::SlotCotiza()
{
Cotiza();
}
void QVentas::SlotProducto(CQSisProducto *pCQSProducto)
{
	CQSProducto=pCQSProducto;
	SiscomPasaFocoControl(QLECantidad);
	MuestraDescripcion();
}
void QVentas::IniciaVariables()
{
	QCtrProductos->PonServidor(SisDatCom);
	QCtrPrecios->PonServidor(SisDatCom);
	QCtrClientes->PonServidor(SisDatCom);
	QCtrFPago->PonServidor(SisDatCom);
	QCtrContactos->PonServidor(SisDatCom);
	QCtrProductos->IniciaControl();
	QCtrClientes->IniciaControl();
	QCtrPrecios->IniciaControl();
	QCtrFPago->IniciaControl();
	QCtrClientes->setFocus();
	CambiaDatos[0]=&QVentas::OpcionInvalida;
	CambiaDatos[1]=&QVentas::CambiaCantidad;
	CambiaDatos[2]=&QVentas::OpcionInvalida;
	CambiaDatos[3]=&QVentas::CambiaTipoPrecio;
	CambiaDatos[4]=&QVentas::OpcionInvalida;
	QPBRegistra->setText(chrPtrArgumentos[11]);
	AsignaPerfilVenta();
	CQSLPrecios=QCtrPrecios->Precios();
	if(chrPtrArgumentos[12])
	setCaption(chrPtrArgumentos[12]);
	
	CQSEExpendio=new CQSisEmpresa("0","");
	CQSEUsuario=(CQSisEmpleado *)chrPtrArgumentos[0];
}
void QVentas::MuestraCliente()
{
	QLECliente->setText(CQSCliente->SRegistrosPro2["Nombre"]);
}
void QVentas::MuestraDescripcion()
{
	QTEDescripcion->setText(CQSProducto->SRegistrosPro2["Dsc"]);

}
void QVentas::Cotiza()
{
SiscomLog("");
CQSisOpCotiza lCQSOCotiza(SisDatCom);
CQSPCotiza=ProductoCotiza();
lCQSOCotiza.CotizaProducto(CQSPCotiza);
MuestraCotizacion();
ActivaAnexarOrden();
}
CQSisProdCotiza *QVentas::ProductoCotiza()
{
return new CQSisProdCotiza(
		CQSProducto,
		CQSPrecio,
		CQSFPago,
		CQSEExpendio,
		CQSCliente,
		CQSContacto,
		CQSEUsuario,
		SiscomObtenInformacionDelEdit(QLECantidad),
		"",
		"",
		SiscomObtenInformacionDelEdit(QLEImporte),
		"",
		"",
		chrPtrArgumentos[10]);
}
void QVentas::MuestraCotizacion()
{

QLCDNExistencia->display(CQSPCotiza->SRegistrosPro2["Existencia"]);
QLCDNPrecio->display(CQSPCotiza->SRegistrosPro2["Precio"]);
QLCDNImporte->display(CQSPCotiza->SRegistrosPro2["Total"]);
QLECantidad->setText(CQSPCotiza->SRegistrosPro2["Cantidad"]);
}
void QVentas::ActivaAnexarOrden()
{
int lintSePuedeVender;
  lintSePuedeVender=QString(CQSPCotiza->SRegistrosPro2["SePuedeVender"])=="Si";
QPBAnexar->setEnabled(lintSePuedeVender);
if(!lintSePuedeVender)
QCtrProductos->setFocus();
else
SiscomPasaFocoControl(QPBAnexar);

}
void QVentas::CotizaOrden()
{
if(CQSLPCotiza.count())
{
CQSisOpCotiza lCQSOCotiza(SisDatCom);
lCQSOCotiza.CotizaProductos(&CQSLPCotiza);
}
}
void QVentas::MuestraCotizacionOrden()
{
int lintContador;
int lintNFilas=CQSLPCotiza.count();
CQSisProdCotiza *lCQSPCotiza;
QTDatos->setNumRows(lintNFilas);
for(lintContador=0;
    lintContador<lintNFilas;
    lintContador++)
{
 lCQSPCotiza=CQSLPCotiza.at(lintContador);
 SiscomAnexarRegistroALaTabla(
 		lintContador,
		QTDatos,
		QStringList() <<
		lCQSPCotiza->Producto()->SRegistrosPro2["Clave"]	<<
		lCQSPCotiza->SRegistrosPro2["Cantidad"]			<<
		lCQSPCotiza->SRegistrosPro2["Precio"]			<<
		lCQSPCotiza->Precio()->SRegistrosPro2["Nombre"]		<<
		lCQSPCotiza->SRegistrosPro2["Total"]);
}
QLCDTotalOrden->display(CQSLPCotiza.TotalOrden());
QCtrProductos->setFocus();
SiscomAjustaColumnas(QTDatos);
}
void QVentas::MuestraContactos()
{
QCtrContactos->setEnabled(true);
QCtrContactos->setFocus();
QCtrContactos->PonEmpresa(CQSCliente->Empresa());
QCtrContactos->IniciaControl();
}
void QVentas::Registra()
{
CQSisOpVenta lCQSOVenta(SisDatCom);
lCQSOVenta.RegistraVenta(&CQSLPCotiza);
CQSLPCotiza.setAutoDelete(true);
CQSLPCotiza.clear();
CQSLPCotiza.setAutoDelete(false);

}
void QVentas::GeneraIdVenta()
{
CQSisOpCotiza lCQSOCotiza(SisDatCom);
lCQSOCotiza.GeneraIdentificador(&CQSLPCotiza);
}
void QVentas::IniciaOtraVenta()
{
	SiscomEliminaFilasTabla(QTDatos);
	/*
	CQSLPCotiza.setAutoDelete(true);
	CQSLPCotiza.clear();

	*/
	QCtrClientes->setFocus();
	QPBAnexar->setEnabled(false);
	QPBRegistra->setEnabled(false);
	/*
	ActivaImprimirEliminar();
	*/
}
void QVentas::Eliminar()
{

QMemArray<int> lQMArray;
lQMArray=SiscomFilasSeleccionadas(QTDatos);
if(!lQMArray.count())
QMessageBox::information(this,"Aviso Del Sistema","Se requiere seleccionar las filas a eliminar");
else
{
QTDatos->removeRows(lQMArray);
CQSLPCotiza.EliminaProductos(lQMArray);
CotizandoOrden();
}
ActivaImprimirEliminar();
}
void QVentas::CotizandoOrden()
{
	CotizaOrden();
	MuestraCotizacionOrden();
}
void QVentas::CambiaCantidad(CQSisProdCotiza *pCQSPCotiza,int,int)
{
QCapturaCantidad lQCCantidad(pCQSPCotiza);
if(lQCCantidad.Opcion())
CotizandoOrden();
}
void QVentas::OpcionInvalida(CQSisProdCotiza *pCQSPCotiza,int,int)
{
printf("Opcion Invalida\n");
}
void QVentas::CambiaTipoPrecio(CQSisProdCotiza *pCQSPCotiza,
				int pintNFila,
				int pintNColumna)
{
		  CQSPTabla=new CQSisPreciosTabla(&CQSLPrecios,
		  				 this,
						 pintNFila,
						 pintNColumna);
	  	  QTDatos->setCellWidget(pintNFila,pintNColumna,CQSPTabla);
		  connect(CQSPTabla,
		  	  SIGNAL(SignalPrecio(CQSisPrecio *,int,int)),
			  SLOT(SlotCambiaPrecio(CQSisPrecio *,int,int)));
}

void QVentas::SlotCambiaPrecio(CQSisPrecio *pCQSPrecio,
			       int pintNProducto,
			       int pintNColumna)
{
CQSisProdCotiza *lCQSPCotiza=CQSLPCotiza.at(pintNProducto);
	lCQSPCotiza->SiscomActualizaCampo("IdPrecio",
					  pCQSPrecio->SRegistrosPro2["IdPrecio"]);
	lCQSPCotiza->Precio(pCQSPrecio);
	QTDatos->setText(pintNProducto,
			 pintNColumna,
			 pCQSPrecio->SRegistrosPro2["Nombre"]);
	CotizandoOrden();	

}
void QVentas::ActivaImprimirEliminar()
{
	QPBEliminar->setEnabled(CQSLPCotiza.count());
	QPBImprimir->setEnabled(CQSLPCotiza.count());

}
void QVentas::MuestraArgumentos()
{
/*
	for(lintContador=10;
	    lintContador<15;
	    lintContador++)
	 printf("Dato[%d]=%s\n",
	 	lintContador,
	 	chrPtrArgumentos[lintContador]);
*/
}

void QVentas::AsignaPerfilVenta()
{

/*
 * Jueves 21 Febrero 2008
 * Debido, que en el proceso de integracion con otroas
 * aplicaciones (SiscomClinicas3), no se realiza la 
 * validacion del perfil de ventas, no se habia considerado
 * la validacion, vs 0 del argumento 5, pero al no inicializarse
 * por la ventana SiscomClinicas3, tronaba al cargar la ventana
 * de ventas
 *
 */
CQSisPerfilVentas *lCQSPVentas=(CQSisPerfilVentas *)chrPtrArgumentos[5];
if(lCQSPVentas)
{
QCtrClientes->setEnabled(lCQSPVentas->EdoClientes());
QCtrContactos->setEnabled(lCQSPVentas->EdoContacto());
QCtrFPago->setEnabled(lCQSPVentas->EdoFormaPago());
QCtrPrecios->setEnabled(lCQSPVentas->EdoPrecios());
}
}
