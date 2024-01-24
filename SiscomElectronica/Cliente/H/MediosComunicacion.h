#ifndef __MEDIOSCOMUNICACION_H__
#define __MEDIOSCOMUNICACION_H__
#include <SISCOMComunicaciones++.h>
#include <qptrlist.h>

class MedioComunicacion:public SiscomInformacion
{
public:
	MedioComunicacion(const char *,
			const char *,
			const char *,
			const char *,
			const char *);
};
class MediosComunicacion:public QPtrList<MedioComunicacion>
{
public:
	MediosComunicacion();
	MediosComunicacion &operator<<(MedioComunicacion *);

};
#endif
