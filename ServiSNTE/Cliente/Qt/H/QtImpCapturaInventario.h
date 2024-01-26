#ifndef __QTIMPCAPTURAINVENTARIO_H__
#define __QTIMPCAPTURAINVENTARIO_H__
#include <cstddef>
#include <CapturaInventario.h>
#include <zProductos.h>

class zSiscomConexion;
class zSiscomRegistro;
class zInventario;

class QtImpCapturaInventario:public CapturaInventario
{
Q_OBJECT
public:
	QtImpCapturaInventario(QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  WFlags pWFlags=false);

private:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaControles();
	void ProductosProveedor();
	void IniciaVariables();
	void IniciaCaptura();
	void Reinicia();
    void AnexaProductoInventario();
	void ProductoPorProveedor();
	void FocoAProductos();
	void HabilitaCantidad();
	void MuestraProductos();
	void AgregaPorCodigoBarras(zSiscomRegistro *);
	void ConsultaCodigoBarras();
	void ConsultandoCodigoBarras();
	void RegistraInventario();
	void VerificaInventario();
    void RecuperaInventario();
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisProveedor;
	zSiscomRegistro *zSisProducto;
	zSiscomRegistro *zInventarioEnCurso;
    zProductos zProductosI;
	zInventario *zInventarioP;

private slots:
	void SlotProveedor(zSiscomRegistro *pzSisProveedor);
	void SlotProducto(zSiscomRegistro *pzSisProducto);
	void SlotFocoAAnexar();
	void SlotAnexar();
	void SlotProgramarInventario();
	void SlotProductoPorCodigoBarras();
	void SlotRegistraInventario();
    void SlotCapturaCantidad(int,
                             int,
                             int,
                             const QPoint &);
};

#endif
