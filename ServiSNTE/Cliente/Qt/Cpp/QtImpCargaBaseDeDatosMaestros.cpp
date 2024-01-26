#include <QtImpCargaBaseDeDatosMaestros.h>

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
QtImpCargaBaseDeDatosMaestros::QtImpCargaBaseDeDatosMaestros(QWidget *pQWParent,
				     const char *pchrPtrName):
				     CargaBaseDeDatosMaestros(pQWParent,pchrPtrName)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 ConectaSlots();

}

void QtImpCargaBaseDeDatosMaestros::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpCargaBaseDeDatosMaestros::ConectaSlots()
{
 connect(QPBSelArchivo,
 	SIGNAL(clicked()),
	SLOT(SlotSelArchivo()));
}

void QtImpCargaBaseDeDatosMaestros::SlotSelArchivo()
{
ObtenArchivo();
IniciaEnvioArchivo();
EnviaArchivo(); 
}
void QtImpCargaBaseDeDatosMaestros::IniciaEnvioArchivo()
{
   zSisEnviaArchivo=new zSiscomEnviaArchivo((const char *)QLEArchivoNomina->text(),
   					    zSisConexion);
}
void QtImpCargaBaseDeDatosMaestros::ObtenArchivo()
{

 QLEArchivoNomina->setText(QFileDialog::getOpenFileName(
                     "/home/hgarduno/ServiSNTE/Documentacion",
		     "Bases de Maestros (*.csv)",
			this,
		      "Archivos Bases de Datos Maestros",
		      "Selecciona Un Archivo"));
}

void QtImpCargaBaseDeDatosMaestros::EnviaArchivo()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,
				    "CargaBaseDeDatosMaestros");

lzOpServiSNTE.EnviaArchivoNomina((const char *)QLEArchivoNomina->text(),
				 zSisEnviaArchivo);
}
