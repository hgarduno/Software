#include <zOperacionesServiSNTE.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomCampo.h>
#include <zSiscomDesarrollo4.h>
#include <zPersona.h>
#include <zDireccion.h>
#include <zEmpresa.h>

#include <zCamion.h>
#include <zDepartamento.h>

#include <zCosto.h>
#include <zCostos.h>
#include <zDescuentos.h>
#include <zProducto.h>
#include <zDescuento.h>
#include <zProductos.h>
#include <zOrden.h>
#include <zVenta.h>
#include <zCompra.h>
#include <zInventario.h>
#include <zTransferencia.h>
#include <zCreditosCliente.h>
#include <zTelefonos.h>
#include <zDatosGenerales.h>
#include <zEmpleo.h>
#include <zCargoPublico.h>
#include <zGeneralesBeneficios.h>
#include <zContratoBeneficios.h>
#include <zDatosComunicacion.h>
#include <zCorreo.h>
#include <zEmpresa.h>
#include <zReferenciasPersonales.h>
#include <zCentroTrabajo.h>
#include <zDatosComunicacion.h>
#include <zCliente.h>
#include <zVentas.h>
#include <zReciboApartado.h>
#include <zFolio.h>
#include <zUsuario.h>
#include <zCostoDescuento.h>
#include <zPrecio.h>
#include <zPreciosProducto.h>

#include <string.h>
zOperacionesServiSNTE::zOperacionesServiSNTE(zSiscomConexion *pzSisConexion,
				       const char *pchrPtrFuncion,
				       const char *pchrPtrModulo):
				       zSiscomOperaciones(pzSisConexion,
				       			  pchrPtrModulo,
							  pchrPtrFuncion)
{


}

zOperacionesServiSNTE::zOperacionesServiSNTE(zSiscomConexion *pzSisConexion,
				       const char *pchrPtrFuncion,
				       zSiscomRegistro *pzSisRegistroEnvio,
				       const char *pchrPtrModulo):
				       zSiscomOperaciones(pzSisConexion,
				       			  pchrPtrModulo,
							  pchrPtrFuncion,
							  pzSisRegistroEnvio)
{


}

void zOperacionesServiSNTE::EnviaArchivoNomina(const char *pchrPtrArchivo,
					       zSiscomEnviaArchivo *pzSiscomEnArcNomina)
{
   AgregaEnvio(zSiscomRegistro().Registro("%s [Archivo] ",pchrPtrArchivo));
   Enviando();
   pzSiscomEnArcNomina->Envia();

}

zSiscomRegistros *zOperacionesServiSNTE::ConceptosExistencias()
{
  return EnviaRecibe();  
}


zSiscomRegistros *zOperacionesServiSNTE::TiendasEntrega()
{
  return EnviaRecibe();  
}

zSiscomRegistros *zOperacionesServiSNTE::Vendedores(const char *pchrPtrTipoPersona)
{
    AgregaEnvio(zSiscomRegistro().Registro("%s [TipoPersona] ",
           pchrPtrTipoPersona));
    return EnviaRecibe();  
}

zSiscomRegistros *zOperacionesServiSNTE::PerfilesSS(const char *pchrPtrTipoPersona)
{
    AgregaEnvio(zSiscomRegistro().Registro("%s [TipoPersona] ",
           pchrPtrTipoPersona));
    return EnviaRecibe();  
}

zSiscomRegistros *zOperacionesServiSNTE::TipoDocumentos()
{
  return EnviaRecibe();  
}

zSiscomRegistros *zOperacionesServiSNTE::Estados()
{
  return EnviaRecibe();  
}

zSiscomRegistros *zOperacionesServiSNTE::TipoVentas()
{
  return EnviaRecibe();  
}

zSiscomRegistros *zOperacionesServiSNTE::FormasEntrega()
{
  return EnviaRecibe();  
}
zSiscomRegistros *zOperacionesServiSNTE::Financiadoras()
{
  return EnviaRecibe();  
}

zSiscomRegistros *zOperacionesServiSNTE::ProveedoresSS()
{
	
  return EnviaRecibe();  
}

zSiscomRegistros *zOperacionesServiSNTE::Plazos()
{
  return EnviaRecibe();  
}

zSiscomRegistros *zOperacionesServiSNTE::Camiones()
{
  return EnviaRecibe();  
}

zSiscomRegistros *zOperacionesServiSNTE::ReporteVentas(const char *pchrPtrRangoFechas,
						       zSiscomRegistro *pzSisRegTienda,
						       zSiscomRegistro *pzSisRegTipoVenta)
{
LogSiscom("%s",pchrPtrRangoFechas);
 AgregaEnvio(zSiscomRegistro().Registro("%s[RangoFechas] %s[IdTienda] %s[IdTipoVenta] ",
 					pchrPtrRangoFechas,
					(*pzSisRegTienda)["idtienda"],
					(*pzSisRegTipoVenta)["idtipoventa"]));
  return EnviaRecibe();  
}

zVentas *zOperacionesServiSNTE::Ventas(const char *pchrPtrRFC)
{
zSiscomRegistro *lzSisRegRegreso;
 AgregaEnvio(zSiscomRegistro().Registro("%s[RFC] ",pchrPtrRFC));
  if((lzSisRegRegreso=EnviaRecibe()->Primer()))
  {
    if(!lzSisRegRegreso->EstaElCampoEnElRegistro("EstadoConsulta"))
    {
  	SiscomRegistroLog2(lzSisRegRegreso);
  	return new zVentas(lzSisRegRegreso);
    }
    else
    return 0;
  }
  else
  return 0;
}


zSiscomRegistros *zOperacionesServiSNTE::ProductosSS(zSiscomRegistro *pzSisProveedor)
{
  AgregaEnvio(zSiscomRegistro().Registro("%s [IdProveedor] ",
  	      (*pzSisProveedor)["idempresa"]));
  return EnviaRecibe();  
}

zSiscomRegistros *zOperacionesServiSNTE::ProductosCodigoBarras(zSiscomRegistro *pzSisProveedor)
{
  AgregaEnvio(zSiscomRegistro().Registro("%s [IdProveedor] ",
  	      (*pzSisProveedor)["idempresa"]));
  return EnviaRecibe();  
}

zSiscomRegistros *zOperacionesServiSNTE::ProductosCodigoBarrasFechaCompra(const char *pchrPtrFecha)
{
  AgregaEnvio(zSiscomRegistro().Registro("%s [FechaCompra] ",
  	      pchrPtrFecha));
  return EnviaRecibe();  
}


zSiscomRegistros *zOperacionesServiSNTE::ProductosCodigoBarrasTodos()
{
/*
  AgregaEnvio(zSiscomRegistro().Registro("%s [FechaCompra] ",
  	      pchrPtrFecha));
 */
  return EnviaRecibe();  
}

zSiscomRegistro *zOperacionesServiSNTE::ProductoCodigoBarras(const char *pchrPtrCodigoBarras)
{
zSiscomRegistro *lzSiscomRegreso;
  AgregaEnvio(zSiscomRegistro().Registro("%s [CodigoBarras] ",
  	      pchrPtrCodigoBarras));

  if((lzSiscomRegreso=EnviaRecibe()->Primer()))
  {
	if((*lzSiscomRegreso)["EstadoConsulta"])
	return 0;
	else
	return lzSiscomRegreso;
  }
}
zSiscomRegistro *zOperacionesServiSNTE::ProductoProveedor(zSiscomRegistro *pzSiscomRegEmpresa,
							  const char *pchrPtrNumProducto)
{
zSiscomRegistro *lzSiscomRegRegreso;
  AgregaEnvio(zSiscomRegistro().Registro("%s [IdEmpresa] %s [NumProducto]",
  	      (*pzSiscomRegEmpresa)["idempresa"],
	      pchrPtrNumProducto));
  if((lzSiscomRegRegreso=EnviaRecibe()->Primer()))
  {
  	if(!lzSiscomRegRegreso->EstaElCampoEnElRegistro("EstadoConsulta"))
	return lzSiscomRegRegreso;
	else
	return 0;
  }
return 0;
}
zCliente *zOperacionesServiSNTE::ValidaRfcParaVenta(const char *pchrPtrRFC,
						      	   const char *pchrPtrIdTipoVenta)
{
zSiscomRegistro *lzSisRegCliente;
zCliente *lzCliente;
  AgregaEnvio(zSiscomRegistro().Registro("%s [RFC] %s [IdTipoVenta]",
  	      pchrPtrRFC,
	      pchrPtrIdTipoVenta));
  if((lzSisRegCliente=EnviaRecibe()->Primer()))
  {
       SiscomRegistroLog2(lzSisRegCliente);
       if(lzSisRegCliente->EstaElCampoEnElRegistro("IdMensaje"))
       return 0;
       else
       {
	lzCliente=new zCliente();
	lzCliente->ClientePorComprasRegistradas(lzSisRegCliente);
	return lzCliente;
	}
  }
  else
   return 0;
}

