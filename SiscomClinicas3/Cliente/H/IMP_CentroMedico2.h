
#ifndef __IMP_CENTROMEDICO2_H__
#define __IMP_CENTROMEDICO2_H__
#include <UIC_H_CentroMedico2.h>
#include <CQSisConsultas.h>
#include <qiconview.h>


class SiscomDatCom;
class SisUsuarioSeg3;
class QCentroMedico;
class QExpedientes;
class QIconViewCnsActual:public QIconViewItem
{
public:
	QIconViewCnsActual(CQSisConsulta *,QWidget *,QIconView *);
	QWidget *ConsultaActual();
private:
	QWidget *QWCnsActual;
	CQSisConsulta *CQSConsulta;
};
class QCentroMedico2:public CentroMedico2
{
 Q_OBJECT
public:
	QCentroMedico2(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QCentroMedico2();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisLstConsulta CQSLConsultasActual;
	CQSisLstConsulta CQSLConsultas;
	SisUsuarioSeg3 *SUSeg3Firmado;
	QWidget *QWParent;
	QWidget *QWCnsActual;
	CQSisPersona *CQSPPaciente;
	QExpedientes *QEExpedientes;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultaActual();
	void ConsultasRegistradas();
	void ConsultaConsultas();
	void MuestraConsultas();
	void MuestraConsultasActivas();
	void EstadisticasMedico();
	void ConsultandoActuales();
	void CargaExpediente();
private slots:
	void SlotConsultaActual(QIconViewItem *);
	void SlotTerminaConsulta(QCentroMedico *);
	void SlotActualiza();
	void SlotExpedientes();
	void SlotCerroExpediente(CQSisPersona *);
};
extern "C" QCentroMedico2 *InstanciaCentroMedico2(void *,char **,void *,const char *,int);
#endif
