#include <zProductoImportado.h>
#include <zSiscomCampo.h>
#include <string.h>
#include <zSiscomDesarrollo4.h>
zProductoImportado::zProductoImportado()
{
   (*this) 				<<
   new zSiscomCampo("CveProducto");
   AgregaCampos();
}
zProductoImportado::zProductoImportado(zSiscomRegistro *pzSisProducto)
{

   (*this)									<<
   new zSiscomCampo("CveProducto",(*pzSisProducto)["cveproducto"]);
   AgregaCampos();
}
void zProductoImportado::AgregaCampos()
{
   (*this)									<< 
   new zSiscomCampo("Cantidad")							<<
   new zSiscomCampo("Peso")							<<
   new zSiscomCampo("PesoTotal")						<<
   new zSiscomCampo("CostoEnvio")						<<
   new zSiscomCampo("CostoUnitarioDolares")					<<
   new zSiscomCampo("CostoTotalDolares")					<<
   new zSiscomCampo("PrecioMasCostoEnvio")					<<
   new zSiscomCampo("CostoFinalPesos")						<<
   new zSiscomCampo("CostoFinalMasCosAdm")					<<
   new zSiscomCampo("CostoPartida")						<<
   new zSiscomCampo("CveProveedor")						<<
   new zSiscomCampo("IdProveedor")						<<
   new zSiscomCampo("RazonSocial");
}
void zProductoImportado::Clave(const char *pchrPtrClave)
{
   ActualizaCampo("CveProducto",(const unsigned char *)pchrPtrClave);
}
void zProductoImportado::Cantidad(const char *pchrPtrCantidad)
{
   ActualizaCampo("Cantidad",(const unsigned char *)pchrPtrCantidad);
}
void zProductoImportado::Peso(const char *pchrPtrPeso)
{

   ActualizaCampo("Peso",(const unsigned char *)pchrPtrPeso);
}
void zProductoImportado::PesoTotal(const char *pchrPtrPesoTotal)
{
   ActualizaCampo("PesoTotal",(const unsigned char *)pchrPtrPesoTotal);
}
void zProductoImportado::CostoEnvio(const char *pchrPtrCostoEnvio)
{

   ActualizaCampo("CostoEnvio",(const unsigned char *)pchrPtrCostoEnvio);
}
void zProductoImportado::PrecioMasCostoEnvio(const char *pchrPtrPrecioMasCostoEnvio)
{

   ActualizaCampo("PrecioMasCostoEnvio",(const unsigned char *)pchrPtrPrecioMasCostoEnvio);
}
void zProductoImportado::CostoFinalPesos(const char *pchrPtrCostoFinalPesos)
{

   ActualizaCampo("CostoFinalPesos",(const unsigned char *)pchrPtrCostoFinalPesos);
}
void zProductoImportado::CostoFinalMasCosAdm(const char *pchrPtrCostoFinalMasCosAdm)
{

   ActualizaCampo("CostoFinalMasCosAdm",(const unsigned char *)pchrPtrCostoFinalMasCosAdm);
}
void zProductoImportado::CostoPartida(const char *pchrPtrCostoPartida)
{

   ActualizaCampo("CostoPartida",(const unsigned char *)pchrPtrCostoPartida);
}
void zProductoImportado::CostoUnitarioDolares(const char *pchrPtrCostoUnitarioDolares)
{
  ActualizaCampo("CostoUnitarioDolares",(const unsigned char *)pchrPtrCostoUnitarioDolares);
}
void zProductoImportado::CostoTotalDolares(const char *pchrPtrCostoTotalDolares)
{
  ActualizaCampo("CostoTotalDolares",(const unsigned char *)pchrPtrCostoTotalDolares);
}
void zProductoImportado::CveProveedor(const char *pchrPtrCveProveedor)
{
  ActualizaCampo("CveProveedor",(const unsigned char *)pchrPtrCveProveedor);
}
void zProductoImportado::IdProveedor(const char *pchrPtrIdProveedor)
{
 ActualizaCampo("IdProveedor",(const unsigned char *)pchrPtrIdProveedor);
}

void zProductoImportado::RazonSocial(const char *pchrPtrRazonSocial)
{
 ActualizaCampo("RazonSocial",(const unsigned char *)pchrPtrRazonSocial);
}

const char *zProductoImportado::Clave()
{
     return (const char *)(*this)["CveProducto"];
}

const char *zProductoImportado::Cantidad()
{
     return (const char *)(*this)["Cantidad"];
}

const char *zProductoImportado::Peso()
{
     return (const char *)(*this)["Peso"];
}
const char *zProductoImportado::PesoTotal()
{
     return (const char *)(*this)["PesoTotal"];
}

const char *zProductoImportado::CostoEnvio()
{
     return (const char *)(*this)["CostoEnvio"];
}

const char *zProductoImportado::CostoUnitarioDolares()
{
     return (const char *)(*this)["CostoUnitarioDolares"];
}

const char *zProductoImportado::CostoTotalDolares()
{
     return (const char *)(*this)["CostoTotalDolares"];
}

const char *zProductoImportado::PrecioMasCostoEnvio()
{
     return (const char *)(*this)["PrecioMasCostoEnvio"];
}

const char *zProductoImportado::CostoFinalPesos()
{
     return (const char *)(*this)["CostoFinalPesos"];
}

const char *zProductoImportado::CostoFinalMasCosAdm()
{
     return (const char *)(*this)["CostoFinalMasCosAdm"];
}

const char *zProductoImportado::CostoPartida()
{
     return (const char *)(*this)["CostoPartida"];
}
const char *zProductoImportado::CveProveedor()
{
   return (const char *)(*this)["CveProveedor"];
}
const char *zProductoImportado::IdProveedor()
{
   return (const char *)(*this)["IdProveedor"];
}

const char *zProductoImportado::RazonSocial()
{
   return (const char *)(*this)["RazonSocial"];
}

bool zProductoImportado::operator==(zProductoImportado *pzProdImportado)
{
   if(Clave() && pzProdImportado->Clave())
   return !strcmp(Clave(),pzProdImportado->Clave());
   else
   return false;
}
bool zProductoImportado::operator=(zProductoImportado *pzProdImportado)
{
      PesoTotal(pzProdImportado->PesoTotal());
      CostoEnvio(pzProdImportado->CostoEnvio());
      CostoUnitarioDolares(pzProdImportado->CostoUnitarioDolares());
      CostoTotalDolares(pzProdImportado->CostoTotalDolares());
      PrecioMasCostoEnvio(pzProdImportado->PrecioMasCostoEnvio());
      CostoFinalPesos(pzProdImportado->CostoFinalPesos());
      CostoFinalMasCosAdm(pzProdImportado->CostoFinalMasCosAdm());
      CostoPartida(pzProdImportado->CostoPartida());
      Peso(pzProdImportado->Peso());
      RazonSocial(pzProdImportado->RazonSocial());
      return true;
}

