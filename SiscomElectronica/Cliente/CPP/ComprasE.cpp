#include <ComprasE.h>
#include <EmpresasN.h>


CompraE::CompraE(ProductoE *pProducto,
		 const char *pchrPtrFecha,
		 const char *pchrPtrPrecioCompra)
{

	SRegistroPro2			<<
	"CveProducto"			<<
	"Cantidad"			<<
	"Precio"			<<
	"Importe"			<<
	"RazonSocial"			<<
	"IdEmpresa"			<<
	"RFC"				<<
	"Expendio"			<<
	"IdExpendio"			<<
	"RFCExpendio"			<<
	"Fecha"				<<
	"FormaPago"			<<
	"NumFactura"			<<
	"PrecioVenta";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2									<<
	SiscomCampoPro2("CveProducto",pProducto->SRegistrosPro2["CveProducto"])		<<
	SiscomCampoPro2("Cantidad",pProducto->SRegistrosPro2["Cantidad"])		<<
	SiscomCampoPro2("Precio",pchrPtrPrecioCompra)					<<
	SiscomCampoPro2("Importe",pProducto->SRegistrosPro2["Importe"])			<<
	SiscomCampoPro2("RazonSocial",pProducto->SRegistrosPro2["Proveedor"]) 		<<
	SiscomCampoPro2("IdEmpresa",pProducto->SRegistrosPro2["IdProveedor"])		<<
	SiscomCampoPro2("RFC","")							<<
	SiscomCampoPro2("Expendio","")							<<
	SiscomCampoPro2("IdExpendio","")						<<
	SiscomCampoPro2("RFCExpendio","")						<<
	SiscomCampoPro2("Fecha",pchrPtrFecha)						<<
	SiscomCampoPro2("FormaPago","")							<<
	SiscomCampoPro2("NumFactura",pProducto->SRegistrosPro2["NumFactura"])		<<
	SiscomCampoPro2("PrecioVenta",pProducto->SRegistrosPro2["Precio"]);

	SRegistrosPro2.SiscomAnexaRegistro();
}
		
ComprasE::ComprasE()
{


}
ComprasE &ComprasE::operator<<(CompraE *pCompra)
{
	append(pCompra);
	return *this;
}
OpCompras::OpCompras(SiscomDatCom *pSisDatCom,
		  const char *pchrPtrIdEmpleado,
		  ProductosE &pProductos):
		  SisDatCom(pSisDatCom),
		 chrPtrIdEmpleado(pchrPtrIdEmpleado),
		 PProductos(pProductos)
		 
{


}
void OpCompras::RegistraCompras()
{
SiscomGeneralOperacionesSrv lSGenOp(SisDatCom,
				    (QPtrList<SiscomInformacion>*)&PProductos);
	PProductos.at(0)->SiscomActualizaCampo("IdUnidad",chrPtrIdEmpleado);
	lSGenOp.SiscomEjecutaEnvio("RegistraCompras");

}
void OpCompras::ConsultaCompras()
{

}
