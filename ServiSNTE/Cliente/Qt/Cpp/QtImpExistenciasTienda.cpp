#include <QtImpExistenciasTienda.h>
#include <QtImpSeleccionaProducto.h>
#include <QCtrlProveedoresSS.h>
#include <QCtrlTiendasEntrega.h>

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

QtImpExistenciasTienda::QtImpExistenciasTienda(QWidget *pQWParent,
					       const char *pchrPtrName):
					   ExistenciasTienda(pQWParent,pchrPtrName),
					   intExistenciaProveedor(1),
					   zSisRegTienda(0)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpExistenciasTienda::IniciaVariables()
{
 QCtrTiendas->Servidor(zSisConexion);
 QCtrProveedores->Servidor(zSisConexion);
 QCtrProveedores->IniciaControl();
 QCtrTiendas->IniciaControl();
/* Consultando(); */
 zSiscomQt3::Foco(QCtrTiendas);
}
void QtImpExistenciasTienda::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpExistenciasTienda::ConectaSlots()
{
connect(QCtrProveedores,
	SIGNAL(SignalProveedor(zSiscomRegistro *)),
	SLOT(SlotSeleccionoProveedor(zSiscomRegistro *)));
connect(QPBExistenciasProveedor,
	SIGNAL(clicked()),
	SLOT(SlotExistenciasProveedor()));
connect(QPBExistenciasProducto,
	SIGNAL(clicked()),
	SLOT(SlotExistenciasProducto()));
connect(QCtrTiendas,
	SIGNAL(SignalTienda(zSiscomRegistro *)),
	SLOT(SlotTienda(zSiscomRegistro *)));
connect(QPBExistenciasListaProductos,
	SIGNAL(clicked()),
	SLOT(SlotExistenciasListaProductos()));
connect(QPBTodosLosProductos,
	SIGNAL(clicked()),
	SLOT(SlotTodosLosProductos()));
}
void QtImpExistenciasTienda::SlotTodosLosProductos()
{
 Consultando();
}
void QtImpExistenciasTienda::SlotCopiar()
{

}
void QtImpExistenciasTienda::SlotExistenciasListaProductos()
{
  ConsultandoExitenciaListaProductos((const char *)QTEListaProductos->text());
}
void QtImpExistenciasTienda::SlotTienda(zSiscomRegistro *pzSisRegTienda)
{
	zSisRegTienda=pzSisRegTienda;
	zSiscomQt3::Foco(QCtrProveedores);
}
void QtImpExistenciasTienda::SlotExistenciasProveedor()
{
	intExistenciaProveedor=1;
}
void QtImpExistenciasTienda::SlotExistenciasProducto()
{
	intExistenciaProveedor=0;
}
void QtImpExistenciasTienda::SlotSeleccionoProveedor(zSiscomRegistro *pzSisRegProveedor)
{
zSiscomRegistro *lzSisRegProducto;
   zSisRegProveedor=pzSisRegProveedor;
  AgregandoTienda();
if(ExistenciasProveedor())
ConsultandoExistenciasProveedor();
else
{
QtImpSeleccionaProducto lQtImpSelProducto(zSisConexion,pzSisRegProveedor);
if((lzSisRegProducto=lQtImpSelProducto.Producto()))
{
  ConsultandoExistenciaProducto(lzSisRegProducto);
}
}
}
void QtImpExistenciasTienda::Consultando()
{
  Consulta();
  Muestra();
}
void QtImpExistenciasTienda::Consulta()
{
zOperacionesServiSNTE lzSisOpeServiSNTE(zSisConexion,"ExistenciasTienda");
zSisRegsExistencias=lzSisOpeServiSNTE.ExistenciasTienda(zSisRegTienda);
}
void QtImpExistenciasTienda::Muestra()
{
const char *lchrPtrCampos[]={"nombreproducto","modelo","idempresa","existencia","stock",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,zSisRegsExistencias,QTExistencias);
}
void QtImpExistenciasTienda::ConsultandoExistenciaProducto(zSiscomRegistro *pzSisRegProducto)
{
	ConsultaExistenciaProducto(pzSisRegProducto);
	Muestra();
}
void QtImpExistenciasTienda::ConsultaExistenciaProducto(zSiscomRegistro *pzSisRegProducto)
{
zOperacionesServiSNTE lzSisOpeServiSNTE(zSisConexion,"ExistenciasProductoTienda");
zSisRegsExistencias=lzSisOpeServiSNTE.ExistenciaTiendaProducto(zSisRegTienda,pzSisRegProducto);
}
void QtImpExistenciasTienda::ConsultandoExistenciasProveedor()
{
  ConsultaExistenciasProveedor();
  Muestra();
}
void QtImpExistenciasTienda::ConsultaExistenciasProveedor()
{

zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"ExistenciasTiendaProveedor"); 
AgregandoTienda();
zSisRegsExistencias=lzOpeServiSNTE.ExistenciasTiendaProveedor(zSisRegProvYTienda);
}
int QtImpExistenciasTienda::ExistenciasProveedor()
{
   return intExistenciaProveedor;
}
void QtImpExistenciasTienda::AgregandoTienda()
{
 zSisRegProvYTienda=new zSiscomRegistro;
    (*zSisRegProvYTienda)=*zSisRegProveedor;
  if(zSisRegTienda)
    (*zSisRegProvYTienda) << new zSiscomCampo("IdTienda",(*zSisRegTienda)["idtienda"]);
  else
    (*zSisRegProvYTienda) << new zSiscomCampo("IdTienda");

}

void QtImpExistenciasTienda::ConsultandoExitenciaListaProductos(const char *pchrPtrListaProductos)
{
	ConsultaExistenciasListaProductos(pchrPtrListaProductos);
	Muestra();

}
void QtImpExistenciasTienda::ConsultaExistenciasListaProductos(const char *pchrPtrListaProductos)
{
const char *lchrPtrIdTienda;
zOperacionesServiSNTE lzSisOpeServiSNTE(zSisConexion,"ExistenciasTiendaListaProductos");
lchrPtrIdTienda= zSisRegTienda ? (const char *)(*zSisRegTienda)["idtienda"] :(const char *)0;
zSisRegsExistencias=lzSisOpeServiSNTE.ExistenciasTiendaListaProductos(lchrPtrIdTienda,
									pchrPtrListaProductos);
}
