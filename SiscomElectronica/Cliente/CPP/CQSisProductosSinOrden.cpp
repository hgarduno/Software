#include <CQSisProductosSinOrden.h>
#include <CQSisProductosE3Qt.h>


CQSisProductosSinOrden::CQSisProductosSinOrden(SiscomDatCom *pSisDatCom):
		SiscomOperaciones3(pSisDatCom)
{


}


void CQSisProductosSinOrden::Registra(const char *pchrPtrIdExpendio,
				      CQSisProductoE3 *pCQSProductoE3)
{

pCQSProductoE3->SiscomActualizaCampo("IdExpendio",pchrPtrIdExpendio);
	SiscomEnvia("RegistraProductoSinOrden",
	     	    pCQSProductoE3,
	     	    (SiscomRegistro3Lst *)0);
}
