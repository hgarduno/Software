#include <IMP_ReporteVentas4.h>
#include <IMP_QControlFecha.h>
#include <IMP_SelExpendios.h>

#include <zSiscomElectronica.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <EmpresasN.h>

#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>

QReporteVentas4 *InstanciaReporteVentas4(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QReporteVentas4((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QReporteVentas4::QReporteVentas4(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ReporteVentas4(pQWParent,pchrPtrName,pWFlags),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QReporteVentas4::~QReporteVentas4()
{

}

void QReporteVentas4::ConectaSlots()
{
connect(QCtrFechaInicio,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAFechaFin()));
connect(QCtrFechaFin,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAExpendio()));
connect(QPBSeleccionarExpendio,SIGNAL(clicked()),SLOT(SlotSeleccionaExpendio()));
connect(QPBConsultar,SIGNAL(clicked()),SLOT(SlotConsultar()));
}
void QReporteVentas4::SlotConsultar()
{
Consultando();
}
void QReporteVentas4::SlotSeleccionaExpendio()
{
QSelExpendios lQSelExpendio(SisDatCom);

	if((EExpendio=lQSelExpendio.ObtenExpendio()))
	{
	 MuestraEncabezado();
	 zSiscomQt3::Foco(QPBConsultar);
	}
	  else
	  QMessageBox::information(this,
	  			   "Aplicacion",
				   "No Se Selecciono Un Expendio Valido");
}
void QReporteVentas4::SlotFocoAFechaFin()
{
zSiscomQt3::Foco(QCtrFechaFin);
}
void QReporteVentas4::SlotFocoAExpendio()
{
   zSiscomQt3::Foco(QPBSeleccionarExpendio); 
}
void QReporteVentas4::IniciaVariables()
{
zSiscomQt3::Foco(QCtrFechaInicio);
QCtrFechaInicio->ColocaFechaHoy();
QCtrFechaFin->ColocaFechaHoy();
}

void QReporteVentas4::MuestraEncabezado()
{
	   setCaption((*EExpendio)["RazonSocial"]);
}

const char *QReporteVentas4::ObtenIdExpendio()
{
if(EExpendio)
return (*EExpendio)["IdEmpresa"];
else
return chrPtrArgumentos[0];
}
void QReporteVentas4::Consultando()
{
char lchrArrDesEstadoReporte[128];
  if(Consulta(lchrArrDesEstadoReporte))
  Muestra();
  else
  QMessageBox::information(this,"Aviso Sistema",lchrArrDesEstadoReporte);
}
int QReporteVentas4::Consulta(char *pchrPtrDesEstadoReporte)
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ReporteVentas4");
return lzSisElectronica.ReporteVentas(ObtenIdExpendio(),
				(const char *)QCtrFechaInicio->ObtenFecha(),
			       	(const char *)QCtrFechaFin->ObtenFecha(),
				pchrPtrDesEstadoReporte,
			       	&zRepVentas);
}
void QReporteVentas4::Muestra()
{
	ACeroTablas();
	MuestraTotales(); 
	MuestraReportePorEscuela();
}
void QReporteVentas4::MuestraTotales()
{
 QLCDNVentasTotales->display(zRepVentas.ImporteVentas());
 QLCDNVentasApartados->display(zRepVentas.ImporteApartados());
 QLCDNVentasPedidos->display(zRepVentas.ImportePedidos());
 QLCDNTotal->display(zRepVentas.TotalTotalVentas());
}
void QReporteVentas4::ACeroTablas()
{
QTVentaEscuela->setNumRows(0);
QTPedidosEscuela->setNumRows(0);
QTTotales->setNumRows(0);
}
void QReporteVentas4::MuestraReportePorEscuela()
{
const char *lchrPtrOrdenesPorEscuela[]={"fecha","nombre","ordenes","importe",0};
MuestraOrdenesPorTipo(QTVentaEscuela,lchrPtrOrdenesPorEscuela,zRepVentas.VentasPorEscuela());
MuestraOrdenesPorTipo(QTPedidosEscuela,lchrPtrOrdenesPorEscuela,zRepVentas.PedidosPorEscuela());
MuestraOrdenesPorTipo(QTTotales,lchrPtrOrdenesPorEscuela,zRepVentas.Totales());
MuestraVentasTotales();
MuestraMaterialEscuela();
}
void QReporteVentas4::MuestraVentasTotales()
{
const char *lchrPtrVentasTotales[]={"fecha","ordenes","total",0};
if(zRepVentas.VentasTotales())
 zSiscomQt3::LlenaTabla(lchrPtrVentasTotales,zRepVentas.VentasTotales(),QTVentasTotales);
}
void QReporteVentas4::MuestraOrdenesPorTipo(QTable *pQTDatos,
					    const char *pchrPtrCampos[],
					    zSiscomRegistros *pzSisRegDatos)
{
  if(pzSisRegDatos)
  zSiscomQt3::LlenaTabla(pchrPtrCampos,pzSisRegDatos,pQTDatos); 
  
}
void QReporteVentas4::MuestraMaterialEscuela()
{
const char *lchrPtrDatos[]={"fecha","nombre","cveproducto","cantidad",0};
if(zRepVentas.MaterialEscuela())
zSiscomQt3::LlenaTabla(lchrPtrDatos,zRepVentas.MaterialEscuela(),QTMaterialEscuela);
}
