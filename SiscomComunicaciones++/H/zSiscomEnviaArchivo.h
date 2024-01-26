#ifndef __ZSISCOMENVIAARCHIVO_H__
#define __ZSISCOMENVIAARCHIVO_H__
#include <zSiscomArchivo.h>
class zSiscomConexion;
class zSiscomEnviaArchivo:public zSiscomArchivo
{
public:
	zSiscomEnviaArchivo(const char *pchrPtrArchivo,
			    zSiscomConexion *pzSiscomConexion);
	void Envia();
private:
	void Caracteres(zSiscomRegistro *pzSiscomRegDato);
	void Caracteres(const char *pchrPtrEnvio);
	void Caracteres(int);
private:
	zSiscomConexion *zSiscomConexionN;
};

#endif
