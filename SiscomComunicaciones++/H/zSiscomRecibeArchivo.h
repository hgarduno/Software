#ifndef __ZSISCOMRECIBEARCHIVO_H__
#define __ZSISCOMRECIBEARCHIVO_H__
#include <zSiscomArchivo.h>
class zSiscomConexion;

class zSiscomRecibeArchivo:public zSiscomArchivo
{
public:
   zSiscomRecibeArchivo(zSiscomConexion *pzSiscomConexion);
   void Carga();
   void Caracteres(int pintBytes,unsigned char *pchrPtrRegreso);
   void CaracteresSinNulo(int pintBytes,unsigned char *pchrPtrRegreso);
   int Caracteres(int pintCaracteres);
private:
	void Nodo();
private:
	zSiscomConexion *zSiscomConexionN;
};



#endif
