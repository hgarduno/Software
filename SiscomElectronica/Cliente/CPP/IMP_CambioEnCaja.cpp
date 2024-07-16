#include <IMP_CambioEnCaja.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomElectronica.h>
#include <zSiscomQt3.h>

#include <zCambioCaja.h>

#include <qtable.h> 
#include <qpushbutton.h>

QCambioEnCaja::QCambioEnCaja(QWidget *pQWParent,       
			     const char *pchrPtrName,
			     WFlags pWFlags):	      
				CambioEnCaja(pQWParent,pchrPtrName,pWFlags),
				zCambioC(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCambioEnCaja::~QCambioEnCaja()
{

}

void QCambioEnCaja::ConectaSlots()
{
connect(QTCambio,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionoCambioCaja(int,int,int,const QPoint &)));
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
}
void QCambioEnCaja::SlotAceptar()
{
     done(1);
}
void QCambioEnCaja::SlotSeleccionoCambioCaja(int pintFila,int,int,const QPoint &)
{
	if((zCambioC=zCambiosC.CambioCaja(pintFila)))
	{
	  QPBAceptar->setEnabled(true);
	  zSiscomQt3::Foco(QPBAceptar);
	}
}
void QCambioEnCaja::IniciaVariables()
{
Consultando();
}
void QCambioEnCaja::Consultando()
{
Consulta();
Muestra();
}
void QCambioEnCaja::Muestra()
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
void QCambioEnCaja::Consulta()
{
zSiscomElectronica lzSisElectronica(Conexion(),"CambiosCaja");
lzSisElectronica.CambiosCaja(&zCambiosC);
}
zSiscomConexion *QCambioEnCaja::Conexion()
{
return (zSiscomConexion *)gzSiscomConexion;
}
zCambioCaja *QCambioEnCaja::CambioCaja()
{
  return zCambioC;
}
