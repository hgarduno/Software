#include <QtImpPuntoDeVenta.h>
#include <QtImpCapturaCliente.h>
#include <QtImpCapturaDireccion.h>
#include <QtImpCambioPrecio.h>
#include <QtImpSeleccionaProducto.h>
#include <QtImprimePuntoVenta.h>
#include <QtImpCancelarFolio.h>
#include <zImpresionPuntoVenta.h>
#include <zSiscomDesarrollo4.h>
#include <QCtrlConceptosExistencias.h>
#include <QCtrlTiendasEntrega.h>
#include <QCtrlTipoVentas.h>
#include <QCtrlFormasEntrega.h>
#include <QCtrlFinanciadoras.h>
#include <QCtrlVendedores.h>
#include <QCtrlPlazos.h>
#include <QCtrlProveedoresSS.h>
#include <QtImprimeFactura.h>


#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <zOperacionesServiSNTE.h>
#include <zProducto.h>
#include <zOrden.h>
#include <zCliente.h>
#include <zDireccion.h>

#include <qpushbutton.h>
#include <qlineedit.h>
#include <qdatetime.h>
#include <qcheckbox.h>
#include <qstring.h>
#include <qlcdnumber.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qmessagebox.h>


QtImpPuntoDeVenta::QtImpPuntoDeVenta(QWidget *pQWParent,
				     const char *pchrPtrName):
				     PuntoDeVenta(pQWParent,pchrPtrName),
				     zSiscomTipoVenta(0),
				     zSiscomFinanciadora(0),
				     zSiscomVendedor(0),
				     zSiscomFormaEntrega(0),
				     zPerCliente(0),
				     zPerDireccion(0),
				     intClienteRegistrado(0),
				     intProductoSeleccionado(-1),
				     intPorCodigoBarras(0),
				     intPorClaveProveedor(1)

{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 IniciaControles();
 IniciaVariables();
 ConectaSlots();
}

void QtImpPuntoDeVenta::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpPuntoDeVenta::ConectaSlots()
{
connect(QCtrTipoVenta,
	SIGNAL(SignalTipoVenta(zSiscomRegistro *)),
	SLOT(SlotTipoVenta(zSiscomRegistro *)));

connect(QCtrFinanciadora,
	SIGNAL(SignalFinanciadora(zSiscomRegistro *)),
	SLOT(SlotFinanciadora(zSiscomRegistro *)));
connect(QCtrPlazos,
	SIGNAL(SignalPlazo(zSiscomRegistro *)),
	SLOT(SlotPlazo(zSiscomRegistro *)));
connect(QCtrVendedores,
	SIGNAL(SignalVendedor(zSiscomRegistro *)),
	SLOT(SlotVendedor(zSiscomRegistro *)));
connect(QCtrFormaEntrega,
	SIGNAL(SignalFormaEntrega(zSiscomRegistro *)),
	SLOT(SlotFormaEntrega(zSiscomRegistro *)));
/*
connect(QLEFolio,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoACapturaCliente()));
*/
connect(QPBCapturaCliente,
	SIGNAL(clicked()),
	SLOT(SlotCapturaCliente()));
connect(QPBCapturaDireccion,
	SIGNAL(clicked()),
	SLOT(SlotCapturaDireccion()));
connect(QLETelefono,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoAFormaEntrega()));
connect(QLETelefono,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoTelefono(const QString &)));
connect(QLECodigoBarras,
	SIGNAL(returnPressed()),
	SLOT(SlotCodigoBarras()));
connect(QPBAgregar,
	SIGNAL(clicked()),
	SLOT(SlotAgregarOrden()));
connect(QPRegistrarVenta,
	SIGNAL(clicked()),
	SLOT(SlotRegistraVenta()));
connect (QPBImprimir,
	SIGNAL(clicked()),
	SLOT(SlotImprimeFactura()));
connect(QPBCambiarPrecio,
	SIGNAL(clicked()),
	SLOT(SlotCambiarPrecio()));
connect(QTDetalleFactura,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionaProducto(int,int,int,const QPoint &)));

connect(QLECantidadCotiza,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoACodigoBarras()));

connect(QPBNuevaVenta,
	SIGNAL(clicked()),
	SLOT(SlotNuevaOrden()));
connect(QPBEliminar,
	SIGNAL(clicked()),
	SLOT(SlotEliminaProducto()));
