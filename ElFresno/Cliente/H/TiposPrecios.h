#ifndef __TIPOSPRECIOS_H__
#define __TIPOSPRECIOS_H__
#include <qobject.h>
#include <qptrlist.h>
#include <qstringlist.h>
class CSISCOMDatComunicaciones;
class CQOGenericaServidorSiscom;
class QLineEdit;
class QComboBox;

class TipoPrecio
{
public:
	TipoPrecio(const char *,const char *,const char *);
	void PonNmbTipoPrecio(const char *);
	void PonDescripcion(const char *);
	void PonEdoRegistro(const char *);
	void PonTipo(const char *);
	
	const char *ObtenNmbTipoPrecio();
	const char *ObtenDescripcion();
	const char *ObtenEdoRegistro();
	const char *ObtenTipo();
	
private:
	const char *chrPtrNmbTipoPrecio;
	const char *chrPtrDescripcion;
	const char *chrPtrEdoRegistro;
	const char *chrPtrTipo;
	 /*  El Estado del registro sera 
	  *      0 Registrar 
	  *      1 Registrado
	  *      2 Modificar 
	  *      3 Eliminar
	  */
};
class CQTiposPrecios:public QPtrList<TipoPrecio>
{
public:
	CQTiposPrecios();

};

class CQCtrTiposPrecios
{
public:
	enum CtrTiposPrecios
	{
	    Consultar,
	    Registrar
	};
	CQCtrTiposPrecios(CSISCOMDatComunicaciones *,CtrTiposPrecios ,CQTiposPrecios *);
private:
	CQOGenericaServidorSiscom *CQOGSvrSiscom;
        CSISCOMDatComunicaciones *CSisDatCom;
        QStringList QSLRegistro;
	int intNumParametrosReg;
	const char *chrPtrParametrosRegistro;
private:
	void ConsultaLosTiposPrecios(CQTiposPrecios *);
	void RegistrarLosTiposPrecios(CQTiposPrecios *);
	void FormaRespuesta(CQTiposPrecios *);
};
class CQSeleccionaTipoPrecio:public QObject
{
Q_OBJECT
	public:	
		CQSeleccionaTipoPrecio(CSISCOMDatComunicaciones *,
				       QWidget *,
				       const char *,
				       QLineEdit *,
				       QLineEdit *,
				       QComboBox *);
private:
	QLineEdit *QLECNmbTipoPrecio;
	QLineEdit *QLEDescripcion;
	QComboBox *QCBNmbTipoPrecio;
	CQTiposPrecios CQTPrecios;
	CSISCOMDatComunicaciones *CSisDatCom;
private:
	void ConectaSlots();
	void LlenaComboNmbTipoPrecios();	
private slots:
	void S_SeleccionandoTipoPrecio(int);
	void S_SeleccionoTipoPrecio(int);
	void S_SeleccionoTipoPrecio();
signals:
	void Signal_STipoPrecio(TipoPrecio *);

};
#endif
