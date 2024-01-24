#include <CQSisProdCotiza.h>
#include <CQSisProductos.h>
#include <CQSisPrecios.h>
#include <CQSisEmpleados.h>
#include <CQSisEmpresas.h>
#include <CQSisClientes.h>
#include <CQSisFormaPago.h>
#include <CQSisContactos.h>
CQSisProdCotiza::CQSisProdCotiza(CQSisProducto *pCQSProducto,
				 const char *pchrPtrCantidad,
				 const char *pchrPtrPrecio,
				 const char *pchrPtrImporte,
				 const char *pchrPtrExistencia,
				 const char *pchrPtrExiMinima):
			CQSProducto(pCQSProducto)
{
SRegistroPro2			<<
"Cantidad"			<<
"Precio"			<<
"Importe"			<<
"Existencia"			<<
"ExiMinima";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2 					<<
SiscomCampoPro2("Cantidad",pchrPtrCantidad)	<<
SiscomCampoPro2("Precio",pchrPtrPrecio)		<<
SiscomCampoPro2("Importe",pchrPtrImporte)	<<
SiscomCampoPro2("Existencia",pchrPtrExistencia)	<<
SiscomCampoPro2("ExiMinima",pchrPtrExiMinima);	
SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisProdCotiza::CQSisProdCotiza(CQSisProducto *pCQSProducto,
				 CQSisPrecio *pCQSPrecio,
				 CQSisFormaPago *pCQSFPago,
				 CQSisEmpresa *pCQSExpendio,
				 CQSisCliente *pCQSCliente,
				 CQSisContacto *pCQSContacto,
				 CQSisEmpleado *pCQSEmpleado,
				 const char *pchrPtrCantidad,
				 const char *pchrPtrExistencia,
				 const char *pchrPtrPrecio,
				 const char *pchrPtrTotal,
				 const char *pchrPtrSePuedeVender,
				 const char *pchrPtrIdVenta,
				 const char *pchrPtrEdoVenta):
			CQSProducto(pCQSProducto),
			CQSPrecio(pCQSPrecio),
			CQSFPago(pCQSFPago),
			CQSExpendio(pCQSExpendio),
			CQSCliente(pCQSCliente),
			CQSEmpleado(pCQSEmpleado),
			CQSContacto(pCQSContacto)
{
	SRegistroPro2		<<
	"IdProducto"		<<
	"Clave"			<<
	"IdPrecio"		<<
	"IdFormaPago"		<<
	"IdExpendio"		<<
	"IdCliente"		<<
	"TipoCliente"		<<
	"IdContacto"		<<
	"IdEmpleado"		<<
	"Cantidad"		<<
	"Existencia"		<<
	"Precio"		<<
	"Total"			<<
	"SePuedeVender"		<<
	"IdCotizacion"		<<
	"EdoVenta";
SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
SRegistrosPro2								<<
SiscomCampoPro2("IdProducto",
		CQSProducto->SRegistrosPro2["IdProducto"])		<<
SiscomCampoPro2("Clave",
		CQSProducto->SRegistrosPro2["Clave"])			<<
SiscomCampoPro2("IdPrecio",
		 CQSPrecio->SRegistrosPro2["IdPrecio"])			<<
SiscomCampoPro2("IdFormaPago",
		 CQSFPago->SRegistrosPro2["IdFormaPago"])		<<
SiscomCampoPro2("IdExpendio",
		 CQSExpendio->SRegistrosPro2["IdEmpresa"])		<<
SiscomCampoPro2("IdCliente",ObtenIdCliente())				<<
SiscomCampoPro2("TipoCliente",
		CQSCliente->SRegistrosPro2["TipoCliente"])		<<
SiscomCampoPro2("IdContacto",
		CQSContacto ? 
		CQSContacto->ObtenPersona()->SRegistrosPro2["IdPersona"] :
		"")							<<
SiscomCampoPro2("IdEmpleado",
		CQSEmpleado->SRegistrosPro2["IdPersona"])	<<
SiscomCampoPro2("Cantidad",pchrPtrCantidad)				<<
SiscomCampoPro2("Existencia",pchrPtrExistencia)				<<
SiscomCampoPro2("Precio",pchrPtrPrecio)					<<
SiscomCampoPro2("Total",pchrPtrTotal)					<<
SiscomCampoPro2("SePuedeVender",pchrPtrSePuedeVender)			<<
SiscomCampoPro2("IdCotizacion",pchrPtrIdVenta)				<<
SiscomCampoPro2("EdoVenta",pchrPtrEdoVenta);
SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisProdCotiza::CQSisProdCotiza(CQSisProducto *pCQSProducto,
				 CQSisEmpresa *pCQSExpendio,
				 const char *pchrPtrCantidad,
				 const char *pchrPtrPrecio,
				 const char *pchrPtrTotal,
				 const char *pchrPtrIdCotizacion):
			CQSProducto(pCQSProducto),
			CQSExpendio(pCQSExpendio)
{
	SRegistroPro2		<<
	"IdProducto"		<<
	"Cantidad"		<<
	"Precio"		<<
	"Total"			<<
	"IdCotizacion"		<<
	"IdExpendio"		<<
	"IdDevolucion";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2					<<
	SiscomCampoPro2("IdProducto",CQSProducto->SRegistrosPro2["IdProducto"])	<<
	SiscomCampoPro2("Cantidad",pchrPtrCantidad)	<<
	SiscomCampoPro2("Precio",pchrPtrPrecio)		<<
	SiscomCampoPro2("Total",pchrPtrTotal)		<<
	SiscomCampoPro2("IdCotizacion",pchrPtrIdCotizacion)	<<
	SiscomCampoPro2("IdExpendio",CQSExpendio->SRegistrosPro2["IdEmpresa"])	<<
	SiscomCampoPro2("IdDevolucion","");
	SRegistrosPro2.SiscomAnexaRegistro();
}

CQSisProdCotiza::~CQSisProdCotiza()
{
SiscomLog("");
}
const char *CQSisProdCotiza::ObtenIdCliente()
{
	if(!strcmp(CQSCliente->SRegistrosPro2["TipoCliente"],"Fisica"))
	return CQSCliente->Persona()->SRegistrosPro2["IdPersona"];
	if(!strcmp(CQSCliente->SRegistrosPro2["TipoCliente"],"Moral"))
	return CQSCliente->Empresa()->SRegistrosPro2["IdEmpresa"];
}
CQSisProducto *CQSisProdCotiza::Producto()
{
	return CQSProducto;
}
void CQSisProdCotiza::Precio(CQSisPrecio *pCQSPrecio)
{
	CQSPrecio=pCQSPrecio;
}
CQSisPrecio *CQSisProdCotiza::Precio()
{
	return CQSPrecio;
}
CQSisEmpresa *CQSisProdCotiza::Expendio()
{
	return CQSExpendio;
}
CQSisCliente *CQSisProdCotiza::Cliente()
{
	return CQSCliente;
}
CQSisEmpleado *CQSisProdCotiza::Empleado()
{
	return CQSEmpleado;
}
CQSisContacto *CQSisProdCotiza::Contacto()
{
	return CQSContacto;
}
CQSisFormaPago *CQSisProdCotiza::FormaPago()
{
	return CQSFPago;
}
CQSisLstProdCotiza::CQSisLstProdCotiza():
		chrPtrTotalOrden(0)
{
	//setAutoDelete(true);
}
CQSisLstProdCotiza::~CQSisLstProdCotiza()
{
	SiscomLog("");
	clear();
}
CQSisLstProdCotiza &CQSisLstProdCotiza::operator<<(CQSisProdCotiza *pCQSPCotiza)
{
	append(pCQSPCotiza);
	return *this;
}
void CQSisLstProdCotiza::PonTotalOrden(const char *pchrPtrTotalOrden)
{
	chrPtrTotalOrden=pchrPtrTotalOrden;
}
const char *CQSisLstProdCotiza::TotalOrden()
{
	return chrPtrTotalOrden;
}
void CQSisLstProdCotiza::EliminaProductos(QMemArray<int> pQMAProductos)
{
int lintContador;
int lintNFilas=pQMAProductos.count();
CQSisLstProdCotiza lCQSLPCotiza;
CQSisProdCotiza *lCQSPCotiza;
	for(lintContador=0;
	    lintContador<lintNFilas;
	    lintContador++)
	  lCQSLPCotiza << at(pQMAProductos[lintContador]);
	for(lCQSPCotiza=lCQSLPCotiza.first();
	    lCQSPCotiza;
	    lCQSPCotiza=lCQSLPCotiza.next())
	  remove(lCQSPCotiza);
}
CQSisOpCotiza::CQSisOpCotiza(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{

}
CQSisOpCotiza::~CQSisOpCotiza()
{
	SiscomLog("");
	SPConsulta.setAutoDelete(true);
	SPConsulta.clear();
}
void CQSisOpCotiza::CotizaProducto(CQSisProdCotiza *pCQSCProducto)
{
CQSisLstProdCotiza lCQSLPCotiza;
SiscomRegistrosPro2 *lSRegistrosPro2;

lCQSLPCotiza	<< pCQSCProducto;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLPCotiza);
SiscomActualiza2SubRegistros("CotizaProductos",&lSRegistrosPro2);
AsignaResultados(lSRegistrosPro2,pCQSCProducto);
}
void CQSisOpCotiza::CotizaProductos(CQSisLstProdCotiza *pCQSLPCotiza)
{
SiscomLog("");
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomPonParametrosConsulta((SiscomInformacionLst *)pCQSLPCotiza);
SiscomActualiza2SubRegistros("CotizaProductos",&lSRegistrosPro2);
SiscomLog("");
lSRegistrosPro2->SiscomImprimeContenido();
SiscomLog("");
AsignaResultados(lSRegistrosPro2,pCQSLPCotiza);
}
void CQSisOpCotiza::GeneraIdentificador(CQSisLstProdCotiza *pCQSLPCotiza)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomPonParametrosConsulta((SiscomInformacionLst *)pCQSLPCotiza);
SiscomActualiza2SubRegistros("IdentificadorCotizacion",&lSRegistrosPro2);
AsignaIdentificador(lSRegistrosPro2,pCQSLPCotiza);

}
void CQSisOpCotiza::AsignaIdentificador(
		SiscomRegistrosPro2 *pSRegistrosPro2,
		CQSisLstProdCotiza *pCQSLPCotiza)
{
CQSisProdCotiza *lCQSPCotiza;

for(lCQSPCotiza=pCQSLPCotiza->first();
    lCQSPCotiza;
    lCQSPCotiza=pCQSLPCotiza->next(),
    ++(*pSRegistrosPro2))
lCQSPCotiza->SRegistrosPro2.SiscomActualizaCampo(
			"IdCotizacion",
			(*pSRegistrosPro2)["IdCotizacion"]);
}
void CQSisOpCotiza::AsignaResultados(
		SiscomRegistrosPro2 *pSRegistrosPro2,
		CQSisLstProdCotiza *pCQSLPCotiza)
{
CQSisProdCotiza *lCQSPCotiza;

for(lCQSPCotiza=pCQSLPCotiza->first();
    lCQSPCotiza;
    lCQSPCotiza=pCQSLPCotiza->next(),
    ++(*pSRegistrosPro2))
{
lCQSPCotiza->SRegistrosPro2.SiscomActualizaCampo(
			"Existencia",
			(*pSRegistrosPro2)["Existencia"]);
lCQSPCotiza->SRegistrosPro2.SiscomActualizaCampo(
			"Precio",
			(*pSRegistrosPro2)["Precio"]);
lCQSPCotiza->SRegistrosPro2.SiscomActualizaCampo(
			"Total",
			(*pSRegistrosPro2)["Total"]);
lCQSPCotiza->SRegistrosPro2.SiscomActualizaCampo(
			"SePuedeVender",
			(*pSRegistrosPro2)["SePuedeVender"]);
/*
 *
 * Miercoles 23 Enero 2008
 *
 * Se modifico para la integracion con la funcionalidad
 * que permite al usuario capaturar el importe del 
 * producto, el sistema calcula la cantidad
 *
 */
lCQSPCotiza->SRegistrosPro2.SiscomActualizaCampo(
			"Cantidad",
			(*pSRegistrosPro2)["Cantidad"]);
}
pCQSLPCotiza->PonTotalOrden((*pSRegistrosPro2)["Total"]);

}
void CQSisOpCotiza::AsignaResultados(
		SiscomRegistrosPro2 *pSRegistrosPro2,
		CQSisProdCotiza *pCQSProducto)
{
pCQSProducto->SRegistrosPro2.SiscomColocaPrimerRegistro();
pCQSProducto->SRegistrosPro2.SiscomActualizaCampo(
			"Existencia",
			(*pSRegistrosPro2)["Existencia"]);
pCQSProducto->SRegistrosPro2.SiscomActualizaCampo(
			"Precio",
			(*pSRegistrosPro2)["Precio"]);
pCQSProducto->SRegistrosPro2.SiscomActualizaCampo(
			"Total",
			(*pSRegistrosPro2)["Total"]);
pCQSProducto->SRegistrosPro2.SiscomActualizaCampo(
			"SePuedeVender",
			(*pSRegistrosPro2)["SePuedeVender"]);
/*
 *
 * Miercoles 23 Enero 2008
 *
 * Se modifico para la integracion con la funcionalidad
 * que permite al usuario capaturar el importe del 
 * producto, el sistema calcula la cantidad
 *
 */
pCQSProducto->SRegistrosPro2.SiscomActualizaCampo(
			"Cantidad",
			(*pSRegistrosPro2)["Cantidad"]);
}
void CQSisOpCotiza::Elimina(CQSisLstProdCotiza *pCQSLPCotiza)
{
pCQSLPCotiza->setAutoDelete(true);
pCQSLPCotiza->clear();
pCQSLPCotiza->setAutoDelete(false);

}
