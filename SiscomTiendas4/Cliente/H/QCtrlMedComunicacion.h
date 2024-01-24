#ifndef __QCTRLMEDCOMUNICACION_H__
#define __QCTRLMEDCOMUNICACION_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qiconview.h>
#include <SisMedioComunicacion.h>

class QIconView;
class QHBoxLayout;
class SisMedCom;
class SiscomDatCom;

class QIVItemMedComunicacion:public QIconViewItem
{
public:
	QIVItemMedComunicacion(SisMedCom *, QIconView *);
	SisMedCom *ObtenMedComunicacion();
private:
	SisMedCom *SMCom;
private:
	void IniciaVariables();

};
class QT_WIDGET_PLUGIN_EXPORT QCtrlMedComunicacion : public QWidget
{
    Q_OBJECT
public:
    QCtrlMedComunicacion( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void setFocus();
    void LimpiaSeleccion();
    void Limpia();
    
private:
	void IniciaVariables();
	void ConsultaMedComunicaciones();
	void MuestraMedComunicaciones();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	QIconView *QIVCompetencias;
	SiscomDatCom *SisDatCom;
	SisLstMedCom SLMComunicacion;

private slots:
	void S_SeleccionoMedComunicacion(QIconViewItem *);
signals:
	void SignalMedComunicacion(SisMedCom  *);
};

#endif
