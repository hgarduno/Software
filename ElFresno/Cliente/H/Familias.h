#ifndef __FAMILIAS_H__
#define __FAMILIAS_H__
#include <qptrlist.h>
#include <qstringlist.h>
#include <qobject.h>

class CSISCOMDatComunicaciones;
class CQOGenericaServidorSiscom;
class QWidget;
class QLineEdit;
class QComboBox;
class Familia
{
public:
	Familia(const char *,
		const char *,
		const char *);
	void PonIdFamilia(const char *);
	void PonNmbFamilia(const char *);
	void PonDscFamilia(const char *);
	void PonEdoRegistro(const char *);
	const char *ObtenIdFamilia();
	const char *ObtenNmbFamilia();
	const char *ObtenDscFamilia();
	const char *ObtenEdoRegistro();
	
private:
	const char *chrPtrIdFamilia;
	const char *chrPtrNmbFamilia;
	const char *chrPtrDscFamilia;
	const char *chrPtrEdoRegistro;
	/*  El Estado del registro sera 
	 *      0 Registrar 
	 *	1 Registrado
	 *	2 Modificar 
	 *	3 Eliminar
	 */

};
class CQFamilias:public QPtrList<Familia>
{
public:
	CQFamilias();
};
	
class CQCtrFamilias
{
public:
	enum CtrFamilias
	{
	    Registrar,
	    Consultar
	};
	CQCtrFamilias(CSISCOMDatComunicaciones *,
		      CtrFamilias ,
		      CQFamilias *);
private:
	void RegistraLasFamilias(CQFamilias *);
	void AnalizaRespuesta(CQFamilias *);
	void ConsultaLasFamilias(CQFamilias *);
	void FormaEnvio(CQFamilias *);
private:
	CQOGenericaServidorSiscom *CQOGSvrSiscom;
        CSISCOMDatComunicaciones *CSisDatCom;
        QStringList QSLRegistro;
};

class CQSeleccionaFamilia:public QObject
{
Q_OBJECT 
public:
	CQSeleccionaFamilia(CSISCOMDatComunicaciones *,
			    QWidget *,
			    const char *,
			    QLineEdit *,
			    QLineEdit *,
			    QComboBox *);
	void setFocus();
private:
	QLineEdit *QLEFamilia;
	QLineEdit *QLEDscFamilia;
	QComboBox *QCBFamilia;
	CQFamilias CQ_Familias;
	CSISCOMDatComunicaciones *CSisDatCom;
private:
	void ConectaSlots();
	void LlenaComboFamilias();
private slots:
	void S_SeleccionoFamilia();
	void S_SeleccionoFamilia(int);
signals:
	void Signal_Familia(Familia *);
};
#define __NumParRegFamilias__ 5
#define __ParametrosRegFamilias__ "%s%s%s%s%s"
#endif
