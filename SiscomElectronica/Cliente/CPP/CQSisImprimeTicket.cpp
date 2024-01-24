#include <CQSisImprimeTicket.h>
#include <CQSisPuntosElectronica.h>
#include <ProductosE.h>
#include <Personas.h>


#include <SiscomDesarrollo3Qt++.h>
CQSisImprimeTicket::CQSisImprimeTicket(const char *pchrPtrIdExpendio,
					const char *pchrPtrOrden,
				       CQSisPuntosPromocionCliente *pCQSPPCliente,
				       Persona *pPCliente,
				       ProductosE *pProdEDatos):
				chrPtrIdExpendio(pchrPtrIdExpendio),
				CQSPPCliente(pCQSPPCliente),
				ProdEDatos(pProdEDatos),
				pCliente(pPCliente)
{
strcpy(chrArrIdOrden,pchrPtrOrden);
FormaEnvio();

}

void CQSisImprimeTicket::FormaEnvio()
{
ProductoE *lProdEDato;
SiscomRegistro3 *lSisReg3Dato;
const char *lchrPtrIdCaja=getenv("IdCaja");
const char *lchrPtrPuntosCliente;
const char *lchrPtrPromociones;
lchrPtrIdCaja=lchrPtrIdCaja ? lchrPtrIdCaja : "";
CQSPPCliente->first();
/*
lchrPtrPuntosCliente=CQSPPCliente->CampoRegistroSubGrupo(0,0,0,"PuntosCliente");
lchrPtrPromociones=CQSPPCliente->CampoRegistroSubGrupo(0,0,0,"Promociones");
*/
lchrPtrPuntosCliente="";
lchrPtrPromociones="";

for(lProdEDato=ProdEDatos->first();
    lProdEDato;
    lProdEDato=ProdEDatos->next())
{
  lSisReg3Dato=new SiscomRegistro3;

  (*lSisReg3Dato) << 
new SiscomCampo3("Cantidad",(*lProdEDato)["Cantidad"])				<<
new SiscomCampo3("Importe",(*lProdEDato)["Importe"])				<<
new SiscomCampo3("NumJuegos",(*lProdEDato)["NumJuegos"])			<<
new SiscomCampo3("CveProducto",(*lProdEDato)["CveProducto"])			<<
new SiscomCampo3("Precio",(*lProdEDato)["Precio"])				<<
new SiscomCampo3("ClienteFrecuente",(*lProdEDato)["ClienteFrecuente"])		<<
new SiscomCampo3("NoOrden",chrArrIdOrden)					<<
new SiscomCampo3("NmbCliente",(*pCliente)["Nombre"])				<<
new SiscomCampo3("PorDescuento",(*lProdEDato)["PorDescuento"])			<<
new SiscomCampo3("IdCaja",lchrPtrIdCaja)					<<
new SiscomCampo3("IdExpendio",chrPtrIdExpendio)					<<
new SiscomCampo3("EdoImpresion","")						<<
new SiscomCampo3("PuntosCliente",lchrPtrPuntosCliente)				<<
new SiscomCampo3("Promociones",lchrPtrPromociones);
  (*this) << lSisReg3Dato; 

}
SiscomEscribeLog3Qt("");
}

CQSisImprimeTicketOp::CQSisImprimeTicketOp(SiscomDatCom *pSisDatCom):
		SiscomOperaciones3(pSisDatCom)
{


}

void CQSisImprimeTicketOp::TicketVenta(CQSisImprimeTicket *pCQSisITicket)
{
SiscomRegistro3Lst lSisReg3LstRegreso;
SiscomEnvia("ImprimeTicketVenta",
	     pCQSisITicket,
	     &lSisReg3LstRegreso);
}
