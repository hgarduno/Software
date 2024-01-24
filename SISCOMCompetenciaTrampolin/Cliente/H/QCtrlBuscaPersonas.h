#ifndef __QCTRLBUSCAPERSONAS_H__
#define __QCTRLBUSCAPERSONAS_H__

#include <CQSisBuscaPersonas.h>
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <CQSisEntrenadores.h>

class QHBoxLayout;
class SiscomDatCom;
class QLineEdit;
class QLabel;
class QPushButton;
class QTable;
class QButtonGroup;
class QRadioButton;

class QT_WIDGET_PLUGIN_EXPORT QCtrlBuscaPersonas : public QWidget
{
    Q_OBJECT
public:
    QCtrlBuscaPersonas( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void PonPersona(const char *);
    void setFocus();
    void LimpiaSeleccion();
    void HabilitaGimnasta(bool);
    void HabilitaJuez(bool);
    void HabilitaEntrenador(bool);
    
private:
	void IniciaVariables();
	void ConectaSlots();
	void IniciaGrids();
	void ColocaDatosGenerales();
	void ColocaTablaYBoton();
	void ColocaRadioBotones();
	void MuestraResultados();
	void Juez();
	void Gimnasta();
	void Entrenador();
	
private:
	SiscomDatCom *SisDatCom;
	QSisHEspacio *QSHEspacio;
	QGridLayout *QGLEspacio;
	QGridLayout *QGLEspacio1;
	QGridLayout *QGLRadioBotones;
	QLineEdit *QLENombre;
	QLineEdit *QLEAPaterno;
	QLineEdit *QLEAMaterno;

	QLabel *QLNombre;
	QLabel *QLAPaterno; QLabel *QLAMaterno;
	
	QTable *QTDatos;
	QPushButton *QPBBuscar;
	QButtonGroup *QBGBotones;

	QRadioButton *QRBGimnasta;
	QRadioButton *QRBJuez;
	QRadioButton *QRBEntrenador;
	const char *chrPtrPersona;

	CQSisLstEntrenador CQSLPersonas;

	void (QCtrlBuscaPersonas::*TipoPersona[10])();

private slots:
	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotPasaFocoBuscar();
	void SlotBusca();
	void SlotPersona(int,int,int,const QPoint &);
	void SlotTipoPersona(int );
signals:
	void SignalPersona(CQSisEntrenador *,const char *);
};

#endif
