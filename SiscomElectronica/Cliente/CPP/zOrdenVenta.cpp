#include <zOrdenVenta.h> 
#include <zProductoCotizar.h> 
#include <zProductos.h> 
#include <zClienteSiscom.h> 
#include <zApartado.h>
#include <zCotizacion.h>
#include <zPedido.h>
#include <zCircuitoImpreso.h>
#include <zMaterialAAreaDiseno.h>
#include <zDonacionMaterial.h>
#include <zExpendio.h>
#include <zConexionExpendio.h>
#include <zFormaPago.h>

#include <zSiscomCampo.h>
#include <zSiscomRegistros.h>
#include <zSiscomDesarrollo4.h>

#include <string.h>
/* Lunes 26 de Diciembre del 2016
 * IdTipoOrden 
 * 		0 Venta
 * 		1 Cotizacion
 * 		2 Apartado 
 * 		3 Orden En Caja
 * 		4 Pedido
 * 		5 Orden Cancelada
 * 		Miercoles 26 de Julio 2017 
 * 		6 Registro de circuito Impreso
 * 		Domingo 7 de Enero 2017
 * 		7 Orden que se paga con tarjeta
 * 		8 Material a Area de diseno
 * 		9 Donacion de material
 *
 *
 *      Se agrega el campo Forma de pago
 *      FormaPago -> 0 Efectivo
 *		     1 Tarjeta
 * 		
 *	Ecatepec Jueves 14 de Diciembre 2023 
 *
 *		11 Transferencia
 *
 *
 */


/* Tepotzotlan Mexico a 17 de Abril 2022 
 * Agrego el campo de Expendio , para poder
 * realizar el manejo de la orden en memoria, y lograr 
 * en la interfaz grafica integrar la funcionalidad de
 * cambiar la conexion a otro expendio, cuando desde 
 * la GUI, estoy conectado a dos expendios, al realizar
 * el cambio a un expendio remoto, debo actualizar estos
 * datos
 *
 * Debo revisar el cambio del campo IdExpendio, al Campo Expendio
 *
 */
