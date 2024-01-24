#include <IMP_ManejadorPrecios.h>

#include <TipoPrecios.h>
#include <ProductosE.h>
#include <SISCOMComunicaciones++.h>


#include <zSiscomQt3.h>
#include <zSiscomDesarrollo4.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QManejadorPrecios *InstanciaManejadorPrecios(void *pSisDatCom,
					     char **pchrPtrArgumentos,
					     void *pQWParent,
					     const char *pchrPtrName,
					     int pintWFlags)
{

	return new QManejadorPrecios((SiscomDatCom *)pSisDatCom,
				      pchrPtrArgumentos,
				      (QWidget *)pQWParent,
				      pchrPtrName,
				      pintWFlags);


}
QManejadorPrecios::QManejadorPrecios(SiscomDatCom *pSisDatCom,
				     char **pchrPtrArgumentos,
					QWidget* parent,
					const char* name,
					WFlags fl )
    : ManejadorPrecios( parent, name, fl ),
    SisDatCom(pSisDatCom),
    chrPtrArgumentos(pchrPtrArgumentos)
{
	IniciaVariables();
	ConectaSlots();
}

QManejadorPrecios::~QManejadorPrecios()
{
}
void QManejadorPrecios::IniciaVariables()
{
	QLECTipoPrecio=SiscomColocaEditAlCombo(QCBTipoPrecio,"QLECTipoPrecio");
	QLECProductos=SiscomColocaEditAlCombo(QCBProductos,"QLECProductos");
	MTipoPrecio=new ManTipoPrecio(SisDatCom,
				      QCBTipoPrecio,
				      QLECTipoPrecio,
				      QLEDescripcion,
				      this,
				      "MTipoPrecio");
	QMProductos=new QManProductos(SisDatCom,
				    chrPtrArgumentos[0],
				    QCBProductos,
				    QLECProductos,
				    QLEDescripcion,
				    this,
				    "MProductos");
	SiscomPasaFocoControl(QLECTipoPrecio);
}
void QManejadorPrecios::ConectaSlots()
{

	connect(MTipoPrecio,
		SIGNAL(SignalTipoPrecio(TipoPrecio *)),
		SLOT(S_TipoPrecio(TipoPrecio *)));
	connect(QMProductos,
		SIGNAL(SignalProducto(ProductoE *)),
		SLOT(S_Producto(ProductoE *)));
	connect(QMProductos,
		SIGNAL(SignalNoEstaClave(const char *)),
		SLOT(S_NoEstaLaClave(const char *)));
	connect(QLENvoPrecio,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoRegistrarPrecio()));
	connect(QPBRegistrarPrecio,
		SIGNAL(clicked()),
		SLOT(S_RegistrarPrecio()));
	connect(QLENvoPrecio,
		SIGNAL(textChanged(const QString &)),
		SLOT(S_HabilitandoRegistro(const QString &)));

}
void QManejadorPrecios::S_HabilitandoRegistro(const QString &)
{
  LogSiscom(" Producto %x Tipo Precio ",PProducto,TTipoPrecio);
      QPBRegistrarPrecio->setEnabled(PProducto && 
      				     TTipoPrecio  && 
				     zSiscomQt3::TextoValido(QLENvoPrecio));

}
void QManejadorPrecios::S_RegistrarPrecio()
{
ConsultaProductosE lCnsProducto(SisDatCom);
		lCnsProducto.ActualizaPrecio(TTipoPrecio,	
					     PProducto,
					     (const char *)QLENvoPrecio->text());
	SiscomPasaFocoControl(QLECTipoPrecio);

HabilitaDesHabilita(false);
}
void QManejadorPrecios::S_PasaFocoRegistrarPrecio()
{
	SiscomPasaFocoControl(QPBRegistrarPrecio);
}
void QManejadorPrecios::S_TipoPrecio(TipoPrecio *pTipoPrecio)
{
	TTipoPrecio=pTipoPrecio;
	QCBProductos->setEnabled(true);
	SiscomPasaFocoControl(QLECProductos);
}
void QManejadorPrecios::S_Producto(ProductoE *pProducto)
{
	PProducto=pProducto;
 	PProducto->SiscomActualizaCampo("IdExpendio",chrPtrArgumentos[0]);
	if(ConsultaPrecioProducto())
	{
	QLENvoPrecio->setEnabled(true);
	SiscomPasaFocoControl(QLENvoPrecio);
	}
}
void QManejadorPrecios::S_NoEstaLaClave(const char *pchrPtrCve)
{

}
int QManejadorPrecios::ConsultaPrecioProducto()
{
ConsultaProductosE lCnsProducto(SisDatCom);
ProductosE lProductos;
		lCnsProducto.ObtenPrecioProducto(TTipoPrecio,
						 PProducto,
						 lProductos);
	if(lProductos.count())
	{
	 QLEPVenta->setText(lProductos.at(0)->SRegistrosPro2["Precio"]);
	 return 1;
	}
	else 
	return 0;
	
}
void QManejadorPrecios::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
void QManejadorPrecios::HabilitaDesHabilita(bool pbEstado)
{
  QCBProductos->setEnabled(pbEstado);
  QLENvoPrecio->setEnabled(pbEstado);
  QPBRegistrarPrecio->setEnabled(pbEstado);
}
