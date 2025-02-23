#include <IMP_ManejadorOrden.h>
#include <IMP_CapturaDato.h>
#include <IMP_AvisoNoAlcanza4.h>
#include <IMP_ConExpendiosVenta.h>

#include <IMP_MenuManejadorOrden.h>
#include <IMP_NoAlcanzaProducto.h>
#include <IMP_OrdenesDisponibles.h>
#include <IMP_MuestraExistenciaExpendios.h>
#include <IMP_Faltantes.h>
#include <IMP_ComoPago.h>
#include <QCtrlProductosSE.h>

#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomEnvioACadena.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>

#include <zProductoCotizar.h>
#include <zClienteSiscom.h>
#include <zTelefono.h>
#include <zCorreo.h>
#include <zDireccion.h>
#include <zUbicacion.h>
#include <zEstante.h>
#include <zCajaMaterial.h>
#include <zExpendio.h>
#include <zConexionExpendio.h>

#include <EmpresasN.h>
#include <SiscomRegistros3.h>
#include <qtextedit.h> 
#include <qlineedit.h>
#include <qlcdnumber.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qmessagebox.h>
#include <qapplication.h>
#include <qclipboard.h> 


QManejadorOrden::QManejadorOrden(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ManejadorOrden(pQWParent,pchrPtrName,pWFlags),
				QtManejadorOrden((ManejadorOrden *)this,(QManejadorOrden *)this),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zOrdVenta(0),
				intIdConsecutivo(0),
				chrPtrIdOrden(0),
				intSeAbrioOExpendios(0),
				intSoloDescripcion(0),
				zProdPPFaltante(0),
				QConExpsV(0),
				QWParent(pQWParent)

{
IniciaVariables();
ConectaSlots();
}
QManejadorOrden::~QManejadorOrden()
{

}

void QManejadorOrden::ConectaSlots()
{
connect(QCtrProductos,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotSeleccionoProducto(zSiscomRegistro *)));
connect(QCtrProductos,
	SIGNAL(SignalProductoNoValido(zProducto *)),
	SLOT(SlotProductoNoValido(zProducto *)));
connect(QTOrden,
	SIGNAL(contextMenuRequested(int,int,const QPoint &)),
	SLOT(SlotActivaMenu(int,int,const QPoint &)));
connect(QTOrden,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotCantidad(int,int,int,const QPoint &)));
connect(QLECantidad,SIGNAL(returnPressed()),SLOT(SlotFocoAProducto()));
connect(QPBAnexarOrden,SIGNAL(clicked()),SLOT(SlotAnexarOrden()));	
connect(QPBNuevaOrden,SIGNAL(clicked()),SLOT(SlotNuevaOrden()));
connect(QPBRegistrar,SIGNAL(clicked()),SLOT(SlotRegistrar()));
connect(QPBImprime,SIGNAL(clicked()),SLOT(SlotImprimir()));
connect(QPBImprimePdf,SIGNAL(clicked()),SLOT(SlotImprimirPdf()));
connect(QLECantidad,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoCantidad(const QString &)));
connect(QPBExExpendios,SIGNAL(clicked()),SLOT(SlotExistenciaExpendios()));
connect(QPBCargaCotizacion,SIGNAL(clicked()),SLOT(SlotCargaCotizacion()));
connect(QPBFaltante,SIGNAL(clicked()),SLOT(SlotFaltante()));
}
void QManejadorOrden::SlotProductoNoValido(zProducto *pzProducto)
{
    zProdPPFaltante=pzProducto;  
   SiscomRegistroLog2(zProdPPFaltante);
}
void QManejadorOrden::SlotFaltante()
{
RegistrandoFaltante();
}
void QManejadorOrden::SlotImprimirPdf()
{
   ImprimirPdf();
}
void QManejadorOrden::SlotCargaCotizacion()
{
 if(QtManejadorOrden::SeleccionandoOrden())
 {
 AsignandoOrdenSeleccionada();
 intIdConsecutivo=Orden()->NumProductos();
 }
}
void QManejadorOrden::SlotExistenciaExpendios()
{
ConsultandoExistenciaExpendios();
}
void QManejadorOrden::SlotCapturandoCantidad(const QString &pQStrCantidad)
{
   QCtrProductos->setEnabled(EsCantidadValida()); 
   QPBAnexarOrden->setEnabled(false);
}
void QManejadorOrden::SlotCantidad(int pintProducto,
				   int pintColumna,
				   int,
				   const QPoint &)
{
 if(pintProducto!=-1)
 {
  	if(pintColumna==0)
  	{
   		CambiandoCantidades(pintProducto);
   		ReCotizandoOrden();
   	}
	else
	if(pintColumna==5)
	{
	   CambiandoPrecios(pintProducto);
	   ReCotizandoOrden();
	}
	
		
   	else
   	QTOrden->selectRow(pintProducto);
 }
}
void QManejadorOrden::MenuConUnaSeleccion(int pintFila,
					  const QPoint &pQPPosicion)
{
zProductoCotizar *lzProdCotizar;
if(pintFila!=-1)
{
if((lzProdCotizar=zOrdVenta->ProductoPorIdConsecutivo(pintFila)))
{
QTOrden->selectRow(pintFila);

QMenuManejadorOrden lQMMOrden(lzProdCotizar,
			      pQPPosicion,
			      this,
			      "QMenuManejadorOrden");
connect(&lQMMOrden,
	SIGNAL(SignalEliminaProducto(zProductoCotizar *)),
	SLOT(SlotEliminaProducto(zProductoCotizar *)));
connect(&lQMMOrden,
	SIGNAL(SignalNumeroJuegos(const char *)),
	SLOT(SlotNumeroJuegos(const char *)));
connect(&lQMMOrden,
	SIGNAL(SignalNumeroJuegosSeparados(int )),
	SLOT(SlotJuegosSeparados(int )));
connect(&lQMMOrden,
	SIGNAL(SignalDescuentoOrden(const char *)),
	SLOT(SlotDescuentoOrden(const char *)));
connect(&lQMMOrden,
	SIGNAL(SignalPrecioProducto()),
	SLOT(SlotPrecioProducto()));
lQMMOrden.EjecutaMenu();
}
zSiscomQt3::Foco(QLECantidad);
}
  
}
void QManejadorOrden::SlotActivaMenu(int pintFila,
				     int,
				     const QPoint &pQPPosicion)
{
int lintProductos[512];   
  if(ProductosSeleccionados(lintProductos)==1)
 	MenuConUnaSeleccion(pintFila,pQPPosicion);
   else
   {
	LogSiscom("Se tienen varias selecciones");
   }
    
}
void QManejadorOrden::SlotPagoConTarjeta()
{
 	PagoConTarjeta();
}
void QManejadorOrden::SlotPrecioProducto()
{
   ReCotizandoOrden(); 
}
void QManejadorOrden::SlotDescuentoOrden(const char *pchrPtrDescuentoOrden)
{
    DescuentoOrden(pchrPtrDescuentoOrden);
    ReCotizandoOrden();
}
void QManejadorOrden::SlotDescuentoProducto(const char *pchrPtrDescuentoProducto)
{

}
void QManejadorOrden::SlotNumeroJuegos(const char *pchrPtrNoJuegos)
{
   CambiaNoJuegos(pchrPtrNoJuegos);
   ReCotizandoOrden();
}
void QManejadorOrden::SlotJuegosSeparados(int pintNJuegosSeparados)
{
int lintContador;
for(lintContador=1;lintContador<pintNJuegosSeparados;lintContador++)
{
  zOrdsVenta.Orden(zOrdVenta->DuplicaOrden());
  AsignaIdOrden(lintContador);
}
}
void QManejadorOrden::SlotEliminaProducto(zProductoCotizar *pzProdCotizar)
{
if(!ReCotizandoPorEliminacion(pzProdCotizar))
QTOrden->setNumRows(0);
HabilitaImpresionRegistro();
}
void QManejadorOrden::SlotImprimir()
{
  Imprimir();
  QPBRegistrar->setEnabled(Orden()->Cliente() && !NoAlcanza());
}
void QManejadorOrden::SlotRegistrar()
{
   Registrar();
   QPBExExpendios->setEnabled(false);
   chrPtrIdOrden=0;
   intIdConsecutivo=0;
}
void QManejadorOrden::SlotNuevaOrden()
{
NuevaOrden();
HabilitaImpresionRegistro();
zSiscomQt3::Foco(QLECantidad);
}
void QManejadorOrden::SlotAnexarOrden()
{
  CotizandoOrden();
  zSiscomQt3::Foco(QLECantidad);
  HabilitaImpresionRegistro();
  QPBAnexarOrden->setEnabled(false);
  QCtrProductos->setEnabled(false);
}
void QManejadorOrden::SlotFocoAProducto()
{
int lintCantidadValida;
  if((lintCantidadValida=EsCantidadValida()))
  {
  QCtrProductos->setEnabled(lintCantidadValida);
  zSiscomQt3::Foco(QCtrProductos);
  }
}
void QManejadorOrden::SlotSeleccionoProducto(zSiscomRegistro *pzSisRegProducto)
{
	zSisRegProducto=pzSisRegProducto;
	CotizandoProducto(zSisRegProducto);
	zSiscomQt3::Foco(QPBAnexarOrden);
	QPBExExpendios->setEnabled(true);
	MuestraUbicacion();
}
void QManejadorOrden::IniciaConexionExpendio()
{
zConExpendio=new zConexionExpendio(IniciaExpendioActual());
}
void QManejadorOrden::IniciaVariables()
{
IniciaConexionExpendio();
IniciaOrden();
QCtrProductos->Servidor(zConExpendio);
QCtrProductos->IniciaControl();
zSiscomQt3::Foco(QLECantidad);
QCFondoBotones=QPBImprime->paletteBackgroundColor(); 
QConExpsV=new QConExpendiosVenta(zConExpendio,chrPtrArgumentos);
}
zExpendio *QManejadorOrden::IniciaExpendioActual()
{
SiscomRegistro3 *lSisRegEmpresa=(SiscomRegistro3 *)Argumentos(5);
zExpendio *lzExActual;
  lzExActual=new zExpendio((*lSisRegEmpresa)["RazonSocial"],
  			   ((zSiscomConexion *)gzSiscomConexion)->DireccionIp(),
			   "",
			  (*lSisRegEmpresa)["IdExpendio"]);
  lzExActual->Puerto(((zSiscomConexion *)gzSiscomConexion)->Puerto());
return lzExActual;
}
void QManejadorOrden::CotizandoOrden()
{
    CotizaOrden();
    MuestraOrdenCotizada(zOrdVenta);
    TextoEncabezado();
}

