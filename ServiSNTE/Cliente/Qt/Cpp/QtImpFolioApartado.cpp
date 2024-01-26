#include <QtImpFolioApartado.h>


#include <QCtrlTiendasEntrega.h>
#include <QCtrlTiposFolio.h>
#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>

#include <zOperacionesServiSNTE.h>


#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <zFolio.h>

#include <qlineedit.h> 
#include <qpushbutton.h>


QtImpFolioApartado::QtImpFolioApartado(
					 QWidget *pQWParent,
				     const char *pchrPtrName,
				     WFlags pWFlags):
				     FolioApartado(pQWParent,pchrPtrName),
					 zSisRegTienda(0)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 ConectaSlots();
 IniciaVariables();
}


void QtImpFolioApartado::IniciaVariables()
{
	QCtrTiendas->Servidor(zSisConexion);	
	QCtrTiendas->IniciaControl();

	QCtrTiposFolio->Servidor(zSisConexion);	
	QCtrTiposFolio->IniciaControl();

	zSiscomQt3::Foco(QCtrTiposFolio);
}

void QtImpFolioApartado::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpFolioApartado::ConectaSlots()
{
	connect(QCtrTiendas,
		SIGNAL(SignalTienda(zSiscomRegistro *)),
		SLOT(SlotTienda(zSiscomRegistro *)));
	connect(QLEFolioInicio,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAFolioFin()));
	connect(QLEFolioFin,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoARegistrar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistrar()));
	connect(QCtrTiposFolio,
		SIGNAL(SignalFolio(zSiscomRegistro *)),
		SLOT(SlotTipoFolio(zSiscomRegistro *)));
}
void QtImpFolioApartado::SlotTipoFolio(zSiscomRegistro *pzSisRegTipoFolio)
{
    zSisRegTipoFolio=pzSisRegTipoFolio;
    zSiscomQt3::Foco(QCtrTiendas);
}
void QtImpFolioApartado::SlotRegistrar()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"RegistraFolio");
lzOpServiSNTE.RegistraFolio(Folio());
}
void QtImpFolioApartado::SlotFocoARegistrar()
{
  zSiscomQt3::Foco(QPBRegistrar);
}
void QtImpFolioApartado::SlotFocoAFolioFin()
{
	zSiscomQt3::Foco(QLEFolioFin);
}
void QtImpFolioApartado::SlotTienda(zSiscomRegistro *pzSisRegTienda)
{
    zSisRegTienda=pzSisRegTienda;
    zSiscomQt3::Foco(QLEFolioInicio);
}
zFolio *QtImpFolioApartado::Folio()
{

return new zFolio(zSisRegTienda,
		  zSisRegTipoFolio,
		  zSiscomQt3::Texto(QLEFolioInicio),
		  zSiscomQt3::Texto(QLEFolioFin));


}
