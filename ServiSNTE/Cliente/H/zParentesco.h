#ifndef __ZPARENTESCO_H__
#define __ZPARENTESCO_H__
#include <zSiscomRegistro.h>

class zParentesco:public zSiscomRegistro
{
public:
	zParentesco();
	void Parentesco(const char *pchrPtrParentesco);
};

#endif
