/*#include <QtImpCancelarFolioAbono.h>


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

#include <zReciboApartado.h>
#include <qlineedit.h> 
#include <qpushbutton.h>
#include <qtextedit.h>

QtImpCancelarFolioAbono::QtImpCancelarFolioAbono(
		  	zVenta *pzVenta,
			QWidget *pQWParent,
			const char *pchrPtrName,
			bool pbModal,
			WFlags pWFlags):
		CancelarFolioAbono(pQWParent,pchrPtrName,pbModal,pWFlags),
		intAceptar(0),
		zVentaDat(pzVenta)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 IniciaVariables();
 ConectaSlots();
 exec();
}
void QtImpCancelarFolioAbono::ConectaSlots()
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
void QtImpCancelarFolioAbono::SlotRegistrarCancelacion()
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"RegistraCancelacionFolio");
lzOpeServiSNTE.CancelarFolioAbonoFactura(zVentaDat,
				    zSiscomQt3::Texto(QLEFolioAAsignar),
				    (const char *)QTEMotivo->text());
zVentaDat->Folio((const unsigned char *)strdup(zSiscomQt3::Texto(QLEFolioAAsignar)));
QPBRegistrarCancelacion->setEnabled(false);
}
void QtImpCancelarFolioAbono::SlotAceptar()
{
	intAceptar=1;
	done(1);
}
void QtImpCancelarFolioAbono::SlotCancelar()
{
	intAceptar=0;
	done(1);
}
void QtImpCancelarFolioAbono::reject()
{

}
int QtImpCancelarFolioAbono::Aceptar()
{
  return intAceptar;
}

void QtImpCancelarFolioAbono::IniciaVariables()
{
   QLEFolioCancelar->setText(zVentaDat->Folio());
   ObtenFolio();
   zSiscomQt3::Foco(QTEMotivo);
}
void QtImpCancelarFolioAbono::Conexion(zSiscomConexion *pzSisConexion)
{
  zSisConexion=pzSisConexion;
}

void QtImpCancelarFolioAbono::ObtenFolio()
{
char lchrArrFolio[10];
  zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"FolioActual");
  lzOpServiSNTE.FolioActualFactura("1",lchrArrFolio);
  QLEFolioAAsignar->setText(lchrArrFolio);
}*/
