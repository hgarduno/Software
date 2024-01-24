#ifndef __VEHICULOS_H__
#define __VEHICULOS_H__
#include <qptrlist.h>
#include <qstringlist.h>
#include <qobject.h>
class QLineEdit;
class QComboBox;
class CSISCOMDatComunicaciones;
class CQOGenericaServidorSiscom;
class Vehiculo
{
public:
	Vehiculo(const char *,const char *,const char *);
	void PonIdVehiculo(const char *);
	void PonPlacas(const char *);
	void PonDescripcion(const char *);
	void PonEdoRegistro(const char *);
	const char *ObtenIdVehiculo();
	const char *ObtenPlacas();
	const char *ObtenDescripcion();
	const char *ObtenEdoRegistro();
private:
	const char *chrPtrIdVehiculo;
	const char *chrPtrPlacas;
	const char *chrPtrDescripcion;
	const char *chrPtrEdoRegistro;
};
class CQVehiculos:public QPtrList<Vehiculo>
{
public:
	CQVehiculos();


};
class CQCtrVehiculos
{
public:
	enum CtrVehiculos
	{
		Registrar,
		ConsultarVehiculos
	};
	CQCtrVehiculos(CSISCOMDatComunicaciones *,
		       CtrVehiculos ,
		       CQVehiculos *);
	CQCtrVehiculos(CSISCOMDatComunicaciones *,
			QStringList ,
			CtrVehiculos ,
			CQVehiculos *);
		       

private:
	CQOGenericaServidorSiscom *CQOGSvrSiscom;
        CSISCOMDatComunicaciones *CSisDatCom;
        QStringList QSLRegistro;
	const char *chrPtrParametrosRegistro;
	int intNumParametrosRegistro;
private:
	void RegistraLosVehiculos(CQVehiculos *);
	void ConsultaLosVehiculos(QStringList ,CQVehiculos *);
	void AsignaRespuesta(CQVehiculos *);
};

class CQSeleccionaVehiculo:public QObject
{
Q_OBJECT
	public:
		CQSeleccionaVehiculo(CSISCOMDatComunicaciones *,
				     QWidget *,
				     const char *,
				     QLineEdit *,
				     QLineEdit *,
				     QComboBox *);
private:
	void ConectaSlots();
	void LlenaComboVehiculos();
	
private:
	QLineEdit *QLEDescripcion;
	QLineEdit *QLECPlacas;
	QComboBox *QCBPlacas;
	CSISCOMDatComunicaciones *CSisDatCom;
	CQVehiculos CQVVehiculos;
signals:
	void Signal_Vehiculo(Vehiculo *);
private slots:
	void S_MuestraVehiculo(int);
	void S_SeleccionoVehiculo(int );
	void S_SeleccionoVehiculo();
	
};
#endif
