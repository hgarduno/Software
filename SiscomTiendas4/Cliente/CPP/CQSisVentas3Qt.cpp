#include <CQSisVentas3Qt.h>
#include <CQSisProdCotiza3Qt.h>
CQSisOpVentas3Qt::CQSisOpVentas3Qt(SiscomDatCom *pSisDatCom):
			SiscomOperaciones3(pSisDatCom)
{

}

void CQSisOpVentas3Qt::RegistraVenta(
			CQSisProdCotiza3QtLst *pCQSProdCotiza3QtLst)
{
CQSisProdCotiza3QtLst lCQSPCotiza3QtLst;
SiscomEnvia("RegistraVenta",
	    pCQSProdCotiza3QtLst,
	    &lCQSPCotiza3QtLst);
}
void CQSisOpVentas3Qt::ProductosPorAproximacion(const char *pchrPtrTexto,
						SiscomRegistro3Lst *pSRegistro3LstRes)
{
SiscomEnvia("ConsultaTiendas4",
	   pSRegistro3LstRes,
	   "%s%s",
	   "ProductosPorAproximacion",
	   pchrPtrTexto);
}
