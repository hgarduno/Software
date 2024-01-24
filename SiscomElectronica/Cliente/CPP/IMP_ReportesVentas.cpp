#include <IMP_ReportesVentas.h>
#include <IMP_CapturaRangoFechas.h>
#include <IMP_SelExpendios.h>
#include <IMP_ControladorReportesVentasExpendios.h>
#include <SISCOMComunicaciones++.h>
#include <SiscomDesarrollo3Qt++.h>



#include <ReportesVentas.h>
#include <GraficaOrdenes.h>
#include <QControlesGrafica.h>
#include <QControlSemanaVenta.h>
#include <QControlMesVenta.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qtabwidget.h>
#include <qlcdnumber.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qpainter.h>
#include <qmessagebox.h>
QReportesVentas *InstanciaReportesVentas(void *pSisDatCom,
					 char **pchrPtrArgumentos,
					 void *pQWParent,
					 const char *pchrPtrName,
					 int pWFlags)
{

	return new QReportesVentas((SiscomDatCom *)pSisDatCom,
				   pchrPtrArgumentos,
				   (QWidget *)pQWParent,
				   pchrPtrName,
				   pWFlags);
}
QReportesVentas::QReportesVentas(SiscomDatCom *pSisDatCom,
				 char **pchrPtrArgumentos,
				 QWidget* parent,
				 const char* name, 
				 WFlags fl )
    : ReportesVentas( parent, name, fl ),
    	SisDatCom(pSisDatCom),
	chrPtrArgumentos(pchrPtrArgumentos),
	EExpendio(0)
{
	IniciaVariables();
	ConectaSlots();
}

QReportesVentas::~QReportesVentas()
{
}
void QReportesVentas::ConectaSlots()
{
	connect(QPBFReporte,
		SIGNAL(clicked()),
		SLOT(S_CapturaFechaReporte()));
	connect(QPBRefrescar,
		SIGNAL(clicked()),
		SLOT(S_Refrescar()));
	connect(QTWDatos,
		SIGNAL(currentChanged(QWidget *)),
		SLOT(S_CambioTab(QWidget *)));
	connect(QPBFechas,
		SIGNAL(clicked()),
		SLOT(S_ReporteImportesPorSemana()));
	connect(QPBSExpendio,
		SIGNAL(clicked()),
		SLOT(S_SeleccionaExpendio()));
}
/* Santiago de Queretaro a 25 de noviembre del 2013 
 * Se agrega la seleccion del expendio, del cual se requiere
 * obtener el reporte
 *
 */
void QReportesVentas::S_SeleccionaExpendio()
{
QSelExpendios lQSelExpendio(SisDatCom);

	if((EExpendio=lQSelExpendio.ObtenExpendio()))
	 MuestraEncabezado();
	  else
	  QMessageBox::information(this,
	  			   "Aplicacion",
				   "No Se Selecciono Un Expendio Valido");
}
void QReportesVentas::S_CambioTab(QWidget *pQWTab)
{

}
void QReportesVentas::ConsultaVentasPorSemana()
{
QCapturaRangoFechas lQCRFechas;
          lQCRFechas.ObtenRangoFechas(chrArrFechaIni,
	                                        chrArrFechaFin);
OrdenesHora lOHora;

	lOHora << 
	new OrdenHora("","","","VentasPorHora")		<<
	new OrdenHora("","","",ObtenIdExpendio())		<<
	new OrdenHora("","","",chrArrFechaIni)		<<
	new OrdenHora("","","",chrArrFechaFin);

	SiscomEscribeLog3Qt(
			  "QReportesVentas::S_CapturaFecha:%d",
			  lOHora.count());
OpOrdenesHora lOOrdenesHora(SisDatCom,&lOHora);
	    lOOrdenesHora.SiscomConsulta("ConsultaVentasPorHora",
	    				 (QPtrList<SiscomInformacion> *)&OHora);
	    lOOrdenesHora.ObtenDatosSemanas(CSDtsSemanas);

}
void QReportesVentas::S_ReporteImportesPorSemana()
{
CSisDatosSemana *lCSDtoSemana;
CSisDatoDia *lCSDtoDia;
int lintContador=0;
	ConsultaVentasPorSemana();
	QCMesVenta->ActualizaDatos(CSDtsSemanas);
}
void QReportesVentas::S_CapturaFecha()
{
/*
OrdenesHora lOHora;

	lOHora << 
	new OrdenHora("","","","VentasPorHora")		<<
	new OrdenHora("","","",chrPtrArgumentos[0])	<<
	new OrdenHora("","","","2007-03-06");

	SiscomEscribeLog3Qt(
			  "QReportesVentas::S_CapturaFecha:%d",
			  lOHora.count());
OpOrdenesHora lOOrdenesHora(SisDatCom,&lOHora);
	    lOOrdenesHora.SiscomConsulta("ConsultaVentasPorHora",
	    				 (QPtrList<SiscomInformacion> *)&OHora);
*/
}
void QReportesVentas::S_Refrescar()
{
	EjecutaReporteVentasPorDia(chrArrFechaIni,chrArrFechaFin);
}

