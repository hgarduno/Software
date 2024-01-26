#ifndef __ZTELEFONOS_H__
#define __ZTELEFONOS_H__
#include <zSiscomRegistro.h>


class zTelefonos:public zSiscomRegistro
{
public:
	zTelefonos(const char *pchrPtrIdPersona);
	zTelefonos();
	zTelefonos(zSiscomRegistros *pzSisRegsTelefonos);
	zTelefonos *DesdePersonaRegistrada(zSiscomRegistro *pzSisRegPersona);
	const char *TelefonoPorDsc(const char *pchrPtrDescripcion);
	void ActualizaPorDescripcion(const char *pchrPtrDescripcion,const char *pchrPtrTelefono);
	zSiscomRegistro *Telefono(const char *pchrPtrDescripcion);
	void IdPersona(const char *pchrPtrIdPersona);
	void AgregaTelefono(const char *pchrPtrIdTelefono,
			     const char *pchrPtrDescripcion,
			    const char *pchrPtrTelefono);
	void AgregaTelefono(const char *pchrPtrIdTelefono,
			    const char *pchrPtrDescripcion,
			    const char *pchrPtrTelefono,
			    const char *pchrPtrExtension);
	void AgregaTelefono(zSiscomRegistro *pzSisRegTelefono);
	void AgregaTelefono2(zSiscomRegistro *pzSisRegTelefono);
	const char *Telefono();
	const char *Extension();
	zTelefonos *DesdeDatosEmpleo(zSiscomRegistro *pzSisRegEmpleo);
private:
	void AgregaTelefonos(zSiscomRegistros *pzSisRegsTelefonos);
};


#endif
