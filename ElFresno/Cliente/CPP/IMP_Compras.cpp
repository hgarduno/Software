#include <IMP_Compras.h>
#include <IMP_QControlFecha.h>
#include <SISCOMComunicaciones++.h>

#include <Empresas.h>
#include <Productos.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qdatetime.h>

QCompras *InstanciaCompras(void *pCSisDatCom,
			   void *pQWParent,
			   const char *pchrPtrName,
			   int pintWFlags)
{
	return new QCompras((CSISCOMDatComunicaciones *)pCSisDatCom,
			    (QWidget *)pQWParent,
			    pchrPtrName,
			    pintWFlags);
}
QCompras::QCompras(CSISCOMDatComunicaciones *pCSisDatCom,
		   QWidget* parent,
		   const char* name, 
		   WFlags fl )
    : Compras( parent, name, fl ),
    CSisDatCom(pCSisDatCom),
    C_Compra(0)
{
	IniciaVariables();
	ConectaSlots();
	
}
void QCompras::IniciaVariables()
{
	//CQCompra.setAutoDelete(true);
	QLECProductos=ColocaLineEditAlCombo(QCBProductos,"QLECProductos");
	QLECRazonSocial=ColocaLineEditAlCombo(QCProveedores,"QLECRazonSocial");
	QLECFormaPago=ColocaLineEditAlCombo(QCBFormaPago,"QLECFormaPago");
	QCFechaHoy->ColocaFechaHoy();
	QCFechaPago->ColocaFechaHoy();
	QCFechaHoy->setFocus();
	CQSProducto=new CQSeleccionaProducto(
			CSisDatCom,
			this,
			"CQSProducto",
			QLECProductos,
			QLEDescripcion,
			QLEUnidades,
			QCBProductos);
	CQSProveedor=new CQSeleccionaProveedor(CSisDatCom,
					   this,
					   "CQSProveedor",
					   QLECRazonSocial,
					   QCProveedores);

	connect(CQSProducto,
		SIGNAL(Signal_SProducto(Producto *)),
		SLOT(S_SeleccionoProducto(Producto *)));
	connect(CQSProveedor,
		SIGNAL(Signal_Proveedor(Empresa *)),
		SLOT(S_SeleccionoProveedor(Empresa *)));
	connect(QCFechaHoy,
		SIGNAL(Signal_EnterA_o()),
		SLOT(S_PasaFocoProducto()));
	AbreArchivoCompras();
	QPBAnexar->setEnabled(false);
	QPBRegistrar->setEnabled(false);
					   
			
}
void QCompras::S_PasaFocoProducto()
{
	PasaFocoControl(QLECProductos);	
}
void QCompras::S_SeleccionoProducto(Producto *pProducto)
{
	PProducto=pProducto;
	PasaFocoControl(QLECRazonSocial);
}
void QCompras::S_SeleccionoProveedor(Empresa *pEProveedor)
{
	if(C_Compra)
	  C_Compra->PonProveedor(pEProveedor);
	E_Proveedor=pEProveedor;
	PasaFocoControl(QLECantidad);
}
void QCompras::PonExpendio(Empresa *pEmpresa)
{
	E_Expendio=pEmpresa;
	MuestraNombreExpendio();
}
void QCompras::MuestraNombreExpendio()
{
	setCaption(QString("Sitema De Compras:") +
		   E_Expendio->ObtenRazonSocial());
}
void QCompras::ConectaSlots()
{
	connect(QCBFormaPago,
		SIGNAL(activated(int)),
		SLOT(S_SeleccionoFormaPago(int)));
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoPrecioCompra()));
	connect(QLEPCompra,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoFormaPago()));
	connect(QLECFormaPago,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoNumFactura()));
	connect(QLENumFactura,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoFechaPago()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_Anexar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(S_RegistrarCompra()));
	connect(QPBECompra,
		SIGNAL(clicked()),
		SLOT(S_EliminaCompra()));
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(S_SeleccionoCompra(int,int,int,const QPoint &)));

}
void QCompras::S_EliminaCompra()
{
int lintNEliminar;
	if((lintNEliminar=QTDatos->currentRow())!=-1)
	{
	 C_Compra->EliminaProducto(lintNEliminar);
	 QTDatos->removeRow(lintNEliminar);
	}
}
void QCompras::S_SeleccionoCompra(int pintNFila,
				  int,
				  int,
				  const QPoint &)
{
       QTDatos->selectRow(pintNFila);
}
void QCompras::S_Anexar()
{
ProductoCotizacion *lProdCotizacion;

	if(!C_Compra)
	  C_Compra=new Compra(strdup((const char *)QCFechaHoy->ObtenFecha()),
			      strdup((QCFechaPago->isEnabled() ? 
			      (const char *)QCFechaPago->ObtenFecha() :
			      "")),
			      SISCOMObtenInformacionDelEdit(QLECFormaPago),
			      SISCOMObtenInformacionDelEdit(QLENumFactura),
			      E_Proveedor,
			      E_Expendio);
	AnexarRegistroALaTabla(QTDatos,
			       QStringList() <<
			       PProducto->ObtenClave() <<
			       QLECantidad->text() <<
			       QLEPCompra->text() <<
			       QLECRazonSocial->text() <<
			       QLECFormaPago->text() <<
				(QCFechaPago->isEnabled() ? 
			        (const char *)QCFechaPago->ObtenFecha() :
			         "")		   <<
				 QLENumFactura->text());
	PProducto->AnexaPrecio(new Precio("",
					  "",
					  SISCOMObtenInformacionDelEdit(QLEPCompra),
					  new TipoPrecio("","","")));
	C_Compra->AnexaProducto(new ProductoCotizacion(PProducto,
						       SISCOMObtenInformacionDelEdit(QLECantidad),
						       "",
						       "",
						       ""));
	PasaFocoControl(QLECProductos);
	QPBRegistrar->setEnabled(true);
}
void QCompras::S_RegistrarCompra()
{
	CQCompra.append(C_Compra);
CQCtrCompras lCQComprar(CSisDatCom,
			QStringList () << 
			QString("RegistrarCompras") <<
			"Parametro1" <<
			"Parametro2",
			&CQCompra);
	CQCompra.clear();
	QTDatos->setNumRows(0);
	RegistraCompraEnArchivo();
	delete C_Compra;
	C_Compra=0;
	QPBRegistrar->setEnabled(false);
	QPBAnexar->setEnabled(false);
}
void QCompras::S_PasaFocoPrecioCompra()
{
	PasaFocoControl(QLEPCompra);
}
void QCompras::S_PasaFocoFechaPago()
{
	if(QCFechaPago->isEnabled())
	PasaFocoControl(QCFechaPago);
	else
	{
	QPBAnexar->setEnabled(true);
	PasaFocoControl(QPBAnexar);
	}
}
void QCompras::S_PasaFocoNumFactura()
{
	PasaFocoControl(QLENumFactura);
}
void QCompras::S_PasaFocoFormaPago()
{
	PasaFocoControl(QLECFormaPago);
}
void QCompras::S_SeleccionoFormaPago(int pintNFormaPago)
{
	QCFechaPago->setEnabled(pintNFormaPago);
}


