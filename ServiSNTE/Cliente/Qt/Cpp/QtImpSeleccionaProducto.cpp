#include <QtImpSeleccionaProducto.h>
#include <QCtrlProductosSS.h>
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

#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtextedit.h> 
#include <qtable.h>
QtImpSeleccionaProducto::QtImpSeleccionaProducto(zSiscomConexion *pzSisConexion,
					         zSiscomRegistro *pzSisProveedor,
						 QWidget *pQWParent,
				     const char *pchrPtrName,
				     bool pbModal,
				     WFlags pWFlags):
				     SeleccionaProducto(pQWParent,pchrPtrName,pbModal,pWFlags),
				     zSisConexion(pzSisConexion),
				     zSisProveedor(pzSisProveedor),
				     zSisProducto(0)
{
 ConectaSlots();
 IniciaVariables();
 exec();

}

void QtImpSeleccionaProducto::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QCtrProductos,
		SIGNAL(SignalProducto(zSiscomRegistro *)),
		SLOT(SlotProducto(zSiscomRegistro *)));
	connect(QTProductos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotProducto(int ,int,int,const QPoint &)));

}
void QtImpSeleccionaProducto::SlotProducto(int pintNProducto,
						     int,
						     int,
						     const QPoint &)
{
	zSisProducto=(*QCtrProductos->Productos())[pintNProducto];
	zSiscomQt3::Foco(QPBAceptar);

}
void QtImpSeleccionaProducto::SlotProducto(zSiscomRegistro *pzSisProducto)
{
	zSisProducto=pzSisProducto;
	zSiscomQt3::Foco(QPBAceptar);
}
void QtImpSeleccionaProducto::SlotAceptar()
{
	intAceptar = 1;
	done(1);
}
void QtImpSeleccionaProducto::SlotCancelar()
{
	intAceptar = 0;
	done(1);
}
void QtImpSeleccionaProducto::reject()
{

}
void QtImpSeleccionaProducto::IniciaVariables()
{
  QCtrProductos->Servidor(zSisConexion);
  QCtrProductos->Proveedor(zSisProveedor);
  QCtrProductos->IniciaControl();
  MuestraProductosTabla();
}
zSiscomRegistro *QtImpSeleccionaProducto::Producto()
{
 return zSisProducto;
}
int QtImpSeleccionaProducto::Aceptar()
{
  return intAceptar;
}
void QtImpSeleccionaProducto::MuestraProductosTabla()
{
/*char *lchrPtrCampos[]={"ProdModelo",0}; */
const char *lchrPtrCampos[]={"numproducto","modelo","nombreproducto",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,QCtrProductos->Productos(),QTProductos);
QTProductos->adjustColumn(0);
}
