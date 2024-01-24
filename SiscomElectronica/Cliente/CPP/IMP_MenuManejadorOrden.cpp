#include <IMP_MenuManejadorOrden.h>
#include <IMP_CapturaDato.h>
#include <zProductoCotizar.h>
#include <qaction.h>
#include <zSiscomDesarrollo4.h>
#include <stdlib.h>
QMenuManejadorOrden::QMenuManejadorOrden(zProductoCotizar *pzProdCotizar,
				          const QPoint &pQPoint,
					  QWidget *pQWParent,
					 const char *pchrPtrName):
				   QPopupMenu(pQWParent,pchrPtrName),
				   zProdCotizar(pzProdCotizar)
{

IniciaOpciones();
popup(pQPoint);
}
void QMenuManejadorOrden::EjecutaMenu()
{
  exec();
}
QAction *QMenuManejadorOrden::AgregaOpcion(const char *pchrPtrName,
					   const char *pchrPtrTexto,
				       const char *pchrPtrSlot)
{
QAction *lQAction=new QAction(QString(pchrPtrTexto),
			      QKeySequence(0),
			      this,
			      pchrPtrName);
if(pchrPtrSlot)
	connect(lQAction,
	SIGNAL(activated()),
	pchrPtrSlot);
	lQAction->addTo(this);
return lQAction;

}
void QMenuManejadorOrden::IniciaOpciones()
{
char lchrArrCabecera[128];
   FormaCabecera(lchrArrCabecera);
   QACabecera=AgregaOpcion("QACabecera",lchrArrCabecera, 0);
   insertSeparator();
   QAJuegos=AgregaOpcion("QAJuegos","# Juegos",SLOT(SlotNumeroJuegos()));
   QAJuegosSeparados=AgregaOpcion("QAJuegosSeparados","Juegos Separados",SLOT(SlotJuegosSeparados()));
   insertSeparator();
   QADescuentoOrden=AgregaOpcion("QADescuentoOrden","% Descuento Orden",SLOT(SlotDescuentoOrden()));
   insertSeparator();
   QAPrecioProducto=AgregaOpcion("QAPrecioProducto","Precio Producto",SLOT(SlotPrecioProducto()));
   QAEliminaProd=AgregaOpcion("QAEliminaPord","Elimina Producto",SLOT(SlotEliminaProducto()));
   			   
}
void QMenuManejadorOrden::SlotPrecioProducto()
{
 CapturaCantidad(chrArrPrecioProducto);
 zProdCotizar->Precio(chrArrPrecioProducto);
 zProdCotizar->PrecioEspecial("1");
 emit SignalPrecioProducto();

}
void QMenuManejadorOrden::SlotDescuentoOrden()
{
 CapturaCantidad(chrArrDescuentoOrden);
  emit SignalDescuentoOrden(chrArrDescuentoOrden);
}
void QMenuManejadorOrden::SlotDesProducto()
{

}
void QMenuManejadorOrden::SlotEliminaProducto()
{
  emit SignalEliminaProducto(zProdCotizar);
}
void QMenuManejadorOrden::SlotPorDescuento()
{
LogSiscom("% de Descuento");
}
void QMenuManejadorOrden::SlotNumeroJuegos()
{
 CapturaCantidad(chrArrNJuegos);
 emit SignalNumeroJuegos(chrArrNJuegos);
}
void QMenuManejadorOrden::SlotJuegosSeparados()
{
int lintJuegosSeparados;
 CapturaCantidad(chrArrNJuegos);
 lintJuegosSeparados=atoi(chrArrNJuegos);
 emit SignalNumeroJuegosSeparados(lintJuegosSeparados);
 
}

void QMenuManejadorOrden::FormaCabecera(char *pchrPtrCabecera)
{
sprintf(pchrPtrCabecera, "%-40s", zProdCotizar->Clave());
}

void QMenuManejadorOrden::CapturaCantidad(char *pchrPtrCantidad)
{
QCapturaDato lQCDato("Cambia Cantidad",
		     "Cantidad",
		     "1");
lQCDato.ObtenDato(pchrPtrCantidad);
}

