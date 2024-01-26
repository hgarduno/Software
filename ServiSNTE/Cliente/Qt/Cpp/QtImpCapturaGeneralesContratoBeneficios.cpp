#include <QtImpCapturaGeneralesContratoBeneficios.h>
#include <zContratoBeneficios.h>
#include <zGeneralesBeneficios.h>
#include <zOperacionesServiSNTE.h>

#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>


#include <qlineedit.h>
#include <qpushbutton.h>

QtImpCapturaGeneralesContratoBeneficios::QtImpCapturaGeneralesContratoBeneficios(
						zContratoBeneficios *pzConBeneficios,
						QWidget *pQWParent,
						const char *pchrPtrName):
						CapturaGeneralesContratoBeneficios(pQWParent,pchrPtrName),
						zConBeneficios(pzConBeneficios),
						intAceptar(0)
{

Conexion((zSiscomConexion *)gzSiscomConexion);
IniciaVariables();
ConectaSlots();

exec();

}

void QtImpCapturaGeneralesContratoBeneficios::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
int QtImpCapturaGeneralesContratoBeneficios::Aceptar()
{
  return intAceptar;
}
void QtImpCapturaGeneralesContratoBeneficios::IniciaVariables()
{
    zSiscomQt3::Foco(QLELugar);
    MuestraDatos();
    SeHabilitaRegistro();
}

void QtImpCapturaGeneralesContratoBeneficios::ConectaSlots()
{
   connect(QLELugar,
   	   SIGNAL(returnPressed()),
	   SLOT(SlotFocoAFecha()));
   connect(QLEFecha,
   	   SIGNAL(returnPressed()),
	   SLOT(SlotFocoARegistrar()));
   connect(QPBRegistrar,
   	   SIGNAL(clicked()),
	   SLOT(SlotRegistrar()));
   connect(QPBAceptar,
   	   SIGNAL(clicked()),
	   SLOT(SlotAceptar()));
   connect(QPBCancelar,
   	   SIGNAL(clicked()),
	   SLOT(SlotCancelar()));
}
void QtImpCapturaGeneralesContratoBeneficios::SlotCancelar()
{
    intAceptar=0;
    done(0);
}
void QtImpCapturaGeneralesContratoBeneficios::SlotAceptar()
{
	intAceptar=1;
	done(1);
}
void QtImpCapturaGeneralesContratoBeneficios::SlotRegistrar()
{
     if(Registrando())
     {
     QPBRegistrar->setEnabled(false);
     zSiscomQt3::Foco(QPBAceptar);
     }
}
void QtImpCapturaGeneralesContratoBeneficios::SlotFocoAFecha()
{
   zSiscomQt3::Foco(QLEFecha);
}
void QtImpCapturaGeneralesContratoBeneficios::SlotFocoARegistrar()
{
    zSiscomQt3::Foco(QPBRegistrar);
}

void QtImpCapturaGeneralesContratoBeneficios::AnexaDatos()
{
const char *lchrPtrFecha=strdup((const char *)QLEFecha->text());
zGenBeneficios=new zGeneralesBeneficios(zConBeneficios->IdVenta());
zGenBeneficios->Lugar(zSiscomQt3::Texto(QLELugar));
zGenBeneficios->Fecha(lchrPtrFecha);
zConBeneficios->GeneralesContrato(zGenBeneficios);
}
int QtImpCapturaGeneralesContratoBeneficios::Registra()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"RegistraGeneralesContratoBeneficios");
return lzOpServiSNTE.RegistraGeneralesBeneficios(zGenBeneficios);
}
int QtImpCapturaGeneralesContratoBeneficios::Registrando()
{
     AnexaDatos();
     if(Registra())
     {
 	QPBAceptar->setEnabled(true);
	zSiscomQt3::Foco(QPBAceptar);
     }
     else
     {
 	return 0;
     }
} 

void QtImpCapturaGeneralesContratoBeneficios::MuestraDatos()
{
    QLELugar->setText(zConBeneficios->Lugar());
    QLEFecha->setText(zConBeneficios->Fecha());
}
int QtImpCapturaGeneralesContratoBeneficios::SeHabilitaRegistro()
{
  QPBRegistrar->setEnabled(!((*zConBeneficios->Lugar()) &&
      (*zConBeneficios->Fecha())));
}
void QtImpCapturaGeneralesContratoBeneficios::reject()
{

}
