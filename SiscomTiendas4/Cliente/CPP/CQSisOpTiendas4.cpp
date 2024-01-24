#include <CQSisOpTiendas4.h>
#include <CQSisFamilias.h>
#include <CQSisProductos.h>
#include <CQSisPrecios.h>
#include <CQSisDatoPrecio.h>
#include <CQSisEmpresas.h>
#include <CQSisContactos.h>
#include <CQSisFormaPago.h>
#include <CQSisClientes.h>
#include <CQSisObjetosTiendas4.h>
#include <CQSisProdCotiza.h>
#include <CQSisOrdenes.h>
#include <CQSisEmpleados.h>

#include <SisMedioComunicacion.h>

CQSisOpTiendas4::CQSisOpTiendas4(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{
//	SPConsulta.setAutoDelete(true);
}
CQSisOpTiendas4::~CQSisOpTiendas4()
{
//	SPConsulta.clear();
}
void CQSisOpTiendas4::CalculaTotalADevolver(
		      CQSisLstProdCotiza *pCQSLPCotiza,
		      SiscomRegistrosPro2 **pSRegistrosPro2)
{
if(pCQSLPCotiza->count())
{
SiscomPonParametrosConsulta((SiscomInformacionLst *)pCQSLPCotiza);
SiscomActualiza2SubRegistros("TotalADevolver",pSRegistrosPro2);
}

}
void CQSisOpTiendas4::EjecutaDevolucion(
		      CQSisLstProdCotiza *pCQSLPCotiza,
		      SiscomRegistrosPro2 **pSRegistrosPro2)
{
if(pCQSLPCotiza->count())
{
SiscomPonParametrosConsulta((SiscomInformacionLst *)pCQSLPCotiza);
SiscomActualiza2SubRegistros("Devolucion",pSRegistrosPro2);
}

}
void CQSisOpTiendas4::Empleado(CQSisEmpleado *pCQSEmpleado,
			       SiscomRegistrosPro2 **pSRegistrosPro2)
{
CQSisLstEmpleado lCQSLEmpleado;
	lCQSLEmpleado<< pCQSEmpleado;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLEmpleado);
SiscomActualiza2SubRegistros("RegistraEmpleado",pSRegistrosPro2);
}
void CQSisOpTiendas4::Cliente(CQSisCliente *pCQSCliente,
			      SiscomRegistrosPro2 **pSRegistrosPro2)
{
CQSisLstCliente lCQSLCliente;
	lCQSLCliente << pCQSCliente;

SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLCliente);
SiscomActualiza2SubRegistros("RegistraClienteFisica",pSRegistrosPro2);

}
void CQSisOpTiendas4::AnexaFamilia(CQSisFamilia *pCQSFamilia)
{
CQSisLstFamilia lCQSLFamilia;
SiscomRegistrosPro2 *lSRegistrosPro2;
		lCQSLFamilia	<< pCQSFamilia;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLFamilia);
SiscomActualiza2SubRegistros("RegistraFamilia",&lSRegistrosPro2);
}
void CQSisOpTiendas4::AnexaPrecio(CQSisPrecio *pCQSPrecio)
{
CQSisLstPrecio lCQSLPrecio;
SiscomRegistrosPro2 *lSRegistrosPro2;
	lCQSLPrecio << pCQSPrecio;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLPrecio);
SiscomActualiza2SubRegistros("RegistraPrecio",&lSRegistrosPro2);
}
void CQSisOpTiendas4::ActualizaProducto(CQSisProducto *pCQSProducto)
{
CQSisLstProducto lCQSLProducto;
SiscomRegistrosPro2 *lSRegistrosPro2;
	lCQSLProducto << pCQSProducto;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLProducto);
SiscomActualiza2SubRegistros("ActualizaProducto",&lSRegistrosPro2);
}
void CQSisOpTiendas4::ActualizaPrecioProducto(
			CQSisProducto *pCQSProducto,
			CQSisDatoPrecio *pCQSDPrecio)
{
SiscomRegistrosPro2 *lSRegistrosPro2;

SPConsulta			<<
new SiscomParametroConsulta("ActualizaPrecioProducto")			<<
new SiscomParametroConsulta(pCQSProducto->SRegistrosPro2["IdProducto"])	<<
new SiscomParametroConsulta(pCQSDPrecio->ObtenPrecio()->SRegistrosPro2["IdPrecio"])	<<
new SiscomParametroConsulta(pCQSDPrecio->SRegistrosPro2["Valor"])			<<
new SiscomParametroConsulta((*pCQSDPrecio)["Cantidad"]);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);

}

