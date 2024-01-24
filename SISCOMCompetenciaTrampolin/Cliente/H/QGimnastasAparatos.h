#ifndef __QGIMNASTASAPARATOS_H__
#define __QGIMNASTASAPARATOS_H__
#include <QGimnastasAparato.h>
#include <CQSisRonda.h>
#include <qwidget.h>
class CQSisLstAparatoCompetencia;
class CQSisAparatoCompetencia;
class CQSisCompitiendo;
class QHBoxLayout;
class QTabWidget;
class QGimnastasAparatos:public QWidget
{
Q_OBJECT
public:
	QGimnastasAparatos(CQSisLstAparatoCompetencia *,
			   const char *,
			   const char *,
			   const char *,
			   QWidget *pQWParent=0,
			   const char *pchrPtrName=0,
			   WFlags pWFlags=0);
	void ActivaAparato(CQSisAparatoCompetencia *);
	void AsignaGimnastaAparato(CQSisAparatoCompetencia *,CQSisCompitiendo *);
	const CQSisLstRonda &ObtenGimnastasPorAparato();
private:
	CQSisLstAparatoCompetencia *CQSLACompetencia;
	QHBoxLayout *QHBLayout;
	QTabWidget *QTWApGimnastas;
	QGimnastasAparatoLst QGmnsAparatoLst;
	CQSisLstRonda CQSLRonda;
	const char *chrPtrIdRonda;
	const char *chrPtrNmbRonda;
	const char *chrPtrIdCompetencia;
private:
	void IniciaVariables();
	void IniciaAparatos();

};
class QGimnastasAparatosLst:public QPtrList<QGimnastasAparatos>
{
public:
	QGimnastasAparatosLst();
	QGimnastasAparatosLst &operator<<(QGimnastasAparatos *);
};
#endif
