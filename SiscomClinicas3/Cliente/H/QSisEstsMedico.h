#ifndef __QSISESTSMEDICO_H__
#define __QSISESTSMEDICO_H__
#include <SISCOMComunicaciones++.h>
class QTabWidget;
class QSisImporteServicios;
class QSisResultadosGen;
class QSisEstsMedico:public QWidget 
{
Q_OBJECT
public:
	QSisEstsMedico(QWidget *pQWParent=0,
		       const char *pchrPtrName=0,
		       WFlags pWFlgas=0);
	void IdMedico(const char *);
	void Servidor(SiscomDatCom *);
	void IniciaControl();
	void RangoFechas(const char *,const char *);
private:

	QTabWidget *QTWDatos;
	QSisImporteServicios *QSIServicios;
	QSisResultadosGen *QSRGenerales;
	QPushButton *QPBActualiza;
private:
	void IniciaInterfaz();
};


#endif
