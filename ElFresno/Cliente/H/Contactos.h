#ifndef __CONTACTOS_H__
#define __CONTACTOS_H__
#include <SISCOMComunicaciones++.h>

class Contacto:public SiscomInformacion
{
public:
	Contacto(const char *,
		 const char *,
		 const char *,
		 const char *,
		 const char *,
		 const char *,
		 const char *);


};


#endif
