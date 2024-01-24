#include <CQSisCompras.h>
#include <CQSisContactos.h>
#include <CQSisFormaPago.h>
#include <CQSisEmpresas.h>
#include <CQSisContactos.h>
#include <CQSisProductos.h>
#include <CQSisFamilias.h>
#include <CQSisObjetosTiendas4.h>
CQSisCompra::CQSisCompra(
		CQSisProducto *pCQSProducto,
		CQSisEmpresa *pCQSEmpresa,
		CQSisContacto *pCQSContacto,
		CQSisFormaPago *pCQSFPago,
		const char *pchrPtrIdCompra,
		const char *pchrPtrCantidad,
		const char *pchrPtrPrecio,
		const char *pchrPtrFactura,
		const char *pchrPtrFecha,
		const char *pchrPtrIdExpendio):
	CQSProducto(pCQSProducto),
	CQSEmpresa(pCQSEmpresa),
	CQSContacto(pCQSContacto),
	CQSFPago(pCQSFPago)
{
	SRegistroPro2		<<
	"IdProducto"		<<
	"IdEmpresa"		<<
	"IdContacto"		<<
	"IdCompra"		<<
	"Cantidad"		<<
	"Precio"		<<
	"Factura"		<<
	"Fecha"			<<
	"IdFormaPago"		<<
	"IdExpendio";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2				<<
SiscomCampoPro2("IdProducto",CQSProducto->SRegistrosPro2["IdProducto"]) <<
SiscomCampoPro2("IdEmpresa",CQSEmpresa->SRegistrosPro2["IdEmpresa"])	<<
SiscomCampoPro2("IdContacto",CQSContacto->ObtenPersona()->SRegistrosPro2["IdPersona"])	<<
SiscomCampoPro2("IdCompra",pchrPtrIdCompra)	<<
SiscomCampoPro2("Cantidad",pchrPtrCantidad)	<<
SiscomCampoPro2("Precio",pchrPtrPrecio)		<<
SiscomCampoPro2("Factura",pchrPtrFactura)	<<
SiscomCampoPro2("Fecha",pchrPtrFecha)		<<
SiscomCampoPro2("IdFormaPago",CQSFPago->SRegistrosPro2["IdFormaPago"]) <<
SiscomCampoPro2("IdExpendio",pchrPtrIdExpendio);
SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisProducto *CQSisCompra::Producto()
{
	return CQSProducto;
}
CQSisEmpresa *CQSisCompra::Proveedor()
{
	return CQSEmpresa;
}
CQSisContacto *CQSisCompra::Contacto()
{
	return CQSContacto;
}
CQSisFormaPago *CQSisCompra::FormaPago()
{
	return CQSFPago;
}
CQSisLstCompra::CQSisLstCompra()
{
//	setAutoDelete(true);
}
CQSisLstCompra::~CQSisLstCompra()
{
	clear();
}
CQSisLstCompra &CQSisLstCompra::operator<<(CQSisCompra *pCQSCompra)
{
	append(pCQSCompra);
	return *this;
}

CQSisOpCompras::CQSisOpCompras(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{
	SPConsulta.setAutoDelete(true);
}
CQSisOpCompras::~CQSisOpCompras()
{
	SPConsulta.clear();
}
void CQSisOpCompras::Registra(CQSisLstCompra *pCQSLCompra)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomPonParametrosConsulta((SiscomInformacionLst *)pCQSLCompra);
SiscomActualiza2SubRegistros("RegistraCompra",&lSRegistrosPro2);
}
void CQSisOpCompras::UltimaCompraProducto(
			CQSisEmpresa *pCQSEExpendio,
			CQSisProducto *pCQSProducto,
			CQSisLstCompra *pCQSLCompra)
{
SiscomRegistrosPro2 *lSRegistrosPro2;

SPConsulta								<<
new SiscomParametroConsulta("UltimaCompraProducto")			<<
new SiscomParametroConsulta(pCQSProducto->SRegistrosPro2["IdProducto"])	<<
new SiscomParametroConsulta(pCQSEExpendio->SRegistrosPro2["IdEmpresa"])	;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);
FormaUltimaCompraProducto(lSRegistrosPro2,pCQSLCompra);
}
void CQSisOpCompras::FormaUltimaCompraProducto(
			SiscomRegistrosPro2 *pSRegistrosPro2,
			CQSisLstCompra *pCQSLCompra)
{
CQSisEmpresa *lCQSEProveedor;
for(;
    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
    ++(*pSRegistrosPro2))
 (*pCQSLCompra) << ObjetosTiendas4::Compra(pSRegistrosPro2);
}
void CQSisOpCompras::Compras(CQSisEmpresa *pCQSEExpendio,
			     const char *pchrPtrFechaIni,
			     const char *pchrPtrFechaFin,
			     CQSisLstCompra *pCQSLCompra)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(
		&SPConsulta,
		"%s%s%s%s",
		"ComprasRegistradas",
		(*pCQSEExpendio)["IdEmpresa"],
		pchrPtrFechaIni,
		pchrPtrFechaFin);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);
FormaUltimaCompraProducto(lSRegistrosPro2,pCQSLCompra);
}


void CQSisOpCompras::DetalleCompra(CQSisEmpresa *pCQSEExpendio,
			     CQSisCompra *pCQSCompra,
			     CQSisLstCompra *pCQSLCompra)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(
		&SPConsulta,
		"%s%s%s%s%s",
		"DetalleCompra",
		(*pCQSEExpendio)["IdEmpresa"],
		(*pCQSCompra)["IdCompra"],
		pCQSCompra->Contacto()->ObtenPersona()->SRegistrosPro2["IdPersona"],
		(*pCQSCompra->Proveedor())["IdEmpresa"]);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);
FormaUltimaCompraProducto(lSRegistrosPro2,pCQSLCompra);
}
