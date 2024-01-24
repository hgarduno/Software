#include <IMP_CierraApartado.h>
#include <IMP_QControlFecha.h>


#include <zOrdenes.h> 
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <qpushbutton.h>
#include <qtable.h>

QCierraApartado::QCierraApartado(zSiscomConexion *pzSiscomConexion,
				 QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CierraApartado(pQWParent,pchrPtrName,pbModal,pWFlags),
				zSisConexion((zSiscomConexion *)pzSiscomConexion),
				zSisRegApartado(0)
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
void QCierraApartado::SlotPagar()
{
  zSisRegApartado->ActualizaCampo("formapago",(const unsigned char *)"0");
  QPBPagar->setEnabled(false);
  emit SignalPagar(zSisRegApartado); 
 Consultando();
}

void QCierraApartado::SlotSeleccionaApartado(int pintFila,
					     int,
					     int,
					     const QPoint &)
{
   if(pintFila!=-1)
   {
    QTApartados->selectRow(pintFila); 
    zSisRegApartado=(*zSisRegsApartados)[pintFila];
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
zSiscomElectronica lzSisElectronica(zSisConexion,"OrdenesApartados");
zSisRegsApartados=lzSisElectronica.Apartados((const char *)QCtrFechaIni->ObtenFecha(),
			   		      (const char *)QCtrFechaFin->ObtenFecha());
}
void QCierraApartado::Muestra()
{
const char *lchrPtrCampos[]={"idventa",
			    "fechahora",
			    "horapedido",
			    "fechaentrega",
			    "horaentrega",
			    "nombre",
			    "acuenta",
			    "porpagar",
			    0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,
			zSisRegsApartados,
			QTApartados);
}

void QCierraApartado::setFocus()
{
   zSiscomQt3::Foco(QCtrFechaIni);
}
void QCierraApartado::HabilitaDesHabilitaPagar()
{
   QPBPagar->setEnabled(zSisRegApartado ? 1 : 0);
}
void QCierraApartado::closeEvent(QCloseEvent *)
{

}
