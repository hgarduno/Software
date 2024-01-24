#include <ProductosE.h>
#include <TipoPrecios.h>
#include <ComprasE.h>
#include <Familias.h>
#include <Unidades.h>

#include <zSiscomDesarrollo4.h>

ProductoE::ProductoE(ProductoE *pProducto)
{
	SRegistroPro2 			<<
	"CveProducto"			<<
	"DscProducto"			<<
	"IdUnidad"			<<
	"IdFamilia"			<<
	"Precio"			<<
	"NmbPrecio"			<<
	"Cantidad"			<<
	"Existencia"			<<
	"IdCliente"			<<
	"IdExpendio"                    <<
	"Importe"			<<
	"SePuedeVender"			<<
	"NumJuegos"			<<
	"IdProveedor"			<<
	"Proveedor"			<<
	"NumFactura"			<<
	"FechaPago"			<<
	"EdoRegistro"			<<
	"IdPractica"			<<
	"NmbUnidad"			<<
	"Abreviatura"			<<
	"NmbFamilia"			<<
	"PrecioIVA"			<<
	"ClienteFrecuente"		<<
	"PorDescuento"			<<
	"RFC"				<<
	"ExistenciaMinima"		<<
	"IdCaja"			<<
	"Recibi"			<<
	"Cambio"			<<
	"IdEscuela"			<<
	"IdBodega"			<<
	"ExisBodega"			<<
	"PorDescuentoCaja"		<<
	"PorDescuentoCajaOrden"		<<
	"OrdenACaja"			<<
	"CantidadValida";


	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2					  				<<
	SiscomCampoPro2("CveProducto",pProducto->SRegistrosPro2["CveProducto"])		<<
	SiscomCampoPro2("DscProducto",pProducto->SRegistrosPro2["DscProducto"])		<<
	SiscomCampoPro2("IdUnidad",pProducto->SRegistrosPro2["IdUnidad"])		<<
	SiscomCampoPro2("IdFamilia",pProducto->SRegistrosPro2["IdFamilia"])		<<
	SiscomCampoPro2("Precio",pProducto->SRegistrosPro2["Precio"])			<<
	SiscomCampoPro2("NmbPrecio",pProducto->SRegistrosPro2["NmbPrecio"])		<<
	SiscomCampoPro2("Cantidad",pProducto->SRegistrosPro2["Cantidad"])		<<
	SiscomCampoPro2("Existencia",pProducto->SRegistrosPro2["Existencia"])		<<
	SiscomCampoPro2("IdCliente",pProducto->SRegistrosPro2["IdCliente"])		<<
	SiscomCampoPro2("IdExpendio",pProducto->SRegistrosPro2["IdExpendio"])         	<<
	SiscomCampoPro2("Importe",pProducto->SRegistrosPro2["Importe"])			<<
	SiscomCampoPro2("SePuedeVender",pProducto->SRegistrosPro2["SePuedeVender"])	<<
	SiscomCampoPro2("NumJuegos",pProducto->SRegistrosPro2["NumJuegos"])		<<
	SiscomCampoPro2("IdProveedor",pProducto->SRegistrosPro2["IdProveedor"])		<<
	SiscomCampoPro2("Proveedor",pProducto->SRegistrosPro2["Proveedor"])		<<
	SiscomCampoPro2("NumFactura",pProducto->SRegistrosPro2["NumFactura"])		<<
	SiscomCampoPro2("FechaPago",pProducto->SRegistrosPro2["FechaPago"])		<<
	SiscomCampoPro2("EdoRegistro",pProducto->SRegistrosPro2["EdoRegistro"])		<<
	SiscomCampoPro2("IdPractica",pProducto->SRegistrosPro2["IdPractica"])		<<
	SiscomCampoPro2("NmbUnidad",pProducto->SRegistrosPro2["NmbUnidad"])		<<
	SiscomCampoPro2("Abreviatura",pProducto->SRegistrosPro2["Abreviatura"])		<<
	SiscomCampoPro2("NmbFamilia",pProducto->SRegistrosPro2["NmbFamilia"])		<<
	SiscomCampoPro2("PrecioIVA",pProducto->SRegistrosPro2["PrecioIVA"])		<<
	SiscomCampoPro2("ClienteFrecuente",pProducto->SRegistrosPro2["ClienteFrecuente"])<<
	SiscomCampoPro2("PorDescuento",pProducto->SRegistrosPro2["PorDescuento"])	<<
	SiscomCampoPro2("RFC",pProducto->SRegistrosPro2["RFC"])					<<
	SiscomCampoPro2("ExistenciaMinima",pProducto->SRegistrosPro2["ExistenciaMinima"])	<<
	SiscomCampoPro2("IdCaja",pProducto->SRegistrosPro2["IdCaja"])				<<
	SiscomCampoPro2("Recibi",pProducto->SRegistrosPro2["Recibi"])	<<
	SiscomCampoPro2("Cambio",pProducto->SRegistrosPro2["Cambio"])	<<
	SiscomCampoPro2("IdEscuela",pProducto->SRegistrosPro2["IdEscuela"])	<<
	SiscomCampoPro2("IdBodega",pProducto->SRegistrosPro2["IdBodega"])	<<
	SiscomCampoPro2("ExisBodega",pProducto->SRegistrosPro2["ExisBodega"])	<<
	SiscomCampoPro2("PorDescuentoCaja",pProducto->SRegistrosPro2["PorDescuentoCaja"])	<<
	SiscomCampoPro2("PorDescuentoCajaOrden",pProducto->SRegistrosPro2["PorDescuentoCajaOrden"])	<<
	SiscomCampoPro2("OrdenCaja",pProducto->SRegistrosPro2["OrdenCaja"])	<<
	SiscomCampoPro2("CantidadValida",pProducto->SRegistrosPro2["CantidadValida"]);

	SRegistrosPro2.SiscomAnexaRegistro();

}
ProductoE::ProductoE(const char *pchrPtrCveProducto,
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
		   const char *pchrPtrExistenciaMinima,
		   const char *pchrPtrIdCaja,
		   const char *pchrPtrRecibi,
		   const char *pchrPtrCambio,
		   const char *pchrPtrIdEscuela,
		   const char *pchrPtrIdBodega,
		   const char *pchrPtrExisBodega,
		   const char *pchrPtrPorDescuentoCaja,
		   const char *pchrPtrPorDescuentoCajaOrden,
		   const char *pchrPtrOrdenACaja,
		   const char *pchrPtrCantidadValida,
		   const char *pchrPtrIdOrigenCompra,
		   const char *pchrPtrEsKit,
		   const char *pchrPtrCveKit,
		   const char *pchrPtrTipoCotizacion,
		   const char *pchrPtrIdProductoKit,
		   const char *pchrPtrCantidadKit,
		   const char *pchrPtrImporteKit,
		   const char *pchrPtrIdTipoProducto, //44
		   const char *pchrPtrCantidadTransfiereZacatenco)
{

	SRegistroPro2 			<<
	"CveProducto"			<<
	"DscProducto"			<<
	"IdUnidad"			<<
	"IdFamilia"			<<
	"Precio"			<<
	"NmbPrecio"			<<
	"Cantidad"			<<
	"Existencia"			<<
	"IdCliente"			<<
	"IdExpendio"                    <<
	"Importe"			<<
	"SePuedeVender" 		<<
	"NumJuegos"			<<
	"IdProveedor"			<<
	"Proveedor"			<<
	"NumFactura"			<<
	"FechaPago" 			<<
	"EdoRegistro"			<<
	"IdPractica"			<<
	"NmbUnidad"			<<
	"Abreviatura"			<<
	"NmbFamilia"			<<
	"PrecioIVA"			<<
	"ClienteFrecuente"		<<
	"PorDescuento"			<<
	"RFC"				<<
	"ExistenciaMinima"		<<
	"IdCaja"			<<
	"Recibi"			<<
	"Cambio"			<<
	"IdEscuela"			<<
	"IdBodega"			<<
	"ExisBodega"			<<
	"PorDescuentoCaja"		<<
	"PorDescuentoCajaOrden"		<<
	"OrdenACaja"			<<
	"CantidadValida"		<<
	"IdOrigenCompra"		<<
	"EsKit"				<<
	"ClaveKit"			<<
	"TipoCotizacion"		<<
	"IdProductoKit"			<<
	"CantidadKit"			<<
	"ImporteKit"			<<
	"IdTipoProducto"		<<
	"CantidadTransfiereZacatenco";


	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2					  			<<
	SiscomCampoPro2("CveProducto",pchrPtrCveProducto)			<<
	SiscomCampoPro2("DscProducto",pchrPtrDscProducto)			<<
	SiscomCampoPro2("IdUnidad",pchrPtrIdUnidad)				<<
	SiscomCampoPro2("IdFamilia",pchrPtrIdFamilia)				<<
	SiscomCampoPro2("Precio",pchrPtrPrecio)					<<
	SiscomCampoPro2("NmbPrecio",pchrPtrNmbPrecio)				<<
	SiscomCampoPro2("Cantidad",pchrPtrCantidad)				<<
	SiscomCampoPro2("Existencia",pchrPtrExistencia)				<<
	SiscomCampoPro2("IdCliente",pchrPtrIdCliente)				<<
	SiscomCampoPro2("IdExpendio",pchrPtrIdExpendio)         		<<
	SiscomCampoPro2("Importe",pchrPtrImporte)				<<
	SiscomCampoPro2("SePuedeVender",pchrPtrSePuedeVender)   		<<
	SiscomCampoPro2("NumJuegos",pchrPtrNumJuegos)				<<
	SiscomCampoPro2("IdProveedor",pchrPtrIdProveedor)			<<
	SiscomCampoPro2("Proveedor",pchrPtrProveedor)				<<
	SiscomCampoPro2("NumFactura",pchrPtrNumFactura)				<<
	SiscomCampoPro2("FechaPago",pchrPtrFechaPago)				<<
	SiscomCampoPro2("EdoRegistro",pchrPtrEdoRegistro)			<<
	SiscomCampoPro2("IdPractica",pchrPtrIdPractica)				<<
	SiscomCampoPro2("NmbUnidad",pchrPtrNmbUnidad)				<<
	SiscomCampoPro2("Abreviatura",pchrPtrAbreviatura)			<<
	SiscomCampoPro2("NmbFamilia",pchrPtrNmbFamilia)				<<
	SiscomCampoPro2("PrecioIVA",pchrPtrPrecioIVA)				<<
	SiscomCampoPro2("ClienteFrecuente",pchrPtrClienteFrecuente)		<<
	SiscomCampoPro2("PorDescuento",pchrPtrPorDescuento)			<<
	SiscomCampoPro2("RFC",pchrPtrRFC)					<<
	SiscomCampoPro2("ExistenciaMinima",pchrPtrExistenciaMinima)		<<
	SiscomCampoPro2("IdCaja",pchrPtrIdCaja)					<<
	SiscomCampoPro2("Recibi",pchrPtrRecibi)					<<
	SiscomCampoPro2("Cambio",pchrPtrCambio)					<<
	SiscomCampoPro2("IdEscuela",pchrPtrIdEscuela)				<<
	SiscomCampoPro2("IdBodega",pchrPtrIdBodega)				<<
	SiscomCampoPro2("ExisBodega",pchrPtrExisBodega)				<<
	SiscomCampoPro2("PorDescuentoCaja",pchrPtrPorDescuentoCaja)		<<
	SiscomCampoPro2("PorDescuentoCajaOrden",pchrPtrPorDescuentoCajaOrden)	<<
	SiscomCampoPro2("OrdenACaja",pchrPtrOrdenACaja)				<<
	SiscomCampoPro2("CantidadValida",pchrPtrCantidadValida)			<<
	SiscomCampoPro2("IdOrigenCompra",pchrPtrIdOrigenCompra)			<<
	SiscomCampoPro2("EsKit",pchrPtrEsKit)					<<
	SiscomCampoPro2("ClaveKit",pchrPtrCveKit)				<<
	SiscomCampoPro2("TipoCotizacion",pchrPtrTipoCotizacion)			<<
	SiscomCampoPro2("IdProductoKit",pchrPtrIdProductoKit)			<<
	SiscomCampoPro2("CantidadKit",pchrPtrCantidadKit)			<<
	SiscomCampoPro2("ImporteKit",pchrPtrImporteKit)				<<
	SiscomCampoPro2("IdTipoProducto",pchrPtrIdTipoProducto)			<<
	SiscomCampoPro2("IdOrigenCompra",pchrPtrIdOrigenCompra)			<<
	SiscomCampoPro2("CantidadTransfiereZacatenco",pchrPtrCantidadTransfiereZacatenco);

	SRegistrosPro2.SiscomAnexaRegistro();
}
Familia *ProductoE::ObtenFamilia()
{
return new Familia(SRegistrosPro2["IdFamilia"],
		    SRegistrosPro2["NmbFamilia"],
		    SRegistrosPro2[""],
		    "Insertado");
}
Unidad *ProductoE::ObtenUnidad()
{
return new Unidad(SRegistrosPro2["IdUnidad"],
		  SRegistrosPro2["NmbUnidad"],
		  "");

}
ProductosE::ProductosE()
{

}

