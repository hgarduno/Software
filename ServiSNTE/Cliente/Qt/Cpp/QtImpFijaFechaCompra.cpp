#include <QtImpFijaFechaCompra.h>
#include <QCtrlProveedoresSS.h>
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

#include <zDireccion.h>
#include <zPersona.h>
#include <zOperacionesServiSNTE.h> 
#include <qlineedit.h>
#include <qtextedit.h>
#include <qpushbutton.h>
QtImpFijaFechaCompra::QtImpFijaFechaCompra(
					 QWidget *pQWParent,
				     const char *pchrPtrName):
				     FijaFechaCompra(pQWParent,pchrPtrName)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 IniciaControles();
 IniciaVariables();
 ConectaSlots();
}

void QtImpFijaFechaCompra::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpFijaFechaCompra::ConectaSlots()
{
	connect(QCtrProveedores,
		SIGNAL(SignalProveedor(zSiscomRegistro *)),
		SLOT(SlotProveedor(zSiscomRegistro *)));
	connect(QLEFecha,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoARegistraFecha()));
	connect(QPBRegistraFecha,
		SIGNAL(clicked()),
		SLOT(SlotRegistraFecha()));
}
void QtImpFijaFechaCompra::SlotRegistraFecha()
{
  FijandoFechaCompra();
}
void QtImpFijaFechaCompra::SlotFocoARegistraFecha()
{
	zSiscomQt3::Foco(QPBRegistraFecha);
}
void QtImpFijaFechaCompra::SlotProveedor(zSiscomRegistro *pzSisProveedor)
{
   zSisProveedor=pzSisProveedor;
   QLEFecha->setEnabled(true);
   zSiscomQt3::Foco(QLEFecha);
}
void QtImpFijaFechaCompra::IniciaControles()
{
   QCtrProveedores->Servidor(zSisConexion);
   QCtrProveedores->IniciaControl();
}

void QtImpFijaFechaCompra::IniciaVariables()
{
  zSiscomQt3::Foco(QCtrProveedores);
}


void QtImpFijaFechaCompra::FijandoFechaCompra()
{
zOperacionesServiSNTE lzOpServFijaFecha(zSisConexion,"FijaFechaCompra");
lzOpServFijaFecha.FijaFechaCompra(zSisProveedor,(const char *)QLEFecha->text());
}
