
#ifndef __IMP_DEVOLUCIONES_H__
#define __IMP_DEVOLUCIONES_H__
#include <UIC_H_Devoluciones.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class QDevoluciones:public Devoluciones
{
 Q_OBJECT
public:
	QDevoluciones(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QDevoluciones();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3Lst SisReg3ProductosE;
	SiscomRegistro3Lst SisReg3DevuelveE;
	SiscomRegistro3Lst SisReg3CalDevolucion;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultaOrden();
	void CotizaOrden();
	void MuestraOrden();
	void CotizandoOrden();
	void EliminaProducto(int);
	void EliminandoProducto(int );
	void MuestraDevolucion();
	void CalculaTotalADevolver();
	void MuestraProductoADevolver(SiscomRegistro3 *);
	void closeEvent(QCloseEvent *);
	void EjecutoDevolucion();
private slots:
	void SlotObtenOrden();
	void SlotSeleccionando(int,int,int,const QPoint &);
	void SlotDevuelve();
	void SlotCambiandoCantidadADevolver(int,int,int,const QPoint &);	
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QDevoluciones *InstanciaDevoluciones(void *,char **,void *,const char *,int);
#endif
