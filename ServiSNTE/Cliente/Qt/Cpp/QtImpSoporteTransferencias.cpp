#include <QtImpSoporteTransferencias.h>
#include <QtImprimiendoSoporteTransferencias.h>
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

#include <zSoporteTransferencias.h>
#include <zImpresionSoporteTransferencias.h>

#include <zOperacionesServiSNTE.h>
#include <qpushbutton.h>
#include <qtextedit.h>
QtImpSoporteTransferencias::QtImpSoporteTransferencias(QWidget *pQWParent,
					       const char *pchrPtrName):
					   SoporteTransferencias(pQWParent,pchrPtrName)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpSoporteTransferencias::IniciaVariables()
{
        QCtrTiendas->Servidor(zSisConexion);
        QCtrTiendas->IniciaControl();
        zSiscomQt3::Foco(QCtrTiendas);
}
void QtImpSoporteTransferencias::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpSoporteTransferencias::ConectaSlots()
{
        connect(QCtrTiendas,
            SIGNAL(SignalTienda(zSiscomRegistro *)),
            SLOT(SlotTienda(zSiscomRegistro *)));
	 connect(QPBImprimir,
           SIGNAL(clicked()),
           SLOT(SlotImprimir()));
}

void QtImpSoporteTransferencias::SlotTienda(zSiscomRegistro *pzSisRegTienda)
{
        zSisRegTienda=pzSisRegTienda;
        zSiscomQt3::Foco(QLERangoFechas);
}
void QtImpSoporteTransferencias::SlotImprimir()
{
zImpresionSoporteTransferencias *lzImpSoporteTransferencias=new zImpresionSoporteTransferencias(zSptTransferencias);
QtImprimiendoSoporteTransferencias lQtImpSoporteTransferencias(zSisConexion,
                                                 lzImpSoporteTransferencias);
}

