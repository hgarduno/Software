#ifndef __IMP_CLIENTE_H__
#define __IMP_CLIENTE_H__

#include <UIC_H_Cliente.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;

class SiscomDatCom;
class TransfiereAEstaciones;
class QEEdoTransmision;
class QNotTransmision;
class QItemToolBoxEscrip:public QWidget
{
public:
	QItemToolBoxEscrip(const char *,QWidget *,const char *);
	const char *ObtenEscript();
	const char *ObtenNmbEscript();
private:
	const char *chrPtrNmbEscrip;
	QTextEdit *QTEscript;

};
class QCliente : public Cliente
{
    Q_OBJECT

public:
    QCliente( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QCliente();
private:
	void ConectaSlots();
	void IniciaComunicaciones();
	void MuestraDatosTabla(QStringList ,QTable *);
	void ObtenDatosArchivo(QString,char *);
	void SeleccionaYAnexaArchivos(const char *,QStringList &,QTable *);
	void TransfiereArchivos(QStringList,const char *,const char *,const char *);
	void IniciaVariables();
	void AnexaEscript();
	void TransfiereEscripts();
	void CargaEstaciones();
	void customEvent(QCustomEvent *);
	void EstadoTransmision(QEEdoTransmision *);
private slots:
	void S_CreaDirectorios();
	void S_AnexaModulos();
	void S_TransfiereClienteAlServidor();
	void S_AnexaAplicacionCliente();
	void S_AnexaConfiguracionCliente();
	void S_AnexaEscript();
	void S_AnexaEstacion();
	void S_ActualizaEstaciones();
	void S_TransfiereAEstaciones();
private:
	SiscomDatCom *SDatCom;
	QStringList QSLModulos;
	QStringList QSLACliente;
	QStringList QSLConCliente;
	TransfiereAEstaciones *TAEstaciones;
	QNotTransmision *QNTransmision;
};

#endif 
