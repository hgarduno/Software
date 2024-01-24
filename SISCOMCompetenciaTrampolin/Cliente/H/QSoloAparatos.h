#ifndef __QSOLOAPARATOS_H__
#define __QSOLOAPARATOS_H__
#include <qwidget.h>
#include <CQSisAparatoCompetencia.h>
class SiscomDatCom;
class SISCOMVentanaPrincipal;
class QCtrlAparatoCompetencia;
class CQSisCompetencia;
class CQSisAparatoCompetencia;

class QLabel;
class QSoloAparatos:public QWidget
{

Q_OBJECT
public:
	QSoloAparatos(SiscomDatCom *,
		      char **,
		      QWidget *,
		      const char *,
		      WFlags );
	void Aparatos();
	const CQSisLstAparatoCompetencia &AparatosCompetencia();
private:
	void IniciaInterfaz();
	void IniciaVariables();
	void CreaAreaVentana();
	void ConectaSlots();
private:
	QCtrlAparatoCompetencia *QCtrACompetencia;
	QLabel *QLAparatos;
	SISCOMVentanaPrincipal *QSisVentanaP;
	char **chrPtrArgumentos;
	SiscomDatCom *SisDatCom;
	CQSisCompetencia *QSCompetencia;
private slots:
	void SlotAparatoCompetencia(CQSisAparatoCompetencia *);
};

extern "C" QSoloAparatos *InstanciaSoloAparatos(void *,char **,void *,const char *,int );

#endif 
