#ifndef __QCTRLPRECIOSPRODUCTOS_H__
#define __QCTRLPRECIOSPRODUCTOS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>
class QHBoxLayout;
class QTable;
class SiscomDatCom;

class QT_WIDGET_PLUGIN_EXPORT QCtrlPreciosProductos : public QWidget
{
    Q_OBJECT
public:
    QCtrlPreciosProductos( QWidget *parent = 0, const char *name = 0);
    ~QCtrlPreciosProductos();
    void Servidor(SiscomDatCom *);
    void Producto(const char *pchrPtrIdProducto);
    void ObtenPrecios();
    void setFocus();
    void Limpia();
    
private:
	void IniciaVariables();
	void ConsultaPreciosProducto();
	void MuestraPreciosProducto();
	void ConectaSlots();
private:
	QHBoxLayout *QHBLayout;
	QTable *QTPProducto;
	SiscomDatCom *SisDatCom;
	SiscomRegistro3Lst SReg3LstPProducto;
	const char *chrPtrIdProducto;
private slots:
	void SlotPrecioProducto(int );
	void SlotPrecioProducto();
signals:
};

#endif
