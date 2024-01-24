#ifndef __QCTRLESTADISTICAMEDICO_H__
#define __QCTRLESTADISTICAMEDICO_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <CQSisEstadisticaMedicos.h>

class QHBoxLayout;
class SiscomDatCom;
class CQSisPersona;
/*
 *
 * Mediante este control, se podra crear un panel para el
 * administrador que le permita visualizar la evolucion del
 * trabajo de cada uno de los medicos de la clinica
 *
 */
class QT_WIDGET_PLUGIN_EXPORT QCtrlEstadisticaMedicos: public QWidget
{
    Q_OBJECT
public:
    QCtrlEstadisticaMedicos( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void Medico(CQSisPersona *);
    void setFocus();
    void LimpiaSeleccion();
    void Limpia();
    
private:
	void IniciaVariables();
	void ConsultaEstadisticaMedicos();
	void MuestraEstadisticaMedicos();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	SiscomDatCom *SisDatCom;
	CQSisLstEstadisticaMedico  CQSLEstadisticaMedico;

	CQSisPersona *CQSMedico;

private slots:
signals:
};

#endif

