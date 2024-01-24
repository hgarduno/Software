#ifndef __ZCOMPRAIMPORTACION_H__
#define __ZCOMPRAIMPORTACION_H__
#include <zSiscomRegistro.h>

class zProductosImportados;
class zProductoImportado;
class zSiscomProductos;
class zEmpresa;
class zCompraImportacion:public zSiscomRegistro
{
public:
	zCompraImportacion();
	void IdCompraImportacion(const char *pchrPtrIdCompraImportacion);
	void IdExpendio(const char *pchrPtrIdExpendio);
	void IdResponsable(const char *pchrPtrIdResponsable);
	void NumFactura(const char *pchrPtrNumFactura);
	void ImporteFactura(const char *pchrPtrNumFactura);
	void Empresa(zSiscomRegistro *pzSisRegEmpresa);
	void CostoEnvio(const char *pchrPtrCostoEnvio);
	void CostoDolar(const char *pchrPtrCostoDolar);
	void CostoAdministrativo(const char *pchrPtrCostoAdministrativo);
	void PonderacionCostoAdministrativo(const char *pchrPtrPonderacionCostoAdministrativo);
	void NumPartidas(const char *pchrPtrNumPartidas);
	void PesoCompra(const char *pchrPtrPesoCompra);
	void Descripcion(const char *pchrPtrDescripcion);
	void Productos(zProductosImportados *pzProdsImportados);
	void AgregaProducto(zProductoImportado *pzProdImportado);
	void EliminaProductoImportado(int pintNProducto);
	void Fecha(const char *pchrPtrFecha);
	void CostoGrEnvio(const char *);
	void IdBodega(const char *);

	const char *IdCompraImportacion();
	const char *PesoCompra();
	const char *ImporteFactura();
	const char *CostoEnvio();
	const char *CostoDolar();
	const char *CostoAdministrativo();
	const char *NumPartidas();
	const char *NumFactura();
	const char *Descripcion();
	const char *Fecha();
	const char *CostoGrEnvio();
	const char *IdBodega();
	const char *IdExpendio();
	const char *IdResponsable();
	zEmpresa *Empresa();

	int NumPartidasInt();

	void ActualizaProductos(zSiscomRegistros *pzSisRegsProductos);
	zProductosImportados *Productos();
	zProductoImportado *Producto(int pintNProducto);

	void EliminaProductos();
	void AgregaProveedor(zEmpresa *);
	void AgregaProveedores(zSiscomRegistros *);
	zEmpresa *UltimoProveedor();
	zSiscomRegistros *Proveedores();

	int operator=(zCompraImportacion &);

	zCompraImportacion *DuplicaConOtrosProductos(zProductosImportados*);
};



#endif
