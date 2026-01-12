#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistro.h>
#include <zOrdenVenta.h>
#include <zOrdenes.h>
#include <zFactura.h>
#include <zCliente.h>
#include <zClienteSiscom.h>
#include <zCorreos.h>
#include <zCorreo.h>
#include <zTelefonos.h>
#include <zTelefono.h>
#include <zPersona.h>
#include <zDireccion.h>
#include <zEmpresa.h>
#include <zExistenciaExpendios.h>
#include <zProductos.h>
#include <zPractica.h>
#include <zDireccion.h>
#include <zSiscomCampo.h>
#include <zSiscomDesarrollo4.h>
#include <zReporteVentas.h>
#include <zCotizacion.h>
#include <zProductosTransferir.h>
#include <zCircuitoImpreso.h>
#include <zOrdenCompra.h>
#include <zDatosReEnvioFactura.h>
#include <zClaveSat.h>
#include <zPedidoExpendio.h>
#include <zProductoPedido.h>
#include <zExpendios.h>
#include <zDenominacion.h>
#include <zCierreCaja.h>
#include <zCompraImportacion.h>
#include <zProductosImportados.h>
#include <zProductoSiscom.h>
#include <zProductoImportado.h>
#include <zPreciosExpendios.h>
#include <zPrecios2Productos.h>
#include <zCotizacionImportacion.h>
#include <zCotizacionesImportacion.h>
#include <zDirecciones.h>
#include <zComprasImportacion.h>
#include <zDevolucion.h>
#include <zClavesProveedor.h>
#include <zClaveProveedor.h>
#include <zProductoCompraImportacion.h>
#include <zCajaMaterial.h>
#include <zProductoImportadoInf.h>
#include <zOrdenesFavoritas.h>
#include <zCajas.h>
#include <zPedido.h>
#include <zPuntoEntrega.h>
#include <zEstadoPedido.h>
#include <zEscuela.h>
#include <zEscuelas.h>
#include <zContenedor.h>
#include <zProductoPrecioExpendios.h>
#include <zListaExpendios.h>
#include <zCondicionConsultaOrdenes.h>
#include <zBodegas.h>
#include <zExistenciaBodega.h>
#include <zTransfiereBodegaBodega.h>
#include <zFormaPagoTransferencia.h>
#include <zFormaPago.h>
#include <zClientesSiscom.h>
#include <zConCuantoPago.h>
#include <zCambiosCaja.h>
#include <zCambioCaja.h>
#include <zDenominaciones.h>
#include <zCompraParcialImportacion.h>
#include <zCorteCaja.h>
#include <zApartado.h>
#include <zBodega.h>
#include <zAbonoAApartado.h>
#include <zExistenciaVenta.h>
#include <zCompras.h>

#include <string.h> 
zSiscomElectronica::zSiscomElectronica(zSiscomConexion *pzSiscomConexion,
				       const char *pchrPtrFuncion,
				       const char *pchrPtrModulo):
				       zSiscomOperaciones(pzSiscomConexion,
				       			  pchrPtrModulo,
							  pchrPtrFuncion)
{


}
zSiscomElectronica::~zSiscomElectronica()
{
}
zSiscomRegistros *zSiscomElectronica::OrdenesPendientes(const char *pchrPtrFechaInicio,
				     			const char *pchrPtrFechaFin)
{
zSiscomRegistros *lzSisRegOrdPendientes;
AgregaEnvio(zSiscomRegistro().Registro("%s [FechaInicio] %s [FechaFin]",
		pchrPtrFechaInicio,
		pchrPtrFechaFin));
lzSisRegOrdPendientes=EnviaRecibe();
SiscomRegistrosLog(lzSisRegOrdPendientes);
return lzSisRegOrdPendientes;
}

zSiscomRegistros *zSiscomElectronica::Productos(const char *pchrPtrCriterio)
{
zSiscomRegistros *lzSisRegsRespuesta;
zSiscomRegistro *lzSisRegRespuesta;
AgregaEnvio(zSiscomRegistro().Registro("%s [Criterio]",pchrPtrCriterio));
if((lzSisRegsRespuesta=EnviaRecibe()))
{
   lzSisRegRespuesta=(*lzSisRegsRespuesta)[0]; 
   if(lzSisRegRespuesta->EstaElCampoEnElRegistro("Estado"))
   return 0;
   else 
   return lzSisRegsRespuesta;
}
else
return 0;
}


zSiscomRegistros *zSiscomElectronica::Escuelas(const char *pchrPtrCriterio)
{
AgregaEnvio(zSiscomRegistro().Registro("%s [Criterio]",pchrPtrCriterio));
return EnviaRecibe();
}

zSiscomRegistros *zSiscomElectronica::TiposProducto(const char *pchrPtrCriterio)
{
AgregaEnvio(zSiscomRegistro().Registro("%s [Criterio]",pchrPtrCriterio));
return EnviaRecibe();
}

zSiscomRegistros *zSiscomElectronica::EstadosImpresos(const char *pchrPtrCriterio)
{
AgregaEnvio(zSiscomRegistro().Registro("%s [Criterio]",pchrPtrCriterio));
return EnviaRecibe();
}
zSiscomRegistros *zSiscomElectronica::EstadosPedidos(const char *pchrPtrCriterio)
{
AgregaEnvio(zSiscomRegistro().Registro("%s [Criterio]",pchrPtrCriterio));
return EnviaRecibe();
}


zSiscomRegistros *zSiscomElectronica::Gastos(const char *pchrPtrCriterio)
{
AgregaEnvio(zSiscomRegistro().Registro("%s [Criterio]",pchrPtrCriterio));
return EnviaRecibe();
}


int zSiscomElectronica::CotizaOrden(zOrdenVenta *pzOrdenVenta,
				    zSiscomRegistro **pzSisRegEdoRegreso)
{
zSiscomRegistros *lzSisRegsOrdenCotizada;
zSiscomRegistro *lzSisRegOrden;
	AgregaEnvio(pzOrdenVenta);
	*pzSisRegEdoRegreso=0;
     if((lzSisRegsOrdenCotizada=EnviaRecibe()))
     {
	  lzSisRegOrden=(*lzSisRegsOrdenCotizada)[0];
	  if(lzSisRegOrden)
	  {
	    if(lzSisRegOrden->EstaElCampoEnElRegistro("Estado"))
	    {
	    *pzSisRegEdoRegreso=lzSisRegOrden;
	     ProcesaErrorCambioDatosOrdenVenta(lzSisRegOrden,pzOrdenVenta);
	     return lzSisRegOrden->CampoInt("Estado");
	    }
	    else
	    {
	    pzOrdenVenta->ActualizaOrden(lzSisRegOrden);
	    return 0;
	    }
	 }
	 else
	 {
	 LogSiscom("Error en la recepcion de la cotizacion");
	 SiscomRegistroLog2(lzSisRegOrden);
	 return 0;
	 }
     }
     else
     {
     LogSiscom("NO llego la respuesta");
     return 0;
     }
}


int zSiscomElectronica::ClienteRegistrado(const char *pchrPtrRFC,
					  zCliente *pzCliente)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegCliente;
   AgregaEnvio(zSiscomRegistro().Registro("%s [RFC]",pchrPtrRFC));

   if((lzSisRegsRegreso=EnviaRecibe()))
   {
	lzSisRegCliente=(*lzSisRegsRegreso)[0];
	SiscomRegistroLog2(lzSisRegCliente);
     if(lzSisRegCliente->EstaElCampoEnElRegistro("Persona"))
     {
	if(lzSisRegCliente->AsociadoDelCampo("Persona"))
	{
	/* Miercoles 16 de Noviembre del 2016 
	 * Revisar la asignacion de Persona, por los nombres en minuscula 
	 * que regresa la consulta a base de datos, para que en el select 
	 * se use la notacion para que regrese el nombre del campo correcto, 
	 * y no hacer la asignacion via zSiscomRegistro, sino directo de como
	 * llega
	 */
	pzCliente->Persona(new zPersona(lzSisRegCliente->AsociadoDelCampo("Persona")));
	pzCliente->Direccion(new zDireccion(lzSisRegCliente->AsociadoDelCampo("Direccion")));
	pzCliente->Correos((zCorreos *)lzSisRegCliente->AsociadosDelCampo("Correos"));
	pzCliente->Telefonos((zTelefonos *)lzSisRegCliente->AsociadosDelCampo("Telefonos"));
	pzCliente->RFC((const char *)lzSisRegCliente->AsociadoDelCampo("Persona")->Campo("rfc"));
	return 1;
       }
       else
       if(lzSisRegCliente->AsociadoDelCampo("Empresa"))
       {
	pzCliente->Empresa((zEmpresa *)lzSisRegCliente->AsociadoDelCampo("Empresa"));
	pzCliente->Direccion(new zDireccion(lzSisRegCliente->AsociadoDelCampo("Direccion")));
	pzCliente->Correos((zCorreos *)lzSisRegCliente->AsociadosDelCampo("Correos"));
	pzCliente->Telefonos((zTelefonos *)lzSisRegCliente->AsociadosDelCampo("Telefonos"));
	pzCliente->RFC((const char *)lzSisRegCliente->AsociadoDelCampo("Empresa")->Campo("Rfc"));
	return 2;
	}
	return 0;
   }
   else
   {
    LogSiscom("Cliente No Registrado");
   return 0;
   }
   }
   else
   return 0;
}
zOrdenes *zSiscomElectronica::Ordenes(const char *pchrPtrFechaInicio,
				      const char *pchrPtrFechaFin,
				      const char *pchrPtrIdTipoOrden)
{
zSiscomRegistros *lzSisRegsOrdenes;
zSiscomRegistro *lzSisRegOrden;
	AgregaEnvio(zSiscomRegistro().Registro("%s [FechaInicio] %s[FechaFin] %s[IdTipoOrden]",
					       pchrPtrFechaInicio,
					       pchrPtrFechaFin,
					       pchrPtrIdTipoOrden));
     if((lzSisRegsOrdenes=EnviaRecibe()))
	return (zOrdenes *)lzSisRegsOrdenes;
   return 0;
}

zOrdenes *zSiscomElectronica::OrdenesParaFacturar(const char *pchrPtrFechaInicio,
				      const char *pchrPtrFechaFin)
{
zSiscomRegistros *lzSisRegsOrdenes;
zSiscomRegistro *lzSisRegOrden;
	AgregaEnvio(zSiscomRegistro().Registro("%s [FechaInicio] %s[FechaFin] ",
					       pchrPtrFechaInicio,
					       pchrPtrFechaFin));
     if((lzSisRegsOrdenes=EnviaRecibe()))
	return (zOrdenes *)lzSisRegsOrdenes;
   return 0;
}


zOrdenes *zSiscomElectronica::OrdenParaFacturar(const char *pchrPtrIdVenta)
{
zSiscomRegistros *lzSisRegsOrdenes;
zSiscomRegistro *lzSisRegOrden;
	AgregaEnvio(zSiscomRegistro().Registro("%s [IdVenta] ", pchrPtrIdVenta));
     if((lzSisRegsOrdenes=EnviaRecibe()))
	return (zOrdenes *)lzSisRegsOrdenes;
   return 0;
}

