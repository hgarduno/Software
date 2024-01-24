#ifndef __FAMILIASPROT2_H__
#define __FAMILIASPROT2_H__
#include <SISCOMComunicaciones++.h>
#include <Familias.h>
class FamiliaProt2:public SiscomInformacion
{
public:
	FamiliaProt2(const char *,
		    const char *,
		    const char *);
};

class FamiliasProt2:public QPtrList<FamiliaProt2>
{
public:
	FamiliasProt2();
	FamiliasProt2 &operator<<(FamiliaProt2 *);

};
#endif