zSiscomRegistros *zOperacionesServiSNTE::DepartamentosSS()
{
  return EnviaRecibe();  
}

zSiscomRegistros *zOperacionesServiSNTE::SumaProductosCodigoBarras(zSiscomRegistros *pzProductos)
{
  AgregaEnvio(pzProductos);
  return EnviaRecibe();  
}

zSiscomRegistros *zOperacionesServiSNTE::DireccionesPersona(zPersona *pzPersona)
{
zSiscomRegistros *lzSisRegsDirecciones; 
  AgregaEnvio(zSiscomRegistro().Registro("%s [IdPersona]",(*pzPersona)["IdPersona"]));
  lzSisRegsDirecciones=EnviaRecibe();  
  //SiscomRegistrosLog(lzSisRegsDirecciones);
  return lzSisRegsDirecciones;
}

int zOperacionesServiSNTE::RegistraCliente(zPersona *pzPersona,
					   char **pchrPtrMensajeRegreso)
{
zSiscomRegistro *lzSiscomCliente,
		*lzSiscomResCliente;
zSiscomRegistros *lzSiscomRespuesta;
const char *lchrPtrMensaje;
  AgregaEnvio(pzPersona);
  if((lzSiscomRespuesta=EnviaRecibe()))
  {
      if((lzSiscomResCliente=lzSiscomRespuesta->Primer()))
      {
	if(lzSiscomResCliente->EstaElCampoEnElRegistro("SqlPersonaRegistrada"))
	{
	   lzSiscomCliente=lzSiscomResCliente->AsociadoDelCampo("SqlPersonaRegistrada");
	    SiscomRegistroLog2(lzSiscomCliente);
	    pzPersona->DesdePersonaRegistrada(lzSiscomCliente);
	    pzPersona->Direccion(lzSiscomCliente);
	    return 1;
	}
	else
	{
	  pzPersona->ActualizaCampo("IdPersona",(*lzSiscomResCliente)["IdPersona"]);
	  LogSiscom("El Id del cliente:%s",(const char *)(*lzSiscomResCliente)["IdPersona"]);
	  return 2;
	}

      }
  }
  
}
int zOperacionesServiSNTE::ActualizaRFC(const char *pchrPtrIdPersona,
					       const char *pchrPtrRFC)
{
zSiscomRegistros *lzSisRegsRegreso;
   AgregaEnvio(zSiscomRegistro().Registro("%s [IdPersona] %s [RFC]",
   					  pchrPtrIdPersona,
					  pchrPtrRFC));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {

   }
}
void zOperacionesServiSNTE::RegistraDireccion(zDireccion *pzDireccion)
{
zSiscomRegistros *lzSisRegsResp ;
zSiscomRegistro *lzSisRegreso;

  AgregaEnvio(pzDireccion);
  lzSisRegsResp=EnviaRecibe();
  lzSisRegreso=lzSisRegsResp->Primer();
  pzDireccion->ActualizaCampo("IdDireccion",(*lzSisRegreso)["IdDireccion"]);
}

void zOperacionesServiSNTE::ActualizaDireccion(zDireccion *pzDireccion)
{
zSiscomRegistros *lzSisRegsResp ;
zSiscomRegistro *lzSisRegreso;

  AgregaEnvio(pzDireccion);
  lzSisRegsResp=EnviaRecibe();
  lzSisRegreso=lzSisRegsResp->Primer();
}


void zOperacionesServiSNTE::RegistraCamion(zCamion *pzCamion)
{
  AgregaEnvio(pzCamion);
  Enviando();
}

void zOperacionesServiSNTE::RegistraDepartamento(zDepartamento *pzDepartamento)
{
  AgregaEnvio(pzDepartamento);
  Enviando();
}


void zOperacionesServiSNTE::CalculaCostoProveedor(zCosto *pzCosto,
					  zDescuento *pzDescuento)
{
zCostoDescuento *lzCostoDes=new zCostoDescuento(pzCosto,pzDescuento);
zSiscomRegistros *lzSisRegsRegreso;
AgregaEnvio(lzCostoDes);
if((lzSisRegsRegreso=EnviaRecibe()))
{
   pzCosto->CostoNeto((*lzSisRegsRegreso->Primer())["Costo"]);
}
}
void zOperacionesServiSNTE::CalculaPrecios(zPrecio *pzPrecio,
					   zPrecio *pzPrecioForaneo,
					   zCosto *pzCosto)
{
zPreciosProducto *lzPreciosP=new zPreciosProducto(pzPrecio,
						  pzPrecioForaneo,
						  pzCosto);
zSiscomRegistros *lzSisRegsRegreso;
AgregaEnvio(lzPreciosP);
if((lzSisRegsRegreso=EnviaRecibe()))
{
  SiscomRegistrosLog(lzSisRegsRegreso);
   pzPrecio->Precio((*lzSisRegsRegreso->Primer())["Precio"]);
   pzPrecioForaneo->Precio((*lzSisRegsRegreso->Primer())["PrecioForaneo"]);
}


}
int zOperacionesServiSNTE::CalculaPorcentajeGanancia(zCosto *pzCosto,
						     const char *pchrPtrPrecio,
						     char *pchrPtrCantidad)
{
zSiscomRegistros *lzSisRegsRegreso;
 AgregaEnvio(zSiscomRegistro().Registro("%s [CostoNeto] %s [Precio]",
 					(*pzCosto)["costoneto"],
					pchrPtrPrecio));
if((lzSisRegsRegreso=EnviaRecibe()))
{
  SiscomRegistrosLog(lzSisRegsRegreso);
  strcpy(pchrPtrCantidad,lzSisRegsRegreso->CampoRegistro(0,"Ganancia"));
}


}
void zOperacionesServiSNTE::RegistraPrecios(zProducto *pzProducto)
{
    AgregaEnvio(pzProducto);
    EnviaRecibe();
}
void zOperacionesServiSNTE::AgregaPrecios(zProducto *pzProducto)
{
    AgregaEnvio(pzProducto);
    EnviaRecibe();
}
zProducto *zOperacionesServiSNTE::CotizaProducto(const char *pchrPtrCantidad,
						 const char *pchrPtrCodigo)
{
zSiscomRegistros *lzSisRegsResp ;
zSiscomRegistro *lzSisRegreso;
  AgregaEnvio(zSiscomRegistro().Registro("%s [CodigoBarras] %s [Cantidad] ",pchrPtrCodigo,pchrPtrCantidad));
   lzSisRegsResp=EnviaRecibe();
   lzSisRegreso=lzSisRegsResp->Primer();
   if((*lzSisRegreso)["MensajeSistema"])
   return 0;
   else
   return new zProducto(lzSisRegreso);
}
void zOperacionesServiSNTE::CotizaOrden(zOrden *pzOrden)
{
zSiscomRegistro *lzSisRegCotiza;
zSiscomRegistros *lzSisRegsProductos;
zSiscomRegistros *lzSisRegsCredito;
AgregaEnvio(pzOrden);
lzSisRegCotiza=EnviaRecibe()->Primer();
pzOrden->ActualizaCampo("Total",(*lzSisRegCotiza)["Total"]);
pzOrden->ActualizaCampo("Iva",(*lzSisRegCotiza)["Iva"]);
pzOrden->ActualizaCampo("SubTotal",(*lzSisRegCotiza)["SubTotal"]);
lzSisRegsProductos=lzSisRegCotiza->AsociadosDelCampo("Productos");
lzSisRegsCredito=lzSisRegCotiza->AsociadosDelCampo("Credito");
pzOrden->ActualizaImporteProductos(lzSisRegsProductos);
if(lzSisRegsCredito)
pzOrden->Credito(lzSisRegsCredito->Primer());

}

