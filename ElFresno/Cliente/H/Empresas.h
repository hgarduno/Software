#ifndef __EMPRESAS_H__
#define __EMPRESAS_H__
#include <qptrlist.h>
#include <qstringlist.h>
#include <qobject.h>
#include <Personas.h>
#include <Direcciones.h>
#include <Telefonos.h>
class CQ_Persona;
class CQ_Direccion;
class CQ_Telefono;
class CQ_Personas;
class CQ_Direcciones;
class CQ_Telefonos;
class CSISCOMDatComunicaciones;
class CQOGenericaServidorSiscom;
class QComboBox;

class CQEmpresas;
class Empresa;
class Empresa
{

	public:	
		Empresa();
		Empresa(const char *,
		        const char *,
		        const char *,
			const char *);
		const char *ObtenIdEmpresa();	
		const char *ObtenRFC();
		const char *ObtenRazonSocial();
		const char *ObtenEsExpendio();
		void AnexarDireccion(CQ_Direccion *);
		void AnexarContacto(CQ_Persona *);
		void AnexarTelefono(CQ_Telefono *);
	
		const CQ_Personas &ObtenContactos();
		const CQ_Direcciones &ObtenDirecciones();
		const CQ_Telefonos &ObtenTelefonos();
		
private:
		const char *chrPtrIdEmpresa;
		const char *chrPtrRFC;
		const char *chrPtrRazonSocial;
		const char *chrPtrEsExpendio;
		CQ_Personas CQPContactos;
		CQ_Direcciones CQDirecciones;
		CQ_Telefonos CQTelefonos;
};

class CQEmpresas:public QPtrList<Empresa>
{

public:
	CQEmpresas();

};
class CQCtrEmpresas
{
public:
		CQCtrEmpresas(CSISCOMDatComunicaciones *,
			      QStringList ,
			      CQEmpresas *);
private:
		
	CQOGenericaServidorSiscom *CQOGSvrSiscom;
        CSISCOMDatComunicaciones *CSisDatCom;
        QStringList QSLRegistro;
	SISCOMRegistroEnvio SISCOMRegEnvio;
private:
	void IniciaRegistroEnvio();
	void IniciaComunicacion();
	void EnviaParametrosOperacion(QStringList );
	void EnviaGeneralesEmpresa(Empresa *);
	void EnviaDirecciones(Empresa *);
	void EnviaContactos(Empresa *);
	void EnviaTelefonos(Empresa *);
	void EnviaFinDeRegistro();
	void EnviaInformacion();
	
	void EnviaEmpresas(CQEmpresas *);
	void AnexaRegistroVacio();
	void AnexaRegistro();

	void AnexaDirecciones(Empresa *);
	void AnexaTelefonos(Empresa *);
	void AnexaContactos(Empresa *);

	void AnalizaRespuesta(CQEmpresas *);
	
};

class CQSeleccionaProveedor:public QObject
{
Q_OBJECT 
public:
	CQSeleccionaProveedor(CSISCOMDatComunicaciones *,
			      QWidget *,	
			      const char *,
			      QLineEdit *,
			      QComboBox *);

private:
	QLineEdit *QLECRazonSocial;
	QComboBox *QCBRazonSocial;
	CSISCOMDatComunicaciones *CSisDatCom;
	CQEmpresas CQ_Empresas;
private:
	void ConectaSlots();
	void LlenaComboRazonSocial();
private slots:
	void S_SeleccionoProveedor();
	void S_SeleccionoProveedor(int);
signals:
	void Signal_Proveedor(Empresa *);
};


#endif
