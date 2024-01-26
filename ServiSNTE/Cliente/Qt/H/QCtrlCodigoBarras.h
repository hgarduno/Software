#ifndef __QCTRLCODIGOBARRAS_H__
#define __QCTRLCODIGOBARRAS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class QHBoxLayout;
class QLineEdit;
class QT_WIDGET_PLUGIN_EXPORT QCtrlCodigoBarras : public QWidget
{
    Q_OBJECT
public:
    QCtrlCodigoBarras( QWidget *parent = 0, const char *name = 0);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void setFocus();
	const char *CodigoBarras();
	zSiscomRegistros *ConsultaProductosSumados();
	zSiscomRegistros *ProductosSumados();
    	void ActualizaCantidadProducto();
	void CodigoBarras(const QString &);
	void EsStock(const char *pchrPtrEsStock);
	void Cantidad(int pintNProducto,const char *pchrPtrCantidad);

private:
	void IniciaVariables();
	void ConectaSlots();
	void ConsultaCodigoBarras();
	void AgregandoStock(zSiscomRegistro *pzSisRegProducto);
	void AgregandoCantidad(zSiscomRegistro *pzSisRegProducto,const char *pchrPtrCantidad);
private:
 	
	QHBoxLayout *QHBLayout;
	QLineEdit *QLECodigoBarras;
	zSiscomRegistros *zSisRegCodigoBarrasS;
	zSiscomRegistros *zSisRegCodigoBarrasSRespuesta;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegCodigoBarras;
	const char *chrPtrEsStock;
private slots:
	void SlotCapturo();
	void SlotCapturandoCodigoBarras(const QString &pQStrCodigoBarras);
signals:
	void SignalNuevoCodigoBarras(const QString &);
	void SignalCodigoBarras(zSiscomRegistro *pzSisRegCodigoBarras);
	void SignalCodigoBarrasVacia();
    	void SignalCodigoBarrasContabilizados(zSiscomRegistros *);

};

#endif
