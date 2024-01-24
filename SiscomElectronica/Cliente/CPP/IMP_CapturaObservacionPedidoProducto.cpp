#include <IMP_CapturaObservacionPedidoProducto.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qpushbutton.h>
#include <qtextedit.h>
QCapturaObservacionPedidoProducto::QCapturaObservacionPedidoProducto(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CapturaObservacionPedidoProducto(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				intAceptar(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapturaObservacionPedidoProducto::~QCapturaObservacionPedidoProducto()
{

}

void QCapturaObservacionPedidoProducto::ConectaSlots()
{
connect(QPBAceptar,
	SIGNAL(clicked()),
	SLOT(SlotAceptar()));
connect(QPBCancelar,
	SIGNAL(clicked()),
	SLOT(SlotCancelar()));

}
void QCapturaObservacionPedidoProducto::SlotAceptar()
{
intAceptar=1;
done(1);
}
void QCapturaObservacionPedidoProducto::SlotCancelar()
{
intAceptar=0;
done(2);
}
void QCapturaObservacionPedidoProducto::IniciaVariables()
{

}
void QCapturaObservacionPedidoProducto::reject()
{

}
int QCapturaObservacionPedidoProducto::Aceptar()
{
return intAceptar;
}
void QCapturaObservacionPedidoProducto::Observaciones(char *pchrPtrObservaciones)
{
    strcpy(pchrPtrObservaciones,SiscomDesarrollo3Qt::InformacionEdit(QTEObservaciones));
}
