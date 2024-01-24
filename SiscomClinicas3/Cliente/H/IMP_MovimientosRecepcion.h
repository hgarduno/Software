
#ifndef __IMP_MOVIMIENTOSRECEPCION_H__
#define __IMP_MOVIMIENTOSRECEPCION_H__
#include <UIC_H_MovimientosRecepcion.h>
#include <CQSisConsultas.h>
class SiscomDatCom;
class CQSisPersona;
class QMovimientosRecepcion:public MovimientosRecepcion
{
 Q_OBJECT
public:
	QMovimientosRecepcion(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QMovimientosRecepcion();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisLstConsulta CQSLCRegistradas;
	CQSisPersona *CQSMedico;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultaConsultas(const char *,
			       const char *,
			       const char *,
			       const char *);
	void ConsultasRegistradas();
	void MuestraConsultas();
private slots:
	void SlotConsulta();
	void SlotPorMedico();
	void SlotMedico(CQSisPersona *);
};
extern "C" QMovimientosRecepcion *InstanciaMovimientosRecepcion(void *,char **,void *,const char *,int);
#endif
