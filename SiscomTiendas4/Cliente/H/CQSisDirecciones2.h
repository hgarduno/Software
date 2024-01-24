#ifndef __CQSISDIRECCIONES2_H__
#define __CQSISDIRECCIONES2_H__
#include <SiscomRegistros3.h>

class CQSisDireccion2:public SiscomRegistro3
{
public:
	CQSisDireccion2(const char *pchrPtrEdoRegistro,
			const char *pchrPtrIdPersona,
			const char *pchrPtrRfc,
			const char *pchrPtrDireccion);
};

#endif
