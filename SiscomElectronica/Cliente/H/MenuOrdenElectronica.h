#ifndef __MENUORDENELECTRONICA_H__
#define __MENUORDENELECTRONICA_H__
#include <qpopupmenu.h>
#include <SiscomRegistros3.h>
class QAction;
class SiscomDatCom;
class ProductoE;
class MenuOrdenElectronica:public QPopupMenu
{
Q_OBJECT
public:
     MenuOrdenElectronica(SiscomDatCom *,
     			  char **pchrPtrArgumentos,
     			  ProductoE *,
     			  const QPoint &,
			  QWidget *,
			  const char *);
     int ObtenNumJuegos();
private:
	QAction *QACabecera;
	QAction *QAJgsSep;
	QAction *QAJgs;
	QAction *QACCliente;
	QAction *QAEliminaProd;
	QAction *QAPorDescuento;

	SiscomDatCom *SisDatCom;
	ProductoE *PProducto;
	int intNumJuegos;
	int intNumJuegosSep;
	int intPorcentajeDesc;
	SiscomRegistro3Lst SisReg3LstCCaja;
	char **chrPtrArgumentos;
private:
	void IniciaOpciones();
	QAction *AgregaOpcion(const char *,
			  QString ,
			  const char *);
	void SeguridadControlesCaja();
	void ColocaSeguridadCaja();
	void MuestraEstadoControlesCaja();
	void AsignaNivelSeguridad();
	SiscomRegistro3 *EstadoControl(const char *);
private slots:
	void S_JuegosSeparados();
	void S_Juegos();
	void S_EliminaProductos();
	void S_PorcentajeDescuento();
	void S_PorcentajeDescuentoOrden();
signals:
	void SignalCambioNumJuegos(int);
	void SignalJuegosSeparados(int);
	void SignalEliminaProductos();
	void SignalPorcentajeDescuento();
	void SignalPorcentajeDescuentoOrden(int);
};


#endif
