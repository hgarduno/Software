#include <CQSisFactura.h>
CQSisFactura::CQSisFactura(SiscomRegistro3 *pSisReg3Cliente,
			   SiscomRegistro3Lst *pSisReg3LstProductos,
			   SiscomRegistro3Lst *pSisReg3LstOrdenes)
{
SiscomAgregaRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaRegistro(0,pSisReg3Cliente);
SiscomAgregaRegistros(1,pSisReg3LstProductos);
SiscomAgregaRegistros(2,pSisReg3LstOrdenes);
SiscomContenidoRegistro4Log(this);

}




CQSisOpRegistraFactura::CQSisOpRegistraFactura(SiscomDatCom *pSisDatCom):
				SiscomOperaciones3(pSisDatCom)
{



}
void CQSisOpRegistraFactura::Registra(CQSisFactura *pCQSisFactura)
{
SiscomRegistro4 lSisReg4Regreso;
SiscomEnvia("RegistraFactura",
	    0,
	    pCQSisFactura,
	    &lSisReg4Regreso);
}
