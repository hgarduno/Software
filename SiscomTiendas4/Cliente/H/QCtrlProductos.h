#ifndef __QCTRLPRODUCTOS_H__
#define __QCTRLPRODUCTOS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <CQSisProductos.h>

class QHBoxLayout;
class QComboBox;
class QLineEdit;
class CQSisProducto;
class SiscomDatCom;

class QT_WIDGET_PLUGIN_EXPORT QCtrlProductos : public QWidget
{
    Q_OBJECT
public:
    QCtrlProductos( QWidget *parent = 0, const char *name = 0);
    ~QCtrlProductos();
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void setFocus();
    void Limpia();
    
private:
	void IniciaVariables();
	void ConsultaProductos();
	void MuestraProductos();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBProductos;
	QLineEdit *QLEProductos;
	SiscomDatCom *SisDatCom;
	CQSisLstProducto CQSLProductos;
private slots:
	void SlotProducto(int );
	void SlotSeleccionandoProducto(int);
signals:
	void SignalProductos(CQSisProducto *);
	void SignalSeleccionandoProducto(CQSisProducto *);
};

#endif
