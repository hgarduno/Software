#include <IMP_Facturacion.h>
#include <IMP_BuscarClientes.h>
#include <IMP_RangoFechas.h>

#include <Personas.h>
#include <OrdenesVentas.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

QFacturacion *InstanciaFacturacion(void *pCSisDatCom,
				   void *pQWParent,
				   const char *pchrPtrName,
				   int pintWFlags)
{
	return new QFacturacion((CSISCOMDatComunicaciones *)pCSisDatCom,
				(QWidget *)pQWParent,
				pchrPtrName,
				pintWFlags);
}

QFacturacion::QFacturacion(CSISCOMDatComunicaciones *pCSisDatCom,
			    QWidget* parent,
			    const char* name,
			     WFlags fl )
    : Facturacion( parent, name, fl ),
CSisDatCom(pCSisDatCom),
	chrPtrConSinIva("1")
{
	IniciaVariables();
	ConectaSlots();
}

QFacturacion::~QFacturacion()
{
}
void QFacturacion::IniciaVariables()
{
		QSLPFacturacion <<
		"ConsultaFacturacion" <<
		"OrdenesParaFacturar" <<
		chrPtrConSinIva ;
}
void QFacturacion::ConectaSlots()
{
	connect(QPBBCliente,
		SIGNAL(clicked()),
		SLOT(S_SelCliente()));
	connect(QPBRFechas,
		SIGNAL(clicked()),
		SLOT(S_RangoFechas()));
	connect(QTDatosOrdenes,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(S_AnexaOrden(int,int,int,const QPoint &)));
	connect(QPBNoIva,
		SIGNAL(clicked()),
		SLOT(S_NoIncluyeIva()));
	connect(QPBIIva,
		SIGNAL(clicked()),
		SLOT(S_IncluyeIva()));
}
void QFacturacion::S_IncluyeIva()
{
	QSLPFacturacion[2]="1";
		EjecutaFacturacion();
		MuestraFacturacion();

}
void QFacturacion::S_NoIncluyeIva()
{
	QSLPFacturacion[2]="1.15";
		EjecutaFacturacion();
		MuestraFacturacion();
}
void QFacturacion::S_AnexaOrden(int pintNFila,
				int,
				int,
				const QPoint &)
{

		AnexaOrdenParaFacturar(pintNFila);
		EjecutaFacturacion();
		MuestraFacturacion();


}
void QFacturacion::S_RangoFechas()
{
QRangoFechas lQRFechas;

	  if(lQRFechas.ObtenSeleccion()==QRangoFechas::Aceptar)
	  {
	     lQRFechas.ObtenRangoFechas(&chrPtrFechaIni,
			     		&chrPtrFechaFin);
	     ConsultaOrdenes();
	     MuestraOrdenes();
	  }

}
void QFacturacion::S_SelCliente()
{
QBuscarClientes lQBClientes(CSisDatCom);
        if(lQBClientes.ObtenSeleccion()==QBuscarClientes::Aceptar)
	{
	   CQPCliente=lQBClientes.ObtenPersona();
	   setCaption(QString("Facturando A:")     +
		      CQPCliente->ObtenNombre()    +
		      " "			   +
		      CQPCliente->ObtenAPaterno()  +
		      " "                          +
		      CQPCliente->ObtenAMaterno()  +
		      "[RFC:"                      +
		      CQPCliente->ObtenRFC()       +
		      "]");

	}

}
void QFacturacion::ConsultaOrdenes()
{
CQFacturas lCQFacturas;
CQCtrFacturacion lCQCFacturacion(CSisDatCom,
				 QStringList() 		 	<<
				 "ConsultaFacturacion"    	<<
				 "ConsultaOrdenesPorFecha"	<<
				 CQPCliente->ObtenIdPersona()   <<
				 chrPtrFechaIni			<<
				 chrPtrFechaFin,
				 &lCQFacturas);
if(lCQFacturas.count())
FFactura=lCQFacturas.at(0);

}
void QFacturacion::MuestraOrdenes()
{
CQOrdenesVenta lCQOVenta=FFactura->ObtenOrdenesVenta();
OrdenVenta *lOVenta;
int lintContador;
	QTDatosOrdenes->setNumRows(lCQOVenta.count());	
	for(lOVenta=lCQOVenta.first(),
	    lintContador=0;
	    lOVenta;
	    lOVenta=lCQOVenta.next(),
	    lintContador++)
	SISCOMAnexarRegistroALaTabla(lintContador,
				QTDatosOrdenes,
			       QStringList() <<
			       lOVenta->ObtenIdVenta() <<
			       lOVenta->ObtenFechaHora()    <<
			       lOVenta->ObtenImporte());
}
void QFacturacion::AnexaOrdenParaFacturar(int pintNOrden)
{
CQOrdenesVenta lCQOVenta=FFactura->ObtenOrdenesVenta();
		QSLPFacturacion << lCQOVenta.at(pintNOrden)->ObtenIdVenta();

}
void QFacturacion::EjecutaFacturacion()
{
CQFFacturas.setAutoDelete(true);
CQFFacturas.clear();
CQCtrFacturacion lCQFacturacion(CSisDatCom,
				QSLPFacturacion,
				&CQFFacturas);
}
void QFacturacion::MuestraFacturacion()
{
if(CQFFacturas.count()==2)
{
CQProductosCotizacion *lCQPCotizacion=CQFFacturas.at(1)->ObtenProductos();
ProductoCotizacion *lPCotizacion;
CQPrecios lCQPrecios;
int lintContador;
	QTFactura->setNumRows(lCQPCotizacion->count());
	for(lintContador=0,
	    lPCotizacion=lCQPCotizacion->first();
	    lPCotizacion;
	    lPCotizacion=lCQPCotizacion->next(),
	    lintContador++)
	{
	 lCQPrecios=lPCotizacion->ObtenProducto()->ObtenPrecios();
	 SISCOMAnexarRegistroALaTabla(lintContador,
			 	QTFactura,
			 	QStringList () <<
				lPCotizacion->ObtenProducto()->ObtenClave() <<
				lPCotizacion->ObtenCantidad() <<
				lCQPrecios.at(0)->ObtenPrecio() <<
				lPCotizacion->ObtenImporte());
	}
	QLCNTotal->display(lCQPCotizacion->ObtenImporteTotal());
	QLEImporteSinIva->setText(CQFFacturas.at(1)->ObtenImporteSinIva());
	QLEIva->setText(CQFFacturas.at(1)->ObtenIva());

delete lCQPCotizacion;
}	
}