void zOperacionesServiSNTE::RegistraVenta(zVenta *pzVenta)
{
zSiscomRegistro *lzSisRegCotiza;
   AgregaEnvio(pzVenta);
   lzSisRegCotiza=EnviaRecibe()->Primer();
   pzVenta->ActualizaCampo("Fecha",(*lzSisRegCotiza)["Fecha"]);
   pzVenta->ActualizaCampo("IdVenta",(*lzSisRegCotiza)["IdVenta"]);
   pzVenta->ActualizaCampo("Anio",(*lzSisRegCotiza)["Anio"]);
   pzVenta->ActualizaCampo("Mes",(*lzSisRegCotiza)["Mes"]);
   pzVenta->ActualizaCampo("Dia",(*lzSisRegCotiza)["Dia"]);
   pzVenta->TiendaVenta(lzSisRegCotiza->AsociadoDelCampo("Tienda"));
   SiscomRegistroLog2(lzSisRegCotiza->AsociadoDelCampo("Tienda"));
}
void zOperacionesServiSNTE::CalculaTotalCompra(zOrden *pzOrden)
{
zSiscomRegistro *lzSisRegCotiza;
   AgregaEnvio(pzOrden);
   lzSisRegCotiza=EnviaRecibe()->Primer();
   pzOrden->ActualizaCampo("Total",(*lzSisRegCotiza)["Total"]);
   pzOrden->ActualizaCampo("Iva",(*lzSisRegCotiza)["Iva"]);
   pzOrden->ActualizaCampo("SubTotal",(*lzSisRegCotiza)["SubTotal"]);
}
void zOperacionesServiSNTE::RegistraCompra(zCompra *pzCompra)
{
   AgregaEnvio(pzCompra);
   EnviaRecibe();
}

void zOperacionesServiSNTE::ProgramaInventario(zInventario *pzInventario)
{
    zSiscomRegistro *lzSisRegreso;
    AgregaEnvio(pzInventario);
    lzSisRegreso=EnviaRecibe()->Primer();
    pzInventario->ActualizaCampo("IdInventario",(*lzSisRegreso)["IdInventario"]);
}

void zOperacionesServiSNTE::PreRegistraInventario(zInventario *pzInventario)
{
   AgregaEnvio(pzInventario);
   EnviaRecibe();
}
void zOperacionesServiSNTE::RegistraInventario(zInventario *pzInventario)
{
   AgregaEnvio(pzInventario);
   EnviaRecibe();
}
void zOperacionesServiSNTE::ProgramaInventarioAlmacen(zInventario *pzInventario)
{
    zSiscomRegistro *lzSisRegreso;
    AgregaEnvio(pzInventario);
    lzSisRegreso=EnviaRecibe()->Primer();
    pzInventario->ActualizaCampo("IdInventario",(*lzSisRegreso)["IdInventario"]);
}
void zOperacionesServiSNTE::PreRegistraInventarioAlmacen(zInventario *pzInventario)
{
   AgregaEnvio(pzInventario);
   EnviaRecibe();
}
void zOperacionesServiSNTE::RegistraInventarioAlmacen(zInventario *pzInventario)
{
   AgregaEnvio(pzInventario);
   EnviaRecibe();
}
void zOperacionesServiSNTE::RegistraProducto(zProducto *pzProducto)
{
   AgregaEnvio(pzProducto);
   EnviaRecibe();
}
zSiscomRegistro *zOperacionesServiSNTE::TransfiereATienda(zTransferencia *pzTransferencia)
{
   AgregaEnvio(pzTransferencia);
   return EnviaRecibe()->Primer();
}
zSiscomRegistros *zOperacionesServiSNTE::ConsultaTransferencias()
{
    return EnviaRecibe();  
}
zSiscomRegistros *zOperacionesServiSNTE::ConsultaContenidoTransferencia(zSiscomRegistro *pzSisRegTransferencia)
{
    AgregaEnvio(pzSisRegTransferencia);
    return EnviaRecibe();  
}
zSiscomRegistros *zOperacionesServiSNTE::DetalleTransferencia(const char *pchrPtrIdTransferencia)
{
    AgregaEnvio(zSiscomRegistro().Registro("%s [idtransferencia]",pchrPtrIdTransferencia));
    return EnviaRecibe();  
}

int zOperacionesServiSNTE::ApartadosCliente(const char *pchrPtrFolioApartado,
					    zSiscomRegistro **pzSisRegTienda,
					    zSiscomRegistro **pzSisRegPersona,
					    zSiscomRegistros **pzSisRegsApartados,
					    char **pchrPtrFechaHoy)
{
zSiscomRegistros *lzSisRegsApartados; 
zSiscomRegistros *lzSisRegsPersonas;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [FolioApartado]",pchrPtrFolioApartado));
if((lzSisRegsApartados=EnviaRecibe()))
{
LogSiscom("Si hay apartados");
    lzSisRegRegreso=lzSisRegsApartados->Primer();
    if(lzSisRegRegreso->EstaElCampoEnElRegistro("Tienda"))
    {
    if(lzSisRegRegreso->EstaElCampoEnElRegistro("Persona"))
    {
       LogSiscom("Si esta el cliente");
    	if((lzSisRegsPersonas=lzSisRegRegreso->AsociadosDelCampo("Persona")))
	{
     	*pzSisRegPersona=lzSisRegsPersonas->Primer();
    	
    	  if(lzSisRegRegreso->EstaElCampoEnElRegistro("Apartados"))
     	   *pzSisRegsApartados=lzSisRegsApartados->Primer()->AsociadosDelCampo("Apartados");
          else
          return 1; 
	  *pzSisRegTienda=lzSisRegRegreso->AsociadosDelCampo("Tienda")->Primer();
	  *pchrPtrFechaHoy=(char *)(*lzSisRegRegreso)["FechaHoy"];
        }
       else
       return 0;
    }
    else
    return 0;
 }
  else
  return -1;
}
  return 2;
}
void zOperacionesServiSNTE::AbonoAApartado(zSiscomRegistro *pzSisRegVenta,
					   zReciboApartado *pzReciboApartado)
{
AgregaEnvio(zSiscomRegistro().Registro("%s [IdVenta] %s [MontoAbono] %s [Folio] ",
				 	(const char *)(*pzSisRegVenta)["idventa"],
					(const char *)(*pzReciboApartado)["Importe"],
					(const char *)(*pzReciboApartado)["FolioApartado"]));

 EnviaRecibe();
}

void  zOperacionesServiSNTE::FijaFechaCompra(zSiscomRegistro *pzSisProveedor,
					     const char *pchrPtrFechaAFijar)
{
AgregaEnvio(zSiscomRegistro().Registro("%s [IdProveedor] %s [FechaCompra] ",
				 	(const char *)(*pzSisProveedor)["idempresa"],
					pchrPtrFechaAFijar));
 EnviaRecibe();


}
int zOperacionesServiSNTE::FechaCompraProveedor(zSiscomRegistro *pzSisProveedor,
					       char *pchrPtrFechaCompra)
{
zSiscomRegistros *lzSisRegsRegreso;
  AgregaEnvio(zSiscomRegistro().Registro("%s [IdProveedor] ",
  	      				 (*pzSisProveedor)["idempresa"]));
  if((lzSisRegsRegreso=EnviaRecibe()))
  {  
     zSiscomRegistro *lzSisRegistro=lzSisRegsRegreso->Primer();
     const unsigned char *lchrPtrFecha=(*lzSisRegistro)["fechacompra"];
     if(lchrPtrFecha)
     {
     strcpy(pchrPtrFechaCompra,(const char *)(*lzSisRegistro)["fechacompra"]);
     return 1;
     }
     else
     return 0;
  }
  else
  return 0;
}
void zOperacionesServiSNTE::ActualizaEstadoTransferencia(const char *pchrPtrIdTransferencia,
							 const char *pchrPtrIdEstado,
							 const char *pchrPtrIdTiendaEntrega)
{
    AgregaEnvio(zSiscomRegistro().Registro("%s [IdTransferencia] %s [IdEstado] %s [IdTienda]",
          pchrPtrIdTransferencia,
          pchrPtrIdEstado,
	  pchrPtrIdTiendaEntrega));
    EnviaRecibe();
}


