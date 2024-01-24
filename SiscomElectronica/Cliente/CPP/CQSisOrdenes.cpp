#include <CQSisOrdenes.h>

CQSisOrdenesSiscom::CQSisOrdenesSiscom(SiscomDatCom *pSisDatCom):
			SiscomOperaciones3(pSisDatCom)
{

}
void CQSisOrdenesSiscom::Ordenes(const char *pchrPtrIdExpendio,
				 const char *pchrPtrFechaIni,
				 const char *pchrPtrFechaFin,
				 SiscomRegistro3Lst *pSisReg3LstOrdenes)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstOrdenes,
	    "%s%s%s%s",
	    "OrdenesVendidasSiscom",
	    pchrPtrIdExpendio,
	    pchrPtrFechaIni,
	    pchrPtrFechaFin);
}
void CQSisOrdenesSiscom::DetalleOrden(const char *pchrPtrIdExpendio,
				      SiscomRegistro3 *pSisReg3Orden,
				      SiscomRegistro3Lst *pSisReg3LstProductos)

{

SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstProductos,
	    "%s%s%s",
	    "DetalleOrden",
	    pchrPtrIdExpendio,
	    (*pSisReg3Orden)["idventa"]);
}

void CQSisOrdenesSiscom::AnexarOrdenContabilidad(
			     const char *pchrPtrIdExpendio,
			     SiscomRegistro3 *pSisReg3Orden)
{
SiscomRegistro3Lst lSisReg3LstRespuesta;
pSisReg3Orden->SiscomActualizaCampo("IdExpendio",pchrPtrIdExpendio);
SiscomEnvia("AnexarOrdenContabilidad",
	    pSisReg3Orden,
	    &lSisReg3LstRespuesta);

}
