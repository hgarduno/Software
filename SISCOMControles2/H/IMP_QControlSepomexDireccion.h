#ifndef __CQCONTROLSEPOMEXDIRECCION_H__
#define __CQCONTROLSEPOMEXDIRECCION_H__

#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qlayout.h>
#include <SepomexEstados.h>
#include <SepomexMunicipios.h>
#include <SepomexTAsentamientos.h>
#include <SepomexAsentamientos.h>
class QGridLayout;
class QSpacerItem;
class QLineEdit;
class QVBoxLayout;
class QHBoxLayout;
class QComboBox;
class SiscomDatCom;
class QLabel;
class QPushButton;
/*
class QHEspacio:public QHBoxLayout
{
public:
	QHEspacio(QWidget *,int ,int,const char *);

	QHEspacio &operator+=(QVBoxLayout  *);


};
*/
class QT_WIDGET_PLUGIN_EXPORT CQControlSepomexDireccion : public QWidget 
{
    Q_OBJECT

public:
    CQControlSepomexDireccion( QWidget* parent = 0, const char* name = 0);
    ~CQControlSepomexDireccion();
	QPushButton *button;
	QLineEdit *lineEdit;
/*
    void setFocus();
    void PonServidor(SiscomDatCom *);
    void IniciaControl();
private:
private:
	void ConectaSlots();
	void IniciaVariables();
	void LlenaComboEstados();
	void LlenaComboMunicipios();
	void LlenaComboTAsentamientos();
	void LlenaComboAsentamientos();
	void ConsultaEstados();
	void ConsultaMunicipios(int);
	void ConsultaTAsentamientos();
	void ConsultaAsentamientos();


	QVBoxLayout *CreaEspacioEtiquetaEdit(const char *,
					     const char *,
					     const char *,
					     QLineEdit **);
	QVBoxLayout *CreaEspacioEtiquetaCombo(const char *,
					      const char *,
					      const char *,
					      QComboBox **,
					      QLabel **pQLRegreso=0);


private:

	SepomexEstados SepEstados;
	SepomexMunicipios SepMunicipios;
	SepomexTAsentamientos SepTAsentamientos;
	SepomexAsentamientos SepAsentamientos;
	SiscomDatCom *SisDatCom;

	SepomexEstado *SepEstado;
	SepomexMunicipio *SepMunicipio;
	SepomexTAsentamiento *SepTAsen;
	SepomexAsentamiento *SepAsen;

	QGridLayout *QGLRegilla;
	QHEspacio *QHECalleNum;
	QHEspacio *QHEAsentamiento;
	QHEspacio *QHECPCiudad;

	QLineEdit *QLECalle;
	QLineEdit *QLENumero;

	QComboBox *QCBEstados;
	QComboBox *QCBMunicipio;
	QComboBox *QCBTipoAsen;
	QComboBox *QCBAsentamiento;
	QComboBox *QCBCiudad;

	QLineEdit *QLEEstados;
	QLineEdit *QLEMunicipios;
	QLineEdit *QLETAsen;
	QLineEdit *QLEAsentamientos;
	QLineEdit *QLECP;

	QLabel *QLAsentamiento; 

	QHBoxLayout *layout;
	
private slots:
	void S_SeleccionoEstado();
	void S_PasaFocoEstados();
	void S_PasaFocoNumero();
	void S_PasaFocoTipoAsentamientos();
	void S_SeleccionoTipoAsentamiento();
	void S_SeleccionoAsentamiento();
signals:
*/
};

#endif 