zOrdenVenta::zOrdenVenta(const char *pchrPtrIdVenta,
			 const char *pchrPtrIdExpendio)
{
(*this)									<< 
new zSiscomCampo("IdVenta",(const unsigned char *)pchrPtrIdVenta)	<<
new zSiscomCampo("IdExpendio",(const unsigned char *)pchrPtrIdExpendio)	<<
new zSiscomCampo("IdTipoOrden",(const unsigned char *)"0")		<<
new zSiscomCampo("FormaPago")						<<
new zSiscomCampo("IdVendedor")						<<
new zSiscomCampo("Descripcion")						<<
new zSiscomCampo("Juegos",(const unsigned char *)"1")			<<
new zSiscomCampo("JuegosNuevo",(const unsigned char *)"1")		<<
new zSiscomCampo("JuegosSeparados",(const unsigned char *)"1")		<<
new zSiscomCampo("JuegosNuevoSeparados",(const unsigned char *)"1")	<<
new zSiscomCampo("DescuentoOrden",(const unsigned char *)"0")		<<
new zSiscomCampo("Importe")						<<
new zSiscomCampo("Productos")						<<
new zSiscomCampo("Cliente")						<<
new zSiscomCampo("NumKitsPracticasEtc")					<<
new zSiscomCampo("NumProductos")					<<
new zSiscomCampo("Apartado")						<<
new zSiscomCampo("Cotizacion")						<<
new zSiscomCampo("Pedido")						<<
new zSiscomCampo("CircuitoImpreso")					<<
new zSiscomCampo("MaterialAAreaDiseno")					<<
new zSiscomCampo("DonacionMaterial")					<<
new zSiscomCampo("SeImprimeTicket",(const unsigned char *)"1")		<<
new zSiscomCampo("Fecha")						<<
new zSiscomCampo("Expendio");
}
zOrdenVenta::zOrdenVenta()
{
(*this)									<< 
new zSiscomCampo("IdVenta")						<<
new zSiscomCampo("IdExpendio")						<<
new zSiscomCampo("IdTipoOrden")						<<
new zSiscomCampo("FormaPago")						<<
new zSiscomCampo("IdVendedor")						<<
new zSiscomCampo("Juegos")						<<
new zSiscomCampo("JuegosNuevo")						<<
new zSiscomCampo("DescuentoOrden",(const unsigned char *)"0")		<<
new zSiscomCampo("Importe")						<<
new zSiscomCampo("Productos")						<<
new zSiscomCampo("Cliente")						<<
new zSiscomCampo("NumKitsPracticasEtc") 				<<
new zSiscomCampo("NumProductos")					<<
new zSiscomCampo("Apartado")						<<
new zSiscomCampo("Cotizacion")						<<
new zSiscomCampo("Pedido")						<<
new zSiscomCampo("CircuitoImpreso")					<<
new zSiscomCampo("MaterialAAreaDiseno")					<<
new zSiscomCampo("DonacionMaterial")    				<<
new zSiscomCampo("SeImprimeTicket",(const unsigned char *)"1")		<<
new zSiscomCampo("Fecha")						<<
new zSiscomCampo("Expendio");
}
zOrdenVenta::zOrdenVenta(zSiscomRegistro *pzSisRegOrdenVenta)
{
(*this)									<< 
new zSiscomCampo("IdVenta",(*pzSisRegOrdenVenta)["idventa"])		<<
new zSiscomCampo("IdExpendio")						<<
new zSiscomCampo("IdTipoOrden",(const unsigned char *)"0")		<<
new zSiscomCampo("FormaPago")						<<
new zSiscomCampo("IdVendedor")						<<
new zSiscomCampo("Juegos")						<<
new zSiscomCampo("JuegosNuevo")						<<
new zSiscomCampo("DescuentoOrden",(const unsigned char *)"0")		<<
new zSiscomCampo("Importe",(*pzSisRegOrdenVenta)["importe"])		<<
new zSiscomCampo("Productos")						<<
new zSiscomCampo("Cliente")						<<
new zSiscomCampo("NumKitsPracticasEtc") 				<<
new zSiscomCampo("NumProductos")					<<
new zSiscomCampo("Apartado")						<<
new zSiscomCampo("Cotizacion")						<<
new zSiscomCampo("Pedido")						<<
new zSiscomCampo("CircuitoImpreso")					<<
new zSiscomCampo("MaterialAAreaDiseno")					<<
new zSiscomCampo("DonacionMaterial")					<<
new zSiscomCampo("SeImprimeTicket",(const unsigned char *)"1")		<<
new zSiscomCampo("Fecha",(*pzSisRegOrdenVenta)["fechahora"])		<<
new zSiscomCampo("Expendio");
AsignaOrdenConsultada(pzSisRegOrdenVenta);
AsignaProductos(pzSisRegOrdenVenta->AsociadosDelCampo("Productos"));
if(pzSisRegOrdenVenta->AsociadoDelCampo("Cliente"))
Cliente(new zClienteSiscom(pzSisRegOrdenVenta->AsociadoDelCampo("Cliente")));
if(pzSisRegOrdenVenta->AsociadoDelCampo("Cotizacion"))
Cotizacion(new zCotizacion(pzSisRegOrdenVenta->AsociadoDelCampo("Cotizacion")));
}
zOrdenVenta::zOrdenVenta(zOrdenVenta *pzOrdVenta)
{
(*this)											<< 
new zSiscomCampo("IdVenta",(const unsigned char *)pzOrdVenta->IdVenta())		<<
new zSiscomCampo("IdExpendio",(const unsigned char *)pzOrdVenta->IdExpendio())		<<
new zSiscomCampo("IdTipoOrden",(const unsigned char *)pzOrdVenta->IdTipoOrden())	<<
new zSiscomCampo("FormaPago")								<<
new zSiscomCampo("IdVendedor")								<<
new zSiscomCampo("Juegos",(const unsigned char *)pzOrdVenta->Juegos())			<<
new zSiscomCampo("JuegosNuevo",(const unsigned char *)pzOrdVenta->JuegosNuevo())	<<
new zSiscomCampo("JuegosSeparados",(const unsigned char *)"1")				<<
new zSiscomCampo("JuegosNuevoSeparados",(const unsigned char *)"1")			<<
new zSiscomCampo("DescuentoOrden",(const unsigned char *)pzOrdVenta->DescuentoOrden())	<<
new zSiscomCampo("Importe")								<<
new zSiscomCampo("Productos")								<<
new zSiscomCampo("Cliente",pzOrdVenta->Cliente())					<<
new zSiscomCampo("NumKitsPracticasEtc")							<<
new zSiscomCampo("NumProductos")							<<
new zSiscomCampo("Apartado")								<<
new zSiscomCampo("Cotizacion")								<<
new zSiscomCampo("Pedido")								<<
new zSiscomCampo("CircuitoImpreso")							<<
new zSiscomCampo("MaterialAAreaDiseno")							<<
new zSiscomCampo("DonacionMaterial")							<<
new zSiscomCampo("SeImprimeTicket",(const unsigned char *)"1")				<<
new zSiscomCampo("Fecha")								<<
new zSiscomCampo("Expendio");
}
zOrdenVenta::~zOrdenVenta()
{

}
void zOrdenVenta::AgregaProducto(zProductoCotizar *pzProdCotizar)
{
AsociadoAlCampo("Productos",pzProdCotizar);
}
void zOrdenVenta::Descripcion(const char *pchrPtrDescripcion)
{
   ActualizaCampo("Descripcion",(const unsigned char *)pchrPtrDescripcion); 
}
void zOrdenVenta::ActualizaOrden(zSiscomRegistro *pzSisRegRespuesta)
{
zSiscomRegistro *lzSisRegEnvio;
zSiscomRegistros *lzSisRegsProductos;
lzSisRegEnvio=pzSisRegRespuesta->AsociadoDelCampo("Envio");
if(lzSisRegEnvio)
{
   if((lzSisRegsProductos=lzSisRegEnvio->AsociadosDelCampo("Productos")))
   ActualizaDatosProductos(lzSisRegsProductos);	
   ActualizaCampo("Importe",(*lzSisRegEnvio)["Importe"]);
   ActualizaCampo("NumKitsPracticasEtc",(*lzSisRegEnvio)["NumKitsPracticasEtc"]);
   ActualizaCampo("NumProductos",(*lzSisRegEnvio)["NumProductos"]); 
   ActualizaCampo("Juegos",(*lzSisRegEnvio)["Juegos"]);
   ActualizaCampo("JuegosNuevo",(*lzSisRegEnvio)["JuegosNuevo"]);
   ActualizaCampo("Fecha",(*lzSisRegEnvio)["Fecha"]);
}

}
void zOrdenVenta::ActualizaDatosProductos(zSiscomRegistros *pzSisRegsProdsRespuesta)
{
zSiscomRegistro *lzSisRegProducto;
     for(lzSisRegProducto=pzSisRegsProdsRespuesta->Primer();
         lzSisRegProducto;
	 lzSisRegProducto=pzSisRegsProdsRespuesta->Siguiente())
      ActualizaProducto(lzSisRegProducto);
}
void zOrdenVenta::ActualizaProducto(zSiscomRegistro *pzSisRegProducto)
{
zSiscomRegistros *lzSisRegsProductos=AsociadosDelCampo("Productos");
zSiscomRegistro *lzSisRegProducto;
for(lzSisRegProducto=lzSisRegsProductos->Primer();
    lzSisRegProducto;
    lzSisRegProducto=lzSisRegsProductos->Siguiente())
{
    if(!strcmp((const char *)(*lzSisRegProducto)["IdConsecutivo"],
    	       (const char *)(*pzSisRegProducto)["IdConsecutivo"]))
    {
	lzSisRegProducto->ActualizaCampo("Existencia",(*pzSisRegProducto)["Existencia"]);
	lzSisRegProducto->ActualizaCampo("ExiBodega",(*pzSisRegProducto)["ExiBodega"]);
	lzSisRegProducto->ActualizaCampo("Precio",(*pzSisRegProducto)["Precio"]);
	lzSisRegProducto->ActualizaCampo("Importe",(*pzSisRegProducto)["Importe"]);
	lzSisRegProducto->ActualizaCampo("SePuedeVender",(*pzSisRegProducto)["SePuedeVender"]);
	lzSisRegProducto->ActualizaCampo("IdConsecutivo",(*pzSisRegProducto)["IdConsecutivo"]);
	lzSisRegProducto->ActualizaCampo("PrecioEspecial",(*pzSisRegProducto)["PrecioEspecial"]);
	lzSisRegProducto->AsociadosAlCampo("Productos",pzSisRegProducto->AsociadosDelCampo("Productos"));
    }
}
}