void zSiscomElectronica::AsignaDatosApartado(zSiscomRegistro *pzSisRegCotizacion,
					     zOrdenVenta *pzOrden)
{
zSiscomRegistro *lzSisRegCotizacion;

 SiscomRegistroLog2(pzSisRegCotizacion); 

  if((lzSisRegCotizacion=pzSisRegCotizacion->AsociadoDelCampo("Apartado")))
   pzOrden->Apartado(new zApartado(lzSisRegCotizacion));
}
void zSiscomElectronica::AsignaDatosCotizacion(zSiscomRegistro *pzSisRegCotizacion,
					       zOrdenVenta *pzOrden)
{
zSiscomRegistro *lzSisRegCotizacion;
  if((lzSisRegCotizacion=pzSisRegCotizacion->AsociadoDelCampo("Cotizacion")))
  {
  pzOrden->Cotizacion(new zCotizacion(lzSisRegCotizacion));
  }
}

void zSiscomElectronica::AsignaDatosVenta(zSiscomRegistro *pzSisRegOrden,
				          zOrdenVenta *pzOrden)
{
}
void zSiscomElectronica::AsignaDatosCancelacion(zSiscomRegistro *,
					        zOrdenVenta *)
{
 LogSiscom("Cancelacion");
}

void zSiscomElectronica::AsignaDatosPagoTransferencia(zSiscomRegistro *pzSisRegRegreso,
					             zOrdenVenta *pzOrdenV)
{
zFormaPagoTransferencia *lzFormaPagoT;
zFormaPago *lzFormaPago=new zFormaPago;
lzFormaPagoT=new zFormaPagoTransferencia(pzSisRegRegreso);
lzFormaPago->Transferencia(lzFormaPagoT);
pzOrdenV->FormaPago(lzFormaPago);
}

void zSiscomElectronica::AsignaDatosPedido(zSiscomRegistro *pzSisRegOrden,
					   zOrdenVenta *pzOrdenVenta)
{
zClienteSiscom *lzCliSiscom=new zClienteSiscom(pzSisRegOrden);
/*
SiscomRegistroLog2(pzSisRegOrden);
SiscomRegistroLog2(pzSisRegOrden->AsociadoDelCampo("Pedido"));
*/
zPedido *lzPedido=new zPedido(pzSisRegOrden->AsociadoDelCampo("Pedido"));
 pzOrdenVenta->Cliente(lzCliSiscom);
 pzOrdenVenta->Pedido(lzPedido);
 pzOrdenVenta->Pedido()->PuntoEntrega(zPuntoEntrega::PuntoEntrega(pzSisRegOrden->AsociadoDelCampo("Pedido")));
 pzOrdenVenta->Pedido()->EstadoPedido(zEstadoPedido::EstadoPedido(pzSisRegOrden->AsociadoDelCampo("Pedido")));
}
void zSiscomElectronica::AsignaDatosNoDefinido(zSiscomRegistro *,zOrdenVenta *)
{
 LogSiscom("");
}


void zSiscomElectronica::IniciaAsignandoDatosOrden()
{
  DatosTipoOrden[0]=&zSiscomElectronica::AsignaDatosVenta;
  DatosTipoOrden[1]=&zSiscomElectronica::AsignaDatosCotizacion;
  DatosTipoOrden[2]=&zSiscomElectronica::AsignaDatosApartado;
  DatosTipoOrden[3]=&zSiscomElectronica::AsignaDatosNoDefinido;
  DatosTipoOrden[4]=&zSiscomElectronica::AsignaDatosPedido;
  DatosTipoOrden[5]=&zSiscomElectronica::AsignaDatosCancelacion;
  DatosTipoOrden[6]=&zSiscomElectronica::AsignaDatosNoDefinido;
  DatosTipoOrden[7]=&zSiscomElectronica::AsignaDatosNoDefinido;
  DatosTipoOrden[8]=&zSiscomElectronica::AsignaDatosNoDefinido;
  DatosTipoOrden[9]=&zSiscomElectronica::AsignaDatosNoDefinido;
  DatosTipoOrden[10]=&zSiscomElectronica::AsignaDatosNoDefinido;
  DatosTipoOrden[11]=&zSiscomElectronica::AsignaDatosPagoTransferencia;
  DatosTipoOrden[12]=&zSiscomElectronica::AsignaDatosNoDefinido;
  DatosTipoOrden[13]=&zSiscomElectronica::AsignaDatosNoDefinido;
  DatosTipoOrden[14]=&zSiscomElectronica::AsignaDatosNoDefinido;
  

}
void zSiscomElectronica::AsignandoDatosOrden(zSiscomRegistro *pzSisRegCotizacion,
					     zOrdenVenta *pzOrden)
{
int lintIdTipoOrden;
lintIdTipoOrden=pzSisRegCotizacion->CampoInt("idtipoorden");
(this->*DatosTipoOrden[lintIdTipoOrden])(pzSisRegCotizacion,pzOrden);
}
void zSiscomElectronica::AsignandoOrdenes(zSiscomRegistros *pzSisRegsOrdenes,
					  zOrdenes *pzOrdenes)
{
zSiscomRegistro *lzSisRegOrden;
zOrdenVenta *lzOrden;
IniciaAsignandoDatosOrden();
for(lzSisRegOrden=pzSisRegsOrdenes->Primer();
    lzSisRegOrden;
    lzSisRegOrden=pzSisRegsOrdenes->Siguiente())
{
    lzOrden=zOrdenVenta().ConsultaOrdenes2(lzSisRegOrden);
    SiscomRegistroLog2(lzOrden);
    AsignandoDatosOrden(lzSisRegOrden,lzOrden);
    pzOrdenes->Orden(lzOrden);	
}
}
						
					
/* Ciudad de Mexico a 17 de Febrero del 2017
 * A este punto podemos decir que una orden 
 * es la informacion de productos y sus datos de venta y puede o no 
 * contener datos de pedido, datos apartado , cotizacion
 * Con esta consideracion se implementa una funcion general
 * que consulte a la base de datos y regrese en zOrdenes 
 * la informacion , agregando en el servidor los datos si 
 * es pedido , si es apartado o cotizacion 
 */
zOrdenes *zSiscomElectronica::Ordenes2(const char *pchrPtrFechaInicio,
				      const char *pchrPtrFechaFin,
				      const char *pchrPtrIdTipoOrden)
{
zSiscomRegistros *lzSisRegsOrdenes;
zSiscomRegistro *lzSisRegOrden;
	AgregaEnvio(zSiscomRegistro().Registro("%s [FechaInicio] %s[FechaFin] %s[IdTipoOrden]",
					       pchrPtrFechaInicio,
					       pchrPtrFechaFin,
					       pchrPtrIdTipoOrden));
     if((lzSisRegsOrdenes=EnviaRecibe()))
     {
	zOrdenes *lzOrdenes=new zOrdenes;
	AsignandoOrdenes(lzSisRegsOrdenes,lzOrdenes);
	return lzOrdenes;
     }
   return 0;
}


zOrdenes *zSiscomElectronica::Ordenes(zCondicionConsultaOrdenes *pzConConsOrdenes)
{
zSiscomRegistros *lzSisRegsOrdenes;
zSiscomRegistro *lzSisRegOrden;
	AgregaEnvio(pzConConsOrdenes);
     if((lzSisRegsOrdenes=EnviaRecibe()))
     {
	zOrdenes *lzOrdenes=new zOrdenes;
	AsignandoOrdenes(lzSisRegsOrdenes,lzOrdenes);
	return lzOrdenes;
     }
   return 0;
}




int zSiscomElectronica::CalculaFactura(zOrdenes *pzOrdenes,
				       zFactura *pzFactura)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;

 	AgregaEnvio(pzOrdenes);
	if((lzSisRegsRegreso=EnviaRecibe()))
	{
	  lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	  pzFactura->Productos(lzSisRegRegreso->AsociadosDelCampo("Productos")); 
	  pzFactura->Importe((const char *)(*lzSisRegRegreso)["Importe"]);
	  pzFactura->Total((const char *)(*lzSisRegRegreso)["Total"]);
	  pzFactura->Iva((const char *)(*lzSisRegRegreso)["Iva"]);
	  return 1;
	}
return 0;
}
void zSiscomElectronica::RegistraCliente(zCliente *pzCliente)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;

      AgregaEnvio(pzCliente);
      if((lzSisRegsRegreso=EnviaRecibe()))
      {
       LogSiscom("Si llego algo ....");

  	lzSisRegRegreso=(*lzSisRegsRegreso)[0];	
	if(lzSisRegRegreso)
	{
	SiscomRegistroLog2(lzSisRegRegreso);
	pzCliente->Empresa()->IdEmpresa((const char *)(*lzSisRegRegreso)["IdEmpresa"]);
	}
	else
	{

	LogSiscom("Se Registro el cliente pero no se envio nada de regreso");
	}
      }
      else
      {
	LogSiscom("Se Registro el cliente pero no se envio nada de regreso");
      }
}
int zSiscomElectronica::RegistraCliente(zClienteSiscom *pzSisCliSiscom,
					zClientesSiscom **pzClisSiscom)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso,
		*lzSisRegDireccion,
		*lzSisRegTelefono,
		*lzSisRegCorreo;
	AgregaEnvio(pzSisCliSiscom);
	if((lzSisRegsRegreso=EnviaRecibe()))
	{
	    lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	    SiscomRegistroLog2(lzSisRegRegreso);
	    if(lzSisRegRegreso->CampoInt("Registrado")==1)
	    {
	    
	    	pzSisCliSiscom->IdPersona((const char *)lzSisRegRegreso->CampoAsociado("Persona","idpersona"));
		pzSisCliSiscom->Nombre((const char *)lzSisRegRegreso->CampoAsociado("Persona","nombre"));
		pzSisCliSiscom->APaterno((const char *)lzSisRegRegreso->CampoAsociado("Persona","apaterno"));
		pzSisCliSiscom->AMaterno((const char *)lzSisRegRegreso->CampoAsociado("Persona","amaterno"));
		pzSisCliSiscom->Escuela(new zEscuela(lzSisRegRegreso->AsociadoDelCampo("Persona")));

		if((lzSisRegDireccion=lzSisRegRegreso->AsociadoDelCampo("Direccion")))
		pzSisCliSiscom->Direccion(new zDireccion(lzSisRegDireccion));
		if((lzSisRegTelefono=lzSisRegRegreso->AsociadoDelCampo("Telefonos")))
		pzSisCliSiscom->Celular(new zTelefono(lzSisRegTelefono));
		if((lzSisRegCorreo=lzSisRegRegreso->AsociadoDelCampo("Correos")))
		pzSisCliSiscom->Correo(new zCorreo(lzSisRegCorreo));

		LogSiscom("La Escuela %s",pzSisCliSiscom->Escuela());
	    	return 0;
	    }
	    else
	    if(lzSisRegRegreso->CampoInt("Registrado")==2)
	    {
	      *pzClisSiscom=new zClientesSiscom(lzSisRegRegreso->AsociadosDelCampo("Clientes"));
	      return 2;
	    }
	    else
	    if(lzSisRegRegreso->CampoInt("Registrado")==3)
	    {
		return 3;
	    }
	    else
	    {
	    	pzSisCliSiscom->IdPersona((const char *)lzSisRegRegreso->Campo("IdPersona"));
	    	return 1;
	    }
	}
	return 0;
}
int zSiscomElectronica::RegistraCelularAlumno(zClienteSiscom *pzSisCliSiscom)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
	AgregaEnvio(pzSisCliSiscom);
	if((lzSisRegsRegreso=EnviaRecibe()))
	{
	    lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	    SiscomRegistroLog2(lzSisRegRegreso);
	    return 1;
	}
