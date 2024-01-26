#include <QtImpExistenciasAlmacen.h>
#include <QtImpSeleccionaProducto.h>
#include <QCtrlProveedoresSS.h>

#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <zOperacionesServiSNTE.h>
#include <qpushbutton.h>
#include <qtextedit.h>
QtImpExistenciasAlmacen::QtImpExistenciasAlmacen(QWidget *pQWParent,
					       const char *pchrPtrName):
					   ExistenciasAlmacen(pQWParent,pchrPtrName),
					   intExistenciasProveedor(0)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpExistenciasAlmacen::IniciaVariables()
{
 QCtrProveedores->Servidor(zSisConexion);
 /*QCtrProveedores->IniciaControlPorClave(); */
 QCtrProveedores->IniciaControl();
 Consultando();
}
void QtImpExistenciasAlmacen::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpExistenciasAlmacen::ConectaSlots()
{
connect(QCtrProveedores,
	SIGNAL(SignalProveedor(zSiscomRegistro *)),
	SLOT(SlotSeleccionoProveedor(zSiscomRegistro *)));
connect(QPBExistenciasProveedor,
	SIGNAL(clicked()),
	SLOT(SlotExistenciasProveedor()));
connect(QPBPorProducto,
	SIGNAL(clicked()),
	SLOT(SlotExistenciasProducto()));
connect(QPBExistenciasListaProductos,
	SIGNAL(clicked()),
	SLOT(SlotExistenciasListaProductos()));
}
void QtImpExistenciasAlmacen::SlotExistenciasListaProductos()
{
   LogSiscom("%s",(const char *)QTEListaProductos->text());
   ConsultandoExistenciasListaProductos((const char *)QTEListaProductos->text());
}
void QtImpExistenciasAlmacen::SlotExistenciasProveedor()
{
  intExistenciasProveedor=1;
  zSiscomQt3::Foco(QCtrProveedores);
}

void QtImpExistenciasAlmacen::SlotExistenciasProducto()
{
	intExistenciasProveedor=0;
}
void QtImpExistenciasAlmacen::SlotSeleccionoProveedor(zSiscomRegistro *pzSisRegProveedor)
{
zSiscomRegistro *lzSisRegProducto;
zSisRegProveedor=pzSisRegProveedor;
if(ExistenciasProveedor())
ConsultandoExistenciasProveedor();
else
{
QtImpSeleccionaProducto lQtImpSelProducto(zSisConexion,pzSisRegProveedor);
if((lzSisRegProducto=lQtImpSelProducto.Producto()))
  ConsultandoExistenciaProducto(lzSisRegProducto);
}
}
void QtImpExistenciasAlmacen::Consultando()
{
  Consulta();
  Muestra();
}
void QtImpExistenciasAlmacen::ConsultandoExistenciasListaProductos(const char *pchrPtrLista)
{
   ConsultaExistenciasListaProductos(pchrPtrLista);
   Muestra();
}
void QtImpExistenciasAlmacen::Consulta()
{
zOperacionesServiSNTE lzSisOpeServiSNTE(zSisConexion,"ExistenciasAlmacen");
zSisRegsExistencias=lzSisOpeServiSNTE.ExistenciasAlmacen();
}
void QtImpExistenciasAlmacen::ConsultaExistenciasListaProductos(const char *pchrPtrListaProductos)
{
zOperacionesServiSNTE lzSisOpeServiSNTE(zSisConexion,"ExistenciasAlmacenListaProductos");
zSisRegsExistencias=lzSisOpeServiSNTE.ExistenciasAlmacenListaProductos(pchrPtrListaProductos);
}

void QtImpExistenciasAlmacen::Muestra()
{
const char *lchrPtrCampos[]={"nombreproducto","modelo","idempresa","existencia",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,zSisRegsExistencias,QTExistencias);
}
void QtImpExistenciasAlmacen::ConsultandoExistenciaProducto(zSiscomRegistro *pzSisRegProducto)
{
	ConsultaExistenciaProducto(pzSisRegProducto);
	Muestra();
}
void QtImpExistenciasAlmacen::ConsultaExistenciaProducto(zSiscomRegistro *pzSisRegProducto)
{
zOperacionesServiSNTE lzSisOpeServiSNTE(zSisConexion,"ExistenciasProductoAlmacen");
zSisRegsExistencias=lzSisOpeServiSNTE.ExistenciaAlmacenProducto(pzSisRegProducto);
}
int QtImpExistenciasAlmacen::ExistenciasProveedor()
{
	return intExistenciasProveedor ;
}
void QtImpExistenciasAlmacen::ConsultandoExistenciasProveedor()
{
   ConsultaExistenciasProveedor();
   Muestra();
}
void QtImpExistenciasAlmacen::ConsultaExistenciasProveedor()
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"ExistenciasAlmacenProveedor"); 
zSisRegsExistencias=lzOpeServiSNTE.ExistenciasAlmacenProveedor(zSisRegProveedor);
}