void zOperacionesServiSNTE::RecibeTransferencia(zSiscomRegistros *pzSisRegsTransferencia)
{
    AgregaEnvio(pzSisRegsTransferencia);
    EnviaRecibe();
}

void zOperacionesServiSNTE::RecibeTransferenciaParcial(zSiscomRegistros *pzProductosRecibidos, zSiscomRegistros *pzProductosDevueltos)
{
    /*zSiscomRegistro *lzSiscomRegistro = new zSiscomRegistro;
    lzSiscomRegistro <<
        new zSiscomCampo("ProductosRecibidos") <<
        new zSiscomCampo("ProductosDevueltos");

    AgregaEnvio(lzSiscomRegistro);
*/
    AgregaEnvio(zSiscomRegistro().Registro("%a [ProductosRecibidos] %a [ProductosDevueltos]",
          pzProductosRecibidos,
          pzProductosDevueltos));
    EnviaRecibe();  
}

zSiscomRegistro *zOperacionesServiSNTE::VerificarInventarioEnCurso()
{ 
    zSiscomRegistro *lzSiscomRegreso;
    if((lzSiscomRegreso=EnviaRecibe()->Primer()))
    {
	    if((*lzSiscomRegreso)["EstadoConsulta"])
	        return 0;
	    else
	        return lzSiscomRegreso;
    }
}

void zOperacionesServiSNTE::CancelaCapturaInventario(const char *pchrPtrIdInventario)
{
    AgregaEnvio(zSiscomRegistro().Registro("%s [IdInventario] %s [IdMotivoInventario]",
        pchrPtrIdInventario,
        "2"));
    EnviaRecibe();  
}

zSiscomRegistros *zOperacionesServiSNTE::RecuperaInventario(const char *pchrPtrIdInventario)
{
    AgregaEnvio(zSiscomRegistro().Registro("%s [IdInventario] ",
          pchrPtrIdInventario));
    return EnviaRecibe();  
}

zSiscomRegistros *zOperacionesServiSNTE::RecuperaInventarioAlmacen(const char *pchrPtrIdInventario)
{
    AgregaEnvio(zSiscomRegistro().Registro("%s [IdInventario] ",
          pchrPtrIdInventario));
    return EnviaRecibe();  
}

zCreditosCliente *zOperacionesServiSNTE::CreditosCliente(const char *pchrPtrRFC)
{
zSiscomRegistro *lzSisRegRegreso;
zSiscomRegistros *lzSisRegsRegreso;
     AgregaEnvio(zSiscomRegistro().Registro("%s [RFC]",pchrPtrRFC));
     lzSisRegsRegreso=EnviaRecibe();
     lzSisRegRegreso=(*lzSisRegsRegreso)[0];
     if(lzSisRegRegreso->EstaElCampoEnElRegistro("EstadoConsulta"))
     {
	  LogSiscom("No hay informacion para el RFC");
	  return 0;
     }
     else
     {
	return new zCreditosCliente(lzSisRegsRegreso);
     }
}

zSiscomRegistros *zOperacionesServiSNTE::TipoViviendaSS()
{
	return EnviaRecibe();
}

zSiscomRegistros *zOperacionesServiSNTE::FrecuenciaPagosSS()
{
	return EnviaRecibe();      
}

zSiscomRegistros *zOperacionesServiSNTE::FrecuenciaTransaccionalSS()
{
     return EnviaRecibe();
}

zSiscomRegistros *zOperacionesServiSNTE::ConsultaAbonosVenta(const char *pchrPtrIdVenta)
{
    AgregaEnvio(zSiscomRegistro().Registro("%s [IdVenta] ",
          pchrPtrIdVenta));
    return EnviaRecibe();  
}

void zOperacionesServiSNTE::CancelaAApartado(zSiscomRegistro *pzSisRegAbono)
{
    AgregaEnvio(zSiscomRegistro().Registro("%s [IdVenta] %s [Fecha] %s [MontoAbono]",
				 	(const char *)(*pzSisRegAbono)["idventa"],
				 	(const char *)(*pzSisRegAbono)["fecha"],
				 	(const char *)(*pzSisRegAbono)["monto"]));
    EnviaRecibe();
}

void zOperacionesServiSNTE::CancelaApartado(zSiscomRegistro *pzSisRegApartado)
{
    AgregaEnvio(zSiscomRegistro().Registro("%s [IdVenta]",
				 	(const char *)(*pzSisRegApartado)["idventa"]));
    EnviaRecibe();
}

int zOperacionesServiSNTE::PreciosDescuentosProducto(zSiscomRegistro *pzSisRegProducto,
						     zCostos *pzCostosBruto,
						     zCostos *pzCostosGeneral,
						     zCostos *pzCostosForaneo,
						     zDescuentos *pzDescuentos)
{
    zSiscomRegistros *lzSisRegRespuesta;
    zSiscomRegistro *lzSisRegistro;
    AgregaEnvio(zSiscomRegistro().Registro("%s [IdProducto]",(*pzSisRegProducto)["idproducto"]));
    if((lzSisRegRespuesta=EnviaRecibe()))
    {
        //SiscomRegistrosLog(lzSisRegRespuesta);
     lzSisRegistro=lzSisRegRespuesta->Primer();
     if(lzSisRegistro->EstaElCampoEnElRegistro("CostoBruto") &&
        lzSisRegistro->EstaElCampoEnElRegistro("PreciosGeneral") &&
	lzSisRegistro->EstaElCampoEnElRegistro("PreciosForaneos"))
     {
     *(zSiscomRegistros *)pzCostosBruto=*lzSisRegistro->AsociadosDelCampo("CostoBruto");
     *(zSiscomRegistros *)pzCostosGeneral=*lzSisRegistro->AsociadosDelCampo("PreciosGeneral");
     *(zSiscomRegistros *)pzCostosForaneo=*lzSisRegistro->AsociadosDelCampo("PreciosForaneos");
     *(zSiscomRegistros *)pzDescuentos=*lzSisRegistro->AsociadosDelCampo("Descuentos");
     return 1;
     }
     else
      return 0;
    }
    else
    return 0;
}

void zOperacionesServiSNTE::ValidaLiquidacionApartado(zSiscomRegistro *pzSisRegApartado)
{
    AgregaEnvio(zSiscomRegistro().Registro("%s [IdVenta]",
				 	(const char *)(*pzSisRegApartado)["idventa"]));
    EnviaRecibe();
}

zSiscomRegistro *zOperacionesServiSNTE::RegistraContratoBeneficios(zContratoBeneficios *pzContBeneficios)
{
   //AgregaEnvio(pzContBeneficios);
   return EnviaRecibe()->Primer();
}

int zOperacionesServiSNTE::RegistraTelefonos(zTelefonos *pzTelefonos)
{
zSiscomRegistros *lzSisRegsRespuesta;
   AgregaEnvio(pzTelefonos);
   if((lzSisRegsRespuesta=EnviaRecibe()))
   return lzSisRegsRespuesta->CampoRegistroInt(0,"EdoRegistro")==0;
   else
   return 0;
}

