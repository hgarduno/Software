#ifndef __IMP_REPORTESVENTAS_H__
#define __IMP_REPORTESVENTAS_H__

#include <UIC_H_ReportesVentas.h>
#include <ReportesVentas.h>
#include <OrdenesHora.h>
#include <PuntosHoras.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTabWidget;
class QPushButton;
class QLCDNumber;
class QTable;
class QGraficaOrdenes;
class SiscomDatCom;
class QCtrMesVenta;
class QControlesGrafica;
class EmpresaN;
class QEventoConsultaReporte;


class QReportesVentas : public ReportesVentas
{
    Q_OBJECT
public:
    QReportesVentas(SiscomDatCom *,
    		     char **,
		     QWidget* parent = 0,
		     const char* name = 0,
		     WFlags fl = 0 );
    ~QReportesVentas();

    void AsignaRangoFechas(const char *pchrPtrFechaIni,
    			   const char *pchrPtrFechaFin);
    void AsignaExpendio(EmpresaN *pEExpendio);
    void CorreReporte();
    void CorreReporte(const char *pchrPtrFechaInicio,const char *pchrPtrFechaFin);
	void customEvent(QCustomEvent *);
private:
	void ConectaSlots();
	void EjecutaReporteVentasPorDia(const char *,const char *);
	void MuestraDetalleVentas(RegistrosRepVenta );
	void MuestraVentaPorDia(RegistrosRepVenta );
	void MuestraOrdenesPorDia(RegistrosRepVenta );
	void MuestraOrdenesEscuela(RegistrosRepVenta &);
	void MuestraTotalOrdenesEscuela(RegistrosRepVenta &);
	void IniciaVariables();
	void AnexaGrafica();
	void AnexaVentasHoraMes();

	void ConsultaVentasPorSemana();
	void closeEvent(QCloseEvent *);

	const char *ObtenIdExpendio();
	void MuestraEncabezado();

private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	char chrArrFechaIni[30];
	char chrArrFechaFin[30];
	OrdenesHora OHora;
	QGraficaOrdenes *QGOrdenes;
	QCtrMesVenta *QCMesVenta;
	QControlesGrafica *QCtrGrafica;
	QPushButton *QPBFechas;

	CSisDatosSemanas CSDtsSemanas;
	EmpresaN *EExpendio;
private slots:
	void S_CapturaFechaReporte();
	void S_Refrescar();
	void S_CapturaFecha();
	void S_CambioTab(QWidget *);
	void S_ReporteImportesPorSemana();
	/* Santiago De Queretaro Lunes 25 de Noviembre del 2013 
	 * A esta fecha ya se tienen varios expendios, por lo que
	 * es necesario estar monitoreando las ventas, de cada tienda
	 * se agrega la seleccion del expendio para no tener que abrir 
	 * un sistema apuntando al expendio del que se quiere saber la 
	 * venta
	 */
	void S_SeleccionaExpendio();
signals:
	void SignalTerminar(QWidget *);
};

extern "C" QReportesVentas *InstanciaReportesVentas(void *,
						    char **,
						    void *,
						    const char *,
						    int );
#endif 
