#include <QtImpDesajusteInventario.h>
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
QtImpDesajusteInventario::QtImpDesajusteInventario(QWidget *pQWParent,
					       const char *pchrPtrName):
					   DesajusteInventario(pQWParent,pchrPtrName)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpDesajusteInventario::IniciaVariables()
{
        QCtrTiendas->Servidor(zSisConexion);
        QCtrTiendas->IniciaControl();
        zSiscomQt3::Foco(QCtrTiendas);
}
void QtImpDesajusteInventario::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpDesajusteInventario::ConectaSlots()
{
        connect(QCtrTiendas,
            SIGNAL(SignalTienda(zSiscomRegistro *)),
            SLOT(SlotTienda(zSiscomRegistro *)));
}

void QtImpDesajusteInventario::SlotTienda(zSiscomRegistro *pzSisRegTienda)
{
        zSisRegTienda=pzSisRegTienda;
}