ProductoE *ProductosE::operator[](int pintNProducto)
{
	return at(pintNProducto);
}
ProductosE &ProductosE::operator<<(ProductoE *pProducto)
{
	append(pProducto);
	return *this;
}
ProductosE &ProductosE::operator+=(ProductosE &pProductos)
{
ProductoE *lProducto;
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Operador +=");

	for(lProducto=pProductos.first();
	    lProducto;
	    lProducto=pProductos.next())
	  append(lProducto);
	  return *this;
}
ConsultaProductosE::ConsultaProductosE()
{

}
ConsultaProductosE::ConsultaProductosE(SiscomDatCom *pSisDatCom):
		SisDatCom(pSisDatCom)
{

}
ConsultaProductosE::ConsultaProductosE(SiscomDatCom *pSisDatCom,
				     const char *pchrPtrCveProducto,
				     const char *pchrPtrDscProducto,
				     const char *pchrPtrFamilia,
				     const char *pchrPtrIdExpendio,
				     ProductosE &pProductos)
{
SiscomParametrosConsulta lSPConsulta;

		lSPConsulta 				         	<<
		new SiscomParametroConsulta("ProductosExpendio")	<<
		new SiscomParametroConsulta(pchrPtrCveProducto)		<<
		new SiscomParametroConsulta(pchrPtrDscProducto)		<<
		new SiscomParametroConsulta(pchrPtrFamilia)		<<
		new SiscomParametroConsulta(pchrPtrIdExpendio);
SiscomGeneralOperacionesSrv lSGenOp(
				pSisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("ConsultaProductos");
		GeneraProductos((const SiscomComunicaSrv *)lSGenOp,pProductos);
}

void ConsultaProductosE::GeneraProductos(const SiscomComunicaSrv *pSComunicaSrv,
					ProductosE &pProductos)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);

	for(;
		!lSRegistrosPro2.SiscomEsElUltimoRegistro();
		++lSRegistrosPro2)
	  pProductos 	<<
	   new ProductoE(lSRegistrosPro2["cveproducto"],
	   	        lSRegistrosPro2["dscproducto"],
			lSRegistrosPro2["unidad"],
			lSRegistrosPro2["idfamilia"],
			lSRegistrosPro2["precio"],
			"",
			"",
			lSRegistrosPro2["existencia"],
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			lSRegistrosPro2["nmbunidad"],
			lSRegistrosPro2["abreviatura"],
			lSRegistrosPro2["nmbfamilia"],
			"",
			"",
			"",
			"",
			lSRegistrosPro2["eximinima"],
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			lSRegistrosPro2["idtipoproducto"]);
	delete pSComunicaSrv;
}
void ConsultaProductosE::ObtenDatosProducto(const char *pchrPtrIdExpendio,
					    const char *pchrPtrCveProducto,
					    const char *pchrPtrTipoBusqueda,
					    ProductosE &pProductos)
{
SiscomParametrosConsulta lSPConsulta;

		lSPConsulta 				         			<<
		new SiscomParametroConsulta("DatosProducto")				<<
		new SiscomParametroConsulta(pchrPtrCveProducto)				<<	
		new SiscomParametroConsulta(pchrPtrIdExpendio)				<<	
		new SiscomParametroConsulta(pchrPtrTipoBusqueda)			<<
		new SiscomParametroConsulta(pchrPtrIdExpendio);	
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("ConsultaProductos");
		GeneraProductos((const SiscomComunicaSrv *)lSGenOp,pProductos);
}
void ConsultaProductosE::ObtenDatosProducto(SiscomDatCom *pSisDatCom,
				       ProductoE *pProducto,
				       ProductosE &pProductos)
{
SiscomParametrosConsulta lSPConsulta;

		lSPConsulta 				         	<<
		new SiscomParametroConsulta("DatosProducto")		<<
		new SiscomParametroConsulta(pProducto->SRegistrosPro2["CveProducto"])	;	
SiscomGeneralOperacionesSrv lSGenOp(
				pSisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("ConsultaProductos");
		GeneraProductos((const SiscomComunicaSrv *)lSGenOp,pProductos);
}
void ConsultaProductosE::ActualizaDatosProductos(ProductosE &pProductos)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&pProductos);
		lSGenOp.SiscomEjecutaEnvio("ActualizaProducto");

}
void ConsultaProductosE::ObtenProductosSimilares(const char *pchrPtrProducto,
						 const char *pchrPtrIdExpendio,
						 ProductosE &pProductos)
{
SiscomParametrosConsulta lSPConsulta;

		lSPConsulta 				         	<<
		new SiscomParametroConsulta("ConsultaSimilares") 	<<
		new SiscomParametroConsulta(pchrPtrProducto)		<<	
		new SiscomParametroConsulta("")				<<
		new SiscomParametroConsulta("")				<<
		new SiscomParametroConsulta(pchrPtrIdExpendio);
		
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("ConsultaProductos");
		GeneraProductos((const SiscomComunicaSrv *)lSGenOp,pProductos);
}
void ConsultaProductosE::ObtenProductosPorcentajeExistenciaMinima(
			const char *pchrPtrIdExpendio,
			const char *pchrPtrPorBajo,
			const char *pchrPtrPorAlto,
			ProductosE &pProductos)
{
SiscomParametrosConsulta lSPConsulta;

lSPConsulta 				         	<<
new SiscomParametroConsulta("ConsultaPorcentajeExistenciaMinima")	<<
new SiscomParametroConsulta(pchrPtrIdExpendio)			<<
new SiscomParametroConsulta(pchrPtrPorBajo)			<<
new SiscomParametroConsulta(pchrPtrPorAlto)			<<	
new SiscomParametroConsulta(pchrPtrIdExpendio);	

SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("ConsultaProductos");
		GeneraProductos((const SiscomComunicaSrv *)lSGenOp,pProductos);
}
void ConsultaProductosE::ObtenProductosPorDescripcion(const char *pchrPtrDescripcion,
						      const char *pchrPtrIdExpendio,
						      ProductosE &pProductos)
{
SiscomParametrosConsulta lSPConsulta;

		lSPConsulta 				       		  	<<
		new SiscomParametroConsulta("ConsultaDescripcion")		<<
		new SiscomParametroConsulta(pchrPtrIdExpendio)			<< 
		new SiscomParametroConsulta(pchrPtrDescripcion)	;	
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvioSubRegistros("ConsultaProductosDescripcion");
		GeneraProductos((const SiscomComunicaSrv *)lSGenOp,pProductos);
}
void ConsultaProductosE::ObtenPrecioProducto(TipoPrecio *pTipoPrecio,
				       ProductoE *pProducto,
				       ProductosE &pProductos)
{
SiscomParametrosConsulta lSPConsulta;

		lSPConsulta 				       		  		  <<
		new SiscomParametroConsulta("ConsultaPrecioProducto")			  <<
		new SiscomParametroConsulta(pProducto->SRegistrosPro2["CveProducto"]) 	  <<
		new SiscomParametroConsulta(pTipoPrecio->SRegistrosPro2["NmbTipoPrecio"]) <<
		new SiscomParametroConsulta("")						  <<
		new SiscomParametroConsulta((*pProducto)["IdExpendio"])	;	
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("ConsultaProductos");
		GeneraProductos((const SiscomComunicaSrv *)lSGenOp,pProductos);
}
void ConsultaProductosE::ConsultaUltimaCompra(TipoPrecio *pTipoPrecio,
					      ProductoE *pProducto,
					      const char *pchrPtrIdExpendio,
					      ComprasE *pCompras)
{
SiscomParametrosConsulta lSPConsulta;

		lSPConsulta 				       		  	<<
		new SiscomParametroConsulta("ConsultaUltimaCompra")		<<
		new SiscomParametroConsulta(pProducto->SRegistrosPro2["CveProducto"]) <<
		new SiscomParametroConsulta(pTipoPrecio->SRegistrosPro2["NmbTipoPrecio"]) <<
		new SiscomParametroConsulta(pchrPtrIdExpendio)				  <<	
		new SiscomParametroConsulta(pchrPtrIdExpendio);	
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("ConsultaProductos");
		AsignaDatosUltimaCompra((const SiscomComunicaSrv *)lSGenOp,pCompras);


}
void ConsultaProductosE::AsignaDatosUltimaCompra(const SiscomComunicaSrv *pSComunicaSrv,
						 ComprasE *pCompras)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);

	if(!lSRegistrosPro2.SiscomEsElUltimoRegistro())
	{
	  (*pCompras) << new CompraE(new ProductoE(lSRegistrosPro2["cveproducto"],
	  					"",
						"",
						"",
						lSRegistrosPro2["precioventa"],
						"",
						lSRegistrosPro2["cantidad"],
						"",
						"",
						"",
						"",
						"",
						"",
						lSRegistrosPro2["idproveedor"],
						lSRegistrosPro2["proveedor"],
						lSRegistrosPro2["numfactura"],
						"",
						"",
						"",
						"",
						"",
						""),
					lSRegistrosPro2["fecha"],
					lSRegistrosPro2["preciocompra"]);
	}
