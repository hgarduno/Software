#include <QtImpRegistroLibro.h>
#include <QtImprimiendoRepCuentasPagar.h>
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

#include <zCuentasPagar.h>
#include <zImpresionCuentasPagar.h>

#include <zOperacionesServiSNTE.h>
#include <qpushbutton.h>
#include <qtextedit.h>
QtImpRegistroLibro::QtImpRegistroLibro(QWidget *pQWParent,
					       const char *pchrPtrName):
					   RegistroLibro(pQWParent,pchrPtrName)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpRegistroLibro::IniciaVariables()
{

}
void QtImpRegistroLibro::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpRegistroLibro::ConectaSlots()
{
	connect(QPBImprimir,
           SIGNAL(clicked()),
           SLOT(SlotImprimir()));

}
void QtImpRegistroLibro::SlotImprimir()
{
zImpresionCuentasPagar *lzImpCuentasPagar=new zImpresionCuentasPagar(zCtsPagar);
QtImprimiendoRepCuentasPagar lQtImpRepCuentasPagar(zSisConexion,
                                                 lzImpCuentasPagar);
}

