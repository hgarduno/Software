#include <zVenta.h>
#include <zSiscomCampo.h>
#include <zOrden.h>
#include <zCredito.h>
#include <zSiscomRegistros.h>

#include <string.h>
zVenta::zVenta()
{
(*this) 				<<
new zSiscomCampo("IdVenta")		<<
new zSiscomCampo("IdTipoVenta") 	<<
new zSiscomCampo("IdConcepto")	<<
new zSiscomCampo("IdTiendaEntrega")	<<
new zSiscomCampo("NombreTiendaEntrega")	<<
new zSiscomCampo("IdVendedor")	<<
new zSiscomCampo("NombreVendedor")	<<
new zSiscomCampo("Folio")		<<
new zSiscomCampo("Fecha")		<<
new zSiscomCampo("Anio")		<<
new zSiscomCampo("Mes")		<<
new zSiscomCampo("Dia")		<<
new zSiscomCampo("IdCliente")		<<
new zSiscomCampo("Nombre")		<<
new zSiscomCampo("APaterno")		<<
new zSiscomCampo("AMaterno")		<<
new zSiscomCampo("RFC")			<<
new zSiscomCampo("IdDireccion")	<<
new zSiscomCampo("Calle")		<<
new zSiscomCampo("NumExterior")	<<
new zSiscomCampo("NumInterior")	<<
new zSiscomCampo("Colonia")		<<
new zSiscomCampo("DelegMunic")	<<
new zSiscomCampo("CodigoPostal")	<<
new zSiscomCampo("FormaEntrega")	<<
new zSiscomCampo("InstruccionesE")	<<
new zSiscomCampo("Orden")		<<
new zSiscomCampo("Credito")		<<
new zSiscomCampo("TiendaVenta")	<<
new zSiscomCampo("Telefono")		<<
new zSiscomCampo("IdTelefono")		<<
new zSiscomCampo("Referencias");

}

void zVenta::IdVenta(const unsigned char *pchrPtrIdVenta)
{
ActualizaCampo("IdVenta",pchrPtrIdVenta);
}
void zVenta::IdTipoVenta(const unsigned char *pchrPtrIdTipoVenta)
{
ActualizaCampo("IdTipoVenta",pchrPtrIdTipoVenta);
}

void zVenta::IdConcepto(const unsigned char *pchrPtrIdConcepto)
{
ActualizaCampo("IdConcepto",pchrPtrIdConcepto);
}

void zVenta::IdTiendaEntrega(const unsigned char *pchrPtrIdTiendaEntrega)
{
ActualizaCampo("IdTiendaEntrega",pchrPtrIdTiendaEntrega);
}

void zVenta::NombreTiendaEntrega(const unsigned char *pchrPtrNombreTiendaEntrega)
{
ActualizaCampo("NombreTiendaEntrega",pchrPtrNombreTiendaEntrega);
}

void zVenta::IdVendedor(const unsigned char *pchrPtrIdVendedor)
{
ActualizaCampo("IdVendedor",pchrPtrIdVendedor);
}

void zVenta::NombreVendedor(const unsigned char *pchrPtrNombreVendedor)
{
ActualizaCampo("NombreVendedor",pchrPtrNombreVendedor);
}

void zVenta::Folio(const unsigned char *pchrPtrFolio)
{
ActualizaCampo("Folio",pchrPtrFolio);
}
void zVenta::Fecha(const unsigned char *pchrPtrFecha)
{
ActualizaCampo("Fecha",pchrPtrFecha);
}

void zVenta::Anio(const unsigned char *pchrPtrAnio)
{
   ActualizaCampo("Anio",pchrPtrAnio);
}
void zVenta::Mes(const unsigned char *pchrPtrMes)
{
  ActualizaCampo("Mes",pchrPtrMes);
}
void zVenta::Dia(const unsigned char *pchrPtrDia)
{
 ActualizaCampo("Dia",pchrPtrDia);
}
void zVenta::IdCliente(const unsigned char *pchrPtrIdCliente)
{
ActualizaCampo("IdCliente",pchrPtrIdCliente);
}