void QManejadorOrden::CotizandoProducto(zSiscomRegistro *pzSisRegProducto)
{
zSiscomElectronica lzSiscomE(zOrdVenta->Expendio(),"CotizandoProductos4");
zOrdCotProducto=new zOrdenVenta(0,zOrdVenta->Expendio()->IdExpendio());
zProductoCotizar *lzProdCotizar=new zProductoCotizar(zSiscomQt3::Texto(QLECantidad),
						     0,
						     pzSisRegProducto);
	lzProdCotizar->IdConsecutivo(intIdConsecutivo);
	zOrdCotProducto->AgregaProducto(lzProdCotizar);
	zOrdCotProducto->Cliente(zOrdVenta->Cliente());
	zOrdCotProducto->IdTipoOrden(zOrdVenta->IdTipoOrden());
	lzSiscomE.CotizaOrden(zOrdCotProducto,&zSisRegEdoCotizacion);
	zProdCotizar=zOrdCotProducto->Producto(0);
	MuestraCotizacionProducto(zOrdCotProducto);
	SePuedeAnexarProducto(zProdCotizar);
}
void QManejadorOrden::MuestraNombreKit(int pintFila,
				       zProductoCotizar *pzProdCotizar)
{
 QTOrden->setText(pintFila,0,pzProdCotizar->Cantidad());
 QTOrden->setText(pintFila,1,pzProdCotizar->Existencia());
 QTOrden->setText(pintFila,2,pzProdCotizar->ExiBodega());
 QTOrden->setText(pintFila,3,zOrdVenta->Juegos());
 QTOrden->setText(pintFila,4,pzProdCotizar->Clave());
 QTOrden->setText(pintFila,5,pzProdCotizar->Precio());
 QTOrden->setText(pintFila,6,pzProdCotizar->Importe());
}
void QManejadorOrden::MuestraProductoKit(int pintFila,
					 zSiscomRegistro *pzSisRegProducto)
{
QTOrden->setText(pintFila,0,(const char *)(*pzSisRegProducto)["cantidad"]);
QTOrden->setText(pintFila,1,(const char *)(*pzSisRegProducto)["existencia"]);
QTOrden->setText(pintFila,2,(const char *)(*pzSisRegProducto)["exbodegas"]);
QTOrden->setText(pintFila,4,(const char *)(*pzSisRegProducto)["cveproducto"]);
QTOrden->setText(pintFila,5,(const char *)(*pzSisRegProducto)["precio"]);
QTOrden->setText(pintFila,6,(const char *)(*pzSisRegProducto)["importe"]);
}
int QManejadorOrden::MuestraDefinicionProducto(zOrdenVenta *pzOrdVenta,
					       zProductoCotizar *pzProdCotizar,
					       int *pintPtrFilaNoSePuedeVender)
{
zSiscomRegistro *lzSisRegProducto;
zSiscomRegistros *lzSisRegsProducto;
int lintFila;
 lzSisRegsProducto=pzProdCotizar->DefinicionProducto();
 lintFila=QTOrden->numRows();
 pzProdCotizar->IdConsecutivo(lintFila);
 QTOrden->setNumRows(QTOrden->numRows() 	 +
                     lzSisRegsProducto->NNodos() +
		     1);
MuestraNombreKit(lintFila,pzProdCotizar);
if(!pzProdCotizar->SePuedeVender())
 *pintPtrFilaNoSePuedeVender=lintFila;
 for(lzSisRegProducto=lzSisRegsProducto->Primer();
     lzSisRegProducto;
     lzSisRegProducto=lzSisRegsProducto->Siguiente(),
     lintFila++)
      MuestraProductoKit(lintFila+1,lzSisRegProducto);
return pzProdCotizar->SePuedeVender();
}
int QManejadorOrden::MuestraProducto(int pintNProducto,zProductoCotizar *pzProdCotizar)
{
	QTOrden->setText(pintNProducto,0,pzProdCotizar->Cantidad());
	QTOrden->setText(pintNProducto,1,pzProdCotizar->Existencia());
	QTOrden->setText(pintNProducto,2,pzProdCotizar->ExiBodega());
	QTOrden->setText(pintNProducto,3,zOrdVenta->Juegos());
	QTOrden->setText(pintNProducto,4,pzProdCotizar->Clave());
	QTOrden->setText(pintNProducto,5,pzProdCotizar->Precio());
	QTOrden->setText(pintNProducto,6,pzProdCotizar->Importe());
	return !pzProdCotizar->SePuedeVender();
}
void QManejadorOrden::AvisoNoAlcanza(zProductoCotizar *pzProdCotizar)
{
QAvisoNoAlcanza4 lQANAlcanza(pzProdCotizar);
if(lQANAlcanza.SeElimino())
{
  if(!ReCotizandoPorEliminacion(pzProdCotizar))
  QTOrden->setNumRows(0);
}
else
ReCotizandoOrden();
}
int QManejadorOrden::NoEsProducto(zProductoCotizar *pzProdCotizar)
{
 if(pzProdCotizar->EsElValorCampo("TipoProducto","4"))
 return 0;
 else
 if(pzProdCotizar->EsElValorCampo("TipoProducto","3"))
 return 0;
 else
 if(pzProdCotizar->EsElValorCampo("TipoProducto","2"))
 return 0;
 else
 if(pzProdCotizar->EsElValorCampo("TipoProducto","1"))
 return 0;
 else
 return 1;
}
void QManejadorOrden::MuestraProductos(zOrdenVenta *pzOrdenVenta)
{
int lintProductos=0,
	lintPosicion=0;
int lintProductosNoAlcanza[500];
intNoAlcanza=0;
memset(lintProductosNoAlcanza,0,sizeof(int)*500);
if(pzOrdenVenta->Productos())
{
    QTOrden->setNumRows(pzOrdenVenta->NumProductos());  
for(lintProductos=0;
    lintProductos<pzOrdenVenta->ProductosCotizados();
    lintProductos++)
{
   if(NoEsProducto(pzOrdenVenta->Producto(lintProductos)))
   {
    pzOrdenVenta->Producto(lintProductos)->IdConsecutivo(lintPosicion);
    if(MuestraProducto(lintPosicion,pzOrdenVenta->Producto(lintProductos)))
     lintProductosNoAlcanza[lintPosicion]=1;
    lintPosicion++;
   }
}
}
lintProductosNoAlcanza[lintProductos]=-1;
zSiscomQt3::ColoreaFilas(QTOrden,Qt::red,lintProductosNoAlcanza);
}
void QManejadorOrden::MuestraProductos2(zOrdenVenta *pzOrdenVenta)
{
int lintProductos=0,
	lintPosicion=0;
zSiscomRegistros *lzSisRegsProductos;
zProductoCotizar *lzProdCotizar;
    QTOrden->setNumRows(pzOrdenVenta->NumProductos());  
lzSisRegsProductos=pzOrdenVenta->Productos();
for(lzProdCotizar=(zProductoCotizar *)lzSisRegsProductos->Primer();
    lzProdCotizar;
    lzProdCotizar=(zProductoCotizar *)lzSisRegsProductos->Siguiente())
{
  if(NoEsProducto(lzProdCotizar))
  {
  lzProdCotizar->IdConsecutivo(lintPosicion);
  MuestraProducto(lintPosicion,lzProdCotizar);
  lintPosicion++;
  }
}
}
void QManejadorOrden::MuestraNoProductos(zOrdenVenta *pzOrdenVenta)
{
int lintContador,
	lintPosicion=0,
	lintFilaNoSeVende,
	lintFilaNoSeVendeContador=0,
	lintNoSePuedeVender[200];
memset(lintNoSePuedeVender,0,sizeof(int)*200);
	for(lintContador=0;
	    lintContador<pzOrdenVenta->ProductosCotizados();
	    lintContador++)
	{
        if(!NoEsProducto(pzOrdenVenta->Producto(lintContador)) && 
	   SeMuestraDefinicionProducto(pzOrdenVenta->Producto(lintContador)))
	 if(!MuestraDefinicionProducto(pzOrdenVenta,pzOrdenVenta->Producto(lintContador),&lintFilaNoSeVende))
	 {
	   lintNoSePuedeVender[lintFilaNoSeVende]=1;
	   lintFilaNoSeVendeContador++;
	 }
	}
lintNoSePuedeVender[lintFilaNoSeVendeContador]=-1;
zSiscomQt3::ColoreaFilas(QTOrden,Qt::red,lintNoSePuedeVender);
}
int QManejadorOrden::SeMuestraDefinicionProducto(zProductoCotizar *pzProdCotizar)
{
 int lintTipoProducto=pzProdCotizar->TipoProductoInt(); 
 /* Tepotzotlan Sabado 12 de enero 2019 
  * Falta revisar la logica para poder integrar 
  * la funcionalidad que permite no mostrar la definicion del producto
  * el problema tiene que ver con la validacion de la existencia de los
  * productos de la definicion del producto, ya que se manda al momento 
  * de mostrarlo .... 
  * 
  * Ya se realizo el ajuste del lado del servidor, no se imprime la 
  * definicion del producto para el caso de Producto Siscom, Circuito Impreso
  * por ahora...
  */
  return 1;
}
void QManejadorOrden::MuestraOrdenCotizada(zOrdenVenta *pzOrdenVenta)
{
  if(pzOrdenVenta->Productos())
  {
  QTOrden->setNumRows(0);
  QLCDNumTotalOrden->display(pzOrdenVenta->ImporteOrden());
  MuestraProductos(pzOrdenVenta);
  MuestraNoProductos(pzOrdenVenta);
  zSiscomQt3::AjustaColumnasTabla(QTOrden);
  }
  else
  QTOrden->setNumRows(0);

}
void QManejadorOrden::MuestraOrdenActual()
{
  MuestraOrdenCotizada(zOrdVenta);
}
void QManejadorOrden::MuestraCotizacionProducto(zOrdenVenta *pzOrdVenta)
{
  QLEExistencia->setText(pzOrdVenta->Existencia(0));
  QLEExiBodega->setText(pzOrdVenta->ExBodega(0));
  QLCDNumPrecio->display(pzOrdVenta->Precio(0));
  QTEDescripcion->setText(pzOrdVenta->Descripcion(0));
}
void QManejadorOrden::CotizaOrden()
{
zSiscomElectronica lzSiscomE(zOrdVenta->Expendio(),"CotizandoProductos4");
      zOrdVenta->AgregaProducto(zProdCotizar); 
      intIdConsecutivo++;
      lzSiscomE.CotizaOrden(zOrdVenta,&zSisRegEdoCotizacion);
}
int QManejadorOrden::ReCotizaOrden()
{
zSiscomElectronica lzSiscomE(zOrdVenta->Expendio(),"CotizandoProductos4");
if(lzSiscomE.CotizaOrden(zOrdVenta,&zSisRegEdoCotizacion))
{
QMessageBox::information(this,
			 "Aviso Sistema",
			 (const char *)(*zSisRegEdoCotizacion)["Mensaje"]);
return 1;
}
else
{
TextoEncabezado();
return 0;
}
}
void QManejadorOrden::ReCotizandoOrden()
{
if(Orden()->NumProductos()>0)
{
if(!ReCotizaOrden()) 
{
MuestraOrdenCotizada(zOrdVenta);
HabilitaImpresionRegistro();
}
else
QMessageBox::information(this,"Aviso del Sistema","NOO Se puede mostrar la Orden");
}
else
LogSiscom("Orden sin productos %d",Orden()->NumProductos());
}
void QManejadorOrden::IniciaOrden()
{
     zOrdVenta=new zOrdenVenta(0,ContinuandoConOtroExpendio()->IdExpendio());
     zOrdVenta->Expendio(ContinuandoConOtroExpendio());
     zOrdVenta->IdVendedor(chrPtrArgumentos[1]);
     chrPtrIdOrden=0;
     QTOrden->setNumRows(0);
     AgregandoOrden();
}
void QManejadorOrden::MuestraDatosCliente()
{
/*
 QTECliente->setText(QString("Nombre del Cliente\n")			+
 			     zCliSiscom->Nombre()  			+ 
 			     " " 					+
			     zCliSiscom->APaterno()			+
			     " "					+
			     zCliSiscom->AMaterno()  		+
			     "\n"					+
			     "Escuela\n" 				+
			     " "					+
			     zCliSiscom->Escuela()			+
			     "\n"					+
			     "Datos Comunicacion"			+
			     "\n"					+
			     "Celular:"                 		+
			     zCliSiscom->Celular()->Telefono()	+
			     " "					+
			     "Correo Electronico:"			+
			     zCliSiscom->Correo()->Correo()		+
			     "\n"					+
			     "Direccion Entrega"			+
			     "\n"					+
			     zCliSiscom->Direccion()->Calle() 	+
			     " " 					+
			     zCliSiscom->Direccion()->Numero()	+
			     " "					+
			     zCliSiscom->Direccion()->Colonia()	+
			     " " 					+
			     zCliSiscom->Direccion()->Delegacion()	+
			     " "					+
			     zCliSiscom->Direccion()->Estado()	+
			     " "					+
			     zCliSiscom->Direccion()->CP()		+
			     "\n"					+
			     "Referencias"				+
			     "\n"					+
			     zCliSiscom->Direccion()->Referencias());
*/
}


