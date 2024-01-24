#ifndef __QCTRLTIPOCOMPETENCIA_H__
#define __QCTRLTIPOCOMPETENCIA_H__ 
#include <CQSisTipoCompetencia.h>
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qiconview.h>

class QIconView;
class QHBoxLayout;
class CQSisTipoCompetencia;
class SiscomDatCom;
class CQSisClase;

class QIVItemTipoCompetencia:public QIconViewItem
{
public:
	QIVItemTipoCompetencia(CQSisTipoCompetencia *, QIconView *);
	CQSisTipoCompetencia *ObtenTipoCompetencia();
private:
	CQSisTipoCompetencia *CQSTipoCompetencia;
private:
	void IniciaVariables();

};
class QT_WIDGET_PLUGIN_EXPORT QCtrlTipoCompetencia : public QWidget
{
    Q_OBJECT
public:
    QCtrlTipoCompetencia( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void setFocus();
    void LimpiaSeleccion();
    void Limpia();
    
private:
	void IniciaVariables();
	void ConsultaTipoCompetencia();
	void MuestraTipoCompetencia();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	QIconView *QIVCompetencias;
	SiscomDatCom *SisDatCom;
	CQSisClase *CQSClase;
	CQSisLstTipoCompetencia CQSLTipoCompetencia;

private slots:
	void SlotTipoCompetencia(QIconViewItem *);
signals:
	void SignalTipoCompetencia(CQSisTipoCompetencia *);
};

#endif
