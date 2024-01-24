#include <CQSisVentas.h>
#include <CQSisProdCotiza.h>



CQSisVenta::CQSisVenta(CQSisProdCotiza *pCQSCotiza)
{


}
CQSisLstVenta::CQSisLstVenta()
{

}
CQSisLstVenta &CQSisLstVenta::operator<<(CQSisVenta *pCQSVenta)
{
	append(pCQSVenta);
	return *this;
}

CQSisOpVenta::CQSisOpVenta(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{

}

void CQSisOpVenta::RegistraVenta(CQSisLstProdCotiza *pCQSPCotiza)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomPonParametrosConsulta((SiscomInformacionLst *)pCQSPCotiza);
SiscomActualiza2SubRegistros("RegistraVenta",&lSRegistrosPro2);
}

