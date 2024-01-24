#include <IMP_Ganancias.h>
#include <IMP_CapturaRangoFechas.h>
#include<SISCOMComunicaciones++.h>
#include <CQSisGanancias.h>
#include <SiscomDesarrollo3Qt++.h>
QGanancias *InstanciaGanancias(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QGanancias((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QGanancias::QGanancias(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Ganancias(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QGanancias::~QGanancias()
{

}

void QGanancias::ConectaSlots()
{
	connect(QPFechas,
		SIGNAL(clicked()),
		SLOT(SlotCapturaRangoFechas()));

}
void QGanancias::SlotCapturaRangoFechas()
{
QCapturaRangoFechas lQCRangoFechas;
if(lQCRangoFechas.ObtenOpcion())
{
lQCRangoFechas.ObtenRangoFechas(chrArrFechaIni,
				chrArrFechaFin);
Consultando();
}
}
void QGanancias::IniciaVariables()
{

}


void QGanancias::Consultando()
{
ConsultaGanancias();
MuestraGanancias();
}
void QGanancias::ConsultaGanancias()
{
CQSisGanando lCQSGanando(SisDatCom);
lCQSGanando.GananciasPeriodo(chrPtrArgumentos[0],
			     chrArrFechaIni,
			     chrArrFechaFin,
			     &SisReg3LstResumen,
			     &SisReg3LstGProducto,
			     &SisReg3LstGFecha);
}
void QGanancias::MuestraResumen()
{
SiscomRegistro3 *lSisReg3Resumen=SisReg3LstResumen[0];
QLEPeriodo->setText((*lSisReg3Resumen)["Periodo"]);
QLETotalVentas->setText((*lSisReg3Resumen)["TotalVentas"]);
QLEGanancias->setText((*lSisReg3Resumen)["Ganancia"]);
}
void QGanancias::MuestraGananciaProducto()
{
const char *lchrArrCampos[]={"Producto",
		       "TotalVentas",
		       "Ganancia",
		       0
		       };
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrArrCampos,
				       QTGProducto,
				       &SisReg3LstGProducto);
SiscomDesarrollo3Qt::AjustaColumnas(QTGProducto);

}
void QGanancias::MuestraGananciaFecha()
{
const char *lchrArrCampos[]={"Fecha",
		       "TotalVentas",
		       "Ganancia",
		       0
		       };
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrArrCampos,
				       QTGFecha,
				       &SisReg3LstGFecha);
SiscomDesarrollo3Qt::AjustaColumnas(QTGFecha);
}
void QGanancias::MuestraGanancias()
{
MuestraResumen();
MuestraGananciaProducto();
MuestraGananciaFecha();
}
void QGanancias::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
