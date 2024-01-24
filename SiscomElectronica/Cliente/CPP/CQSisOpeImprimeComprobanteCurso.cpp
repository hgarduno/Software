#include <CQSisOpeImprimeComprobanteCurso.h>
#include <CQSisImprimeComprobantePagoCurso.h>
CQSisOpeImprimeComprobanteCurso::CQSisOpeImprimeComprobanteCurso(
					SiscomDatCom *pSisDatCom):
					SiscomOperaciones3(pSisDatCom)
{


}

void CQSisOpeImprimeComprobanteCurso::ImprimeComprobante(CQSisImprimeComprobantePagoCurso *pCQSCPCurso)
{
SiscomRegistro3Lst lSisReg3LstRespuesta;
SiscomEnvia("ImprimeComprobanteCurso",
	    pCQSCPCurso,
	    &lSisReg3LstRespuesta);
}


