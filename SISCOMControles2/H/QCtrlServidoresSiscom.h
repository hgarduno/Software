#ifndef __QCTRLSERVIDORESSISCOM_H__
#define __QCTRLSERVIDORESSISCOM_H__

#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qiconview.h>
class QHBoxLayout;
class QIconView;
class SiscomDatCom;
class QIVItemServidor:public QIconViewItem
{
public:
	QIVItemServidor(const char *pchrPtrNombre,
			SiscomDatCom *,QIconView *);
	SiscomDatCom *ObtenServidor();
private:
	void IniciaVariables();
private:
	SiscomDatCom *SisDatCom;
	const char *chrPtrNombre;

};
class QT_WIDGET_PLUGIN_EXPORT QCtrlServidoresSiscom : public QWidget
{
    Q_OBJECT

public:
    QCtrlServidoresSiscom( QWidget *parent = 0, const char *name = 0);
    void PonArchivoComunicaciones(const char *);
    void IniciaControl();
    void setFocus();
    void LimpiaSeleccion();

private:
	QHBoxLayout *QHBLayout;
	QIconView *QIVServidores;
	const char *chrPtrArcComunicaciones;
private:
	void IniciaVariables();
	void MuestraArchivos();
	void ObtenDatosServidores(const char *,char **,char **,char **);
	void ConectaSlots();
private slots:
	void S_SeleccionoServidor(QIconViewItem *);
	void S_MarcaServidor(QIconViewItem *);
signals:
	void SignalServidor(SiscomDatCom *);
	void SignalMarcaServidor(SiscomDatCom *);

};

#endif
