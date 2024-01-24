#include <zCompraImportacion.h>
#include <zSiscomCampo.h>

#include <zProductosImportados.h>
#include <zProductoImportado.h>
#include <zEmpresa.h>
#include <zSiscomDesarrollo4.h>
zCompraImportacion::zCompraImportacion()
{
  (*this) 						<< 
  new zSiscomCampo("IdCompraImportacion")		<<
  new zSiscomCampo("IdExpendio")			<<
  new zSiscomCampo("IdResponsable")			<<
  new zSiscomCampo("NumFactura")			<<
  new zSiscomCampo("ImporteFactura")			<<
  new zSiscomCampo("Empresa") 				<<
  new zSiscomCampo("CostoEnvio")			<<
  new zSiscomCampo("CostoDolar")			<<
  new zSiscomCampo("CostoAdministrativo")		<<
  new zSiscomCampo("PonderacionCostoAdministrativo")	<<
  new zSiscomCampo("NumPartidas")			<<
  new zSiscomCampo("PesoCompra")			<<
  new zSiscomCampo("Descripcion")			<<
  new zSiscomCampo("Fecha")				<<
  new zSiscomCampo("CostoGrEnvio")			<<
  new zSiscomCampo("Productos")				<<
  new zSiscomCampo("Proveedores")			<<
  new zSiscomCampo("IdBodega");
}
void zCompraImportacion::CostoGrEnvio(const char *pchrPtrCostoGrEnvio)
{
 ActualizaCampo("CostoGrEnvio",(const unsigned char *)pchrPtrCostoGrEnvio);
}
void zCompraImportacion::IdCompraImportacion(const char *pchrPtrIdCompraImportacion)
{
 ActualizaCampo("IdCompraImportacion",(const unsigned char *)pchrPtrIdCompraImportacion);
}
void zCompraImportacion::IdExpendio(const char *pchrPtrIdExpendio)
{
 ActualizaCampo("IdExpendio",(const unsigned char *)pchrPtrIdExpendio);
}
void zCompraImportacion::IdResponsable(const char *pchrPtrIdResponsable)
{
 ActualizaCampo("IdResponsable",(const unsigned char *)pchrPtrIdResponsable);
}
void zCompraImportacion::NumFactura(const char *pchrPtrNumFactura)
{
 ActualizaCampo("NumFactura",(const unsigned char *)pchrPtrNumFactura);
}

void zCompraImportacion::ImporteFactura(const char *pchrPtrImporteFactura)
{
 ActualizaCampo("ImporteFactura",(const unsigned char *)pchrPtrImporteFactura);
}
void zCompraImportacion::Empresa(zSiscomRegistro *pzSisRegistro)
{
  ActualizaCampo("Empresa",pzSisRegistro);
}

void zCompraImportacion::CostoEnvio(const char *pchrPtrCostoEnvio)
{
  ActualizaCampo("CostoEnvio",(const unsigned char *)pchrPtrCostoEnvio);
}


void zCompraImportacion::CostoDolar(const char *pchrPtrCostoDolar)
{
  ActualizaCampo("CostoDolar",(const unsigned char *)pchrPtrCostoDolar);
}
void zCompraImportacion::CostoAdministrativo(const char *pchrPtrCostoAdministrativo)
{
  ActualizaCampo("CostoAdministrativo",(const unsigned char *)pchrPtrCostoAdministrativo);
}
void zCompraImportacion::PonderacionCostoAdministrativo(const char *pchrPtrPonderacionCostoAdmin)
{
  ActualizaCampo("PonderacionCostoAdministrativo",(const unsigned char *)pchrPtrPonderacionCostoAdmin);
}
void zCompraImportacion::NumPartidas(const char *pchrPtrNumPartidas)
{
  ActualizaCampo("NumPartidas",(const unsigned char *)pchrPtrNumPartidas);
}

void zCompraImportacion::PesoCompra(const char *pchrPtrPesoCompra)
{
  ActualizaCampo("PesoCompra",(const unsigned char *)pchrPtrPesoCompra);
}
void zCompraImportacion::Descripcion(const char *pchrPtrDescripcion)
{
  ActualizaCampo("Descripcion",(const unsigned char *)pchrPtrDescripcion);
}
void zCompraImportacion::Fecha(const char *pchrPtrFecha)
{
 	ActualizaCampo("Fecha",(const unsigned char *)pchrPtrFecha);
}
void zCompraImportacion::Productos(zProductosImportados *pzProdsImportados)
{
  AsociadosAlCampo("Productos",pzProdsImportados);
}
void zCompraImportacion::IdBodega(const char *pchrPtrIdBodega)
{
     ActualizaCampo("IdBodega",(const unsigned char *)pchrPtrIdBodega);
}
void zCompraImportacion::AgregaProducto(zProductoImportado *pzProdImportado)
{
   AsociadoAlCampo("Productos",pzProdImportado);
}
void zCompraImportacion::EliminaProductoImportado(int pintNNodo)
{
   AsociadosDelCampo("Productos")->Elimina(pintNNodo);
}
const char *zCompraImportacion::PesoCompra()
{
   return (const char *)Campo("PesoCompra");
}

