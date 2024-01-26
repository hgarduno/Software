#ifndef __QTIMPCARGABASEDEDATOSMAESTROS_H__
#define __QTIMPCARGABASEDEDATOSMAESTROS_H__
#include <cstddef>
#include <CargaBaseDeDatosMaestros.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomEnviaArchivo;

class QtImpCargaBaseDeDatosMaestros:public CargaBaseDeDatosMaestros
{
Q_OBJECT
public:
	QtImpCargaBaseDeDatosMaestros(QWidget *pQWParent,
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