const char *zOrdenVenta::CampoProducto(int pintNProducto,
				       const char *pchrPtrCampo)
{
zSiscomRegistros *lzSisRegsProductos;
zSiscomRegistro *lzSisRegProducto;
if((lzSisRegsProductos=AsociadosDelCampo("Productos")))
   return lzSisRegsProductos->CampoRegistro(pintNProducto,pchrPtrCampo);
else
return (const char *)0;
}
const char *zOrdenVenta::Clave(int pintNProducto)
{
  return CampoProducto(pintNProducto,"Clave");
}

const char *zOrdenVenta::Existencia(int pintNProducto)
{
  return CampoProducto(pintNProducto,"Existencia");
}

const char *zOrdenVenta::ExBodega(int pintNProducto)
{
  return CampoProducto(pintNProducto,"ExiBodega");
}
const char *zOrdenVenta::Precio(int pintNProducto)
{
  return CampoProducto(pintNProducto,"Precio");
}
const char *zOrdenVenta::Importe(int pintNProducto)
{
  return CampoProducto(pintNProducto,"Importe");
}

const char *zOrdenVenta::Cantidad(int pintNProducto)
{
  return CampoProducto(pintNProducto,"Cantidad");
}
const char *zOrdenVenta::Descripcion(int pintNProducto)
{
  return CampoProducto(pintNProducto,"Descripcion");
}
zProductoCotizar *zOrdenVenta::Producto(int pintNProducto)
{
   return (zProductoCotizar *)(*AsociadosDelCampo("Productos"))[pintNProducto];
}
zProductoCotizar *zOrdenVenta::ProductoPorIdConsecutivo(int pintIdConsecutivo)
{
zProductoCotizar *lzProdCotizar;

for(lzProdCotizar=(zProductoCotizar *)AsociadosDelCampo("Productos")->Primer();
    lzProdCotizar;
    lzProdCotizar=(zProductoCotizar *)AsociadosDelCampo("Productos")->Siguiente())
if(lzProdCotizar->CampoInt("IdConsecutivo")==pintIdConsecutivo)
return lzProdCotizar;


return 0;

}
int zOrdenVenta::ProductosCotizados()
{
zSiscomRegistros *lzSisRegsProductos;
int lintNProductos=0;
   if((lzSisRegsProductos=AsociadosDelCampo("Productos")))
   lintNProductos=lzSisRegsProductos->NNodos(); 

   return lintNProductos;
}
const char *zOrdenVenta::ImporteOrden()
{
 return (const char *)(*this)["Importe"];
}
const char *zOrdenVenta::IdVenta()
{
  return (const char *)(*this)["IdVenta"];
}
const char *zOrdenVenta::IdExpendio()
{
  return (const char *)(*this)["IdExpendio"];
}
const char *zOrdenVenta::Juegos()
{
  return (const char *)(*this)["Juegos"];
}
const char *zOrdenVenta::JuegosNuevo()
{
  return (const char *)(*this)["JuegosNuevo"];
}

