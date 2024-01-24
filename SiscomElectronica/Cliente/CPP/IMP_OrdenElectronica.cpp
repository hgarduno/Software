#include <IMP_OrdenElectronica.h>
#include <IMP_CapturaDato.h>
#include <IMP_AvisoNoAlcanza.h>
#include <IMP_OpcionCerrar.h>
#include <IMP_CapturaNoCotizacion.h>
#include <IMP_CapturaPago.h>

#include <MenuOrdenElectronica.h>

#include <SISCOMComunicaciones++.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomRegistros3.h>
#include <OpSeguridad3.h>
#include <CQSisPuntosElectronica.h>

#include <zSiscomDesarrollo4.h>

#include <Personas.h>
#include <ProductosE.h>
#include <CotizaDispositivos.h>
#include <Ventas.h>
#include <CQSisVentasCaja.h>
#include <CQSisImprimeTicket.h>
#include <CQSisSeguridadCajaVentas.h>
#include <qvariant.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qmessagebox.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
/*
 * Sabado 2 de Febrero 2008
 *
 * Por la anexion de los botones  por separado
 * para capturar la informacion de la orden o 
 * de la cotizacion se observo que, al realizar
 * cualquiera de estas operaciones, en la interfaz
 * queda confuso el siguiente, paso, pudiendo registrar
 * la orden que se captura, en lugar del registro 
 * de la venta, por tal motivo se debera ver la
 * forma en la que se podra desactivar los botones
 * y volverlos a activar en el caso de que se requira
 * capturar nuevamente otro numero de orden o numero
 * de venta.
 *
 *
 */ 

QOrdenElectronica::QOrdenElectronica(SiscomDatCom *pSDatCom,
				     char **pchrPtrArgumentos,
				     Persona *pPersona,
				     const char *pchrPtrIdEmpleado,
				     const char *pchrPtrIdOrden,
				     const char *pchrPtrIdExpendio,
				     QWidget* parent,
				     const char* name,
				     WFlags fl )
    : Seguridad3Protocolo2(getenv("Aplicacion"),
      			   pchrPtrArgumentos[4],
			   pSDatCom,
			   this),
      OrdenElectronica( parent, name, fl ),
     SisDatCom(pSDatCom),
     chrPtrArgumentos(pchrPtrArgumentos),
     PPersona(pPersona),
     QIVOrdenE(0),
     intTurnoIcono(0),
     chrPtrIdEmpleado(pchrPtrIdEmpleado),
     intYaSeNotificoClienteFrecuente(0),
     chrPtrClienteFrecuente(0),
     chrPtrPorDescuento(0),
     chrPtrIdExpendio(pchrPtrIdExpendio),
     intModificaOrdenPorCajaCentral(0)

{
	chrPtrIdCaja=IdCaja();
	strcpy(chrArrIdOrden,pchrPtrIdOrden);	
	SiscomEscribeLog3Qt("La Orden de la venta:%s",(const char *)chrArrIdOrden);	
	SiscomEscribeLog3Qt("El TipoPersona:%s",(const char *)chrPtrArgumentos[4]);
	IniciaVariables();
	ColocaEncabezado();
	RedimensionaColumnas();
	ConectaSlots();

	show();
}