connect(QCtrProveedores,
	SIGNAL(SignalProveedor(zSiscomRegistro *)),
	SLOT(SlotSeleccionaProveedor(zSiscomRegistro *)));
connect(QPBProductosProveedor,
	SIGNAL(clicked()),
	SLOT(SlotProductosProveedor()));
connect(QLENumeroProducto,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturoNumeroProducto()));
connect(QPBCancelarVenta,
	SIGNAL(clicked()),
	SLOT(SlotCancelarFolio()));
}
void QtImpPuntoDeVenta::SlotCapturandoTelefono(const QString &pQStrTelefono)
{
	LogSiscom("%s",(const char *)pQStrTelefono);
		if(pQStrTelefono=="04")
		{
			LogSiscom("Inicia Captura Celular");
		}
		if(pQStrTelefono=="01")
		{
			LogSiscom("Inicia Captura Telefono fijo");
		}
		
}
void QtImpPuntoDeVenta::SlotCancelarFolio()
{
CancelarFolio();
}
void QtImpPuntoDeVenta::SlotCapturoNumeroProducto()
{
    if(QLENumeroProducto->text().isEmpty())
    {
	QPBProductosProveedor->setEnabled(true);
	zSiscomQt3::Foco(QPBProductosProveedor);
    }
    else
	ObtenProductoProveedorNumProducto();
}
void QtImpPuntoDeVenta::SlotProductosProveedor()
{
zSiscomRegistro *lzSisRegProducto;
if(zSiscomRegProveedor)
{
QtImpSeleccionaProducto lQtImpSelProducto(zSisConexion,zSiscomRegProveedor);
if((lzSisRegProducto=lQtImpSelProducto.Producto()))
{
     QLECodigoBarras->setText((const char *)(*lzSisRegProducto)["codigobarras"]);
     SlotCodigoBarras();
}
}
else
QMessageBox::information(this,"Aviso del Sistema","Se debe seleccionar un proveedor");
}
void QtImpPuntoDeVenta::SlotFocoAFormaEntrega()
{
   FocoAFormaEntrega();
}
void QtImpPuntoDeVenta::SlotSeleccionaProveedor(zSiscomRegistro *pzSisRegProveedor)
{
zSiscomRegProveedor=pzSisRegProveedor;
QLENumeroProducto->setEnabled(true);
zSiscomQt3::Foco(QLENumeroProducto);
}
void QtImpPuntoDeVenta::SlotEliminaProducto()
{
	if(intProductoSeleccionado>=0)
	{
	     zProdsOrden.Elimina(intProductoSeleccionado);
	     if(zProdsOrden.NNodos())
	     CotizaOrden();
	     MuestraCotizandoOrden();
	     MuestraInformacionCredito();
	     QPBEliminar->setEnabled(false);
	     QPBCambiarPrecio->setEnabled(false);
	     QCtrProveedores->setEnabled(false);
	     QLENumeroProducto->setEnabled(false);
	     zSiscomQt3::Foco(QLECantidadCotiza);
	}
}
void QtImpPuntoDeVenta::SlotNuevaOrden()
{
   QPBCancelarVenta->setEnabled(false);
   ReIniciaVenta(); 
   zSiscomQt3::Foco(QCtrTipoVenta);
   QLETelefono->setEnabled(false);
   QCtrFormaEntrega->setEnabled(false);
   QLECantidadCotiza->setEnabled(false);   
   QCtrProveedores->setEnabled(false);
   QLENumeroProducto->setEnabled(false);
}
void QtImpPuntoDeVenta::SlotFocoACodigoBarras()
{
if(intPorClaveProveedor)
{
	QCtrProveedores->setEnabled(true);
	zSiscomQt3::Foco(QCtrProveedores);
}

else
zSiscomQt3::Foco(QLECodigoBarras);
}
void QtImpPuntoDeVenta::SlotSeleccionaProducto(int pintNProducto,
					       int,
					       int,
					       const QPoint &)
{
   if(pintNProducto!=-1)
   {
    SeleccionandoProducto(pintNProducto);
    intProductoSeleccionado=pintNProducto;
   }
}
void QtImpPuntoDeVenta::SlotCambiarPrecio()
{
QtImpCambioPrecio lQCPrecio(zProdCambiar);
CotizaOrden();
MuestraCotizandoOrden();
MuestraInformacionCredito();
QPBCambiarPrecio->setEnabled(false);
QPBEliminar->setEnabled(false);
zSiscomQt3::Foco(QLECantidadCotiza);
}
void QtImpPuntoDeVenta::SlotPlazo(zSiscomRegistro *pzSiscomPlazo)
{
      zSiscomPlazo=pzSiscomPlazo; 
      QCtrVendedores->setEnabled(true);
      zSiscomQt3::Foco(QCtrVendedores);
}
void QtImpPuntoDeVenta::SlotTipoVenta(zSiscomRegistro *pzSiscomTipoVenta)
{
	zSiscomTipoVenta=pzSiscomTipoVenta;
	VeSiSeHabilitaFinanciera();
}
void QtImpPuntoDeVenta::SlotFinanciadora(zSiscomRegistro *pzSiscomFinanciadora)
{
	zSiscomFinanciadora=pzSiscomFinanciadora;
	VeSiSeHabilitaConcepto();
}

