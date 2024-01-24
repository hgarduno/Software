#include <CQSisOpeProductoNoSincronizado.h>
#include <CQSisProductoNoSincronizado.h>
CQSisOpeProductoNoSincronizado::CQSisOpeProductoNoSincronizado(SiscomDatCom *pSisDatCom):
				SiscomOperaciones3(pSisDatCom)
{


}

void CQSisOpeProductoNoSincronizado::ProductosNoSincronizados(
			const char *pchrPtrIdExpendio,
			CQSisProductoNoSincronizado *pCQSisPNSincronizado)
{
SiscomEnvia2("ProductosNoSincronizados",
	     pCQSisPNSincronizado,
	     "%s [Expendios] %s [IdExpendio]",
	     "Todos",
	     pchrPtrIdExpendio);
}
void CQSisOpeProductoNoSincronizado::EjecutaSincronizacion(
			const char *pchrPtrIdExpendio,
			SiscomRegistro4 *pSisReg4EdoRegistro)
{
SiscomEnvia2("EnviaSincronizacionProductos",
	     pSisReg4EdoRegistro,
	     "%s [IdExpendio]",
	     pchrPtrIdExpendio);
}
