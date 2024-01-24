#ifndef __ZCLAVESAT_H__
#define __ZCLAVESAT_H__
#include <zSiscomRegistro.h>

class zClaveSat:public zSiscomRegistro
{
	public:
		zClaveSat();
		void Id(const char *pchrPtrId);
		void Clave(const char *pchrPtrClave);
		void Sat(const char *pchrPtrSat);
		void PalabraClave(const char *pchrPtrPalabraClave);

		const char *Sat();
		const char *PalabraClave();
};

#endif
