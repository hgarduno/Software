#include <QtSisBotonOrden.h>
#include <qpushbutton.h>
#include <zSiscomDesarrollo4.h>
QtSisBotonOrden::QtSisBotonOrden(QWidget *pQWParent,const char *pchrPtrName):
		QPushButton(pQWParent,pchrPtrName),
		zOrdVenta(0)
{
  setMinimumHeight(60);
  setEnabled(false); 
}
void QtSisBotonOrden::Orden(zOrdenVenta *pzOrdenVenta)
{
	zOrdVenta=pzOrdenVenta;
}
void QtSisBotonOrden::OrdenFavorita(zOrdenFavorita *pzOrdenFavorita)
{
	zOrdFavorita=pzOrdenFavorita;
}

void QtSisBotonOrden::Texto(const char *pchrPtrTexto)
{
   setText(pchrPtrTexto);
}
void QtSisBotonOrden::IdOrden(const char *pchrPtrIdOrden)
{
   chrPtrIdOrden=pchrPtrIdOrden;
}

zOrdenVenta *QtSisBotonOrden::Orden()
{
	return zOrdVenta;
}
zOrdenFavorita *QtSisBotonOrden::OrdenFavorita()
{
	return zOrdFavorita;
}
const char *QtSisBotonOrden::Texto()
{
  return (const char *)text();
}
const char *QtSisBotonOrden::IdOrden()
{
   return chrPtrIdOrden;
}
