#include <zSiscomVentanaOpcion.h>
#include <zSiscomRegistros.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
zSiscomVentanaOpcion::zSiscomVentanaOpcion(zSiscomConfiguracion *pzSisConfiguracion,
					   QWidget *pQWParent,
					   const char *pchrPtrName,
					   WFlags pWFOpciones):
					   QWidget(pQWParent,pchrPtrName,pWFOpciones)
{


}

zSiscomVentanaOpcion::zSiscomVentanaOpcion(QWidget *pQWParent,
					   const char *pchrPtrNombre,
					   WFlags pWFlags):
					  QWidget(pQWParent,pchrPtrNombre,pWFlags)
{


}

void zSiscomVentanaOpcion::Configuracion(zSiscomConfiguracion *pzSisConfiguracion)
{
	zSisConfiguracion=pzSisConfiguracion;
}
zSiscomConfiguracion *zSiscomVentanaOpcion::Configuracion()
{
 return zSisConfiguracion;
}
void zSiscomVentanaOpcion::Conexion(zSiscomConexion *pzSisConexion)
{
LogSiscom("Se Inicializa la conexion");
zSisConexion=pzSisConexion;
}
