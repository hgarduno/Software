#ifndef __CQSISRESPONSABLEVEHICULO_H__
#define __CQSISRESPONSABLEVEHICULO_H__
#include <CQSisClientes3Qt.h>


class CQSisResponsableVehiculo:public CQSisCliente3Qt
{
public:
	CQSisResponsableVehiculo(const char *pchrPtrIdPersona,
				 const char *pchrPtrNombre,
				 const char *pchrPtrAPaterno,
				 const char *pchrPtrAMaterno,
				 const char *pchrPtrCargo);

};

#endif
				
