#ifndef __DIRECCIONES_H__
#define __DIRECCIONES_H__
#include <SISCOMComunicaciones++.h>
#include <qptrlist.h>

class Direccion:public SiscomInformacion
{
public:
	Direccion();
	Direccion(const char *,
		  const char *,
		  const char *,
		  const char *,
		  const char *,
		  const char *,
		  const char *,
		  const char *,
		  const char *);

};

class Direcciones:public QPtrList<Direccion>
{
public:
	Direcciones();
	Direcciones &operator<<(Direccion *);
};


#endif 