void QManejadorOrden::NuevaOrden()
{
}
void QManejadorOrden::TextoEncabezado()
{

}
void QManejadorOrden::TextoEncabezado(const char *pchrPtrTexto)
{
 setCaption(pchrPtrTexto);
}
void QManejadorOrden::TextoBotonRegistro(const char *pchrPtrTexto)
{

}
void QManejadorOrden::TextoBotonNuevaOrden(const char *pchrPtrTexto)
{

}
zOrdenVenta *QManejadorOrden::Orden()
{
	 return zOrdVenta;
}
/* Tepotzotlan 25 de Octubre del 2020
 * En plena pandemia por el COVID-19
 *
 * Se debe revisar cuidadosamente el uso de esta funcion
 * ya que , se sobre escribe la direccion del apuntador 
 * que previamente se asigno al Iniciar la orden
 *
 * Lo correcto seria de la orden actual agregar los productos
 * que se estan observando de una cotizacion registrada en el 
 * sistema o de una orden previamente vendida, 
 */
void QManejadorOrden::Orden(zOrdenVenta *pzOrdenVenta)
{
	zOrdVenta=pzOrdenVenta;
}
void QManejadorOrden::ProductosALaOrden(zSiscomRegistros *pzSisRegsProductos)
{

}
void QManejadorOrden::Registrar()
{
}
void QManejadorOrden::PagoConTarjeta()
{

}
void QManejadorOrden::Imprimir()
{

}
void QManejadorOrden::ImprimirPdf()
{
}
void QManejadorOrden::OrdenRapidaEscuelaPrincipal()
{

}
void QManejadorOrden::OrdenRapidaOtro()
{

}
void QManejadorOrden::PantallaMasUsada()
{

}
zSiscomConexion *QManejadorOrden::Conexion()
{
/* 
 * Siscom Lindavista   12 Noviembre 2024
 * La loca, mas loca , pienso si de verdad hice tan mal las 
 * cosas 
 *
 *
 * Al momento de registrar la orden se elimina todo , y 
 * volver con la conexion del expendio ... . ????
 */
    return Orden()->Expendio();;

}
void QManejadorOrden::CambiaCantidad(int pintProducto)
{
char lchrArrCantidad[128];
zProductoCotizar *lzProdCotizar;
lzProdCotizar=zOrdVenta->ProductoPorIdConsecutivo(pintProducto);
if(lzProdCotizar)
{
	CapturaCantidad(lzProdCotizar->Cantidad(),lchrArrCantidad);
	lzProdCotizar->Cantidad(lchrArrCantidad);
}
}
void QManejadorOrden::CambiaPrecio(int pintProducto)
{
char lchrArrCantidad[128];
zProductoCotizar *lzProdCotizar;
lzProdCotizar=zOrdVenta->ProductoPorIdConsecutivo(pintProducto);
if(lzProdCotizar)
{
	CapturaCantidad(lzProdCotizar->Precio(),lchrArrCantidad);
	lzProdCotizar->Precio(lchrArrCantidad);
	lzProdCotizar->PrecioEspecial("1");
}
}
void QManejadorOrden::CambiaNoJuegos(const char *pchrPtrNoJuegos)
{
zOrdVenta->JuegosNuevo(pchrPtrNoJuegos);
}
void QManejadorOrden::DescuentoOrden(const char *pchrPtrDescuentoOrden)
{
zOrdVenta->DescuentoOrden(pchrPtrDescuentoOrden);
}
void QManejadorOrden::DescuentoProducto(const char *pchrPtrDescuentoProd)
{
}
void QManejadorOrden::CapturaCantidad(const char *pchrPtrCantidadActual,char *pchrPtrCantidad)
{
QCapturaDato lQCDato("Cambia Cantidad",
		     "Cantidad",
		     pchrPtrCantidadActual);
lQCDato.ObtenDato(pchrPtrCantidad);
}
void QManejadorOrden::TeclasEspeciales(QKeyEvent *pQKETeclas)
{
  LogSiscom("");
   if(pQKETeclas->state()==Qt::AltButton)
   {
     LogSiscom("Presionando el Alt");
        if(pQKETeclas->key()>=Qt::Key_0 && 
	   pQKETeclas->key()<=Qt::Key_5 && 
	   intSeAbrioOExpendios) 
	  CambiandoAlExpendio(pQKETeclas->key());
	else
	if(pQKETeclas->key()==Qt::Key_Tab)
	{
	if(zOrdsVenta.HayMasDeUnaOrden())
	SeleccionandoOrden();
	else
	LogSiscom("Solo Es la orden actual ...");
	}
	else
	if(pQKETeclas->key()==Qt::Key_F12)
	SeImprimeSinTiquet();
	else
	if(pQKETeclas->key()==Qt::Key_F11)
	 OrdenRapidaEscuelaPrincipal();
	else
	if(pQKETeclas->key()==Qt::Key_F10)
	 OrdenRapidaOtro();
	else
	/*
	 *  Tepotzotlan Mexico 
	 *  1 de Noviembre 2024 
	 *
	 *  No se que quise hacer con esto ... 
	 *  por lo pronto lo quito
	 *  
	if(pQKETeclas->key()==Qt::Key_F4)
	PantallaMasUsada();
	else
	*/
	if(pQKETeclas->key()==Qt::Key_F1)
	{
	  if(CambiandoExpendio())
	  Orden()->OrdenPrecioEspecial();
	  ReCotizandoOrden();
	  intSeAbrioOExpendios=1;
	}
	else
	if(pQKETeclas->key()==Qt::Key_F3)
	RegistroRapidoCotizacionEnvio();
	else 
	if(pQKETeclas->key()==Qt::Key_F6)
	 CargaUltimaOrden();
	 else
	if(pQKETeclas->key()==Qt::Key_Control)
	SlotNuevaOrden();
   }
   else
   if(pQKETeclas->state()==Qt::ControlButton)
 	 if(pQKETeclas->key()==Qt::Key_C)
	     CopiandoPortaPapeles();
	 else
	 if(pQKETeclas->key()==Qt::Key_D)
	    CopiandoPortapapelesTelemarketing();
	 else
	 if(pQKETeclas->key()==Qt::Key_E)
	    CopiandoPrecioProductoPortapapeles();
	 else
	 if(pQKETeclas->key()==Qt::Key_V)
	 CopiandoOrdenDesdePortaPapeles();
   	 else
	 if(pQKETeclas->key()==Qt::Key_P)
	 QtManejadorOrden::ComoSePaga();
	 else
	 if(pQKETeclas->key()==Qt::Key_F11) 
	 ModificaCotizacion();
	 else
 	 if(pQKETeclas->key()==Qt::Key_F12)
	 zSiscomQt3::Foco(QLECantidad);
}
void QManejadorOrden::CambiandoDeExpendio(int pintNExpendio)
{
	   ConectandoAlExpendio(pintNExpendio);	   
	   ReCotizandoOrden();
	   CambiandoColorBotonVenderImprimir();
}
void QManejadorOrden::TeclasNormales(QKeyEvent *pQKETeclas)
{
      if(pQKETeclas->key()==Qt::Key_Delete)
      EliminaProductos();
}

