#ifndef __CQSISSUELDOS_H__
#define __CQSISSUELDOS_H__
#include <SiscomRegistros3.h>

class CQSisSueldo:public SiscomRegistro3
{
public:
	CQSisSueldo(const char *pchrPtrIdPersona,
		    const char *pchrPtrFecha,
		    const char *pchrPtrSueldo);
};

#endif
