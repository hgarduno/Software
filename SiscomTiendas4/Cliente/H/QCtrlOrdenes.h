#ifndef __QCTRLORDENES_H__
#define __QCTRLORDENES_H__

#include <CQSisOrdenes.h>
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <qiconview.h>

class QIconView;
class QHBoxLayout;
class CQSisOrden;
class CQSisEmpresa;
class SiscomDatCom;

class QIVItemOrden:public QIconViewItem
{
public:
	QIVItemOrden(CQSisOrden *, QIconView *);
	CQSisOrden *ObtenOrden();
private:
	CQSisOrden *CQSOrden;
private:
	void IniciaVariables();

};
class QT_WIDGET_PLUGIN_EXPORT QCtrlOrdenes : public QWidget
{
    Q_OBJECT
public:
    QCtrlOrdenes( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void PonRangoFecha(const char *,const char *);
    void PonExpendio(CQSisEmpresa *);
    void PonEdoVenta(const char *);
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
	CQSisLstOrden CQSLOrden;
	const char *chrPtrFechaIni;
	const char *chrPtrFechaFin;
	const char *chrPtrEdoVenta;
	CQSisEmpresa *CQSExpendio;

private slots:
	void S_SeleccionoClase(QIconViewItem *);
signals:
	void SignalOrden(CQSisOrden *);
};

#endif
