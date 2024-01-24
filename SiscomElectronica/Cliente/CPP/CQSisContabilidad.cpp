#include <CQSisContabilidad.h>
#include <SiscomRegistros3.h>
CQSisContabilidad::CQSisContabilidad(SiscomDatCom *pSisDatCom):
		SiscomOperaciones3(pSisDatCom)
{


}
void CQSisContabilidad::Contabilidad(const char *pchrPtrIdExpendio,
			  SiscomRegistro3Lst *pSisReg3LstFactCompras,
			  SiscomRegistro3Lst *pSisReg3LstFactVentas,
			  SiscomRegistro3Lst *pSisReg3LstTotales,
			  SiscomRegistro3Lst *pSisReg3LstDatRegistro)
{
SiscomRegistro3Lst lSisReg3LstRespuesta;
SiscomEnvia("ConsultasSiscomElectronica2",
	    &lSisReg3LstRespuesta,
	    "%s%s",
	    "Contabilidad",
	    pchrPtrIdExpendio);
	   
}
void CQSisContabilidad::EjecutaProceso(const char *pchrPtrIdExpendio,
						   const char *pchrPtrIdProceso)
{
SiscomRegistro3Lst lSisReg3LstRegreso;
SiscomEnvia("ConsultasSiscomElectronica2",
	    &lSisReg3LstRegreso,
	    "%s%s%s",
	    "EjecutaProcesoContabilidad",
	    pchrPtrIdExpendio,
	    pchrPtrIdProceso);
	    

}
