#include <QtImpCancelarFolio.h>


#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>


#include <zOperacionesServiSNTE.h>

#include <zVenta.h>
#include <qlineedit.h> 
#include <qpushbutton.h>
#include <qtextedit.h>

QtImpCancelarFolio::QtImpCancelarFolio(
		  	zVenta *pzVenta,
			QWidget *pQWParent,
			const char *pchrPtrName,
			bool pbModal,
			WFlags pWFlags):
		CancelarFolio(pQWParent,pchrPtrName,pbModal,pWFlags),
		intAceptar(0),
		zVentaDat(pzVenta)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 IniciaVariables();
 ConectaSlots();
 exec();
}
void QtImpCancelarFolio::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QPBRegistrarCancelacion,
		SIGNAL(clicked()),
		SLOT(SlotRegistrarCancelacion()));
}
void QtImpCancelarFolio::SlotRegistrarCancelacion()
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"RegistraCancelacionFolio");
lzOpeServiSNTE.CancelarFolioFactura(zVentaDat,
				    zSiscomQt3::Texto(QLEFolioAAsignar),
				    (const char *)QTEMotivo->text());
zVentaDat->Folio((const unsigned char *)strdup(zSiscomQt3::Texto(QLEFolioAAsignar)));
QPBRegistrarCancelacion->setEnabled(false);
}
void QtImpCancelarFolio::SlotAceptar()
{
	intAceptar=1;
	done(1);
}
void QtImpCancelarFolio::SlotCancelar()
{
	intAceptar=0;
	done(1);
}
void QtImpCancelarFolio::reject()
{

}
int QtImpCancelarFolio::Aceptar()
{
  return intAceptar;
}

void QtImpCancelarFolio::IniciaVariables()
{
   QLEFolioCancelar->setText(zVentaDat->Folio());
   ObtenFolio();
   zSiscomQt3::Foco(QTEMotivo);
}
void QtImpCancelarFolio::Conexion(zSiscomConexion *pzSisConexion)
{
  zSisConexion=pzSisConexion;
}

void QtImpCancelarFolio::ObtenFolio()
{
char lchrArrFolio[10];
  zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"FolioActual");
  lzOpServiSNTE.FolioActualFactura("0",lchrArrFolio);
  QLEFolioAAsignar->setText(lchrArrFolio);
}
