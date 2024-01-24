#include <CQSisOpeOrdenCaja.h>
#include <CQSisOrdenCaja.h>
#include <CQSisDatosOrdenCaja.h>
CQSisOpeOrdenCaja::CQSisOpeOrdenCaja(SiscomDatCom *pSisDatCom):
		SiscomOperaciones3(pSisDatCom)
{


}
void CQSisOpeOrdenCaja::OrdenesPendientes(
			  CQSisDatosOrdenCaja *pCQSDatOrdenCaja,
			  CQSisOrdenCaja *pCQSOCaja)
{
pCQSOCaja->SiscomLimpia();
SiscomContenidoRegistro4Log(pCQSDatOrdenCaja);
SiscomEnvia("OrdenesPendientes",
	    0,
	    pCQSDatOrdenCaja,
	    pCQSOCaja);
}
void CQSisOpeOrdenCaja::VendeOrden(CQSisDatosOrdenCaja *pCQSDOCaja)
{
SiscomContenidoRegistro4Log(pCQSDOCaja);
SiscomEnvia("VendeOrdenCajaCentral",
	     0,
	     pCQSDOCaja,
	     &SisReg4EdoConexion);

}
