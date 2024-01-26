#ifndef __ZDEPARTAMENTO_H__
#define __ZDEPARTAMENTO_H__

#include <zSiscomRegistro.h>


class zDepartamento:public zSiscomRegistro
{
public:
	zDepartamento(const char *pchrPtrIdDepartamento,
		 const char *pchrPtrNombreDepto,
		 const char *pchrPtrAbrevDepto);

};

#endif
