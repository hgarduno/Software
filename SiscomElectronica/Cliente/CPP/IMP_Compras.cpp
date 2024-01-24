#include <IMP_Compras.h>
#include <IMP_QControlFecha.h>
#include <IMP_CapturaIva.h>
#include <IMP_CapturaDato.h>
#include <ComprasE.h>
#include <TipoPrecios.h>

#include <zSiscomElectronica.h>

#include <SISCOMComunicaciones++.h>
#include <QCtrlCmbBodegas.h>
#include <QCtrlOrigenCompra.h>
#include <qgroupbox.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qmessagebox.h>
#include <qapplication.h>
#include <qclipboard.h>


#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <zSiscomRecibeDeCadena.h>

QCompras *InstanciaCompras(void *pSisDatCom,
			    char **pchrPtrArgumentos,
			    void *pQWParent,
			    const char *pchrPtrName,
			    int pintFlags)
{
	return new QCompras((SiscomDatCom *)pSisDatCom,
			pchrPtrArgumentos,
			(QWidget *)pQWParent,
			pchrPtrName,
			pintFlags);
}
QCompras::QCompras(SiscomDatCom *pSisDatCom ,
                   char **pchrPtrArgumentos,
		   QWidget* parent,
		   const char* name,
		   WFlags fl )
    : Compras( parent, name, fl ),
    SisDatCom(pSisDatCom),
    chrPtrArgumentos(pchrPtrArgumentos),
    intProductoValido(1),
    zSisConexion((zSiscomConexion *)gzSiscomConexion)
{
	IniciaVariables();
	ConectaSlots();
}

QCompras::~QCompras()
{
}

