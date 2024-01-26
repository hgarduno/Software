#include <QtImpCatalogoStock.h>

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

#include <zDireccion.h>
#include <zPersona.h>
#include <zOperacionesServiSNTE.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtextedit.h>
 
QtImpCatalogoStock::QtImpCatalogoStock(
					 QWidget *pQWParent,
				     const char *pchrPtrName):
				     CatalogoStock(pQWParent,pchrPtrName)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 IniciaControles();
 IniciaVariables();
 ConectaSlots();
}

void QtImpCatalogoStock::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpCatalogoStock::ConectaSlots()
{

}

void QtImpCatalogoStock::IniciaControles()
{

}

void QtImpCatalogoStock::IniciaVariables()
{

}


