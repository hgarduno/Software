#include <IMP_ControladorReportesVentasExpendios.h>
#include <IMP_ReportesVentas.h>
#include <IMP_QControlFecha.h>
#include<SiscomDesarrollo3Qt++.h>
#include <qobjectlist.h>
#include <qapplication.h>

QControladorReportesVentasExpendios *InstanciaControladorReportesVentasExpendios(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QControladorReportesVentasExpendios((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QControladorReportesVentasExpendios::QControladorReportesVentasExpendios(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ControladorReportesVentasExpendios(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				QWParent(pQWParent)
{
IniciaVariables();
ConectaSlots();
BuscaVentaReportes();
}

QControladorReportesVentasExpendios::~QControladorReportesVentasExpendios()
{

}

void QControladorReportesVentasExpendios::ConectaSlots()
{
connect(QPBIniMuestreo,
	SIGNAL(clicked()),
	SLOT(SlotIniciaMuestreo()));

}
void QControladorReportesVentasExpendios::SlotIniciaMuestreo()
{
ObtenExpendiosAMuestrear();
CargaReportesVentas();
new QLanzaReConsultaReporte(QLEPeriodo->text().toInt(),QOLPtrRepExpendios);
QPBIniMuestreo->setEnabled(false);
}
void QControladorReportesVentasExpendios::IniciaVariables()
{
ConsultandoExpendios();
QCtrFechaIni->ColocaFechaHoy();
QCtrFechaFin->ColocaFechaHoy();
}
void QControladorReportesVentasExpendios::BuscaVentaReportes()
{
QObjectList *lQOLPtrOVentanas=QWParent->queryList("QReportesVentas");
QObjectListIt lQOLItOVentas(*lQOLPtrOVentanas);
QObject *lQOPtrControl;

while((lQOPtrControl=lQOLItOVentas.current())!=0)
{
	SiscomEscribeLog3Qt("%s",lQOPtrControl->className());
	++lQOLItOVentas;
}
}

void QControladorReportesVentasExpendios::ConsultandoExpendios()
{
ConsultaExpendios();
MuestraExpendios();
SiscomDesarrollo3Qt::AjustaColumnas(QTExpendios);
}
void QControladorReportesVentasExpendios::ConsultaExpendios()
{
ConsultaEmpresasN lCCnsExpendios(SisDatCom,
				 "Expendios",
				 EExpendios);
}
void QControladorReportesVentasExpendios::MuestraExpendios()
{
EmpresaN *lEmpresa;
int lintContador;
QTExpendios->setNumRows(EExpendios.count());
for(lEmpresa=EExpendios.first(),
    lintContador=0;
    lEmpresa;
    lEmpresa=EExpendios.next(),
    lintContador++)
QTExpendios->setText(lintContador,0,(*lEmpresa)["RazonSocial"]);
}
void QControladorReportesVentasExpendios::ObtenExpendiosAMuestrear()
{
int lintContador;
for(lintContador=0;
    lintContador<QTExpendios->numRows();
    lintContador++)
if((QTExpendios->isRowSelected(lintContador,true)))
 EExpendiosAMuestrear << EExpendios.at(lintContador);

}
void QControladorReportesVentasExpendios::CargaReportesVentas()
{
EmpresaN *lEmpresa;
for(lEmpresa=EExpendiosAMuestrear.first();
    lEmpresa;
    lEmpresa=EExpendiosAMuestrear.next())
{
  SiscomEscribeLog3Qt("Cargando el reporte para :%s",
  			(*lEmpresa)["RazonSocial"]);
  CargaReporteVentas(lEmpresa);    
}
    
}
void QControladorReportesVentasExpendios::CargaReporteVentas(EmpresaN *pEExpendio)
{
QReportesVentas *lQRVentas;
    lQRVentas=new QReportesVentas(SisDatCom,chrPtrArgumentos,QWParent);
    lQRVentas->AsignaExpendio(pEExpendio);
    lQRVentas->CorreReporte((const char *)QCtrFechaIni->ObtenFecha(),
    			    (const char *)QCtrFechaFin->ObtenFecha());
    QOLPtrRepExpendios.append(lQRVentas);
}

QEventoConsultaReporte::QEventoConsultaReporte():
			QCustomEvent(12345)
{
}
QEventoActualizaFechaReporte::QEventoActualizaFechaReporte(const char *pchrPtrFechaIni,
							   const char *pchrPtrFechaFin):
							  QCustomEvent(12346)
{
  strcpy(chrArrFechaIni,pchrPtrFechaIni);
  strcpy(chrArrFechaFin,pchrPtrFechaFin);
}

void QEventoActualizaFechaReporte::Fechas(char *pchrPtrFechaIni,
					  char *pchrPtrFechaFin)
{
   strcpy(pchrPtrFechaIni,chrArrFechaFin);
   strcpy(pchrPtrFechaFin,chrArrFechaFin);
}
QLanzaReConsultaReporte::QLanzaReConsultaReporte(int pintPeriodo,
						 const QObjectList &pQOLExpendios):bDeten(false),
						QOLExpendios(pQOLExpendios),
						intPeriodo(pintPeriodo)
{
start();
}
void QLanzaReConsultaReporte::CambioElDia(int pintDiaInicio,
					  int pintMesInicio,
					  int pintAnoInicio)
{
int lintDia,lintMes,lintAno;
char lchrArrFechaIni[20],lchrArrFechaFin[20];
SiscomDesarrollo3Qt::FechaHoy(&lintDia,&lintMes,&lintAno);
sprintf(lchrArrFechaIni,"%04d-%02d-%02d",lintAno,lintMes,lintDia);
sprintf(lchrArrFechaFin,"%04d-%02d-%02d",lintAno,lintMes,lintDia);
if(lintDia!=pintDiaInicio ||
   lintMes!=pintMesInicio || 
   lintAno!=pintAnoInicio)
{
QObject *lQORepVenta;
QObjectListIt lQOLItOVentas(QOLExpendios);
while((lQORepVenta=lQOLItOVentas.current()))
{
   QApplication::postEvent(lQORepVenta,new QEventoActualizaFechaReporte(lchrArrFechaIni,lchrArrFechaFin));
   ++lQOLItOVentas;
}
}
}
void QLanzaReConsultaReporte::run()
{
int lintDiaInicio,
    lintMesInicio,
    lintA_oInicio,
    lintDia,
    lintMes,
    lintAno;
SiscomDesarrollo3Qt::FechaHoy(&lintDiaInicio,&lintMesInicio,&lintA_oInicio);
SiscomEscribeLog3Qt("Fecha Inicio:%d-%d-%d",
		    lintDiaInicio,
		    lintMesInicio,
		    lintA_oInicio);
	while(!bDeten)
	{
	     sleep(intPeriodo);
	     EnviaEventoReConsulta();
	     CambioElDia(lintDiaInicio,lintMesInicio,lintA_oInicio);
	}

}
void QLanzaReConsultaReporte::EnviaEventoReConsulta()
{
QObject *lQORepVenta;
QObjectListIt lQOLItOVentas(QOLExpendios);
while((lQORepVenta=lQOLItOVentas.current()))
{
   QApplication::postEvent(lQORepVenta,new QEventoConsultaReporte);
   ++lQOLItOVentas;
}
}