void QManejadorOrden::keyPressEvent(QKeyEvent *pQKETeclas)
{
     TeclasEspeciales(pQKETeclas); 
     TeclasNormales(pQKETeclas);
}
int QManejadorOrden::HabilitaImpresionRegistro()
{
int lintRegreso=SePuedeHabilitarRegistro();
QPBImprime->setEnabled(lintRegreso);
return lintRegreso;
}
int QManejadorOrden::SePuedeHabilitarRegistro()
{
  return zOrdVenta->ProductosCotizados() 	&&
         Orden()->Cliente()		 	&&
	 Orden()->Cliente()->EscuelaReg()	&&
	 Orden()->SePuedeVender();
}
void QManejadorOrden::SePuedeAnexarProducto(zProductoCotizar *pzProdCotizar)
{
int lintSePuedeVender;
 if(!(lintSePuedeVender=pzProdCotizar->SePuedeVender()))
 {
 if(!pzProdCotizar->EsProductoSiscom() && !NoEsProducto(pzProdCotizar))
   QNoAlcanzaProducto lQNProducto(pzProdCotizar->DefinicionProducto());
 zSiscomQt3::Foco(QLECantidad);
 }
 LogSiscom("Se puede Vender %d",lintSePuedeVender);
 QPBAnexarOrden->setEnabled((lintSePuedeVender) );
}
int QManejadorOrden::ReCotizandoPorEliminacion(zProductoCotizar *pzProdCotizar)
{
int lintRegreso;
   zOrdVenta->EliminaProducto(pzProdCotizar);
   if((lintRegreso=zOrdVenta->ProductosCotizados()))
   ReCotizandoOrden();
   TextoEncabezado();

return lintRegreso;
}
void QManejadorOrden::ObtenIdOrden()
{
   if(!chrPtrIdOrden)
   {
	zSiscomElectronica lzSisElectronica(Orden()->Expendio(),"ObtenIdOrden");
	if(lzSisElectronica.IdNuevaOrden(&chrPtrIdOrden))
	{
	}
   }
Orden()->IdVenta(chrPtrIdOrden);
}
void QManejadorOrden::EliminaOrdenLista()
{
zOrdsVenta.Elimina(Orden());
}
void QManejadorOrden::EliminaOrden()
{
zOrdenVenta *lzOrdVenta=Orden();
delete lzOrdVenta;
lzOrdVenta=0;
QTOrden->setNumRows(0);
}


