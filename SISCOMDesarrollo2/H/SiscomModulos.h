#ifndef __SISCOMMODULOS_H__
#define __SISCOMMODULOS_H__
#include <qptrlist.h>
class SiscomModulo;

class SiscomModulos:public QPtrList<SiscomModulo>
{
public:
	SiscomModulos();
	SiscomModulos &operator<<(SiscomModulo *);
	int operator==(const char *);
	SiscomModulo *Modulo(const char *pchrPtrModulo);

};

#endif
