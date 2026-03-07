#ifndef __ZSISCOM_PORTAPAPELES_H__
#define __ZSISCOM_PORTAPAPELES_H__
#include <zSiscomOperaciones.h>



class zClienteSiscom;
class zTelefono;
class zSiscomRegistro;

class zSiscomPortaPapeles:public zSiscomOperaciones
{
public:
	zSiscomPortaPapeles(zSiscomConexion *,
			    const char *pchrPtrFuncion,
			    const char *pchrPtrMomdulo="libSiscomElectronica4.so");

	~zSiscomPortaPapeles();

	void ClienteSiscom(const char *,zClienteSiscom *);
private:
	zTelefono *Celular(zSiscomRegistro *pzSisRegDatos);
};


#endif
