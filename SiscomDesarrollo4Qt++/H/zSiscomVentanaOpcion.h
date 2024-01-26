#ifndef __ZSISCOMVENTANAOPCION_H__
#define __ZSISCOMVENTANAOPCION_H__


#include <qwidget.h>


class zSiscomConfiguracion;
class zSiscomConexion;
class zSiscomVentanaOpcion:public QWidget 
{
Q_OBJECT
public:
	zSiscomVentanaOpcion(zSiscomConfiguracion *pzSisConfiguracion,
			     QWidget *pQWParent=0,
			     const char *pchrPtrName=0,
			     WFlags pWFOpciones=false);
	zSiscomVentanaOpcion(QWidget *pQWParent,
			     const char *pchrPtrName,
			     WFlags pWFOpciones);
	void Configuracion(zSiscomConfiguracion *pzSisConfiguracion);
	zSiscomConfiguracion *Configuracion();
	void Conexion(zSiscomConexion *pzSisConexion);
private:
	zSiscomConfiguracion *zSisConfiguracion;
	zSiscomConexion *zSisConexion;
};
#endif