int zOperacionesServiSNTE::RegistraGenerales(zDatosGenerales *pzDatGenerales)
{
zSiscomRegistros *lzSisRegsRespuesta;
   AgregaEnvio(pzDatGenerales);
   if((lzSisRegsRespuesta=EnviaRecibe()))
   return lzSisRegsRespuesta->CampoRegistroInt(0,"EdoRegistro")==0;
   else
   return 0;
}
/*
int zOperacionesServiSNTE::ActualizaGenerales(zDatosGenerales *pzDatGenerales)
{
zSiscomRegistros *lzSisRegsRespuesta;
   AgregaEnvio(pzDatGenerales);
   if((lzSisRegsRespuesta=EnviaRecibe()))
   return lzSisRegsRespuesta->CampoRegistroInt(0,"EdoRegistro")==0;
   else
   return 0;
}

int zOperacionesServiSNTE::ActualizaDatosComunicacion(zDatosComunicacion *pzDatComunicacion)
{
zSiscomRegistros *lzSisRegsRespuesta;
   AgregaEnvio(pzDatComunicacion);
   if((lzSisRegsRespuesta=EnviaRecibe()))
   return lzSisRegsRespuesta->CampoRegistroInt(0,"EdoRegistro")==0;
   else
   return 0;
}

*/
int zOperacionesServiSNTE::RegistraEmpleo(zEmpleo *pzEmpleo)
{
zSiscomRegistros *lzSisRegsRespuesta;
   AgregaEnvio(pzEmpleo);
   if((lzSisRegsRespuesta=EnviaRecibe()))
   return lzSisRegsRespuesta->CampoRegistroInt(0,"EdoRegistro")==0;
   else
   return 0;
}
int zOperacionesServiSNTE::RegistraDatosCasa(const char *pchrPtrIdDireccion,
					     const char *pchrPtrIdTipoVivienda,
					     const char *pchrPtrTiempoResidir)
{
zSiscomRegistros *lzSisRegsRespuesta;
  AgregaEnvio(zSiscomRegistro().Registro("%s [IdDireccion] %s [IdTipoVivienda] %s [TiempoResidir]",
  					 pchrPtrIdDireccion,
					 pchrPtrIdTipoVivienda,
				 	 pchrPtrTiempoResidir));
   if((lzSisRegsRespuesta=EnviaRecibe()))
   return lzSisRegsRespuesta->CampoRegistroInt(0,"EdoRegistro")==0;
   else
   return 0;
}



int zOperacionesServiSNTE::RegistraCargoPublico(zCargoPublico *pzCargoPublico)
{
zSiscomRegistros *lzSisRegsRespuesta;
   AgregaEnvio(pzCargoPublico);
   if((lzSisRegsRespuesta=EnviaRecibe()))
   return lzSisRegsRespuesta->CampoRegistroInt(0,"EdoRegistro")==0;
   else
   return 0;
}


int zOperacionesServiSNTE::RegistraGeneralesBeneficios(zGeneralesBeneficios *pzGenBeneficios)
{
zSiscomRegistros *lzSisRegsRespuesta;
   AgregaEnvio(pzGenBeneficios);
   if((lzSisRegsRespuesta=EnviaRecibe()))
   return lzSisRegsRespuesta->CampoRegistroInt(0,"EdoRegistro")==0;
   else
   return 0;
}

int zOperacionesServiSNTE::RegistraReferenciasPersonales(zReferenciasPersonales *pzRefsPersonales)
{
zSiscomRegistros *lzSisRegsRespuesta;
   AgregaEnvio(pzRefsPersonales);
   if((lzSisRegsRespuesta=EnviaRecibe()))
   return lzSisRegsRespuesta->CampoRegistroInt(0,"EdoRegistro")==0;
   else
   return 0;
}


int zOperacionesServiSNTE::RegistraCentroTrabajo(zCentroTrabajo *pzCentroTrabajo)
{
zSiscomRegistros *lzSisRegsRespuesta;
   AgregaEnvio(pzCentroTrabajo);
   if((lzSisRegsRespuesta=EnviaRecibe()))
   return lzSisRegsRespuesta->CampoRegistroInt(0,"EdoRegistro")==0;
   else
   return 0;
}
void zOperacionesServiSNTE::AgregaGeneralesContrato(zSiscomRegistro *pzSisRegDatos,
						    zContratoBeneficios *pzConBeneficios)
{
zSiscomRegistro *lzSisRegGenerales=pzSisRegDatos->AsociadoDelCampo("GeneralesContrato");
if(lzSisRegGenerales)
 pzConBeneficios->GeneralesContrato(new zGeneralesBeneficios(lzSisRegGenerales));
else
LogSiscom("NO Se encontro el campo \"GeneralesContrato\"");
}
void zOperacionesServiSNTE::AgregaGeneralesBeneficios(zSiscomRegistro *pzSisRegDatos,
						      zContratoBeneficios *pzConBeneficios)
{
zSiscomRegistro *lzSisRegGenerales=pzSisRegDatos->AsociadoDelCampo("DatosNacimiento");
zSiscomRegistro *lzSisRegIdentificacion=pzSisRegDatos->AsociadoDelCampo("Identificacion");
zDatosGenerales *lzDatGenerales=0;
if(lzSisRegGenerales &&
   lzSisRegIdentificacion)
{
 lzDatGenerales=new zDatosGenerales(lzSisRegGenerales);
 lzDatGenerales->Identificacion((const char *)(*lzSisRegIdentificacion)["identificacion"]);
 lzDatGenerales->NoIdentificacion((const char *)(*lzSisRegIdentificacion)["noidentificacion"]);
 pzConBeneficios->Generales(lzDatGenerales);
 }
 else
 LogSiscom("No se encontraron los campos \"DatosNacimiento\" y \"Identificacion\"");
 
}
void zOperacionesServiSNTE::AgregaDatosCasa(zSiscomRegistro *pzSisRegDatos,
					    zContratoBeneficios *pzConBeneficios)
{
zSiscomRegistro *lzSisRegGenerales=pzSisRegDatos->AsociadoDelCampo("DatosCasa");
if(lzSisRegGenerales)
{
zSiscomRegistro *lzSisRegTipoVivienda=new zSiscomRegistro;
(*lzSisRegTipoVivienda) << 
new zSiscomCampo("idtipovivienda",(*lzSisRegGenerales)["idtipovivienda"]) <<
new zSiscomCampo("nombre",(*lzSisRegGenerales)["nombre"]);
 pzConBeneficios->TipoVivienda(lzSisRegTipoVivienda);
  pzConBeneficios->TiempoResidir((const char *)(*lzSisRegGenerales)["tiemporesidir"]);
}
else
LogSiscom("No Se encontro el campo \"DatosCasa\"");

}
void zOperacionesServiSNTE::AgregaDatosComunicacion(zSiscomRegistro *pzSisRegDatos,
						    zContratoBeneficios *pzConBeneficios)
{
zSiscomRegistros *lzSisRegsTelefonos=pzSisRegDatos->AsociadosDelCampo("TelefonosCliente");
zSiscomRegistro *lzSisRegCorreo=pzSisRegDatos->AsociadoDelCampo("CorreosCliente");
if(lzSisRegsTelefonos &&
   lzSisRegCorreo)
{
zDatosComunicacion *lzDatComunicacion=new zDatosComunicacion(lzSisRegsTelefonos); 
zCorreo *lzCorreo=new zCorreo(lzSisRegCorreo);
/*
 SiscomRegistroLog2(lzCorreo);
 SiscomRegistrosLog(lzSisRegsTelefonos); 
 */
lzDatComunicacion->Correo(lzCorreo);
pzConBeneficios->Comunicacion(lzDatComunicacion);
}
else
LogSiscom("No se encontraron los campos \"TelefonosCliente\" y \"CorreosCliente\"");
}
void zOperacionesServiSNTE::AgregaDatosEmpleo(zSiscomRegistro *pzSisRegDatos,
					      zContratoBeneficios *pzConBeneficios)
{
zSiscomRegistro *lzSisRegEmpleo=pzSisRegDatos->AsociadoDelCampo("Empleo");
if(lzSisRegEmpleo)
{
zEmpresa *lzEmpresa=zEmpresa().DesdeDatosEmpleo(lzSisRegEmpleo);
zEmpleo *lzEmpleo=new zEmpleo(lzSisRegEmpleo);
SiscomRegistroLog2(lzSisRegEmpleo);
lzEmpleo->Empresa(lzEmpresa);
pzConBeneficios->Empleo(lzEmpleo);
}
else
LogSiscom("NO se encontro el campo \"Empleo\"");

}
void zOperacionesServiSNTE::AgregaReferenciasPersonales(zSiscomRegistro *pzSisRegDatos,
							zContratoBeneficios *pzConBeneficios)
{
zSiscomRegistros *lzSisRegsReferencias=pzSisRegDatos->AsociadosDelCampo("ReferenciasPersonales");
if(lzSisRegsReferencias)
{
//SiscomRegistrosLog(lzSisRegsReferencias);
zReferenciasPersonales *lzRefsPersonales=new zReferenciasPersonales(lzSisRegsReferencias);
pzConBeneficios->ReferenciasPersonales(lzRefsPersonales);
}
else
LogSiscom("NO Se encontraron Referencias Personales");
}