const char *zCompraImportacion::IdResponsable()
{
   return (const char *)Campo("IdResponsable");
}

const char *zCompraImportacion::IdExpendio()
{
   return (const char *)Campo("IdExpendio");
}
const char *zCompraImportacion::ImporteFactura()
{
   return (const char *)Campo("ImporteFactura");
}
const char *zCompraImportacion::CostoEnvio()
{
   return (const char *)Campo("CostoEnvio");
}
const char *zCompraImportacion::CostoDolar()
{
   return (const char *)Campo("CostoDolar");
}
const char *zCompraImportacion::CostoAdministrativo()
{
   return (const char *)Campo("CostoAdministrativo");

}
const char *zCompraImportacion::NumFactura()
{
   return (const char *)Campo("NumFactura");

}
int zCompraImportacion::NumPartidasInt()
{
   return CampoInt("NumPartidas");
}
const char *zCompraImportacion::NumPartidas()
{
   return (const char *)Campo("NumPartidas");
}
const char *zCompraImportacion::IdCompraImportacion()
{
   return (const char *)Campo("IdCompraImportacion");
}
const char *zCompraImportacion::Descripcion()
{
  return (const char *)Campo("Descripcion");
}
const char *zCompraImportacion::Fecha()
{
	return (const char *)Campo("Fecha");
}
const char *zCompraImportacion::CostoGrEnvio()
{
	return CampoConstChar("CostoGrEnvio");
}
zEmpresa *zCompraImportacion::Empresa()
{
   return (zEmpresa *)AsociadoDelCampo("Empresa");
}
const char *zCompraImportacion::IdBodega()
{
	return CampoConstChar("IdBodega");

}
void zCompraImportacion::ActualizaProductos(zSiscomRegistros *pzSisRegsProductos)
{
zProductosImportados *lzProdsImportados;
lzProdsImportados=(zProductosImportados *)AsociadosDelCampo("Productos");
lzProdsImportados->Actualiza(pzSisRegsProductos);
}
zProductosImportados *zCompraImportacion::Productos()
{
 return (zProductosImportados *)AsociadosDelCampo("Productos");
}
void zCompraImportacion::EliminaProductos()
{
 AsociadosDelCampo("Productos")->Libera(); 
}
zProductoImportado *zCompraImportacion::Producto(int pintNProducto)
{
   return (zProductoImportado *)(*Productos())[pintNProducto];
}
int zCompraImportacion::operator=(zCompraImportacion &pzCompraImp)
{
        CostoEnvio(pzCompraImp.CostoEnvio());
	CostoDolar(pzCompraImp.CostoDolar());
	CostoAdministrativo(pzCompraImp.CostoAdministrativo());
	NumPartidas(pzCompraImp.NumPartidas());
	NumFactura(pzCompraImp.NumFactura());
	Descripcion(pzCompraImp.Descripcion());
	Empresa(pzCompraImp.Empresa());
return 0;
}
void zCompraImportacion::AgregaProveedor(zEmpresa *pzProveedor)
{
    AsociadoAlCampo("Proveedores",pzProveedor);
}
void zCompraImportacion::AgregaProveedores(zSiscomRegistros *pzSisRegsProveedores)
{
zSiscomRegistro *lzSisRegEmpresa;
for(lzSisRegEmpresa=pzSisRegsProveedores->Primer();
    lzSisRegEmpresa;
    lzSisRegEmpresa=pzSisRegsProveedores->Siguiente())
    AsociadoAlCampo("Proveedores",zEmpresa::DeConsultaEmpresas(lzSisRegEmpresa));
}
zEmpresa *zCompraImportacion::UltimoProveedor()
{
      return (zEmpresa *)(*AsociadosDelCampo("Proveedores"))[0];
}
zSiscomRegistros *zCompraImportacion::Proveedores()
{
    return AsociadosDelCampo("Proveedores");
}
zCompraImportacion *zCompraImportacion::DuplicaConOtrosProductos(zProductosImportados *pzProdsImportados)
{
zCompraImportacion *lzComImportacion=new zCompraImportacion;
SiscomRegistroLog2(this);
   lzComImportacion->IdCompraImportacion(IdCompraImportacion());
   lzComImportacion->IdExpendio(IdExpendio());
   lzComImportacion->IdResponsable(IdResponsable());
   lzComImportacion->Empresa(Empresa());
   lzComImportacion->IdBodega(IdBodega());
   lzComImportacion->NumFactura(NumFactura());
   lzComImportacion->ImporteFactura(ImporteFactura());
   lzComImportacion->Productos(pzProdsImportados);
return lzComImportacion;
}
