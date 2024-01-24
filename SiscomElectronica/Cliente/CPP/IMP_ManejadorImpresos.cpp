#include <IMP_ManejadorImpresos.h>
#include <QCtrlEstadosImpresosSE.h>
#include <IMP_QControlFecha.h>
#include <zSiscomElectronica.h>
#include <zClienteSiscom.h>
#include <zPersona.h>
#include <zTelefono.h>
#include <zOrdenVenta.h>
#include <zCircuitoImpreso.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <qlineedit.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qcombobox.h>
#include <qtable.h>
QManejadorImpresos *InstanciaManejadorImpresos(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QManejadorImpresos((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QManejadorImpresos::QManejadorImpresos(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ManejadorImpresos(pQWParent,pchrPtrName,pWFlags),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QManejadorImpresos::~QManejadorImpresos()
{

}

void QManejadorImpresos::ConectaSlots()
{
connect(QCtrFechaInicio,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAFechaFin()));
connect(QCtrFechaFin,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAEstadosImpresos()));
connect(QPBConsultar,SIGNAL(clicked()),SLOT(SlotConsultar()));
connect(QPBActualiza,SIGNAL(clicked()),SLOT(SlotActualiza()));
connect(QCtrEdosImpresos,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotFocoAConsulta(zSiscomRegistro *)));
connect(QTDatos,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionaImpreso(int,int,int,const QPoint &)));
}
void QManejadorImpresos::SlotActualiza()
{
	Actualizando();
	Consultando();
}
void QManejadorImpresos::SlotSeleccionaImpreso(int pintImpreso,
						int,
						int,
						const QPoint &)
{
    QTDatos->selectRow(pintImpreso);
    zSisRegImpreso=(*zSisRegsEdoFecha)[pintImpreso];
}
void QManejadorImpresos::SlotConsultar()
{
  Consultando();
}
void QManejadorImpresos::SlotFocoAFechaFin()
{
	zSiscomQt3::Foco(QCtrFechaFin);
}
void QManejadorImpresos::SlotFocoAEstadosImpresos()
{
	zSiscomQt3::Foco(QCtrEdosImpresos);
}
void QManejadorImpresos::SlotFocoAConsulta(zSiscomRegistro *pzSisRegEdoImpresos)
{
 	zSisRegEdoImpresos=pzSisRegEdoImpresos;
	zSiscomQt3::Foco(QPBConsultar);
}
void QManejadorImpresos::IniciaVariables()
{

QCtrEdosImpresos->Servidor(zSisConexion);
QCtrEdosImpresos->IniciaControl();
QCtrFechaInicio->ColocaFechaHoy();
QCtrFechaFin->ColocaFechaHoy();
zSiscomQt3::Foco(QCtrFechaInicio);
}
int QManejadorImpresos::Consultando()
{
Consulta();
Muestra();
}
int QManejadorImpresos::Consulta()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ImpresosPorEstadoFecha");
lzSisElectronica.CircuitosImpresosPorEstadoFecha(
			(const char *)QCtrFechaInicio->ObtenFecha(),
			(const char *)QCtrFechaFin->ObtenFecha(),
			zSisRegEdoImpresos,
			&zSisRegsEdoFecha);
}
void QManejadorImpresos::Muestra()
{
const char *lchrPtrCampos[]={"nombrecompleto",
			"telefono",
			"fecha",
			"hora",
			"cveproducto",
			"memoria",
			"archivo",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,zSisRegsEdoFecha,QTDatos);
zSiscomQt3::AjustaColumnasTabla(QTDatos);
zSiscomQt3::AjustaFilasTabla(QTDatos);
}
int QManejadorImpresos::Actualizando()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"CircuitoImpresoActualizaEdo");
lzSisElectronica.CircuitoImpresoActualizaEstado(zSisRegEdoImpresos,
						zSisRegImpreso);
}
