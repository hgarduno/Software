#include <QtImpRegistroUsuarios.h>
#include <zReportesServiSNTE.h>
#include <QCtrlPerfilesSS.h>

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
#include <qpushbutton.h>
#include <qlineedit.h>
QtImpRegistroUsuarios::QtImpRegistroUsuarios(QWidget *pQWParent,
					       const char *pchrPtrName):
					   RegistroUsuarios(pQWParent,pchrPtrName)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpRegistroUsuarios::IniciaVariables()
{
 zSiscomQt3::Foco(QLENombre);
 QCtrPerfiles->Servidor(zSisConexion);
 QCtrPerfiles->IniciaControl();
}
void QtImpRegistroUsuarios::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpRegistroUsuarios::ConectaSlots()
{
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotNombre()));
	connect(QLEApellidoPaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotApellidoPaterno()));
	connect(QLEApellidoMaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotApellidoMaterno()));
	connect(QCtrPerfiles,
		SIGNAL(SignalPerfil(zSiscomRegistro *)),
		SLOT(SlotCtrPerfiles()));
	connect(QLEFirma,
		SIGNAL(returnPressed()),
		SLOT(SlotFirma()));
	connect(QLEContrasena,
		SIGNAL(returnPressed()),
		SLOT(SlotContrasena()));
	connect(QLERepetirContrasena,
		SIGNAL(returnPressed()),
		SLOT(SlotRepetirContrasena()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistrar()));
}

void QtImpRegistroUsuarios::SlotNombre()
{
	zSiscomQt3::Foco(QLEApellidoPaterno);
}

void QtImpRegistroUsuarios::SlotApellidoPaterno()
{
	zSiscomQt3::Foco(QLEApellidoMaterno);
}

void QtImpRegistroUsuarios::SlotApellidoMaterno()
{
	zSiscomQt3::Foco(QCtrPerfiles);
}

void QtImpRegistroUsuarios::SlotCtrPerfiles()
{
	zSiscomQt3::Foco(QLEFirma);
}

void QtImpRegistroUsuarios::SlotFirma()
{
	zSiscomQt3::Foco(QLEContrasena);
}

void QtImpRegistroUsuarios::SlotContrasena()
{
	zSiscomQt3::Foco(QLERepetirContrasena);
}

void QtImpRegistroUsuarios::SlotRepetirContrasena()
{
	QPBRegistrar->setEnabled(true);
	zSiscomQt3::Foco(QPBRegistrar);
}

void QtImpRegistroUsuarios::SlotRegistrar()
{	
	RegistrarUsuario();
	zSiscomQt3::Foco(QLENombre);
}

void QtImpRegistroUsuarios::RegistrarUsuario()
{
	int lintRegresoRegistro;

//	zPerUsuario=FormaUsuario();	
}

zUsuario *QtImpRegistroUsuarios::FormaUsuario()
{
/*return new zUsuario(zSiscomQt3::Texto(QLENombre),
		     zSiscomQt3::Texto(QLEApellidoPaterno),
                     zSiscomQt3::Texto(QLEApellidoMaterno),
		     0,
                     zSiscomQt3::Texto(QLEFirma),
                     zSiscomQt3::Texto(QLEContrasena),
                     zSiscomQt3::Texto(QLERepetirContrasena));*/
}
