#ifndef __QCTRLSERVICIO_H__
#define __QCTRLSERVICIO_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <CQSisServicios.h>

class QTable;
class QHBoxLayout;
class SiscomDatCom;

class QT_WIDGET_PLUGIN_EXPORT QCtrlServicios: public QWidget
{
    Q_OBJECT
public:
    QCtrlServicios( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void TipoServicio(const char *);
    void IdMedico(const char *);
    void setFocus();
    void LimpiaSeleccion();
    void Limpia();
    
private:
	void IniciaVariables();
	void ConsultaServicios();
	void MuestraServicios();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	QTable *QTServicios;
	SiscomDatCom *SisDatCom;
	CQSisLstServicio  CQSLServicio;
	const char *chrPtrIdMedico;
	const char *chrPtrTipoServicio;

private slots:
	void SlotServicio(int,int,int,const QPoint &);
signals:
	void SignalServicio(CQSisServicio *);
};

#endif

