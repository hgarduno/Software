#include <QtImpCapturaCentroTrabajo.h>
#include <zContratoBeneficios.h>
#include <zOperacionesServiSNTE.h>
#include <zCentroTrabajo.h>


#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <qlineedit.h>
#include <qpushbutton.h>

QtImpCapturaCentroTrabajo::QtImpCapturaCentroTrabajo(zContratoBeneficios *pzConBeneficios,
						    QWidget *pQWParent,
						    const char *pchrPtrName,
						    bool pbModal,
						    WFlags pWFlags):
						    CapturaCentroTrabajo(pQWParent,
						    			 pchrPtrName,
									 pbModal,
									 pWFlags),
						   zConBeneficios(pzConBeneficios),
						   intAceptar(0)
{
Conexion((zSiscomConexion *)gzSiscomConexion);
IniciaVariables();
ConectaSlots();
exec();
}





void QtImpCapturaCentroTrabajo::IniciaVariables()
{
 zSiscomQt3::Foco(QLECentroTrabajo);
}

void QtImpCapturaCentroTrabajo::ConectaSlots()
{
   connect(QLECentroTrabajo,
   	   SIGNAL(returnPressed()),
	   SLOT(SlotFocoAClavePresupuestal()));
   connect(QLEClavePresupuestal,
   	   SIGNAL(returnPressed()),
	   SLOT(SlotFocoARegistrar()));
    connect(QPBRegistrar,
    	    SIGNAL(clicked()),
	    SLOT(SlotRegistrar()));
    connect(QPBAceptar,
    	    SIGNAL(clicked()),
	    SLOT(SlotAceptar()));
}
void QtImpCapturaCentroTrabajo::SlotAceptar()
{
	intAceptar=1;
	done(1);

}
void QtImpCapturaCentroTrabajo::SlotRegistrar()
{
   if(Registrando())
   {
	QPBAceptar->setEnabled(true);
	QPBRegistrar->setEnabled(false);
	zSiscomQt3::Foco(QPBAceptar);
   }
}
void QtImpCapturaCentroTrabajo::SlotFocoAClavePresupuestal()
{
zSiscomQt3::Foco(QLEClavePresupuestal);
}

void QtImpCapturaCentroTrabajo::SlotFocoARegistrar()
{
zSiscomQt3::Foco(QPBRegistrar);
}

void QtImpCapturaCentroTrabajo::reject()
{

}
void QtImpCapturaCentroTrabajo::Asigna()
{
if(zConBeneficios->CentroTrabajo())
{
Muestra(); 
QPBRegistrar->setEnabled(false);
QPBAceptar->setEnabled(true);
}
else
{
   zCenTrabajo=new zCentroTrabajo(zConBeneficios->IdCliente(),
   				  zSiscomQt3::Texto(QLECentroTrabajo),
   				  zSiscomQt3::Texto(QLEClavePresupuestal));
   zConBeneficios->CentroTrabajo(zCenTrabajo);
}
}
int QtImpCapturaCentroTrabajo::Aceptar()
{
   return intAceptar;
}
int QtImpCapturaCentroTrabajo::Registrando()
{
  Asigna();
  if(Registra())
  {	
	return 1;
  }
  else
  return 0;
}
int QtImpCapturaCentroTrabajo::Registra()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"RegistraCentroTrabajo");
return lzOpServiSNTE.RegistraCentroTrabajo(zCenTrabajo);
}

void QtImpCapturaCentroTrabajo::Conexion(zSiscomConexion *pzSiscomConexion)
{
zSisConexion=pzSiscomConexion;
}
void QtImpCapturaCentroTrabajo::Muestra()
{
QLECentroTrabajo->setText(zConBeneficios->CentroTrabajo2());
QLEClavePresupuestal->setText(zConBeneficios->ClavePresupuestal());
}
