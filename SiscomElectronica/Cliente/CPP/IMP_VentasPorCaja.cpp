#include <IMP_VentasPorCaja.h>
#include <IMP_CapturaRangoFechas.h>
#include <CQSisVentasPorCaja.h>
#include<SISCOMComunicaciones++.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSis3QtComunes.h>
QVentasPorCaja *InstanciaVentasPorCaja(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QVentasPorCaja((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QVentasPorCaja::QVentasPorCaja(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				VentasPorCaja(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QVentasPorCaja::~QVentasPorCaja()
{

}

void QVentasPorCaja::ConectaSlots()
{
	connect(QPBRangoFechas,
		SIGNAL(clicked()),
		SLOT(SlotCapturaRangoFechas()));
	connect(QPBADatos,
		SIGNAL(clicked()),
		SLOT(SlotActualiza()));

}

void QVentasPorCaja::SlotCapturaRangoFechas()
{
QCapturaRangoFechas lQCRangoFechas;
if(lQCRangoFechas.ObtenOpcion())
{
lQCRangoFechas.ObtenRangoFechas(chrArrFechaIni,
				chrArrFechaFin);
Consultando();
}
}
void QVentasPorCaja::SlotActualiza()
{
Consultando();
}
void QVentasPorCaja::IniciaVariables()
{
}
void QVentasPorCaja::Consultando()
{
	Consulta();
	MuestraTotalVentas();
}
void QVentasPorCaja::MuestraTotalVentas()
{
SiscomRegistro3 *lSReg3TotalVentas;

lSReg3TotalVentas=SisReg3VentasCaja[0];
QLCDTotalVentas->display((*lSReg3TotalVentas)["totalvendido"]);
}
void QVentasPorCaja::Consulta()
{
CQSisOpVentaCaja lCQOVentaCaja(SisDatCom);
SisReg3VentasCaja.clear();
lCQOVentaCaja.VentasPorCajaFecha(chrArrFechaIni,
			    chrArrFechaFin,
			    chrPtrArgumentos[0],
			    &SisReg3VentasCaja);
const char *lchrArrCamposM[]={"fechahora",
			"descripcion",
			"total",
			"validacion",
			"edoreporte",
			"totalcortes",
			0
			};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrArrCamposM,
				       QTDatos,
				       &SisReg3VentasCaja);
SiscomDesarrollo3Qt::AjustaColumnas(QTDatos);

}
void QVentasPorCaja::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
