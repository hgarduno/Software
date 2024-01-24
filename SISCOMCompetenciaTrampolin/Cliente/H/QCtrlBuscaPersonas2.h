#ifndef __QCTRLBUSCAPERSONAS2_H__
#define __QCTRLBUSCAPERSONAS2_H__

#include <CQSisBuscaPersonas2.h>
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qdialog.h>
#include <CQSisEntrenadores.h>

class QHBoxLayout;
class SiscomDatCom;
class QLineEdit;
class QLabel;
class QPushButton;
class QTable;
class QButtonGroup;
class QRadioButton;

class QT_WIDGET_PLUGIN_EXPORT QCtrlBuscaPersonas2 : public QWidget
{
    Q_OBJECT
public:
    QCtrlBuscaPersonas2( QWidget *parent = 0, const char *name = 0);
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
	
	const char *chrPtrPersona;

	CQSisLstEntrenador CQSLPersonas;

	void (QCtrlBuscaPersonas2::*TipoPersona[10])();

	int intYaConectoSlots;

private slots:
	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotBusca();
signals:
	void SignalPersona(CQSisEntrenador *,const char *);
};

class QResBusqueda:public QDialog
{
Q_OBJECT
public:
	QResBusqueda(CQSisLstEntrenador *,
		     QWidget *pQWParent=0,
		     const char *pchrPtrName=0,
		     bool pbModal=false,
		     WFlags pWFlags=0);
	CQSisEntrenador *ObtenPersona();
private:
	QTable *QTDatos;
	QHBoxLayout *QHBLayout;
	CQSisLstEntrenador *CQSLEPersona;
	CQSisEntrenador *CQSEPersona;
private:
	void IniciaVariables();
	void IniciaTabla();
	void ConectaSlots();
	void MuestraPersonas();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotPersona(int,int,int,const QPoint &);
};

#endif
