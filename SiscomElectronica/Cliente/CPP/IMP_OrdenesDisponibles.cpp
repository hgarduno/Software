#include <IMP_OrdenesDisponibles.h>
#include <zOrdenes.h>
#include <zOrdenVenta.h>
#include <zClienteSiscom.h>
#include <zExpendio.h>
#include <zConexionExpendio.h>
#include <zSiscomQt3.h>
#include <qtable.h>
#include <qpushbutton.h>
QOrdenesDisponibles::QOrdenesDisponibles(zOrdenes *pzOrdenes,
				        char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				OrdenesDisponibles(pQWParent,pchrPtrName,pbModal,pWFlags),
				chrPtrArgumentos(pchrPtrArgumentos),
				zOrdsVenta(pzOrdenes)
{
IniciaVariables();
ConectaSlots();
exec();
}

QOrdenesDisponibles::~QOrdenesDisponibles()
{

}

void QOrdenesDisponibles::ConectaSlots()
{
connect(QTDatos,
	SIGNAL(doubleClicked(int,int,int,const QPoint &)),
	SLOT(SlotOrden(int,int,int,const QPoint &)));
connect(QTDatos,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionando(int,int,int,const QPoint &)));
connect(QTDatos,
	SIGNAL(currentChanged(int,int)),
	SLOT(SlotSeleccionando(int,int)));
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
}
void QOrdenesDisponibles::SlotAceptar()
{
   done(1); 
}
void QOrdenesDisponibles::SlotSeleccionando(int pintOrden,
					    int)
{
    SlotSeleccionando(pintOrden,0,0,QPoint());
}
void QOrdenesDisponibles::SlotSeleccionando(int pintOrden,
					    int,
					    int,
					    const QPoint &)
{
   zOrVenta=(zOrdenVenta *)(*zOrdsVenta)[pintOrden];
   if(zOrVenta->Productos())
   MuestraDetalle();
   else
	QTDetalle->setNumRows(0);
  zSiscomQt3::Foco(QPBAceptar);
}
void QOrdenesDisponibles::SlotOrden(int pintOrden,
				    int,
				    int,
				    const QPoint &)
{
   zOrVenta=(zOrdenVenta *)(*zOrdsVenta)[pintOrden];
   SiscomRegistroLog2(zOrVenta->Expendio());
   done(1);

}
void QOrdenesDisponibles::IniciaVariables()
{
Muestra();
Mostrando(0);
}
void QOrdenesDisponibles::Muestra()
{
zOrdenVenta *lzOrden;
zSiscomRegistro *lzSisRegEscuela;
int lintContador;
QTDatos->setNumRows(zOrdsVenta->NNodos());
for(lzOrden=(zOrdenVenta *)zOrdsVenta->Primer(),
    lintContador=0;
    lzOrden;
    lzOrden=(zOrdenVenta *)zOrdsVenta->Siguiente(),
    lintContador++)
{
   QTDatos->setText(lintContador,0,lzOrden->ImporteOrden());
   QTDatos->setText(lintContador,1,lzOrden->Cliente()->Escuela());
   QTDatos->setText(lintContador,2,lzOrden->Expendio()->RazonSocial());
}
zSiscomQt3::AjustaColumnasTabla(QTDatos);
}
void QOrdenesDisponibles::MuestraDetalle()
{
zSiscomRegistros *lzSisRegsProductos=zOrVenta->Productos();
const char *lchrPtrCampos[]={"Cantidad","Clave","Precio","Importe",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,lzSisRegsProductos,QTDetalle);
zSiscomQt3::AjustaColumnasTabla(QTDetalle);
}
zOrdenVenta *QOrdenesDisponibles::Orden()
{
  return zOrVenta;
}
void QOrdenesDisponibles::reject()
{
   zOrVenta=(zOrdenVenta *)(*zOrdsVenta)[0];
   QDialog::reject();
}

void QOrdenesDisponibles::Mostrando(int pintOrden)
{
   
   zOrVenta=(zOrdenVenta *)(*zOrdsVenta)[pintOrden];
   if(zOrVenta->Productos())
   MuestraDetalle();
}
