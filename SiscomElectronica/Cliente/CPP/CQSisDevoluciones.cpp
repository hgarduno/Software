#include <CQSisDevoluciones.h>

CQSisDevolviendo::CQSisDevolviendo(SiscomDatCom *pSisDatCom):
			SiscomOperaciones3(pSisDatCom)
{

}
void CQSisDevolviendo::CalculaDevolucion(SiscomRegistro3Lst *pSisReg3ProdDevuelve,
					 SiscomRegistro3Lst *pSisReg3Regreso)
{
pSisReg3Regreso->clear();
SiscomEnvia("CalculaDevolucion",
	    pSisReg3ProdDevuelve,
	    pSisReg3Regreso);
}
void CQSisDevolviendo::Devuelve(SiscomRegistro3Lst *pSisReg3Devuelve)
{
SiscomEnvia("EjecutaDevolucion",
	    pSisReg3Devuelve);
}
