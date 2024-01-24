#ifndef __QCTRLCLASE_H__
#define __QCTRLCLASE_H__

#include <CQSisClase.h>
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qiconview.h>

class QIconView;
class QHBoxLayout;
class CQSisClase;
class SiscomDatCom;
class CQSisCompetencia;

class QIVItemClase:public QIconViewItem
{
public:
	QIVItemClase(CQSisClase *, QIconView *);
	CQSisClase *ObtenClase();
private:
	CQSisClase *CQSClase;
private:
	void IniciaVariables();

};
class QT_WIDGET_PLUGIN_EXPORT QCtrlClase : public QWidget
{
    Q_OBJECT
public:
    QCtrlClase( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void PonCompetencia(CQSisCompetencia *);
    void setFocus();
    void LimpiaSeleccion();
    
private:
	void IniciaVariables();
	void ConsultaClases();
	void MuestraClases();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	QIconView *QIVCompetencias;
	SiscomDatCom *SisDatCom;
	CQSisCompetencia *CQSCompetencia;
	CQSisLstClase CQSLClase;

private slots:
	void S_SeleccionoClase(QIconViewItem *);
signals:
	void SignalClase(CQSisClase *);
};

#endif