void QReportesVentas::S_CapturaFechaReporte()
{
QCapturaRangoFechas lQCRangoFechas;
	if(lQCRangoFechas.ObtenOpcion())
	{
	    lQCRangoFechas.ObtenRangoFechas(chrArrFechaIni,
	    				    chrArrFechaFin);
	    EjecutaReporteVentasPorDia(chrArrFechaIni,chrArrFechaFin);
	    
	}
}
const char *QReportesVentas::ObtenIdExpendio()
{
if(EExpendio)
return (*EExpendio)["IdEmpresa"];
else
return chrPtrArgumentos[0];
}
void QReportesVentas::EjecutaReporteVentasPorDia(const char *pchrPtrFechaIni,
						 const char *pchrPtrFechaFin)
{
ProductosE lProductos;
ProductoE *lProducto;
ReportesVentasSrv lRepVentas(SisDatCom,ObtenIdExpendio());
int lintContador;
RegistrosRepVenta lRRepVentaDetalle,
		  lRRepOrdenes,
		  lRRepImporteDia,
		  lRRepOrdenesE,
		  lRRepTotalOrdenesE;

	lRepVentas.GeneraReporteVentas(pchrPtrFechaIni,
				       pchrPtrFechaFin,
				       lRRepVentaDetalle,
				       lRRepOrdenes,
				       lRRepImporteDia,
				       lRRepOrdenesE,
				       lRRepTotalOrdenesE);
	MuestraDetalleVentas(lRRepVentaDetalle);
	MuestraVentaPorDia(lRRepImporteDia);
	MuestraOrdenesPorDia(lRRepOrdenes);
	MuestraOrdenesEscuela(lRRepOrdenesE);
	MuestraTotalOrdenesEscuela(lRRepTotalOrdenesE);
}
void QReportesVentas::MuestraOrdenesEscuela(RegistrosRepVenta &pRRepRegOrdenesE)
{
RegistroRepVenta *lRRepRegOrdenE;
int lintContador;
QTOrdenesE->setNumRows(pRRepRegOrdenesE.count());
for(lintContador=0,
    lRRepRegOrdenE=pRRepRegOrdenesE.first();
    lRRepRegOrdenE;
    lintContador++,
    lRRepRegOrdenE=pRRepRegOrdenesE.next())
{
   SiscomAnexarRegistroALaTabla(
   		lintContador,
		QTOrdenesE,
		QStringList() << 
		lRRepRegOrdenE->SRegistrosPro2["Fecha"] <<
		lRRepRegOrdenE->SRegistrosPro2["CveProducto"] <<
		lRRepRegOrdenE->SRegistrosPro2["Cantidad"] );


}
}

