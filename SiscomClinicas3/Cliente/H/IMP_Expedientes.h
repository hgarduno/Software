
#ifndef __IMP_EXPEDIENTES_H__
#define __IMP_EXPEDIENTES_H__
#include <UIC_H_Expedientes.h>
#include <CQSisExpedientes.h>
class QSisExpediente;
class CQSisPersona;
class SiscomDatCom;
class QRecetas;

class QExpedientes:public Expedientes
{
 Q_OBJECT
public:
	QExpedientes(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QExpedientes();
	void Paciente(CQSisPersona *);
	void Expediente();

private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisPersona *CQSPaciente;
	CQSisLstExpediente CQSLExpediente;
	QRecetas *QRRecetas;
	QWidget *QWParent;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraPaciente();
	void ConsultaExpediente();
	void ConsultandoExpediente();
	void MuestraExpediente();
	QSisExpediente *WidgetExpediente(CQSisExpediente *);
	void closeEvent(QCloseEvent *);
private slots:
	void SlotHistorialRecetas();
signals:
	void SignalCerroExpediente(CQSisPersona *);
};
#endif
