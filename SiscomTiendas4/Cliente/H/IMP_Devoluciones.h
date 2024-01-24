
#ifndef __IMP_DEVOLUCIONES_H__
#define __IMP_DEVOLUCIONES_H__
#include <UIC_H_Devoluciones.h>
#include <CQSisProdCotiza.h>
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
	CQSisLstProdCotiza CQSLPCotiza;
	CQSisLstProdCotiza CQSLPCDevolver;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultandoOrden();
	void ConsultaOrden();
	void MuestraOrden();
	void MuestraDscProducto(int);
	void Devuelve();
	void Anexar();
	void TotalADevolver();
	void Eliminar();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotConsultaOrden();
	void SlotCambiaProducto(int,int);
	void SlotDevuelve();
	void SlotAnexar();
	void SlotEliminar();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QDevoluciones *InstanciaDevoluciones(void *,char **,void *,const char *,int);
#endif
