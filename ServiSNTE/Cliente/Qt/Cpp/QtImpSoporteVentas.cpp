#include <QtImpSoporteVentas.h>
#include <QtImprimiendoSoporteVentas.h>
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

#include <QCtrlTiendasEntrega.h>
#include <zImpresionSoporteVentas.h>
#include <zSoporteVentas.h>

#include <zOperacionesServiSNTE.h>
#include <qpushbutton.h>
#include <qtextedit.h>
QtImpSoporteVentas::QtImpSoporteVentas(QWidget *pQWParent,
					       const char *pchrPtrName):
					   SoporteVentas(pQWParent,pchrPtrName)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpSoporteVentas::IniciaVariables()
{
        QCtrTiendas->Servidor(zSisConexion);
        QCtrTiendas->IniciaControl();
        zSiscomQt3::Foco(QCtrTiendas);
}
void QtImpSoporteVentas::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpSoporteVentas::ConectaSlots()
{
        connect(QCtrTiendas,
            SIGNAL(SignalTienda(zSiscomRegistro *)),
            SLOT(SlotTienda(zSiscomRegistro *)));
 	connect(QPBImprimir,
            SIGNAL(clicked()),
            SLOT(SlotImprimir()));
}

void QtImpSoporteVentas::SlotTienda(zSiscomRegistro *pzSisRegTienda)
{
        zSisRegTienda=pzSisRegTienda;
        zSiscomQt3::Foco(QLERangoFechas);
}
void QtImpSoporteVentas::SlotImprimir()
{
zImpresionSoporteVentas *lzImpSoporteVentas=new zImpresionSoporteVentas(zSptVentas);
QtImprimiendoSoporteVentas lQtImpSoporteVentas(zSisConexion,
                                                 lzImpSoporteVentas);
}