void QtImpPuntoDeVenta::SlotConcepto(zSiscomRegistro *pzSiscomConcepto)
{
/*	zSiscomConceptosExis=pzSiscomConcepto;
	QCtrTiendasEntrega->setEnabled(true);
	zSiscomQt3::Foco(QCtrTiendasEntrega);
*/
}
void QtImpPuntoDeVenta::SlotTienda(zSiscomRegistro *pzSiscomTiendasEntrega)
{
    zSiscomTiendasEntrega=pzSiscomTiendasEntrega;
    QCtrVendedores->setEnabled(true);
    zSiscomQt3::Foco(QCtrVendedores);
}
void QtImpPuntoDeVenta::SlotVendedor(zSiscomRegistro *pzSiscomVendedor)
{
  zSiscomVendedor=pzSiscomVendedor;
  QLEFolio->setEnabled(true);
  /*zSiscomQt3::Foco(QLEFolio); */
  SlotFocoACapturaCliente();
  ObtenFolio();
  
}
void QtImpPuntoDeVenta::SlotFormaEntrega(zSiscomRegistro *pzSiscomFormaEntrega )
{
	zSiscomFormaEntrega=pzSiscomFormaEntrega;
	if(intPorCodigoBarras)
	QLECodigoBarras->setEnabled(true);
	QLECantidadCotiza->setEnabled(true);
	zSiscomQt3::Foco(QLECantidadCotiza);
}
void QtImpPuntoDeVenta::SlotFocoAFecha()
{
 QLEFecha->setEnabled(true);
 zSiscomQt3::Foco(QLEFecha);
}
void QtImpPuntoDeVenta::SlotFocoACapturaCliente()
{
	QPBCapturaCliente->setEnabled(true);
	zSiscomQt3::Foco(QPBCapturaCliente);
}

void QtImpPuntoDeVenta::SlotCapturaCliente()
{
QtImpCapturaCliente lQtImpCapCliente(zSisConexion,zSiscomTipoVenta);
if(lQtImpCapCliente.Aceptar())
{
 zPerCliente=lQtImpCapCliente.Cliente();
 MuestraDatosCliente();
 if((intClienteRegistrado=lQtImpCapCliente.ClienteRegistrado()))
 {
 DireccionCliente();
 MuestraDatosDireccion();
 FocoAFormaEntrega();
 }
 else
 FocoACapturaDireccion();

}
}
void QtImpPuntoDeVenta::SlotCapturaDireccion()
{
QtImpCapturaDireccion lQtImpCapDireccion(intClienteRegistrado);
lQtImpCapDireccion.Persona(zPerCliente);
lQtImpCapDireccion.CapturandoDireccion();
if(lQtImpCapDireccion.Aceptar())
{
  zPerDireccion=lQtImpCapDireccion.Direccion();
  if(!intClienteRegistrado)
  RegistraDireccion();
  if(intClienteRegistrado==2)
  ActualizaDireccion();
  MuestraDatosDireccion();
  QLETelefono->setEnabled(true); 
  zSiscomQt3::Foco(QLETelefono);
  /*
  FocoAFormaEntrega();
  */
}
}
void QtImpPuntoDeVenta::SlotCodigoBarras()
{
	CotizandoProducto();
        zSiscomQt3::Foco(QPBAgregar);
}

void QtImpPuntoDeVenta::SlotAgregarOrden()
{
    CotizandoOrden();
    QCtrProveedores->setEnabled(false);
    QLENumeroProducto->setEnabled(false);
    zSiscomQt3::Foco(QLECantidadCotiza);
    QPBAgregar->setEnabled(false);
}


