#include <QtImpRepExistenciaTiendaProveedor.h>
#include <QtImprimiendoRepExistenciaTiendaProveedor.h>
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

#include <zExistenciaTiendaProveedor.h>
#include <zImpresionExistenciaTiendaProveedor.h>

#include <zOperacionesServiSNTE.h>
#include <qpushbutton.h>
#include <qtextedit.h>
QtImpRepExistenciaTiendaProveedor::QtImpRepExistenciaTiendaProveedor(QWidget *pQWParent,
					       const char *pchrPtrName):
					   RepExistenciaTiendaProveedor(pQWParent,pchrPtrName)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpRepExistenciaTiendaProveedor::IniciaVariables()
{

}
void QtImpRepExistenciaTiendaProveedor::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpRepExistenciaTiendaProveedor::ConectaSlots()
{
	connect(QPBImprimir,
	   SIGNAL(clicked()),
	   SLOT(SlotImprimir()));
}

void QtImpRepExistenciaTiendaProveedor::SlotImprimir()
{
zImpresionExistenciaTiendaProveedor *lzImpExistenciaTiendaProveedor=new zImpresionExistenciaTiendaProveedor(zExtTiendaProveedor);
QtImprimiendoRepExistenciaTiendaProveedor lQtImpRepExistenciaTiendaProveedor(zSisConexion,
                                                 lzImpExistenciaTiendaProveedor);
}

