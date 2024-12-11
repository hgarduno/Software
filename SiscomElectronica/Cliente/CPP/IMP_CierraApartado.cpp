#include <IMP_CierraApartado.h>
#include <IMP_QControlFecha.h>
#include <IMP_AbonoAApartado.h>
#include <IMP_ComoPago.h>


#include <zOrdenes.h> 
#include <zOrdenVenta.h>
#include <zClienteSiscom.h>

#include <zApartado.h>
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <qpushbutton.h>
#include <qtable.h>
#include <qstring.h>

QCierraApartado::QCierraApartado(zSiscomConexion *pzSiscomConexion,
				 QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CierraApartado(pQWParent,pchrPtrName,pbModal,pWFlags),
				zSisConexion((zSiscomConexion *)pzSiscomConexion)
{
IniciaVariables();
ConectaSlots();
}

QCierraApartado::~QCierraApartado()
{

}

void QCierraApartado::ConectaSlots()
{
connect(QPBConsultar,SIGNAL(clicked()),SLOT(SlotConsulta()));   
connect(QTApartados,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionaApartado(int,int,int,const QPoint &)));
connect(QPBPagar,SIGNAL(clicked()),SLOT(SlotPagar()));
connect(QCtrFechaIni,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAFechaFin()));
connect(QCtrFechaFin,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAConsulta()));
connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar()));
connect(QPBAAApartado,SIGNAL(clicked()),SLOT(SlotAbonoAApartado()));
}
void QCierraApartado::SlotAbonoAApartado()
{
 AbonoAApartado();
}
void QCierraApartado::SlotCancelar()
{
	emit SignalCancelar();
}
void QCierraApartado::SlotFocoAConsulta()
{
  zSiscomQt3::Foco(QPBConsultar);
}
void QCierraApartado::SlotFocoAFechaFin()
{
  zSiscomQt3::Foco(QCtrFechaFin);
}
int QCierraApartado::ComoPago()
{
QComoPago lQCPago(zOrden);
if(lQCPago.ComoPague()==QComoPago::Efectivo)
 return 0;
 else
 if(lQCPago.ComoPague()==QComoPago::Transferencia)
 return 0;
 else
 if(lQCPago.ComoPague()==QComoPago::Cancelar)
  return 1;
}
void QCierraApartado::SlotPagar()
{
/* Falta integrar la forma de pago 
 *
 */
 if(!ComoPago())
 {
   QPBPagar->setEnabled(false);
  emit SignalPagar(zOrden); 
  Consultando();
 }
}

void QCierraApartado::SlotSeleccionaApartado(int pintFila,
					     int,
					     int,
					     const QPoint &)
{
   if(pintFila!=-1)
   {
    QTApartados->selectRow(pintFila); 
    /*
    zSisRegApartado=(*zSisRegsApartados)[pintFila];
    */
    zOrden=(zOrdenVenta *)(*zOrdsRegistradas)[pintFila];
    HabilitaDesHabilitaPagar();
    zSiscomQt3::Foco(QPBPagar);
    }
}
void QCierraApartado::SlotConsulta()
{
   Consultando();
}
void QCierraApartado::IniciaVariables()
{
QCtrFechaIni->ColocaFechaHoy();
QCtrFechaFin->ColocaFechaHoy();
zSiscomQt3::Foco(QCtrFechaIni);
Consultando();
}
void QCierraApartado::Consultando()
{
 Consulta();
 Muestra();
}
void QCierraApartado::Consulta()
{
zSiscomElectronica lzSisElecOrdenes(zSisConexion,"OrdenesVendidas2");
zOrdsRegistradas=lzSisElecOrdenes.Ordenes2((const char *)QCtrFechaIni->ObtenFecha(),
					   (const char *)QCtrFechaFin->ObtenFecha(),
					   "2");
}
void QCierraApartado::MuestraApartado(int pintApartado,
				      zOrdenVenta *pzOrden)
{
QTApartados->setText(pintApartado,0,pzOrden->IdVenta());
QTApartados->setText(pintApartado,1,pzOrden->Fecha());
QTApartados->setText(pintApartado,3,pzOrden->Apartado()->FechaHoraE());
QTApartados->setText(pintApartado,5,QString(pzOrden->Cliente()->Nombre())+
					    " " 			 +
					    pzOrden->Cliente()->APaterno());
QTApartados->setText(pintApartado,6,pzOrden->Apartado()->ACuenta());
QTApartados->setText(pintApartado,7,pzOrden->Apartado()->PorPagar());
}
void QCierraApartado::Muestra()
{
zOrdenVenta *lzOrden;
int lintContador=0;
QTApartados->setNumRows(zOrdsRegistradas->NNodos());
for(lzOrden=(zOrdenVenta *)zOrdsRegistradas->Primer(),
    lintContador=0;
    lzOrden;
    lzOrden=(zOrdenVenta *)zOrdsRegistradas->Siguiente(),
    lintContador++)
    MuestraApartado(lintContador,lzOrden);
}

void QCierraApartado::setFocus()
{
   zSiscomQt3::Foco(QCtrFechaIni);
}
void QCierraApartado::HabilitaDesHabilitaPagar()
{
bool lbolHabilita=zOrdsRegistradas ? 1 :0 ;
   QPBPagar->setEnabled(lbolHabilita);
   QPBAAApartado->setEnabled(lbolHabilita);
}
void QCierraApartado::closeEvent(QCloseEvent *)
{

}
void QCierraApartado::AbonoAApartado()
{
QAbonoAApartado lQAAApartado(zOrden);

}
