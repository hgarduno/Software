#include <QtImpCapturaDescuentos.h>

#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>


#include <zOperacionesServiSNTE.h>
#include <zDescuento.h>
#include <qpushbutton.h>
#include <qlineedit.h>
QtImpCapturaDescuentos::QtImpCapturaDescuentos(QWidget *pQWParent,
					       const char *pchrPtrName,
					       bool pbModal,
					       WFlags pWFlags):
					   CapturaDescuentos(pQWParent,pchrPtrName,pbModal,pWFlags)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
	exec();
}
void QtImpCapturaDescuentos::IniciaVariables()
{
   zSiscomQt3::Foco(QLEDescuento1);

}
void QtImpCapturaDescuentos::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpCapturaDescuentos::ConectaSlots()
{
	connect(QLEDescuento1,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoADescuento2()));
	connect(QLEDescuento2,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoADescuento3()));

	connect(QLEDescuento3,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoADescuento4()));
	connect(QLEDescuento4,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAAceptar()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));

}
void QtImpCapturaDescuentos::SlotAceptar()
{
   done(1); 
}
void QtImpCapturaDescuentos::SlotFocoADescuento2()
{
	zSiscomQt3::Foco(QLEDescuento2);
}

void QtImpCapturaDescuentos::SlotFocoADescuento3()
{
	zSiscomQt3::Foco(QLEDescuento3);
}
void QtImpCapturaDescuentos::SlotFocoADescuento4()
{
	zSiscomQt3::Foco(QLEDescuento4);
}

void QtImpCapturaDescuentos::SlotFocoAAceptar()
{
	zSiscomQt3::Foco(QPBAceptar);
}

zDescuento *QtImpCapturaDescuentos::Descuento()
{
const char *lchrPtrDescuento1,
	   *lchrPtrDescuento2,
	   *lchrPtrDescuento3,
	   *lchrPtrDescuento4;
  lchrPtrDescuento1=zSiscomQt3::Texto(QLEDescuento1);
  lchrPtrDescuento2=zSiscomQt3::Texto(QLEDescuento2);
  lchrPtrDescuento3=zSiscomQt3::Texto(QLEDescuento3);
  lchrPtrDescuento4=zSiscomQt3::Texto(QLEDescuento4);
  if(lchrPtrDescuento1 ||
     lchrPtrDescuento2 ||
     lchrPtrDescuento3 ||
     lchrPtrDescuento4)
  return new zDescuento(0,
  			lchrPtrDescuento1,
  			lchrPtrDescuento2,
  			lchrPtrDescuento3,
  			lchrPtrDescuento4,
			0);
   else
   return 0;
}

