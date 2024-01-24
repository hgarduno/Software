
#ifndef __IMP_GANANCIAS_H__
#define __IMP_GANANCIAS_H__
#include <UIC_H_Ganancias.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class QGanancias:public Ganancias
{
 Q_OBJECT
public:
	QGanancias(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QGanancias();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	char chrArrFechaIni[25];
	char chrArrFechaFin[25];
	SiscomRegistro3Lst SisReg3LstResumen;
	SiscomRegistro3Lst SisReg3LstGProducto;
	SiscomRegistro3Lst SisReg3LstGFecha;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void ConsultaGanancias();
	void MuestraGanancias();
	void MuestraResumen();
	void MuestraGananciaProducto();
	void MuestraGananciaFecha();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotCapturaRangoFechas();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QGanancias *InstanciaGanancias(void *,char **,void *,const char *,int);
#endif