QOrdenElectronica::~QOrdenElectronica()
{


}
void QOrdenElectronica::IniciaVariables()
{
/*
int lintContador;
char lchrArrNmbArchivo[1024];
const char *lchrPtrArchivos[]={ "2rightarrow.png",
				"attach.png",
				"camera_test.png",
				"colorscm.png",
				"document.png",
				"encrypted.png",
				"make.png",
				"player_fwd.png",
				"redo.png",
				"validators.png",
				"wizard.png"
				};
   for(lintContador=0;
       lintContador<12;
       lintContador++)
   {
     sprintf(lchrArrNmbArchivo,
     	     "%s/%s",
	     getenv("RutaIconos"),
	     lchrPtrArchivos[lintContador]);
      QPMarcas[lintContador]=QPixmap(lchrArrNmbArchivo);
   }

*/

}
void QOrdenElectronica::ConectaSlots()
{
	connect(QPBImprimeTicket,
		SIGNAL(clicked()),
		SLOT(S_ImprimeTicket()));
	connect(QPBImprimeCotizacion,
		SIGNAL(clicked()),
		SLOT(S_ImprimeCotizacion()));
	connect(QPBRealizaVenta,
		SIGNAL(clicked()),
		SLOT(S_RealizaVenta()));
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(S_OperacionCotizacion(int,int,int,const QPoint &)));
	connect(QTDatos,
		SIGNAL(contextMenuRequested(int,int,const QPoint &)),
		SLOT(S_CargaMenu(int,int,const QPoint &)));
	connect(QPBRCotizacion,
		SIGNAL(clicked()),
		SLOT(S_RCotizacion()));
	connect(QPBVCotizacion,
		SIGNAL(clicked()),
		SLOT(S_VendeCotizacion()));
	connect(QPBVOrden,
		SIGNAL(clicked()),
		SLOT(S_OrdenVendida()));
	connect(QPBOrdenCaja,
		SIGNAL(clicked()),
		SLOT(S_OrdenCaja()));

}
void QOrdenElectronica::S_OrdenCaja()
{
/* Tepotzotlan 3 De Enero del 2013 
 * Se realizo la integracion con la caja centralizada
 */
if(PProductos.count())
{

/*
 * Modificacion para facturacion
 * se copia cero en el campo proveedor
 * del primer producto, para indicar 
 * que es una venta
 * Tepotzotlan 4 De Enero del 2013
 * Para el caso del registro de la orden a Caja el
 * estado de la venta sera 3
 */

PProductos.at(0)->SiscomActualizaCampo("Proveedor","3");
/*
 * Queretaro 24 Agosto 2010
 * Con la paniqueada del nuevo negocio que sera competencia
 * apartir de este dia, se agrego al registro en la base
 * de datos la escuela a la que pertenece el cliente 
 * que realizo la compra, para saber cuantos clientes 
 * por escuela nos visitan
 */
PProductos.at(0)->SiscomActualizaCampo("IdEscuela",(*SisReg3Escuela)["idescuela"]);

/* Tepotzotlan 3 de Enero del 2013
 * Se agrego la integracion de la caja centralizada
 */
PProductos.at(0)->SiscomActualizaCampo("OrdenACaja","1");
PProductos.at(0)->SiscomActualizaCampo("IdCaja",IdCaja());

VentasE lVentasE(SisDatCom,
		 chrPtrIdEmpleado,
		 PProductos);
	emit SignalVendeOrden(this); 
}
else
QMessageBox::information(this,"Aplicacion","No se puede Realizar La Venta");
}
void QOrdenElectronica::S_CargaMenu(int pintNFila,
				    int pintNColumna,
				    const QPoint &pQPoint)
{
	if(pintNFila!=-1 &&
	   pintNColumna!=-1)
	{
	MOElectronica=new MenuOrdenElectronica(SisDatCom,
					       chrPtrArgumentos,
					       PProductos.at(pintNFila),
					       pQPoint,
					       QTDatos,
					       "MOElectronica");
	connect(MOElectronica,
		SIGNAL(SignalCambioNumJuegos(int)),
		SLOT(S_CambioNumJuegos(int)));
	connect(MOElectronica,
		SIGNAL(SignalJuegosSeparados(int)),
		SLOT(S_JuegosSeparados(int)));
	connect(MOElectronica,
		SIGNAL(SignalEliminaProductos()),
		SLOT(S_EliminaProductos()));
	connect(MOElectronica,
		SIGNAL(SignalPorcentajeDescuento()),
		SLOT(S_PorcentajeDescuento()));
	connect(MOElectronica,
		SIGNAL(SignalPorcentajeDescuentoOrden(int)),
		SLOT(S_PorcentajeDescuentoOrden(int)));
	}	

}
void QOrdenElectronica::S_PorcentajeDescuentoOrden(int pintPorDescuentoOrden)
{
	AsignaPorcentajeDescuentoOrden(pintPorDescuentoOrden);
	CotizaOrden();
}
void QOrdenElectronica::S_PorcentajeDescuento()
{
	CotizaOrden();
}
void QOrdenElectronica::S_EliminaProductos()
{
int lintElimina;
	
	if(EliminaProductos(ProductosSeleccionados()))
	CotizaOrden();
	else
	{
	QTDatos->setNumRows(0);
	PProductos.remove(PProductos.at(0));
	}

}
void QOrdenElectronica::S_JuegosSeparados(int pintNJuegos)
{
	emit SignalJuegosSeparados(pintNJuegos,PProductos);
}
void QOrdenElectronica::S_CambioNumJuegos(int pintNumJuegos)
{

	CambiaNumeroJuegos(CuantosProductosSeleccionados(),
			   pintNumJuegos);
	CotizaOrden();


}
void QOrdenElectronica::MuestraProductos()
{
ProductoE *lProducto;
	for(lProducto=PProductos.first();
	    lProducto;
	    lProducto=PProductos.next())
	   printf("%s\n",lProducto->SRegistrosPro2["CveProducto"]);
}
int QOrdenElectronica::EliminaProductos(ProductosE pProductos)
{
ProductoE *lProducto;
	if(pProductos.count())
	{
	   for(lProducto=pProductos.first();
	       lProducto;
	       lProducto=pProductos.next())
	     PProductos.remove(lProducto);
	}
	return PProductos.count()-1;
}
void QOrdenElectronica::CambiaNumeroJuegos(QMemArray<int> pQMASeleccionados,
					   int pintNumJuegos)
{
char lchrArrNumJuegos[10];
sprintf(lchrArrNumJuegos,"%d",pintNumJuegos);
ProductoE *lProducto;
int lintContador;
int lintNumSel;
	if((lintNumSel=pQMASeleccionados.size()))
	{
	   for(lintContador=0;
	       lintContador<lintNumSel;
	       lintContador++)
	   {
	    lProducto=PProductos.at(pQMASeleccionados[lintContador]);
            lProducto->SiscomActualizaCampo("NumJuegos",lchrArrNumJuegos);
	    }
	}
	else
	for(lProducto=PProductos.first();
            lProducto;
            lProducto=PProductos.next())
            lProducto->SiscomActualizaCampo("NumJuegos",lchrArrNumJuegos);
 

}
ProductosE QOrdenElectronica::ProductosSeleccionados()
{
int lintContador,
    lintNumFilas=QTDatos->numRows();
int lintNumSeleccionadas=0;
ProductosE lProductos;
    for(lintContador=0;
        lintContador<lintNumFilas;
	lintContador++)
     if(QTDatos->isRowSelected(lintContador,true))
        lProductos << PProductos.at(lintContador);

	return lProductos;

}
QMemArray<int> QOrdenElectronica::CuantosProductosSeleccionados()
{
int lintContador,
    lintNumFilas=QTDatos->numRows();
int lintNumSeleccionadas=0;
QMemArray<int> lQMARegreso(lintNumFilas);

    for(lintContador=0;
        lintContador<lintNumFilas;
	lintContador++)
     if(QTDatos->isRowSelected(lintContador,true))
     {
	printf("CuantosProductosSeleccionados:Fila %d Seleccionada \n",lintContador);
      lQMARegreso[lintNumSeleccionadas++]=lintContador;
     }

       lQMARegreso.resize(lintNumSeleccionadas);
   return lQMARegreso;
}
void QOrdenElectronica::S_OperacionCotizacion(int pintNFila,
					      int pintNColumna,
					      int ,
					      const QPoint &)
{
	if(pintNColumna==1 &&
	   pintNFila!=-1)
	 CambiaCantidad(pintNFila);
}
void QOrdenElectronica::S_ImprimeTicket()
{
	
	Imprime(chrArrIdOrden);
}
void QOrdenElectronica::S_ImprimeCotizacion()
{
char lchrArrCadena[30];
SiscomEscribeLog3Qt("");
	sprintf(lchrArrCadena,
		"Cotizacion:%s",
		chrArrIdOrden);
	Imprime(lchrArrCadena);
SiscomEscribeLog3Qt("");
}
void QOrdenElectronica::S_RCotizacion()
{
if(PProductos.count())
{

/*
 * Modificacion para facturacion
 * se copia cero en el campo proveedor
 * del primer producto, para indicar 
 * que es una venta
 */
PProductos.at(0)->SiscomActualizaCampo("Proveedor","1");
VentasE lVentasE(SisDatCom,
		 chrPtrIdEmpleado,
		 PProductos);
	emit SignalVendeOrden(this); 
}
else
QMessageBox::information(this,"Aplicacion","No se puede Realizar La Venta");
}
void QOrdenElectronica::S_RealizaVenta()
{
if(PProductos.count())
{

/*
 * Modificacion para facturacion
 * se copia cero en el campo proveedor
 * del primer producto, para indicar 
 * que es una venta
 */
PProductos.at(0)->SiscomActualizaCampo("Proveedor","0");

/* Viernes 18 De Enero del 2013 
 * Con la integracion de la caja central, se valida si 
 * la orden se modifico en la caja central
 *
 */
 SeModificoLaOrdenEnLaCaja();
/* 
 * Queretaro 17 de septiembre del 2009
 * se agrega la funcionalidad para la integracion del 
 * requerimiento de cajas independientes de cobro
 *
 */
 QCapturaPago lQCapPago(SisDatCom,
 			ImporteTotal());
/*
 * Queretaro 24 Agosto 2010
 * Con la paniqueada del nuevo negocio que sera competencia
 * apartir de este dia, se agrego al registro en la base
 * de datos la escuela a la que pertenece el cliente 
 * que realizo la compra, para saber cuantos clientes 
 * por escuela nos visitan
 *
 */
/* Tepotzotlan 19 De Enero del 2013 
 * Con la integracion de la caja centralizada, la orden ya se registro 
 * en escuelaorden, no se requiere para este caso
 */
if(!intModificaOrdenPorCajaCentral)
PProductos.at(0)->SiscomActualizaCampo("IdEscuela",(*SisReg3Escuela)["idescuela"]);
if(lQCapPago.ImporteValido())
{
chrPtrCambio=lQCapPago.Cambio();
lQCapPago.Recibi(chrArrRecibi);
AgregaInformacionCaja();
VentasE lVentasE(SisDatCom,
		 chrPtrIdEmpleado,
		 PProductos);

VentaCaja();
	emit SignalVendeOrden(this); 
}
else
QMessageBox::information(this,"Aplicacion","No se puede Realizar La Venta Pago Invalido");

}
else
QMessageBox::information(this,"Aplicacion","No se puede Realizar La Venta");
}
/*
 * Es probable, que se necesite pasar el idExpendio para la consulta de
 * la orden
 *
 * Ademas se debe considerar que sera necesario actualizar en los productos
 * el numero de juegos que se pediran.
 *
 * Ya que la consulta solo regresara la cantidad de productos y no el 
 * numero de juegos, este dato esta en la interfaz
 *
 *
 */

