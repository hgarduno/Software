#ifndef __QCTRLCOMPETENCIAS_H__
#define __QCTRLCOMPETENCIAS_H__

#include <CQSisCompetencias.h>
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qiconview.h>

class QIconView;
class QHBoxLayout;
class CQSisCompetencia;
class SiscomDatCom;

class QIVItemCompetencia:public QIconViewItem
{
public:
	QIVItemCompetencia(CQSisCompetencia *, QIconView *);
	CQSisCompetencia *ObtenCompetencia();
private:
	CQSisCompetencia *CQSCompetencia;
private:
	void IniciaVariables();

};
class QT_WIDGET_PLUGIN_EXPORT QCtrlCompetencias : public QWidget
{
    Q_OBJECT
public:
    QCtrlCompetencias( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void setFocus();
    void LimpiaSeleccion();
    
private:
	void IniciaVariables();
	void ConsultaCompetencias();
	void MuestraCompetencias();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	QIconView *QIVCompetencias;
	SiscomDatCom *SisDatCom;
	CQSisLstCompetencia CQSLCompetencias;

private slots:
	void SlotCompetencia(QIconViewItem *);
signals:
	void SignalCompetencia(CQSisCompetencia *);
};

#endif
