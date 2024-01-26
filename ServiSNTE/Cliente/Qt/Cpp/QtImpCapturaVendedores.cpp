#include <QtImpCapturaVendedores.h>

#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>
#include <QCtrlTiendasEntrega.h>

#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <qpushbutton.h>
QtImpCapturaVendedores::QtImpCapturaVendedores(QWidget *pQWParent,
				     const char *pchrPtrName):
				     CapturaVendedores(pQWParent,pchrPtrName)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 ConectaSlots();
 IniciaControles();

}

void QtImpCapturaVendedores::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpCapturaVendedores::ConectaSlots()
{
}

void QtImpCapturaVendedores::IniciaControles()
{
 QCtrTienda->Servidor(zSisConexion);
 QCtrTienda->IniciaControl();
}

