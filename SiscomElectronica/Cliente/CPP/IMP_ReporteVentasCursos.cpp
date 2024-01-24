#include <IMP_ReporteVentasCursos.h>
#include<SiscomDesarrollo3Qt++.h>
#include <QCtrlProgramacionCursos.h>
#include <CQSis3QtOperaciones.h>

#include <qtable.h>
#include <qlcdnumber.h>
QReporteVentasCursos *InstanciaReporteVentasCursos(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QReporteVentasCursos((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QReporteVentasCursos::QReporteVentasCursos(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ReporteVentasCursos(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QReporteVentasCursos::~QReporteVentasCursos()
{

}

void QReporteVentasCursos::ConectaSlots()
{
connect(QCtrProgramacionCursos,
	SIGNAL(SignalProgramacionCurso(SiscomRegistro3 *)),
	SLOT(SlotProgramacionCurso(SiscomRegistro3 *)));

}
void QReporteVentasCursos::SlotProgramacionCurso(SiscomRegistro3 *pSisReg3ProgCurso)
{
SisReg3ProgCurso=pSisReg3ProgCurso;
ConsultandoVentasCursos();
}
void QReporteVentasCursos::IniciaVariables()
{
QCtrProgramacionCursos->Servidor(SisDatCom);
QCtrProgramacionCursos->IniciaControl();
}
void QReporteVentasCursos::ConsultandoVentasCursos()
{
ConsultaVentasCursos();
MuestraVentasCursos();
}
void QReporteVentasCursos::ConsultaVentasCursos()
{
SisReg3LstVentasCursos.SiscomElimina();
CQSis3QtOperaciones lCQS3QOpVentas(SisDatCom);
lCQS3QOpVentas.VentasCursos((*SisReg3ProgCurso)["idprogramacion"],
			    &SisReg3LstVentasCursos);
SiscomRegistro3LstContenido(&SisReg3LstVentasCursos);
}
void QReporteVentasCursos::MuestraVentasCursos()
{
const char *lchrPtrCampos[]={"curso","cantidad","costo","importe",0};
SiscomRegistro3 *lSisReg3VentasCursos;
SiscomRegistro3 *lSisReg3Totales;
int lintContador;
QTVentasCursos->setNumRows(SisReg3LstVentasCursos.count()-1);
for(lSisReg3VentasCursos=SisReg3LstVentasCursos.first(),
    lintContador=0;
    lSisReg3VentasCursos;
    lSisReg3VentasCursos=SisReg3LstVentasCursos.next(),
    lintContador++)
{
if(lSisReg3VentasCursos->EstaElCampo("curso"))
SiscomDesarrollo3Qt::RegistroALaTabla(lintContador,
				      QTVentasCursos,
				      lchrPtrCampos,
				      lSisReg3VentasCursos);
if(lSisReg3VentasCursos->EstaElCampo("ImporteTotal"))
QTVentasCursos->setText(lintContador,3,(*lSisReg3VentasCursos)["ImporteTotal"]);
if(lSisReg3VentasCursos->EstaElCampo("ParticipacionSiscom"))
lSisReg3Totales=lSisReg3VentasCursos;
}
QLCDNVTotales->display((*lSisReg3Totales)["TotalCursos"]);
QLCDNPSiscom->display((*lSisReg3Totales)["ParticipacionSiscom"]);
}
