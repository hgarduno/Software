#ifndef __UNIDADES_H__
#define __UNIDADES_H__
#include <SISCOMComunicaciones++.h>
#include <qptrlist.h>
#include <qwidget.h>

class QLineEdit;
class QComboBox;
class Unidad:public SiscomInformacion
{
public:
	Unidad(const char *,
		const char *,
		const char *);
private:
	void IniciaRegistro();

};

class Unidades:public QPtrList<Unidad>
{

	public:
		Unidades();
	        Unidades &operator<<(Unidad *);
};

class OpUnidades
{
public:
	OpUnidades(SiscomDatCom *);
	void ConsultaUnidades(Unidades &);

private:
	SiscomDatCom *SisDatCom;
private:
	void GeneraUnidades(const SiscomComunicaSrv*,Unidades &);
};

class ManUnidades:public QWidget
{
Q_OBJECT
public:
	ManUnidades(SiscomDatCom *,
		    QComboBox *,
		    QLineEdit *,
		    QLineEdit *,
		    QLineEdit *,
		    QWidget *,
		    const char *);
	Unidad *ObtenUnidad(int);
private:
	SiscomDatCom *SisDatCom;
	QComboBox *QCBUnidades;
	QLineEdit *QLECUnidades;
	QLineEdit *QLEDscUnidad;
	QLineEdit *QLEAbreviatura;
	Unidades FUnidades;
private:
	void ConsultaUnidades();
	void ConectaSlots();
signals:
	void SignalUnidad(Unidad *);
private slots:
	void S_SeleccionandoUnidad(int);
	void S_SeleccionoUnidad();
};
#endif 