void QOrdenElectronica::S_VendeCotizacion()
{
QCapturaNoCotizacion lQCNoCotizacion(SisDatCom,
				     0,
				     "Cotizacion");
ProductoE *lProducto;
if(!lQCNoCotizacion.ObtenBotonPulsado())
{
	lQCNoCotizacion.ObtenProductosCotizacion(&PProductos);
for(lProducto=PProductos.first();
    lProducto;
    lProducto=PProductos.next())
{
lProducto->SiscomActualizaCampo("IdCliente",PPersona->SRegistrosPro2["IdPersona"]);
lProducto->SiscomActualizaCampo("RFC",PPersona->SRegistrosPro2["RFC"]);
lProducto->SiscomActualizaCampo("IdPractica",chrArrIdOrden);
lProducto->SiscomActualizaCampo("NmbPrecio","DEFAULT");
lProducto->SiscomActualizaCampo("IdExpendio",chrPtrIdExpendio);
}
	if(PProductos.count())
	CotizaOrden();

}
}
void QOrdenElectronica::S_OrdenVendida()
{
QCapturaNoCotizacion lQCNoCotizacion(SisDatCom,
				     0,
				     "OrdenVendida");
ProductoE *lProducto;
if(!lQCNoCotizacion.ObtenBotonPulsado())
{
	lQCNoCotizacion.ObtenProductosCotizacion(&PProductos);
for(lProducto=PProductos.first();
    lProducto;
    lProducto=PProductos.next())
{

lProducto->SiscomActualizaCampo("IdCliente",PPersona->SRegistrosPro2["IdPersona"]);
lProducto->SiscomActualizaCampo("RFC",PPersona->SRegistrosPro2["RFC"]);
lProducto->SiscomActualizaCampo("IdPractica",chrArrIdOrden);
lProducto->SiscomActualizaCampo("NmbPrecio","DEFAULT");
lProducto->SiscomActualizaCampo("IdExpendio",chrPtrIdExpendio);
}
	if(PProductos.count())
	CotizaOrden();

}
}
Persona *QOrdenElectronica::ObtenPersona()
{
	return PPersona;
}
void QOrdenElectronica::ColocaEncabezado()
{
  if(PPersona)
   setCaption(QString("Atendiendo A:")               +
   	      PPersona->SRegistrosPro2["Nombre"]   +
	      " "				   +
	      PPersona->SRegistrosPro2["APaterno"] );
}
void QOrdenElectronica::ActivaOrden()
{
	setActiveWindow();
	setFocus();
	raise();
}
void QOrdenElectronica::AnexaProductoALaOrden(ProductoE *pProducto)
{
pProducto->SiscomActualizaCampo("IdCliente",PPersona->SRegistrosPro2["IdPersona"]);
pProducto->SiscomActualizaCampo("RFC",PPersona->SRegistrosPro2["RFC"]);
pProducto->SiscomActualizaCampo("IdPractica",chrArrIdOrden);
PProductos << pProducto;

	CotizaOrden();
}
int QOrdenElectronica::AvisoNoSePuedeVender(ProductoE *pProducto)
{
QAvisoNoAlcanza lQANAlcanza(pProducto);
return lQANAlcanza.Opcion();
}
void QOrdenElectronica::CotizaOrden()
{
CotizaDispositivosE lCotDispo(SisDatCom,PProductos);
ProductoE *lPProducto;
int lintContador;
char lchrArrCantidad[25];

	QTDatos->setNumRows(PProductos.count()-1);
	for(lintContador=0;
	    lintContador<PProductos.count()-1;
	    lintContador++)
	{
	if(!strcmp(PProductos.at(lintContador)->SRegistrosPro2["SePuedeVender"],"No")||
	   !strcmp(PProductos.at(lintContador)->SRegistrosPro2["CantidadValida"],"No"))
	{
        if(!AvisoNoSePuedeVender(PProductos.at(lintContador)))
	{
	 PProductos.remove(PProductos.at(lintContador));
	QTDatos->setNumRows(PProductos.count()-1);
	if(PProductos.count()-1)
	CotizaOrden();
	else 
	PProductos.clear();
	return;
	}
	else
	{
	   printf("QOrdenElectronica::AvisoNoSePuedeVender:{No Selecciono Eliminar}\n");
	   CotizaOrden();
	}

	}
	else
	{
	sprintf(lchrArrCantidad,
		"%.2f",
		atof(PProductos.at(lintContador)->SRegistrosPro2["Cantidad"])*
		atof(PProductos.at(lintContador)->SRegistrosPro2["NumJuegos"]));
	SiscomAnexarRegistroALaTabla(
		lintContador,
		QTDatos,
		QStringList() <<
		    PProductos.at(lintContador)->SRegistrosPro2["CveProducto"]     <<
		    lchrArrCantidad        					   <<
		    PProductos.at(lintContador)->SRegistrosPro2["NumJuegos"]       <<
		    PProductos.at(lintContador)->SRegistrosPro2["Precio"]          <<
		    PProductos.at(lintContador)->SRegistrosPro2["Importe"]	   <<
		    PProductos.at(lintContador)->SRegistrosPro2["PorDescuentoCaja"]);
	}
	}

	QLCNTotal->display((lPProducto=PProductos.at(PProductos.count()-1))->SRegistrosPro2["Importe"]);
	if(!strcmp(lPProducto->SRegistrosPro2["ClienteFrecuente"],"Si") &&
	   !intYaSeNotificoClienteFrecuente)
	{
	   chrPtrClienteFrecuente=lPProducto->SRegistrosPro2["ClienteFrecuente"];
	   chrPtrPorDescuento=lPProducto->SRegistrosPro2["PorDescuento"];
	   QMessageBox::information(this,
	   			    "SISCOM Ventas",
				    QString("Cliente Frecuente, se brindara el ") +
				    lPProducto->SRegistrosPro2["PorDescuento"]    +
				    " Porciento de descuento");
	
	   intYaSeNotificoClienteFrecuente=1;
	}

	if(QIVOrdenE)
	  QIVOrdenE->ActualizaImporte();
}
void QOrdenElectronica::RedimensionaColumnas()
{
int lintContador;

	for(lintContador=0;
	    lintContador<QTDatos->numCols();
	    lintContador++)
	   QTDatos->adjustColumn(lintContador);
}
const char *QOrdenElectronica::ObtenImporteTotal()
{

  return PProductos.at(PProductos.count()-1) ?  
         PProductos.at(PProductos.count()-1)->SRegistrosPro2["Importe"] :
	 "";
}

