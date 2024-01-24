#ifndef __QCTRLTIPOCOMPETENCIA_H__
#define __QCTRLTIPOCOMPETENCIA_H__ 
#include <CQSisAparatoCompetencia.h>
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qiconview.h>

class QIconView;
class QHBoxLayout;
class CQSisAparatoCompetencia;
class CQSisClase;
class CQSisAparato;
class CQSisCompetencia;
class SiscomDatCom;

class QIVItemAparatoCompetencia:public QIconViewItem
{
public:
	QIVItemAparatoCompetencia(CQSisAparatoCompetencia *, QIconView *);
	CQSisAparatoCompetencia *ObtenAparatoCompetencia();
private:
	CQSisAparatoCompetencia *CQSAparatoCompetencia;
private:
	void IniciaVariables();

};
class QT_WIDGET_PLUGIN_EXPORT QCtrlAparatoCompetencia : public QWidget
{
    Q_OBJECT
public:
    QCtrlAparatoCompetencia( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void PonCompetencia(CQSisCompetencia *);
    void setFocus();
    void LimpiaSeleccion();
    void Limpia();
    const CQSisLstAparatoCompetencia &ObtenAparatos();
    
private:
	void IniciaVariables();
	void ConsultaAparatoCompetencia();
	void MuestraAparatoCompetencia();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	QIconView *QIVCompetencias;
	SiscomDatCom *SisDatCom;
	CQSisClase *CQSClase;
	CQSisLstAparatoCompetencia CQSLAparatoCompetencia;
	CQSisCompetencia *CQSCompetencia;

private slots:
	void SlotAparatoCompetencia(QIconViewItem *);
signals:
	void SignalAparatoCompetencia(CQSisAparatoCompetencia *);
};

#endif