void zOperacionesServiSNTE::AgregaCentroTrabajo(zSiscomRegistro *pzSisRegDatos,
							zContratoBeneficios *pzConBeneficios)
{
zSiscomRegistros *lzSisRegsCentroTrabajo=pzSisRegDatos->AsociadosDelCampo("CentroTrabajo");
if(lzSisRegsCentroTrabajo)
{
zSiscomRegistro *lzSisRegCentroTrabajo=lzSisRegsCentroTrabajo->Primer();
//SiscomRegistrosLog(lzSisRegsCentroTrabajo);
zCentroTrabajo *lzCentroTrabajo=new zCentroTrabajo(lzSisRegCentroTrabajo);
pzConBeneficios->CentroTrabajo(lzCentroTrabajo);
}
}

int zOperacionesServiSNTE::CompletaContratoBeneficiosIntegrales(zContratoBeneficios *pzConBeneficios)
{
zSiscomRegistros *lzSisRegsRespuesta;
zSiscomRegistro  *lzSisRegRespuesta;
   AgregaEnvio(zSiscomRegistro().Registro("%s [IdVenta] %s [IdDireccion] %s [IdCliente] ",
   					  pzConBeneficios->IdVenta(),
					  (*pzConBeneficios->DireccionParticular())["IdDireccion"],
					  pzConBeneficios->IdCliente()));
   if((lzSisRegsRespuesta=EnviaRecibe()))
   { 
      lzSisRegRespuesta=(*lzSisRegsRespuesta)[0];
      AgregaGeneralesContrato(lzSisRegRespuesta,pzConBeneficios);
      AgregaGeneralesBeneficios(lzSisRegRespuesta,pzConBeneficios);
      AgregaDatosCasa(lzSisRegRespuesta,pzConBeneficios);
      AgregaDatosComunicacion(lzSisRegRespuesta,pzConBeneficios);
      AgregaDatosEmpleo(lzSisRegRespuesta,pzConBeneficios);
      AgregaReferenciasPersonales(lzSisRegRespuesta,pzConBeneficios);
      AgregaCentroTrabajo(lzSisRegRespuesta,pzConBeneficios);
   }
}
zPersona *zOperacionesServiSNTE::PersonaRegistrada(const char *pchrPtrNombre,
						   const char *pchrPtrAPaterno,
						   const char *pchrPtrAMaterno)
{
zSiscomRegistros *lzSisRegsRespuesta;
zSiscomRegistro *lzSisRegPersona;
zPersona *lzPersona;
  AgregaEnvio(zSiscomRegistro().Registro("%s [Nombre] %s [APaterno] %s[AMaterno]",
  	      pchrPtrNombre,
	      pchrPtrAPaterno,
	      pchrPtrAMaterno));
   if((lzSisRegsRespuesta=EnviaRecibe()))
   {
       if((lzSisRegPersona=lzSisRegsRespuesta->Primer()))
       {
       	   //SiscomRegistroLog2(lzSisRegPersona);
	   if(lzSisRegPersona->EsElValorCampo("EdoRegistro","Si"))
	   {
	       lzPersona=new zPersona(lzSisRegPersona);
	       lzPersona->Direccion(lzSisRegPersona);
	       lzPersona->Telefonos(lzSisRegPersona);
	   return lzPersona;
	   }
	   else
	   return 0;
       }
       else
       return 0;
   }
   else
   return 0;

}

zEmpresa *zOperacionesServiSNTE::EmpresaRegistrada(const char *pchrPtrRazonSocial)
{
zSiscomRegistros *lzSisRegsRespuesta;
zSiscomRegistro *lzSisRegPersona;
zEmpresa *lzEmpresa;
  AgregaEnvio(zSiscomRegistro().Registro("%s [RazonSocial] ",
	      pchrPtrRazonSocial));
   if((lzSisRegsRespuesta=EnviaRecibe()))
   {
       if((lzSisRegPersona=lzSisRegsRespuesta->Primer()))
       {
           //SiscomRegistroLog2(lzSisRegPersona);	
	   if(lzSisRegPersona->EsElValorCampo("EdoRegistro","Si"))
	   {
		lzEmpresa=zEmpresa().DesdeDatosEmpleo(lzSisRegPersona);
		lzEmpresa->EdoRegistro("Si");
		return lzEmpresa;
	   }
	   else
	   return 0;
       }
       else
       {
       return 0;
       }
   }
   else
   {
   return 0;
   }

}

zSiscomRegistro *zOperacionesServiSNTE::CreditosBeneficiosIntegrales()
{
zSiscomRegistros *lzSisRegsCreditos;
zSiscomRegistro *lzSisRegCreditos;
   AgregaEnvio(zSiscomRegistro().Registro("%s [FechaInicio] %s [FechaFin]",
   				           "",
					   ""));
   if((lzSisRegsCreditos=EnviaRecibe()))
   {
     	lzSisRegCreditos=(*lzSisRegsCreditos)[0];
	return lzSisRegCreditos;
   }
   else
   return 0;
}

zSiscomRegistros *zOperacionesServiSNTE::ExistenciasTienda(zSiscomRegistro *pzSisRegTienda)
{
zSiscomRegistros *lzSisRegsExistencias;
    AgregaEnvio(zSiscomRegistro().Registro("%s [IdTienda]",(*pzSisRegTienda)["idtienda"]));
    if((lzSisRegsExistencias=EnviaRecibe()))
    {
	return lzSisRegsExistencias;
    }
    else
    return 0;
}

zSiscomRegistros *zOperacionesServiSNTE::ExistenciaTiendaProducto(zSiscomRegistro *pzSisRegTienda,
								  zSiscomRegistro *pzSisRegProducto)
{
const char *lchrPtrIdTienda;
zSiscomRegistro *lzSisRegEnvio=new zSiscomRegistro;
zSiscomRegistros *lzSisRegsExistencias;
lchrPtrIdTienda= pzSisRegTienda ? (const char *)(*pzSisRegTienda)["idtienda"] : 0;
(*lzSisRegEnvio) << 
	new zSiscomCampo("IdTienda",(const unsigned char *)lchrPtrIdTienda)  <<
	new zSiscomCampo("idproducto",(*pzSisRegProducto)["idproducto"]);
	
    AgregaEnvio(lzSisRegEnvio);
    if((lzSisRegsExistencias=EnviaRecibe()))
	 return lzSisRegsExistencias;
     else
     return 0;
}

