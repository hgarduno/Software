#ifndef __QTIMPEXISTENCIASALMACEN_H__
#define __QTIMPEXISTENCIASALMACEN_H__
#include <ExistenciasAlmacen.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class QtImpExistenciasAlmacen:public ExistenciasAlmacen
{
Q_OBJECT
public:
	QtImpExistenciasAlmacen(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
	void Consultando();
	void Consulta();

	void ConsultandoExistenciaProducto(zSiscomRegistro *pzSisRegProducto);
	void ConsultandoExistenciasProveedor();
	void ConsultandoExistenciasListaProductos(const char *pchrPtrListaProductos);
	void ConsultaExistenciasProveedor();
	void ConsultaExistenciaProducto(zSiscomRegistro *pzSisRegProducto);
	void ConsultaExistenciasListaProductos(const char *pchrPtrListaProductos);

	void Muestra();
	int ExistenciasProveedor();

private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProveedor;
	zSiscomRegistros *zSisRegsExistencias;
	int intExistenciasProveedor;
private slots:
	void SlotSeleccionoProveedor(zSiscomRegistro *pzSisRegProveedor);
	void SlotExistenciasProveedor();
	void SlotExistenciasProducto();
	void SlotExistenciasListaProductos();
};

#endif
