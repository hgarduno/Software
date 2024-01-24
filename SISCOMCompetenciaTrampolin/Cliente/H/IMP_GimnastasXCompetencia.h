#ifndef __IMP_GIMNASTASXCOMPETENCIA_H__
#define __IMP_GIMNASTASXCOMPETENCIA_H__
#include <UIC_H_GimnastasXCompetencia.h>
#include <CQSisCompitiendo.h>
class SiscomDatCom;
class CQSisCompetencia;
class CQSisEntrenador;
class QGimnastasXCompetencia:public GimnastasXCompetencia
{
 Q_OBJECT
public:
	QGimnastasXCompetencia(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QGimnastasXCompetencia();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisLstCompitiendo CQSLCompitiendo;
	CQSisCompitiendo *CQSCompitiendo;
	CQSisCompetencia *CQSCompetencia;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Consulta();
	void MuestraGimnastas();
private slots:
	void SlotCompetencia(CQSisCompetencia *);
	void SlotActualiza(int,int,int,const QPoint &);
	void SlotActDatComGimnasta();
	void SlotActualizaPantalla();
};
extern "C" QGimnastasXCompetencia *InstanciaGimnastasXCompetencia(void *,char **,void *,const char *,int);
#endif