zSiscomRegistros *zOperacionesServiSNTE::ExistenciasAlmacen()
{
zSiscomRegistros *lzSisRegsExistencias;
    AgregaEnvio(zSiscomRegistro().Registro("%s [Todos]","Todos"));
    if((lzSisRegsExistencias=EnviaRecibe()))
    {
	return lzSisRegsExistencias;
    }
    else
    return 0;
}
zSiscomRegistros *zOperacionesServiSNTE::ExistenciaAlmacenProducto(zSiscomRegistro *pzSisRegProducto)
{
zSiscomRegistros *lzSisRegsExistencias;
    AgregaEnvio(pzSisRegProducto);
    if((lzSisRegsExistencias=EnviaRecibe()))
	 return lzSisRegsExistencias;
     else
     return 0;
}
zSiscomRegistros *zOperacionesServiSNTE::ExistenciasAlmacenProveedor(zSiscomRegistro *pzSisRegProveedor)
{
zSiscomRegistros *lzSisRegsExistencias;
    AgregaEnvio(pzSisRegProveedor);
    if((lzSisRegsExistencias=EnviaRecibe()))
	 return lzSisRegsExistencias;
     else
     return 0;
}
zSiscomRegistros *zOperacionesServiSNTE::ExistenciasAlmacenListaProductos(const char *pchrPtrLista)
{
zSiscomRegistros *lzSisRegsExistencias;
zSiscomRegistros lzSisRegsListaProductos;
lzSisRegsListaProductos=zSiscomRegistros().CadenaConSeparador("Producto",pchrPtrLista,'\n');
    AgregaEnvio(&lzSisRegsListaProductos);
    if((lzSisRegsExistencias=EnviaRecibe()))
	 return lzSisRegsExistencias;
     else
     return 0;
}

zSiscomRegistros *zOperacionesServiSNTE::ExistenciasTiendaProveedor(zSiscomRegistro *pzSisRegProveedor)
{
zSiscomRegistros *lzSisRegsExistencias;
    AgregaEnvio(pzSisRegProveedor);
    if((lzSisRegsExistencias=EnviaRecibe()))
	 return lzSisRegsExistencias;
     else
     return 0;
}
zSiscomRegistros *zOperacionesServiSNTE::ExistenciasTiendaListaProductos(const char *pchrPtrIdTienda,
									 const char *pchrPtrLista)
{
zSiscomRegistros *lzSisRegsExistencias;
zSiscomRegistros lzSisRegsListaProductos;
zSiscomRegistro *lzSisRegEnvio=new zSiscomRegistro;
lzSisRegsListaProductos=zSiscomRegistros().CadenaConSeparador("Producto",pchrPtrLista,'\n');

(*lzSisRegEnvio) 							<< 
new zSiscomCampo("IdTienda",(const unsigned char *)pchrPtrIdTienda) 	<<
 new zSiscomCampo("Productos");
 lzSisRegEnvio->AsociadosAlCampo("Productos",&lzSisRegsListaProductos);
    AgregaEnvio(lzSisRegEnvio);
    if((lzSisRegsExistencias=EnviaRecibe()))
	 return lzSisRegsExistencias;
     else
     return 0;
}

zSiscomRegistros *zOperacionesServiSNTE::ReporteCompras(const char *pchrPtrRangoFechas)
{
zSiscomRegistros *lzSisRegsCompras;
    AgregaEnvio(zSiscomRegistro().Registro("%s [RangoFechas]",pchrPtrRangoFechas));
    if((lzSisRegsCompras=EnviaRecibe()))
	 return lzSisRegsCompras;
     else
     return 0;
}
zSiscomRegistros *zOperacionesServiSNTE::ReporteComprasDetalle(zSiscomRegistro *pzSisRegCompra)
{
zSiscomRegistros *lzSisRegsCompras;
    AgregaEnvio(pzSisRegCompra);
    if((lzSisRegsCompras=EnviaRecibe()))
	 return lzSisRegsCompras;
     else
     return 0;

}
void zOperacionesServiSNTE::ActualizaPrecioCompra(zSiscomRegistro *pzSisRegActPrecio)
{
zSiscomRegistros *lzSisRegsRegreso;
AgregaEnvio(pzSisRegActPrecio);
if((lzSisRegsRegreso=EnviaRecibe()))
{

}
}

zSiscomRegistros *zOperacionesServiSNTE::TransferenciasEnviadas(const char *pchrPtrRangoFechas)
{
zSiscomRegistros *lzSisRegsCompras;
    AgregaEnvio(zSiscomRegistro().Registro("%s [RangoFechas]",pchrPtrRangoFechas));
    if((lzSisRegsCompras=EnviaRecibe()))
	 return lzSisRegsCompras;
     else
     return 0;
}



zSiscomRegistros *zOperacionesServiSNTE::CamposImpresionPuntoVenta()
{
zSiscomRegistros *lzSisRegsCompras;
    AgregaEnvio(zSiscomRegistro().Registro("%s [Modulo]","PuntoVenta"));
    if((lzSisRegsCompras=EnviaRecibe()))
	 return lzSisRegsCompras;
     else
     return 0;
}
zSiscomRegistros *zOperacionesServiSNTE::CamposImpresionReciboApartado()
{
zSiscomRegistros *lzSisRegsCompras;
    AgregaEnvio(zSiscomRegistro().Registro("%s [Modulo]","PuntoVenta"));
    if((lzSisRegsCompras=EnviaRecibe()))
	 return lzSisRegsCompras;
     else
     return 0;
}

zSiscomRegistros *zOperacionesServiSNTE::CamposImpresionTransferencia()
{
zSiscomRegistros *lzSisRegsCompras;
    AgregaEnvio(zSiscomRegistro().Registro("%s [Modulo]","PuntoVenta"));
    if((lzSisRegsCompras=EnviaRecibe()))
	 return lzSisRegsCompras;
     else
     return 0;
}
zSiscomRegistros *zOperacionesServiSNTE::CamposImpresionListaPrecios()
{
zSiscomRegistros *lzSisRegsCompras;
    AgregaEnvio(zSiscomRegistro().Registro("%s [Modulo]","PuntoVenta"));
    if((lzSisRegsCompras=EnviaRecibe()))
	 return lzSisRegsCompras;
     else
     return 0;
}
zSiscomRegistros *zOperacionesServiSNTE::CamposImpresionStockTienda()
{
zSiscomRegistros *lzSisRegsCompras;
    AgregaEnvio(zSiscomRegistro().Registro("%s [Modulo]","PuntoVenta"));
    if((lzSisRegsCompras=EnviaRecibe()))
	 return lzSisRegsCompras;
     else
     return 0;
}

zSiscomRegistros *zOperacionesServiSNTE::CamposImpresionExistenciaProveedor()
{
zSiscomRegistros *lzSisRegsCompras;
    AgregaEnvio(zSiscomRegistro().Registro("%s [Modulo]","PuntoVenta"));
    if((lzSisRegsCompras=EnviaRecibe()))
	 return lzSisRegsCompras;
     else
     return 0;
}

zSiscomRegistros *zOperacionesServiSNTE::CamposImpresionRelacionChequesPagar()
{
zSiscomRegistros *lzSisRegsCompras;
    AgregaEnvio(zSiscomRegistro().Registro("%s [Modulo]","PuntoVenta"));
    if((lzSisRegsCompras=EnviaRecibe()))
	 return lzSisRegsCompras;
     else
     return 0;
}

zSiscomRegistros *zOperacionesServiSNTE::CamposImpresionSoporteCompras()
{
zSiscomRegistros *lzSisRegsCompras;
    AgregaEnvio(zSiscomRegistro().Registro("%s [Modulo]","PuntoVenta"));
    if((lzSisRegsCompras=EnviaRecibe()))
	 return lzSisRegsCompras;
     else
     return 0;
}
zSiscomRegistros *zOperacionesServiSNTE::CamposImpresionSoporteVentas()
{
zSiscomRegistros *lzSisRegsCompras;
    AgregaEnvio(zSiscomRegistro().Registro("%s [Modulo]","PuntoVenta"));
    if((lzSisRegsCompras=EnviaRecibe()))
	 return lzSisRegsCompras;
     else
     return 0;
}
zSiscomRegistros *zOperacionesServiSNTE::CamposImpresionSoporteTransferencias()
{
zSiscomRegistros *lzSisRegsCompras;
    AgregaEnvio(zSiscomRegistro().Registro("%s [Modulo]","PuntoVenta"));
    if((lzSisRegsCompras=EnviaRecibe()))
	 return lzSisRegsCompras;
     else
     return 0;
}
zSiscomRegistros *zOperacionesServiSNTE::CamposImpresionDatosCompra()
{
zSiscomRegistros *lzSisRegsCompras;
    AgregaEnvio(zSiscomRegistro().Registro("%s [Modulo]","PuntoVenta"));
    if((lzSisRegsCompras=EnviaRecibe()))
	 return lzSisRegsCompras;
     else
     return 0;
}

