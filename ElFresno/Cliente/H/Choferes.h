#ifndef __CHOFERES_H__
#define __CHOFERES_H__
#include <qptrlist.h>
#include <qstringlist.h>
#include <qobject.h>
class CSISCOMDatComunicaciones;
class CQOGenericaServidorSiscom;
class QWidget;
class QLineEdit;
class QComboBox;

class CQ_Persona;
class Chofer
{
public:
	Chofer(CQ_Persona * );
	CQ_Persona *ObtenChofer();

private:
	CQ_Persona *CQPChofer;
};

class CQChoferes:public QPtrList<Chofer>
{
public:
	CQChoferes();

};

class CQCtrChoferes
{
public:
	CQCtrChoferes(CSISCOMDatComunicaciones *,
		      QStringList ,
		      CQChoferes *);

private:
	CQOGenericaServidorSiscom *CQOGSvrSiscom;
        CSISCOMDatComunicaciones *CSisDatCom;
        QStringList QSLRegistro;
	const char *chrPtrOperacionesChoferes;
	int intNumArgumentosEnvio;
private:
	void EjecutaOperacion(QStringList ,CQChoferes *);
	void AnalizaRespuesta(CQChoferes *);
	void AnexaParametrosOperacion(QStringList );
	void AnexaChoferes(CQChoferes *);
	void AnexaRegistroVacio();
};

class CQSeleccionaChoferes:public QObject
{
Q_OBJECT
	public:
		CQSeleccionaChoferes(const char *,
				     CSISCOMDatComunicaciones *,
				     QWidget *,
				     const char *,
				     QLineEdit *,
				     QLineEdit *,
				     QComboBox *);

private:
	CSISCOMDatComunicaciones *CSisDatCom;
	QLineEdit *QLECChoferes;
	QLineEdit *QLENmbCompleto;
	QComboBox *QCBNmbChofer;
	const char *chrPtrIdChoferes;
	CQChoferes CQCChoferes;
	
private:
	void LlenaComboChoferes();
	void ConectaSlots();
signals:
	void Signal_Chofer(Chofer *);	
private slots:
	void S_Chofer(int);
	void S_Chofer();
	void S_SeleccionandoChofer(int);
};
#endif