void QManejadorOrden::ReIniciaInterfaz()
{
 QPBRegistrar->setEnabled(false);
 QPBImprime->setEnabled(false);
 QPBAnexarOrden->setEnabled(false);
 QPBNuevaOrden->setEnabled(true);
 if(QPBDatosPedido)
 QPBDatosPedido->setEnabled(false);
 zSiscomQt3::Foco(QLECantidad);
}

const char *QManejadorOrden::Argumentos(int pintNArgumento)
{
	return chrPtrArgumentos[pintNArgumento];
}
void QManejadorOrden::SeleccionandoOrden()
{
QOrdenesDisponibles lQOrdDisponibles(&zOrdsVenta,chrPtrArgumentos);
zOrdVenta=lQOrdDisponibles.Orden();
MuestraOrdenCotizada(zOrdVenta);
HabilitaImpresionRegistro();
zSiscomQt3::Foco(QLECantidad);
TextoEncabezado();
}
void QManejadorOrden::AgregandoOrden()
{
  zOrdsVenta.Orden(zOrdVenta);      
}
int QManejadorOrden::OrdenesDisponibles()
{
return zOrdsVenta.HayMasDeUnaOrden() ||
       zOrdsVenta.HayUnaOrden();
}
void QManejadorOrden::IniciandoOrden()
{
   if(OrdenesDisponibles())
   {
	zOrdVenta=(zOrdenVenta *)zOrdsVenta[0];
	MuestraOrdenCotizada(zOrdVenta);
	HabilitaImpresionRegistro();
   }
   else
   {
	IniciaOrden();
 	ReIniciaInterfaz();
   }

}
int QManejadorOrden::EsCantidadValida()
{ 
   return zSiscomQt3::TextoValido(QLECantidad);
}
int QManejadorOrden::SeHabilitaPagoConTarjeta()
{
return !((zOrdVenta->IdTipoOrdenInt()==8 ||
         zOrdVenta->IdTipoOrdenInt()==6 ) &&
	 zOrdVenta->IdTipoOrdenInt()==1);
}
void QManejadorOrden::ConsultandoExistenciaExpendios()
{
QMuestraExistenciaExpendios lQMExExpendios(zSisRegProducto,parentWidget());
}
void QManejadorOrden::Redimensiona()
{
QWidget *lQWParent=(QWidget *)parent();
LogSiscom("Los datos de la ventanota %d %d   y el la ventana (%d,%d)",
	  lQWParent->geometry().width(),
	  lQWParent->geometry().height(),
	  geometry().width(),
	  geometry().height());
}

