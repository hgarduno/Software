
#ifndef __IMP_CONTROLADORREPORTESVENTASEXPENDIOS_H__
#define __IMP_CONTROLADORREPORTESVENTASEXPENDIOS_H__
#include <UIC_H_ControladorReportesVentasExpendios.h>
#include <EmpresasN.h>

#include <qthread.h>
#include <qevent.h>
#include <qobjectlist.h>
class SiscomDatCom;
class QControladorReportesVentasExpendios:public ControladorReportesVentasExpendios
{
 Q_OBJECT
public:
	QControladorReportesVentasExpendios(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QControladorReportesVentasExpendios();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	QWidget *QWParent;
	QObjectList QOLPtrRepExpendios;
	EmpresasN EExpendios;
	EmpresasN EExpendiosAMuestrear;
private:
	void ConectaSlots();
	void IniciaVariables();
	void BuscaVentaReportes();
	void ConsultandoExpendios();
	void ConsultaExpendios();
	void MuestraExpendios();
	void ObtenExpendiosAMuestrear();
	void CargaReportesVentas();
	void CargaReporteVentas(EmpresaN *);
private slots:
	void SlotIniciaMuestreo();
};
extern "C" QControladorReportesVentasExpendios *InstanciaControladorReportesVentasExpendios(void *,char **,void *,const char *,int);



class QEventoConsultaReporte:public QCustomEvent
{
public:
	QEventoConsultaReporte();
};
class QEventoActualizaFechaReporte:public QCustomEvent
{
public:
	QEventoActualizaFechaReporte(const char *pchrPtrFechaIni,
				     const char *pchrPtrFechaFin);
	void Fechas(char *pchrPtrFechaIni,char *pchrPtrFechaFin);
private:
	char chrArrFechaIni[20];
	char chrArrFechaFin[20];
};


class QLanzaReConsultaReporte:public QThread
{
public:
	QLanzaReConsultaReporte(int pintPeriodo,const QObjectList &pQOLExpendios);
	void run();
private:
	bool bDeten;
	QObjectList QOLExpendios;
	int intPeriodo;
private:
	void EnviaEventoReConsulta();
	void CambioElDia(int,int,int);
};

#endif
