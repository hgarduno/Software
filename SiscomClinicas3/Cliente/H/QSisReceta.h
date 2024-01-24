#ifndef __QSISRECETA_H__
#define __QSISRECETA_H__
#include <SISCOMComunicaciones++.h>
class QGridLayout;
class QLineEdit;
class QTextEdit;
class QLabel;

class CQSisConsulta;
class CQSisReceta;

class QSisReceta:public QWidget
{
Q_OBJECT
public:
	QSisReceta(QWidget *pQWParent=0,
		   const char *pchrPtrName=0,
		   WFlags pWFlags=0);
	QSisReceta(CQSisReceta *,
		   QWidget *pQWParent=0,
		   const char *pchrPtrName=0,
		   WFlags pWFlags=0);
	void Consulta(CQSisConsulta *);
	void Servidor(SiscomDatCom *);
	void IdWidgetReceta(int );
private:
	void IniciaVariables();
	void ConectaSlots();
	CQSisReceta *Receta();
	void Registra();
	void MuestraReceta();
	void Actualiza();
private:
	QGridLayout *QGLRegilla;
	QSisHEspacio *QSHEFolio;
	QSisHEspacio *QSHEReceta;
	QSisHEspacio *QSHEBotones;

	SiscomDatCom *SisDatCom;
	CQSisConsulta *CQSConsulta;

	QLineEdit *QLEFolio;
	QTextEdit *QTEReceta;
	QLabel *QLFolio;
	QLabel *QLReceta;
	QPushButton *QPBRegistrar;
	QPushButton *QPBActualizar;
	int intIdWidgetReceta;
	CQSisReceta *CQSReceta;
private slots:
	void SlotCambiaFolio(const QString &);
	void SlotPasaFocoReceta();
	void SlotRegistra();
	void SlotActualiza();
signals:
	void SignalCambiaFolio(const QString &,int);
	void SignalRegistroReceta(QSisReceta *);

};

#endif