void QManejadorOrden::resizeEvent(QResizeEvent *)
{
/*
  LogSiscom("Ventana de tamano (%d,%d)",
  	     geometry().width(),
	     geometry().height());
*/
}

int QManejadorOrden::ProductosSeleccionados(int *pintPtrProductos)
{
int lintContador,
    lintContadorSel=0;

 for(lintContador=0;lintContador<QTOrden->numRows();lintContador++)
 {
    if(QTOrden->isRowSelected(lintContador))
    {
      *(pintPtrProductos+lintContadorSel)=lintContador;
      lintContadorSel++;
    }
 }

  return lintContadorSel;
}
void QManejadorOrden::EliminaProductos()
{
int lintRegreso[512];
int lintNProductos;
int lintContador;
zProductos lzProductos;
  if((lintNProductos=ProductosSeleccionados(lintRegreso)))
  for(lintContador=0;lintContador<lintNProductos;lintContador++)
   lzProductos << zOrdVenta->Producto(lintRegreso[lintContador]);
   zOrdVenta->EliminaProductos(&lzProductos);
  if(!zOrdVenta->ProductosCotizados())
  QTOrden->setNumRows(0);
   ReCotizandoOrden();

	 zSiscomQt3::Foco(QLECantidad);
}
void QManejadorOrden::AsignaIdOrden(int pintNOrden)
{
   chrPtrIdOrden=0;
   ObtenIdOrden();   
   zOrdsVenta.Orden(pintNOrden)->IdVenta(chrPtrIdOrden); 
}