const char *zOrdenVenta::DescuentoOrden()
{
  return (const char *)(*this)["DescuentoOrden"];
}
int zOrdenVenta::NumKitsPracticasEtc()
{
  return CampoInt("NumKitsPracticasEtc");
}
int zOrdenVenta::NumProductos()
{
  return CampoInt("NumProductos");
}
void zOrdenVenta::AsignaOrdenVenta(zSiscomRegistro *pzSisRegOrden)
{
    ActualizaCampo("Importe",(*pzSisRegOrden)["totalorden"]);
}

void zOrdenVenta::IdVenta(const char *pchrPtrIdVenta)
{
  ActualizaCampo("IdVenta",(const unsigned char *)pchrPtrIdVenta);
}
void zOrdenVenta::Cliente(zClienteSiscom *pzCliSiscom)
{
  ActualizaCampo("Cliente",pzCliSiscom);
}
void zOrdenVenta::NumProductos(int pintNumProductos)
{
   ActualizaCampo("NumProductos",pintNumProductos);
}
zClienteSiscom *zOrdenVenta::Cliente()
{
  return (zClienteSiscom *)AsociadoDelCampo("Cliente");
}
zCircuitoImpreso *zOrdenVenta::CircuitoImpreso()
{
  return (zCircuitoImpreso *)AsociadoDelCampo("CircuitoImpreso");
}
void zOrdenVenta::Juegos(const char *pchrPtrNumJuegos)
{
  ActualizaCampo("Juegos",(const unsigned char *)pchrPtrNumJuegos);
}
void zOrdenVenta::Importe(const char *pchrPtrImporte)
{
  ActualizaCampo("Importe",(const unsigned char *)pchrPtrImporte);
}
void zOrdenVenta::JuegosNuevo(const char *pchrPtrNumJuegos)
{
  ActualizaCampo("JuegosNuevo",(const unsigned char *)pchrPtrNumJuegos);
}

