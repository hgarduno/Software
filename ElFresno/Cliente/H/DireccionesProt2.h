#ifndef __DIRECCIONESPROT2_H__
#define __DIRECCIONESPROT2_H__

#include <SISCOMComunicaciones++.h>

class DireccionProt2:public SiscomInformacion
{
public:
	
	DireccionProt2(const char *,
		      const char *,
		      const char *,
		      const char *,
		      const char *,
		      const char *,
		      const char *);

};
class DireccionesProt2:public QPtrList<DireccionProt2>
{
public:
	DireccionesProt2();
	DireccionesProt2 &operator<<(DireccionProt2 *);

};
#endif
