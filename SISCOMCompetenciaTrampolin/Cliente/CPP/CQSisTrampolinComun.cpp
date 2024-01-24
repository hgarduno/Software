#include <CQSisTrampolinComun.h>
CQSisError::CQSisError(const char *pchrPtrMensaje):
		chrPtrMensaje(pchrPtrMensaje)
{
	SiscomAsignaInformacion();
}
void CQSisError::SiscomFormaRegistro()
{
	SRegistroPro2 			<<
	"Mensaje";
}
void CQSisError::SiscomAnexaRegistro()
{
	SRegistrosPro2 			<<
	SiscomCampoPro2("Mensaje",chrPtrMensaje);

}
CQSisLstError::CQSisLstError()
{

}
CQSisLstError &CQSisLstError::operator<<(CQSisError *pCQSEMensaje)
{
	append(pCQSEMensaje);
	return *this;
}


