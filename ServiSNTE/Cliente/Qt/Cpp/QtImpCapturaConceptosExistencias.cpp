#include <QtImpCapturaConceptosExistencias.h>

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

#include <qpushbutton.h>
QtImpCapturaConceptosExistencias::QtImpCapturaConceptosExistencias(QWidget *pQWParent,
				     const char *pchrPtrName):
				     CapturaConceptosExistencias(pQWParent,pchrPtrName)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 ConectaSlots();

}

void QtImpCapturaConceptosExistencias::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpCapturaConceptosExistencias::ConectaSlots()
{
}