void CQSisOpTiendas4::AnexaEmpresa(CQSisEmpresa *pCQSEmpresa)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisLstEmpresa lCQSLEmpresa;
	lCQSLEmpresa << pCQSEmpresa;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLEmpresa);
SiscomActualiza2SubRegistros("RegistraEmpresa",&lSRegistrosPro2);
}
void CQSisOpTiendas4::AnexaProducto(CQSisProducto *pCQSProducto)
{
CQSisLstProducto lCQSLProducto;
SiscomRegistrosPro2 *lSRegistrosPro2;
	lCQSLProducto << pCQSProducto;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLProducto);
SiscomActualiza2SubRegistros("RegistraProducto",&lSRegistrosPro2);
}


void CQSisOpTiendas4::Precios(CQSisLstPrecio *pCQSLPrecio)
{
SiscomRegistrosPro2 *lSRegistrosPro2;

	pCQSLPrecio->setAutoDelete(true);
	pCQSLPrecio->clear();
	SPConsulta		<<
	new SiscomParametroConsulta("Precios");
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);
	FormaPrecios(lSRegistrosPro2,pCQSLPrecio);
}
void CQSisOpTiendas4::Familias(CQSisLstFamilia *pCQSLFamilias)
{
SiscomRegistrosPro2 *lSRegistrosPro2;

	pCQSLFamilias->setAutoDelete(true);
	pCQSLFamilias->clear();

	SPConsulta		<<
	new SiscomParametroConsulta("Familias");
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);
	FormaFamilias(lSRegistrosPro2,pCQSLFamilias);
}
void CQSisOpTiendas4::Productos(CQSisLstProducto *pCQSLProducto)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
	pCQSLProducto->clear();
	SPConsulta		<<
	new SiscomParametroConsulta("Productos")	<<
	new SiscomParametroConsulta("Registrados");
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);
	FormaProductos(lSRegistrosPro2,pCQSLProducto);
}
void CQSisOpTiendas4::IniciaPrecios(SiscomRegistrosPro2 **pSRegistrosPro2)
{

	SPConsulta					<<
	new SiscomParametroConsulta("IniciaPrecios");
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaTiendas4",pSRegistrosPro2);

}
void CQSisOpTiendas4::PreciosProducto(
			CQSisProducto *pCQSProducto,
			CQSisLstDatoPrecio *pCQSLDPrecio)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
	pCQSLDPrecio->clear();
	SPConsulta			<<
	new SiscomParametroConsulta("PreciosProducto")	<<
	new SiscomParametroConsulta(pCQSProducto->SRegistrosPro2["IdProducto"]);
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);
	FormaPreciosProducto(lSRegistrosPro2,pCQSLDPrecio);	
}
void CQSisOpTiendas4::MediosComunicacion(SisLstMedCom *pSLMCom)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
pSLMCom->clear();

	SPConsulta			<<
	new SiscomParametroConsulta("Medios");

	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);
	FormaMedios(lSRegistrosPro2,pSLMCom);

}
void CQSisOpTiendas4::Proveedores(CQSisLstEmpresa *pCQSLEProveedores)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
		pCQSLEProveedores->clear();
		SPConsulta			<<
		new SiscomParametroConsulta("Proveedores");
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);
FormaEmpresas(lSRegistrosPro2,pCQSLEProveedores);
}
void CQSisOpTiendas4::ContactosProveedor(CQSisEmpresa *pCQSEmpresa,
				         CQSisLstContacto *pCQSLContacto)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
		pCQSLContacto->clear();
		SPConsulta.clear();
		SPConsulta						<<
		new SiscomParametroConsulta("ContactosProveedor")	<<
		new SiscomParametroConsulta(pCQSEmpresa->SRegistrosPro2["IdEmpresa"]);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);
