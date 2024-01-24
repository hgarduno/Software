#include <IMP_ProductoPractica.h>
#include <SISCOMComunicaciones++.h>
#include <ProductosE.h>
#include <CotizaDispositivos.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QProductoPractica::QProductoPractica(SiscomDatCom *pSisDatCom,
				     const char *pchrPtrIdExpendio,
				     const char *pchrPtrNmbTipoPrecio,
				     QWidget* parent,
				     const char* name,
				     bool modal, 
				     WFlags fl ):
    ProductoPractica( parent, name, modal, fl ),
    SisDatCom(pSisDatCom),
    chrPtrIdExpendio(pchrPtrIdExpendio),
    chrPtrNmbTipoPrecio(pchrPtrNmbTipoPrecio)

{
	IniciaVariables();
	ConectaSlots();
	 exec();
}

QProductoPractica::~QProductoPractica()
{
}
void QProductoPractica::IniciaVariables()
{
QLECProductos=SiscomColocaEditAlCombo(QCBProductos,"QLECProductos");
QMProductos=new QManProductos(SisDatCom,
			      chrPtrIdExpendio,
			      QCBProductos,
			      QLECProductos,
			      QLEDescripcion,
			      this,
			      "QMProductos");
SiscomPasaFocoControl(QLECProductos);	
}
void QProductoPractica::ConectaSlots()
{
	connect(QMProductos,
		SIGNAL(SignalProducto(ProductoE *)),
		SLOT(S_SeleccionoProducto(ProductoE *)));
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAnexar()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_Anexar()));


}
void QProductoPractica::S_Anexar()
{
	done(1);
}
void QProductoPractica::S_SeleccionoProducto(ProductoE *pProducto)
{
	PProducto=pProducto;
	SiscomPasaFocoControl(QLECantidad);

}
void QProductoPractica::S_PasaFocoAnexar()
{
ProductosE lProductos;
	PProducto->SiscomActualizaCampo("IdExpendio",chrPtrIdExpendio);
	PProducto->SiscomActualizaCampo("NmbPrecio",chrPtrNmbTipoPrecio);
	PProducto->SiscomActualizaCampo("Cantidad",(const char *)QLECantidad->text());
	lProductos << PProducto;
	CotizaDispositivosE lCotDispositivo(SisDatCom,
					    lProductos);
	if(lProductos.at(1))
	{
	QLCDNTotal->display(lProductos.at(1)->SRegistrosPro2["Importe"]);	
	QLEExistencia->setText(lProductos.at(0)->SRegistrosPro2["Existencia"]);
	SiscomPasaFocoControl(QPBAnexar);
	}
}
ProductoE *QProductoPractica::ObtenProducto()
{
	return PProducto;
}
