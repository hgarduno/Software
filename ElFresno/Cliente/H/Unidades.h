#ifndef __UNIDADES_H__
#define __UNIDADES_H__
#include <qptrlist.h>
#include <qstringlist.h>
#include <qobject.h>
class CSISCOMDatComunicaciones;
class CQOGenericaServidorSiscom;
class QLineEdit;
class QComboBox;
class Unidad
{
public:
	Unidad(const char *,
		const char *,
		const char *);
	void PonUnidad(const char *);
	void PonNmbUnidad(const char *);
	void PonAbreviatura(const char *);
	void PonEdoRegistro(const char *);

	const char *ObtenUnidad();
	const char *ObtenNmbUnidad();
	const char *ObtenAbreviatura();
	const char *ObtenEdoRegistro();
private:
	const char *chrPtrUnidad;
	const char *chrPtrNmbUnidad;
	const char *chrPtrAbreviatura;
	const char *chrPtrEdoRegistro;
	/*  El Estado del registro sera
         *      0 Registrar 
         *      1 Registrado
         *      2 Modificar 
         *      3 Eliminar
         */		

};
class CQUnidades:public QPtrList<Unidad>
{
public:
	CQUnidades();
};

class CQCtrUnidades
{
public:
	enum CtrUnidades
	{
	    Registrar,
	    Consultar
	};
	CQCtrUnidades(CSISCOMDatComunicaciones *,
		      CtrUnidades ,
		      CQUnidades *);
private:
	void RegistraLasUnidades(CQUnidades *);
	void FormaEnvio(CQUnidades *);
	void ConsultaUnidades(CQUnidades *);
	void AnalizaRespuesta(CQUnidades *);
private:
        CQOGenericaServidorSiscom *CQOGSvrSiscom;
        CSISCOMDatComunicaciones *CSisDatCom;
        QStringList QSLRegistro;
	int intNumParametros;
	const char *chrPtrFormato;

	

};
class CQSeleccionaUnidades:public QObject
{
Q_OBJECT
public:
	CQSeleccionaUnidades(CSISCOMDatComunicaciones *,
			     QWidget *,
			     const char *,
			     QLineEdit *,
			     QLineEdit *,
			     QComboBox *);
private:
	QLineEdit *QLEAbreviatura;
	QComboBox *QCBUnidades;
	QLineEdit *QLECUnidades;
	CQUnidades CQ_Unidades;
	CSISCOMDatComunicaciones *CSisDatCom;
private:
	void ConectaSlots();
	void LlenaComboUnidades();
private slots:
	void S_Unidad();
	void S_Unidad(int);
	void S_SeleccionandoUnidad(int );
signals:
	void Signal_SUnidad(Unidad *);
	
	

};
#endif
