#ifndef __QCTRLEMPRESAS_H__
#define __QCTRLEMPRESAS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <CQSisEmpresas.h>

class QHBoxLayout;
class QComboBox;
class QLineEdit;
class CQSisEmpresa;
class SiscomDatCom;

class QT_WIDGET_PLUGIN_EXPORT QCtrlEmpresas : public QWidget
{
    Q_OBJECT
public:
    QCtrlEmpresas( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void setFocus();
    void Limpia();
    
private:
	void IniciaVariables();
	void ConsultaEmpresas();
	void MuestraEmpresas();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBEmpresas;
	QLineEdit *QLEEmpresas;
	SiscomDatCom *SisDatCom;
	CQSisLstEmpresa CQSLEmpresas;
private slots:
	void SlotProducto(int );
signals:
	void SignalEmpresas(CQSisEmpresa *);
};

#endif
