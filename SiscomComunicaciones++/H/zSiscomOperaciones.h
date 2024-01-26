#ifndef __ZSISCOMOPERACIONES_H__
#define __ZSISCOMOPERACIONES_H__
#include <zSiscomRegistros.h>
#include <zSiscomEnvio.h>
#include <zSiscomRecibe.h>
class zSiscomConexion;
class zSiscomRegistros;
class zSiscomOperaciones:public zSiscomEnvio,
			 public zSiscomRecibe,
			 public zSiscomRegistros
{
public:
	zSiscomOperaciones();
	zSiscomOperaciones(zSiscomConexion *);
	zSiscomOperaciones(zSiscomConexion *pzSisConexion,
			   const char *pchrPtrModulo,
			   const char *pchrPtrFuncion);
	zSiscomOperaciones(zSiscomConexion *pzSisConexion,
			   const char *pchrPtrModulo,
			   const char *pchrPtrFuncion,
			   zSiscomRegistros *pzSisRegsEnvio);
	zSiscomOperaciones(zSiscomConexion *pzSisConexion,
			   const char *pchrPtrModulo,
			   const char *pchrPtrFuncion,
			   zSiscomRegistro *pzSisRegEnvio);
	void Enviando();
	zSiscomRegistros *Respuesta();
	zSiscomRegistros *EnviaRecibe();
	void AgregaEnvio(zSiscomRegistros *pzSisRegsEnvios);
	void AgregaEnvio(zSiscomRegistro *pzSisRegEnvio);
private:
	void PreparaEnvio();
	void EnviaVersionProtocolo();
private:
	const char *chrPtrModulo;
	const char *chrPtrFuncion;
};


#endif
