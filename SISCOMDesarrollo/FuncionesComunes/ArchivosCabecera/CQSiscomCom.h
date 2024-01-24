#ifndef __CQSISCOMCOM_H__
#define __CQSISCOMCOM_H__

#include <qobject.h>
#include <qobjectlist.h>
#include <qptrlist.h>
#include <qstringlist.h>
#include <qtable.h>
#include <CSISCOMComunicaciones.h>
class QStringList;
class QWidget;
class QLineEdit;
class QTable;
class QPushButton;
class QComboBox;
class QTextEdit;

class CQTableItemColor:public QTableItem
{
public:
	CQTableItemColor(QTable *,EditType ,const QString &);
	void paint(QPainter *,const QColorGroup &,const QRect &,bool );

};
class CQSiscomCom:public CSISCOMComunicaciones
{
	public:
		CQSiscomCom();
		CQSiscomCom(CSISCOMDatComunicaciones );
		CQSiscomCom(int,const char *,const char *,const char *);
		~CQSiscomCom();
		void EjecutaEnvioSvrSISCOM();
		QStringList &ObtenRegistroRespuesta();
		QStringList &ObtenRegistroRespuesta(int *);
		void ObtenRegistroRespuesta(int *,QStringList &);
	private:
		StcLtaRegComSISCOM *SLRComSisPtrDat;
		StcLtaRegComSISCOM *SLRComSisPtrPrim;
		QStringList QSLRegistro;
};

class CQOGenericaServidorSiscom: public CQSiscomCom
{
	public:
		CQOGenericaServidorSiscom();
		~CQOGenericaServidorSiscom();
		CQOGenericaServidorSiscom(CSISCOMDatComunicaciones *,
					  const char *,
					  const char *,
					  int);
		int EsElUltimoRegistro()
		{
			return intPosRegistro==intNRegistros  ? 1 : 0;
		}
		void SiguienteRegistro()
		{
			intPosRegistro++;
		}
		int ObtenNumCamposRespuesta()
		{
		   	return intNCampos;
		}
		int ObtenNumRegistros()
		{
			return intNRegistros;
		}
		void ColocaAlInicio();
		int SiguienteRegistro(int ,QStringList &);
		int SiguienteRegistro(QStringList &);
		void ObtenRespuesta();
		void ObtenRegistro(QStringList &);
		void ObtenCampoTodos(int ,QStringList &);
		QStringList ObtenCampoTodos(int );
		QString ObtenCampo(int ,int);
	private:
		int intPosRegistro;
		int intNRegistros;
		int intNCampos;
		QString QSNmbBibSvr;
		QString QSNmbFuncionSvr;
		QPtrList<QStringList > QPLRegistros;
	private:
		void IniciaRegistroRespuesta(QStringList );
		void AnexaRegistroRespuesta(QStringList );
	

};


class SISCOMCampoEnvio
{
public:
	SISCOMCampoEnvio(const char *,const char *pchrPtrContenido="");
	const char *ObtenNombre();
	const char *ObtenContenido();
	void PonContenido(const char *);
private:
	const char *chrPtrNombre;
	const char *chrPtrContenido;

};
class SISCOMRegistroEnvio:public QPtrList<SISCOMCampoEnvio>
{

public:
	SISCOMRegistroEnvio();
	char **ObtenRegistro();
	SISCOMCampoEnvio *operator[](const char *);
	SISCOMRegistroEnvio &operator<<(SISCOMCampoEnvio *);
	void LimpiaRegistro();
private:

};
class SISCOMOperacionesEnvio
{

public:
	SISCOMOperacionesEnvio(CSISCOMDatComunicaciones *,
			       QStringList,
			       const char *,
			       const char *,
			       const char * );
	virtual void SISCOMIniciaRegistroEnvio() {};
	virtual void SISCOMRegistrosEnvio() {};
	CQOGenericaServidorSiscom *SISCOMObtenOperacionServidor();
	void SISCOMPonRegistroEnvio(const SISCOMRegistroEnvio &);
	void SISCOMEjecutaEnvio();
	void SISCOMAnexaRegistro(const SISCOMRegistroEnvio &);
	void SISCOMAnexaRegistroVacio();

private:
	 CQOGenericaServidorSiscom *CQOGSvrSiscom;
         CSISCOMDatComunicaciones *CSisDatCom;
	 SISCOMRegistroEnvio  SISCOMRegEnvio;
	 QStringList QSLArgumentos;
	 const char *chrPtrServidor;
	 const char *chrPtrFuncion;
	 const char *chrPtrOperacion;
private:
	void IniciaComunicacion(const char *,const char *,const char *);
	void AnexaRegistro();
	void AnexaRegistroVacio();
	void EnviaParametrosOperacion(QStringList );
	void EnviaInformacion();

};
class SISCOMGlobales
{
	public:
		SISCOMGlobales();
		 enum BTN_Captura
		 {
			 Aceptar,
			 Cancelar
		 };
			


};
void MuestraTexto(QLineEdit *,QString );
void PasaFocoControl(QWidget *);
void PasaFocoControl(QLineEdit *);
void SISCOMAnexarRegistroALaTabla(int,QTable *,QStringList );
void SISCOMAnexarRegistroALaTabla(int pintNFila,
			    QTable *pQTTabla,
			    QColor pQColor,
			    QStringList pQSLRegistro);

void AnexarRegistroALaTabla(QTable *,QStringList );
void AnexarRegistroALaTabla(QTable *,QPixmap *,QStringList );
void AnexarRegistroALaTabla(QTable *,int,QStringList );
void CreaListaDeCadenas(QStringList &,const char *,...);
void EliminaFilasTabla(QTable *);
void EliminaFilasTabla2(QTable *);
void LlenaTablaQSiscomCom(CQSiscomCom *,QTable *);
void LeeArchivoApiQT(const char *,char **);
void HabilitaDesHabilitaControles(const char *,...);
void HabilitaDesHabilitaControles(QObject *,int,const char *);
CQSiscomCom *IniciaConsultaAlServidor(const char *,const char *,int,CSISCOMDatComunicaciones *);
void ColocaCheckBoxALaTabla(QTable *,int ,int,QString ,int );
QLineEdit *ColocaLineEditAlCombo(QComboBox *,const char *);
void MuestraContenidoRegistro(QStringList pQSLRegistro,
			      const char *pchrPtrFuncion);
int SISCOMEsElRegistroVacio(QStringList pQSLRegistro);

const char *SISCOMObtenInformacionDelEdit(QLineEdit *);
const char *SISCOMObtenInformacionDelEdit(QTextEdit *);






#endif
