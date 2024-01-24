#include <CQSisSueldos.h>

CQSisSueldo::CQSisSueldo(const char *pchrPtrIdPersona,	
			 const char *pchrPtrFecha,
			 const char *pchrPtrSueldo)
{
	(*this)								<<
	new SiscomCampo3("IdPersona",pchrPtrIdPersona) 		<<
	new SiscomCampo3("Fecha",pchrPtrFecha) 			<<
	new SiscomCampo3("Sueldo",pchrPtrSueldo);

}
