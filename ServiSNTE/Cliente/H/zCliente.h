#ifndef __ZCLIENTE_H__
#define __ZCLIENTE_H__

#include <zPersona.h>

class zCliente:public zPersona
{
public:
	zCliente();
	zCliente(const char *pchrPtrIdPersona,
		 const char *pchrPtrNombre,
		 const char *pchrPtrAPaterno,
		 const char *pchrPtrAMaterno,
		 const char *pchrPtrRFC);
	void ClientePorComprasRegistradas(zSiscomRegistro *);

private:
	void Cliente(zSiscomRegistro *);

};

#endif

