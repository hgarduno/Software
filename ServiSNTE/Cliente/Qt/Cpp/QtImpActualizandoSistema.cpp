#include <QtImpActualizandoSistema.h>
#include <zVerificaActualizacion.h>
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

QtImpActualizandoSistema::QtImpActualizandoSistema(
			QWidget *pQWParent,
			const char *pchrPtrName,
			bool pbModal,
			WFlags pWFlags):
		ActualizandoSistema(pQWParent,pchrPtrName,pbModal,pWFlags)
{
 IniciaVariables();
 ConectaSlots();
}
void QtImpActualizandoSistema::IniciaVariables()
{
  if(HayActualizacionDisponible())
  {
	exec();
  }
}
void QtImpActualizandoSistema::ConectaSlots()
{

}
void QtImpActualizandoSistema::reject()
{


}
int QtImpActualizandoSistema::HayActualizacionDisponible()
{
zVerificaActualizacion lzVerActualizacion((zSiscomConexion *)gzSiscomConexion,
						 "ActualizacionDisponible");
LogSiscom("Lanzando verificacion de actualizacion");
}
