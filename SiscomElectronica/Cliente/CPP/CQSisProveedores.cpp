#include <CQSisProveedores.h>

CQSisProveedores::CQSisProveedores(SiscomDatCom *pSisDatCom):
		SiscomOperaciones3(pSisDatCom)
{

}
void CQSisProveedores::Proveedores(const char *pchrPtrIdExpendio,
				   SiscomRegistro3Lst *pSisReg3LstProveedores)
{

SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstProveedores,
	    "%s%s",
	    "ProveedoresRegistrados",
	    pchrPtrIdExpendio);
}