QCompras::~QCompras()
{
	printf("QCompras::~QCompras\n");
}

void QCompras::AbreArchivoCompras()
{
char lchrArrNmbArchivo[1024];

	sprintf(lchrArrNmbArchivo,
		"%s/RegistroCompras.txt",
		getenv("HOME"));
	if(!(FleRegCompras=fopen(lchrArrNmbArchivo,"a")))
	  printf("QCompras::AbreArchivoCompras:No se pudo abrir el archivo para el registro de compras\n");
	else
	printf("AbreArchivoCompras:El Archivo [%s]\n",
			  lchrArrNmbArchivo);
}
void QCompras::RegistraCompraEnArchivo()
{
CQProductosCotizacion lCQPCotizacion;
CQPrecios lCQPrecios;
ProductoCotizacion *lProdCotizacion;
QDateTime lQDTActual;
	lCQPCotizacion=C_Compra->ObtenProductosCompra();
	lQDTActual=QDateTime::currentDateTime();
   for(lProdCotizacion=lCQPCotizacion.first();
       lProdCotizacion;
       lProdCotizacion=lCQPCotizacion.next())
   {
   	lCQPrecios=lProdCotizacion->ObtenProducto()->ObtenPrecios();
	fprintf(FleRegCompras,
		"%s|%s|%s|%s|%s|%s|%s|%s\n",
		(const char *)lQDTActual.toString(Qt::ISODate),
		E_Expendio->ObtenIdEmpresa(),
		E_Expendio->ObtenRazonSocial(),
		E_Proveedor->ObtenIdEmpresa(),
		E_Proveedor->ObtenRazonSocial(),
		lProdCotizacion->ObtenProducto()->ObtenClave(),
		lProdCotizacion->ObtenCantidad(),
		lCQPrecios.at(0)->ObtenPrecio());
   }




	fflush(FleRegCompras);
}
