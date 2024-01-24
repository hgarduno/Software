
#ifndef __IMP_REPORTEEXISTENCIAS_H__
#define __IMP_REPORTEEXISTENCIAS_H__
#include <UIC_H_ReporteExistencias.h>
#include <CQSisProdCotiza.h>
class SiscomDatCom;

class QReporteExistencias:public ReporteExistencias
{
 Q_OBJECT
public:
	QReporteExistencias(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QReporteExistencias();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisLstProdCotiza CQSLPCotiza;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultaTodosLosProductos();
	void ConsultandoTodosLosProductos();
	void MuestraProductos();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotTodos();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QReporteExistencias *InstanciaReporteExistencias(void *,char **,void *,const char *,int);
#endif