void QCompras::IniciaVariables()
{
	QCFPago->ColocaFechaHoy();
	QCFCompra->ColocaFechaHoy();
	//QCFCompra->setFocus();
	QLECProductos=SiscomColocaEditAlCombo(QCBProductos,"QLECProductos");
	QLECProveedores=SiscomColocaEditAlCombo(QCBProveedores,"QLECProveedores");
	QLECFormaPago=SiscomColocaEditAlCombo(QCBFormaPago,"QLECFormaPago");
	QLECTipoPrecio=SiscomColocaEditAlCombo(QCBTipoPrecio,"QLECTipoPrecio");
	QMProductos=new QManProductos(SisDatCom,
				       chrPtrArgumentos[0],
				      QCBProductos,
				      QLECProductos,
				      QLEDescripcion,
				      this,
				      "MProductos");
	MTipoPrecio=new ManTipoPrecio(SisDatCom,	
				      QCBTipoPrecio,
				      QLECTipoPrecio,
				      QLEDescripcion,
				      this,
				      "MTipoPrecio");
	LlenaComboProveedores();
	TTipoPrecio=MTipoPrecio->ObtenTipoPrecio(0);

	ModificaDatos[0]=0;
	ModificaDatos[1]=&QCompras::ModificaCantidad;
	ModificaDatos[2]=&QCompras::ModificaCantidadATransferir;
	ModificaDatos[3]=&QCompras::ModificaPrecioCompra;
	ModificaDatos[4]=&QCompras::CambiaConMasIva;
	ModificaDatos[5]=0;
	ModificaDatos[6]=0;
	ModificaDatos[7]=0;
	ModificaDatos[8]=0;
	ModificaDatos[9]=0;

	IniciaBodegas(); 

	QCtrOrigenCompra->Servidor(SisDatCom);
	QCtrOrigenCompra->IniciaControl();
	QCtrOrigenCompra->setFocus();
}
void QCompras::LlenaComboProductos()
{
/*
ConsultaProductosE lCnsProductos(SisDatCom,
				"",
				"",
				"",
				PProductos);
ProductoE *lProducto;
  for(lProducto=PProductos.first();
      lProducto;
      lProducto=PProductos.next())
	QCBProductos->insertItem(lProducto->SRegistrosPro2["CveProducto"]);
*/

}
void QCompras::LlenaComboProveedores()
{
ConsultaEmpresasN lCnsExpendios(SisDatCom,
                                "Proveedores",
				EProveedores);
EmpresaN *lEmpresa;
		for(lEmpresa=EProveedores.first(); lEmpresa; lEmpresa=EProveedores.next())
		QCBProveedores->insertItem(lEmpresa->SRegistrosPro2["RazonSocial"]);
}
void QCompras::ConectaSlots()
{
	connect(QCFCompra,
		SIGNAL(Signal_EnterA_o()),
		SLOT(S_PasaFocoProductos()));
	connect(QLECProductos,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoBodegas()));

	connect(QCtrCmbBodegas,
		SIGNAL(SignalSelecciono(SiscomRegistro3 *)),
		SLOT(S_SeleccionoBodega(SiscomRegistro3 *)));
			
	connect(QLECProveedores,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoFormaPago()));
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoACantidadTransfiereZacatenco()));
	connect(QLECantidadATransferirZacatenco,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoPrecioCompra()));
	
	connect(QLEPCompra,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoPrecioVenta()));
	connect(QLEPVenta,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoTipoPrecio()));
	connect(QLECTipoPrecio,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoNumFactura()));
	connect(QLECFormaPago,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoCantidad()));
	connect(QLENumFactura,
		SIGNAL(returnPressed()),
		SLOT(S_SeleccionoFormaPago()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_Anexar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(S_Registrar()));
	connect(QMProductos,
		SIGNAL(SignalProducto(ProductoE *)),
		SLOT(S_SelProducto(ProductoE *)));
	connect(QMProductos,
		SIGNAL(SignalNoEstaClave(const char *)),
		SLOT(S_NoEstaLaClave(const char *)));
	connect(MTipoPrecio,
		SIGNAL(SignalTipoPrecio(TipoPrecio *)),
		SLOT(S_SelTipoPrecio(TipoPrecio *)));
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(S_ModificarDatos(int,int,int,const QPoint &)));
	connect(QPBECompra,
		SIGNAL(clicked()),
		SLOT(S_EliminaProductos()));
	connect(QCtrOrigenCompra,
		SIGNAL(SignalOrigenCompra(SiscomRegistro3 *)),
		SLOT(SlotOrigenCompra(SiscomRegistro3 *)));
}
void QCompras::SlotFocoACantidadTransfiereZacatenco()
{
	SiscomPasaFocoControl(QLECantidadATransferirZacatenco);
}
void QCompras::SlotOrigenCompra(SiscomRegistro3 *pSisReg3OrigenCompra)
{
	SisReg3OrigenCompra=pSisReg3OrigenCompra;
  	QCFCompra->setFocus();	
}
void QCompras::S_SeleccionoBodega(SiscomRegistro3 *pSisReg3Bodega)
{
	SisReg3Bodega=pSisReg3Bodega;
	S_PasaFocoProveedor();
}
void QCompras::S_PasaFocoBodegas()
{
	QCtrCmbBodegas->setFocus();
}
void QCompras::S_EliminaProductos()
{
QMemArray<int> lQMAProductos=SiscomFilasSeleccionadas(QTDatos);
int lintContador;
int lintNProdSeleccionados=lQMAProductos.count();

	QTDatos->removeRows(lQMAProductos);
	
	for(lintContador=0;
	    lintContador<lintNProdSeleccionados;
	    lintContador++)
	{
	  PCompras.remove(PCompras.at(lQMAProductos[lintContador]));	  
	}
	



}
void QCompras::S_ModificarDatos(int pintNFila,
				int pintNumColumna,
				int,
				const QPoint &)
{
	if(QTDatos->numRows() &&
	   ModificaDatos[pintNumColumna])
	(this->*ModificaDatos[pintNumColumna])(pintNFila);
}
void QCompras::S_MasIva()
{
}
void QCompras::S_PasaFocoMasIVA()
{
}
void QCompras::S_SelTipoPrecio(TipoPrecio *pTipoPrecio)
{
	TTipoPrecio=pTipoPrecio;
}
void QCompras::S_NoEstaLaClave(const char *pchrPtrClave)
{

	QMessageBox::information(this,
				 "Error Sistema",
				 QString("NO se encontro:") +
				 pchrPtrClave);
	SiscomPasaFocoControl(QLECProductos);
	intProductoValido=0;

}
void QCompras::S_SelProducto(ProductoE *pProducto)
{
char lchrArrProveedor[128],
	lchrArrPrecioVenta[10],
	lchrArrPrecioCompra[10];
ComprasE lCUltimaCompra;
	PProducto=pProducto;
ConsultaProductosE lCnsProductos(SisDatCom);
	lCnsProductos.ConsultaUltimaCompra(TTipoPrecio,
						PProducto,
						chrPtrArgumentos[0],
						&lCUltimaCompra);
	intProductoValido=1;
CompraE *lCCompra;
if(lCUltimaCompra.count())
{
	 lCCompra=lCUltimaCompra.at(0);
	QLECantidad->setText(lCCompra->SRegistrosPro2["Cantidad"]);
	QLEPCompra->setText((chrPtrUPCompra=lCCompra->SRegistrosPro2["Precio"]));
	QLEPVenta->setText(lCCompra->SRegistrosPro2["PrecioVenta"]);
	QLERSUltimaCompra->setText(lCCompra->SRegistrosPro2["RazonSocial"]);
	QLEFechaCompra->setText(lCCompra->SRegistrosPro2["Fecha"]);
	QLECantidadUC->setText(lCCompra->SRegistrosPro2["Cantidad"]);
	QLEPCompraUC->setText(lCCompra->SRegistrosPro2["Precio"]);
	QLENumFacturaUC->setText(lCCompra->SRegistrosPro2["NumFactura"]);
	/*QLEProveedorUC->setText(lCCompra->SRegistrosPro2["RazonSocial"]); */
	QGBUCompra->setTitle(QString("UltimaCompra:Proveedor ") +
			     lCCompra->SRegistrosPro2["RazonSocial"]);
}
}
void QCompras::S_PasaFocoNumFactura()
{
	SiscomPasaFocoControl(QLENumFactura);
}
void QCompras::S_PasaFocoTipoPrecio()
{
	SiscomPasaFocoControl(QLECTipoPrecio);
}
void QCompras::S_PasaFocoPrecioVenta()
{
	SiscomPasaFocoControl(QLEPVenta);
}
void QCompras::S_Registrar()
{
OpCompras lCRegistra(SisDatCom,	
		    chrPtrArgumentos[1],
		    PCompras);
	 lCRegistra.RegistraCompras();
	 PCompras.clear();
	 QTDatos->setNumRows(0);
}
void QCompras::S_SeleccionoFormaPago()
{
	if(QLECFormaPago->text()=="Credito")
	{
	QCFPago->setEnabled(true);
	connect(QLENumFactura,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoFechaPago()));
	connect(QCFPago,
		SIGNAL(Signal_EnterA_o()),
		SLOT(S_PasaFocoAnexar()));
	}
	else
	{
	QCFPago->setEnabled(false);
	/*
	connect(QLENumFactura,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAnexar()));
	connect(QCFPago,
		SIGNAL(Signal_EnterA_o()),
		SLOT(S_PasaFocoAnexar()));
	 */
	QPBAnexar->setEnabled(true);
	SiscomPasaFocoControl(QPBAnexar);
	}
	

}
void QCompras::S_PasaFocoProductos()
{
	SiscomPasaFocoControl(QLECProductos);
}

