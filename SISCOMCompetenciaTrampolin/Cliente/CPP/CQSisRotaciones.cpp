#include <CQSisRotaciones.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomRegistros3.h>
#include <CQSisCompetencias.h>
CQSisOpRotaciones::CQSisOpRotaciones(SiscomDatCom *pSisDatCom):
			SiscomOperaciones3(pSisDatCom)
{
SiscomEscribeLog3Qt("");

}
void CQSisOpRotaciones::EjecutaRotacion(CQSisCompetencia *pCQSCompetencia,
					const char *pchrPtrIdRonda)
{
SiscomRegistro3Lst lSReg3LstRegreso;
SiscomEnvia("ConsultaGimnasio",
	    &lSReg3LstRegreso,
	    "%s%s%s",
	    "EjecutaRotacion",
	    (*pCQSCompetencia)["IdCompetencia"],
	    pchrPtrIdRonda);

}

void CQSisOpRotaciones::RondasCompetencia(const char *pchrPtrIdCompetencia,
					  SiscomRegistro3Lst *pSRegistro3Lst)
{
SiscomEnvia("ConsultaGimnasio",
	    pSRegistro3Lst,
	    "%s%s",
	    "RondasCompetencia",
	    pchrPtrIdCompetencia);

}
