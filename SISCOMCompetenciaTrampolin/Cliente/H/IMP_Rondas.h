
#ifndef __IMP_RONDAS_H__
#define __IMP_RONDAS_H__
#include <UIC_H_Rondas.h>
#include <CQSisCompitiendo.h>
#include <CQSisAparatoCompetencia.h>
#include <QGimnastasAparatos.h>
#include <CQSisRonda.h>
#include <qmainwindow.h>
class SiscomDatCom;
class CQSisCompetencia;
class CQSisEntrenador;
class QGimnastasAparatos;
class CQSisAparatoCompetencia;
class SISCOMVentanaPrincipal;
class QRondas:public Rondas
{
 Q_OBJECT
public:
	QRondas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	QRondas(SiscomDatCom *,
		CQSisCompetencia *,
		QWidget *,
		const char *);
	~QRondas();
	void AparatoCompetencia(CQSisAparatoCompetencia *);
private:
	QWidget *QWParent;
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisCompetencia *CQSCompetencia;
	CQSisLstCompitiendo CQSLCompitiendo;
	CQSisCompitiendo *CQSCompitiendo;
	QGimnastasAparatos *QGmnsAparatos;
	CQSisLstAparatoCompetencia CQSLAparatos;
	CQSisAparatoCompetencia *CQSACompetencia;
	QGimnastasAparatosLst QGmsApRondas;


	CQSisLstRonda CQSLRonda;
	CQSisLstLstRonda CQSLLRonda;
	SISCOMVentanaPrincipal *QVPrincipal;
	int intNoRonda;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraGimnastas();
	void ConsultaGimnastas();
	void GeneraNombre(CQSisEntrenador *,QString &);
	void MuestraAparatos();
	void IniciaRondas();
	void ActivaAparatoRonda();
	void AsignaGimnastaAparatoRonda();
	void MarcaGimnasta(int );

	void ConsultandoRondas();
	void ConsultaRondas();
	void MuestraRondas();
	void MarcaGimnastasAparato();
	void AsignaPaginasRonda();
private slots:
	void SlotCompetencia(CQSisCompetencia *);
	void SlotAparatoCompetencia(CQSisAparatoCompetencia *);
	void SlotGimnastaAparato(int,int,int,const QPoint &);
	void SlotRegistraRondas();
	void SlotARonda();
	void SlotCambiaRonda(QWidget *);
};
extern "C" QRondas *InstanciaRondas(void *,char **,void *,const char *,int);
#endif
