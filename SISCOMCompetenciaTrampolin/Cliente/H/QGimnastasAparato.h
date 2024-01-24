#ifndef __QGIMNASTAAPARATOS_H__
#define __QGIMNASTAAPARATOS_H__
#include <qwidget.h>
class CQSisAparatoCompetencia;
class CQSisCompitiendo;
class CQSisLstCompitiendo;
class QTable;
class QHBoxLayout;


class QGimnastasAparato:public QWidget 
{
Q_OBJECT
public:
	QGimnastasAparato(CQSisAparatoCompetencia *,
			  QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  WFlags pWFlags=0);
	CQSisAparatoCompetencia *ObtenAparato();
	CQSisLstCompitiendo *ObtenGimnastas();
	void AnexaGimnastaAparatoRonda(CQSisCompitiendo *);
private:

	QHBoxLayout *QHBLayout;
	QTable *QTDatos;
	CQSisAparatoCompetencia *CQSACompetencia;
	CQSisLstCompitiendo *CQSLCompitiendo;
private:
	void IniciaVariables();
	void IniciaTabla();
	void ConectaSlots();
private slots:
	void SlotGimnasta(int,int,int,const QPoint &);
};
class QGimnastasAparatoLst:public QPtrList<QGimnastasAparato>
{
public:
	QGimnastasAparatoLst();
	QGimnastasAparatoLst &operator<<(QGimnastasAparato *);
	QGimnastasAparato *operator[](CQSisAparatoCompetencia *);
};
#endif