return 0;

}
int zSiscomElectronica::RegistraCorreoAlumno(zClienteSiscom *pzSisCliSiscom)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
	AgregaEnvio(pzSisCliSiscom);
	if((lzSisRegsRegreso=EnviaRecibe()))
	{
	    lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	    SiscomRegistroLog2(lzSisRegRegreso);
	    return 1;
	}
return 0;
}
int zSiscomElectronica::RegistraDireccionAlumno(zClienteSiscom *pzSisCliSiscom)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
	AgregaEnvio(pzSisCliSiscom);
	if((lzSisRegsRegreso=EnviaRecibe()))
	{
	    SiscomRegistroLog2(pzSisCliSiscom->Direccion());	
	    return 1;
	}
return 0;
}


int zSiscomElectronica::Factura(zFactura *pzFactura,
				char **pchrPtrEstadoOperacion)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
	AgregaEnvio(pzFactura);
	SiscomRegistroLog2(pzFactura);
	if((lzSisRegsRegreso=EnviaRecibe()))
	{
	   lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	   SiscomRegistroLog2(lzSisRegRegreso);
	   *pchrPtrEstadoOperacion=(char *)(*lzSisRegRegreso)["Descripcion"];
	   return lzSisRegRegreso->CampoInt("Estado");
	}
	else
	return 0;
}
zSiscomRegistro *zSiscomElectronica::FormaRegistroAgregarCorreo(zPersona *pzPersona,
						   zEmpresa *pzEmpresa,
						   zCorreos *pzCorreos)
{
zSiscomRegistro *lzSisRegRegreso=new zSiscomRegistro;

(*lzSisRegRegreso) 			<< 
new zSiscomCampo("Persona",pzPersona)  	<<
new zSiscomCampo("Empresa",pzEmpresa)	<<
new zSiscomCampo("Correos",pzCorreos);
return lzSisRegRegreso;
}
void zSiscomElectronica::AgregaCorreoCliente(zPersona *pzPersona,
					    zEmpresa *pzEmpresa,
					    zCorreos *pzCorreos)
{
zSiscomRegistros *lzSisRegsRespuesta;
    AgregaEnvio(FormaRegistroAgregarCorreo(pzPersona,
    					   pzEmpresa,
					   pzCorreos));
    lzSisRegsRespuesta=EnviaRecibe();
}

void zSiscomElectronica::ExistenciaExpendios(zProductos *pzProductos,
					    zExistenciaExpendios *pzExExpendios)
{
   AgregaEnvio(pzProductos);
   pzExExpendios->Productos(EnviaRecibe());
}
void zSiscomElectronica::ExistenciaExpendios(zExistenciaVenta *pzExistenciaV)
{
   AgregaEnvio(pzExistenciaV);
   pzExistenciaV->Productos((zProductos *)EnviaRecibe());
}

void zSiscomElectronica::ExistenciaExpendios(zSiscomRegistro *pzSisRegProducto,
					     zExistenciaExpendios *pzExExpendios)
{
  AgregaEnvio(pzSisRegProducto);
  pzExExpendios->Productos(EnviaRecibe());
}
/* Siscom Ecatepec 
 * 14 de enero 2025 
 * A esta funcion se le pasara como parametro la forma de la consulta
 * pudiendo seleccionar todos los producto 
 * o familia 
 * o algun otro filtro
 *
 * El cual se debera integrar como campo en zExistenciaVenta 
 *
 */
void zSiscomElectronica::ExistenciaSiscom(zExistenciaVenta *pzExistenciaV)
{
zProductos *lzProductos;
    AgregaEnvio(pzExistenciaV);
    lzProductos=(zProductos *)EnviaRecibe();
    if(lzProductos)
    pzExistenciaV->Productos(lzProductos);
    SiscomRegistrosLog(lzProductos);
}

int zSiscomElectronica::ValidaReCaptura(const char *pchrPtrCaptura1,
					const char *pchrPtrCaptura2)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
   AgregaEnvio(zSiscomRegistro().Registro("%s [CapturaUno] %s [CapturaDos] ",
   					  pchrPtrCaptura1,
					  pchrPtrCaptura2));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
	lzSisRegRegreso=(*lzSisRegsRegreso)[0];
   	SiscomRegistroLog2(lzSisRegRegreso);
	return lzSisRegRegreso->EsElValorCampo("Estado","1");
   }

return 0;
}
void zSiscomElectronica::ImprimeTicketVenta(zOrdenVenta *pzOrdVenta)
{
     AgregaEnvio(pzOrdVenta);
     EnviaRecibe();
}
void zSiscomElectronica::RegistraOrden(zOrdenVenta *pzOrdVenta)
{
     AgregaEnvio(pzOrdVenta);
     EnviaRecibe();
}

int zSiscomElectronica::IdNuevaOrden(char **pchrPtrIdNuevaOrden)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
 AgregaEnvio(zSiscomRegistro().Registro("%s [Nada]","Nada"));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
	if((lzSisRegRegreso=(*lzSisRegsRegreso)[0]))
	{
	*pchrPtrIdNuevaOrden=(char *)(*lzSisRegRegreso)["IdOrden"];
	return 1;
	}
	else
	return 0;
   }
   else
   return 0;
}
zSiscomRegistro *zSiscomElectronica::PublicoEnGeneral()
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
 AgregaEnvio(zSiscomRegistro().Registro("%s [Nada]","Nada"));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
      if((lzSisRegRegreso=(*lzSisRegsRegreso)[0]))
	return lzSisRegRegreso;
      else
      return (zSiscomRegistro *)0;
   }
   else
   return (zSiscomRegistro *)0;
}
zSiscomRegistros *zSiscomElectronica::Apartados(const char *pchrPtrFechaIni,
				   const char *pchrPtrFechaFin)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
 AgregaEnvio(zSiscomRegistro().Registro("%s [FechaIni] %s [FechaFin]",
 	     pchrPtrFechaIni,
	     pchrPtrFechaFin));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
   	SiscomRegistrosLog(lzSisRegsRegreso);
	return lzSisRegsRegreso;
   }
return 0;
}
void zSiscomElectronica::CierraApartado(zSiscomRegistro *pzSisRegApartado)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
 AgregaEnvio(pzSisRegApartado);
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
   	SiscomRegistrosLog(lzSisRegsRegreso);
   }
}
zSiscomRegistros *zSiscomElectronica::ProductoEnApartados(const char *pchrPtrClave)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
 AgregaEnvio(zSiscomRegistro().Registro("%s [Clave]",pchrPtrClave));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
   	SiscomRegistrosLog(lzSisRegsRegreso);
	return lzSisRegsRegreso;
   }
   return 0;
}
const char *zSiscomElectronica::RegistraPractica(zPractica *pzPractica)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
 AgregaEnvio(pzPractica);
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
   	SiscomRegistrosLog(lzSisRegsRegreso);
   }

return (const char *)0;
}

zOrdenVenta *zSiscomElectronica::ConsultaOrden(const char *pchrPtrIdOrden,
					       const char *pchrPtrIdTipoOrden,
					       zOrdenes **pzOrdenes)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
 AgregaEnvio(zSiscomRegistro().Registro("%s [IdOrden] %s [IdTipoOrden]",
 	     pchrPtrIdOrden,
	     pchrPtrIdTipoOrden));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
      if(lzSisRegsRegreso->NNodos()==1)
      {
      		if((lzSisRegRegreso=lzSisRegsRegreso->Primer()))
      		{
      			SiscomRegistroLog2(lzSisRegRegreso);
      		    if(lzSisRegRegreso->AsociadosDelCampo("Productos"))
		    /* Siscom Ecatepec 
		     * Viernes 12 de abril del 2024 
		     *
      		    return new zOrdenVenta(lzSisRegRegreso); 
		    */
		    return zOrdenVenta().OrdenPorId(lzSisRegRegreso);
      		    else
      		  return 0;
      		}
      		else
      		return 0;
      }
      else
      {
	*pzOrdenes=new zOrdenes;
	AsignandoOrdenes(lzSisRegsRegreso,*pzOrdenes);
	return 0;
      }
   }
   return 0;
}
zDireccion *zSiscomElectronica::Escuela(zSiscomRegistro *pzSisRegEscuela)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
 AgregaEnvio(zSiscomRegistro().Registro("%s [IdEscuela]",(const char *)(*pzSisRegEscuela)["idescuela"]));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
      if((lzSisRegRegreso=lzSisRegsRegreso->Primer()))
      return new zDireccion(lzSisRegRegreso);
      else
      return (zDireccion *)0;
   }
   else
   return (zDireccion *)0;
	
}
int zSiscomElectronica::ReporteVentas(const char *pchrPtrIdExpendio,
				      const char *pchrPtrFechaInicio,
				      const char *pchrPtrFechaFin,
				      char *pchrPtrDesEstadoReporte,
				      zReporteVentas *pzRepVentas)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
 AgregaEnvio(zSiscomRegistro().
 	     Registro("%s [IdExpendio] %s [FechaInicio] %s [FechaFin]",
	     		pchrPtrIdExpendio,
		      pchrPtrFechaInicio,
		      pchrPtrFechaFin));
 
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
      if((lzSisRegRegreso=lzSisRegsRegreso->Primer()))
      {
	SiscomRegistroLog2(lzSisRegRegreso);
	if(lzSisRegRegreso->EstaElCampoEnElRegistro("Estado"))
	{
           strcpy(pchrPtrDesEstadoReporte,(const char *)lzSisRegRegreso->Campo("Descripcion"));
	   return 0;
	}
	else
	pzRepVentas->Reportes(lzSisRegRegreso);

	return 1;
      }
      return 1;
   }
   else
   return 0;


}


int zSiscomElectronica::VentasSiscom(const char *pchrPtrFechaInicio,
				      const char *pchrPtrFechaFin,
				      zReporteVentas *pzRepVentas)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
 AgregaEnvio(zSiscomRegistro().
 	     Registro("%s [FechaInicio] %s [FechaFin]",
		      pchrPtrFechaInicio,
		      pchrPtrFechaFin));
 			
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
      if((lzSisRegRegreso=lzSisRegsRegreso->Primer()))
      {
	SiscomRegistroLog2(lzSisRegRegreso);
	return 1;
      }
     return 1;
   }
   else
   return 0;
}