void zVenta::Nombre(const unsigned char *pchrPtrNombre)
{
ActualizaCampo("Nombre",pchrPtrNombre);
}

void zVenta::APaterno(const unsigned char *pchrPtrAPaterno)
{
ActualizaCampo("APaterno",pchrPtrAPaterno);
}
void zVenta::AMaterno(const unsigned char *pchrPtrAMaterno)
{
ActualizaCampo("AMaterno",pchrPtrAMaterno);
}
void zVenta::RFC(const unsigned char *pchrPtrRFC)
{
ActualizaCampo("RFC",pchrPtrRFC);
}
void zVenta::IdDireccion(const unsigned char *pchrPtrIdDireccion)
{
ActualizaCampo("IdDireccion",pchrPtrIdDireccion);
}
void zVenta::Calle(const unsigned char *pchrPtrCalle)
{
ActualizaCampo("Calle",pchrPtrCalle);
}
void zVenta::NumExterior(const unsigned char *pchrPtrNumExterior)
{
ActualizaCampo("NumExterior",pchrPtrNumExterior);
}
void zVenta::NumInterior(const unsigned char *pchrPtrNumInterior)
{
ActualizaCampo("NumInterior",pchrPtrNumInterior);
}
void zVenta::Colonia(const unsigned char *pchrPtrColonia)
{
ActualizaCampo("Colonia",pchrPtrColonia);
}
void zVenta::DelegMunic(const unsigned char *pchrPtrDelegMunic)
{
ActualizaCampo("DelegMunic",pchrPtrDelegMunic);
}
void zVenta::CodigoPostal(const unsigned char *pchrPtrCodigoPostal)
{
ActualizaCampo("CodigoPostal",pchrPtrCodigoPostal);
}
void zVenta::FormaEntrega(zSiscomRegistro *pzSisRegFormaEntrega)
{
AsociadoAlCampo("FormaEntrega",pzSisRegFormaEntrega);
}
void zVenta::Telefono(const char *pchrPtrTelefono)
{
ActualizaCampo("Telefono",(const unsigned char *)pchrPtrTelefono);
}
void zVenta::IdTelefono(const char *pchrPtrIdTelefono)
{
  ActualizaCampo("IdTelefono",(const unsigned char *)pchrPtrIdTelefono);
}
void zVenta::Referencias(const unsigned char *pchrPtrReferencias)
{
  ActualizaCampo("Referencias",(const unsigned char *)pchrPtrReferencias);
}

//voirArrBuffer,
void zVenta::InstruccionesEntrega(const char *pchrPtrInstruccionesE)
{
 ActualizaCampo("InstruccionesE",(const unsigned char *)pchrPtrInstruccionesE);
}
void zVenta::TiendaVenta(zSiscomRegistro *pzSisRegTienda)
{
  AsociadoAlCampo("TiendaVenta",pzSisRegTienda); 
}
void zVenta::Orden(zOrden *pzOrden)
{
 AsociadoAlCampo("Orden",pzOrden); 
}
void zVenta::Credito(zCredito *pzCredito)
{
   AsociadoAlCampo("Credito",pzCredito);
}

zOrden *zVenta::Orden()
{
zSiscomRegistro *lzSisRegistro=AsociadosDelCampo("Orden")->Primer();
return (zOrden *)lzSisRegistro;
}

const char *zVenta::SiglasTienda()
{
  zSiscomRegistro *lzSisRegTienda;
  if((lzSisRegTienda=AsociadoDelCampo("TiendaVenta")))
     return (const char *)(*lzSisRegTienda)["siglas"];
  else
  return 0;
}


const char *zVenta::Folio()
{
  return (const char *)(*this)["Folio"];
}
const char *zVenta::Id()
{
  return (const char *)(*this)["IdVenta"];
}


