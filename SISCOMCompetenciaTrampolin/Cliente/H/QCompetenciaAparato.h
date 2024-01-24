#ifndef __QCOMPETENCIAAPARATO_H__
#define __QCOMPETENCIAAPARATO_H__
#include <qwidget.h>

class SiscomDatCom;
class QCtrlAparatoCompetencia;
class QCtrlCompetencias;
class SISCOMVentanaPrincipal;
class QLabel;
class CQSisCompetencia;
class QRondas;
class QCompetenciasAparatos:public QWidget
{
Q_OBJECT
public:
	QCompetenciasAparatos(SiscomDatCom *pSisDatCom,
			char **,
			QWidget *,
			const char *,
			WFlags );
private:
	void IniciaInterfaz();
	void IniciaVariables();
	void ColocaArea();
	void ConectaSlots();
	void MuestraAparatos();
	void AsignaCompetencia();
	void IniciaAparatos();
private:
	char **chrPtrArgumentos;
	QCtrlCompetencias *QCtrCompetencias;
	QCtrlAparatoCompetencia *QCtrACompetencia;
	QLabel *QLCompetencias;
	QLabel *QLAparatos;
	SiscomDatCom *SisDatCom;
	SISCOMVentanaPrincipal *QVPrincipal;
	QWidget *QWParent;
	CQSisCompetencia *CQSCompetencia;
	QRondas *QRCompetencia;
private slots:
	void SlotCompetencia(CQSisCompetencia *);

};
extern "C" QCompetenciasAparatos *InstanciaCompetenciasAparatos(void *,char **,void *,const char *,int);
#endif
