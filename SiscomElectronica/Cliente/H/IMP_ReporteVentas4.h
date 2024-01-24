
#ifndef __IMP_REPORTEVENTAS4_H__
#define __IMP_REPORTEVENTAS4_H__
#include <UIC_H_ReporteVentas4.h>
#include <zReporteVentas.h>
class SiscomDatCom;
class EmpresaN;
class zSiscomConexion;
class QTable;
class zSiscomRegistros;
class QReporteVentas4:public ReporteVentas4
{
 Q_OBJECT
public:
	QReporteVentas4(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QReporteVentas4();
private:
	SiscomDatCom *SisDatCom;
	zSiscomConexion *zSisConexion;
	char **chrPtrArgumentos;
	EmpresaN *EExpendio;
	zReporteVentas zRepVentas;	
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraEncabezado();
	const char *ObtenIdExpendio();
	int Consulta(char *pchrPtrDesEstadoReporte);
	void Muestra();
	void MuestraTotales();
	void MuestraReportePorEscuela();
	void MuestraOrdenesPorEscuela();
	void MuestraVentasTotales();
	void MuestraMaterialEscuela();
	void MuestraOrdenesPorTipo(QTable *pQTDatos,
				   const char *pchrPtrCampos[],
				   zSiscomRegistros *pzSisRegDatos);
	void Consultando();

	void ACeroTablas();
private slots:
	void SlotFocoAFechaFin();
	void SlotFocoAExpendio();
	void SlotSeleccionaExpendio();
	void SlotConsultar();
};
extern "C" QReporteVentas4 *InstanciaReporteVentas4(void *,char **,void *,const char *,int);
#endif