void QCompras::S_PasaFocoProveedor()
{
	if(intProductoValido)
	SiscomPasaFocoControl(QLECProveedores);
}

void QCompras::S_PasaFocoCantidad()
{
	SiscomPasaFocoControl(QLECantidad);
}

void QCompras::S_PasaFocoPrecioCompra()
{
	SiscomPasaFocoControl(QLEPCompra);
}

void QCompras::S_PasaFocoFormaPago()
{
	SiscomPasaFocoControl(QLECFormaPago);
}

void QCompras::S_PasaFocoAnexar()
{
	QPBAnexar->setEnabled(true);
	SiscomPasaFocoControl(QPBAnexar);
}

void QCompras::S_PasaFocoFechaPago()
{
	SiscomPasaFocoControl(QCFPago);
}

void QCompras::S_Anexar()
{
EmpresaN *lEmpresa=EProveedores.at(QCBProveedores->currentItem());
int lintNumCompras=QTDatos->numRows();
const char *lchrPtrConIva;
const char *lchrPtrMensajeValidaCantidadATransferir;
	if(!ValidaCantidadATransferir(&lchrPtrMensajeValidaCantidadATransferir))
	{
	lchrPtrConIva=ProductoConIva();
	QPBAnexar->setEnabled(false);
	QCFCompra->setFocus();

	PProducto->SiscomActualizaCampo("IdProveedor",lEmpresa->SRegistrosPro2["IdEmpresa"]);
	PProducto->SiscomActualizaCampo("Precio",(const char *)QLEPCompra->text());
	PProducto->SiscomActualizaCampo("IdExpendio",chrPtrArgumentos[0]);
	PProducto->SiscomActualizaCampo("NmbPrecio",(const char *)QCBFormaPago->currentText());
	PProducto->SiscomActualizaCampo("NumFactura",(const char *)QLENumFactura->text());
	PProducto->SiscomActualizaCampo("Cantidad",(const char *)QLECantidad->text());
	PProducto->SiscomActualizaCampo("FechaPago",(const char *)QCFPago->ObtenFecha());
	PProducto->SiscomActualizaCampo("PrecioIVA",lchrPtrConIva);
	PProducto->SiscomActualizaCampo("Importe",SiscomObtenInformacionDelEdit(QLEPVenta));
	PProducto->SiscomActualizaCampo("IdBodega",(*SisReg3Bodega)["idbodega"]);
	PProducto->SiscomActualizaCampo("IdOrigenCompra",(*SisReg3OrigenCompra)["idrfcorigen"]);
	PProducto->SiscomActualizaCampo("CantidadTransfiereZacatenco",SiscomObtenInformacionDelEdit(QLECantidadATransferirZacatenco));
	PCompras << PProducto;	
	QTDatos->setNumRows(lintNumCompras+1);

	SiscomAnexarRegistroALaTabla(lintNumCompras,
				     QTDatos,
				     QStringList () <<
				     PProducto->SRegistrosPro2["CveProducto"] 	<<
				     QLECantidad->text() 			<<
				     QLECantidadATransferirZacatenco->text()	<<
				     QLEPCompra->text()  			<<
				     ""						<<
				     QCBProveedores->currentText() 		<<
				     QCBFormaPago->currentText()		<<
				     ""						<<
				     QLENumFactura->text()); 
	QPBRegistrar->setEnabled(true);
	AnexaControlIvaTabla(lintNumCompras,lchrPtrConIva);
	}
	else
	{
	QMessageBox::information(this,
				 "Aviso Sistema",
				 lchrPtrMensajeValidaCantidadATransferir);
	SiscomPasaFocoControl(QLECantidadATransferirZacatenco);
	
	}
}
const char *QCompras::ProductoConIva()
{
QCapturaIva lQCapturaIva;

		return lQCapturaIva.ObtenSinConIva();

}
void QCompras::AnexaControlIvaTabla(int pintNFila,
				    const char *pchrPtrMasConIva)
{
QCheckTableItem *lQCTbItem=new QCheckTableItem(QTDatos,pchrPtrMasConIva);

	QTDatos->setItem(pintNFila,4,lQCTbItem);
	
}
void QCompras::CambiaEstadoControlIva(QCheckTableItem *pQCTabItem,
				      const char *pchrPtrTexto)
{
	pQCTabItem->setText(pchrPtrTexto);
	pQCTabItem->setChecked(true);
}
void QCompras::CambiaConMasIva(int pintNumFila)
{
QCheckTableItem *lQCTbItem=(QCheckTableItem *)QTDatos->item(pintNumFila,4);
QString lQSTexto=lQCTbItem->text();	

		if(lQSTexto=="+IVA")
		{
		   CambiaEstadoControlIva(lQCTbItem,"Con IVA");
		   PCompras.at(pintNumFila)->SiscomActualizaCampo("PrecioIVA","Con IVA");

		}
		if(lQSTexto=="Con IVA")
		{
		   CambiaEstadoControlIva(lQCTbItem,"+IVA");
		   PCompras.at(pintNumFila)->SiscomActualizaCampo("PrecioIVA","+IVA");
		}

}


