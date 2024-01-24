#ifndef __MEDIOSCOMUNICACION_H__
#define __MEDIOSCOMUNICACION_H__
#include <SISCOMComunicaciones++.h>
class MedioComunicacion:public SiscomInformacion
{
public:
	MedioComunicacion(const char *,
			  const char *,
			  const char *,
			  const char *);


};

#endif