void zOrdenVenta::JuegosSeparados(const char *pchrPtrNumJuegos)
{
  ActualizaCampo("JuegosSeparados",(const unsigned char *)pchrPtrNumJuegos);
}
void zOrdenVenta::JuegosNuevoSeparados(const char *pchrPtrNumJuegos)
{
  ActualizaCampo("JuegosNuevoSeparados",(const unsigned char *)pchrPtrNumJuegos);
}



void zOrdenVenta::DescuentoOrden(const char *pchrPtrDescuentoOrden)
{
  ActualizaCampo("DescuentoOrden",(const unsigned char *)pchrPtrDescuentoOrden);
}
void zOrdenVenta::IdVendedor(const char *pchrPtrIdVendedor)
{
  ActualizaCampo("IdVendedor",(const unsigned char *)pchrPtrIdVendedor);
}
void zOrdenVenta::IdExpendio(const char *pchrPtrIdExpendio)
{
  ActualizaCampo("IdExpendio",(const unsigned char *)pchrPtrIdExpendio);
}

void zOrdenVenta::IdTipoOrden(const char *pchrPtrIdTipoOrden)
{
  ActualizaCampo("IdTipoOrden",(const unsigned char *)pchrPtrIdTipoOrden);
}
void zOrdenVenta::Fecha(const char *pchrPtrFecha)
{
  ActualizaCampo("Fecha",(const unsigned char *)pchrPtrFecha);
}
void zOrdenVenta::Expendio(zConexionExpendio *pzExpendio)
{
  ActualizaCampo("Expendio",pzExpendio);
}

