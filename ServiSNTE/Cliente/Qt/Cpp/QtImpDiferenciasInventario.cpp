#include <QtImpDiferenciasInventario.h>
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
#include <qpushbutton.h>
#include <qtextedit.h>
QtImpDiferenciasInventario::QtImpDiferenciasInventario(QWidget *pQWParent,
					       const char *pchrPtrName):
					   DiferenciasInventario(pQWParent,pchrPtrName)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpDiferenciasInventario::IniciaVariables()
{

}
void QtImpDiferenciasInventario::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpDiferenciasInventario::ConectaSlots()
{

}
