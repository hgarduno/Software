#include <CQSisOrVendidas.h>
#include <CQSisProdCotiza.h>
#include <CQSisObjetosTiendas4.h>
#include <CQSisEmpresas.h>
#include <CQSisFormaPago.h>
#include <CQSisClientes.h>
CQSisOpOrdenes::CQSisOpOrdenes(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{


}
void CQSisOpOrdenes::Orden(const char *pchrPtrIdOrden,
			   CQSisEmpresa *pCQSEmpresa,
			   CQSisLstProdCotiza *pCQSLPCotiza)
{
SiscomRegistrosPro2 *lSRegistrosPro2;

	pCQSLPCotiza->setAutoDelete(true);
	pCQSLPCotiza->clear();
SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s%s",
			 "OrdenVendida",
			 pchrPtrIdOrden,
			 pCQSEmpresa->SRegistrosPro2["IdEmpresa"]);

SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);
FormaProductoCotiza(lSRegistrosPro2,
		    pCQSLPCotiza);
}
void CQSisOpOrdenes::Orden(const char *pchrPtrIdOrden,
			   CQSisEmpresa *pCQSEmpresa,
			   CQSisFormaPago *pCQSFPago,
			   CQSisCliente *pCQSCliente,
			   CQSisEmpleado *pCQSEmpleado,
			   CQSisLstProdCotiza *pCQSLPCotiza)
{
SiscomRegistrosPro2 *lSRegistrosPro2;

	pCQSLPCotiza->setAutoDelete(true);
	pCQSLPCotiza->clear();
SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s%s",
			 "OrdenVendida",
			 pchrPtrIdOrden,
			 pCQSEmpresa->SRegistrosPro2["IdEmpresa"]);

SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);
FormaProductoCotiza(lSRegistrosPro2,
		    pCQSFPago,
		    pCQSCliente,
		    pCQSEmpleado,
		    pCQSLPCotiza);
}
void CQSisOpOrdenes::FormaProductoCotiza(SiscomRegistrosPro2 *pSRegistrosPro2,
					 CQSisFormaPago *pCQSFPago,
					 CQSisCliente *pCQSCliente,
					 CQSisEmpleado *pCQSEmpleado,
					 CQSisLstProdCotiza *pCQSLPCotiza)
{
CQSisEmpresa *lCQSExpendio;

if(!pSRegistrosPro2->SiscomEsElUltimoRegistro())
lCQSExpendio=new CQSisEmpresa((*pSRegistrosPro2)["idexpendio"],"");
for(;
    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
    ++(*pSRegistrosPro2))
(*pCQSLPCotiza)	<< new CQSisProdCotiza(
			 ObjetosTiendas4::Producto(pSRegistrosPro2),
			 ObjetosTiendas4::Precio(pSRegistrosPro2),
			 pCQSFPago,
			 lCQSExpendio,
			 pCQSCliente,
			 pCQSCliente->Contacto(),
			 pCQSEmpleado,
			 (*pSRegistrosPro2)["cantidad"],
			 (*pSRegistrosPro2)["existencia"],
			 (*pSRegistrosPro2)["precio"],
			 (*pSRegistrosPro2)["total"],
			 "Si",
			 (*pSRegistrosPro2)["idventa"],
			 (*pSRegistrosPro2)["edoventa"]);
}
void CQSisOpOrdenes::FormaProductoCotiza(SiscomRegistrosPro2 *pSRegistrosPro2,
					 CQSisLstProdCotiza *pCQSLPCotiza)
{
CQSisEmpresa *lCQSExpendio;

if(!pSRegistrosPro2->SiscomEsElUltimoRegistro())
lCQSExpendio=new CQSisEmpresa((*pSRegistrosPro2)["idexpendio"],"");
for(;
    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
    ++(*pSRegistrosPro2))
(*pCQSLPCotiza)	<< new CQSisProdCotiza(
			 ObjetosTiendas4::Producto(pSRegistrosPro2),
			 lCQSExpendio,
			 (*pSRegistrosPro2)["cantidad"],
			 (*pSRegistrosPro2)["precio"],
			 (*pSRegistrosPro2)["total"],
			 (*pSRegistrosPro2)["idventa"]);
}