void zSiscomElectronica::ProcesaErrorCambioDatosOrdenVenta(zSiscomRegistro *pzSiscomRegistro,
							   zOrdenVenta *pzOrdenVenta)
{
  ErrorCambioDatosOrdenVenta[0]=0;
  ErrorCambioDatosOrdenVenta[1]=&zSiscomElectronica::CambiaNoJuegos;
  ErrorCambioDatosOrdenVenta[3]=&zSiscomElectronica::NoSePuedeVenderPorNoTenerPrecio;
  (this->*ErrorCambioDatosOrdenVenta[pzSiscomRegistro->CampoInt("Estado")])(pzOrdenVenta); 
}
void zSiscomElectronica::CambiaNoJuegos(zOrdenVenta *pzOrdenVenta)
{
  pzOrdenVenta->JuegosNuevo(pzOrdenVenta->Juegos());
}

void zSiscomElectronica::NoSePuedeVenderPorNoTenerPrecio(zOrdenVenta *pzOrdenVenta)
{
  pzOrdenVenta->Producto(0)->SePuedeVender("0");
  SiscomRegistroLog2(pzOrdenVenta->Producto(0));
  LogSiscom("Se Puede Vender (%s)",(*pzOrdenVenta->Producto(0))["SePuedeVender"]);
}

int zSiscomElectronica::ValidaExistenciaATransferir(const char *pchrPtrCantidad,
						    const char *pchrPtrCantidadComprada,
						    const char *pchrPtrCveProducto,
						    const char **pchrPtrMensaje)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
	AgregaEnvio(zSiscomRegistro().Registro("%s [Cantidad] "
					       "%s [CantidadComprada] "
					       "%s [CveProducto]",
					      pchrPtrCantidad,
					      pchrPtrCantidadComprada,
					      pchrPtrCveProducto));
	if(lzSisRegsRegreso=EnviaRecibe())
	{
		lzSisRegEstado=(*lzSisRegsRegreso)[0];
		SiscomRegistroLog2(lzSisRegEstado);
		*pchrPtrMensaje=(const char *)(*lzSisRegEstado)["Mensaje"];
		return lzSisRegEstado->CampoInt("Estado");
	}
	else
	return 0;
}
int zSiscomElectronica::ExistenciaExpendioOrigenDestino(const char *pchrPtrIdExpendioO,
							 const char *pchrPtrIdExpendioD,
							 zSiscomRegistro *pzSisRegProducto,
							 zSiscomRegistro **pzSisRegExistencias)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
	AgregaEnvio(
	 zSiscomRegistro().Registro("%s [IdExpendioO] %s [IdExpendioD] %s [CveProducto]",
	 pchrPtrIdExpendioO,
	 pchrPtrIdExpendioD,
	 (*pzSisRegProducto)["cveproducto"]));
if((lzSisRegsRegreso=EnviaRecibe()))
{
     lzSisRegEstado=(*lzSisRegsRegreso)[0];
     *pzSisRegExistencias=lzSisRegEstado;
     if((*pzSisRegExistencias)->EstaElCampoEnElRegistro("EdoConexion"))
	 return -1;
     else
     return (*pzSisRegExistencias)->CampoInt("SePuedeTransferir");
}
return 0;
}
int zSiscomElectronica::ValidandoTransferenciaExpendioOrigen(zSiscomRegistro *pzSisRegEnvio)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
	AgregaEnvio(pzSisRegEnvio);
if((lzSisRegsRegreso=EnviaRecibe()))
{
     lzSisRegEstado=(*lzSisRegsRegreso)[0];
     pzSisRegEnvio->ActualizaCampo("SePuedeTransferir",(*lzSisRegEstado)["SePuedeTransferir"]);
     SiscomRegistroLog2(lzSisRegEstado);
     return lzSisRegEstado->CampoInt("SePuedeTransferir");
}
return 0;


}

void zSiscomElectronica::TransfiereProductosExpendioExpendio(zProductosTransferir *pzProdsTransferir)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
	AgregaEnvio(pzProdsTransferir);
	if((lzSisRegsRegreso=EnviaRecibe()))
	{
	     lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	     SiscomRegistroLog2(lzSisRegRegreso);
	}
}

zSiscomRegistros *zSiscomElectronica::ProductosTransferenciaOtrosExpendios()
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(zSiscomRegistro().Registro("%s [Fecha] ",(const char *)0));
   if((lzSisRegsRegreso=EnviaRecibe()))
	return lzSisRegsRegreso;
    else
    return 0;
}
void zSiscomElectronica::ImprimeTransferenciaOtrosExpendios()
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(zSiscomRegistro().Registro("%s [Fecha] ",(const char *)0));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {

   }
}

void zSiscomElectronica::RegistraImpreso(zCircuitoImpreso *pzCircuitoImpreso)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(pzCircuitoImpreso);
   if((lzSisRegsRegreso=EnviaRecibe()))
   {

	     lzSisRegEstado=(*lzSisRegsRegreso)[0];
	     SiscomRegistroLog2(lzSisRegEstado);
   }
}
void zSiscomElectronica::CircuitosImpresosRegistrados(zSiscomRegistros **pzSisRegsImpresosR)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(zSiscomRegistro().Registro("%s [Fecha] ",(const char *)0));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
	*pzSisRegsImpresosR=lzSisRegsRegreso;
   }
}
void zSiscomElectronica::CircuitosImpresosPorEstadoFecha(const char *pchrPtrFechaInicio,
						     const char *pchrPtrFechaFin,
						     zSiscomRegistro *pzSisRegEstado,
						     zSiscomRegistros **pzSisRegsImpresosR)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(zSiscomRegistro().Registro("%s [FechaInicio] "
   					  "%s [FechaFin]    "
					  "%s [IdEstado] ", 
   					  pchrPtrFechaInicio,
					  pchrPtrFechaFin,
					  (const char *)(*pzSisRegEstado)["idestado"]));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
	*pzSisRegsImpresosR=lzSisRegsRegreso;
   }
}

void zSiscomElectronica::CircuitoImpresoActualizaEstado(zSiscomRegistro *pzSisRegEstado,
						       zSiscomRegistro *pzSisRegImpreso)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(zSiscomRegistro().Registro("%s [IdImpreso] "
					  "%s [IdEstado] ", 
					  (const char *)(*pzSisRegImpreso)["idimpreso"],
					  (const char *)(*pzSisRegEstado)["idestado"]));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
   }
}

void zSiscomElectronica::RegistraOrdenCompra(zOrdenCompra *pzOrdCompra)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(pzOrdCompra);
   if((lzSisRegsRegreso=EnviaRecibe()))
   {

   }

}
/* Falta identificar aqui, como se realizara
 * la consulta de empresa o personas fisicas
 */
void zSiscomElectronica::DatosParaReEnvioFactura(const char *pchrPtrIdFactura,
						zDatosReEnvioFactura **pzDatReEnvFactura)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(zSiscomRegistro().Registro("%s [IdFactura] ",pchrPtrIdFactura));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
	*pzDatReEnvFactura=(zDatosReEnvioFactura *)(*lzSisRegsRegreso)[0];
	(*pzDatReEnvFactura)->Inicia();
   }


}
void zSiscomElectronica::ReEnviaFactura(const char *pchrPtrIdFactura,
				       const char *pchrPtrCorreo,
				       zSiscomRegistro **pzSisRegEdoReEnvio)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(zSiscomRegistro().Registro("%s [IdFactura] %s [Correo] ",
   					  pchrPtrIdFactura,
					  pchrPtrCorreo));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
	*pzSisRegEdoReEnvio=(*lzSisRegsRegreso)[0];
   }
}

void zSiscomElectronica::RegistraClaveSat(zClaveSat *pzClaveSat)
{
     AgregaEnvio(pzClaveSat);
     EnviaRecibe();
}

int zSiscomElectronica::ClaveSat(const char *pchrPtrClave,
				 zClaveSat *pzClaveSat)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(zSiscomRegistro().Registro("%s [Clave] ",pchrPtrClave));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
   	lzSisRegEstado=(*lzSisRegsRegreso)[0];
	SiscomRegistroLog2(lzSisRegEstado);
	if(!lzSisRegEstado->EstaElCampoEnElRegistro("Estado"))
	{
	pzClaveSat->Id((const char *)(*lzSisRegEstado)["id"]);
	pzClaveSat->Clave((const char *)(*lzSisRegEstado)["clave"]);
	pzClaveSat->Sat((const char *)(*lzSisRegEstado)["sat"]);
	pzClaveSat->PalabraClave((const char *)(*lzSisRegEstado)["palabrasclave"]);
	return 1;
	}
	else
	return 0;
   }
   else
   return 0;
}

int zSiscomElectronica::PedidoExpendioHoy(const char *pchrPtrIdExpendio,
					  zPedidoExpendio *pzPedidoExpendio)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(zSiscomRegistro().Registro("%s [IdExpendio] ",pchrPtrIdExpendio));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
   	lzSisRegEstado=(*lzSisRegsRegreso)[0];
	if(lzSisRegEstado->EstaElCampoEnElRegistro("Estado"))
	return 100;
	else
	{
	   pzPedidoExpendio->Pedido(lzSisRegEstado->AsociadoDelCampo("PedidoExpendio"));
	   pzPedidoExpendio->Productos(lzSisRegEstado->AsociadosDelCampo("DetallePedidoExpendio"));
	   return 0;
	}
   }
   else
   return 100;
}
int zSiscomElectronica::IniciaPedidoExpendioHoy(const char *pchrPtrIdExpendio)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(zSiscomRegistro().Registro("%s [IdExpendio] ",pchrPtrIdExpendio));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
	return 0;
   }
   else
   return 100;
}

int zSiscomElectronica::ActualizaObservacionesPedido(zPedidoExpendio *pzPedExpendio,
						     const char *pchrPtrObservaciones)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(zSiscomRegistro().Registro("%s [IdPedido] %s [Observaciones] ",
   					  pzPedExpendio->IdPedido(),
					  pchrPtrObservaciones));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
	return 0;
   }
   else
   return 100;
}

int zSiscomElectronica::ProductoAPedidoExpendioHoy(zProductoPedido *pzProdPedido)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(pzProdPedido);
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
	return 0;
   }
   else
   return 100;
}
int zSiscomElectronica::EliminaProductoPedido(const char *pchrPtrIdProducto,
					      const char *pchrPtrIdPedido)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(zSiscomRegistro().Registro("%s [IdProducto] %s [IdPedido] ",
   					pchrPtrIdProducto,
   					 pchrPtrIdPedido));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
	return 0;
   }
   else
   return 100;
}

