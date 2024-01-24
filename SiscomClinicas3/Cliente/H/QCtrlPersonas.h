#ifndef __QCTRLPERSONA_H__
#define __QCTRLPERSONA_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qiconview.h>
#include <CQSisPersonas.h>

class QIconView;
class QHBoxLayout;
class SiscomDatCom;

class QIVItemPersona:public QIconViewItem
{
public:
	QIVItemPersona(CQSisPersona*, QIconView *);
	CQSisPersona *ObtenPersona();
private:
	CQSisPersona *CQSPersona;
private:
	void IniciaVariables();

};
class QT_WIDGET_PLUGIN_EXPORT QCtrlPersonas: public QWidget
{
    Q_OBJECT
public:
    QCtrlPersonas( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void NombrePerfil(const char *);
    void setFocus();
    void LimpiaSeleccion();
    void Limpia();
    
private:
	void IniciaVariables();
	void ConsultaPersonas();
	void MuestraPersonas();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	QIconView *QIVPersonas;
	SiscomDatCom *SisDatCom;
	CQSisLstPersona  CQSLPersona;
	const char *chrPtrNmbPerfil;

private slots:
	void S_SeleccionoPersona(QIconViewItem *);
signals:
	void SignalPersona(CQSisPersona *);
};

#endif

