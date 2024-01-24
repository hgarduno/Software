#include <zProductoCotizar.h>
#include <zSiscomCampo.h>
#include <zSiscomDesarrollo4.h>
#include <string.h>
#include <stdio.h>
zProductoCotizar::zProductoCotizar(const char *pchrPtrCantidad,
				   const char *pchrPtrPrecioVenta,
				   zSiscomRegistro *pzSisRegProducto):
				   zProducto(pzSisRegProducto)

{
  (*this)								<< 
  new zSiscomCampo("Cantidad",(const unsigned char *)pchrPtrCantidad)	<<
  new zSiscomCampo("Precio",(const unsigned char *)pchrPtrPrecioVenta)	<<
  new zSiscomCampo("Importe")						<<
  new zSiscomCampo("IdConsecutivo")					<<
  new zSiscomCampo("SePuedeVender")					<<
  new zSiscomCampo("SePuedeVenderDefProd")				<<
  new zSiscomCampo("PrecioEspecial",(const unsigned char *)"0");
}
zProductoCotizar::zProductoCotizar(zSiscomRegistro *pzSisRegistro):
				zProducto(pzSisRegistro)
{
  
  (*this)								<< 
  new zSiscomCampo("Cantidad",(*pzSisRegistro)["cantidad"])		<<
  new zSiscomCampo("Precio",(*pzSisRegistro)["precio"])			<<
  new zSiscomCampo("Importe",(*pzSisRegistro)["importe"])		<<
  new zSiscomCampo("IdConsecutivo",(*pzSisRegistro)["idconsecutivo"])   <<
  new zSiscomCampo("SePuedeVender")					<<
  new zSiscomCampo("SePuedeVenderDefProd",(const unsigned char *)"1") 	<<
  new zSiscomCampo("PrecioEspecial",(const unsigned char *)"0");
}
zProductoCotizar::~zProductoCotizar()
{
LogSiscom("");
}
const char *zProductoCotizar::Cantidad()
{
    return (const char *)(*this)["Cantidad"];
}
const char *zProductoCotizar::Precio()
{
    return (const char *)(*this)["Precio"];
}
const char *zProductoCotizar::Importe()
{
    return (const char *)(*this)["Importe"];
}
const char *zProductoCotizar::IdConsecutivo()
{
    return (const char *)(*this)["IdConsecutivo"];
}
 
int zProductoCotizar::SePuedeVender()
{
   return CampoInt("SePuedeVender");
}

int zProductoCotizar::SePuedeVenderDefProd()
{
   return CampoInt("SePuedeVenderDefProd");
}
void zProductoCotizar::IdConsecutivo(const char *pchrPtrIdConsecutivo)
{
   ActualizaCampo("IdConsecutivo",(const unsigned char *)pchrPtrIdConsecutivo);
}
void zProductoCotizar::IdConsecutivo(int pintIdConsecutivo)
{
char lchrArrIdConsecutivo[12];
sprintf(lchrArrIdConsecutivo,"%d",pintIdConsecutivo);
IdConsecutivo(strdup(lchrArrIdConsecutivo));
}
void zProductoCotizar::Cantidad(const char *pchrPtrCantidad)
{
   ActualizaCampo("Cantidad",(const unsigned char *)pchrPtrCantidad);
}
void zProductoCotizar::Precio(const char *pchrPtrPrecio)
{
   ActualizaCampo("Precio",(const unsigned char *)pchrPtrPrecio);
}

void zProductoCotizar::Importe(const char *pchrPtrImporte)
{
   ActualizaCampo("Importe",(const unsigned char *)pchrPtrImporte);
}
/* Tepotzotlan Mexico a 3 de Agosto del 2017
 * Se agrega el campo PrecioEspecial, para indicar si el 
 * producto en la orden tendra un precio diferente al de 
 * la base de datos
 */
void zProductoCotizar::PrecioEspecial(const char *pchrPtrPrecioEspecial)
{
   ActualizaCampo("PrecioEspecial",(const unsigned char *)pchrPtrPrecioEspecial);
}
int zProductoCotizar::EsProductoSiscom()
{
   return TipoProductoInt()==3;
}

void zProductoCotizar::SePuedeVender(const char *pchrPtrSePuedeVender)
{
    ActualizaCampo("SePuedeVender",(const unsigned char *)pchrPtrSePuedeVender);
}
