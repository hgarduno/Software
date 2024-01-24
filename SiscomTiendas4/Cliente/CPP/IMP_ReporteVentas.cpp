#include <IMP_ReporteVentas.h>
#include <IMP_QControlFecha.h>

#include<SISCOMComunicaciones++.h>
#include <CQSisProductos.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>
QReporteVentas *InstanciaReporteVentas(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QReporteVentas((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QReporteVentas::QReporteVentas(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ReporteVentas(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QReporteVentas::~QReporteVentas()
{

}

void QReporteVentas::ConectaSlots()
{
	connect(QPBEjecuta,
		SIGNAL(clicked()),
		SLOT(SlotEjecuta()));
	connect(QCtrFechaIni,
		SIGNAL(Signal_EnterA_o()),
		SLOT(SlotPasaFocoFechaFin()));
	connect(QCtrFechaFin,
		SIGNAL(Signal_EnterA_o()),
		SLOT(SlotPasaFocoEjecuta()));

}
void QReporteVentas::SlotPasaFocoEjecuta()
{
	
	SiscomPasaFocoControl(QPBEjecuta);
}
void QReporteVentas::SlotPasaFocoFechaFin()
{
	QCtrFechaFin->setFocus();
}
void QReporteVentas::SlotEjecuta()
{

	ConsultandoReporteVentas();
	ConsultandoDetalleVentas();

}
void QReporteVentas::IniciaVariables()
{
	QCtrFechaFin->ColocaFechaHoy();
	QCtrFechaIni->ColocaFechaHoy();
	QCtrFechaIni->setFocus();
}
void QReporteVentas::ConsultaReporteVentas()
{
CQSisOpReportes lCQSORVentas(SisDatCom);
CQSLRVenta.clear();
	lCQSORVentas.ReporteVentas((const char *)QCtrFechaIni->ObtenFecha(),
				   (const char *)QCtrFechaFin->ObtenFecha(),
				   &CQSLRVenta);
}
void QReporteVentas::MuestraReporteVentas()
{
CQSisRepVenta *lCQSRVenta;
int lintContador;
int lintNFilas=CQSLRVenta.count()-1;
	QTDatos->setNumRows(lintNFilas);
	for(lCQSRVenta=CQSLRVenta.first(),
	    lintContador=0;
	    lintContador<lintNFilas;
	    lCQSRVenta=CQSLRVenta.next(),
	    lintContador++)
	 SiscomAnexarRegistroALaTabla(
	 	lintContador,
		QTDatos,
		QStringList() <<
		lCQSRVenta->SRegistrosPro2["NumOrdenes"]	<<
		lCQSRVenta->SRegistrosPro2["Total"]	<<
		lCQSRVenta->SRegistrosPro2["Fecha"]);
SiscomAjustaColumnas(QTDatos);
QLCDNTotal->display(lCQSRVenta->SRegistrosPro2["Total"]);
}
void QReporteVentas::ConsultandoReporteVentas()
{
	ConsultaReporteVentas();
	MuestraReporteVentas();
}

void QReporteVentas::ConsultandoDetalleVentas()
{
ConsultaDetalleVentas();
MuestraDetalleVentas();
}
void QReporteVentas::ConsultaDetalleVentas()
{
CQSisOpReportes lCQSOReportes(SisDatCom);
lCQSOReportes.DetalleVentas(
		(const char *)QCtrFechaIni->ObtenFecha(),
		(const char *)QCtrFechaFin->ObtenFecha(),
		&CQSLPCotiza);
}
void QReporteVentas::MuestraDetalleVentas()
{
int lintContador;
CQSisProdCotiza *lCQSPCotiza;
CQSisProducto *lCQSProducto;
QTDetalle->setNumRows(CQSLPCotiza.count());
for(lintContador=0,
    lCQSPCotiza=CQSLPCotiza.first();
    lCQSPCotiza;
    lintContador++,
    lCQSPCotiza=CQSLPCotiza.next())
{
lCQSProducto=lCQSPCotiza->Producto();
SiscomAnexarRegistroALaTabla(
	lintContador,
	QTDetalle,
	QStringList() 				<<
	(*lCQSProducto)["Clave"]		<<
	(*lCQSProducto)["Dsc"]			<<
	(*lCQSPCotiza)["Cantidad"]		<<
	(*lCQSPCotiza)["Precio"]		<<
	(*lCQSPCotiza)["Importe"]);
}
SiscomAjustaFilas(QTDetalle);
SiscomAjustaColumnas(QTDetalle);
}

void QReporteVentas::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
