#ifndef __QROTACIONES_H__
#define __QROTACIONES_H__
#include <qwidget.h>
class QToolButton;
class QButtonGroup;
class CQSisCompetencia;
class SiscomDatCom;
class QRotaciones:public QWidget
{
Q_OBJECT
public:
	QRotaciones(SiscomDatCom *pSisDatCom,
		     QWidget *pQWParent=0,
		    const char *pchrPtrName=0);
	void Competencia(CQSisCompetencia *);
private:
	QToolButton *QTBERotacion;
	QToolButton *QTBERotacion1;
	QToolButton *QTBERotacion2;
	SiscomDatCom *SisDatCom;
	CQSisCompetencia *CQSCompetencia;
	const char *chrPtrIdRonda;
	void (QRotaciones::*Operaciones[10])();

private:
	void IniciaInterfaz();
	void IniciaVariables();
	QToolButton *CreaBoton(QButtonGroup *,const char *);
	void EjecutaRotacion();
	void EnConstruccion();
	void ObtenRonda();
	
private slots:
	void SlotSeleccion(int );
};

#endif
