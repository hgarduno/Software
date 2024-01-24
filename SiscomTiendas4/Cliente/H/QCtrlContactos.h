#ifndef __QCTRLCONTACTOS_H__
#define __QCTRLCONTACTOS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <CQSisContactos.h>

class QHBoxLayout;
class QComboBox;
class QLineEdit;
class CQSisContacto;
class CQSisEmpresa;
class SiscomDatCom;

class QT_WIDGET_PLUGIN_EXPORT QCtrlContactos : public QWidget
{
    Q_OBJECT
public:
    QCtrlContactos( QWidget *parent = 0, const char *name = 0);
    ~QCtrlContactos();
    void PonEmpresa(CQSisEmpresa *);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void setFocus();
    void Limpia();
    
private:
	void IniciaVariables();
	void ConsultaContactos();
	void MuestraContactos();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBContactos;
	QLineEdit *QLEContactos;
	SiscomDatCom *SisDatCom;
	CQSisEmpresa *CQSEmpresa;
	CQSisLstContacto CQSLContactos;
private slots:
	void SlotProducto(int );
signals:
	void SignalContactos(CQSisContacto *);
};

#endif
