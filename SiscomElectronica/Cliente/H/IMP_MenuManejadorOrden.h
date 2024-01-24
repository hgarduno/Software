#ifndef __IMP_MENUMANEJADORORDEN_H__
#define __IMP_MENUMANEJADORORDEN_H__
#include <qpopupmenu.h>

class QAction;
class zProductoCotizar;
class QMenuManejadorOrden:public QPopupMenu
{
Q_OBJECT
public:
	QMenuManejadorOrden(zProductoCotizar *pzProdCotizar,
			    const QPoint &pQPoint,
			    QWidget *pQWParent=0,
			    const char *pchrPtrName=0);
	void EjecutaMenu();
private:
	QAction *AgregaOpcion(const char *pchrPtrName,
			  const char *pchrPtrTexto,
			  const char *pchrPtrSlot);
	void IniciaOpciones();
	void FormaCabecera(char *pchrPtrCabecera);
	void CapturaCantidad(char *pchrPtrCantidad);
private:
	QAction *QACabecera;
	QAction *QAJuegos;
	QAction *QAJuegosSeparados;

	QAction *QAEliminaProd;
	QAction *QADescuentoOrden;
	QAction *QAPrecioProducto;
	zProductoCotizar *zProdCotizar;
	char chrArrNJuegos[28];
	char chrArrNJuegosSeparados[28];
	char chrArrDescuentoOrden[28];
	char chrArrPrecioProducto[28];
private slots:
	void SlotNumeroJuegos();
	void SlotJuegosSeparados();
	void SlotPorDescuento();
	void SlotEliminaProducto();
	void SlotDescuentoOrden();
	void SlotDesProducto();
	void SlotPrecioProducto();
	
signals:
	void SignalEliminaProducto(zProductoCotizar *pzProdCotizar);
	void SignalNumeroJuegos(const char *pchrPtrNJuegos);
	void SignalNumeroJuegosSeparados(int pintNJuegosSeparados);
	void SignalDescuentoOrden(const char *pchrPtrDescuento);
	void SignalDesProducto(const char *pchrPtrDescOrden);
	void SignalPrecioProducto();
};

#endif

