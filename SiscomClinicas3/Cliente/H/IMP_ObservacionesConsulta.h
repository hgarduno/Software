
#ifndef __IMP_OBSERVACIONESCONSULTA_H__
#define __IMP_OBSERVACIONESCONSULTA_H__
#include <UIC_H_ObservacionesConsulta.h>
#include <CQSisExpedientes.h>
class SiscomDatCom;
class CQSisConsulta;
class QObservacionesConsulta:public ObservacionesConsulta
{
 Q_OBJECT
public:
	QObservacionesConsulta(
	    CQSisConsulta *,
	    SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=0,
	    WFlags pWFlags=0);
	~QObservacionesConsulta();
	int SiObservaciones();
	static int HayObservaciones(SiscomDatCom *,const char *);
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisConsulta *CQSConsulta;
	CQSisLstExpediente CQSLExpediente;
private:
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
	void Registra();
	void Observaciones();
	void ConsultaObservaciones();
	void MuestraObservaciones();
	void Actualiza();
private slots:
	void SlotRegistra();
	void SlotTerminar();
};
#endif
