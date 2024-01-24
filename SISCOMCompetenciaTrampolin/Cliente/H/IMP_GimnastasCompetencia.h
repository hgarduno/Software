
#ifndef __IMP_GIMNASTASCOMPETENCIA_H__
#define __IMP_GIMNASTASCOMPETENCIA_H__
#include <UIC_H_GimnastasCompetencia.h>
#include <CQSisCompitiendo.h>
#include <CQSisCGimnastas.h>
#include <QCalCompetencia.h>

#include <qiconview.h>
class SiscomDatCom;
class CQSisCompetencia;
class CQSisAparatoCompetencia;

class QIconViewItemGrupo:public QIconViewItem
{
public:
	QIconViewItemGrupo(QWidget *,QString,QIconView *);
	QWidget *ObtenGrupo();
private:
	QWidget *QWGrupo;
};
class QGimnastasCompetencia:public GimnastasCompetencia
{
 Q_OBJECT
public:
	QGimnastasCompetencia(SiscomDatCom *,
	    void *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QGimnastasCompetencia();
private:
	SiscomDatCom *SisDatCom;
	void *chrPtrArgumentos;
	CQSisCompetencia *CQSCompetencia;
	CQSisLstLstCompitiendo CQSLLCompitiendo;
	QCalCompetenciaLst QCCompetenciaLst;
	CQSisAparatoCompetencia *CQSACompetencia;
private:
	void ConectaSlots();
	void IniciaVariables();
	void LimpiaControles();
	void LimpiaTabWidget();

	void ConsultandoGimnastasPorClase();
	void ConsultaGimnastasPorClase();
	void ConsultaAparatosCompetencia();
	void MuestraGimnastasPorClase();


private slots:
	void SlotCompetencia(CQSisCompetencia *);
	void SlotActualizoCalificacion();
	void SlotGrupo(QIconViewItem *);
	void SlotAparatoCompetencia(CQSisAparatoCompetencia *);
};
extern "C" QGimnastasCompetencia *InstanciaGimnastasCompetencia(void *,void *,void *,const char *,int);
#endif