void QOrdenElectronica::PonQIconAsociado(QIconVOrdenE *pQiVOrden)
{
	QIVOrdenE=pQiVOrden;
}

void QOrdenElectronica::AnexaProductosALaOrden(ProductosE pProductos)
{
if(pProductos.count())
{
ProductoE *lProducto;
int lintContador;

	intTurnoIcono=intTurnoIcono>12 ? 0 :intTurnoIcono++;
	for(lProducto=pProductos.first(),
	    lintContador=0;
	    lintContador<pProductos.count()-1;
	    lProducto=pProductos.next(),
	    lintContador++)
	{
	   if(!lintContador)
	   lProducto->SiscomActualizaCampo("IdPractica",chrArrIdOrden);
	   lProducto->SiscomActualizaCampo("IdCliente",PPersona->SRegistrosPro2["IdPersona"]);
	   PProductos<<lProducto;
	}
	CotizaOrden();
}

}
void QOrdenElectronica::CambiaCantidad(int pintNFila)
{
ProductoE *lPProducto=PProductos.at(pintNFila);
QCapturaDato lQCDato("Introduce Cantidad",
		     "Cantidad");
char lchrArrCantidad[10];
	lQCDato.ObtenDato(lchrArrCantidad);
	lPProducto->SiscomActualizaCampo("Cantidad",
					  lchrArrCantidad);
	CotizaOrden();
}