void QtImpPuntoDeVenta::SlotRegistraVenta()
{
   RegistrandoVenta();
}


void QtImpPuntoDeVenta::SlotImprimeFactura()
{
    EnviaDatosALogSiscom();
    EnviaProductosLog();
    imprimeFactura();
    QPBCancelarVenta->setEnabled(true);
}
void QtImpPuntoDeVenta::IniciaControles()
{
 PorClaveProveedor();
 QCtrVendedores->Servidor(zSisConexion);
 QCtrVendedores->IniciaControl("Vendedores");
 QCtrTipoVenta->Servidor(zSisConexion);
 QCtrTipoVenta->IniciaControl();
 QCtrFormaEntrega->Servidor(zSisConexion);
 QCtrFormaEntrega->IniciaControl();
 QCtrFinanciadora->Servidor(zSisConexion);
 QCtrFinanciadora->IniciaControl();
 QCtrPlazos->Servidor(zSisConexion);
 QCtrPlazos->IniciaControl();
 QCtrProveedores->Servidor(zSisConexion);
 if(intPorClaveProveedor)
 QCtrProveedores->IniciaControlPorClave();
 else
 QCtrProveedores->IniciaControl();
}
void QtImpPuntoDeVenta::FocoACapturaDireccion()
{
 QPBCapturaDireccion->setEnabled(true);
 zSiscomQt3::Foco(QPBCapturaDireccion);
}

void QtImpPuntoDeVenta::IniciaVariables()
{
   zSiscomQt3::Foco(QCtrTipoVenta);
}

void QtImpPuntoDeVenta::RegistraDireccion()
{
  zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"RegistraDireccion");
  lzOpServiSNTE.RegistraDireccion(zPerDireccion);
}

void QtImpPuntoDeVenta::FocoAFormaEntrega()
{
 QLETelefono->setEnabled(true);
 QCtrFormaEntrega->setEnabled(true);
 zSiscomQt3::Foco(QCtrFormaEntrega);
}

void QtImpPuntoDeVenta::VeSiSeHabilitaFinanciera()
{
int lintEsCredito;
   if(zSiscomTipoVenta)
   {
     lintEsCredito=!strcmp((const char *)(*zSiscomTipoVenta)["nombre"],"Credito");
     QCtrFinanciadora->setEnabled(lintEsCredito);
     if(lintEsCredito)
       zSiscomQt3::Foco(QCtrFinanciadora);
   
     else
     {
/*
        QCtrConceptosExis->setEnabled(true);
	    zSiscomQt3::Foco(QCtrConceptosExis);
*/
	    QCtrPlazos->setEnabled(false);
 	    QCtrVendedores->setEnabled(true);
	    zSiscomQt3::Foco(QCtrVendedores);
     }
   }
}
void QtImpPuntoDeVenta::VeSiSeHabilitaConcepto()
{
int lintDifNinguna;
  if(zSiscomFinanciadora)
  {
    lintDifNinguna=strcmp((const char *)(*zSiscomFinanciadora)["nombre"],"Ninguna");
    QCtrPlazos->setEnabled(lintDifNinguna);
    if(lintDifNinguna)
      zSiscomQt3::Foco(QCtrPlazos);
    else
    {
       //zSiscomQt3::Foco(QCtrConceptosExis);
 	   QCtrVendedores->setEnabled(true);
       zSiscomQt3::Foco(QCtrVendedores);
    }
  }
}

void QtImpPuntoDeVenta::MuestraDatosDireccion()
{
 zSiscomRegistro *lzSisRegPaso=(zSiscomRegistro *)zPerDireccion;
 QString lqstrDireccion((const char *)(*lzSisRegPaso)["Calle"]);
lqstrDireccion+=QString((const char *)" ") +
		 (const char *)(*lzSisRegPaso)["NumInterior"] +
		 (const char *)" " +
		 (const char *)(*lzSisRegPaso)["NumExterior"] +
		 (const char *)" " +
		 (const char *)(*lzSisRegPaso)["Colonia"];
QLEDireccion->setText(lqstrDireccion);	
QPBCapturaDireccion->setEnabled(true);
QPBCapturaDireccion->setText("Actualizar Direccion");
intClienteRegistrado=2;
}


