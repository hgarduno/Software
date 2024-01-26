#ifndef __QTIMPEXISTENCIASTIENDA_H__
#define __QTIMPEXISTENCIASTIENDA_H__
#include <ExistenciasTienda.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class QtImpExistenciasTienda:public ExistenciasTienda
{
Q_OBJECT
public:
	QtImpExistenciasTienda(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
	void Consultando();
	void Consulta();
	void ConsultandoExistenciaProducto(zSiscomRegistro *pzSisRegProducto);
	void ConsultandoExitenciaListaProductos(const char *pchrPtrListaProductos);
	void ConsultaExistenciaProducto(zSiscomRegistro *pzSisRegProducto);
	void Muestra();
	void ConsultandoExistenciasProveedor();
	void ConsultaExistenciasProveedor();
	void ConsultaExistenciasListaProductos(const char *pchrPtrListaProductos);
	int ExistenciasProveedor();
	void AgregandoTienda();
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProveedor;
	zSiscomRegistro *zSisRegProvYTienda;
	zSiscomRegistros *zSisRegsExistencias;
	zSiscomRegistro *zSisRegTienda;
	int intExistenciaProveedor;
private slots:
	void SlotSeleccionoProveedor(zSiscomRegistro *pzSisRegProveedor);
	void SlotExistenciasProveedor();
	void SlotExistenciasProducto();
	void SlotTienda(zSiscomRegistro *pzSisRegTienda);
	void SlotExistenciasListaProductos();
	void SlotCopiar();
	void SlotTodosLosProductos();
};

#endif
