#include <CQSisResponsableVehiculo.h>

CQSisResponsableVehiculo::CQSisResponsableVehiculo(
				const char *pchrPtrIdPersona,
				const char *pchrPtrNombre,
				const char *pchrPtrAPaterno,
				const char *pchrPtrAMaterno,
				const char *pchrPtrCargo):
		CQSisCliente3Qt(pchrPtrIdPersona,
				pchrPtrNombre,
				pchrPtrAPaterno,
				pchrPtrAMaterno)
{

	(*this)				<<
	new SiscomCampo3("Cargo",pchrPtrCargo);
}