void QtImpPuntoDeVenta::MuestraDatosCliente()
{
zSiscomRegistro *lzSisRegPaso=(zSiscomRegistro *)zPerCliente;
QString lqstrCliente((const char *)(*lzSisRegPaso)["Nombre"]);
lqstrCliente+=QString((const char *) " ")                      	+
		      (const char *)(*lzSisRegPaso)["APaterno"] +
		      (const char *)" " 			+
		      (const char *)(*lzSisRegPaso)["AMaterno"];
QLECliente->setText(lqstrCliente);
}
void QtImpPuntoDeVenta::CotizaProducto()
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"CotizaProducto");
zProdCotizar=lzOpeServiSNTE.CotizaProducto(zSiscomQt3::Texto(QLECantidadCotiza),
					   zSiscomQt3::Texto(QLECodigoBarras));
/*
QPBAgregar->setEnabled(zProdCotizar);
*/
}
void QtImpPuntoDeVenta::MuestraProductoCotizado()
{
    if(zProdCotizar)
    {
    QLEDescripcionProducto->setText((const char *)(*zProdCotizar)["nombreproducto"]);
    QLEModelo->setText((const char *)(*zProdCotizar)["modelo"]);
    QLESerie->setText((const char *)(*zProdCotizar)["serie"]);
    QLEPrecioVenta->setText((const char *)(*zProdCotizar)["preciogeneral"]);
    QLCDImporte->display((const char *)(*zProdCotizar)["Importe"]);
    QLCDExistencia->display((const char *)(*zProdCotizar)["existencia"]);
    }
    else
    {
        QString informacion = "El producto NO se encuentra en la base: ";
        informacion = informacion + QLECodigoBarras->text();
        QMessageBox::information(this,"Aviso del sistema",informacion);
        zSiscomQt3::Foco(QLECodigoBarras);
    }
}
void QtImpPuntoDeVenta::CotizandoProducto()
{
const char *lchrPtrMensaje;
	CotizaProducto();
	lchrPtrMensaje=zProdCotizar->SePuedeVender();
	HabilitaAnexarProducto(lchrPtrMensaje ? 0 : 1);
	MuestraMensajeSePuedeVender(lchrPtrMensaje);	
	MuestraProductoCotizado();
}
void QtImpPuntoDeVenta::CotizaOrden()
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"CotizaOrden");
zOrdenVenta.TipoVenta(zSiscomTipoVenta);
if(zSiscomFinanciadora)
{
zOrdenVenta.Financiadora(zSiscomFinanciadora);
zOrdenVenta.Plazo(zSiscomPlazo);
}
zOrdenVenta.Productos(&zProdsOrden);
lzOpeServiSNTE.CotizaOrden(&zOrdenVenta);
}
void QtImpPuntoDeVenta::CotizandoOrden()
{
	AgregaProductoOrden();
	HabilitaInstruccionesEntrega();
   	CotizaOrden();
	MuestraCotizandoOrden();
	MuestraInformacionCredito();
}
void QtImpPuntoDeVenta::MuestraInformacionCredito()
{
zSiscomRegistro *lzSisRegistro=zOrdenVenta.Credito();
if(lzSisRegistro)
  QTEInfoCredito->setText(QString("Plazo:") 			   		+
  			  (const char *)(*lzSisRegistro)["Plazo"] 		+ 
			  "\n" 					   		+
			  "Pagos Quincenales:"			   		+
			  (const char *)(*lzSisRegistro)["DesQuincenal"]	+
			  "\n"							+
			  "Pago Total:"						+
			  (const char *)(*lzSisRegistro)["PagoTotal"]);
else
LogSiscom("NO Llego la informacion del credio");
}
void QtImpPuntoDeVenta::MuestraCotizandoOrden()
{
 int lintContador;
 zSiscomRegistro *lzSisRegistro;
 QTDetalleFactura->setNumRows(zProdsOrden.NNodos());
 for(lzSisRegistro=zProdsOrden.Primer(),
     lintContador=0;
     lzSisRegistro;
     lzSisRegistro=zProdsOrden.Siguiente(),
     lintContador++)
 {
   QTDetalleFactura->setText(lintContador,0,(const char *)(*lzSisRegistro)["numproducto"]);
   QTDetalleFactura->setText(lintContador,1,(const char *)(*lzSisRegistro)["modelo"]);
   QTDetalleFactura->setText(lintContador,2,(const char *)(*lzSisRegistro)["nombreproducto"]);
   QTDetalleFactura->setText(lintContador,3,(const char *)(*lzSisRegistro)["Cantidad"]);
   QTDetalleFactura->setText(lintContador,4,(const char *)(*lzSisRegistro)["preciogeneral"]);
   QTDetalleFactura->setText(lintContador,5,(const char *)(*lzSisRegistro)["Importe"]);
 }
 QLCDTotal->display((const char *)zOrdenVenta["Total"]);
 zSiscomQt3::AjustaColumnasTabla(QTDetalleFactura);
}
void QtImpPuntoDeVenta::AgregaProductoOrden()
{
     zProdsOrden << zProdCotizar;
}
void QtImpPuntoDeVenta::AgregaVentaACredito()
{
zSiscomRegistro *lzSisRegCredito=zOrdenVenta.Credito();
   if(zSiscomFinanciadora)
   {
     if(zSiscomTipoVenta->CampoInt("idtipoventa")==2)
     {
       	zVentaCredito.IdFinanciadora((*zSiscomFinanciadora)["idfinanciadora"]);
	zVentaCredito.IdPlazo((*zSiscomPlazo)["idplazo"]);
	zVentaCredito.PagoQuincenal((*lzSisRegCredito)["DesQuincenal"]);
	zVentaCredito.PagoTotal((*lzSisRegCredito)["PagoTotal"]);
	zVentaOrden.Credito(&zVentaCredito);
     }
    }
}
void QtImpPuntoDeVenta::RegistrandoVenta()
{
const char *lchrPtrTelefono;
	lchrPtrTelefono=strdup((const char *)QLETelefono->text());
  zVentaOrden.IdTipoVenta((*zSiscomTipoVenta)["idtipoventa"]);
  zVentaOrden.IdVendedor((*zSiscomVendedor)["idvendedor"]);
  zVentaOrden.IdTiendaEntrega((*zSiscomVendedor)["idvendedor"]);
  zVentaOrden.Folio((const unsigned char *)zSiscomQt3::Texto(QLEFolio));
  zVentaOrden.IdCliente((*zPerCliente)["IdPersona"]);
  zVentaOrden.NombreVendedor((*zSiscomVendedor)["nombre"]);
  zVentaOrden.Nombre((*zPerCliente)["Nombre"]);
  zVentaOrden.APaterno((*zPerCliente)["APaterno"]);
  zVentaOrden.AMaterno((*zPerCliente)["AMaterno"]);
  zVentaOrden.RFC((*zPerCliente)["RFC"]);
  zVentaOrden.IdDireccion((*zPerDireccion)["IdDireccion"]);
  zVentaOrden.Calle((*zPerDireccion)["Calle"]);
  zVentaOrden.NumExterior((*zPerDireccion)["NumExterior"]);
  zVentaOrden.NumInterior((*zPerDireccion)["NumInterior"]);
  zVentaOrden.Colonia((*zPerDireccion)["Colonia"]);
  zVentaOrden.DelegMunic((*zPerDireccion)["DelegMunic"]);
  zVentaOrden.CodigoPostal((*zPerDireccion)["CodigoPostal"]);
  zVentaOrden.Referencias((*zPerDireccion)["Referencias"]);
  zVentaOrden.FormaEntrega(zSiscomFormaEntrega);
  zVentaOrden.Telefono(lchrPtrTelefono);
  AgregaVentaACredito();
  zVentaOrden.Orden(&zOrdenVenta);
  zVentaOrden.InstruccionesEntrega(strdup((const char *)QTEInstrucionesEntrega->text()));
  zOperacionesServiSNTE lzOpeServiSNTEVenta(zSisConexion,"RegistraVenta");
  lzOpeServiSNTEVenta.RegistraVenta(&zVentaOrden);
  QLEFecha->setText((const char *)(zVentaOrden)["Fecha"]);
  QLEFecha->setReadOnly(true);
  QPBImprimir->setEnabled(true);
  zSiscomQt3::Foco(QPBImprimir);
  QPRegistrarVenta->setEnabled(false);
  QPBNuevaVenta->setEnabled(true);
  QPBAgregar->setEnabled(false);
  QMessageBox::information(this,"Aviso del sistema",
                    "Venta registro exitoso!                    ");
/*
  free((void *)lchrPtrTelefono);
*/
}
void QtImpPuntoDeVenta::HabilitaInstruccionesEntrega()
{
 QTEInstrucionesEntrega->setEnabled(zProdsOrden.NNodos()); 
}
void QtImpPuntoDeVenta::EnviaProductosLog()
{
    zProductos *lzProductos=zVentaOrden.Orden()->Productos();
    zProducto *lzProducto;
    for(lzProducto=(zProducto *)lzProductos->Primer();
        lzProducto;
        lzProducto=(zProducto *)lzProductos->Siguiente())
    {
        SiscomRegistroLog2(lzProducto);
        LogSiscom("Producto: %s %s %s %s \n",(*lzProducto)["codigobarras"],
                        (*lzProducto)["nombreproducto"],
                        (*lzProducto)["idpreciogeneral"],
                        (*lzProducto)["Importe"]);
    }
}