void QCompras::ModificaCantidad(int pintNFila)
{
QCapturaDato lQCDato("Cambia Cantidad",
		      "Cantidad",
	              PCompras.at(pintNFila)->SRegistrosPro2["Cantidad"]);
char lchrArrCantidad[10];
	lQCDato.ObtenDato(lchrArrCantidad);

	PCompras.at(pintNFila)->SiscomActualizaCampo("Cantidad",lchrArrCantidad);
	QTDatos->setText(pintNFila,1,lchrArrCantidad);

	
}
void QCompras::ModificaPrecioCompra(int pintNFila)
{
QCapturaDato lQCDato("Precio Compra",
		      "Precio De Compra",
	              PCompras.at(pintNFila)->SRegistrosPro2["Precio"]);
char lchrArrCantidad[10];
	lQCDato.ObtenDato(lchrArrCantidad);

	PCompras.at(pintNFila)->SiscomActualizaCampo("Precio",lchrArrCantidad);
	QTDatos->setText(pintNFila,3,lchrArrCantidad);



}
void QCompras::ModificaCantidadATransferir(int pintNFila)
{
QCapturaDato lQCDato("Cantidad A Transferir",
		      "Cantidad",
	              PCompras.at(pintNFila)->SRegistrosPro2["CantidadTransfiereZacatenco"]);
char lchrArrCantidad[10];
	lQCDato.ObtenDato(lchrArrCantidad);

	PCompras.at(pintNFila)->SiscomActualizaCampo("CantidadTransfiereZacatenco",lchrArrCantidad);
	QTDatos->setText(pintNFila,2,lchrArrCantidad);



}

