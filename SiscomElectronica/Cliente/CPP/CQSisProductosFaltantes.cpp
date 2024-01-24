#include <CQSisProductosFaltantes.h>

CQSisProductosFaltantes::CQSisProductosFaltantes()
{

}


CQSisProductosFaltantesOp::CQSisProductosFaltantesOp(SiscomDatCom *pSisDatCom):
				SiscomOperaciones3(pSisDatCom)
{


}
void CQSisProductosFaltantesOp::Faltantes(const char *pchrPtrIdExpendio,
					  CQSisProductosFaltantes *pCQSProdsFaltantes)
{
SiscomEnvia2("ProductosFaltantes",
	     pCQSProdsFaltantes,
	     "%s [IdExpendio]",
	     pchrPtrIdExpendio);
}
