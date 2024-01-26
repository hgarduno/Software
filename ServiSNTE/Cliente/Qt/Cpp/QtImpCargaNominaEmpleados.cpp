#include <QtImpCargaNominaEmpleados.h>

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
#include <qfiledialog.h>
#include <qlineedit.h>
QtImpCargaNominaEmpleados::QtImpCargaNominaEmpleados(QWidget *pQWParent,
				     const char *pchrPtrName):
				     CargaNominaEmpleados(pQWParent,pchrPtrName)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 ConectaSlots();

}

void QtImpCargaNominaEmpleados::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpCargaNominaEmpleados::ConectaSlots()
{
 connect(QPBSelArchivo,
 	SIGNAL(clicked()),
	SLOT(SlotSelArchivo()));
}


void QtImpCargaNominaEmpleados::SlotSelArchivo()
{
ObtenArchivo();
IniciaEnvioArchivo();
EnviaArchivo(); 
}
void QtImpCargaNominaEmpleados::IniciaEnvioArchivo()
{
   zSisEnviaArchivo=new zSiscomEnviaArchivo((const char *)QLEArchivoNomina->text(),
   					    zSisConexion);
}
void QtImpCargaNominaEmpleados::ObtenArchivo()
{

 QLEArchivoNomina->setText(QFileDialog::getOpenFileName(
                     "/home/hgarduno/ServiSNTE/Documentacion",
		     "Archivos Nomina (*.txt)",
			this,
		      "Archivos Nomina Empleados",
		      "Selecciona Un Archivo"));
}

void QtImpCargaNominaEmpleados::EnviaArchivo()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,
				    "CargaNominaEmpleados");

lzOpServiSNTE.EnviaArchivoNomina((const char *)QLEArchivoNomina->text(),
				 zSisEnviaArchivo);
}
