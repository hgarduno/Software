#include <CQSisProductosE3Qt.h>
CQSisProductoE3::CQSisProductoE3(SiscomRegistro3 *pSisReg3Producto)
{
(*this)									<<
new SiscomCampo3("CveProducto",(*pSisReg3Producto)["cveproducto"])	<<
new SiscomCampo3("DscProducto",(*pSisReg3Producto)["dscproducto"])	<<
new SiscomCampo3("IdUnidad","")						<<
new SiscomCampo3("IdFamilia","")					<<
new SiscomCampo3("Precio","")						<<
new SiscomCampo3("NmbPrecio","DEFAULT")					<<
new SiscomCampo3("Cantidad","1")					<<
new SiscomCampo3("Existencia","1")					<<
new SiscomCampo3("IdCliente","")					<<
new SiscomCampo3("IdExpendio","")					<<
new SiscomCampo3("Importe","")						<<
new SiscomCampo3("SePuedeVender","")					<<
new SiscomCampo3("NumJuegos","")					<<
new SiscomCampo3("IdProveedor","")					<<
new SiscomCampo3("Proveedor","")					<<
new SiscomCampo3("NumFactura","")					<<
new SiscomCampo3("FechaPago","")					<<
new SiscomCampo3("EdoRegistro","")					<<
new SiscomCampo3("IdPractica","")					<<
new SiscomCampo3("NmbUnidad","")					<<
new SiscomCampo3("Abreviatura","")					<<
new SiscomCampo3("NmbFamilia","")					<<
new SiscomCampo3("PrecioIVA","")					<<
new SiscomCampo3("ClienteFrecuente","")					<<
new SiscomCampo3("PorDescuento","")					<<
new SiscomCampo3("RFC","")						<<
new SiscomCampo3("ExistenciaMinima","")					<<
new SiscomCampo3("IdCaja","");


}
CQSisProductoE3::CQSisProductoE3(const char *pchrPtrCveProducto,
			 const char *pchrPtrDscProducto,
			 const char *pchrPtrIdUnidad,
			 const char *pchrPtrIdFamilia,
			 const char *pchrPtrPrecio,
			 const char *pchrPtrNmbPrecio,
			 const char *pchrPtrCantidad,
			 const char *pchrPtrExistencia,
			 const char *pchrPtrIdCliente,
			 const char *pchrPtrIdExpendio,
			 const char *pchrPtrImporte,
			 const char *pchrPtrSePuedeVender,
			 const char *pchrPtrNumJuegos,
			 const char *pchrPtrIdProveedor,
			 const char *pchrPtrProveedor,
			 const char *pchrPtrNumFactura,
			 const char *pchrPtrFechaPago,
			 const char *pchrPtrEdoRegistro,
			 const char *pchrPtrIdPractica,
			 const char *pchrPtrNmbUnidad,
			 const char *pchrPtrAbreviatura,
			 const char *pchrPtrNmbFamilia,
			 const char *pchrPtrPrecioIVA,
			 const char *pchrPtrClienteFrecuente,
			 const char *pchrPtrPorDescuento,
			 const char *pchrPtrRFC,
			 const char *pchrPtrExistenciaMinima)
{

	(*this)								<<
	new SiscomCampo3("CveProducto",pchrPtrCveProducto)      	<<
	new SiscomCampo3("DscProducto",pchrPtrDscProducto)		<<
	new SiscomCampo3("IdUnidad",pchrPtrIdUnidad)			<<
	new SiscomCampo3("IdFamilia",pchrPtrIdFamilia)			<<
	new SiscomCampo3("Precio",pchrPtrPrecio)			<<
	new SiscomCampo3("NmbPrecio",pchrPtrNmbPrecio)			<<
	new SiscomCampo3("Cantidad",pchrPtrCantidad)			<<
	new SiscomCampo3("Existencia",pchrPtrExistencia)		<<
	new SiscomCampo3("IdCliente",pchrPtrIdCliente)			<<
	new SiscomCampo3("IdExpendio",pchrPtrIdExpendio)		<<
	new SiscomCampo3("Importe",pchrPtrImporte)			<<
	new SiscomCampo3("SePuedeVender",pchrPtrSePuedeVender)		<<
	new SiscomCampo3("NumJuegos",pchrPtrNumJuegos)			<<
	new SiscomCampo3("IdProveedor",pchrPtrIdProveedor)		<<
	new SiscomCampo3("Proveedor",pchrPtrProveedor)			<<
	new SiscomCampo3("NumFactura",pchrPtrNumFactura)		<<
	new SiscomCampo3("FechaPago",pchrPtrFechaPago)			<<
	new SiscomCampo3("EdoRegistro",pchrPtrEdoRegistro)		<<
	new SiscomCampo3("IdPractica",pchrPtrIdPractica)		<<
	new SiscomCampo3("NmbUnidad",pchrPtrNmbUnidad)			<<
	new SiscomCampo3("Abreviatura",pchrPtrAbreviatura)		<<
	new SiscomCampo3("NmbFamilia",pchrPtrNmbFamilia)		<<
	new SiscomCampo3("PrecioIVA",pchrPtrPrecioIVA)			<<
	new SiscomCampo3("ClienteFrecuente",pchrPtrClienteFrecuente)	<<
	new SiscomCampo3("PorDescuento",pchrPtrPorDescuento)		<<
	new SiscomCampo3("RFC",pchrPtrRFC)				<<
	new SiscomCampo3("ExistenciaMinima",pchrPtrExistenciaMinima)	<<
	new SiscomCampo3("IdCaja","");
}

CQSisOrdenesElectronica::CQSisOrdenesElectronica(SiscomDatCom *pSisDatCom):
			SiscomOperaciones3(pSisDatCom)
{

}

void CQSisOrdenesElectronica::ProductosOrden(const char *pchrPtrIdExpendio,
						 const char *pchrPtrIdVenta,
						 SiscomRegistro3Lst *pSisReg3Productos)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3Productos,
	    "%s%s%s",
	    "ProductosOrden",
	    pchrPtrIdExpendio,
	    pchrPtrIdVenta);
}

void CQSisOrdenesElectronica::CotizaDispositivos(SiscomRegistro3Lst *pSisReg3Productos)
{
SiscomEnvia("CotizaDispositivos",
	    pSisReg3Productos);
}