delete pSComunicaSrv;
}
void ConsultaProductosE::ActualizaPrecio(TipoPrecio *pTipoPrecio,
					 ProductoE *pProducto,
					 const char *pchrPtrPrecio)
{
SiscomParametrosConsulta lSPConsulta;

		lSPConsulta 				       		  			<<
		new SiscomParametroConsulta("ActualizaPrecio")					<<
		new SiscomParametroConsulta(pProducto->SRegistrosPro2["CveProducto"]) 		<<
		new SiscomParametroConsulta(pTipoPrecio->SRegistrosPro2["NmbTipoPrecio"])	<<
		new SiscomParametroConsulta(pchrPtrPrecio);	
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("ActualizaPrecio");
}
void ConsultaProductosE::ActualizaExistenciaMinima(ProductosE &pProductos)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&pProductos);
		lSGenOp.SiscomEjecutaEnvio("ActualizaExistenciaMinima");


}
void ConsultaProductosE::RegistraProductos(ProductosE &pProductos)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&pProductos);
		lSGenOp.SiscomEjecutaEnvio("RegistraProductos");


}
QManProductos::QManProductos(SiscomDatCom *pSisDatCom,
			     const char *pchrPtrIdExpendio,
			     QComboBox *pQCBProductos,
			     QLineEdit *pQLECProductos,
			     QTextEdit *pQLEDescripcion,
			     QWidget *pQWParent,
			     const char *pchrPtrName):
	SisDatCom(pSisDatCom),
	QWidget(pQWParent,pchrPtrName),
	QCBProductos(pQCBProductos),
	QLECProductos(pQLECProductos),
	QLEDescripcion(pQLEDescripcion)
{
	ConectaSlots();
	LlenaComboProductos(pchrPtrIdExpendio);

}