const char *zOrdenVenta::IdTipoOrden()
{
  return (const char *)(*this)["IdTipoOrden"];
}
const char *zOrdenVenta::Descripcion()
{
   return (const char *)(*this)["Descripcion"];
}
int zOrdenVenta::IdTipoOrdenInt()
{
	return CampoInt("IdTipoOrden");
}
const char *zOrdenVenta::Fecha()
{
    return (const char *)(*this)["Fecha"];
}
void zOrdenVenta::Apartado(zApartado *pzApartado)
{
  if(pzApartado)
  AsociadoAlCampo("Apartado",pzApartado);
  else
  ActualizaCampo("Apartado",(const unsigned char *)0);
}
void zOrdenVenta::Cotizacion(zCotizacion *pzCotizacion)
{
  if(pzCotizacion)
  AsociadoAlCampo("Cotizacion",pzCotizacion);
  else
  ActualizaCampo("Cotizacion",(const unsigned char *)0);
}
void zOrdenVenta::Pedido(zPedido *pzPedido)
{
zSiscomRegistro *lzSisRegPedido;

if((lzSisRegPedido=AsociadoDelCampo("Pedido")))
  ActualizaCampo("Pedido",pzPedido);
else
  AsociadoAlCampo("Pedido",pzPedido);
}
void zOrdenVenta::CircuitoImpreso(zCircuitoImpreso *pzCircuitoImpreso)
{
  if(pzCircuitoImpreso)
  AsociadoAlCampo("CircuitoImpreso",pzCircuitoImpreso);
  else
  ActualizaCampo("CircuitoImpreso",(const unsigned char *)0);
}
void zOrdenVenta::MaterialAAreaDiseno(zMaterialAAreaDiseno *pzMatAAreaDiseno)
{
  if(pzMatAAreaDiseno)
  AsociadoAlCampo("MaterialAAreaDiseno",pzMatAAreaDiseno);
  else
  ActualizaCampo("MaterialAAreaDiseno",(const unsigned char *)0);
}
void zOrdenVenta::DonacionMaterial(zDonacionMaterial *pzDonacionM)
{
  if(pzDonacionM)
  AsociadoAlCampo("DonacionMaterial",pzDonacionM);
  else
  ActualizaCampo("DonacionMaterial",(const unsigned char *)0);
}

void zOrdenVenta::SeImprimeTicket(const char *pchrPtrSeImprimeTicket)
{
  ActualizaCampo("SeImprimeTicket",(const unsigned char *)pchrPtrSeImprimeTicket);
}

void zOrdenVenta::FormaPago(zFormaPago *pzFPago)
{
  AsociadoAlCampo("FormaPago",pzFPago);
}

