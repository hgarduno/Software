#ifndef __ZDATOSCOMUNICACION_H__
#define __ZDATOSCOMUNICACION_H__

#include <zTelefonos.h>
class zCorreo;
class zSiscomRegistros;
class zDatosComunicacion:public zTelefonos
{
public:
	zDatosComunicacion(const char *pchrPtrIdPersona);
	zDatosComunicacion(zSiscomRegistros *pzSisRegsDatos);
	void Correo(zCorreo *pzCorreo);
	void ActualizaCorreo(const char *pchrPtrCorreo);

};

#endif
