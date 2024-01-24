#ifndef __UNIDADESPROT2_H__
#define __UNIDADESPROT2_H__
#include <SISCOMComunicaciones++.h>
#include <Unidades.h>

class UnidadProt2:public SiscomInformacion
{
public:
	UnidadProt2(const char *,
		    const char *,
		    const char *);

};

class UnidadesProt2:public QPtrList<UnidadProt2>
{
public:
	UnidadesProt2();
	UnidadesProt2 &operator<<(UnidadProt2 *);

};
#endif
