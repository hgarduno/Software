
#ifndef __IMP_ORDENES_H__
#define __IMP_ORDENES_H__
#include <UIC_H_Ordenes.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class QOrdenes:public Ordenes
{
 Q_OBJECT
public:
	QOrdenes(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QOrdenes();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3Lst SisReg3LstOrdenes;
	SiscomRegistro3Lst SisReg3LstDetalleOrden;
	SiscomRegistro3    *SisReg3Orden;
	char chrArrFechaIni[25];
	char chrArrFechaFin[25];
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Consulta();
	void Muestra();
	void ConsultandoDetalleOrden();
	void ConsultaDetalleOrden();
	void MuestraDetalleOrden();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotRangoFechas();
	void SlotAnexarContabilidad();
	void SlotSeleccionaOrden(int,int,int,const QPoint &);
	void SlotSeleccionaOrden(int,int);
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QOrdenes *InstanciaOrdenes(void *,char **,void *,const char *,int);
#endif
