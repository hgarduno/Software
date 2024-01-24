#ifndef __QCTRLELFRESNO_H__
#define __QCTRLELFRESNO_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qiconview.h>
#include <CQSisElFresnos.h>

class QIconView;
class QHBoxLayout;
class SiscomDatCom;

class QIVItemElFresno:public QIconViewItem
{
public:
	QIVItemElFresno(CQSisElFresno*, QIconView *);
	CQSisElFresno *ObtenElFresno();
private:
	CQSisElFresno *CQSElFresno;
private:
	void IniciaVariables();

};
class QT_WIDGET_PLUGIN_EXPORT QCtrlElFresnos: public QWidget
{
    Q_OBJECT
public:
    QCtrlElFresnos( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void setFocus();
    void LimpiaSeleccion();
    void Limpia();
    
private:
	void IniciaVariables();
	void ConsultaElFresnos();
	void MuestraElFresnos();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	QIconView *QIVElFresnos;
	SiscomDatCom *SisDatCom;
	CQSisLstElFresno  CQSLElFresno;

private slots:
	void S_SeleccionoElFresno(QIconViewItem *);
signals:
	void SignalElFresno(CQSisElFresno *);
};

#endif