int zSiscomElectronica::ActualizaProductoPedido(zProductoPedido *pzProdPedido)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(pzProdPedido);
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
	return 0;
   }
   else
   return 100;
}

int zSiscomElectronica::RegistrandoPedido(zPedidoExpendio *pzPedExpendio)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(pzPedExpendio);
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
	return 0;
   }
   else
   return 100;
}

int zSiscomElectronica::Expendios(zExpendios *pzExpendios)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(zSiscomRegistro().Registro("%s [Expendios] ",
   					 "Expendios"));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
	return 0;
   }
   else
   return 100;
}

int zSiscomElectronica::CierreHoy(zCierreCaja *pzCierreCaja)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(zSiscomRegistro().Registro("%s [CierreCaja] ", "CierreCaja"));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
   	
	return 0;
   }
   else
   return 100;
}

int zSiscomElectronica::InventarioExpendio(const char *pchrPtrIdExpendio,
					   const char *pchrPtrFecha,
					   zProductos *pzProductos)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(zSiscomRegistro().Registro("%s [IdExpendio] %s [Fecha]",
   					  pchrPtrIdExpendio,
					  pchrPtrFecha));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
   	
	return 0;
   }
   else
   return 100;
}



int zSiscomElectronica::Proveedores(zSiscomRegistros **pzSisRegsProveedores)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(zSiscomRegistro().Registro("%s [Proveedores]","Proveedores"));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
        *pzSisRegsProveedores=lzSisRegsRegreso;	
	return 0;
   }
   else
   return 100;
}

int zSiscomElectronica::PesoProducto(zSiscomRegistro *pzSisRegProducto,
				     char *pchrPtrPeso)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(zSiscomRegistro().Registro("%s [CveProducto]",
					  (const char *)(*pzSisRegProducto)["cveproducto"]));
   if(lzSisRegsRegreso=EnviaRecibe())
   {
        if((lzSisRegEstado=(*lzSisRegsRegreso)[0]))
	{
	   strcpy(pchrPtrPeso,(const char *)lzSisRegEstado->Campo("peso"));
	   return 1;
	}
	else
	return 0;
   }
   else
   return 0;
}


int zSiscomElectronica::RegistraPesoProducto(zSiscomRegistro *pzSisRegProducto,
				             const char *pchrPtrPeso)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(zSiscomRegistro().Registro(
   		"%s [CveProducto] %s [Peso]",
   		(const char *)(*pzSisRegProducto)["CveProducto"],
		pchrPtrPeso));
   if(lzSisRegsRegreso=EnviaRecibe())
   /* Se debe validar el regreso, despues de realizar 
    * la insercion del peso del producto
   {
   	
        if((lzSisRegEstado=(*lzSisRegsRegreso)[0]))
	{
 
	return 1;
	}
	else
	return 0;
   }
   else
   return 0;
   */
   return 1;
   else
   return 0;
}
int zSiscomElectronica::ActualizaPesoProducto(zProductoImportado *pzProdImportado)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(pzProdImportado);
   if(lzSisRegsRegreso=EnviaRecibe())
   {
   	/*	
        if((lzSisRegEstado=(*lzSisRegsRegreso)[0]))
	{
 
	return 1;
	}
	else
	return 0;
	*/
	return 1;
   }
   else
   return 0;
}
int zSiscomElectronica::CalculaProductoImportacion(zCompraImportacion *pzComImportacion,
						   char *pchrPtrMensaje)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(pzComImportacion);
   if(lzSisRegsRegreso=EnviaRecibe())
   {
        if((lzSisRegEstado=(*lzSisRegsRegreso)[0]))
	{
	   if(!lzSisRegEstado->EstaElCampoEnElRegistro("Estado"))
	   {
	   pzComImportacion->PesoCompra((const char *)lzSisRegEstado->Campo("PesoCompra"));
	   pzComImportacion->ImporteFactura((const char *)lzSisRegEstado->Campo("ImporteFactura"));
	   pzComImportacion->PonderacionCostoAdministrativo((const char *)lzSisRegEstado->Campo("PonderacionCostoAdministrativo"));
	   pzComImportacion->CostoGrEnvio(lzSisRegEstado->CampoConstChar("CostoGrEnvio"));
	   pzComImportacion->ActualizaProductos(lzSisRegEstado->AsociadosDelCampo("Productos"));
	   return 1;
	   }
	   else
	   {
	    strcpy(pchrPtrMensaje,lzSisRegEstado->CampoConstChar("Descripcion"));	
	    return 0;
	   }

	}
	else
	return 0;
   }
   else
   return 0;
}

int zSiscomElectronica::RegistraCompraImportacion(zCompraImportacion *pzComImportacion)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(pzComImportacion);
   if(lzSisRegsRegreso=EnviaRecibe())
   {
        if((lzSisRegEstado=(*lzSisRegsRegreso)[0]))
	{
	   SiscomRegistroLog2(lzSisRegEstado);
	   return 1;
	}
	else
	return 0;
   }
   else
   return 0;
}
int zSiscomElectronica::RegistroParcialCompraImportacionFaltaronProductos(zCompraParcialImportacion *pzCompraImportacion)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(pzCompraImportacion);
   if(lzSisRegsRegreso=EnviaRecibe())
   {
        if((lzSisRegEstado=(*lzSisRegsRegreso)[0]))
	{
	   SiscomRegistroLog2(lzSisRegEstado);
	   return 1;
	}
	else
	return 0;
   }
   else
   return 0;


}

int zSiscomElectronica::ActualizaCompraImportacionRegistrada(zCompraImportacion *pzCompraImportacion)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(pzCompraImportacion);
   if(lzSisRegsRegreso=EnviaRecibe())
   {
        if((lzSisRegEstado=(*lzSisRegsRegreso)[0]))
	{
	   SiscomRegistroLog2(lzSisRegEstado);
	   return 1;
	}
	else
	return 0;
   }
   else
   return 0;


}



int zSiscomElectronica::ProductosImportadosPorFiltro(const char *pchrPtrFiltro,
						     const char *pchrPtrCantidad,
						     const char *pchrPtrCostoUnitario,
						     const char *pchrPtrPeso,
						    zProductosImportados **pzProdsImportados)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegEstado;
   AgregaEnvio(zSiscomRegistro().Registro("%s [Filtro]",pchrPtrFiltro));
   if(lzSisRegsRegreso=EnviaRecibe())
   {
   	*pzProdsImportados=(zProductosImportados *)lzSisRegsRegreso;
	(*pzProdsImportados)->ProductosFiltrados(pchrPtrCantidad,
						 pchrPtrCostoUnitario,
						 pchrPtrPeso,
						 lzSisRegsRegreso);
	return 1;
   }
   else
   return 0;


}

int zSiscomElectronica::CierreDia(const char *pchrPtrIdExpendio,
				      const char *pchrPtrFechaInicio,
				      const char *pchrPtrFechaFin,
				      zReporteVentas *pzRepVentas)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
 AgregaEnvio(zSiscomRegistro().
 	     Registro("%s [IdExpendio] %s [FechaInicio] %s [FechaFin]",
	     		pchrPtrIdExpendio,
		      pchrPtrFechaInicio,
		      pchrPtrFechaFin));
 			
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
   	lzSisRegRegreso=(*lzSisRegsRegreso)[0];
   	SiscomRegistrosLog(lzSisRegsRegreso);
	pzRepVentas->CierreDia(lzSisRegRegreso);
	return 1;
   }
   else
   return 0;


}

zClienteSiscom *zSiscomElectronica::OrdenEscuelaPrincipal(const char *pchrPtrIdExpendio)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
zClienteSiscom *lzCliSiscom;
 AgregaEnvio(zSiscomRegistro().Registro("%s [IdExpendio] ", pchrPtrIdExpendio));
 			
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
   	lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	lzCliSiscom=new zClienteSiscom(lzSisRegRegreso->AsociadoDelCampo("PublicoEnGeneral"));
	lzCliSiscom->Escuela(lzSisRegRegreso->AsociadoDelCampo("Escuela"));
	return lzCliSiscom;
   }
   else
   return 0;

}

zClienteSiscom *zSiscomElectronica::OrdenOtro(const char *pchrPtrIdExpendio)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
zClienteSiscom *lzCliSiscom;
 AgregaEnvio(zSiscomRegistro().Registro("%s [IdExpendio] ", pchrPtrIdExpendio));
 			
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
   	lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	lzCliSiscom=new zClienteSiscom(lzSisRegRegreso->AsociadoDelCampo("PublicoEnGeneral"));
	lzCliSiscom->Escuela(lzSisRegRegreso->AsociadoDelCampo("Escuela"));
	return lzCliSiscom;
   }
   else
   return 0;

}
void zSiscomElectronica::ClientesMayoreo(zSiscomRegistros **pzSisRegsClientesMay)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
zClienteSiscom *lzCliSiscom;
 AgregaEnvio(zSiscomRegistro().Registro("%s [Mayoreo] ", ""));
 			
   if((lzSisRegsRegreso=EnviaRecibe()))
	*pzSisRegsClientesMay=lzSisRegsRegreso;
}
zClienteSiscom *zSiscomElectronica::ClientePublicoEnGeneral(zSiscomConexion *pzSisConexion)
{
zSiscomRegistro *lzSisRegPEGeneral;
zSiscomElectronica lzSisElectronica(pzSisConexion,"PublicoEnGeneral");
if((lzSisRegPEGeneral=lzSisElectronica.PublicoEnGeneral()))
return new zClienteSiscom(lzSisRegPEGeneral);
else
return (zClienteSiscom *)0;
}

void zSiscomElectronica::DefinicionProducto(zProducto *pzProdSiscom)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
zClienteSiscom *lzCliSiscom;
 AgregaEnvio(pzProdSiscom);
 			
   if((lzSisRegsRegreso=EnviaRecibe()))
       pzProdSiscom->DefinicionProducto(lzSisRegsRegreso);
}


void zSiscomElectronica::ComprandoProductoSiscom(zProductoSiscom *pzProdSiscom)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
zClienteSiscom *lzCliSiscom;
 AgregaEnvio(pzProdSiscom);
 			
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
      lzSisRegRegreso=(*lzSisRegsRegreso)[0];
      SiscomRegistrosLog(lzSisRegsRegreso);
      pzProdSiscom->ActualizaProductos(lzSisRegRegreso->AsociadosDelCampo("Productos"));
      pzProdSiscom->NoAlcanza(lzSisRegRegreso->EstaElCampoEnElRegistro("AlgunoNoAlcanza") ? 1:0);
   }
}


void zSiscomElectronica::ValidandoCompraProductoSiscom(zProductoSiscom *pzProdSiscom)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
zClienteSiscom *lzCliSiscom;
 AgregaEnvio(pzProdSiscom);
 			
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
      lzSisRegRegreso=(*lzSisRegsRegreso)[0];
      pzProdSiscom->ActualizaProductos(lzSisRegRegreso->AsociadosDelCampo("Productos"));
      pzProdSiscom->NoAlcanza(lzSisRegRegreso->EstaElCampoEnElRegistro("AlgunoNoAlcanza") ? 1:0);
   }
}