void QtImpPuntoDeVenta::EnviaDatosALogSiscom()
{
  if(zSiscomFinanciadora)
  LogSiscom("Imprimiendo Factura\n\
  	    Fecha: %S \n\
  	    Tienda: %s \n\
  	    TipoVenta: %s \n\
	    Financiadora: %s \n\
	    Nombre Cliente: %s %s %s \n\
	    Calle: %s \n\
	    NumExt: %s\n\
	    NumInt: %s\n\
	    Colonia: %s\n\
	    Poblacion: %s \n\
	    CP: %s \n\
	    InstEntrega: %s",
  (const char *)zVentaOrden["Fecha"],
  (const char *)zVentaOrden["IdTiendaEntrega"],
  (const char *)zVentaOrden["IdTipoVenta"],
  (const char *)(*zSiscomFinanciadora)["IdFinanciadora"],
  (const char *)zVentaOrden["Nombre"],
  (const char *)zVentaOrden["APaterno"],
  (const char *)zVentaOrden["AMaterno"],
  (const char *)zVentaOrden["Calle"],
  (const char *)zVentaOrden["NumExterior"],
  (const char *)zVentaOrden["NumInterior"],
  (const char *)zVentaOrden["Colonia"],
  (const char *)zVentaOrden["DelegMunic"],
  (const char *)zVentaOrden["CodigoPostal"],
  (const char *)zVentaOrden["InstruccionesE"]);
  else
  LogSiscom("Imprimiendo Factura\n"
  	    "Fecha: %s  (%s) (%s) (%s)\n"
  	    "Tienda: %s\n"
  	    "TipoVenta: %s \n"
	    "Nombre Cliente: %s %s %s \n"
	    "Calle: %s \n"
	    "NumExt: %s NumInt: %s \n"
	    "Colonia: %s Poblacion: %s CP: %s\n"
	    "InstEntrega: %s",
  (const char *)zVentaOrden["Fecha"],
  (const char *)zVentaOrden["Anio"],
  (const char *)zVentaOrden["Mes"],
  (const char *)zVentaOrden["Dia"],
  (const char *)zVentaOrden["IdTiendaEntrega"],
  (const char *)zVentaOrden["IdTipoVenta"],
  (const char *)zVentaOrden["Nombre"],
  (const char *)zVentaOrden["APaterno"],
  (const char *)zVentaOrden["AMaterno"],
  (const char *)zVentaOrden["Calle"],
  (const char *)zVentaOrden["NumExterior"],
  (const char *)zVentaOrden["NumInterior"],
  (const char *)zVentaOrden["Colonia"],
  (const char *)zVentaOrden["DelegMunic"],
  (const char *)zVentaOrden["CodigoPostal"],
  (const char *)zVentaOrden["InstruccionesE"]);
}

