#ifndef __ZIMPRESION_H__
#define __ZIMPRESION_H__
#include <zSiscomRegistros.h>


class zImpresion:public zSiscomRegistros
{

public:
	zImpresion();
	const char *operator[](const char *);

};
#endif
