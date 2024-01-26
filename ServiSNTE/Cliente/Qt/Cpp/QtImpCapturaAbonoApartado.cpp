#include <QtImpCapturaAbonoApartado.h>

#include <qlineedit.h> 
#include <qpushbutton.h>
#include <zSiscomQt3.h>

#include <zOperacionesServiSNTE.h>
#include <zReciboApartado.h>

QtImpCapturaAbonoApartado::QtImpCapturaAbonoApartado(	
			zSiscomConexion *pzSisConexion,
			QWidget *pQWParent,
			const char *pchrPtrName,
			bool pbModal,
			WFlags pWFlags):
		CapturaAbonoApartado(pQWParent,pchrPtrName,pbModal,pWFlags),
		intAceptar(0),
		zSisConexion(pzSisConexion)
{
 IniciaVariables();
 ConectaSlots();
 exec();
}
void QtImpCapturaAbonoApartado::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QLEFolio,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoACantidad()));
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(SlotCantidad()));
}
void QtImpCapturaAbonoApartado::SlotFocoACantidad()
{
zSiscomQt3::Foco(QLECantidad);
}
void QtImpCapturaAbonoApartado::SlotAceptar()
{
	intAceptar=1;
	done(1);
}
void QtImpCapturaAbonoApartado::SlotCancelar()
{
	intAceptar=0;
	done(1);
}
void QtImpCapturaAbonoApartado::SlotCantidad()
{
	zSiscomQt3::Foco(QPBAceptar);
}
void QtImpCapturaAbonoApartado::reject()
{

}
void QtImpCapturaAbonoApartado::Cantidad(zReciboApartado *pzRecibo)
{
   pzRecibo->Importe(strdup((const char *)QLECantidad->text()));
   pzRecibo->FolioApartado(strdup((const char *)QLEFolio->text()));
}
int QtImpCapturaAbonoApartado::Aceptar()
{
  return intAceptar;
}

void QtImpCapturaAbonoApartado::IniciaVariables()
{
   zSiscomQt3::Foco(QLEFolio);
   ObtenFolio();   
}

void QtImpCapturaAbonoApartado::ObtenFolio()
{
char lchrArrFolio[10];
  zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"FolioActual");
  lzOpServiSNTE.FolioActualFactura("1",lchrArrFolio);
QLEFolio->setText(lchrArrFolio);
SlotFocoACantidad();
}