FormaPersonas(lSRegistrosPro2,pCQSLContacto);

}
void CQSisOpTiendas4::ExistenciaProductos(CQSisLstProdCotiza *pCQSLPCotiza)
{
SiscomRegistrosPro2 *lSRegistrosPro2;

	SiscomArgumentosConsulta(&SPConsulta,
				 "%s",
				 "ExistenciaProductos"); 

	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	EliminaProductosCotiza(pCQSLPCotiza);
	SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);
	FormaProductoExistencia(lSRegistrosPro2,pCQSLPCotiza);
}
void CQSisOpTiendas4::FormaProductoExistencia(
			SiscomRegistrosPro2 *pSRegistrosPro2,
			CQSisLstProdCotiza *pCQSLPCotiza)
{
  for(;
       !pSRegistrosPro2->SiscomEsElUltimoRegistro();
       ++(*pSRegistrosPro2))
   (*pCQSLPCotiza)	<<  
      	new CQSisProdCotiza(ObjetosTiendas4::Producto(pSRegistrosPro2),
			    "",
			    "",
			    "",
			    (*pSRegistrosPro2)["existencia"],
			    (*pSRegistrosPro2)["existenciamin"]);
}
						
void CQSisOpTiendas4::FormaPago(CQSisLstFormaPago *pCQSLFPago)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
		pCQSLFPago->clear();
		SPConsulta.clear();
		SPConsulta						<<
		new SiscomParametroConsulta("FormaPago");
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);
FormaFormaPago(lSRegistrosPro2,pCQSLFPago);
}

void CQSisOpTiendas4::FormaFormaPago(SiscomRegistrosPro2 *pSRegistrosPro2,
				     CQSisLstFormaPago *pCQSLFPago)
{
	for(;
	    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	    ++(*pSRegistrosPro2))
	 (*pCQSLFPago)	<< FormaFormaPagoProtocolo(pSRegistrosPro2);
}
void CQSisOpTiendas4::Clientes(CQSisLstCliente *pCQSLCliente)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
	SiscomArgumentosConsulta(&SPConsulta,
				 "%s%s%s",
				 "ClientesRegistrados",
				 "Prueba",
				 "Prueba");
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);
	FormaClientes(lSRegistrosPro2,pCQSLCliente);

}
void CQSisOpTiendas4::Ordenes(CQSisEmpresa *pCQSExpendio,
			      const char *pchrPtrFechaIni,
			      const char *pchrPtrFechaFin,
			      const char *pchrPtrEdoVenta,
			      CQSisLstOrden *pCQSLOrden)
{
SiscomRegistrosPro2 *lSRegistrosPro2;

	SiscomArgumentosConsulta(&SPConsulta,
				 "%s%s%s%s%s",
				 "Ordenes",
				 pCQSExpendio->SRegistrosPro2["IdEmpresa"],
				 pchrPtrFechaIni,
				 pchrPtrFechaFin,
				 pchrPtrEdoVenta);

	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
	SiscomConsulta("ConsultaTiendas4",&lSRegistrosPro2);
	FormaOrden(lSRegistrosPro2,pCQSLOrden);

}
void CQSisOpTiendas4::FormaOrden(SiscomRegistrosPro2 *pSRegistrosPro2,
				 CQSisLstOrden *pCQSLOrden)
{
	for(;
	    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	    ++(*pSRegistrosPro2))
	 (*pCQSLOrden)	<< ObjetosTiendas4::Orden(pSRegistrosPro2);

}
void CQSisOpTiendas4::FormaClientes(SiscomRegistrosPro2 *pSRegistrosPro2,
				    CQSisLstCliente *pCQSLCliente)
{
	for(;
	    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	     ++(*pSRegistrosPro2))
	(*pCQSLCliente)	<< ObjetosTiendas4::Cliente(pSRegistrosPro2);

}
CQSisFormaPago *CQSisOpTiendas4::FormaFormaPagoProtocolo(SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new CQSisFormaPago((*pSRegistrosPro2)["idformapago"],
			  (*pSRegistrosPro2)["nombre"],
			  (*pSRegistrosPro2)["diassigpago"]);
}
void CQSisOpTiendas4::FormaPersonas(SiscomRegistrosPro2 *pSRegistrosPro2,
				    CQSisLstContacto *pCQSLContactos)
{
	for(;
	    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	    ++(*pSRegistrosPro2))
	 (*pCQSLContactos)	<< FormaPersonaProtocolo(pSRegistrosPro2);
}
CQSisContacto *CQSisOpTiendas4::FormaPersonaProtocolo(
			SiscomRegistrosPro2 *pSRegistrosPro2)
{
	return new CQSisContacto(new SisPersona((*pSRegistrosPro2)["nombre"],
			      (*pSRegistrosPro2)["apaterno"],
			      (*pSRegistrosPro2)["amaterno"],
			      (*pSRegistrosPro2)["idpersona"]),
			      0);
}
void CQSisOpTiendas4::FormaEmpresas(SiscomRegistrosPro2 *pSRegistrosPro2,
				    CQSisLstEmpresa *pCQSLEProveedores)
{
	for(;
	    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	    ++(*pSRegistrosPro2))
	  (*pCQSLEProveedores) << FormaEmpresaProtocolo(pSRegistrosPro2);
}
CQSisEmpresa *CQSisOpTiendas4::FormaEmpresaProtocolo(SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new CQSisEmpresa((*pSRegistrosPro2)["idempresa"],
			(*pSRegistrosPro2)["razonsocial"]);
}
void CQSisOpTiendas4::FormaMedios(SiscomRegistrosPro2 *pSRegistrosPro2,
				  SisLstMedCom *pSLMCom)
{
	for(;
	     !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	     ++(*pSRegistrosPro2))
	  (*pSLMCom) <<  FormaMedComProtocolo(pSRegistrosPro2);
}
SisMedCom *CQSisOpTiendas4::FormaMedComProtocolo(SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new SisMedCom((*pSRegistrosPro2)["idmedio"],
		     (*pSRegistrosPro2)["medio"],
		     "",
		     "");
}
void CQSisOpTiendas4::FormaPreciosProducto(
			SiscomRegistrosPro2 *pSRegistrosPro2,
			CQSisLstDatoPrecio *pCQSLDPrecio)
{
        for(;
	    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	    ++(*pSRegistrosPro2))
	(*pCQSLDPrecio)	<< new CQSisDatoPrecio(
				  FormaPrecioProtocolo(pSRegistrosPro2),
				  (*pSRegistrosPro2)["precio"],
				  (*pSRegistrosPro2)["cantidad"]);
}
void CQSisOpTiendas4::FormaPrecios(
			SiscomRegistrosPro2 *pSRegistrosPro2,
			CQSisLstPrecio *pCQSLPrecio)
{
	for(;
	    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	    ++(*pSRegistrosPro2))
	 (*pCQSLPrecio)	<< FormaPrecioProtocolo(pSRegistrosPro2);
}
void CQSisOpTiendas4::FormaProductos(
			SiscomRegistrosPro2 *pSRegistrosPro2,
			CQSisLstProducto *pCQSLProducto)
{
	for(;
	     !pSRegistrosPro2->SiscomEsElUltimoRegistro();
	     ++(*pSRegistrosPro2))
	 (*pCQSLProducto) << FormaProductoProtocolo(pSRegistrosPro2);
}