void QReportesVentas::MuestraTotalOrdenesEscuela(RegistrosRepVenta &pRRepRegOrdenesE)
{
RegistroRepVenta *lRRepRegOrdenE;
int lintContador;
QTOrdenesETotales->setNumRows(pRRepRegOrdenesE.count());
for(lintContador=0,
    lRRepRegOrdenE=pRRepRegOrdenesE.first();
    lRRepRegOrdenE;
    lintContador++,
    lRRepRegOrdenE=pRRepRegOrdenesE.next())
{
   SiscomAnexarRegistroALaTabla(
   		lintContador,
		QTOrdenesETotales,
		QStringList() << 
		lRRepRegOrdenE->SRegistrosPro2["CveProducto"] <<
		lRRepRegOrdenE->SRegistrosPro2["Cantidad"] );


}
}
void QReportesVentas::MuestraDetalleVentas(RegistrosRepVenta pRRepRegVenta)
{
RegistroRepVenta *lRRegRepVenta;
int lintContador;
	QTDatos->setNumRows(pRRepRegVenta.count()-1);
	for(lRRegRepVenta=pRRepRegVenta.first(),
	    lintContador=0;
	    lintContador<pRRepRegVenta.count();
	    lRRegRepVenta=pRRepRegVenta.next(),
	    lintContador++)
	{
	   if(!strcmp(lRRegRepVenta->SRegistrosPro2["DscProducto"],"Total Ventas"))
	   QLCDNTotal->display(lRRegRepVenta->SRegistrosPro2["Importe"]);
	   else
	   SiscomAnexarRegistroALaTabla(
	   	lintContador,
		QTDatos,
		QStringList()   				<<
		lRRegRepVenta->SRegistrosPro2["CveProducto"]	<<
		lRRegRepVenta->SRegistrosPro2["Cantidad"]	<<
		lRRegRepVenta->SRegistrosPro2["Importe"]);
	}
}
void QReportesVentas::MuestraVentaPorDia(RegistrosRepVenta pRRepRegVenta)
{
RegistroRepVenta *lRRegRepVenta;
int lintContador;
	QTVentas->setNumRows(pRRepRegVenta.count());
	for(lRRegRepVenta=pRRepRegVenta.first(),
	    lintContador=0;
	    lRRegRepVenta;
	    lRRegRepVenta=pRRepRegVenta.next(),
	    lintContador++)
	{
	   SiscomAnexarRegistroALaTabla(
	   	lintContador,
		QTVentas,
		QStringList()   				<<
		lRRegRepVenta->SRegistrosPro2["Fecha"]	<<
		lRRegRepVenta->SRegistrosPro2["Cantidad"]);
	}

}
void QReportesVentas::MuestraOrdenesPorDia(RegistrosRepVenta pRRepRegVenta)
{
RegistroRepVenta *lRRegRepVenta;
int lintContador;
QTOrdenes->setNumRows(pRRepRegVenta.count());
for(lRRegRepVenta=pRRepRegVenta.first(),
    lintContador=0;
    lRRegRepVenta;
    lRRegRepVenta=pRRepRegVenta.next(),
    lintContador++)
{
   SiscomAnexarRegistroALaTabla(
	lintContador,
	QTOrdenes,
	QStringList()   				<<
	lRRegRepVenta->SRegistrosPro2["Fecha"]	<<
	lRRegRepVenta->SRegistrosPro2["Cantidad"]);
}

}
void QReportesVentas::IniciaVariables()
{
SiscomObtenFechaHoyCharAAAADDMM(chrArrFechaIni);
strcpy(chrArrFechaFin,chrArrFechaIni);
AnexaGrafica();
AnexaVentasHoraMes();
}
void QReportesVentas::AnexaGrafica()
{
QWidget *lQWGrafica=new QWidget(QTWDatos,"lQWGrafica");
QVBoxLayout *lQBL=new QVBoxLayout(lQWGrafica);
QGOrdenes=new QGraficaOrdenes(SisDatCom,chrPtrArgumentos,lQWGrafica,"lQGOrdenes");
/*
QCtrGrafica=new QControlesGrafica(lQWGrafica,"QCtrGrafica");
*/

lQBL->addWidget(QGOrdenes);
//lQBL->addWidget(QCtrGrafica);
QTWDatos->insertTab(lQWGrafica,"Grafica");
}
void QReportesVentas::AnexaVentasHoraMes()
{
QWidget *lQWVentasMes=new QWidget(QTWDatos,"lQWVentasMes");
QVBoxLayout *lQBL=new QVBoxLayout(lQWVentasMes);
QCMesVenta=new QCtrMesVenta(CSDtsSemanas,lQWVentasMes,"QCMesVenta");
QPBFechas=new QPushButton("Fecha Reporte",lQWVentasMes,"QPBFechas");
lQBL->addWidget(QCMesVenta);
lQBL->addWidget(QPBFechas);
QTWDatos->insertTab(lQWVentasMes,"Reporte Mensual");
}
void QReportesVentas::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}

void QReportesVentas::AsignaRangoFechas(const char *pchrPtrFechaIni,
					const char *pchrPtrFechaFin)
{
strcpy(chrArrFechaIni,pchrPtrFechaIni);
strcpy(chrArrFechaFin,pchrPtrFechaFin);
}
void QReportesVentas::AsignaExpendio(EmpresaN *pEExpendio)
{
  EExpendio=pEExpendio; 
  MuestraEncabezado();
}
void QReportesVentas::CorreReporte()
{
QPBFReporte->setEnabled(false);
QPBSExpendio->setEnabled(false);
QPBRefrescar->setEnabled(false);
show();
EjecutaReporteVentasPorDia(chrArrFechaIni,chrArrFechaFin);
}

void QReportesVentas::CorreReporte(const char *pchrPtrFechaIni,
				   const char *pchrPtrFechaFin)
{
QPBFReporte->setEnabled(false);
QPBSExpendio->setEnabled(false);
QPBRefrescar->setEnabled(false);
show();
strcpy(chrArrFechaIni,pchrPtrFechaIni);
strcpy(chrArrFechaFin,pchrPtrFechaFin);
EjecutaReporteVentasPorDia(chrArrFechaIni,chrArrFechaFin);
}
void QReportesVentas::MuestraEncabezado()
{
	   setCaption(caption()		+
	   	      " "  		+
		      (*EExpendio)["RazonSocial"]);
}

void QReportesVentas::customEvent(QCustomEvent *pQCEReConsulta)
{

   if(pQCEReConsulta->type()==12346)
   {
	QEventoActualizaFechaReporte *lQEAFechaRep=(QEventoActualizaFechaReporte *)pQCEReConsulta;
	lQEAFechaRep->Fechas(chrArrFechaIni,chrArrFechaFin);
   }
   
   if(pQCEReConsulta->type()==12345)
   {
	EjecutaReporteVentasPorDia(chrArrFechaIni,chrArrFechaFin);
   }
}
