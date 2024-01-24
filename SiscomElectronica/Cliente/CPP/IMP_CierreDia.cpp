#include <IMP_CierreDia.h>
#include <IMP_SelExpendios.h>

#include <IMP_QControlFecha.h>

#include <zSiscomElectronica.h>
#include <zProductoCotizar.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <qmessagebox.h>

QCierreDia *InstanciaCierreDia(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QCierreDia((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QCierreDia::QCierreDia(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				CierreDia(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)
{
IniciaVariables();
ConectaSlots();
}

QCierreDia::~QCierreDia()
{

}

void QCierreDia::ConectaSlots()
{
connect(QCtrFechaInicio,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAFechaFin()));
connect(QCtrFechaFin,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAExpendio()));
connect(QPBSeleccionarExpendio,SIGNAL(clicked()),SLOT(SlotSeleccionaExpendio()));
connect(QPBConsulta,SIGNAL(clicked()),SLOT(SlotConsulta()));

}
void QCierreDia::SlotConsulta()
{
Consultando();
}
void QCierreDia::SlotFocoAFechaFin()
{
zSiscomQt3::Foco(QCtrFechaFin);
}
void QCierreDia::SlotFocoAExpendio()
{
   zSiscomQt3::Foco(QPBSeleccionarExpendio); 
}
void QCierreDia::IniciaVariables()
{
zSiscomQt3::Foco(QCtrFechaInicio);
QCtrFechaInicio->ColocaFechaHoy();
QCtrFechaFin->ColocaFechaHoy();
}
void QCierreDia::Consultando()
{
 Consulta();
 Muestra();
}
void QCierreDia::Consulta()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"CierraDia");
lzSisElectronica.CierreDia(ObtenIdExpendio(),
				(const char *)QCtrFechaInicio->ObtenFecha(),
			       	(const char *)QCtrFechaFin->ObtenFecha(),
				&zRepVentas);	
}
void QCierreDia::Muestra()
{
QLEVentasEfectivo->setText(zRepVentas.ImporteVentas());
QLEVentasTarjeta->setText(zRepVentas.ImporteTarjeta());
QLEVentasPedidos->setText(zRepVentas.ImportePedidos());
QLCDNTotal->display(zRepVentas.TotalTotalVentas());
}

void QCierreDia::SlotSeleccionaExpendio()
{
QSelExpendios lQSelExpendio(SisDatCom);

	if((EExpendio=lQSelExpendio.ObtenExpendio()))
	{
	 MuestraEncabezado();
	 zSiscomQt3::Foco(QPBConsulta);
	}
	  else
	  QMessageBox::information(this,
	  			   "Aplicacion",
				   "No Se Selecciono Un Expendio Valido");
}

void QCierreDia::MuestraEncabezado()
{
	   setCaption(caption()		+
	   	      " "  		+
		      (*EExpendio)["RazonSocial"]);
}

const char *QCierreDia::ObtenIdExpendio()
{
if(EExpendio)
return (*EExpendio)["IdEmpresa"];
else
return chrPtrArgumentos[0];
}
