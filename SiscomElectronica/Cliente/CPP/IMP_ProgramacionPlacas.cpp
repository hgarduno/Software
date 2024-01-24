#include <IMP_ProgramacionPlacas.h>
#include<SiscomDesarrollo3Qt++.h>
#include <CQSisProgramacionPlacas.h>
#include <IMP_QControlFecha.h>

#include <qpushbutton.h>
#include <qtable.h>
QProgramacionPlacas *InstanciaProgramacionPlacas(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QProgramacionPlacas((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QProgramacionPlacas::QProgramacionPlacas(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ProgramacionPlacas(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QProgramacionPlacas::~QProgramacionPlacas()
{

}

void QProgramacionPlacas::ConectaSlots()
{
 connect(QPBPPendientes,
 	 SIGNAL(clicked()),
	 SLOT(SlotPlacasPendientes()));
  connect(QTDatos,
  	  SIGNAL(clicked(int,int,int,const QPoint &)),
	  SLOT(SlotSeleccionaPlaca(int,int,int,const QPoint &)));
  connect(QPBEntregar,
  	  SIGNAL(clicked()),
	  SLOT(SlotEntrega()));

}
void QProgramacionPlacas::SlotEntrega()
{
EntregandoPlaca();
Consultando();
}
void QProgramacionPlacas::SlotSeleccionaPlaca(int pintNPlaca,
						int,
						int,
						const QPoint &)
{
      QTDatos->selectRow(pintNPlaca);
      SisRegPlaca=SisRegPlacasProgramadas[pintNPlaca];
}
						
void QProgramacionPlacas::SlotPlacasPendientes()
{
  SisRegPlacasProgramadas.clear();
  Consultando();
}
void QProgramacionPlacas::IniciaVariables()
{
  QCtrFechaInicio->ColocaFechaHoy();
  QCtrFechaFin->ColocaFechaHoy();
   Consultando();
}
void QProgramacionPlacas::Consultando()
{
Consulta();
/*
Muestra();
*/
}
void QProgramacionPlacas::Consulta()
{
CQSisProgramacionPlacas lCQSProgPlacas(SisDatCom);
lCQSProgPlacas.ProgramacionPlacas((const char *)QCtrFechaInicio->ObtenFecha(),
				  (const char *)QCtrFechaFin->ObtenFecha(),
				  chrPtrArgumentos[0],
				  &SisRegPlacasProgramadas);
}
void QProgramacionPlacas::Muestra()
{
const char *lchrPtrCampos[]={"nombre",
			"cveproducto",
			"fechahora",
			0};

SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
					QTDatos,
					&SisRegPlacasProgramadas);

SiscomDesarrollo3Qt::AjustaColumnas(QTDatos);
}
void QProgramacionPlacas::EntregandoPlaca()
{
CQSisProgramacionPlacas lCQSProgPlacas(SisDatCom);
lCQSProgPlacas.EntregarPlaca(chrPtrArgumentos[0],SisRegPlaca);
}
