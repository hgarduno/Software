#ifndef __QTIMPMANTENIMIENTOPRODUCTOS_H__
#define __QTIMPMANTENIMIENTOPRODUCTOS_H__
#include <MantenimientoProductos.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zCosto;
class zDescuento;
class zPrecio;
class zProducto;
class QtImpMantenimientoProductos:public MantenimientoProductos
{
Q_OBJECT
public:
	QtImpMantenimientoProductos(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProveedor;
	zSiscomRegistro *zSisRegDepartamento;
	zCosto *zCostoP;
	zDescuento *zDescuentoP;
	zPrecio *zPrecioP;
	zPrecio *zPrecioForaneo;
	QString QStrNumProducto;
private:
	void MuestraProveedor();
	void Costo();
	void Precios();
	void CalculaCostoPrecio();
	void CalculaPrecios();
	void MuestraCalculoCosto();
	void Descuentos();
	void CalculandoCosto();
	void CalculandoPrecios();
	void MostrandoPrecios();
	void CalculandoPorcentajeGanancia(const char *pchrPtrPrecio,char *pchrPtrGanancia);
	void CalculaPorcentajeGanancia(const char *pchrPtrPrecio,char *pchrPtrGanancia);
	void Registrando();
	void Registra();
	zProducto *Producto();
	void ProductosProveedor();

private slots:
		void SlotProveedor(zSiscomRegistro *pzSisRegProveedor);
		void SlotDepartamento(zSiscomRegistro *pzSisRegDepartamento);
		void SlotFocoANombreProducto();
		void SlotFocoAModelo();
		void SlotFocoAPrecio();
		void SlotFocoAIva();
		void SlotFocoADepartamento();
		void SlotFocoAPorUtilidad();
		void SlotFocoAPrecioForaneo();
		void SlotFocoAPorUtilidadForaneo();
		void SlotFocoADescuento1();
		void SlotFocoADescuento2();
		void SlotFocoADescuento3();
		void SlotFocoADescuento4();
		void SlotUtilidad();
		void SlotGananciaPrecioForaneo();
		void SlotRegistrar();
		void SlotFocoARegistrar();
		void SlotNuevoProducto(const QString &);
};

#endif
