#ifndef __QSISSEPOMEX_H__
#define __QSISSEPOMEX_H__

#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qlayout.h>
#include <SiscomRegistros3.h>
class QGridLayout;
class QSpacerItem;
class QLineEdit;
class QVBoxLayout;
class QHBoxLayout;
class QComboBox;
class SiscomDatCom;
class QLabel;
class QPushButton;
class SisDireccion;
class SepomexDireccion;

class QHEspacio:public QHBoxLayout
{
public:
	QHEspacio(QWidget *,int ,int,const char *);

	QHEspacio &operator+=(QVBoxLayout  *);
};

class QVEspacio:public QVBoxLayout
{
public:
	QVEspacio(QWidget *,int ,int,const char *);

	QVEspacio &operator+=(QVBoxLayout  *);
};
class QT_WIDGET_PLUGIN_EXPORT QSisSepomex : public QWidget
{
    Q_OBJECT

public:
    QSisSepomex( QWidget *parent = 0, const char *name = 0);
    void setFocus();
    void PonServidor(SiscomDatCom *);
    void IniciaControl();
    void SiscomDatosServidor(const char *pchrPtrOperacionConsulta,
    			     const char *pchrPtrConsulta);
private:
	void ConectaSlots();
	void IniciaVariables();
	void LlenaComboEstados();
	void LlenaComboMunicipios();
	void LlenaComboTAsentamientos();
	void LlenaComboAsentamientos();
	void ConsultaEstados();
	void ConsultaMunicipios();
	void ConsultaAsentamientos();
	void LimpiaMunicipios();
	void LimpiaAsentamientos();
	


	QVBoxLayout *CreaEspacioEtiquetaEdit(const char *,
					     const char *,
					     const char *,
					     QLineEdit **);
	QVBoxLayout *CreaEspacioEtiquetaCombo(const char *,
					      const char *,
					      const char *,
					      QComboBox **,
					      QLabel **pQLRegreso=0);

	int SeGeneraLaSenalDireccion();
	void GeneraSenalDireccion();

	void ConsultandoMunicipios();
	void ConsultandoAsentamientos();

	SiscomRegistro3 *IniciaDireccion();

private:
	SiscomDatCom *SisDatCom;

	SiscomRegistro3Lst SisReg3LstEstados;
	SiscomRegistro3 *SisReg3Estado;
	SiscomRegistro3Lst SisReg3LstMunicipios;
	SiscomRegistro3 *SisReg3Municipio;
	SiscomRegistro3Lst SisReg3LstAsentamientos;
	SiscomRegistro3 *SisReg3Asentamiento;

	const char *chrPtrOperacionesConsulta;
	const char *chrPtrConsulta;

	QGridLayout *QGLRegilla;
	QHEspacio *QHECalleNum;
	QHEspacio *QHEAsentamiento;
	QHEspacio *QHECPCiudad;

	QLineEdit *QLECalle;
	QLineEdit *QLENumero;

	QComboBox *QCBEstados;
	QComboBox *QCBMunicipio;
	QComboBox *QCBAsentamiento;
	QComboBox *QCBCiudad;

	QLineEdit *QLEEstados;
	QLineEdit *QLEMunicipios;
	QLineEdit *QLEAsentamientos;
	QLineEdit *QLECP;

	QLabel *QLAsentamiento; 

	QHBoxLayout *layout;

	int intYaEstados;
	int intYaMunicipios;
	int intYaColonias;
	
private slots:
	void S_SeleccionoEstado();
	void S_PasaFocoEstados();
	void S_PasaFocoNumero();
	/*
	 * Domingo 21 De Septiembre del 2008 Tepotzotlan Mexico
	 *
	 * Al momento de enlazar este control con el programa
	 * principal SiscomTiendas4, marco que no encontraba
	 * la referencia a estos metodos, por lo que para no
	 * eliminarlos lo declare como virtuales
	 *
	 */
	virtual void S_PasaFocoTipoAsentamientos();
	virtual void S_SeleccionoTipoAsentamiento();
	void S_SeleccionoAsentamiento();
	void S_SeleccionoCP();
	void S_SeleccionoMunicipio();
	void S_SeleccionoEstado(int);
	void S_SeleccionoMunicipio(int);
	void S_SeleccionoAsentamiento(int);
signals:	
	void SignalDireccion(SisDireccion *);
	void SignalDireccion(SiscomRegistro3 *);
	
};

#endif