const char *zSiscomElectronica::IdCompraProductoSiscom()
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
 AgregaEnvio(zSiscomRegistro().Registro("%s [Nada]","Nada"));
 			
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
      lzSisRegRegreso=(*lzSisRegsRegreso)[0];
      SiscomRegistrosLog(lzSisRegsRegreso);
      return (const char *)(*lzSisRegRegreso)["IdCompra"];
   }
   else
   return (const char *)0;
}

int zSiscomElectronica::Practica(zSiscomRegistro *pzSisRegPractica,
				 zPractica *pzPractica)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
 AgregaEnvio(pzSisRegPractica);
 			
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
      lzSisRegRegreso=(*lzSisRegsRegreso)[0];
      pzPractica->Practica(lzSisRegRegreso);
      SiscomRegistroLog2(lzSisRegRegreso);
      return 1;
   }
   else
   return 0;
}

int zSiscomElectronica::ConsultaCompraImportacion(const char *pchrPtrIdCompra,
			         zCompraImportacion *pzCompraImportacion,
				 char *pchrPtrMensaje)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
 AgregaEnvio(zSiscomRegistro().Registro("%s [IdCompra]",pchrPtrIdCompra));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
      lzSisRegRegreso=(*lzSisRegsRegreso)[0];
      if(lzSisRegRegreso->EstaElCampoEnElRegistro("Estado"))
      {
        strcpy(pchrPtrMensaje,lzSisRegRegreso->CampoConstChar("Descripcion"));
        return 1;
      }
      else
      {
      if(lzSisRegRegreso->AsociadoDelCampo("Compra"))
      AsignaCompraImportacion(lzSisRegRegreso->AsociadoDelCampo("Compra"),pzCompraImportacion);
      if(lzSisRegRegreso->AsociadosDelCampo("DetalleCompra"))
      AsignaProductosImportados(lzSisRegRegreso->AsociadosDelCampo("DetalleCompra"),pzCompraImportacion);
      if(lzSisRegRegreso->AsociadosDelCampo("ProveedoresCompra"))
      AsignaProveedoresCompraImportacion(lzSisRegRegreso->AsociadosDelCampo("ProveedoresCompra"),pzCompraImportacion);
      return 0;
      }
   }
   else
   {
   strcpy(pchrPtrMensaje,"NO Se encontrol la compra");
   return 0;
   }
}
int zSiscomElectronica::ConsultaComprasImportacion(const char *pchrPtrFechaIni,
						   const char *pchrPtrFechaFin,
						   zComprasImportacion *pzCompsImportacion)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
 AgregaEnvio(zSiscomRegistro().Registro("%s [FechaIni] %s [FechaFin]",
 				        pchrPtrFechaIni,pchrPtrFechaFin));
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
      lzSisRegRegreso=(*lzSisRegsRegreso)[0];
      AsignaComprasImportacion(lzSisRegRegreso->AsociadosDelCampo("Compra"),pzCompsImportacion);
      return 0;
   }
   else
   return 0;

}
int zSiscomElectronica::GuardaCompraImportacion(zCompraImportacion *pzCompraImportacion)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
 AgregaEnvio(pzCompraImportacion);
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
      
      lzSisRegRegreso=(*lzSisRegsRegreso)[0];
      pzCompraImportacion->IdCompraImportacion(lzSisRegRegreso->CampoConstChar("IdCompraImportacion"));

      return 1;
   }
   else
   return 0;
}

int zSiscomElectronica::GuardaCompraImportacionComo(zCompraImportacion *pzCompraImportacion)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
 AgregaEnvio(pzCompraImportacion);
   if((lzSisRegsRegreso=EnviaRecibe()))
   {
      SiscomRegistroLog2((*lzSisRegsRegreso)[0]); 
      lzSisRegRegreso=(*lzSisRegsRegreso)[0];
      pzCompraImportacion->IdCompraImportacion((const char *)(*lzSisRegRegreso)["IdCompraImportacion"]);
      return 1;
   }
   else
   return 0;
}
zProductoImportado *zSiscomElectronica::FormaProductoImportado(zSiscomRegistro *pzSisRegProducto)
{
zProductoImportado *lzProdImportado;
lzProdImportado=new zProductoImportado(pzSisRegProducto);
lzProdImportado->Cantidad((const char *)(*pzSisRegProducto)["cantidad"]);
lzProdImportado->Peso((const char *)(*pzSisRegProducto)["peso"]);
lzProdImportado->CostoUnitarioDolares((const char *)(*pzSisRegProducto)["costounitario"]);
lzProdImportado->CveProveedor((const char *)(*pzSisRegProducto)["cveproveedor"]);
lzProdImportado->IdProveedor((const char *)(*pzSisRegProducto)["idempresa"]);
lzProdImportado->RazonSocial((const char *)(*pzSisRegProducto)["razonsocial"]);
return lzProdImportado;
}
void zSiscomElectronica::AsignaProveedoresCompraImportacion(
				zSiscomRegistros *pzSisRegsFacsCompraImp,
				zCompraImportacion *pzCompraImp)
{
 
 pzCompraImp->AgregaProveedores(pzSisRegsFacsCompraImp);

}
							
void zSiscomElectronica::AsignaProductosImportados(zSiscomRegistros *pzSisRegsDetCompra,
						 zCompraImportacion *pzCompraImp)
{
zSiscomRegistro *lzSisRegCompra;
zProductoImportado *lzProdImportado;
zProductosImportados *lzProdsImportados=new zProductosImportados;

for(lzSisRegCompra=pzSisRegsDetCompra->Primer();
    lzSisRegCompra;
    lzSisRegCompra=pzSisRegsDetCompra->Siguiente())
{
  lzProdsImportados->Agrega(FormaProductoImportado(lzSisRegCompra));
}
pzCompraImp->AsociadosAlCampo("Productos",lzProdsImportados);
}
						 
void zSiscomElectronica::AsignaCompraImportacion(zSiscomRegistro *pzSisRegComImp,
						 zCompraImportacion *pzCompraImp)
{
pzCompraImp->IdCompraImportacion((const char *)(*pzSisRegComImp)["idcompraimportacion"]);
pzCompraImp->CostoEnvio((const char *)(*pzSisRegComImp)["costoenviodolares"]);
pzCompraImp->CostoDolar((const char *)(*pzSisRegComImp)["costodolar"]);
pzCompraImp->CostoAdministrativo((const char *)(*pzSisRegComImp)["costoadministrativo"]);
pzCompraImp->PonderacionCostoAdministrativo((const char *)(*pzSisRegComImp)["ponderacioncostoadministrativo"]);
pzCompraImp->NumPartidas((const char *)(*pzSisRegComImp)["numeropartidas"]);
pzCompraImp->PesoCompra((const char *)(*pzSisRegComImp)["pesocompra"]);
pzCompraImp->ImporteFactura((const char *)(*pzSisRegComImp)["importefactura"]);
pzCompraImp->NumFactura((const char *)(*pzSisRegComImp)["numerofactura"]);
pzCompraImp->Descripcion((const char *)(*pzSisRegComImp)["descripcion"]);
pzCompraImp->Empresa(zEmpresa::DeConsultaEmpresas(pzSisRegComImp));
}

int zSiscomElectronica::ActualizaInventarioParaPedido(const char *pchrPtrIdExpendio,
						      const char *pchrPtrCveProducto,
						      const char *pchrPtrCantidad)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
LogSiscom("Actualizando Inventario %s %s",pchrPtrCveProducto,pchrPtrCantidad);
AgregaEnvio(zSiscomRegistro().Registro("%s [CveProducto] %s [Cantidad] %s [IdExpendio]",
	                               pchrPtrCveProducto,
				       pchrPtrCantidad,
				       pchrPtrIdExpendio));
if((lzSisRegsRegreso=EnviaRecibe()))
  {
        lzSisRegRegreso=(*lzSisRegsRegreso)[0];
  }

return 0;
}



int zSiscomElectronica::TransfiereBodegaAExpendioParaPedido(const char *pchrPtrIdExpendio,
							  const char *pchrPtrIdEmpleado,
							  const char *pchrPtrIdBodega,
						          const char *pchrPtrCveProducto,
						          const char *pchrPtrCantidad,
							  zSiscomRegistro **pzSisRegRegreso)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [IdExpendio] "
				       "%s [IdEmpleado] "
				       "%s [IdBodega] "
                                       "%s [CveProducto] "
				       "%s [Cantidad]",
				       pchrPtrIdExpendio,
				       pchrPtrIdEmpleado,
				       pchrPtrIdBodega,
	                               pchrPtrCveProducto,
				       pchrPtrCantidad));
if((lzSisRegsRegreso=EnviaRecibe()))
  {
        *pzSisRegRegreso=(*lzSisRegsRegreso)[0];
	if(*pzSisRegRegreso && (*pzSisRegRegreso)->EstaElCampoEnElRegistro("Error"))
	return (*pzSisRegRegreso)->CampoInt("Estado");
  }

return 0;
}

int zSiscomElectronica::PreciosExpendios(const char *pchrPtrIdExpendioO,
					 const char *pchrPtrIdExpendioD,
					 zPreciosExpendios *pzPreciosE)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [IdExpendioO] "
				       "%s [IdExpendioD]",
				       pchrPtrIdExpendioO,
				       pchrPtrIdExpendioD));
if((lzSisRegsRegreso=EnviaRecibe()))
  {
        lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	SiscomRegistroLog2(lzSisRegRegreso);
	pzPreciosE->Precios(pchrPtrIdExpendioO,lzSisRegRegreso->AsociadosDelCampo("PreciosO"));
	pzPreciosE->Precios(pchrPtrIdExpendioD,lzSisRegRegreso->AsociadosDelCampo("PreciosD"));
  }
return 0;
}
int zSiscomElectronica::Precios2Productos(zEmpresa *pzExpendioO,
					 zEmpresa *pzExpendioD,
					 zPrecios2Productos *pzPrecios2Prods)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [IdExpendioO] "
				       "%s [IdExpendioD]",
				       (const char *)(*pzExpendioO)["IdEmpresa"],
				       (const char *)(*pzExpendioD)["IdEmpresa"]));
if((lzSisRegsRegreso=EnviaRecibe()))
  {
        lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	SiscomRegistroLog2(lzSisRegRegreso);
  }
return 0;
}

int zSiscomElectronica::CotizacionesImportacion(zCotizacionesImportacion *pzCotizacionesImp)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [Cotizaciones] ","Todas"));

if((lzSisRegsRegreso=EnviaRecibe()))
  {
	//SiscomRegistrosLog(lzSisRegsRegreso);
	pzCotizacionesImp->AgregaCotizaciones(lzSisRegsRegreso);
	//SiscomRegistrosLog(pzCotizacionesImp);

  }
return 0;
}

