#include <QtImpSoporteCompras.h>
#include <QtImprimiendoSoporteCompras.h>
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
#include <zImpresionSoporteCompras.h>
#include <zSoporteCompras.h>

#include <zOperacionesServiSNTE.h>
#include <qpushbutton.h>
#include <qtextedit.h>
QtImpSoporteCompras::QtImpSoporteCompras(QWidget *pQWParent,
					       const char *pchrPtrName):
					   SoporteCompras(pQWParent,pchrPtrName)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpSoporteCompras::IniciaVariables()
{
        QCtrTiendas->Servidor(zSisConexion);
        QCtrTiendas->IniciaControl();
        zSiscomQt3::Foco(QCtrTiendas);
}
void QtImpSoporteCompras::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpSoporteCompras::ConectaSlots()
{
        connect(QCtrTiendas,
            SIGNAL(SignalTienda(zSiscomRegistro *)),
            SLOT(SlotTienda(zSiscomRegistro *)));
	connect(QPBImprimir,
            SIGNAL(clicked()),
            SLOT(SlotImprimir()));
}

void QtImpSoporteCompras::SlotTienda(zSiscomRegistro *pzSisRegTienda)
{
        zSisRegTienda=pzSisRegTienda;
        zSiscomQt3::Foco(QLERangoFechas);
}
void QtImpSoporteCompras::SlotImprimir()
{
zImpresionSoporteCompras *lzImpSoporteCompras=new zImpresionSoporteCompras(zLstSoporte);
QtImprimiendoSoporteCompras lQtImpSoporteCompras(zSisConexion,
                                                 lzImpSoporteCompras);
}
