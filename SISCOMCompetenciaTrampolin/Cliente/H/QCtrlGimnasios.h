#ifndef __QCTRLGIMNASIOS_H__
#define __QCTRLGIMNASIOS_H__

#include <CQSisGimnasios.h>
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qiconview.h>

class QIconView;
class QHBoxLayout;
class CQSisGimnasio;
class SiscomDatCom;

class QIVItemGimnasio:public QIconViewItem
{
public:
	QIVItemGimnasio(CQSisGimnasio *, QIconView *);
	CQSisGimnasio *ObtenGimnasio();
private:
	CQSisGimnasio *CQSGimnasio;
private:
	void IniciaVariables();

};
class QT_WIDGET_PLUGIN_EXPORT QCtrlGimnasios : public QWidget
{
    Q_OBJECT
public:
    QCtrlGimnasios( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void setFocus();
    void LimpiaSeleccion();
    void Limpia();
    
private:
	void IniciaVariables();
	void ConsultaGimnasios();
	void MuestraGimnasios();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	QIconView *QIVGimnasios;
	SiscomDatCom *SisDatCom;
	CQSisLstGimnasio CQSLstGimnasios;

private slots:
	void S_SeleccionoGimnasio(QIconViewItem *);
signals:
	void SignalGimnasio(CQSisGimnasio *);
};

#endif