int zSiscomElectronica::RegistrandoCotizacionImportacion(zCotizacionImportacion *pzCotizacionImp)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzCotizacionImp);
if((lzSisRegsRegreso=EnviaRecibe()))
  {
        lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	SiscomRegistroLog2(lzSisRegRegreso);
	if(!lzSisRegRegreso->CampoInt("Estado"))
	{
	 pzCotizacionImp->IdCotizacion((const char *)(*lzSisRegRegreso)["IdCotizacion"]);
	return 1;
	}
  }
return 0;
}

int zSiscomElectronica::RegistraProductoCotizaImportacion(zCotizacionImportacion *pzCotizacionImp)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzCotizacionImp);
if((lzSisRegsRegreso=EnviaRecibe()))
  {
  	lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	pzCotizacionImp->PesoTotalProductos(lzSisRegRegreso->AsociadosDelCampo("Productos"));
	pzCotizacionImp->ImporteProductos(lzSisRegRegreso->AsociadosDelCampo("Productos"));
	pzCotizacionImp->ImporteTotal((const char *)(*lzSisRegRegreso)["ImporteTotal"]);
	pzCotizacionImp->PesoTotal((const char *)(*lzSisRegRegreso)["PesoTotal"]);
  }
return 0;
}
int zSiscomElectronica::SeleccionoCotizacionImportacion(zCotizacionImportacion *pzCotizacionImp)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzCotizacionImp);
if((lzSisRegsRegreso=EnviaRecibe()))
pzCotizacionImp->Agrega(lzSisRegsRegreso);
return 0;
}

int zSiscomElectronica::Direcciones(zClienteSiscom *pzCliSiscom,
				    zDirecciones *pzDirecciones)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [IdPersona]",
				       pzCliSiscom->IdPersona()));
if((lzSisRegsRegreso=EnviaRecibe()))
  {
        lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	SiscomRegistroLog2(lzSisRegRegreso);
  }
return 0;
}


zSiscomRegistros *zSiscomElectronica::RFCs(const char *pchrPtrCriterio)
{
AgregaEnvio(zSiscomRegistro().Registro("%s [Criterio]",pchrPtrCriterio));
return EnviaRecibe();
}

zSiscomRegistros *zSiscomElectronica::FormasPagoSat(const char *pchrPtrCriterio)
{
AgregaEnvio(zSiscomRegistro().Registro("%s [Criterio]",pchrPtrCriterio));
return EnviaRecibe();
}

zSiscomRegistros *zSiscomElectronica::MetodoPagoSat(const char *pchrPtrCriterio)
{
AgregaEnvio(zSiscomRegistro().Registro("%s [Criterio]",pchrPtrCriterio));
return EnviaRecibe();
}

zSiscomRegistros *zSiscomElectronica::RegimenFiscal(const char *pchrPtrCriterio)
{
AgregaEnvio(zSiscomRegistro().Registro("%s [Criterio]",pchrPtrCriterio));
return EnviaRecibe();
}


zSiscomRegistros *zSiscomElectronica::UsoFacturaSat(const char *pchrPtrCriterio)
{
AgregaEnvio(zSiscomRegistro().Registro("%s [Criterio]",pchrPtrCriterio));
return EnviaRecibe();
}

void zSiscomElectronica::AsignaComprasImportacion(zSiscomRegistros *pzSisRegsComImp,
						  zComprasImportacion *pzCompsImportacion)
{
zSiscomRegistro *lzSisRegCompra;
zCompraImportacion *lzComImportacion;
for(lzSisRegCompra=pzSisRegsComImp->Primer();
    lzSisRegCompra;
    lzSisRegCompra=pzSisRegsComImp->Siguiente())
{
    lzComImportacion=new zCompraImportacion;
    AsignaCompraImportacion(lzSisRegCompra,lzComImportacion);
    (*pzCompsImportacion) << lzComImportacion;
}
}
		
int zSiscomElectronica::Devolucion(zDevolucion *pzDevolucion)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzDevolucion);
if((lzSisRegsRegreso=EnviaRecibe()))
  {
        lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	SiscomRegistroLog2(lzSisRegRegreso);
  }
return 0;
}


int zSiscomElectronica::RegistraClavesProveedor(zClavesProveedor *pzClavesProveedor)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzClavesProveedor);
if((lzSisRegsRegreso=EnviaRecibe()))
  {
        lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	SiscomRegistroLog2(lzSisRegRegreso);
  }
return 0;
}

int zSiscomElectronica::ValidaClaveRegistrada(zSiscomRegistro *pzSisRegProducto,
					      zSiscomRegistro *pzSisRegProveedor,
					      zClaveProveedor **pzClaveProveedor)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [Clave] %s [IdEmpresa]",
	                               (*pzSisRegProducto)["cveproducto"],
				       (*pzSisRegProveedor)["idempresa"]));
if((lzSisRegsRegreso=EnviaRecibe()))
  {
        lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	if(lzSisRegRegreso->CampoInt("EdoConsulta"))
	*pzClaveProveedor=new zClaveProveedor(lzSisRegRegreso->AsociadoDelCampo("ClaveProveedor"));
	else
	*pzClaveProveedor=0;
	return lzSisRegRegreso->CampoInt("EdoConsulta");
  }
  else
  return 0;
}

int zSiscomElectronica::ProductoCompraImportacion(zSiscomRegistro *pzSisRegProducto,
					          zSiscomRegistro  *pzSisRegProveedor,
						  zProductoCompraImportacion **pzProdComImp)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [Clave] %s [IdEmpresa]",
	                               (*pzSisRegProducto)["cveproducto"],
				       (*pzSisRegProveedor)["idempresa"]));
if((lzSisRegsRegreso=EnviaRecibe()))
  {
        lzSisRegRegreso=(*lzSisRegsRegreso)[0];
        *pzProdComImp=zProductoCompraImportacion::Producto(lzSisRegRegreso);
        return 1;
  }
  else
  return 0;
}

int zSiscomElectronica::CalculaPesoImporteTotal(zProductoCompraImportacion *pzProdComImp)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzProdComImp);
if((lzSisRegsRegreso=EnviaRecibe()))
  {
        lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	pzProdComImp->PrecioTotal((const char *)(*lzSisRegRegreso)["PrecioTotal"]);
	pzProdComImp->PesoTotal((const char *)(*lzSisRegRegreso)["PesoTotal"]);
	SiscomRegistroLog2(pzProdComImp);
        return 1;
  }
  else
  return 0;
}
zSiscomRegistros *zSiscomElectronica::Materias(const char *pchrPtrIdEscuela)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [IdEscuela]",pchrPtrIdEscuela));
if((lzSisRegsRegreso=EnviaRecibe()))
  {
	return lzSisRegsRegreso;
  }
  else
  return 0;
}

zSiscomRegistros *zSiscomElectronica::CajasMaterial()
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
if((lzSisRegsRegreso=EnviaRecibe()))
  {
	return lzSisRegsRegreso;
  }
  else
  return 0;
}
zSiscomRegistros *zSiscomElectronica::Estantes()
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
if((lzSisRegsRegreso=EnviaRecibe()))
  {
	return lzSisRegsRegreso;
  }
  else
  return 0;
}


int zSiscomElectronica::RegistraCajaMaterial(zCajaMaterial *pzCajaMaterial)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzCajaMaterial);
if((lzSisRegsRegreso=EnviaRecibe()))
  {
        lzSisRegRegreso=(*lzSisRegsRegreso)[0];
        return 1;
  }
  else
  return 0;
}
int zSiscomElectronica::AsignaCajaProducto(zSiscomRegistro *pzSisRegProducto)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzSisRegProducto);
if((lzSisRegsRegreso=EnviaRecibe()))
  {
        lzSisRegRegreso=(*lzSisRegsRegreso)[0];
        return 1;
  }
  else
  return 0;
}


int zSiscomElectronica::UbicacionDeLaDescripcion()
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [Productos]","Productos"));
if((lzSisRegsRegreso=EnviaRecibe()))
  {
        lzSisRegRegreso=(*lzSisRegsRegreso)[0];
        return 1;
  }
  else
  return 0;
}
void zSiscomElectronica::FormaPesoProductoImportadoInf(zSiscomRegistro *pzSisRegRegreso,
						       zProductoImportadoInf *pzProdImpInf)
{
 pzProdImpInf->Actualiza(pzSisRegRegreso);

}
void zSiscomElectronica::FormaProductoImportadoInf(
				zSiscomRegistro *pzSisRegRegreso,
				zProductoImportadoInf *pzProdImpInf)
{
FormaPesoProductoImportadoInf(pzSisRegRegreso,pzProdImpInf);
}
int zSiscomElectronica::ProductoImportadoInf(zSiscomRegistro *pzSisRegProducto,
					     zSiscomRegistro *pzSisRegProveedor,
					     zProductoImportadoInf *pzProdImpInf)
{
const char *lchrPtrCveProducto,*lchrPtrIdEmpresa;
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
lchrPtrCveProducto=(const char *)(*pzSisRegProducto)["cveproducto"];
lchrPtrIdEmpresa=(const char *)(*pzSisRegProveedor)["IdEmpresa"];
AgregaEnvio(zSiscomRegistro().Registro("%s [CveProducto] %s [IdEmpresa]",
					lchrPtrCveProducto,
					lchrPtrIdEmpresa));
if((lzSisRegsRegreso=EnviaRecibe()))
  {
        lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	FormaProductoImportadoInf(lzSisRegRegreso,pzProdImpInf);
        return 1;
  }
  else
  return 0;
}

int zSiscomElectronica::RegistraOrdenesFavoritas(zOrdenesFavoritas *pzOrdsFavoritas)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzOrdsFavoritas);
if((lzSisRegsRegreso=EnviaRecibe()))
  {
        lzSisRegRegreso=(*lzSisRegsRegreso)[0];
        return 1;
  }
  else
  return 0;
}
int zSiscomElectronica::ConsultaOrdenesFavoritas(zOrdenesFavoritas *pzOrdsFavoritas)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [IdOrden]","IdOrden"));
if((lzSisRegsRegreso=EnviaRecibe()))
  {
        lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	if(lzSisRegRegreso &&
	   lzSisRegRegreso->AsociadosDelCampo("OrdenesFavoritas"))
	pzOrdsFavoritas->OrdenesFavoritas(lzSisRegRegreso->AsociadosDelCampo("OrdenesFavoritas"));
        return 1;
  }
  else
  return 0;
}
int zSiscomElectronica::EliminaOrdenesFavoritas(zOrdenesFavoritas *pzOrdsFavoritas)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzOrdsFavoritas);
if((lzSisRegsRegreso=EnviaRecibe()))
  {
        lzSisRegRegreso=(*lzSisRegsRegreso)[0];
        return 1;
  }
  else
  return 0;
}
/*
int zSiscomElectronica::CalculaCorteCaja(zCajas *pzCajas)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio((zSiscomRegistros *)pzCajas);
if((lzSisRegsRegreso=EnviaRecibe()))
  {
	pzCajas->Actualiza(lzSisRegsRegreso);
        return 1;
  }
  else
  return 0;
}
*/

