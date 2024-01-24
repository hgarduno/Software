#include <IMP_EstadosPedido.h>
#include <IMP_QControlFecha.h>

#include <zSiscomElectronica.h>
#include <zOrdenes.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <qpushbutton.h>

QEstadosPedido::QEstadosPedido(zSiscomConexion *pzSiscomConexion,
			      QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				EstadosPedido(pQWParent,pchrPtrName,pbModal,pWFlags),
				zSisConexion((zSiscomConexion *)pzSiscomConexion)

{

IniciaVariables();
ConectaSlots();
exec();
}

QEstadosPedido::~QEstadosPedido()
{

}

void QEstadosPedido::ConectaSlots()
{
connect(QPBConsulta,SIGNAL(clicked()),SLOT(SlotConsulta()));

}
void QEstadosPedido::SlotConsulta()
{
  ConsultandoPedidos();
}
void QEstadosPedido::IniciaVariables()
{
QCtrFechaInicio->ColocaFechaHoy();
QCtrFechaFin->ColocaFechaHoy();
ConsultandoPedidos();
}
void QEstadosPedido::ConsultandoPedidos()
{
Consulta();
Muestra();

}
void QEstadosPedido::Consulta()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"OrdenesVendidas2");
zOrdenesS=lzSisElectronica.Ordenes2((const char *)QCtrFechaInicio->ObtenFecha(),
				    (const char *)QCtrFechaFin->ObtenFecha(),
				    "4");
}
void QEstadosPedido::Muestra()
{
   SiscomRegistrosLog(zOrdenesS);
}
void QEstadosPedido::reject()
{

}
