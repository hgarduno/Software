#include <IMP_Ventas3Qt.h>
#include <IMP_CapturaCantidad3Qt.h>
#include <IMP_RemisionFactura.h>
#include <IMP_ResultadosBusqueda.h>
#include <SiscomDesarrollo3Qt++.h>
#include <QCtrlProductos3Qt.h>
#include <QCtrlFormaPago3Qt.h>
#include <QCtrlClientes3Qt.h>
#include <QCtrlPrecios3Qt.h>
#include <QCtrlContactos3Qt.h>
#include <QCtrlPreciosProductos.h>
#include <CQSisProdCotiza3Qt.h>
#include <CQSisVentas3Qt.h>
#include <CQSisPreciosTabla3Qt.h>
#include <CQSisComunesTiendas3Qt.h>

#include <qtextedit.h>
#include <qlineedit.h>
#include <qlcdnumber.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qbuttongroup.h>
QVentas3Qt *InstanciaVentas3Qt(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QVentas3Qt((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QVentas3Qt::QVentas3Qt(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Ventas3Qt(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				CQSPTabla3Qt(0),
				intSeElimina(0),
				chrPtrTipoOrden("Remision"),
				SReg3Producto(0),
				SReg3Precio(0),
				SReg3Cliente(0),
				SReg3FPago(0)
{
IniciaVariables();
ConectaSlots();
}

QVentas3Qt::~QVentas3Qt()
{

}

void QVentas3Qt::ConectaSlots()
{
connect(QCtrClientes,
	SIGNAL(SignalMoral(SiscomRegistro3 *)),
	SLOT(SlotMoral(SiscomRegistro3 *)));
connect(QCtrClientes,
	SIGNAL(SignalFisica(SiscomRegistro3 *)),
	SLOT(SlotFisica(SiscomRegistro3 *)));
connect(QCtrContactos,
	SIGNAL(SignalContacto(SiscomRegistro3 *)),
	SLOT(SlotContacto(SiscomRegistro3 *)));
connect(QCtrFPago,
	SIGNAL(SignalFormaPago(SiscomRegistro3 *)),
	SLOT(SlotFormaPago(SiscomRegistro3 *)));
connect(QCtrPrecios,
	SIGNAL(SignalPrecio(SiscomRegistro3 *)),
	SLOT(SlotPrecio(SiscomRegistro3 *)));
connect(QCtrProductos,
	SIGNAL(SignalProductos(SiscomRegistro3 *)),
	SLOT(SlotProducto(SiscomRegistro3 *)));
connect(QCtrProductos,
	SIGNAL(SignalSeleccionandoProducto(SiscomRegistro3 *)),
	SLOT(SlotSeleccionandoProducto(SiscomRegistro3 *)));
connect(QCtrProductos,
	SIGNAL(SignalProductoNoEstaEnLaLista(const char *)),
	SLOT(SlotProductoNoEstaEnLaLista(const char *)));
connect(QLECantidad,
	SIGNAL(returnPressed()),
	SLOT(SlotCotiza()));
connect(QPBAnexar,
	SIGNAL(clicked()),
	SLOT(SlotAnexarProducto()));
connect(QPBRegistra,
	SIGNAL(clicked()),
	SLOT(SlotRegistra()));
connect(QPBImprimir,
	SIGNAL(clicked()),
	SLOT(SlotImprime()));
connect(QTDatos,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotCambiaDato(int,int,int,const QPoint &)));
connect(QTDatos,
	SIGNAL(selectionChanged()),
	SLOT(SlotCambioSeleccion()));
connect(QPBEliminar,
	SIGNAL(clicked()),
	SLOT(SlotElimina()));
connect(QBGTOrden,
	SIGNAL(clicked(int)),
	SLOT(SlotTipoOrden(int)));
}
void QVentas3Qt::SlotProductoNoEstaEnLaLista(const char *pchrPtrTexto)
{
const char *lchrPtrClave;
SiscomRegistro3Lst lSisReg3LstReg;
CQSisOpVentas3Qt lCQSOpVentas3Qt(SisDatCom);
SiscomEscribeLog3Qt("El Texto de lo que no esta en lista:%s",pchrPtrTexto);
lCQSOpVentas3Qt.ProductosPorAproximacion(pchrPtrTexto,&lSisReg3LstReg);
QResultadosBusqueda lQResBusqueda(&lSisReg3LstReg,
				  SisDatCom,
				  chrPtrArgumentos);
if((lchrPtrClave=lQResBusqueda.Clave()))
QCtrProductos->ColocaListaEnLaClave(lchrPtrClave);
}
void QVentas3Qt::SlotTipoOrden(int pintTipoOrden)
{
if(pintTipoOrden==0)
 chrPtrTipoOrden="Remision";
if(pintTipoOrden==1)
 chrPtrTipoOrden="Factura";
if(pintTipoOrden==2)
 chrPtrTipoOrden="Cotizacion";
SiscomEscribeLog3Qt("El Numero de Opcion:%d %s",
		    pintTipoOrden,
		    chrPtrTipoOrden);
 ActualizaTipoOrden();
 CotizandoProductos();
}
void QVentas3Qt::SlotElimina()
{
  EliminaSeleccionados();
  CotizandoProductos();
}
void QVentas3Qt::SlotCambioSeleccion()
{
int lintContador;
int lintSiHaySeleccion=0;
for(lintContador=0;
    lintContador<QTDatos->numRows();
    lintContador++)
if(QTDatos->isRowSelected(lintContador,true))
{
   lintSiHaySeleccion=1;
   break;
}
   QPBEliminar->setEnabled(lintSiHaySeleccion);
}
void QVentas3Qt::SlotCambiaDato(int pintNFila,
				int pintNColumna,
				int,
				const QPoint &)
{
 (this->*CambiaDatos[pintNColumna])(CQSProd3QtLstCotiza[pintNFila],
 				 pintNFila,
				 pintNColumna);
}
void QVentas3Qt::SlotImprime()
{
char lchrArrNoRemFactura[28];
	if(CapturaRemFactura(lchrArrNoRemFactura))
	 ColocaNoRemisionFactura(lchrArrNoRemFactura);
	if(chrPtrArgumentos[10][0]!='2')
	GeneraIdentificador();	
	/*
	QPBImprimir->setEnabled(false);
	*/
	QPBRegistra->setEnabled(true);
}
void QVentas3Qt::SlotRegistra()
{
CQSisOpVentas3Qt lCQSOVentas3Qt(SisDatCom);
lCQSOVentas3Qt.RegistraVenta(&CQSProd3QtLstCotiza);

IniciaOtraOrden();
}
void QVentas3Qt::SlotAnexarProducto()
{
CQSProd3QtLstCotiza << CQSProd3QtCotiza;
CotizandoProductos();
QPBAnexar->setEnabled(false);
SiscomDesarrollo3Qt::PasaFocoControl(QCtrProductos);
QPBImprimir->setEnabled(CQSProd3QtLstCotiza.count());
}
void QVentas3Qt::SlotCotiza()
{
CotizandoProducto();
if(CQSProd3QtCotiza)
ActivaAnexarALaOrden();
else
SiscomEscribeLog3Qt("No Cotizo El Producto");
}
void QVentas3Qt::SlotSeleccionandoProducto(SiscomRegistro3 *pSReg3Producto)
{
QTEDescripcion->setText((*pSReg3Producto)["dscproducto"]);
}
void QVentas3Qt::SlotProducto(SiscomRegistro3 *pSReg3Producto)
{
	SReg3Producto=pSReg3Producto;
	SiscomDesarrollo3Qt::PasaFocoControl(QLECantidad);
	MuestraPreciosProducto();
}
void QVentas3Qt::SlotPrecio(SiscomRegistro3 *pSReg3Precio)
{
   SReg3Precio=pSReg3Precio;
   SiscomDesarrollo3Qt::PasaFocoControl(QCtrProductos);
}
void QVentas3Qt::SlotFormaPago(SiscomRegistro3 *pSReg3FPago)
{
 SReg3FPago=pSReg3FPago;
 SiscomDesarrollo3Qt::PasaFocoControl(QCtrPrecios);
}
void QVentas3Qt::SlotContacto(SiscomRegistro3 *pSReg3Contacto)
{
SReg3Contacto=pSReg3Contacto;
SiscomDesarrollo3Qt::PasaFocoControl(QCtrFPago);
}
void QVentas3Qt::SlotFisica(SiscomRegistro3 *pSReg3Cliente)
{
char lchrArrCliente[90];
SReg3Cliente=pSReg3Cliente;
SiscomDesarrollo3Qt::PasaFocoControl(QCtrFPago);
CQSisComunesTiendas3Qt::NombreCompleto(SReg3Cliente,lchrArrCliente);
QLECliente->setText(lchrArrCliente);
}
void QVentas3Qt::SlotMoral(SiscomRegistro3 *pSReg3Cliente)
{
 SReg3Cliente=pSReg3Cliente;
 MuestraContactos();
 SiscomDesarrollo3Qt::PasaFocoControl(QCtrContactos);
}
void QVentas3Qt::SlotCambioTipoPrecio(SiscomRegistro3 *pSReg3Precio,
				      int pintNFila,
				      int pintNColumna)
{
SiscomRegistro3 *lSReg3Producto;
	lSReg3Producto=CQSProd3QtLstCotiza[pintNFila];
	CotizandoProductos();
}
void QVentas3Qt::MuestraContactos()
{
QCtrContactos->Limpia();
QCtrContactos->Servidor(SisDatCom);
QCtrContactos->PonEmpresa(SReg3Cliente);
QCtrContactos->IniciaControl();
}
void QVentas3Qt::IniciaVariables()
{
QCtrProductos->Servidor(SisDatCom);
QCtrProductos->IniciaControl();
QCtrFPago->Servidor(SisDatCom);
QCtrFPago->IniciaControl();
QCtrClientes->Servidor(SisDatCom);
QCtrClientes->IniciaControl();
QCtrPrecios->Servidor(SisDatCom);
QCtrPrecios->IniciaControl();
QCtrPProducto->Servidor(SisDatCom);
SiscomDesarrollo3Qt::PasaFocoControl(QCtrClientes);
CambiaDatos[0]=&QVentas3Qt::OpcionInvalida;
CambiaDatos[1]=&QVentas3Qt::OpcionInvalida;
CambiaDatos[2]=&QVentas3Qt::OpcionInvalida;
CambiaDatos[3]=&QVentas3Qt::CambiaCantidad;
CambiaDatos[4]=&QVentas3Qt::OpcionInvalida;
CambiaDatos[5]=&QVentas3Qt::CambiaTipoPrecio;
CambiaDatos[6]=&QVentas3Qt::OpcionInvalida;

QPBRegistra->setText(chrPtrArgumentos[11]);
if(chrPtrArgumentos[12])
setCaption(chrPtrArgumentos[12]);
SReg3TiposPrecios=QCtrPrecios->Precios();
QCtrClientes->ConElCliente("Publico General");
QBGTOrden->setButton(0);
chrPtrTipoOrden="Remision";

SReg3Producto=QCtrProductos->PrimerProducto();
SReg3Precio=QCtrPrecios->PrimerPrecio();
SReg3Cliente=QCtrClientes->PrimerCliente();
SReg3FPago=QCtrFPago->PrimerFormaPago();
}
CQSisProdCotiza3Qt *QVentas3Qt::Producto()
{
if(SReg3Producto &&
   SReg3Precio    &&
   SReg3Cliente   &&
   SReg3FPago)
{
SiscomEscribeLog3Qt("");
return new CQSisProdCotiza3Qt(SReg3Producto,
			      SReg3Precio,
			      SReg3Cliente,
			      SReg3FPago,
			      SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLECantidad),
			      "",
			      "",
			      "",
			      "",
			      chrPtrArgumentos[10],
			      "",
			      chrPtrTipoOrden,
			      "",
			      "",
			      "");
}
else
{
SiscomEscribeLog3Qt("Falta Algo");
return 0;
}
}
void QVentas3Qt::CotizaProducto()
{
SiscomEscribeLog3Qt("");
CQSisOpProductos3Qt lCQSisOpProd3Qt(SisDatCom);
if((CQSProd3QtCotiza=Producto()))
{
SiscomEscribeLog3Qt("Esta Todo Se cotiza ....");
lCQSisOpProd3Qt.CotizaProducto(CQSProd3QtCotiza);
}
else
SiscomEscribeLog3Qt("No Se Pudo Cotizar Falta Algo ....");
}
void QVentas3Qt::CotizandoProducto()
{
CotizaProducto();
if(CQSProd3QtCotiza)
MuestraProductoCotizado();
else
SiscomEscribeLog3Qt("Por Lo Tanto No Se Muestra");
}
void QVentas3Qt::MuestraPreciosProducto()
{
QCtrPProducto->Producto((*SReg3Producto)["idproducto"]);
QCtrPProducto->ObtenPrecios();
}
void QVentas3Qt::MuestraProductoCotizado()
{
QLCDNExistencia->display((*CQSProd3QtCotiza)["Existencia"]);
QLCDNPrecio->display((*CQSProd3QtCotiza)["Precio"]);
QLCDNImporte->display((*CQSProd3QtCotiza)["Total"]);
}
void QVentas3Qt::MuestraProductos()
{
const char *lchrPtrDatos[]={"Clave",
		      "Dsc",
		      "Escala",
		      "Cantidad",
		      "Precio",
		      "TipoPrecio",
		      "Total",
			    0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrDatos,
				       QTDatos,
				       &CQSProd3QtLstCotiza);
QLCDTotalOrden->display(CQSProd3QtLstCotiza.Total());
QLCDTotalOrdenSinIva->display(CQSProd3QtLstCotiza.TotalSinIva());
QLCDIva->display(CQSProd3QtLstCotiza.Iva());
SiscomDesarrollo3Qt::AjustaColumnas(QTDatos);
}
void QVentas3Qt::ActivaAnexarALaOrden()
{
int lintSiActiva=!strcmp((*CQSProd3QtCotiza)["SePuedeVender"],"Si");
QPBAnexar->setEnabled(lintSiActiva);
if(lintSiActiva)
SiscomDesarrollo3Qt::PasaFocoControl(QPBAnexar);
}
void QVentas3Qt::CotizandoProductos()
{
if(CQSProd3QtLstCotiza.count())
{
CotizaProductos();
MuestraProductos();
}
else
QTDatos->setNumRows(0);
}
void QVentas3Qt::CotizaProductos()
{
CQSisOpProductos3Qt lCQSOProd3Qt(SisDatCom);
lCQSOProd3Qt.CotizaProductos(&CQSProd3QtLstCotiza);
}
void QVentas3Qt::GeneraIdentificador()
{
CQSisOpProductos3Qt lCQSOProd3Qt(SisDatCom);
	lCQSOProd3Qt.GeneraIdentificador(&CQSProd3QtLstCotiza);
}
void QVentas3Qt::IniciaOtraOrden()
{
SiscomDesarrollo3Qt::EliminaFilas(QTDatos);
CQSProd3QtLstCotiza.SiscomElimina();
SiscomDesarrollo3Qt::PasaFocoControl(QCtrClientes);
QPBRegistra->setEnabled(false);
}

void QVentas3Qt::CambiaCantidad(SiscomRegistro3 *pSReg3Producto,
				int pintNFila,
				int pintNColumna)
{
QCapturaCantidad3Qt lQCapCantidad3Qt(pSReg3Producto);
CotizandoProductos();
				     
}
void QVentas3Qt::CambiaTipoPrecio(SiscomRegistro3 *pSReg3Producto,
				int pintNFila,
				int pintNColumna)
{
	CQSPTabla3Qt=new CQSisPreciosTabla3Qt(&SReg3TiposPrecios,
					   pSReg3Producto,
					   this,
					   pintNFila,
					   pintNColumna);
	QTDatos->setCellWidget(pintNFila,pintNColumna,CQSPTabla3Qt);
	connect(CQSPTabla3Qt,
		SIGNAL(SignalCambioTipoPrecio(SiscomRegistro3 *,int,int)),
		SLOT(SlotCambioTipoPrecio(SiscomRegistro3 *,int,int)));
}

void QVentas3Qt::OpcionInvalida(SiscomRegistro3 *pSReg3Producto,
				int pintNFila,
				int pintNColumna)
{
SiscomEscribeLog3Qt("Opcion Invalida.....");

}

void QVentas3Qt::keyPressEvent(QKeyEvent *pQKEvent)
{
	switch(pQKEvent->key())
	{
	 case Key_F5:
	 	SiscomEscribeLog3Qt("Actualizando los datos...");
		ReInicia();
		SiscomEscribeLog3Qt("Termino.............");
	 break;
	}

}
void QVentas3Qt::ReInicia()
{
QCtrProductos->IniciaControl();
QCtrFPago->IniciaControl();
QCtrClientes->IniciaControl();
QCtrPrecios->IniciaControl();
}

void QVentas3Qt::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
void QVentas3Qt::EliminaSeleccionados()
{
CQSisProdCotiza3QtLst lCQSisProdCot3QtLst;
int lintContador;
for(lintContador=0;
    lintContador<QTDatos->numRows();
    lintContador++)
if(QTDatos->isRowSelected(lintContador,true))
      lCQSisProdCot3QtLst << CQSProd3QtLstCotiza[lintContador];
if(lCQSisProdCot3QtLst.count())
for(lintContador=0;
    lintContador<lCQSisProdCot3QtLst.count();
    lintContador++)
 CQSProd3QtLstCotiza.remove(lCQSisProdCot3QtLst[lintContador]);
}
void QVentas3Qt::ActualizaTipoOrden()
{
SiscomRegistro3 *lSisReg3Producto;
for(lSisReg3Producto=CQSProd3QtLstCotiza.first();
    lSisReg3Producto;
    lSisReg3Producto=CQSProd3QtLstCotiza.next())
 lSisReg3Producto->SiscomActualizaCampo("TipoOrden",chrPtrTipoOrden);
}

int QVentas3Qt::CapturaRemFactura(char *pchrPtrNoRemFactura)
{
if(strcmp(chrPtrTipoOrden,"Cotizacion"))
{
	QRemisionFactura lQRFactura(SisDatCom,
			    chrPtrArgumentos);
	if(lQRFactura.Opcion())
	{
   		lQRFactura.NoRemFactura(pchrPtrNoRemFactura);
   		return 1;
	}
	else
	return 0;
}
else
{
strcpy(pchrPtrNoRemFactura,"Cotizacion");
return 1;
}
}
void QVentas3Qt::ColocaNoRemisionFactura(const char *pchrPtrNoRemFactura)
{
SiscomRegistro3 *lSisReg3Producto;
SiscomEscribeLog3Qt("El numero de remision:%s",pchrPtrNoRemFactura);
for(lSisReg3Producto=CQSProd3QtLstCotiza.first();
    lSisReg3Producto;
    lSisReg3Producto=CQSProd3QtLstCotiza.next())
{
 SiscomEscribeLog3Qt("Actualizando:%s",(*lSisReg3Producto)["Clave"]);
 lSisReg3Producto->SiscomActualizaCampo("NoRemFactura",pchrPtrNoRemFactura);
}
}