void zOrdenVenta::EliminaProducto(zProductoCotizar *pzProdCotizar)
{
 zSiscomRegistros *lzSisRegsProductos;
 if((lzSisRegsProductos=AsociadosDelCampo("Productos")))
     lzSisRegsProductos->Elimina(pzProdCotizar);
}
void zOrdenVenta::EliminaProductos(zProductos *pzProductos)
{
zProductoCotizar *lzProducto;
 for(lzProducto=(zProductoCotizar*)pzProductos->Primer();
     lzProducto;
     lzProducto=(zProductoCotizar  *)pzProductos->Siguiente())
  EliminaProducto(lzProducto);
     
}
void zOrdenVenta::EliminaProductosOrden()
{
zSiscomRegistros *lzSisRegsProductos;
zProductoCotizar *lzProdCotizar;
if((lzSisRegsProductos=Productos()))
{
   for(lzProdCotizar=(zProductoCotizar *)lzSisRegsProductos->Primer();
       lzProdCotizar;
       lzProdCotizar=(zProductoCotizar *)lzSisRegsProductos->Siguiente())
	EliminaProducto(lzProdCotizar);
   ActualizaCampo("Productos",(const unsigned char *)0);
}
}
void zOrdenVenta::AsignaOrdenConsultada(zSiscomRegistro *pzSisRegOrden)
{
ActualizaCampo("IdVenta",pzSisRegOrden->CampoAsociado("ImporteOrden","idventa"));
ActualizaCampo("IdExpendio",pzSisRegOrden->CampoAsociado("Productos","idexpendio"));
ActualizaCampo("Juegos",(const unsigned char *)"1");
ActualizaCampo("DescuentoOrden",(const unsigned char *)"0");
ActualizaCampo("Importe",pzSisRegOrden->CampoAsociado("ImporteOrden","importe"));
}
void zOrdenVenta::AsignaProductos(zSiscomRegistros *pzSisRegsProductos)
{
zSiscomRegistro *lzSisRegProducto;
zProductoCotizar *lzProdCotiza;
int lintContador;
for(lzSisRegProducto=pzSisRegsProductos->Primer(),
    lintContador=0;
    lzSisRegProducto;
    lzSisRegProducto=pzSisRegsProductos->Siguiente(),
    lintContador++)
{
    lzProdCotiza=new zProductoCotizar((const char *)(*lzSisRegProducto)["cantidad"],
    				      (const char *)(*lzSisRegProducto)["precio"],
				      lzSisRegProducto);
    lzProdCotiza->Importe((const char *)(*lzSisRegProducto)["importe"]);
    lzProdCotiza->IdConsecutivo(lintContador);
    AsociadoAlCampo("Productos",lzProdCotiza);
}
}
void zOrdenVenta::ProductosALaOrden(zSiscomRegistros *pzSisRegsProductos)
{
     AsociadosAlCampo("Productos",pzSisRegsProductos); 
}
zSiscomRegistros *zOrdenVenta::Productos()
{
       return AsociadosDelCampo("Productos");
}
zCotizacion *zOrdenVenta::Cotizacion()
{
      return (zCotizacion *)AsociadoDelCampo("Cotizacion");
}
zPedido *zOrdenVenta::Pedido()
{
	return (zPedido *)AsociadoDelCampo("Pedido");
}
zConexionExpendio *zOrdenVenta::Expendio()
{
      return (zConexionExpendio *)AsociadoDelCampo("Expendio");
}
void zOrdenVenta::AgregandoProductos(zSiscomRegistros *pzSisRegsProductos,
				     zOrdenVenta *pzOrdenVenta)
{
zSiscomRegistro *lzSisRegProducto;
zProductoCotizar *lzProdCotizar;
int lintContador;
for(lintContador=NumProductos(),
    lzSisRegProducto=pzSisRegsProductos->Primer();
    lzSisRegProducto;
    lzSisRegProducto=pzSisRegsProductos->Siguiente(),
    lintContador++)
{
   lzProdCotizar=new zProductoCotizar(lzSisRegProducto);
   pzOrdenVenta->AgregaProducto(lzProdCotizar);
}
}
void zOrdenVenta::AgregandoProductos(zSiscomRegistros *pzSisRegsProductos)
{
zSiscomRegistro *lzSisRegProducto;
zProductoCotizar *lzProdCotizar;
int lintContador;

for(lintContador=NumProductos(),
    lzSisRegProducto=pzSisRegsProductos->Primer();
    lzSisRegProducto;
    lzSisRegProducto=pzSisRegsProductos->Siguiente(),
    lintContador++)
    AgregaProducto((zProductoCotizar *)lzSisRegProducto); 
}

zOrdenVenta *zOrdenVenta::ConsultaOrdenes2(zSiscomRegistro *pzSisRegOrden)
{
zSiscomRegistros *lzSisRegsProductos;
zOrdenVenta *lzOrdenVenta=new zOrdenVenta;
   lzOrdenVenta->ActualizaCampo("IdVenta",(*pzSisRegOrden)["idventa"]);
   lzOrdenVenta->ActualizaCampo("Importe",(*pzSisRegOrden)["importeorden"]);
   lzOrdenVenta->ActualizaCampo("IdTipoOrden",(*pzSisRegOrden)["idtipoorden"]);
   lzOrdenVenta->ActualizaCampo("IdVendedor",(*pzSisRegOrden)["vendedor"]);
   lzOrdenVenta->ActualizaCampo("Fecha",(*pzSisRegOrden)["fechahora"]);
   lzOrdenVenta->Cliente(new zClienteSiscom(pzSisRegOrden));
   lzOrdenVenta->ActualizaCampo("Juegos",(const unsigned char *)"1");
   lzOrdenVenta->ActualizaCampo("JuegosNuevo",(const unsigned char *)"1");
   lzSisRegsProductos=pzSisRegOrden->AsociadosDelCampo("Productos");
   lzOrdenVenta->NumProductos(lzSisRegsProductos->NNodos());
   AgregandoProductos(lzSisRegsProductos,lzOrdenVenta);
return lzOrdenVenta;
}

