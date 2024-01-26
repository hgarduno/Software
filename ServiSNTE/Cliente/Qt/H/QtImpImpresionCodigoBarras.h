#ifndef __QTIMPIMPRESIONCODIGOBARRAS_H__
#define __QTIMPIMPRESIONCODIGOBARRAS_H__
#include <cstddef>
#include <ImpresionCodigoBarras.h>
#include <string.h>
#include <qprinter.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;

class QtImpImpresionCodigoBarras:public ImpresionCodigoBarras
{
Q_OBJECT
public:
	QtImpImpresionCodigoBarras(QWidget *pQWParent,
			  const char *pchrPtrName);

public:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaControles();
	void IniciaVariables();
	void ConsultandoProductosProveedor();
	void ConsultaProductosProveedor();
	void ConsultandoProductosFechaCompra();
	void ConsultaProductosFechaCompra();
	void ConsultandoProductosTodos();
	void ConsultaProductosTodos();
	void MuestraProductos();
	void ImprimeCodigosSeleccionados();

    void RegistrosParaImprimir(QTable *,
                               zSiscomRegistros *,
                               zSiscomRegistros *);
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegProductos;
	zSiscomRegistro *zSisProveedor;
    QPrinter *printer;
private slots:
	void SlotProveedor(zSiscomRegistro *);
	void SlotFechaCompra();
	void SlotTodosProductos();
    void SlotImprimirCodigos();
	void SlotImpresionTodaHoja();
    void SlotImprimirCodigosX8();
    void SlotCapturaCantidad(int pintFila,
                             int pintColumna,
                             int,
                             const QPoint &);
};



#endif