zSiscomRegistros *zOperacionesServiSNTE::CamposImpresionCuentasPagar()
{
zSiscomRegistros *lzSisRegsCompras;
    AgregaEnvio(zSiscomRegistro().Registro("%s [Modulo]","PuntoVenta"));
    if((lzSisRegsCompras=EnviaRecibe()))
	 return lzSisRegsCompras;
     else
     return 0;
}

zSiscomRegistros *zOperacionesServiSNTE::CamposImpresionExistenciaTiendaProveedor()
{
zSiscomRegistros *lzSisRegsCompras;
    AgregaEnvio(zSiscomRegistro().Registro("%s [Modulo]","PuntoVenta"));
    if((lzSisRegsCompras=EnviaRecibe()))
	 return lzSisRegsCompras;
     else
     return 0;
}

zSiscomRegistros *zOperacionesServiSNTE::CamposImpresionProveedores()
{
zSiscomRegistros *lzSisRegsCompras;
    AgregaEnvio(zSiscomRegistro().Registro("%s [Modulo]","PuntoVenta"));
    if((lzSisRegsCompras=EnviaRecibe()))
	 return lzSisRegsCompras;
     else
     return 0;
}


zSiscomRegistros *zOperacionesServiSNTE::CamposImpresionListaPreciosComprador()
{
zSiscomRegistros *lzSisRegsCompras;
    AgregaEnvio(zSiscomRegistro().Registro("%s [Modulo]","PuntoVenta"));
    if((lzSisRegsCompras=EnviaRecibe()))
	 return lzSisRegsCompras;
     else
     return 0;
}
zSiscomRegistros *zOperacionesServiSNTE::CamposImpresionStockProveedorCosto()
{
zSiscomRegistros *lzSisRegsCompras;
    AgregaEnvio(zSiscomRegistro().Registro("%s [Modulo]","PuntoVenta"));
    if((lzSisRegsCompras=EnviaRecibe()))
	 return lzSisRegsCompras;
     else
     return 0;
}

void zOperacionesServiSNTE::CostoPrecioTransferencia(zOrden *pzOrden)
{
zSiscomRegistros *lzSisRegsRespuesta;
zSiscomRegistro *lzSisRegEnvio;
    AgregaEnvio(pzOrden);
    lzSisRegsRespuesta=EnviaRecibe();
    lzSisRegEnvio=lzSisRegsRespuesta->Primer()->AsociadoDelCampo("Envio");
    SiscomRegistrosLog(lzSisRegEnvio->AsociadosDelCampo("Productos"));
    pzOrden->AsignaCostoPrecioProductos(lzSisRegEnvio->AsociadosDelCampo("Productos"));
}

void zOperacionesServiSNTE::RegistraFolio(zFolio *pzFolio)
{
zSiscomRegistros *lzSisRegsRespuesta;
zSiscomRegistro *lzSisRegEnvio;
	AgregaEnvio(pzFolio);
	if(lzSisRegsRespuesta=EnviaRecibe())
	{


	}

}
zSiscomRegistros *zOperacionesServiSNTE::TiposFolio()
{
  return EnviaRecibe();  
}
int zOperacionesServiSNTE::FolioActualFactura(const char *pchrPtrIdTipoFolio,
					      char *pchrPtrFolio)
{
zSiscomRegistros *lzSisRegsRespuesta;
zSiscomRegistro *lzSisRegEnvio;

   AgregaEnvio(zSiscomRegistro().Registro("%s [IdTipoFolio] %s [FolioFactura] ",
   					   pchrPtrIdTipoFolio,""));
   if(lzSisRegsRespuesta=EnviaRecibe())
   {
     if(lzSisRegEnvio=(*lzSisRegsRespuesta)[0])
        strcpy(pchrPtrFolio,(const char *)(*lzSisRegEnvio)["FolioActual"]); 
   }

}

int zOperacionesServiSNTE::CancelarFolioFactura(zVenta *pzVenta,
						const char *pchrPtrNuevoFolio,
						const char *pchrPtrMotivo)
{
zSiscomRegistros *lzSisRegsRespuesta;
zSiscomRegistro *lzSisRegEnvio;
AgregaEnvio(zSiscomRegistro().Registro("%s [IdVenta] "
				       "%s [FolioCancelado] "
				       "%s [FolioNuevo] "
				       "%s [Motivo] "
				       "%s [IdCancelacionFolio] ",
				       pzVenta->Id(),
				       pzVenta->Folio(),
				       pchrPtrNuevoFolio,
				       pchrPtrMotivo,
				       0));
 
   if(lzSisRegsRespuesta=EnviaRecibe())
   {
   }
   
}

zSiscomRegistros *zOperacionesServiSNTE::FoliosCanceladosPorTienda(zSiscomRegistro *pzSisRegTienda,
									const char *pchrPtrFechaInicio,
									const char *pchrPtrFechaFinal)
{
LogSiscom("Se agrego la fecha Inicio %s",pchrPtrFechaInicio);
LogSiscom("Se agrego la fecha Final %s",pchrPtrFechaFinal);
zSiscomRegistros *lzSisRegsFolios;
AgregaEnvio(zSiscomRegistro().Registro("%s [IdTienda] %s [FechaInicio] %s [FechaFinal]",
			 	(*pzSisRegTienda)["idtienda"],
				pchrPtrFechaInicio,
				pchrPtrFechaFinal));
   if(lzSisRegsFolios=EnviaRecibe())
   {
    SiscomRegistrosLog(lzSisRegsFolios);
    return lzSisRegsFolios;
   }
   else
return 0;
}

int zOperacionesServiSNTE::RFCRegistradoBaseDatos(const char *pchrPtrRFC)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRFCRegistradoBD;
   AgregaEnvio(zSiscomRegistro().Registro("%s [RFC] ",pchrPtrRFC));

   if((lzSisRegsRegreso=EnviaRecibe()))
   {
    SiscomRegistrosLog(lzSisRegsRegreso);
       if((lzSisRegRFCRegistradoBD=lzSisRegsRegreso->Primer()))
       {
	  if(lzSisRegRFCRegistradoBD->EstaElCampoEnElRegistro("RFCRegistradoBaseDatos"))
	  return 1;
	  else 
	  return 0;
       }
   }
   return 0;
}
zSiscomRegistro *zOperacionesServiSNTE::RegistraUsuario(zUsuario *pzUsuario)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRFCRegistradoBD;

   AgregaEnvio(pzUsuario);
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
       if((lzSisRegRFCRegistradoBD=lzSisRegsRegreso->Primer()))
       {
       }
   }
   return 0;
}

int zOperacionesServiSNTE::ActivaDesactivaServidor(const char *pchrPtrIdTienda,
						   const char *pchrPtrActivo)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRFCRegistradoBD;
   AgregaEnvio(zSiscomRegistro().Registro("%s [IdTienda] %s [Activo]",
   				          pchrPtrIdTienda,
					  pchrPtrActivo));

   if((lzSisRegsRegreso=EnviaRecibe()))
   {
    SiscomRegistrosLog(lzSisRegsRegreso);
       if((lzSisRegRFCRegistradoBD=lzSisRegsRegreso->Primer()))
       {
	  if(lzSisRegRFCRegistradoBD->EstaElCampoEnElRegistro("RFCRegistradoBaseDatos"))
	  return 1;
	  else 
	  return 0;
       }
   }
   return 0;
}

int zOperacionesServiSNTE::ActualizaStock(zSiscomRegistro *pzSisRegTienda,
					  zSiscomRegistro *pzSisRegProducto,
					  const char *pchrPtrCantidad)
{
zSiscomRegistros *lzSisRegsRegreso;
   AgregaEnvio(zSiscomRegistro().Registro("%s [IdTienda] %s [IdProducto] %s [Cantidad]",
   					   (*pzSisRegTienda)["idtienda"],
					   (*pzSisRegProducto)["idproducto"],
					   pchrPtrCantidad));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
    SiscomRegistrosLog(lzSisRegsRegreso);
   }
}
