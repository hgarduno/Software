#include <QtInventarioBodega4.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>
#include <zSiscomDesarrollo4.h>
#include <zExistenciaBodega.h>
#include <QCtrlProductosSE.h>
#include <zBodega.h>

#include <qtextedit.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qtable.h>
QtInventarioBodega4::QtInventarioBodega4(QWidget *pQWParent,
					 const char *pchrPtrName,
					 WFlags pWFlags):
			InventarioBodega4(pQWParent,pchrPtrName,pWFlags)
{
 setEnabled(false);

}
void QtInventarioBodega4::Conexion(zSiscomConexion *pzSisConexion)
{
   zSisConexion=pzSisConexion;
}
void QtInventarioBodega4::IniciaVariables()
{
  IniciandoVariables();
  IniciaControl();
  ConectaSlots();
  zSiscomQt3::Foco(QCtrProductos);
}
void QtInventarioBodega4::IniciandoVariables()
{
  zExistenciaB=new zExistenciaBodega(); 
}
void QtInventarioBodega4::IniciaControl()
{
  QCtrProductos->Servidor(zSisConexion);
  QCtrProductos->IniciaControl();
}
void QtInventarioBodega4::ConectaSlots()
{
connect(QCtrProductos,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotProducto(zSiscomRegistro *)));
connect(QLECantidad,SIGNAL(returnPressed()),SLOT(SlotCantidad()));
connect(QPBActualiza,SIGNAL(clicked()),SLOT(SlotActualiza()));
}
void QtInventarioBodega4::SlotActualiza()
{
   Actualizando();
   AgregaProductoActualizado();
   zSiscomQt3::Foco(QCtrProductos);
}
void QtInventarioBodega4::SlotCantidad()
{
 ExistenciaBodega()->Cantidad((const char *)QLECantidad->text()); 
 zSiscomQt3::Foco(QPBActualiza);
}
void QtInventarioBodega4::SlotProducto(zSiscomRegistro *pzSisRegProducto)
{
  AsignaProducto(pzSisRegProducto);
  MuestraProducto(pzSisRegProducto); 
  MostrandoExistencia();
  zSiscomQt3::Foco(QLECantidad);
}
void QtInventarioBodega4::Actualizando()
{

}
void QtInventarioBodega4::AgregaProductoActualizado()
{
int lintNProductos=QTDatos->numRows();  
QTDatos->setNumRows(lintNProductos+1);
QTDatos->setText(lintNProductos,0,Bodega()->Bodega());
QTDatos->setText(lintNProductos,1,ExistenciaBodega()->Producto());
QTDatos->setText(lintNProductos,2,ExistenciaBodega()->Cantidad());
QTDatos->setText(lintNProductos,3,ExistenciaBodega()->Existencia());

zSiscomQt3::AjustaColumnasTabla(QTDatos);
}
void QtInventarioBodega4::AsignaProducto(zSiscomRegistro *pzSisRegProducto)
{
 ExistenciaBodega()->Producto((const char *)(*pzSisRegProducto)["cveproducto"]);
}
void QtInventarioBodega4::MuestraProducto(zSiscomRegistro *pzSisRegProducto)
{
QTEDescripcion->setText((const char *)(*pzSisRegProducto)["dscproducto"]);
}
void QtInventarioBodega4::Bodega(zBodega *pzBodegaE)
{
   zBodegaE=pzBodegaE;
   ExistenciaBodega()->Bodega(zBodegaE);
}
zSiscomConexion *QtInventarioBodega4::Conexion()
{
   return zSisConexion;
}
zBodega *QtInventarioBodega4::Bodega()
{
	return zBodegaE;
}
void QtInventarioBodega4::Argumentos(char **pchrPtrArgumentos)
{
   chrPtrArgumentos=pchrPtrArgumentos;
}
zExistenciaBodega *QtInventarioBodega4::ExistenciaBodega()
{
    return zExistenciaB;
}
void QtInventarioBodega4::MostrandoExistencia()
{
  ConsultandoExistencia();
  MuestraExistencia();
}
void QtInventarioBodega4::ConsultandoExistencia()
{

}
void QtInventarioBodega4::MuestraExistencia()
{
 QLEExistencia->setText(ExistenciaBodega()->Existencia());
}
void QtInventarioBodega4::FocoAProductos()
{
  zSiscomQt3::Foco(QCtrProductos);
}
