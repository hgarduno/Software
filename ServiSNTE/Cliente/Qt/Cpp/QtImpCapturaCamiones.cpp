#include <QtImpCapturaCamiones.h>

#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>

#include <zOperacionesServiSNTE.h>


#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <zCamion.h> 
#include <qlineedit.h> 
#include <qcheckbox.h> 
#include <qpushbutton.h>
QtImpCapturaCamiones::QtImpCapturaCamiones(
					 QWidget *pQWParent,
				     const char *pchrPtrName,
				     bool pbModal,
				     WFlags pWFlags):
				     CapturaCamiones(pQWParent,pchrPtrName),
					 zDatCamion(0)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 ConectaSlots();

}

void QtImpCapturaCamiones::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpCapturaCamiones::ConectaSlots()
{
	connect(QPBCrear,
		SIGNAL(clicked()),
		SLOT(SlotCrear()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QLEClaveCamion,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoANombre()));
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAMarca()));
	connect(QLEMarca,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoATipo()));
	connect(QLETipo,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAModelo()));
	connect(QLEModelo,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAPlacas()));
	connect(QLEPlacas,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoACrear()));

}
void QtImpCapturaCamiones::SlotFocoANombre()
{
	zSiscomQt3::Foco(QLENombre);
}
void QtImpCapturaCamiones::SlotFocoAMarca()
{
	zSiscomQt3::Foco(QLEMarca);
}
void QtImpCapturaCamiones::SlotFocoATipo()
{
	zSiscomQt3::Foco(QLETipo);
}
void QtImpCapturaCamiones::SlotFocoAModelo()
{
	zSiscomQt3::Foco(QLEModelo);
}
void QtImpCapturaCamiones::SlotFocoAPlacas()
{
	zSiscomQt3::Foco(QLEPlacas);
}
void QtImpCapturaCamiones::SlotFocoACrear()
{
	zSiscomQt3::Foco(QPBCrear);
}
void QtImpCapturaCamiones::SlotCrear()
{
	zDatCamion=FormaCamion();
	
	zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"RegistraCamion");
	lzOpServiSNTE.RegistraCamion(zDatCamion);
}
void QtImpCapturaCamiones::SlotCancelar()
{
	
}
void QtImpCapturaCamiones::reject()
{
}
zCamion *QtImpCapturaCamiones::FormaCamion()
{
	return new zCamion(0,
		      zSiscomQt3::Texto(QLENombre),
		      zSiscomQt3::Texto(QLEMarca),
		      zSiscomQt3::Texto(QLETipo),
		      zSiscomQt3::Texto(QLEModelo),
		      zSiscomQt3::Texto(QLEPlacas));
}
zCamion *QtImpCapturaCamiones::Camion()
{
	return zDatCamion;
}
