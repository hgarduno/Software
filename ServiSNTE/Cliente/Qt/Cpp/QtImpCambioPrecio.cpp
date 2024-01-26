#include <QtImpCambioPrecio.h>

#include <qlineedit.h> 
#include <qpushbutton.h>
#include <zSiscomQt3.h>

#include <zProducto.h>
QtImpCambioPrecio::QtImpCambioPrecio(
			zProducto *pzProducto,
			QWidget *pQWParent,
			const char *pchrPtrName,
			bool pbModal,
			WFlags pWFlags):
		CambioPrecio(pQWParent,pchrPtrName,pbModal,pWFlags),
		intAceptar(0),
		zProdCambiar(pzProducto)

{
 ConectaSlots();
 MuestraInformacion();
 exec();

}
void QtImpCambioPrecio::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QLENvoPrecio,
		SIGNAL(returnPressed()),
		SLOT(SlotAMotivoCambio()));
}
void QtImpCambioPrecio::SlotAMotivoCambio()
{
   zSiscomQt3::Foco(QTEMotivoCambioPrecio);
}
void QtImpCambioPrecio::SlotAceptar()
{
	intAceptar=1;
	CambiaPrecio();
	done(1);
}
void QtImpCambioPrecio::SlotCancelar()
{
	intAceptar=0;
	done(1);
}

void QtImpCambioPrecio::reject()
{

}

int QtImpCambioPrecio::Aceptar()
{
  return intAceptar;
}
void QtImpCambioPrecio::MuestraInformacion()
{
  QLEPrecioAnterior->setText((const char *)(*zProdCambiar)["preciogeneral"]);
  zSiscomQt3::Foco(QLENvoPrecio);
}
void QtImpCambioPrecio::CambiaPrecio()
{
const char *lchrPtrPrecioNvo=strdup(zSiscomQt3::Texto(QLENvoPrecio));
zProdCambiar->ActualizaCampo("preciogeneral",(const unsigned char *)lchrPtrPrecioNvo);
}