void QManejadorOrden::IdConsecutivo(int pintIdConsecutivo)
{
   intIdConsecutivo=pintIdConsecutivo;
}
void QManejadorOrden::SeImprimeSinTiquet()
{
	   LogSiscom("Se manda a Imprimir Sin Ticket"); 
	   if(SePuedeHabilitarRegistro())
	   {
	     Orden()->SeImprimeTicket("0");
	     Imprimir(); 
	     QPBRegistrar->setEnabled(true);
	     Orden()->SeImprimeTicket("1");
	   }
}
int QManejadorOrden::NoAlcanza()
{
  return intNoAlcanza;
}
void QManejadorOrden::CopiandoPortaPapeles()
{
zSiscomConexion lzSisConexion;
char lchrArrOrden[32192];
zSiscomRegistros lzSisRegsEnvio;
lzSisRegsEnvio << zOrdVenta;
lchrArrOrden[0]=0;
lzSisConexion.Cadena(lchrArrOrden);
zSiscomEnvioACadena lzSisEnvioACadena(&lzSisConexion,&lzSisRegsEnvio);
LogSiscom("La cadenota \n\n\n%s\n\n%d\n",
	  lzSisConexion.Cadena(),
	  strlen(lchrArrOrden));
QApplication::clipboard()->setText(lchrArrOrden);
}
void QManejadorOrden::IncrementaConsecutivo(int pintIdConsecutivo)
{
    intIdConsecutivo+=pintIdConsecutivo; 
}

int QManejadorOrden::HayCantidadesSeleccionadas(int *pintPtrSeleccionadas)
{
int lintNSeleccionadas=0;
int lintContador;
  for(lintContador=0;lintContador<QTOrden->numRows();lintContador++)
  {
      if(QTOrden->isSelected(lintContador,0))
      {
      *(pintPtrSeleccionadas+lintNSeleccionadas)=lintContador;
      lintNSeleccionadas++;
      }
       
  }
return lintNSeleccionadas;
}
void QManejadorOrden::AsignaCantidades(int pintNProductos,
					int *pintPtrSeleccionados,
					const char *pchrPtrCantidad)
{
int lintContador;
for(lintContador=0;lintContador<pintNProductos;lintContador++)
zOrdVenta->ProductoPorIdConsecutivo(*(pintPtrSeleccionados+lintContador))->Cantidad(pchrPtrCantidad);
}
void QManejadorOrden::AsignaPrecios(int pintNProductos,
				       int *pintPtrSeleccionados,
				       const char *pchrPtrCantidad)
{
int lintContador;
for(lintContador=0;lintContador<pintNProductos;lintContador++)
{
zOrdVenta->ProductoPorIdConsecutivo(*(pintPtrSeleccionados+lintContador))->Precio(pchrPtrCantidad);
zOrdVenta->ProductoPorIdConsecutivo(*(pintPtrSeleccionados+lintContador))->PrecioEspecial("1");
}

}
void QManejadorOrden::CambiandoCantidades(int pintProducto)
{
int lintArrSeleccionados[200];
char lchrArrCantidad[12];
int lintNProductos;
 if((lintNProductos=HayCantidadesSeleccionadas(lintArrSeleccionados))>1)
 {
     CapturaCantidad("1",lchrArrCantidad);
     AsignaCantidades(lintNProductos,lintArrSeleccionados,lchrArrCantidad);
 }
 else
 CambiaCantidad(pintProducto);
}
void QManejadorOrden::CambiandoPrecios(int pintProducto)
{
int lintArrSeleccionados[200];
char lchrArrCantidad[12];
int lintNProductos;
 if((lintNProductos=HayCantidadesSeleccionadas(lintArrSeleccionados))>1)
 {
     CapturaCantidad("1",lchrArrCantidad);
     AsignaPrecios(lintNProductos,lintArrSeleccionados,lchrArrCantidad);
 }
 else
 CambiaPrecio(pintProducto);
}
void QManejadorOrden::MuestraUbicacion()
{
QString lQSUbicacion;
zUbProducto=new zUbicacion(zSisRegProducto);
if(zUbProducto->Estante() && zUbProducto->Caja())
lQSUbicacion=QString("Estante:") 			+
	      zUbProducto->Estante()->Estante()		+
	      " "	 				+
	      "Caja:"					+
	      zUbProducto->Caja()->Caja();
else
if(zUbProducto->Estante() && !zUbProducto->Caja())
lQSUbicacion=QString("Estante:") 			+
	      zUbProducto->Estante()->Estante();
else
if(!zUbProducto->Estante() && zUbProducto->Caja())
lQSUbicacion=QString("Caja:") 			+
	      zUbProducto->Caja()->Caja();
QLEUbicacion->setText(lQSUbicacion);
delete zUbProducto;
}
void QManejadorOrden::CambiandoAlExpendio(int pintExpendio)
{
zConexionExpendio *lzConExp=QConExpsV->Expendio(pintExpendio-Qt::Key_0);
if(lzConExp)
{

      zOrdVenta->IdExpendio(lzConExp->IdExpendio());
      zOrdVenta->Expendio(lzConExp);
      TextoEncabezado();
      ReCotizandoOrden();
   if((lzConExp==QConExpsV->Expendio(0)))
    CambiaColorBotonVenderImprimir(QCFondoBotones);
    else
    CambiaColorBotonVenderImprimir(QColor("Red"));
}

}
void QManejadorOrden::ComunicacionExpendio()
{

}
void QManejadorOrden::ComunicacionExpendio(zExpendio *pzExpendio)
{
  zSisConexion->DireccionIp(pzExpendio->DirIp());
  zSisConexion->Puerto(pzExpendio->PuertoInt());
}
 
