#include <IMP_DatosCorteCaja.h>
#include <IMP_QControlFecha.h>

#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomElectronica.h>
#include <zSiscomQt3.h>

#include <zCambioCaja.h>

#include <qtable.h> 
#include <qpushbutton.h>
/* Siscom Zacatenco a 23 de Julio del 2024 
 *
 */

QDatosCorteCaja::QDatosCorteCaja(QWidget *pQWParent,       
			     const char *pchrPtrName,
			     WFlags pWFlags):	      
				DatosCorteCaja(pQWParent,pchrPtrName,pWFlags),
				zCambioC(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QDatosCorteCaja::~QDatosCorteCaja()
{

}

void QDatosCorteCaja::ConectaSlots()
{
connect(QTCambio,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionoCambioCaja(int,int,int,const QPoint &)));
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QCFInicio,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAFechaFin()));
}
void QDatosCorteCaja::SlotFocoAFechaFin()
{
zSiscomQt3::Foco(QCFFinal);
}
void QDatosCorteCaja::SlotAceptar()
{
     done(1);
}
void QDatosCorteCaja::SlotSeleccionoCambioCaja(int pintFila,int,int,const QPoint &)
{
	if((zCambioC=zCambiosC.CambioCaja(pintFila)))
	{
	  QPBAceptar->setEnabled(true);
	  zSiscomQt3::Foco(QPBAceptar);
	}
}
void QDatosCorteCaja::IniciaVariables()
{
Consultando();
IniciandoFechas();

zSiscomQt3::Foco(QCFInicio);
}
void QDatosCorteCaja::Consultando()
{
Consulta();
Muestra();
}
void QDatosCorteCaja::IniciandoFechas()
{
QCFInicio->ColocaFechaHoy();
QCFFinal->ColocaFechaHoy();
}
void QDatosCorteCaja::Muestra()
{
zCambioCaja *lzCambioC;
int lintContador=0;
QTCambio->setNumRows(zCambiosC.NNodos());
for(lzCambioC=(zCambioCaja *)zCambiosC.Primer();
    lzCambioC;
    lzCambioC=(zCambioCaja *)zCambiosC.Siguiente(),
    lintContador++)
{
  QTCambio->setText(lintContador,0,lzCambioC->Fecha());
  QTCambio->setText(lintContador,1,lzCambioC->Importe());
}
     
}
void QDatosCorteCaja::Consulta()
{
zSiscomElectronica lzSisElectronica(Conexion(),"CambiosCaja");
lzSisElectronica.CambiosCaja(&zCambiosC);
}
zSiscomConexion *QDatosCorteCaja::Conexion()
{
return (zSiscomConexion *)gzSiscomConexion;
}
zCambioCaja *QDatosCorteCaja::CambioCaja()
{
  return zCambioC;
}
const char *QDatosCorteCaja::FechaInicio()
{
   return strdup(QCFInicio->ObtenFecha());
}
const char *QDatosCorteCaja::FechaFin()
{
   return strdup(QCFFinal->ObtenFecha());

}
