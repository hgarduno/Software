#include <QCtrlProductosSS.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>

#include <stdlib.h>

QCtrlProductosSS::QCtrlProductosSS( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegProducto(0),
    zSisRegProductosSS(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlProductosSS::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBProducto=new QComboBox(this);
	QHBLayout->addWidget(QCBProducto);
	QLEProducto=zSiscomQt3::EditAlCombo(QCBProducto,"QLEProducto");
	QCBProducto->setAutoCompletion(true);
	QCBProducto->setDuplicatesEnabled(false);
	QCBProducto->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlProductosSS::MuestraProductosDescripcion()
{
zSiscomQt3::RegistrosAlCombo(QCBProducto,"ProdModelo",zSisRegProductosSS);
}
void QCtrlProductosSS::MuestraProductosNumeroProducto()
{
zSiscomQt3::RegistrosAlCombo(QCBProducto,"numproducto",zSisRegProductosSS);
}
void QCtrlProductosSS::IniciaControl()
{
const char *lchrPtrPorClave;
	ConsultaProducto();
  if((lchrPtrPorClave=getenv("ProveedorPorClave")))
  MuestraProductosNumeroProducto();
  else
  MuestraProductosDescripcion();

}
void QCtrlProductosSS::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlProductosSS::ConsultaProducto()
{
zOperacionesServiSNTE lzSisOpProductosSS(zSisConexion,"Productos");
if((zSisRegProductosSS=lzSisOpProductosSS.ProductosSS(zSisProveedor)))
{
}
else
LogSiscom("NO hay productos aun");
}
void QCtrlProductosSS::ConectaSlots()
{
connect(QCBProducto,
	SIGNAL(activated(int )),
	SLOT(SlotProducto(int)));
connect(QLEProducto,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturo()));
connect(QLEProducto,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoProducto(const QString &)));
}
void QCtrlProductosSS::SlotCapturandoProducto(const QString &pQStrProducto)
{
	if(pQStrProducto.isEmpty())
	emit SignalProductoVacia();
}
void QCtrlProductosSS::SlotProducto(int pintProducto)
{
  zSisRegProducto=(*zSisRegProductosSS)[pintProducto];
  SiscomRegistroLog2(zSisRegProducto);
}
void QCtrlProductosSS::SlotCapturo()
{
if(zSisRegProducto)
{
emit SignalProducto(zSisRegProducto);
zSisRegProducto=0;
}
else
{
LogSiscom("La Producto No existe, se registra");
emit SignalNuevoProducto(QLEProducto->text());
}
}
void QCtrlProductosSS::setFocus()
{
   zSiscomQt3::Foco(QLEProducto); 
   QLEProducto->selectAll();
}

const char *QCtrlProductosSS::Producto()
{
return  (const char *)QLEProducto->text();
}

void QCtrlProductosSS::keyPressEvent(QKeyEvent *pQKPTecla)
{
/* Copiado aqui el Miercoles 17 de diciembre del 2014
 * Domingo 31 Julio del 2011
 * Se buscara integrar una ventana para la busqueda de los
 * alumnos, al momento de presionar F1, ya que si por alguna
 * razon, el nombre que se capturo, tiene alguna variacion 
 * en la busqueda del alumno este no se podra obtener de 
 * manera correcta, la idea de integrarlo en el contro
 * tiene que ver con el hecho de que entodos los lugares
 * en los que se use el control se tenga acceso a esta 
 * funcionalidad
 */
  if(pQKPTecla->key()==Qt::Key_F1)
  {

  }
}

void QCtrlProductosSS::ReIniciaControl()
{
   if(zSisRegProductosSS)
   zSisRegProductosSS->Libera();
   QCBProducto->clear();
   /*IniciaControl(); */
}
void QCtrlProductosSS::Proveedor(zSiscomRegistro *pzSisProveedor)
{
	zSisProveedor=pzSisProveedor;
}
zSiscomRegistros *QCtrlProductosSS::Productos()
{
	SiscomRegistrosLog(zSisRegProductosSS);
	return zSisRegProductosSS;
}
