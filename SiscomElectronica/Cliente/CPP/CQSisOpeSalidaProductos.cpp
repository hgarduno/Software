#include <CQSisOpeSalidaProductos.h>
#include <CQSisProductos4.h>
CQSisOpeSalidaProductos::CQSisOpeSalidaProductos(SiscomDatCom *pSisDatCom):
				SiscomOperaciones3(pSisDatCom)
{

}

void CQSisOpeSalidaProductos::RegistraSalidaProductos(CQSisProducto4 *pCQSProductos)
{
SiscomEnvia("RegistraSalidaMaterial",
	    0,
	    pCQSProductos,
	    &SisReg4EdoConexion);

}
