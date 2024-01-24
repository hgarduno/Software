
#ifndef __QCTRLPRODUCTOS3QT_H__
#define __QCTRLPRODUCTOS3QT_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class CQSisProducto;
class SiscomDatCom;

class QT_WIDGET_PLUGIN_EXPORT QCtrlProductos3Qt : public QWidget
{
    Q_OBJECT
public:
    QCtrlProductos3Qt( QWidget *parent = 0, const char *name = 0);
    ~QCtrlProductos3Qt();
    void IniciaControl();
    void Servidor(SiscomDatCom *);
    void setFocus();
    void Limpia();
    SiscomRegistro3 *PrimerProducto();
    int EsProductoDeLaLista();
    void ProductoDeLaLista(int);
    void ColocaListaEnLaClave(const char *pchrPtrClave);
    
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
	SiscomRegistro3Lst SReg3LstProductos;
	int intEsProdDeLaLista;
private slots:
	void SlotProducto(int );
	void SlotProducto();
	void SlotSeleccionandoProducto(int);
signals:
	void SignalProductos(SiscomRegistro3 *);
	void SignalSeleccionandoProducto(SiscomRegistro3*);
	void SignalProductoNoEstaEnLaLista(const char *pchrPtrTexto);
};

#endif
