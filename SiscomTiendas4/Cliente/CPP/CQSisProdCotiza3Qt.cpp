#include <CQSisProdCotiza3Qt.h>
#include <SiscomDatCom.h>
#include <SiscomDesarrollo3Qt++.h>
CQSisProdCotiza3Qt::CQSisProdCotiza3Qt(SiscomRegistro3 *pSReg3Producto,
				       SiscomRegistro3 *pSReg3TipoPrecio,
				       SiscomRegistro3 *pSReg3Cliente,
				       SiscomRegistro3 *pSReg3FPago,
				       const char *pchrPtrCantidad,
				       const char *pchrPtrPrecio,
				       const char *pchrPtrImporte,
				       const char *pchrPtrExistencia,
				       const char *pchrPtrExiMinima,
				       const char *pchrPtrEdoVenta,
				       const char *pchrPtrEscala,
				       const char *pchrPtrTipoOrden,
				       const char *pchrPtrIva,
				       const char *pchrPtrTotalSinIva,
				       const char *pchrPtrNoRemFactura)
{
	(*this)								<<
	new SiscomCampo3("IdProducto",(*pSReg3Producto)["idproducto"])	<<
	new SiscomCampo3("Clave",(*pSReg3Producto)["clave"])		<<
	new SiscomCampo3("Dsc",(*pSReg3Producto)["dscproducto"])	<<
	new SiscomCampo3("IdFamilia",(*pSReg3Producto)["idfamilia"])	<<
	new SiscomCampo3("IdPrecio",(*pSReg3TipoPrecio)["idprecio"])	<<
	new SiscomCampo3("TipoPrecio",(*pSReg3TipoPrecio)["nombre"])	<<
	new SiscomCampo3("IdExpendio","0")				<<
	new SiscomCampo3("IdEmpleado","1")				<<
	new SiscomCampo3("IdFormaPago",(*pSReg3FPago)["idformapago"])   <<
	new SiscomCampo3("IdCliente",(*pSReg3Cliente)["idpersona"])	<<
	new SiscomCampo3("TipoCliente",(*pSReg3Cliente)["tipopersona"])	<<
	new SiscomCampo3("IdCotizacion","")				<<
	new SiscomCampo3("SePuedeVender","")				<<
	new SiscomCampo3("Total","")					<<
	new SiscomCampo3("Cantidad",pchrPtrCantidad)			<<
	new SiscomCampo3("Precio",pchrPtrPrecio)			<<
	new SiscomCampo3("Importe",pchrPtrImporte)			<<
	new SiscomCampo3("Existencia",pchrPtrExistencia)		<<
	new SiscomCampo3("ExiMinima",pchrPtrExiMinima)			<<
	new SiscomCampo3("EdoVenta",pchrPtrEdoVenta)			<<
	new SiscomCampo3("Escala",pchrPtrEscala)			<<
	new SiscomCampo3("TipoOrden",pchrPtrTipoOrden)			<<
	new SiscomCampo3("Iva",pchrPtrIva)				<<
	new SiscomCampo3("TotalSinIva",pchrPtrTotalSinIva)		<<
	new SiscomCampo3("NoRemFactura",pchrPtrNoRemFactura);
}
CQSisProdCotiza3QtLst::CQSisProdCotiza3QtLst()
{

}
const char *CQSisProdCotiza3QtLst::Total()
{
return chrPtrTotal;
}
const char *CQSisProdCotiza3QtLst::Iva()
{
return chrPtrIva;
}
const char *CQSisProdCotiza3QtLst::TotalSinIva()
{
return chrPtrTotalSinIva;
}
void CQSisProdCotiza3QtLst::Total(const char *pchrPtrTotal)
{
	chrPtrTotal=pchrPtrTotal;
}
void CQSisProdCotiza3QtLst::Iva(const char *pchrPtrIva)
{
	chrPtrIva=pchrPtrIva;
}
void CQSisProdCotiza3QtLst::TotalSinIva(const char *pchrPtrTotalSinIva)
{
	chrPtrTotalSinIva=pchrPtrTotalSinIva;
}
void CQSisProdCotiza3QtLst::ActualizaPrecioCantidad(
				CQSisProdCotiza3QtLst &pCQSProdCod3QtLst)
{
SiscomRegistro3 *lSReg3Producto;
pCQSProdCod3QtLst.first();
for(lSReg3Producto=first();
    lSReg3Producto;
    lSReg3Producto=next(),
    ++pCQSProdCod3QtLst)
{
 lSReg3Producto->SiscomActualizaCampo("Precio",pCQSProdCod3QtLst["Precio"]);
 lSReg3Producto->SiscomActualizaCampo("Total",pCQSProdCod3QtLst["Total"]);
 lSReg3Producto->SiscomActualizaCampo("Cantidad",pCQSProdCod3QtLst["Cantidad"]);
 lSReg3Producto->SiscomActualizaCampo("Escala",pCQSProdCod3QtLst["Escala"]);
}


}
int CQSisProdCotiza3QtLst::operator=(CQSisProdCotiza3QtLst &pCQSPCotiza3QtLst)
{
SiscomRegistro3 *lSReg3Producto;
pCQSPCotiza3QtLst.first();
for(lSReg3Producto=first();
    lSReg3Producto;
    lSReg3Producto=next(),
    ++pCQSPCotiza3QtLst)
 lSReg3Producto->SiscomActualizaCampo("Total",pCQSPCotiza3QtLst["Total"]);
return 1;
}
CQSisOpProductos3Qt::CQSisOpProductos3Qt(SiscomDatCom *pSisDatCom):
			SiscomOperaciones3(pSisDatCom)
{
}

