#ifndef __QSISPACIENTES_H__
#define __QSISPACIENTES_H__
#include <SISCOMComunicaciones++.h>
#include <CQSisConsultas.h>
#include <qwidget.h>
#include <qiconview.h>

class CQSisPersona;
class QIconView;
class QHBoxLayout;
class SisUsuarioSeg3;
class SiscomDatCom;
class CQSisConsulta;

class QSisIconViewItemConsulta:public QIconViewItem
{
public:
	QSisIconViewItemConsulta(CQSisConsulta *,QIconView *);
	CQSisConsulta *Consulta();

private:
	CQSisConsulta *CQSConsulta;

};
class QSisPacientes:public QWidget 
{
Q_OBJECT
public:
	QSisPacientes(QWidget *pQWParent=0,
		      const char *pchrPtrName=0);
	void Servidor(SiscomDatCom *);
	void IniciaControl();
	void RangoFechas(const char *,const char *);
	void Medico(CQSisPersona *);
	void AnexaEstadoConsulta(const char *);

private:

	void IniciaVariables();
	void IniciaInterfaz();
	void ConsultandoHospitalizados();
	void MuestraHospitalizados();
	void ConsultaHospitalizados();
	void ConectaSlots();
private:
	QIconView *QIVPacientes;
	QHBoxLayout *QHBLayout;
	CQSisLstConsulta CQSLCRegistradas;
	SisUsuarioSeg3 *SUSeg3Firmado;
	SiscomDatCom *SisDatCom;
	const char *chrPtrFechaIni;
	const char *chrPtrFechaFin;
private slots:
	void SlotConsulta(QIconViewItem *);
signals:
	void SignalConsulta(CQSisConsulta *);
};


#endif
