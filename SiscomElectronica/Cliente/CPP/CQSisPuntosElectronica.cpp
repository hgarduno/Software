#include <CQSisPuntosElectronica.h>
#include <CQSisPromocionesCliente.h>


CQSisPuntosPromocionCliente::CQSisPuntosPromocionCliente()
{



}

CQSisOpPuntosElectronica::CQSisOpPuntosElectronica(SiscomDatCom *pSisDatCom):
				SiscomOperaciones3(pSisDatCom)
{


}

void CQSisOpPuntosElectronica::PuntosPromocionesCliente(
				const char *pchrPtrIdExpendio,
				const char *pchrPtrIdCliente,
				const char *pchrPtrNmbCliente,
				SiscomRegistro4 *pSisReg4Regreso)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg4Regreso,
	    "%s%s%s%s",
	    "PuntosPromocionCliente",
	    pchrPtrIdExpendio,
	    pchrPtrIdCliente,
	    pchrPtrNmbCliente);
}

void CQSisOpPuntosElectronica::ValidaPuntosPromocionesSel(
				SiscomRegistro3Lst *pSisReg3LstPromociones,
				SiscomRegistro4 *pSisReg4Regreso)
{
SiscomEnvia("ValidaPuntosPromocionesSel",
	    pSisReg3LstPromociones,
	    pSisReg4Regreso);
}

void CQSisOpPuntosElectronica::TomaPromociones(CQSisPromocionesCliente *pCQSPsCliente)
{
SiscomRegistro4 *lSisReg3EdoTomaPromocion=new SiscomRegistro4;
SiscomEnvia("TomaPromociones",
		0,
		pCQSPsCliente,
		lSisReg3EdoTomaPromocion);
pCQSPsCliente->EdoTomaPromociones(lSisReg3EdoTomaPromocion);
}
