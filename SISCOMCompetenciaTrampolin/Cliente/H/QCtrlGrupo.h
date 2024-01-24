#ifndef __QCTRLGRUPO_H__
#define __QCTRLGRUPO_H__

#include <CQSisGrupo.h>
#include <CQSisConsultas.h>
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qiconview.h>

class QIconView;
class QHBoxLayout;
class CQSisGrupo;
class CQSisCompetencia;
class SiscomDatCom;
class QTable;


class QIVItemGrupo:public QIconViewItem
{
public:
	QIVItemGrupo(CQSisGrupo *, QIconView *);
	CQSisGrupo *ObtenClase();
private:
	CQSisGrupo *CQSClase;
private:
	void IniciaVariables();

};
class QT_WIDGET_PLUGIN_EXPORT QCtrlGrupo : public QWidget
{
    Q_OBJECT
public:
    QCtrlGrupo( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void PonCompetencia(CQSisCompetencia *);
    void setFocus();
    void LimpiaSeleccion();
    void FormateaGrupo(CQSisGrupo *,char *);
    
private:
	void IniciaVariables();
	void ConsultaCompetencias();
	void MuestraCompetencias();
	void ConectaSlots();
	int NumeroFilas(CQSisLstGrupo *,int *);
private:
	QHBoxLayout *QHBLayout;
	QIconView *QIVCompetencias;
	SiscomDatCom *SisDatCom;
	QTable *QTDatos;
	CQSisLstLstGrupo CQSLstLstGrupo;
	CQSisCompetencia *CQSCompetencia;
private slots:
	void SlotSeleccionoGrupo(int ,int,int,const QPoint &);
signals:
	void SignalGrupo(CQSisGrupo *);
};

#endif
