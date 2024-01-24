#include <IMP_SeleccionandoProducto.h>

#include <QCtrlProductosSE.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <qpushbutton.h>
#include <qtextedit.h>

QSeleccionandoProducto::QSeleccionandoProducto(QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				SeleccionandoProducto(pQWParent,pchrPtrName,pbModal,pWFlags),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				intAceptar(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QSeleccionandoProducto::~QSeleccionandoProducto()
{

}

void QSeleccionandoProducto::ConectaSlots()
{
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar()));
connect(QCtrProductos,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotSeleccionoProducto(zSiscomRegistro *)));
}
void QSeleccionandoProducto::SlotSeleccionoProducto(zSiscomRegistro *pzSisRegProducto)
{
   zSisRegProducto=pzSisRegProducto;
   MuestraDescripcion(zSisRegProducto);
   zSiscomQt3::Foco(QPBAceptar);
}
void QSeleccionandoProducto::SlotAceptar()
{
   intAceptar=1;
   done(1);
}
void QSeleccionandoProducto::SlotCancelar()
{
   intAceptar=0;
   done(1);
}

void QSeleccionandoProducto::IniciaVariables()
{
QCtrProductos->Servidor(zSisConexion);
QCtrProductos->IniciaControl();
}
void QSeleccionandoProducto::reject()
{
}
int QSeleccionandoProducto::Aceptar()
{
   return intAceptar;
}
zSiscomRegistro *QSeleccionandoProducto::Producto()
{
    return zSisRegProducto;
}
void QSeleccionandoProducto::MuestraDescripcion(zSiscomRegistro *pzSisRegProducto)
{
	QTEDescripcion->setText((const char *)(*pzSisRegProducto)["dscproducto"]);
}
