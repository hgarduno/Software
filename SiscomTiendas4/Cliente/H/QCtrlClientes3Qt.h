
#ifndef __QCTRLCLIENTESQT3_H__
#define __QCTRLCLIENTESQT3_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <CQSisClientes3Qt.h>
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class CQSisCliente;
class SiscomDatCom;

class QT_WIDGET_PLUGIN_EXPORT QCtrlClientes3Qt : public QWidget
{
    Q_OBJECT
public:
    QCtrlClientes3Qt( QWidget *parent = 0, const char *name = 0);
    ~QCtrlClientes3Qt();
    void IniciaControl();
    void Servidor(SiscomDatCom *);
    void ConElCliente(const char *);
    void setFocus();
    void Limpia();
    SiscomRegistro3 *PrimerCliente();
    
private:
	void IniciaVariables();
	void ConsultaClientes();
	void MuestraClientes();
	void ConectaSlots();
	void SeleccionoCliente(int);
	void EnviaSenal(SiscomRegistro3 *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBClientes;
	QLineEdit *QLEClientes;
	SiscomDatCom *SisDatCom;
	/*
	SiscomRegistro3Lst SReg3LstClientes;
	*/
	CQSisCliente3QtLst SReg3LstClientes;
private slots:
	void SlotCliente(int );
	void SlotCliente();
signals:
	void SignalMoral(SiscomRegistro3 *);
	void SignalFisica(SiscomRegistro3 *);
};

#endif
