#ifndef __QRESCOMPETENCIA_H__
#define __QRESCOMPETENCIA_H__
#include <qwidget.h>
class QTable;
class QHBoxLayout;
class CQSisLstCompitiendo;

class QResCompetencia:public QWidget
{
Q_OBJECT
public:
	QResCompetencia(CQSisLstCompitiendo *,
			      QWidget *pQWParent=0,
			      const char *pchrPtrName=0,
			      WFlags pWFlags=0);
private:
	QTable *QTDatos;
	QHBoxLayout *QHBLayout;
	CQSisLstCompitiendo *CQSLCompitiendo;
private:
	void IniciaVariables();
	void IniciaTabla();
	void MuestraGimnastas();

};

class QResCompetenciaLst:public QPtrList<QResCompetencia>
{
public:
	QResCompetenciaLst();
	QResCompetenciaLst &operator<<(QResCompetencia *);
};
#endif