zOrdenVenta *zOrdenVenta::DuplicaOrden()
{
 return (zOrdenVenta *)Duplica();
}

int zOrdenVenta::SePuedeVender()
{
zProductoCotizar *lzProducto;
int lintNoSePuedeVender=0;
  for(lzProducto=(zProductoCotizar *)Productos()->Primer();
      lzProducto;
      lzProducto=(zProductoCotizar *)Productos()->Siguiente())
  {
	if(!lzProducto->SePuedeVender())
	 lintNoSePuedeVender++;
  }
     return lintNoSePuedeVender==0;
}
int zOrdenVenta::SePagoConTransferencia()
{
   return IdTipoOrdenInt()==11;
}
void zOrdenVenta::SePuedeVender(const char *pchrPtrSePuedeVender)
{
   ActualizaCampo("SePuedeVender",(const unsigned char *)pchrPtrSePuedeVender);
}
int zOrdenVenta::EsCotizacion()
{
  return IdTipoOrdenInt()==1;
}
zFormaPago *zOrdenVenta::FormaPago()
{
   return (zFormaPago *)AsociadoDelCampo("FormaPago");
}
void zOrdenVenta::OrdenPrecioEspecial()
{
zProductoCotizar *lzProdCotizar;
   for(lzProdCotizar=(zProductoCotizar *)Productos()->Primer();
       lzProdCotizar;
       lzProdCotizar=(zProductoCotizar *)Productos()->Siguiente())
	 lzProdCotizar->PrecioEspecial("1");
}
void ImprimeOrdenVenta(const char *pchrPtrArchivo,
		       const char *pchrPtrFuncion,
		       int pintNoLinea,
		       zOrdenVenta *pzOrdenVenta)
{
char lchrArrCadena[128];
sprintf(lchrArrCadena,"%-12s%-15s%-10s","IdVenta","IdTipoOrden","Importe");
zSiscomDesarrollo4::Log(pchrPtrArchivo,pchrPtrFuncion,pintNoLinea,"%s",lchrArrCadena);
sprintf(lchrArrCadena,
        "%12s%15s%10s%14s",
	pzOrdenVenta->IdVenta(),
	pzOrdenVenta->IdTipoOrden(),
	pzOrdenVenta->ImporteOrden());
zSiscomDesarrollo4::Log(pchrPtrArchivo, pchrPtrFuncion, pintNoLinea,"%s",lchrArrCadena);
sprintf(lchrArrCadena,"%-15s%-20s","Escuela","Cliente");
zSiscomDesarrollo4::Log(pchrPtrArchivo,pchrPtrFuncion,pintNoLinea,"%s",lchrArrCadena);
if(pzOrdenVenta->Cliente())
{
sprintf(lchrArrCadena,
	"%-15s%-20s%-15s",
	pzOrdenVenta->Cliente()->Escuela(),
	pzOrdenVenta->Cliente()->Nombre(),
	pzOrdenVenta->Cliente()->APaterno());
zSiscomDesarrollo4::Log(pchrPtrArchivo,pchrPtrFuncion,pintNoLinea,"%s",lchrArrCadena);
}
else
zSiscomDesarrollo4::Log(pchrPtrArchivo,pchrPtrFuncion,pintNoLinea,"Error Cliente Nulo");
}
