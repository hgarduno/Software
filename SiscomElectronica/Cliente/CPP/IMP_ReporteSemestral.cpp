#include <IMP_ReporteSemestral.h>
#include<SISCOMComunicaciones++.h>
#include <IMP_QControlFecha.h>
#include <IMP_ImprimeReporteSemestral.h>

#include <CQSisReporteSemestral.h>
#include <SiscomDesarrollo3Qt++.h>
QReporteSemestral *InstanciaReporteSemestral(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QReporteSemestral((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QReporteSemestral::QReporteSemestral(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ReporteSemestral(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				QWParent(pQWParent)
{
IniciaVariables();
ConectaSlots();
}
QReporteSemestral::~QReporteSemestral()
{
}
void QReporteSemestral::closeEvent(QCloseEvent *)
{
	delete QImpRepSemestral;
	emit SignalTerminar(this);
}
void QReporteSemestral::ConectaSlots()
{
connect(QPBReporte,
	SIGNAL(clicked()),
	SLOT(SlotReporteSemestral()));
connect(QPBImprime,
	SIGNAL(clicked()),
	SLOT(SlotImprime()));
connect(QCFInicio,
	SIGNAL(Signal_EnterA_o()),
	SLOT(SlotPasaFocoFechaFin()));
connect(QCFFin,
	SIGNAL(Signal_EnterA_o()),
	SLOT(SlotPasaFocoEjecutaReporte()));
}


void QReporteSemestral::SlotImprime()
{

  QImpRepSemestral=new QImprimeReporteSemestral(&SisReg3LstRSemestral,
  						QWParent);

}
void QReporteSemestral::SlotReporteSemestral()
{

ConsultandoReporte();

}
void QReporteSemestral::ConsultandoReporte()
{
	ConsultaReporte();
	MuestraReporte();
}
void QReporteSemestral::ConsultaReporte()
{
CQSisReporteSemestral lCQSRSemestral(SisDatCom);
lCQSRSemestral.ReporteSemestral(
			(const char *)QCFInicio->ObtenFecha(),
			(const char *)QCFFin->ObtenFecha(),
			chrPtrArgumentos[0],
			&SisReg3LstRSemestral);

}
void QReporteSemestral::MuestraReporte()
{
const char *lchrArrCampos[]={"precioventa",
		       "total",
		       "inventario",
		       "cveproducto",
		       "fechaucompra",
		       "cantidaducompra",
		       "precioucompra",
		       "proveedor",
		       0};

SiscomDesarrollo3Qt::RegistrosALaTabla(lchrArrCampos,
					QTDatos,
					&SisReg3LstRSemestral);
SiscomDesarrollo3Qt::AjustaColumnas(QTDatos);
}
void QReporteSemestral::IniciaVariables()
{
QCFInicio->ColocaFechaHoy();
QCFFin->ColocaFechaHoy();
SiscomDesarrollo3Qt::PasaFocoControl(QCFInicio);
}

void QReporteSemestral::SlotPasaFocoFechaFin()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QCFFin);
}
void QReporteSemestral::SlotPasaFocoEjecutaReporte()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QPBReporte);
}
