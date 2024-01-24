#include <IMP_Ordenes.h>
#include <IMP_CapturaRangoFechas.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSisOrdenes.h>
#include <qpushbutton.h>
#include <qtable.h>
QOrdenes *InstanciaOrdenes(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QOrdenes((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QOrdenes::QOrdenes(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Ordenes(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QOrdenes::~QOrdenes()
{

}

void QOrdenes::ConectaSlots()
{
connect(QPBRangoFechas,
	SIGNAL(clicked()),
	SLOT(SlotRangoFechas()));
connect(QPBAContabilidad,
	SIGNAL(clicked()),
	SLOT(SlotAnexarContabilidad()));
connect(QTOrdenes,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionaOrden(int,int,int,const QPoint &)));
connect(QTOrdenes,
	SIGNAL(currentChanged(int,int)),
	SLOT(SlotSeleccionaOrden(int,int)));
}
void QOrdenes::SlotSeleccionaOrden(int pintNOrden,
				   int)
{
	SisReg3Orden=SisReg3LstOrdenes[pintNOrden];
	ConsultandoDetalleOrden();

}
void QOrdenes::SlotSeleccionaOrden(int pintNOrden,
				   int,
				   int,
				   const QPoint &)
{
	QTOrdenes->selectRow(pintNOrden);
	SisReg3Orden=SisReg3LstOrdenes[pintNOrden];
	ConsultandoDetalleOrden();
}
		
void QOrdenes::SlotAnexarContabilidad()
{
CQSisOrdenesSiscom lCQSOrdenesS(SisDatCom);
lCQSOrdenesS.AnexarOrdenContabilidad(chrPtrArgumentos[0],
				    SisReg3Orden);
}
void QOrdenes::SlotRangoFechas()
{
QCapturaRangoFechas lQCRangoFechas;
if(lQCRangoFechas.ObtenOpcion())
{
  lQCRangoFechas.ObtenRangoFechas(chrArrFechaIni,
  				  chrArrFechaFin);
  Consultando();
}
}
void QOrdenes::IniciaVariables()
{

}

void QOrdenes::Consultando()
{
	Consulta();
	Muestra();
}
void QOrdenes::Consulta()
{
CQSisOrdenesSiscom lCQSOrdenesS(SisDatCom);
SisReg3LstOrdenes.clear();
lCQSOrdenesS.Ordenes(chrPtrArgumentos[0],
		     chrArrFechaIni,
		     chrArrFechaFin,
		     &SisReg3LstOrdenes);
}
void QOrdenes::Muestra()
{
const char *lchrPtrCampos[]={"idventa",
		       "fechahora",
		       "total",
		       0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
					QTOrdenes,
					&SisReg3LstOrdenes);
SiscomDesarrollo3Qt::AjustaColumnas(QTOrdenes);
}

void QOrdenes::ConsultandoDetalleOrden()
{
 ConsultaDetalleOrden();
 MuestraDetalleOrden();
}

void QOrdenes::ConsultaDetalleOrden()
{
CQSisOrdenesSiscom lCQSOrdenesS(SisDatCom);
SisReg3LstDetalleOrden.clear();
lCQSOrdenesS.DetalleOrden(chrPtrArgumentos[0],
			  SisReg3Orden,
			  &SisReg3LstDetalleOrden);
}
void QOrdenes::MuestraDetalleOrden()
{
const char *lchrPtrCampos[]={"cantidad",
		       "cveproducto",
		       "precio",
		       "importe",
		       0};

SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
					QTDetalleOrden,
					&SisReg3LstDetalleOrden);
SiscomDesarrollo3Qt::AjustaColumnas(QTDetalleOrden);
}
void QOrdenes::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
