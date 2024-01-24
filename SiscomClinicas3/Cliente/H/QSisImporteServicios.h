#ifndef __QSISIMPORTESERVICIOS_H__
#define __QSISIMPORTESERVICIOS_H__
#include <SISCOMComunicaciones++.h>
#include <CQSisCotizando.h>
class QSisImporteServicios:public QWidget 
{
Q_OBJECT
public:
	QSisImporteServicios(QWidget *pQWParent=0,
			     const char *pchrPtrName=0,
			     WFlags pWFlags=0);
	void Servidor(SiscomDatCom *);
	void IdMedico(const char *);
	void IniciaControl();
	void RangoFechas(const char *,const char *);
private:
	QLabel *QLDetServicios;
	QLabel *QLImporte;
	QTable *QTDatos;
	QLCDNumber *QLCDNTotal;
	SiscomDatCom *SisDatCom;
	const char *chrPtrIdMedico;
	const char *chrPtrFechaIni;
	const char *chrPtrFechaFin;
	CQSisLstCotizando CQSLCotizando;
private:
	void IniciaInterfaz();	
	void ConsultaVentasMedico();
	void ConsultandoVentasMedico();
	void MuestraVentasMedico();
};
#endif