int QOrdenElectronica::ValidaCierreOrden()
{
/*
 * Se pretendia realizar el soporte para esta funcionalidad 
 * mediante el sistema de seguridad, pero al estar mal estructurada
 * la base de datos hace imposible poder referenciar a un objeto en 
 * especifico, para seleccionarlo o actualizarlo. Y bueno, no hay
 * de otra se tendra que reprogramar todo lo del sistema de seguridad
 */
/* 
OpSeguridad3 lOpSeg3(SisDatCom);
SiscomRegistro3Lst lSisReg3LstVar;
SiscomEscribeLog3Qt("");
lOpSeg3.Variable("ConsultasSiscomElectronica2",
		 chrPtrArgumentos[0],
		 getenv("Aplicacion"),
		 name(),
		 chrPtrArgumentos[4],
		 "intSePuedeCerrarOrden",
		 &lSisReg3LstVar);
*/
SiscomRegistro3 *lSisReg3SeCierra;
CQSisControlesCaja lCQSisContsCaja;
CQSisOpControlCaja lCQSisOCCaja(SisDatCom);
lCQSisOCCaja.ControlesSeguridadCaja(chrPtrArgumentos[0],
				    getenv("IdCaja"),
				    &lCQSisContsCaja);
if((lSisReg3SeCierra=lCQSisContsCaja["intSePuedeCerrarOrden"]))
return atoi((*lSisReg3SeCierra)["estado"]);
else
return 0;
}
void QOrdenElectronica::closeEvent(QCloseEvent *pQCEvent)
{
if(ValidaCierreOrden())
{
QOpcionCerrar lQOpCerrar;
		if(lQOpCerrar.ObtenSeleccion()==QOpcionCerrar::Realizar_Venta)
			S_RealizaVenta();
		if(lQOpCerrar.ObtenSeleccion()==QOpcionCerrar::Cancelar_Venta)
		 emit SignalCancelarVenta(this);
}

}
void QOrdenElectronica::VentaCaja()
{
CQSisVentaCaja lCQSVCaja(chrPtrIdEmpleado,
			 "0",
			 &PProductos);


}
void QOrdenElectronica::ModificaOrdenPorCajaCentral(int pintModificaOrden)
{
intModificaOrdenPorCajaCentral=pintModificaOrden;
}
const char *QOrdenElectronica::ImporteTotal()
{
  (*PProductos.at(PProductos.count()-1))["Importe"];
}
const char *QOrdenElectronica::IdCaja()
{
const char *lchrPtrIdCaja=getenv("IdCaja");
if(lchrPtrIdCaja &&
   *lchrPtrIdCaja)
 return lchrPtrIdCaja;
else
{
QMessageBox::information(this,
			 "Mensaje Del Sistema",
			 "No se ha definido el IdCaja:\n"
			 "IdCaja=");
exit(0);
}
}
void QOrdenElectronica::AgregaInformacionCaja()
{
ProductoE *lProductoE;
lProductoE=PProductos[0];
lProductoE->SiscomActualizaCampo("IdCaja",chrPtrIdCaja);
lProductoE->SiscomActualizaCampo("Recibi",chrArrRecibi);
lProductoE->SiscomActualizaCampo("Cambio",chrPtrCambio);
}
void QOrdenElectronica::Imprime(const char *pchrPtrIdOrden)
{
if(PProductos.count())
{
PuntosPromocionesCliente();
CQSisImprimeTicketOp lCQSisITicketOp(SisDatCom);
CQSisImprimeTicket lCQSisITicket(chrPtrArgumentos[0],
				 pchrPtrIdOrden,
				 &CQSPPCliente,
				 PPersona,
				 &PProductos);

lCQSisITicketOp.TicketVenta(&lCQSisITicket);
}
else
SiscomEscribeLog3Qt("No hay productos en la orden");
}
void QOrdenElectronica::Escuela(SiscomRegistro3 *pSisReg3Escuela)
{
SisReg3Escuela=pSisReg3Escuela;
}
void QOrdenElectronica::PuntosPromocionesCliente()
{
CQSisOpPuntosElectronica lCQSOpPPCliente(SisDatCom);
lCQSOpPPCliente.PuntosPromocionesCliente(chrPtrArgumentos[0],
					 (*PPersona)["IdPersona"],
					 (*PPersona)["Nombre"],
					 &CQSPPCliente); 
SiscomContenidoRegistro4Log(&CQSPPCliente);
SiscomEscribeLog3Qt("");
}
void QOrdenElectronica::AsignaPorcentajeDescuentoOrden(int pintPDescuentoOrden)
{
char lchrArrPorDescuentoOrden[12];
sprintf(lchrArrPorDescuentoOrden,"%d",pintPDescuentoOrden);
PProductos.at(0)->SiscomActualizaCampo("PorDescuentoCajaOrden",lchrArrPorDescuentoOrden);
}
void QOrdenElectronica::SeModificoLaOrdenEnLaCaja()
{
if(intModificaOrdenPorCajaCentral)
PProductos.at(0)->SiscomActualizaCampo("Proveedor","4");
}
QIconVOrdenE::QIconVOrdenE(QOrdenElectronica *pQOElectronica,
			   QIconView *pQIVParent):
		QIconViewItem(pQIVParent),
		QOElectronica(pQOElectronica)
{
Persona *lPersona=pQOElectronica->ObtenPersona();
	if(lPersona)
	setText(QString("Cliente:") 		      +
		lPersona->SRegistrosPro2["Nombre"]    +
		" "				      +
		lPersona->SRegistrosPro2["APaterno"]  +
		"\n"				      +
		pQOElectronica->ObtenImporteTotal());
}
QOrdenElectronica *QIconVOrdenE::ObtenOrdenElectronica()
{
	return QOElectronica;
}

void QIconVOrdenE::ActualizaImporte()
{
Persona *lPersona=QOElectronica->ObtenPersona();

	if(lPersona)
	setText(QString("Cliente:") 		      +
		lPersona->SRegistrosPro2["Nombre"]    +
		" "				      +
		lPersona->SRegistrosPro2["APaterno"]  +
		"\n"				      +
		QOElectronica->ObtenImporteTotal());

}



