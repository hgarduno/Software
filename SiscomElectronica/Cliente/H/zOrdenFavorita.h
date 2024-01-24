#ifndef __ZORDENFAVORITA_H__
#define __ZORDENFAVORITA_H__
#include <zSiscomRegistro.h>

class zOrdenFavorita:public zSiscomRegistro
{
public:
	zOrdenFavorita();
	void IdOrden(const char *pchrPtrIdOrden);
	void Texto(const char *pchrPtrTexto);
	const char *Texto();
	const char *IdOrden();
};
#endif
