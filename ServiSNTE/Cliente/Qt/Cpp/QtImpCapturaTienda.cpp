#include <QtImpCapturaTienda.h>

#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>

#include <QCtrlTipoVentas.h>
#include <QCtrlFinanciadoras.h>

#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <qpushbutton.h>
QtImpCapturaTienda::QtImpCapturaTienda(QWidget *pQWParent,
				     const char *pchrPtrName):
				     CapturaTienda(pQWParent,pchrPtrName)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 IniciaControles();
 ConectaSlots();

}

void QtImpCapturaTienda::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpCapturaTienda::ConectaSlots()
{

}


void QtImpCapturaTienda::IniciaControles()
{
 
 QCtrTipoVentas->Servidor(zSisConexion);
 QCtrTipoVentas->IniciaControl();

 QCtrFinanciadoras->Servidor(zSisConexion);
 QCtrFinanciadoras->IniciaControl();

 
}

