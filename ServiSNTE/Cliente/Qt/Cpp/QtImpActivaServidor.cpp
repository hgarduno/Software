#include <QtImpActivaServidor.h>
#include <zReportesServiSNTE.h>
#include <QCtrlTiendasEntrega.h>
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

#include <zOperacionesServiSNTE.h>
#include <zAdministracionServiSNTE.h>
#include <qpushbutton.h>
#include <qtable.h>
QtImpActivaServidor::QtImpActivaServidor(QWidget *pQWParent,
					       const char *pchrPtrName):
					   ActivaServidor(pQWParent,pchrPtrName)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpActivaServidor::IniciaVariables()
{
	QCtrTiendas->Servidor(zSisConexion);
	QCtrTiendas->IniciaControl();
	zSiscomQt3::Foco(QCtrTiendas);
	Consultando();
}
void QtImpActivaServidor::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpActivaServidor::ConectaSlots()
{
	connect(QCtrTiendas,
		SIGNAL(SignalTienda(zSiscomRegistro *)),
		SLOT(SlotTienda(zSiscomRegistro*)));
	connect(QTServidores,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionaMaquina(int,int,int,const QPoint &)));
	connect(QPBCambiarConexionA,
		SIGNAL(clicked()),
		SLOT(SlotCambiarConexionA()));
}
void QtImpActivaServidor::SlotCambiarConexionA()
{
	zSisConexion->DireccionIp((const char *)(*zSisRegTienda)["dirip"]);
	zSisConexion->Puerto(zSisRegTienda->CampoInt("puertorn"));
	LogSiscom("Se Cambio la direccion a %s:%d",
		  zSisConexion->DireccionIp(),
		  zSisConexion->Puerto());
}
void QtImpActivaServidor::SlotSeleccionaMaquina(int pintMaquina,
						int,
						int,
						const QPoint &)
{
	QPBCambiarConexionA->setEnabled((zSisRegTienda=(*zSisRegsServidores)[pintMaquina]));
}
			
void QtImpActivaServidor::SlotTienda(zSiscomRegistro *pzSisRegTienda)
{
	zSiscomQt3::Foco(QPBConsulta);
	SiscomRegistroLog2(pzSisRegTienda);
	zSisRegTienda=pzSisRegTienda;
}
void QtImpActivaServidor::Consultando()
{
   Consulta();
   Muestra();
}
void QtImpActivaServidor::Consulta()
{
zAdministracionServiSNTE lzAdminServiSNTE(zSisConexion,"EstadoServidores");
zSisRegsServidores=lzAdminServiSNTE.EstadoServidores();
}
void QtImpActivaServidor::Muestra()
{
const char *lchrPtrCampos[]={"idmaquina","nombre","abreviatura","activo",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,zSisRegsServidores,QTServidores);
}
