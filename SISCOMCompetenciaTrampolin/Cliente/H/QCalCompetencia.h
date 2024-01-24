#ifndef __QCALCOMPETENCIA_H__
#define __QCALCOMPETENCIA_H__
#include <qwidget.h>
class QTable;
class QHBoxLayout;
class CQSisLstCompitiendo;
class CQSisCompitiendo;
class CQSisAparato;
class SiscomDatCom;
class QCalCompetencia:public QWidget
{
Q_OBJECT 
public:
	QCalCompetencia(CQSisLstCompitiendo *,
			CQSisAparato *,
			SiscomDatCom *,
			QWidget *pQWParent=0,
			const char *pchrPtrName=0,
			WFlags pWFlags=0);
	void ActualizaInformacion(CQSisLstCompitiendo *);
	CQSisAparato *Aparato();
private:
	QTable *QTDatos;
	QHBoxLayout *QHBLayout;
	CQSisLstCompitiendo *CQSLCompitiendo;
	void (QCalCompetencia::*Jueces[10])(CQSisCompitiendo *);
	SiscomDatCom *SisDatCom;
	CQSisAparato *CQSAparato;
private:
	void IniciaVariables();
	void IniciaTabla();
	void MuestraGimnastas();
	void ConectaSlots();


	void OpcionInvalida(CQSisCompitiendo *);
	void Ejecucion(CQSisCompitiendo *);
	void Dificultad(CQSisCompitiendo *);
	void NotaFinal(CQSisCompitiendo *);

private slots:
	void SlotCalificaGimnasta(int,int,int,const QPoint &);
signals:
	/*
	void SignalActualizoCalificacion();

	*/
	void SignalActualizoCalificacion(QCalCompetencia *);
};
class QCalCompetenciaLst:public QPtrList<QCalCompetencia>
{
public:
	QCalCompetenciaLst();
	QCalCompetenciaLst &operator<<(QCalCompetencia *);

};
#endif
