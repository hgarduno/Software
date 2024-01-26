#include <zTransferencia.h>
#include <zProductos.h>
#include <zSiscomCampo.h>
#include <zSiscomRegistros.h>
#include <zOrden.h>
#include <string.h>
#include <stdio.h>
zTransferencia::zTransferencia(zSiscomRegistro *pzSisRegTienda, 
            zSiscomRegistro *pzSisRegAlmacenista,
            zSiscomRegistro *pzSisRegChofer,
            zSiscomRegistro *pzSisRegCamion)
{

  (*this) <<
   new zSiscomCampo("IdTransferencia")       					<< 
   new zSiscomCampo("TiendaATransferir")					<<
   new zSiscomCampo("IdTienda") 						<<
   new zSiscomCampo("IdAlmacenista") 						<<
   new zSiscomCampo("IdChofer") 						<<
   new zSiscomCampo("NombreChofer") 						<<
   new zSiscomCampo("IdCamion") 						<<
   new zSiscomCampo("Placas") 						<<
   new zSiscomCampo("IdEstado")     						<<
   new zSiscomCampo("Fecha")     						<<
   new zSiscomCampo("Dia")							<<
   new zSiscomCampo("Mes")							<<
   new zSiscomCampo("Anio")							<<
   new zSiscomCampo("ObservacionGeneral")     				<<
   new zSiscomCampo("Productos")						<<
   new zSiscomCampo("IdTipoTransferencia")					<<
   new zSiscomCampo("EsStock")						<<
   new zSiscomCampo("Camion")							<<
   new zSiscomCampo("Almacenista")						<<
   new zSiscomCampo("TiendaOrigen");

if(pzSisRegTienda)
{
 ActualizaCampo("IdTienda",(*pzSisRegTienda)["idtienda"]);
 AsociadoAlCampo("TiendaATransferir",pzSisRegTienda);
}
 if(pzSisRegAlmacenista)
 {
 ActualizaCampo("IdAlmacenista",(*pzSisRegAlmacenista)["idalmacenista"]);
 AsociadoAlCampo("Almacenista",pzSisRegAlmacenista);
 }
 if(pzSisRegChofer)
 {
 ActualizaCampo("IdChofer",(*pzSisRegChofer)["idchofer"]);
 AsociadoAlCampo("NombreChofer",pzSisRegChofer);
 }
if(pzSisRegCamion) 
{
 ActualizaCampo("IdCamion",(*pzSisRegCamion)["idcamion"]);
 AsociadoAlCampo("Camion",pzSisRegCamion);
}
}
const char *zTransferencia::Chofer()
{
char lchrArrNombre[128];
sprintf(lchrArrNombre,"%s - %s %s %s",
	(const char *)CampoAsociado("NombreChofer","clave"),
	(const char *)CampoAsociado("NombreChofer","nombre"),
	(const char *)CampoAsociado("NombreChofer","apaterno"),
	(const char *)CampoAsociado("NombreChofer","amaterno"));
return strdup(lchrArrNombre);
}
const char *zTransferencia::Camion()
{
  return (const char *)CampoAsociado("Camion","nombre");
}
const char *zTransferencia::Placas()
{
  return (const char *)CampoAsociado("Placas","placas");
}
void zTransferencia::EsStock(const char *pchrPtrEsStock)
{
  ActualizaCampo("EsStock",(const unsigned char *)pchrPtrEsStock);
}
void zTransferencia::IdTipoTransferencia(const char *pchrPtrIdTipoTransferencia)
{
  ActualizaCampo("IdTipoTransferencia",(const unsigned char *)pchrPtrIdTipoTransferencia);
}
void zTransferencia::Productos(zProductos *pzProdsTransferencia)
{
  AsociadosAlCampo("Productos",pzProdsTransferencia);
}
void zTransferencia::IdEstado(const unsigned char *pchrPtrIdEstado)
{
    ActualizaCampo("IdEstado",pchrPtrIdEstado);
}

void zTransferencia::ObservacionGeneral(const unsigned char *pchrPtrObservacionGeneral)
{
    ActualizaCampo("ObservacionGeneral",pchrPtrObservacionGeneral);
}
zProductos *zTransferencia::Productos()
{
    return (zProductos *)AsociadosDelCampo("Productos"); 
}

void zTransferencia::TiendaOrigen(zSiscomRegistro *pzSisRegTiendaOrigen)
{
 AsociadoAlCampo("TiendaOrigen",pzSisRegTiendaOrigen);
}
void zTransferencia::Dia(const char unsigned *pchrPtrDia)
{
   ActualizaCampo("Dia",pchrPtrDia);	
}
void zTransferencia::Mes(const unsigned char *pchrPtrMes)
{  
   ActualizaCampo("Mes",pchrPtrMes);
}
void zTransferencia::Anio(const unsigned char *pchrPtrAnio)
{
   ActualizaCampo("Anio",pchrPtrAnio);
}
zSiscomRegistro *zTransferencia::TiendaOrigen()
{
  return AsociadoDelCampo("TiendaOrigen");
}
zSiscomRegistro *zTransferencia::TiendaDestino()
{
  return AsociadoDelCampo("TiendaATransferir");
}
const char *zTransferencia::Dia()
{
   return (const char *)(*this)["Dia"];
}
const char *zTransferencia::Mes()
{
   return (const char *)(*this)["Mes"];
}
const char *zTransferencia::Anio()
{
   return (const char *)(*this)["Anio"];
}
void zTransferencia::AsignaOrden()
{
zOrdenT=new zOrden;
zOrdenT->Productos(Productos());
}
zOrden *zTransferencia::Orden()
{
return zOrdenT;
}
