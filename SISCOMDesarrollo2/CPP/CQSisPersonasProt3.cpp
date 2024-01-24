/*
 * Con estos archivos se inicia la tendencia en la cual
 * se debera basar el desarrollo, la cual consiste en 
 * integrar en la biblioteca principal, toda la funcionalidad
 *
 */
#include <CQSisPersonasProt3.h>

CQSisPersonasProt3::CQSisPersonasProt3(SiscomDatCom *pSisDatCom):
			SiscomOperaciones3(pSisDatCom)
{

}

void CQSisPersonasProt3::Registra(SiscomRegistro3Lst *pSisReg3LstPersonas)
{

}

void CQSisPersonasProt3::Registra(const char *pchrPtrOperacion,
				  SiscomRegistro3 *pSisReg3Persona,
				  SiscomRegistro3Lst *pSisReg3LstRegreso)
{
SiscomEnvia(pchrPtrOperacion,
	    pSisReg3Persona,
	    pSisReg3LstRegreso);
}