void CQSisOpProductos3Qt::CotizaProductos(CQSisProdCotiza3QtLst *pCQSProdCotiza3QtLst)
{
CQSisProdCotiza3QtLst lCQSPCotiza3QtReg;
int lintUltimoProducto;
SiscomEnvia("CotizaProductos",
	    pCQSProdCotiza3QtLst,
	    &lCQSPCotiza3QtReg);
pCQSProdCotiza3QtLst->ActualizaPrecioCantidad(lCQSPCotiza3QtReg);
lintUltimoProducto=lCQSPCotiza3QtReg.count()-1;
pCQSProdCotiza3QtLst->Total((*lCQSPCotiza3QtReg.at(lintUltimoProducto))["Total"]);
pCQSProdCotiza3QtLst->TotalSinIva((*lCQSPCotiza3QtReg.at(lintUltimoProducto))["TotalSinIva"]);
pCQSProdCotiza3QtLst->Iva((*lCQSPCotiza3QtReg.at(lintUltimoProducto))["Iva"]);
*pCQSProdCotiza3QtLst=lCQSPCotiza3QtReg;
}

void CQSisOpProductos3Qt::CotizaProducto(CQSisProdCotiza3Qt *pCQSProdCotiza3Qt)
{
CQSisProdCotiza3QtLst lCQSPCotiza3QtLst;
CQSisProdCotiza3QtLst lCQSPCotiza3QtReg;
lCQSPCotiza3QtLst << pCQSProdCotiza3Qt;
SiscomEnvia("CotizaProductos",
	    &lCQSPCotiza3QtLst,
	    &lCQSPCotiza3QtReg);
SiscomEscribeLog3Qt("Los Registros De Respuesta:%d",
		    lCQSPCotiza3QtReg.count());
if(lCQSPCotiza3QtReg.count())
{
SiscomDesarrollo3Qt::ImprimeContenido(&lCQSPCotiza3QtReg);
lCQSPCotiza3QtReg.first();
pCQSProdCotiza3Qt->SiscomActualizaCampo("Precio",lCQSPCotiza3QtReg["Precio"]);
pCQSProdCotiza3Qt->SiscomActualizaCampo("SePuedeVender",lCQSPCotiza3QtReg["SePuedeVender"]);
pCQSProdCotiza3Qt->SiscomActualizaCampo("Existencia",lCQSPCotiza3QtReg["Existencia"]);
pCQSProdCotiza3Qt->SiscomActualizaCampo("Total",lCQSPCotiza3QtReg["Total"]);
pCQSProdCotiza3Qt->SiscomActualizaCampo("Escala",lCQSPCotiza3QtReg["Escala"]);
pCQSProdCotiza3Qt->SiscomActualizaCampo("Iva",lCQSPCotiza3QtReg["Iva"]);
pCQSProdCotiza3Qt->SiscomActualizaCampo("TotalSinIva",lCQSPCotiza3QtReg["TotalSinIva"]);
}
else
SiscomEscribeLog3Qt("No Se encontro Informacion Para Cotizar");
}

void CQSisOpProductos3Qt::GeneraIdentificador(CQSisProdCotiza3QtLst *pCQSProdCotiza3QtLst)
{
CQSisProdCotiza3QtLst lCQSPCotiza3QtLstReg;
SiscomEnvia("IdentificadorCotizacion",
	    pCQSProdCotiza3QtLst,
	    &lCQSPCotiza3QtLstReg);
SiscomDesarrollo3Qt::ImprimeContenido(&lCQSPCotiza3QtLstReg);
AsignaIdCotizacion(&lCQSPCotiza3QtLstReg,pCQSProdCotiza3QtLst);
}
void CQSisOpProductos3Qt::AsignaIdCotizacion(CQSisProdCotiza3QtLst *pCQSProd3QtLstDat,
					     CQSisProdCotiza3QtLst *pCQSProd3QtLstReg)
{
CQSisProdCotiza3Qt *lCQSPCotiza3Qt;
pCQSProd3QtLstDat->first();
for(lCQSPCotiza3Qt=(CQSisProdCotiza3Qt *)pCQSProd3QtLstReg->first();
    lCQSPCotiza3Qt;
    lCQSPCotiza3Qt=(CQSisProdCotiza3Qt *)pCQSProd3QtLstReg->next())
 lCQSPCotiza3Qt->SiscomActualizaCampo("IdCotizacion",(*pCQSProd3QtLstDat)["IdCotizacion"]);
}
