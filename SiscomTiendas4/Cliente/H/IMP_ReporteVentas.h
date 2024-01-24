#ifndef __IMP_REPORTEVENTAS_H__
#define __IMP_REPORTEVENTAS_H__
#include <UIC_H_ReporteVentas.h>
#include <CQSisReportes.h>
#include <CQSisProdCotiza.h>
class SiscomDatCom;
class QReporteVentas:public ReporteVentas
{
 Q_OBJECT
public:
	QReporteVentas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QReporteVentas();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisLstRepVenta CQSLRVenta;
	CQSisLstProdCotiza CQSLPCotiza;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultandoReporteVentas();
	void ConsultaReporteVentas();
	void MuestraReporteVentas();

	void ConsultandoDetalleVentas();
	void ConsultaDetalleVentas();
	void MuestraDetalleVentas();

	void closeEvent(QCloseEvent *);
private slots:
	void SlotEjecuta();
	void SlotPasaFocoFechaFin();
	void SlotPasaFocoEjecuta();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QReporteVentas *InstanciaReporteVentas(void *,char **,void *,const char *,int);
#endif
