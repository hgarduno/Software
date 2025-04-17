#ifndef __QCTRLPRODUCTOSSE_H__
#define __QCTRLPRODUCTOSSE_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>

class QHBoxLayout;
class QComboBox;
class QLineEdit;
class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class zProducto;


class zProductos;
class QT_WIDGET_PLUGIN_EXPORT QCtrlProductosSE:public QWidget 
{
Q_OBJECT
public:
	QCtrlProductosSE(QWidget *pQWParent=0,const char *pchrPtrName=0);
	void Servidor(zSiscomConexion *pzSiscomConexion);
	void IniciaControl();
	QLineEdit *QLineEditProducto();
	void setFocus();
	void IdExpendio(const char *);
	zSiscomRegistro *Producto(const char *pchrPtrClave);

private:
	void IniciaVariables();
	void ConectaSlots();
	void Consultando();
	void ConsultaProductos();
	void MuestraProductos();
	void ConsultandoProductosSimilares(const char *pchrPtrCriterio);
	void EliminandoProductos();
	zProducto *IniciaParaProducto(const char *);
private:
	QComboBox *QCBProductos;
	QHBoxLayout *QHBLayout;
	QLineEdit *QLEProducto;
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsProductos;
	const char *chrPtrIdExpendio;
	int intSiEnLista;
private slots:
	void SlotSeleccionando(int);
	void SlotSelecciono(int);
	void SlotProducto(const QString &);
signals:
	void SignalSeleccionando(zSiscomRegistro *);
	void SignalSelecciono(zSiscomRegistro *);
	void SignalProductoNoValido(zProducto *);
	void SignalSeleccionados(zProductos *);

};

#endif

