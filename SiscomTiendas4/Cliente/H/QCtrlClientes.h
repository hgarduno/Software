#ifndef __QCTRLCLIENTES_H__
#define __QCTRLCLIENTES_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <CQSisClientes.h>

class QHBoxLayout;
class QComboBox;
class QLineEdit;
class CQSisCliente;
class SiscomDatCom;

class QT_WIDGET_PLUGIN_EXPORT QCtrlClientes : public QWidget
{
    Q_OBJECT
public:
    QCtrlClientes( QWidget *parent = 0, const char *name = 0);
    ~QCtrlClientes();
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void ConElCliente(const char *);
    void setFocus();
    void Limpia();
    
private:
	void IniciaVariables();
	void ConsultaClientes();
	void MuestraClientes();
	void ConectaSlots();
	void SeleccionoCliente(int);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBClientes;
	QLineEdit *QLEClientes;
	SiscomDatCom *SisDatCom;
	CQSisLstCliente CQSLClientes;
private slots:
	void SlotProducto(int );
signals:
	void SignalMoral(CQSisCliente *);
	void SignalFisica(CQSisCliente *);
};

#endif
