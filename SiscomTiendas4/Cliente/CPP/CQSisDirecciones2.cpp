#include <CQSisDirecciones2.h>
CQSisDireccion2::CQSisDireccion2(const char *pchrPtrEdoRegistro,
				 const char *pchrPtrIdPersona,
				 const char *pchrPtrRFC,
				 const char *pchrPtrDireccion)
{

	(*this)							<<
	new SiscomCampo3("EdoRegistro",pchrPtrEdoRegistro)	<<
	new SiscomCampo3("idpersona",pchrPtrIdPersona)		<<
	new SiscomCampo3("rfc",pchrPtrRFC)			<<
	new SiscomCampo3("direccion",pchrPtrDireccion);
}


