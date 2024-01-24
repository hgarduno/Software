
#ifndef __IMP_PAQUETESREGISTRADOS_H__
#define __IMP_PAQUETESREGISTRADOS_H__
#include <UIC_H_PaquetesRegistrados.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class CQSisProductosPaquete;
class QPaquetesRegistrados:public PaquetesRegistrados
{
 Q_OBJECT
public:
	QPaquetesRegistrados(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QPaquetesRegistrados();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3Lst SReg3LPaquetes;
	SiscomRegistro3 *SReg3Paquete;
	SiscomRegistro3 *SReg3ProductoPaquete;
	int intNumPaquete;
	CQSisProductosPaquete *CQSPPaquete;
	QWidget *QWParent;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraPaquetes();
	void ConsultaPaquetes();
	void ConsultandoPaquetes();
	void keyPressEvent(QKeyEvent *);
	void closeEvent(QCloseEvent *);

private slots:
	void SlotSeleccionaPaquete(int ,int,int,const QPoint &);
	void SlotPaquete(int,int,int,const QPoint &);
	void SlotEliminaPaquete();
	void SlotSeleccionandoPaquetes(int,int,int,const QPoint &);
	void SlotSeleccionandoPaquetes(int,int);
	void SlotProducto(SiscomRegistro3 *);
	void SlotEliminaProductoPaquete();
	void SlotAnexarProducto();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QPaquetesRegistrados *InstanciaPaquetesRegistrados(void *,char **,void *,const char *,int);
#endif