void QtImpPuntoDeVenta::ValidandoCliente()
{


}

void QtImpPuntoDeVenta::imprimeFactura()
{
zImpresionPuntoVenta lzImpPuntoVenta;
lzImpPuntoVenta.Orden(&zOrdenVenta);
lzImpPuntoVenta.Venta(&zVentaOrden);
QtImprimePuntoVenta lQtImpPuntoVenta(zSisConexion,this);
lQtImpPuntoVenta.MargenX(23);
lQtImpPuntoVenta.MargenY(5);
lQtImpPuntoVenta.Venta(&lzImpPuntoVenta);
lQtImpPuntoVenta.Imprime();
}

void QtImpPuntoDeVenta::ReIniciaVenta()
{
   zSiscomTipoVenta=0;
   zSiscomFinanciadora=0;
   zSiscomConceptosExis=0;
   zSiscomTiendasEntrega=0;
   zSiscomVendedor=0;
   zSiscomFormaEntrega=0;
   if(zPerCliente)
    delete zPerCliente;
    if(zPerDireccion)
     delete zPerDireccion;
    QTDetalleFactura->setNumRows(0); 
    zProdsOrden.Libera();
    QCtrFinanciadora->setEnabled(false);
    QCtrVendedores->setEnabled(false);
    QLEFolio->setEnabled(false);
    QLEFecha->setEnabled(false);
    QPBCapturaCliente->setEnabled(false);
    QPBCapturaDireccion->setEnabled(false);
    QPBImprimir->setEnabled(false);
    QPBNuevaVenta->setEnabled(false);
}

