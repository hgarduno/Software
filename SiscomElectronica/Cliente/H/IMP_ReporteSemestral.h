
#ifndef __IMP_REPORTESEMESTRAL_H__
#define __IMP_REPORTESEMESTRAL_H__
#include <UIC_H_ReporteSemestral.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class QImprimeReporteSemestral;
class QReporteSemestral:public ReporteSemestral
{
 Q_OBJECT
public:
	QReporteSemestral(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QReporteSemestral();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3Lst SisReg3LstRSemestral;
	QWidget *QWParent;
	QImprimeReporteSemestral *QImpRepSemestral;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultandoReporte();
	void ConsultaReporte();
	void MuestraReporte();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotReporteSemestral();
	void SlotImprime();
	void SlotPasaFocoFechaFin();
	void SlotPasaFocoEjecutaReporte();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QReporteSemestral *InstanciaReporteSemestral(void *,char **,void *,const char *,int);
#endif
