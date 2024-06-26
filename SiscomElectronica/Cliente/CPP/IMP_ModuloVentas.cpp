#include <IMP_ModuloVentas.h>
#include <IMP_ClienteAlumno.h>
#include <IMP_ProductoApartados.h>
#include <IMP_RegistroPlaca.h>
#include <IMP_CapturaDescripcionCotizacion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <zSiscomElectronica.h>
#include <zClienteSiscom.h>
#include <zProductoCotizar.h>
#include <zExpendio.h>
#include <zCotizacion.h>
#include <zTextoWhatsApp.h>
#include <zConexionExpendio.h>
#include <zEscuela.h>

#include <SiscomRegistros3.h>

#include <qpushbutton.h> 
#include <qmessagebox.h>
#include <qtable.h>
#include <qapplication.h>
#include <qclipboard.h>
#include <qtextedit.h>



/* Tepotzotlan Mexico a Domingo 7 de Enero 2018
 * Tipos de venta 
 *
 * 6 -> Circuito Impreso 
 * 8 -> Material area de diseno
 * 9 -> Material para donacion
 *
 *
 */

QModuloVentas *InstanciaModuloVentas(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QModuloVentas((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}

QModuloVentas::QModuloVentas(SiscomDatCom *pSisDatCom,
			     char **pchrPtrArgumentos,
			     QWidget *pQWParent,
			     const char *pchrPtrName,
			     WFlags pWFlags):
			     QManejadorOrden(pSisDatCom,
			     		     pchrPtrArgumentos,
					     pQWParent,
					     pchrPtrName,
					     pWFlags),
				intVendiendo(0),
				intPorqueSeRegistra(0)
{
TextoBotonRegistro("Vende Orden");
TextoBotonNuevaOrden("Nueva Orden");
ConectaSlots();
TextoEncabezado();
EliminaBotonesQueNoUso();
}
void QModuloVentas::ConectaSlots()
{
  connect(this,
  	  SIGNAL(SignalNoSePuedeVender(zProductoCotizar *)),
	  SLOT(SlotNoSePuedeVender(zProductoCotizar *)));
}
void QModuloVentas::SlotNoSePuedeVender(zProductoCotizar *pzProdCotizar)
{
 MuestraProductoEnApartados(pzProdCotizar);
}
void QModuloVentas::MuestraProductoEnApartados(zProductoCotizar *pzProdCotizar)
{
QProductoApartados lQProdApartados(pzProdCotizar);
}
void QModuloVentas::Vendiendo()
{
  intVendiendo=1;
  QPBNuevaOrden->setText("Vendiendo");
}
void QModuloVentas::NuevaOrden()
{
int lintAceptar;
QClienteAlumno lQCAlumno(Argumentos(4),Orden());
if(!Orden()->Cliente())
Orden()->IdTipoOrden(lQCAlumno.IdTipoOrden());
if((lintAceptar=lQCAlumno.Aceptar())==100) //Vende Cotizacion
{
  Orden()->Cliente(lQCAlumno.Cliente()); 
  Orden()->IdTipoOrden(lQCAlumno.IdTipoOrden());
/* Tepotzotlan Mexico a 25/10/2020
 * En plena crisis del COVID-19, ya son casi 8 meses
 *
 * Se selecciona una orden de una lista que se regresa, con lo que el 
 * apuntador de la orden actual pierde, al hacer la asignacion, lo cual
 * trae como consecuencia, que las operaciones sobre la memoria del apuntador
 * que se cree que tiene la informacion inicial al iniciar la orden, sean 
 * incorrectas. 
 *
 * En lugar de asignar el apuntador de la orden , se agregaran los productos 
 * con esto podremos agregar a la orden actual, los productos recuperados 
 * de una cotizacion o de otra venta, lo cual no es posible hacer al dia de
 * hoy
 */
 /* Tepotzotlan Mexico a 25/10/2020
  * La Como se inicia la orden, no es necesario sobre escribir la informacion
  *
  * 	Orden(lQCAlumno.Orden());
  *	Orden()->IdExpendio(Argumentos(0));
  *	Orden()->Juegos("1");
  *	Orden()->JuegosNuevo("1");
  *	Orden()->DescuentoOrden("0");
  *	IdConsecutivo(Orden()->NumProductos());
  *
  */
 IncrementaConsecutivo(Orden()->NumProductos()); 
 ObtenIdOrden();
 ReCotizandoOrden();  
 HabilitaImpresionRegistro();
 QPBRegistrar->setText(TextoTipoOrdenBoton());
}
else
if(lintAceptar==103) //Orden Actual 
{
    Orden()->Cliente(lQCAlumno.Cliente());
    Orden()->IdTipoOrden(lQCAlumno.IdTipoOrden());
    Orden()->Apartado(0);
    Orden()->Cotizacion(0);
    Orden()->Pedido(0);
    ObtenIdOrden();
    Vendiendo();
    QPBAnexarOrden->setEnabled(true);
}
else
if(lintAceptar==99)  //Apartado
{
    LogSiscom("---------------------------------");
    IniciaOrden();   
    Orden()->Cliente(lQCAlumno.Cliente());
    Orden()->Apartado(lQCAlumno.Apartado());
    Orden()->IdTipoOrden(lQCAlumno.IdTipoOrden());
    Orden()->Cotizacion(lQCAlumno.Cotizacion());
    ObtenIdOrden();
    Vendiendo(); 
}
else
if(lintAceptar==105)   //Circuito Impreso
{
   	LogSiscom("Se Vende la fabricacion de un circuito impreso");
    Orden()->Cliente(lQCAlumno.Cliente());
    QPBImprime->setEnabled(lQCAlumno.IdTipoOrdenInt()==2);
    QPBRegistrar->setEnabled(lQCAlumno.SePagoImpreso());
    QPBRegistrar->setText(TextoTipoOrdenBoton());
}
else
if(lintAceptar==107) //Material al area de diseno
{
	LogSiscom("Se Registra Material Area de diseno");
    	Orden()->Cliente(lQCAlumno.Cliente());
    	ObtenIdOrden();
    	QPBImprime->setEnabled(false);
    	QPBRegistrar->setEnabled(true);
    	QPBRegistrar->setText(TextoTipoOrdenBoton());
}
else
if(lintAceptar==108) //Material para donacion
{
	LogSiscom("Se Registra Material de donacion");

    	Orden()->Cliente(lQCAlumno.Cliente());
    	ObtenIdOrden();
    	QPBImprime->setEnabled(false);
    	QPBRegistrar->setEnabled(true);
    	QPBRegistrar->setText(TextoTipoOrdenBoton());
}
else
if(lintAceptar==110)  //Modificando una cotizacion
{
        IncrementaConsecutivo(Orden()->NumProductos()); 
 	ReCotizandoOrden();  
        QPBRegistrar->setText(TextoTipoOrdenBoton());
}
else
if(lintAceptar==120) //Cancelo
{
   LogSiscom("Se Cancelo");
   LogSiscom("NO SE HACE Nada");
}
else
if(lintAceptar==109) // Orden Actual
{
        LogSiscom("Se vende la orden Actual");
        Orden()->IdTipoOrden("0");
        ObtenIdOrden();
 	ReCotizandoOrden();
 	HabilitaImpresionRegistro();
    	QPBRegistrar->setText(TextoTipoOrdenBoton());
}
else
{
    LogSiscom("El Tipo orden %s",lQCAlumno.IdTipoOrden()); ///Vendiendo
    Orden()->Cliente(lQCAlumno.Cliente());
    Orden()->Apartado(lQCAlumno.Apartado());
    Orden()->IdTipoOrden(lQCAlumno.IdTipoOrden());
    Orden()->Cotizacion(lQCAlumno.Cotizacion());
    ReCotizandoOrden();
    ObtenIdOrden();
    Vendiendo();
    QPBRegistrar->setEnabled(lQCAlumno.YaSeImprimio());
    QPBRegistrar->setText(TextoTipoOrdenBoton());
}
TextoEncabezado();
}
void QModuloVentas::OrdenRapidaEscuelaPrincipal()
{
if(Orden()->Cliente())
   LogSiscom("Ya Esta un cliente y escuela seleccionada"); 
else
{
zSiscomElectronica lzSisElectronica(Conexion(),"OrdenEscuelaPrincipal");
zClienteSiscom *lzCliSiscom;
if(lzCliSiscom=lzSisElectronica.OrdenEscuelaPrincipal(IdExpendio()))
  VendiendoAlCliente(lzCliSiscom);
}

TextoEncabezado();
}
void QModuloVentas::VendiendoAlCliente(zClienteSiscom *pzCliSiscom)
{
     Orden()->Cliente(pzCliSiscom);
     Orden()->Apartado(0);
     Orden()->Cotizacion(0);
     Orden()->IdTipoOrden("0");
     ObtenIdOrden();
     Vendiendo();
     QPBRegistrar->setText(TextoTipoOrdenBoton());
     HabilitaImpresionRegistro();
     zSiscomQt3::Foco(QLECantidad);

}
zClienteSiscom *QModuloVentas::OrdenOtro()
{
zSiscomElectronica lzSisElectronica(Conexion(),"OrdenOtro");
return lzSisElectronica.OrdenOtro(IdExpendio());
}
void QModuloVentas::OrdenRapidaOtro()
{
if(Orden()->Cliente() && 
   Orden()->Cliente()->Escuela())
 LogSiscom("Ya esta un cliente y escuela seleccionada");
else
{
zClienteSiscom *lzCliSiscom;
if((lzCliSiscom=OrdenOtro()))
VendiendoAlCliente(lzCliSiscom);
}
}
void QModuloVentas::PantallaMasUsada()
{
QRegistroPlaca lQRPlaca(Conexion());
Orden()->IdTipoOrden("6");
lQRPlaca.Orden(Orden());
lQRPlaca.Ejecutando();
}
void QModuloVentas::TextoBotonRegistro(const char *pchrPtrTexto)
{
  QPBRegistrar->setText(pchrPtrTexto);
}
void QModuloVentas::TextoBotonNuevaOrden(const char *pchrPtrTexto)
{
  QPBNuevaOrden->setText(pchrPtrTexto);
}
void QModuloVentas::Registrar()
{
if(!ComoPago())
{
RegistraOrden();
UltimaOrden();
EliminaOrdenLista();
IniciandoOrden();
ReIniciaInterfaz();
}
}
void QModuloVentas::Imprimir()
{
zSiscomElectronica lzSisElectronica(Conexion(),"ImprimeTicketVenta4");
lzSisElectronica.ImprimeTicketVenta(Orden());
}
void QModuloVentas::ImprimirPdf()
{
 LogSiscom("");
}
void QModuloVentas::RegistraOrden()
{
zSiscomElectronica lzSisElectronica(Conexion(),"RegistraOrden");
lzSisElectronica.RegistraOrden(Orden());
}
void QModuloVentas::closeEvent(QCloseEvent *)
{
intPorqueSeRegistra=5;
if(Orden()->NumProductos()>=1 && 
   !Orden()->EsCotizacion())
{
Orden()->IdTipoOrden("5");
Registrar();
}
else
{
EliminaOrden();
IniciaOrden();
ReIniciaInterfaz();
}

}
const char *QModuloVentas::TextoTipoOrdenBoton()
{
const char *lchrPtrRegreso[]={"Vende O&rden",
			"Regist&ra Cotizacion",
			"Regist&ra Apartado",
			"No definida",
			"No definida",
			"No definida",
			"Regist&rando Circuito Impreso",
			"No definida",
			"Mate&rial A Area de Diseno",
			"Mate&rial Para Donacion"};
return lchrPtrRegreso[Orden()->IdTipoOrdenInt()];
}
void QModuloVentas::TextoEncabezado()
{
 QString lQStrEncabezado;


if(Orden()->Cliente())
    lQStrEncabezado=QString(Orden()->Expendio()->RazonSocial()) 	+
    		    "          "					+
		    Orden()->Cliente()->Escuela()			+
		    "          "					+
		    "$"							+
		    Orden()->ImporteOrden();
else
    lQStrEncabezado=QString(Orden()->Expendio()->RazonSocial()) 		+
    		    "          "					+
		    "$"							+
		    Orden()->ImporteOrden();
if(Orden()->Cotizacion())
{
   QString lQSLineaUno=QString(Orden()->Cotizacion()->Descripcion());
    lQStrEncabezado+=QString("       ") 				+
    		     lQSLineaUno.section('\n',0,0);
}
QManejadorOrden::TextoEncabezado((const char *)lQStrEncabezado);
emit SignalActualizaMenu(lQStrEncabezado);
}
void QModuloVentas::CopiandoPortapapelesTelemarketing()
{
char *lchrPtrCadena=0;
if(Orden()->IdVenta())
{
zTextoWhatsApp lzTexWhatsApp(Orden());
lzTexWhatsApp.CotizacionWhats(&lchrPtrCadena);
QApplication::clipboard()->setText(lchrPtrCadena);
}
else
QMessageBox::information(this,"Aviso Sistema","NO Se a Capturado datos de Cotizacion");
}
void QModuloVentas::CopiandoPrecioProductoPortapapeles()
{
char lchrArrPrecio[1024];
zTextoWhatsApp::PrecioProducto(ProductoCotizado(),lchrArrPrecio);
QApplication::clipboard()->setText(lchrArrPrecio);
}
void QModuloVentas::CapturandoDescripcion(const char *pchrPtrModo)
{
 if(!Orden()->Cliente())
  ClientePublicoEnGeneral();

QCapturaDescripcionCotizacion lQCapDscCot(SoloDescripcion(),
					  pchrPtrModo,Orden(),
					  Conexion());
SoloDescripcion(lQCapDscCot.SoloDescripcion());
QTECliente->setText(Orden()->Cotizacion()->Descripcion());
}
void QModuloVentas::RegistrandoRapidoCotizacion(const char *pchrPtrModo)
{
  CapturandoDescripcion(pchrPtrModo);
  IncrementaConsecutivo(Orden()->NumProductos()); 
  Orden()->IdTipoOrden("1");
  ObtenIdOrden();
  ReCotizandoOrden();  
  HabilitaImpresionRegistro();
  QPBRegistrar->setText(TextoTipoOrdenBoton());
}
void QModuloVentas::RegistroRapidoCotizacion()
{
  LogSiscom("");
  RegistrandoRapidoCotizacion("Cotizacion");
}
void QModuloVentas::RegistroRapidoCotizacionEnvio()
{
 LogSiscom("");
 RegistrandoRapidoCotizacion("Envio");
}
void QModuloVentas::EliminaBotonesQueNoUso()
{
   delete QPBDatosPedido;
   delete QPBImprimePdf;
   QPBDatosPedido=0;
   QPBImprimePdf=0;
}

int QModuloVentas::PorqueSeRegistra()
{
   if(intPorqueSeRegistra==5) 
    return 0;
    else
    return 1;
   return 1;


}
