#ifndef __QCTRLNIVEL_H__
#define __QCTRLNIVEL_H__

#include <CQSisNivel.h>
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qiconview.h>

class QIconView;
class QHBoxLayout;
class CQSisNivel;
class SiscomDatCom;
class CQSisClase;

class QIVItemNivel:public QIconViewItem
{
public:
	QIVItemNivel(CQSisNivel *, QIconView *);
	CQSisNivel *ObtenNivel();
private:
	CQSisNivel *CQSNivel;
private:
	void IniciaVariables();

};
class QT_WIDGET_PLUGIN_EXPORT QCtrlNivel : public QWidget
{
    Q_OBJECT
public:
    QCtrlNivel( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void setFocus();
    void LimpiaSeleccion();
    void Limpia();
    void PonClase(CQSisClase *);
    
private:
	void IniciaVariables();
	void ConsultaNiveles();
	void MuestraNiveles();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	QIconView *QIVCompetencias;
	SiscomDatCom *SisDatCom;
	CQSisClase *CQSClase;
	CQSisLstNivel CQSLNivel;
	int intYaConectaSlots;

private slots:
	void S_SeleccionoNivel(QIconViewItem *);
signals:
	void SignalNivel(CQSisNivel *);
};

#endif
