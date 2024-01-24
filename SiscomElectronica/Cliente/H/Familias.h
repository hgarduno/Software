#ifndef __FAMILIAS_H__
#define __FAMILIAS_H__
#include <SISCOMComunicaciones++.h>
#include <qptrlist.h>
#include <qwidget.h>

class QLineEdit;
class QComboBox;
class Familia:public SiscomInformacion
{
public:
	Familia(const char *,
		const char *,
		const char *,
		const char *pchrPtrEdoRegistro="");
private:
	void IniciaRegistro();

};

class Familias:public QPtrList<Familia>
{

	public:
		Familias();
	        Familias &operator<<(Familia *);
};

class OpFamilias
{
public:
	OpFamilias(SiscomDatCom *);
	void ConsultaFamilias(Familias &);
	void RegistraFamilias(Familias &);

private:
	SiscomDatCom *SisDatCom;
private:
	void GeneraFamilias(const SiscomComunicaSrv*,Familias &);
};

class ManFamilias:public QWidget
{
Q_OBJECT
public:
	ManFamilias(SiscomDatCom *,
		    QComboBox *,
		    QLineEdit *,
		    QLineEdit *,
		    QWidget *,
		    const char *);
	Familia *ObtenFamilia(int);
private:
	SiscomDatCom *SisDatCom;
	QComboBox *QCBFamilias;
	QLineEdit *QLECFamilias;
	QLineEdit *QLEDscFamilia;
	Familias FFamilias;
private:
	void ConsultaFamilias();
	void ConectaSlots();
signals:
	void SignalFamilia(Familia *);
private slots:
	void S_SeleccionandoFamilia(int);
	void S_SeleccionoFamilia();
};
#endif 
