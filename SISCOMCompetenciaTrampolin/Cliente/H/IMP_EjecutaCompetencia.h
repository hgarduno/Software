
#ifndef __IMP_EJECUTACOMPETENCIA_H__
#define __IMP_EJECUTACOMPETENCIA_H__
#include <UIC_H_EjecutaCompetencia.h>
#include <CQSisRonda.h>
#include <QCalCompetencia.h>
class SiscomDatCom;
class CQSisCompetencia;

class QEjecutaCompetencia:public EjecutaCompetencia
{
 Q_OBJECT
public:
	QEjecutaCompetencia(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QEjecutaCompetencia();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisLstLstRonda CQSLLRonda;
	CQSisCompetencia *CQSCompetencia;
	QCalCompetenciaLst  QCLCompetencia;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultaRondas();
	void MuestraInformacion();
	void EliminaRondas();
private slots:
	void SlotCompetencia(CQSisCompetencia *);
	void SlotActualizoCalificacion(QCalCompetencia *,CQSisLstRonda *);
	void SlotRotacion();
};
extern "C" QEjecutaCompetencia *InstanciaEjecutaCompetencia(void *,char **,void *,const char *,int);
#endif
