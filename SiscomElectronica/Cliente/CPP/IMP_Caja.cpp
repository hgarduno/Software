#include <IMP_Caja.h>
#include <IMP_OrdenElectronica.h>
#include <IMP_CapturaPago.h>
#include<SiscomDesarrollo3Qt++.h>
#include <QIconViewItemOrdenCaja.h>

#include <CQSisOpeOrdenCaja.h>
#include <CQSisDatosOrdenCaja.h>

#include <ControladorOrdenes.h>

#include <qpushbutton.h>
#include <qmessagebox.h>
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
show();
}

QCaja::~QCaja()
{

}
void QCaja::ConectaSlots()
{
connect(QPBActualiza,
	SIGNAL(clicked()),
	SLOT(SlotActualizaOrdenes()));

connect(QPBMOrden,
	SIGNAL(clicked()),
	SLOT(SlotModificaOrden()));
connect(QIVOrdenes,
	SIGNAL(onItem(QIconViewItem *)),
	SLOT(SlotSobreLaOrden(QIconViewItem *)));
connect(QIVOrdenes,
	SIGNAL(doubleClicked(QIconViewItem *)),
	SLOT(SlotVendeOrden(QIconViewItem *)));
connect(QIVOrdenes,
	SIGNAL(returnPressed(QIconViewItem *)),
	SLOT(SlotVendeOrden(QIconViewItem *)));
connect(QIVOrdenes,
	SIGNAL(selectionChanged(QIconViewItem *)),
	SLOT(SlotOtraOrdenSeleccionada(QIconViewItem *)));

}
void QCaja::SlotOtraOrdenSeleccionada(QIconViewItem *pQIVItemOrden)
{
if(pQIVItemOrden)
{
SisReg3Orden=((QIconViewItemOrdenCaja *)pQIVItemOrden)->Orden();
SisReg3Cliente=((QIconViewItemOrdenCaja *)pQIVItemOrden)->Cliente();
SiscomContenidoRegistro3(SisReg3Cliente);
}
}
void QCaja::SlotModificaOrden()
{
if(SisReg3Orden)
{
ProductosE *lPProductosE;
ProductosOrden();
CopiaDatosOrden();
PCliente.SiscomActualizaCampo("IdPersona",(*SisReg3Cliente)["IdPersona"]);
emit SignalModificaOrdenCaja((*SisReg3Orden)["idventa"],
			    PProductos,
			    &PCliente);
}

else
MensajeSeleccionarOrden();
}
void QCaja::SlotCargaOrden(QIconViewItem *pQIVItemOrden)
{
SisReg3Orden=((QIconViewItemOrdenCaja *)pQIVItemOrden)->Orden();
SisReg3Cliente=((QIconViewItemOrdenCaja *)pQIVItemOrden)->Cliente();
SiscomContenidoRegistro3(SisReg3Orden);
SiscomContenidoRegistro3(SisReg3Cliente);
}
void QCaja::SlotVendeOrden(QIconViewItem *pQIVItemOrden)
{
if(pQIVItemOrden)
{
SisReg3Orden=((QIconViewItemOrdenCaja *)pQIVItemOrden)->Orden();
SisReg3Cliente=((QIconViewItemOrdenCaja *)pQIVItemOrden)->Cliente();
VendeOrden();
}
else
MensajeSeleccionarOrden();
}
/* Martes 15 de Enero del 2013
 * Se buscara que cuando el raton se pase sobre la orden
 * de muestre un tool tip con la informacion de la 
 * orden (ticket
 */
void QCaja::SlotSobreLaOrden(QIconViewItem *pQIVItemOrden)
{
}
void QCaja::SlotActualizaOrdenes()
{
ConsultaOrdenesPendientes();
MuestraOrdenesPendientes();
}
void QCaja::VendeOrden()
{
 if(SisReg3Orden &&
    CapturaPago())
 {
 EnviaVenta();
 OrdenesPendientes();
 }
 else
 QMessageBox::information(this,
 			  "Aviso del sistema",
			  "NO se ha seleccionado una orden");
}
void QCaja::EnviaVenta()
{
CQSisOpeOrdenCaja lCQSOOCaja(SisDatCom);
lCQSOOCaja.VendeOrden(new CQSisDatosOrdenCaja(chrPtrArgumentos[0],
					      chrArrPago,
					      chrPtrCambio,
					      SisReg3Orden));
}
int QCaja::CapturaPago()
{
QCapturaPago lQCPago(SisDatCom,
		     (*SisReg3Orden)["total"]);
if(lQCPago.ImporteValido())
{
chrPtrCambio=lQCPago.Cambio();
lQCPago.Recibi(chrArrPago);
SiscomEscribeLog3Qt("Se pago con %s y el cambio:%s",
		    chrArrPago,
		    chrPtrCambio);
return 1;
}
else
return 0;
}
void QCaja::IniciaVariables()
{
OrdenesPendientes();
}

void QCaja::OrdenesPendientes()
{
ConsultaOrdenesPendientes();
MuestraOrdenesPendientes();

}
void QCaja::ConsultaOrdenesPendientes()
{
CQSisOpeOrdenCaja lCQSOOCaja(SisDatCom);
lCQSOOCaja.OrdenesPendientes(new CQSisDatosOrdenCaja(chrPtrArgumentos[0]),&CQSOCaja);
SiscomContenidoRegistro4Log(&CQSOCaja);
}
void QCaja::MuestraOrdenesPendientes()
{
int lintContador;
QIconViewItemOrdenCaja *lQIVIOCaja;
QIVOrdenes->clear();
for(lintContador=0;
    lintContador<CQSOCaja.count();
    lintContador++)
{
SiscomEscribeLog3Qt("Agregando:%s",
		    CQSOCaja.CampoRegistroSubGrupo(lintContador,
		    				   0,
						   0,
						   "idventa"));
lQIVIOCaja=new QIconViewItemOrdenCaja(
		CQSOCaja.RegistroSubGrupo(lintContador,0,0),
		CQSOCaja.RegistroSubGrupo(lintContador,1,0),
		QIVOrdenes);
			
QIVOrdenes->insertItem(lQIVIOCaja);
}
}
void QCaja::ModificandoOrden()
{
ProductosOrden();
CopiaDatosOrden();
CopiaDatosCliente();
CargaLaOrden();
}
void QCaja::CargaLaOrden()
{

}
void QCaja::CopiaDatosCliente()
{
SiscomContenidoRegistro3(SisReg3Cliente);
}
void QCaja::CopiaDatosOrden()
{
ProductoE *lProductoE;
for(lProductoE=PProductos->first();
    lProductoE;
    lProductoE=PProductos->next())
{
   lProductoE->SiscomActualizaCampo("IdExpendio",chrPtrArgumentos[0]);
}
}
void QCaja::ProductosOrden()
{
PProductos=new ProductosE;
IdentificadorOrdenes lIdOrdenes;
	lIdOrdenes << 
	new IdentificadorOrden("","ProductosOrdenCajaCentral") <<
	new IdentificadorOrden("",(*SisReg3Orden)["idventa"]);
OpProductosOrdenes lOpProdOrdenes(SisDatCom,
				  &lIdOrdenes);
lOpProdOrdenes.SiscomConsulta("ConsultaControladorOrdenes",
			       (QPtrList<SiscomInformacion> *)PProductos);
(*PProductos) << (*PProductos)[0];
SiscomEscribeLog3Qt("Se Regresaron %d",PProductos->count());
}
void QCaja::MensajeSeleccionarOrden()
{
 QMessageBox::information(this,
 			  "Aviso del sistema",
			  "NO se ha seleccionado una orden");
}
