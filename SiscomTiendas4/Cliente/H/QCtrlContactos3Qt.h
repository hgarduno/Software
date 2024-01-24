
#ifndef __QCTRLCONTACTOS3QT_H__
#define __QCTRLCONTACTOS3QT_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class SiscomDatCom;

class QT_WIDGET_PLUGIN_EXPORT QCtrlContactos3Qt : public QWidget
{
    Q_OBJECT
public:
    QCtrlContactos3Qt( QWidget *parent = 0, const char *name = 0);
    ~QCtrlContactos3Qt();
    void PonEmpresa(SiscomRegistro3 *);
    void IniciaControl();
    void Servidor(SiscomDatCom *);
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
	SiscomRegistro3 *SReg3Empresa;
	SiscomRegistro3Lst SReg3Contactos;
private slots:
	void SlotContacto(int );
signals:
	void SignalContacto(SiscomRegistro3 *);
};

#endif
