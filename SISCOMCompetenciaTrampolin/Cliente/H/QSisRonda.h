#ifndef __QSISRONDA_H__
#define __QSISRONDA_H__
#include <qwidget.h>
class CQSisLstRonda;
class QTabWidget;
class SiscomDatCom;
class QCalCompetencia;
class CQSisLstCompitiendo;
class QSisRonda:public QWidget
{
Q_OBJECT
public:
	QSisRonda(CQSisLstRonda *,
		  SiscomDatCom *,
		  char **pchrPtrArgumentos,
		  QWidget *pQWParent=0,
		  const char *pchrPtrName=0);
private:
	CQSisLstRonda *CQSLRonda;
	QTabWidget *QTWAparatos;
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
	void IniciaInterfaz();
	void MuestraAparatosCompetencia();
private slots:
	void SlotActualizoCalificacion(QCalCompetencia *);
signals:
	void SignalActualizoCalificacion(QCalCompetencia *,CQSisLstRonda *);
};

#endif

