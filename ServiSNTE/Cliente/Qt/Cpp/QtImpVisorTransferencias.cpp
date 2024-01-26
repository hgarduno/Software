#include <QtImpVisorTransferencias.h>
#include <zSiscomDesarrollo4.h>
#include <QCtrlTiendasEntrega.h>
#include <QCtrlVendedores.h>
#include <QCtrlCamiones.h>
#include <QCtrlCodigoBarras.h>
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
#include <zTransferencia.h>

#include <qpushbutton.h>
#include <qlineedit.h>
#include <qstring.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qmessagebox.h>


QtImpVisorTransferencias::QtImpVisorTransferencias(QWidget *pQWParent,
				     const char *pchrPtrName):
				     VisorTransferencias(pQWParent,pchrPtrName)
{
    Conexion((zSiscomConexion *)gzSiscomConexion);
    IniciaControles();
    IniciaVariables();
    ConectaSlots();
}

void QtImpVisorTransferencias::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpVisorTransferencias::ConectaSlots()
{

}

void QtImpVisorTransferencias::IniciaControles()
{

}

void QtImpVisorTransferencias::IniciaVariables()
{

}

void QtImpVisorTransferencias::Reinicia()
{
/*    MostrarTransferenciasTabla();
    QLETienda->setText((const char *)"");
    QLEResponsable->setText((const char *)"");
    QLEChofer->setText((const char *)"");
    QLECamion->setText((const char *)"");
    QTEObservacionGeneral->setText((const char *)"");
    while (QTDetalleTransferencias->numRows())
        QTDetalleTransferencias->removeRow(0);
    QPBRecibir->setEnabled(false);
*/
}