int zSiscomElectronica::CalculaCorteCaja(zCorteCaja *pzCorteCaja)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio((zSiscomRegistro *)pzCorteCaja);
if((lzSisRegsRegreso=EnviaRecibe()))
{
        lzSisRegRegreso=(*lzSisRegsRegreso)[0];
  	pzCorteCaja->Cajas()->Actualiza(lzSisRegRegreso->AsociadosDelCampo("Cajas"));
	pzCorteCaja->CorteCaja(lzSisRegRegreso);
        return 1;
 }
  else
  return 0;
}

int zSiscomElectronica::RegistraCambioCaja(zCajas *pzCajas)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio((zSiscomRegistros *)pzCajas);
if((lzSisRegsRegreso=EnviaRecibe()))
  {
	SiscomRegistrosLog(lzSisRegsRegreso);
	pzCajas->Actualiza(lzSisRegsRegreso);
        return 1;
  }
  else
  return 0;
}

int zSiscomElectronica::CalculaCambioPago(const char *pchrPtrPago,
					  const char *pchrPtrImporte,
					  char *pchrPtrCambio,
					  char *pchrPtrDsc)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;


AgregaEnvio(zSiscomRegistro().Registro("%s [Importe] %s [PagaCon]",
					pchrPtrImporte,
					pchrPtrPago));

if((lzSisRegsRegreso=EnviaRecibe()))
  {
    lzSisRegRegreso=(*lzSisRegsRegreso)[0];
	if(!lzSisRegRegreso->CampoInt("Estado"))
	{
	strcpy(pchrPtrDsc,lzSisRegRegreso->CampoConstChar("Descripcion"));
	return 0;
	}
	else
	{
	strcpy(pchrPtrCambio,lzSisRegRegreso->CampoConstChar("Cambio"));
	return 1;
	}
  }
  else
  return 0;
}
void zSiscomElectronica::FormaEscuelas(zSiscomRegistros *pzSisRegsEscuelas,
				       zEscuelas *pzEscuelas)
{
zSiscomRegistro *lzSisRegEscuela;

for(lzSisRegEscuela=pzSisRegsEscuelas->Primer();
    lzSisRegEscuela;
    lzSisRegEscuela=pzSisRegsEscuelas->Siguiente())
   (*pzEscuelas) << new zEscuela(lzSisRegEscuela);
}
int zSiscomElectronica::EntregaEscuela(zEscuelas *pzEscuelas)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [EscuelaEntrega]","EscuelaEntrega"));
if((lzSisRegsRegreso=EnviaRecibe()))
{
   FormaEscuelas(lzSisRegsRegreso,pzEscuelas);
 return 1;
}
else
return 0;
}

int zSiscomElectronica::ActualizaDescripcionCotizacion(zOrdenVenta *pzOrden)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [Descripcion] %s [IdVenta] ",
				       pzOrden->Cotizacion()->Descripcion(),
				       pzOrden->IdVenta()));
if((lzSisRegsRegreso=EnviaRecibe()))
{
 return 1;
}
else
return 0;
}

int zSiscomElectronica::RegistraRegimenFiscal(const char *pchrPtrRfc,
						     const char *pchrPtrRegimen)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [Rfc] %s [Regimen] ",
				   pchrPtrRfc,
				   pchrPtrRegimen));
if((lzSisRegsRegreso=EnviaRecibe()))
{
 return 1;
}
else
return 0;
}

int zSiscomElectronica::ActualizaClaveProveedor4(zClaveProveedor *pzCveProveedor)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzCveProveedor);
if((lzSisRegsRegreso=EnviaRecibe()))
{
 return 1;
}
else
return 0;
}


int zSiscomElectronica::AgregaFacturaContenedor(zContenedor *pzContenedor,
					        zCompraImportacion *pzCompraImp)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzContenedor);
if((lzSisRegsRegreso=EnviaRecibe()))
{
  pzCompraImp->ActualizaProductos(lzSisRegsRegreso);
 return 1;
}
else
return 0;
}

int zSiscomElectronica::CompletaProductosImportacion(zCompraImportacion *pzComImp)
{

zSiscomRegistros *lzSisRegsRegreso,
		 *lzSisRegsProductos;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzComImp);
if((lzSisRegsRegreso=EnviaRecibe()))
{
 lzSisRegRegreso=(*lzSisRegsRegreso)[0];
 lzSisRegsProductos=lzSisRegRegreso->AsociadoDelCampo("Envio")->AsociadosDelCampo("Productos");
 SiscomRegistrosLog(lzSisRegsProductos);
 pzComImp->Productos()->AsignaClave(lzSisRegsProductos);
 pzComImp->ActualizaProductos(lzSisRegsProductos);
 return 1;
}
else
return 0;
}

int zSiscomElectronica::ActualizaPrecioExpendios(zProductoPrecioExpendios *pzPPExpendios)
{

zSiscomRegistros *lzSisRegsRegreso,
		 *lzSisRegsProductos;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzPPExpendios);
if((lzSisRegsRegreso=EnviaRecibe()))
{
 return 1;
}
else
return 0;
}

int zSiscomElectronica::SincronizaProductosExpendio(zListaExpendios *pzLstExpendios)
{
zSiscomRegistros *lzSisRegsRegreso,
		 *lzSisRegsProductos;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzLstExpendios);
if((lzSisRegsRegreso=EnviaRecibe()))
{
 return 1;
}
else
return 0;
}



int zSiscomElectronica::SincronizaPreciosExpendio(zListaExpendios *pzLstExpendios)
{
zSiscomRegistros *lzSisRegsRegreso,
		 *lzSisRegsProductos;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzLstExpendios);
if((lzSisRegsRegreso=EnviaRecibe()))
{
 return 1;
}
else
return 0;
}

int zSiscomElectronica::BodegasExpendios(zBodegas **pzBodegas)
{
zSiscomRegistros *lzSisRegsRegreso,
		 *lzSisRegsProductos;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [Expendio] ","Todos"));
if((lzSisRegsRegreso=EnviaRecibe()))
{
  *pzBodegas=new zBodegas;
   (*pzBodegas)->ObtenBodegasExpendios(lzSisRegsRegreso);
 return 1;
}
else
return 0;
}

int zSiscomElectronica::ExistenciaBodega(zExistenciaBodega *pzExistenciaB)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzExistenciaB);
if((lzSisRegsRegreso=EnviaRecibe()))
{
 lzSisRegRegreso=(*lzSisRegsRegreso)[0];
  pzExistenciaB->Existencia((const char *)(*lzSisRegRegreso)["existencia"]);
 return 1;
}
else
return 0;
}


int zSiscomElectronica::ActualizaExistenciaBodega(zExistenciaBodega *pzExistenciaB)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzExistenciaB);
if((lzSisRegsRegreso=EnviaRecibe()))
{
 lzSisRegRegreso=(*lzSisRegsRegreso)[0];
 SiscomRegistroLog2(lzSisRegRegreso);
 return 1;
}
else
return 0;
}

int zSiscomElectronica::TransfiereBodegaBodega(zTransfiereBodegaBodega *pzTransfiereBB)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzTransfiereBB);
if((lzSisRegsRegreso=EnviaRecibe()))
{
 lzSisRegRegreso=(*lzSisRegsRegreso)[0];
 SiscomRegistroLog2(lzSisRegRegreso);
 return 1;
}
else
return 0;

}
int zSiscomElectronica::SeReflejoTransferencia(const char *pchrPtrEdo,
						const char *pchrPtrIdVenta)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [Estado] %s [IdVenta] ",
				   pchrPtrEdo,
				   pchrPtrIdVenta));
if((lzSisRegsRegreso=EnviaRecibe()))
{
 return 1;
}
else
return 0;

}

int zSiscomElectronica::ClavesProveedor(const char *pchrPtrCveProducto,	
					const char *pchrPtrIdProveedor,
					zClavesProveedor *pzCvesProvedor)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [CveProducto] %s [IdProveedor] ",
				   pchrPtrCveProducto,
				   pchrPtrIdProveedor));
if((lzSisRegsRegreso=EnviaRecibe()))
{
 return 1;
}
else
return 0;
}




int zSiscomElectronica::VerificaConCuantoPago(zConCuantoPago *pzConCuantoPago)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzConCuantoPago);
if((lzSisRegsRegreso=EnviaRecibe()))
{
  lzSisRegRegreso=(*lzSisRegsRegreso)[0];  
  pzConCuantoPago->SiAlcanza((const char *)(*lzSisRegRegreso)["SiAlcanza"]);
  return pzConCuantoPago->SiAlcanzaInt();
}
else return 0;

}


int zSiscomElectronica::CambiosCaja(zCambiosCaja *pzCambiosC)
{
zSiscomRegistros *lzSisRegsRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [Todos]"));
if((lzSisRegsRegreso=EnviaRecibe()))
{
  pzCambiosC->CambiosCaja(lzSisRegsRegreso);
  return 1;
}
else return 0;
}
int zSiscomElectronica::CambioCaja(zCambioCaja *pzCambioC)
{
zSiscomRegistros *lzSisRegsRegreso;
AgregaEnvio(pzCambioC);
if((lzSisRegsRegreso=EnviaRecibe()))
{
  pzCambioC->Dinero(new zDenominaciones(lzSisRegsRegreso));
  return 1;
}
else return 0;
}
int zSiscomElectronica::ValidaExistenciaBodega(const char *pchrPtrCantidad,
					       zExistenciaBodega *pzExistenciaB)
{
zSiscomRegistros *lzSisRegsRegreso;
AgregaEnvio(zSiscomRegistro().Registro(pzExistenciaB,
				       "%s [Cantidad]",
				       pchrPtrCantidad));
if((lzSisRegsRegreso=EnviaRecibe()))
{
  SiscomRegistroLog2((*lzSisRegsRegreso)[0]); 
  return ((*lzSisRegsRegreso)[0])->CampoInt("Estado");
}
else
return 0;
}


int zSiscomElectronica::AbonoAApartado(zAbonoAApartado *pzAbonoAA)
{
zSiscomRegistros *lzSisRegsRegreso;
zSiscomRegistro *lzSisRegRegreso;
AgregaEnvio(pzAbonoAA);
if((lzSisRegsRegreso=EnviaRecibe()))
{
  lzSisRegRegreso=(*lzSisRegsRegreso)[0];  
  return 1;
}
else
return 0;

}
int zSiscomElectronica::ConsultaComprasSiscom(
				     const char *pchrPtrFechaIni,
				     const char *pchrPtrFechaFin,
				     zCompras *pzCompras)
{
zSiscomRegistros *lzSisRegsRegreso;
AgregaEnvio(zSiscomRegistro().Registro("%s [FechaIni] %s [FechaFin]",
	 		             pchrPtrFechaIni,
				     pchrPtrFechaFin));
if((lzSisRegsRegreso=EnviaRecibe()))
{
       pzCompras->Compras(lzSisRegsRegreso);
}
}
