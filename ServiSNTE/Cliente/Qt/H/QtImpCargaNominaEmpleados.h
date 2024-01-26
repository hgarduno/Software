#ifndef __QTIMPCARGANOMINAEMPLEADOS_H__
#define __QTIMPCARGANOMINAEMPLEADOS_H__
#include <cstddef>
#include <CargaNominaEmpleados.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomEnviaArchivo;

class QtImpCargaNominaEmpleados:public CargaNominaEmpleados
{
Q_OBJECT
public:
	QtImpCargaNominaEmpleados(QWidget *pQWParent,
			  const char *pchrPtrName);

public:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void ObtenArchivo();
	void IniciaEnvioArchivo();
	void EnviaArchivo();
private:
	zSiscomConexion *zSisConexion;
	zSiscomEnviaArchivo *zSisEnviaArchivo;
private slots:
	void SlotSelArchivo();
};



#endif