CQSisProducto *CQSisOpTiendas4::FormaProductoProtocolo(
				SiscomRegistrosPro2 *pSRegistrosPro2)
{

return new CQSisProducto(
		new CQSisFamilia(
			(*pSRegistrosPro2)["idfamilia"],
			(*pSRegistrosPro2)["familia"],
			(*pSRegistrosPro2)["dscfamilia"]),
			(*pSRegistrosPro2)["idproducto"],
			(*pSRegistrosPro2)["clave"],
			(*pSRegistrosPro2)["dscproducto"]);
}
CQSisPrecio *CQSisOpTiendas4::FormaPrecioProtocolo(
				SiscomRegistrosPro2 *pSRegistrosPro2)
{

	return new CQSisPrecio(
		    (*pSRegistrosPro2)["idprecio"],
		    (*pSRegistrosPro2)["nombre"],
		    (*pSRegistrosPro2)["dsc"]);

}
void CQSisOpTiendas4::FormaFamilias(SiscomRegistrosPro2 *pSRegistrosPro2,
				    CQSisLstFamilia *pCQSLFamilia)
{

for(;
     !pSRegistrosPro2->SiscomEsElUltimoRegistro();
     ++(*pSRegistrosPro2))
  (*pCQSLFamilia) << new CQSisFamilia(
  			   (*pSRegistrosPro2)["idfamilia"],
  			   (*pSRegistrosPro2)["familia"],
  			   (*pSRegistrosPro2)["dsc"]);
}


void CQSisOpTiendas4::EliminaProductosCotiza(CQSisLstProdCotiza *pCQSLPCotiza)
{
	pCQSLPCotiza->setAutoDelete(true);
	pCQSLPCotiza->clear();
	pCQSLPCotiza->setAutoDelete(false);
}