void QManejadorOrden::CambiandoColorBotonVenderImprimir()
{
    if(QConExpsV->EsPrincipal())
    CambiaColorBotonVenderImprimir(QCFondoBotones);
    else
    CambiaColorBotonVenderImprimir(QColor("Red"));
}

int QManejadorOrden::CambiandoExpendio()
{
   QConExpsV->Corriendo();
   zOrdVenta->IdExpendio(QConExpsV->IdExpendioActual());
   zOrdVenta->Expendio(QConExpsV->Actual());
   CambiandoColorBotonVenderImprimir();
   ComunicacionExpendio();
   TextoEncabezado();
   return QConExpsV->DejaPrecios();
}
const char *QManejadorOrden::IdExpendio()
{
SiscomRegistro3 *lSisRegEmpresa=(SiscomRegistro3 *)Argumentos(5);
return (*lSisRegEmpresa)["IdExpendio"];
}
const char *QManejadorOrden::Expendio()
{
SiscomRegistro3 *lSisRegEmpresa=(SiscomRegistro3 *)Argumentos(5);
return (*lSisRegEmpresa)["RazonSocial"];
}
void QManejadorOrden::CambiaColorBotonVenderImprimir(const QColor &pQColor)
{
  QPBImprime->setPaletteBackgroundColor(pQColor);
  QPBRegistrar->setPaletteBackgroundColor(pQColor);
}
void QManejadorOrden::ConectandoAlExpendio(int pintNExpendio)
{
   zOrdVenta->IdExpendio(QConExpsV->Expendio(pintNExpendio)->IdExpendio());
   ComunicacionExpendio(QConExpsV->Expendio(pintNExpendio));
}
void QManejadorOrden::CopiandoPortapapelesTelemarketing()
{
}
void QManejadorOrden::CopiandoPrecioProductoPortapapeles()
{

}
void QManejadorOrden::UltimaOrden()
{
  zOrdVUltima=(zOrdenVenta *)Orden()->DuplicaOrden();
}
void QManejadorOrden::CargaUltimaOrden()
{
  zOrdVenta=zOrdVUltima;
  zOrdVenta->Expendio(zConExpendio);
  ObtenIdOrden();
  ReCotizandoOrden();
}
zOrdenVenta *QManejadorOrden::ProductoCotizado()
{
  return zOrdCotProducto;
}
void QManejadorOrden::RegistroRapidoCotizacion()
{

}
void QManejadorOrden::RegistroRapidoCotizacionEnvio()
{

}
void QManejadorOrden::ClientePublicoEnGeneral()
{
zClienteSiscom *lzCliSiscom;
lzCliSiscom=zSiscomElectronica::ClientePublicoEnGeneral(Conexion());
Orden()->Cliente(lzCliSiscom);
}

void QManejadorOrden::CopiandoOrdenDesdePortaPapeles()
{
QString  lQStrRegreso=QApplication::clipboard()->text(QClipboard::Clipboard);
char lchrArrCadena[32192];
strcpy(lchrArrCadena,(const char *)lQStrRegreso);
zSiscomConexion lzSisConexion;
lzSisConexion.Cadena(lchrArrCadena);


LogSiscom("\n\n\n\n\n   %s   \n\n\n\n",
	   lchrArrCadena);

}
void QManejadorOrden::SoloDescripcion(int pintSoloDescripcion)
{
    intSoloDescripcion=pintSoloDescripcion;
}
int QManejadorOrden::SoloDescripcion()
{
   return intSoloDescripcion;
}
zConexionExpendio *QManejadorOrden::ContinuandoConOtroExpendio()
{
  if(QConExpsV)
  {
	LogSiscom("Sigo conectado a %s (%s:%d)",
		   QConExpsV->Actual()->RazonSocial(),
		   QConExpsV->Actual()->DirIp(),
		   QConExpsV->Actual()->PuertoInt());
	return QConExpsV->Actual();
  }
  else
  {
	LogSiscom("Al expendio principal");
	return zConExpendio;
  }
}

void QManejadorOrden::RegistrandoFaltante()
{
zProductoCotizar *lzProdCotizar;
if(zProdPPFaltante)
   lzProdCotizar=(zProductoCotizar *)zProdPPFaltante;
else
   lzProdCotizar=zProdCotizar;
QFaltantes lQFaltantes(lzProdCotizar,chrPtrArgumentos);
}
int QManejadorOrden::SeCargaComoPago()
{
  if((Orden()->IdTipoOrdenInt()==1) || 
     (Orden()->IdTipoOrdenInt()==8) ||
     (Orden()->IdTipoOrdenInt()==9) ||
     (Orden()->IdTipoOrdenInt()==5))
   return 0;
   else
   return 1;
}
int QManejadorOrden::ComoPago()
{
if(!SeCargaComoPago())
return 0;
else
{
QComoPago lQCPago(Orden());
   if(lQCPago.ComoPague()==QComoPago::Efectivo)
   return 0;
   else
   if(lQCPago.ComoPague()==QComoPago::Transferencia)
   {
     return 0; 
   }
   else
   if(lQCPago.ComoPague()==QComoPago::Cancelar)
	return 1;
   else
   return 1;
}
}

void QManejadorOrden::ModificaCotizacion()
{
}
void QManejadorOrden::AsignandoOrdenSeleccionada()
{
  Orden()->AgregandoProductos(QtManejadorOrden::Orden()->Productos());
  Orden()->Cotizacion(QtManejadorOrden::Orden()->Cotizacion());
  Orden()->NumProductos(QtManejadorOrden::Orden()->NumProductos());
  HabilitaImpresionRegistro();
  ReCotizandoOrden();
}
zOrdenVenta *QManejadorOrden::LaUltimaOrden()
{
  return zOrdVUltima;
}


QWidget *QManejadorOrden::Parent()
{
     return QWParent;
}

void QManejadorOrden::Parent(QWidget *pQWParent)
{
       QWParent=pQWParent;
}
