#include <IMP_ReportandoVentas.h>
#include <IMP_QControlFecha.h>
#include <zSiscomQt3.h>

#include <qpushbutton.h>
QReportandoVentas *InstanciaReportandoVentas(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QReportandoVentas((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QReportandoVentas::QReportandoVentas(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ReportandoVentas(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QReportandoVentas::~QReportandoVentas()
{

}

void QReportandoVentas::ConectaSlots()
{
connect(QCtrFechaInicio,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAFechaFin()));
connect(QCtrFechaFin,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoConsultar()));
connect(QPBConsultar,SIGNAL(clicked()),SLOT(SlotConsultar()));
}
void QReportandoVentas::SlotConsultar()
{

}
void QReportandoVentas::SlotFocoConsultar()
{
	zSiscomQt3::Foco(QPBConsultar);
}
void QReportandoVentas::SlotFocoAFechaFin()
{
	zSiscomQt3::Foco(QCtrFechaFin);
}
void QReportandoVentas::IniciaVariables()
{
QCtrFechaInicio->ColocaFechaHoy();
QCtrFechaFin->ColocaFechaHoy();
zSiscomQt3::Foco(QCtrFechaInicio);
}
void QReportandoVentas::Consultando()
{
	Consulta();
	Muestra();
}

void QReportandoVentas::Consulta()
{

}
void QReportandoVentas::Muestra()
{

}
