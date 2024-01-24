#include <IMP_CorteCaja.h>
#include <IMP_CapturaRangoFechas.h>
#include <IMP_CapturaDenominacion.h>
#include <CQSis3QtComunes.h>
#include <CQSisCorteCaja.h>
#include <CQSisVentasPorCaja.h>
#include<SISCOMComunicaciones++.h>
#include <SiscomDesarrollo3Qt++.h>
QCorteCaja *InstanciaCorteCaja(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QCorteCaja((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QCorteCaja::QCorteCaja(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				CorteCaja(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QCorteCaja::~QCorteCaja()
{

}
void QCorteCaja::IniciaVariables()
{
VentasPorCaja();
}
void QCorteCaja::ConectaSlots()
{
connect(QPBRangoFechas,
	SIGNAL(clicked()),
	SLOT(SlotRangoFechas()));
connect(QPBADenominacion,
	SIGNAL(clicked()),
	SLOT(SlotAgregaDenominacion()));
connect(QTVentasPorCaja,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionandoCaja(int,int,int,const QPoint &)));
connect(QPBEDenominacion,
	SIGNAL(clicked()),
	SLOT(SlotEliminaDenominacion()));
connect(QTCorteCaja,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionandoDenominacion(int,int,int,const QPoint &)));
connect(QBPRegistrarCaja,
	SIGNAL(clicked()),
	SLOT(SlotRegistraCorteCaja()));
connect(QPBActualizar,
	SIGNAL(clicked()),
	SLOT(SlotActualizar()));

}
void QCorteCaja::SlotActualizar()
{
	VentasPorCaja();
}
void QCorteCaja::SlotRegistraCorteCaja()
{
CQSisOpCorteCaja lCQSOCorteCaja(SisDatCom);

	lCQSOCorteCaja.RegistraCorteCaja(&SisReg3LstCorteCaja);
	SisReg3LstCorteCaja.SiscomElimina();
	QTCorteCaja->setNumRows(0);
	VentasPorCaja();
	QBPRegistrarCaja->setEnabled(false);
	QPBEDenominacion->setEnabled(false);
	QPBADenominacion->setEnabled(false);
}
void QCorteCaja::SlotSeleccionandoDenominacion(int pintNFila,
					       int,
					       int,
					       const QPoint &)
{
	QTCorteCaja->selectRow(pintNFila);
	SisReg3Denominacion=SisReg3LstCorteCaja[pintNFila];
	  QPBEDenominacion->setEnabled(true);
}
void QCorteCaja::SlotEliminaDenominacion()
{
	if(SisReg3Denominacion)
	{
	  SisReg3LstCorteCaja.remove(SisReg3Denominacion);
	  if(SisReg3LstCorteCaja.count())
	  {
   	  CalculoImporte();
          MuestraCalculoImporte();
	  QPBEDenominacion->setEnabled(false);
	  }
	  else
	  QTCorteCaja->setNumRows(0);
	}
}
void QCorteCaja::SlotSeleccionandoCaja(int pintNFila,
				       int,
				       int ,
				       const QPoint &)
{
QTVentasPorCaja->selectRow(pintNFila);
SisReg3Caja=SisReg3VentasCaja[pintNFila];
QPBADenominacion->setEnabled(true);
}
void QCorteCaja::SlotAgregaDenominacion()
{
char lchrArrDenominacion[12];
char lchrArrCantidad[12];
QCapturaDenominacion lQCDenominacion(SisDatCom,
				     chrPtrArgumentos);
if(lQCDenominacion.Opcion())
{
   lQCDenominacion.DatosDenominacion(lchrArrDenominacion,
   				     lchrArrCantidad);
   SisReg3LstCorteCaja << RegistroCorte(lchrArrDenominacion,
   					lchrArrCantidad);
   CalculoImporte();
   MuestraCalculoImporte();
}
QBPRegistrarCaja->setEnabled(SisReg3LstCorteCaja.count());
QPBEDenominacion->setEnabled(SisReg3LstCorteCaja.count());
}
void QCorteCaja::SlotRangoFechas()
{
QCapturaRangoFechas lQCRangoFechas;
if(lQCRangoFechas.ObtenOpcion())
{
lQCRangoFechas.ObtenRangoFechas(chrArrFechaIni,
				chrArrFechaFin);
VentasPorCaja();
}
}
void QCorteCaja::AgregaDenominacion(const char *pchrPtrDenominacion,
				    const char *pchrPtrCantidad)
{
}
CQSisCorteCaja *QCorteCaja::RegistroCorte(const char *pchrPtrDenominacion,
					  const char *pchrPtrCantidad)
{
CQSisCorteCaja *lCQSCorteCaja;
lCQSCorteCaja=new CQSisCorteCaja((*SisReg3Caja)["idcaja"],
				 "",
				 "",
				 pchrPtrDenominacion,
				 pchrPtrCantidad,
				 chrPtrArgumentos[1],
				 (*SisReg3Caja)["totalencaja"],
				 chrPtrArgumentos[0],
				 "");
return lCQSCorteCaja;
}
void QCorteCaja::VentasPorCaja()
{
CQSisOpVentaCaja lCQOVentaCaja(SisDatCom);
SisReg3VentasCaja.clear();
lCQOVentaCaja.VentasPorCaja(chrArrFechaIni,
			    chrArrFechaFin,
			    chrPtrArgumentos[0],
			    &SisReg3VentasCaja);
const char *lchrArrCamposM[]={"edoreporte",
			"descripcion",
			"totalventas",
			"validacion",
			"importeinicial",
			"totalencaja",
			"totalcorte",
			0
			};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrArrCamposM,
				       QTVentasPorCaja,
				       &SisReg3VentasCaja);
SiscomDesarrollo3Qt::AjustaColumnas(QTVentasPorCaja);
}

void QCorteCaja::CalculoImporte()
{
CQSisOpCorteCaja lCQSOpCorteCaja(SisDatCom);
lCQSOpCorteCaja.ImporteDenominacion(&SisReg3LstCorteCaja);
}
void QCorteCaja::MuestraCalculoImporte()
{
const char *lchrPtrCamposM[]={"Denominacion",
			"Cantidad",
			"Importe",
			0
			};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCamposM,
				       QTCorteCaja,
				       &SisReg3LstCorteCaja);
SiscomDesarrollo3Qt::AjustaColumnas(QTCorteCaja);
QLCDTotal->display(TotalCorte());
QLCDTotalEnCaja->display(TotalEnCaja());
}

const char *QCorteCaja::TotalCorte()
{
int lintUltimo=SisReg3LstCorteCaja.count()-1;
CQSisCorteCaja *lCQSisCorteCaja;
	lCQSisCorteCaja=(CQSisCorteCaja *)SisReg3LstCorteCaja[lintUltimo];
return (*lCQSisCorteCaja)["Total"];
}

const char *QCorteCaja::TotalEnCaja()
{
int lintUltimo=SisReg3LstCorteCaja.count()-1;
CQSisCorteCaja *lCQSisCorteCaja;
	lCQSisCorteCaja=(CQSisCorteCaja *)SisReg3LstCorteCaja[lintUltimo];
return (*lCQSisCorteCaja)["RestoEnCaja"];
}

void QCorteCaja::closeEvent(QCloseEvent *)
{
  emit SignalTerminar(this);
}