void QManProductos::LlenaComboProductos(const char *pchrPtrIdExpendio)
{
ConsultaProductosE lCnsProductos(SisDatCom,
				"",
				"",
				"",
				pchrPtrIdExpendio,
				PProductos);
ProductoE *lProducto;
  for(lProducto=PProductos.first();
      lProducto;
      lProducto=PProductos.next())
	QCBProductos->insertItem(lProducto->SRegistrosPro2["CveProducto"]);

}
void QManProductos::ConectaSlots()
{
	/*
	connect(QCBProductos,
		SIGNAL(highlighted(int)),
		SLOT(S_SeleccionandoProducto(int)));
	connect(QCBProductos,
		SIGNAL(textChanged(const QString &)),
		SLOT(S_SeleccionandoProducto(const QString &)));
		*/
	connect(QLECProductos,
		SIGNAL(returnPressed()),
		SLOT(S_SeleccionoProducto()));

}
void QManProductos::S_SeleccionandoProducto(const QString &pQSCveProducto)
{
}
void QManProductos::S_SeleccionandoProducto(int pintNProducto)
{
	QLEDescripcion->setText(((ProductoE *)PProductos.at(pintNProducto))->SRegistrosPro2["DscProducto"]);
}
void QManProductos::S_SeleccionoProducto()
{
	if(EsParteLista((const char *)QLECProductos->text()))
	{
	 int lintProducto=QCBProductos->currentItem();
	 LogSiscom("El Numero %d",lintProducto);
	 ProductoE *lProducto=PProductos.at(lintProducto);
	 QLEDescripcion->setText(lProducto->SRegistrosPro2["DscProducto"]);
	emit SignalProducto(lProducto);
	}
	else
	emit SignalNoEstaClave((const char *)QLECProductos->text());


}
int QManProductos::EsParteLista(const char *pchrPtrProducto)
{
ProductoE *lProducto;
	for(lProducto=PProductos.first();
	    lProducto;
	    lProducto=PProductos.next())
	 if(!strcmp(pchrPtrProducto,lProducto->SRegistrosPro2["CveProducto"]))
	  return 1;

	return 0;

}
const ProductosE &QManProductos::ObtenProductos()
{
	return PProductos;
}
void QManProductos::setFocus()
{
     SiscomPasaFocoControl(QLECProductos);
}