void QtImpPuntoDeVenta::SeleccionandoProducto(int pintNProducto)
{
  QTDetalleFactura->selectRow(pintNProducto); 
  QPBCambiarPrecio->setEnabled(true);
  QPBEliminar->setEnabled(true);
  zProdCambiar=(zProducto *)zProdsOrden[pintNProducto];
}
void QtImpPuntoDeVenta::DireccionCliente()
{
zPerDireccion=zPerCliente->Direccion();
}
void QtImpPuntoDeVenta::PorClaveProveedor()
{
const char *lchrPtrPorClaveProveedor=getenv("ProveedorPorClave");
if(lchrPtrPorClaveProveedor)
intPorClaveProveedor=1;
else
intPorClaveProveedor=0;
}
void QtImpPuntoDeVenta::HabilitaAnexarProducto(bool pbSePuedeVender)
{
QPRegistrarVenta->setEnabled(pbSePuedeVender);
QPBAgregar->setEnabled(pbSePuedeVender);
}
void QtImpPuntoDeVenta::MuestraMensajeSePuedeVender(const char *pchrPtrMensaje)
{
  if(pchrPtrMensaje)
    QMessageBox::information(this,"Aviso Del Sistema",pchrPtrMensaje);
}
void QtImpPuntoDeVenta::ObtenProductoProveedorNumProducto()
{
zSiscomRegistro *lzSisRegProducto;
const char *lchrPtrProducto;
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"ProductoProveedor");
lchrPtrProducto=strdup((const char *)QLENumeroProducto->text());
if((lzSisRegProducto=lzOpeServiSNTE.ProductoProveedor(zSiscomRegProveedor,
				                     lchrPtrProducto)))
{
     QLECodigoBarras->setText((const char *)(*lzSisRegProducto)["codigobarras"]);
     SlotCodigoBarras();
}
else
QMessageBox::information(this,"Aviso Sistema","Producto no disponible");
free((void *)lchrPtrProducto);
}
void QtImpPuntoDeVenta::ActualizaDireccion()
{
  zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"ActualizaDireccion");
  lzOpServiSNTE.ActualizaDireccion(zPerDireccion);
}

void QtImpPuntoDeVenta::ObtenFolio()
{
 	if(zSiscomTipoVenta->EsElValorCampo("nombre","Credito") ||
	   zSiscomTipoVenta->EsElValorCampo("nombre","Contado"))
	     ObtenFolioFacturaCredito(); 
	else
 	if(zSiscomTipoVenta->EsElValorCampo("nombre","Apartado"))
	   ObtenFolioFacturaApartado();


}
void QtImpPuntoDeVenta::ObtenFolioFacturaCredito()
{
char lchrArrFolio[10];
  zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"FolioActual");
  lzOpServiSNTE.FolioActualFactura("0",lchrArrFolio);
QLEFolio->setText(lchrArrFolio);
}
void QtImpPuntoDeVenta::ObtenFolioFacturaApartado()
{
char lchrArrFolio[10];
  zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"FolioActual");
  lzOpServiSNTE.FolioActualFactura("2",lchrArrFolio);
QLEFolio->setText(lchrArrFolio);
}

void QtImpPuntoDeVenta::CancelarFolio()
{
QtImpCancelarFolio lQtImpCancelarF(&zVentaOrden);
  QLEFolio->setText(zVentaOrden.Folio());
}

int QtImpPuntoDeVenta::LineEditValido(QLineEdit *pQLETexto)
{
   return !pQLETexto->text().isNull() &&
          !pQLETexto->text().isEmpty() ;
}