void QCompras::closeEvent(QCloseEvent *pQCEvent)
{
  emit SignalTerminar(this);
}

void QCompras::IniciaBodegas()
{
	QCtrCmbBodegas->Servidor(SisDatCom);
	QCtrCmbBodegas->Expendio(chrPtrArgumentos[0]);
	QCtrCmbBodegas->IniciaControl();

}
int QCompras::ValidaCantidadATransferir(const char **pchrPtrMensajeCantidadATransferir)
{
 zSiscomElectronica lzSisElectronica(zSisConexion,"ValidaCantidadATransferir");
 return lzSisElectronica.ValidaExistenciaATransferir(
 				SiscomObtenInformacionDelEdit(QLECantidadATransferirZacatenco),
				SiscomObtenInformacionDelEdit(QLECantidad),
 				(*PProducto)["CveProducto"],
				pchrPtrMensajeCantidadATransferir);
}

void QCompras::keyPressEvent(QKeyEvent *pQKEvent)
{
zSiscomRecibeDeCadena lzSisReDeCadena;
	if(pQKEvent->state()==Qt::ControlButton)
	{
	  if(pQKEvent->key()==Qt::Key_V)
	  {
	  	LogSiscom("Pegando .....");
		LogSiscom("%s",(const char *)QApplication::clipboard()->text(QClipboard::Clipboard));
	  }

	}

}
