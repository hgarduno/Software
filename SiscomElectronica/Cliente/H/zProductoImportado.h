#ifndef __ZPRODUCTOIMPORTADO_H__
#define __ZPRODUCTOIMPORTADO_H__
#include <zSiscomRegistro.h>


class zProductoImportado:public zSiscomRegistro
{
public:
	zProductoImportado();
	zProductoImportado(zSiscomRegistro *pzSisRegProducto);
	void Clave(const char *pchrPtrClave);
	void Cantidad(const char *pchrPtrCantidad);
	void Peso(const char *pchrPtrPeso);
	void PesoTotal(const char *pchrPtrPesoTotal);
	void CostoEnvio(const char *pchrPtrCostoEnvio);
	void PrecioMasCostoEnvio(const char *pchrPtrPrecioMasCostoEnvio);
	void CostoFinalPesos(const char *pchrPtrCostoFinalPesos);
	void CostoFinalMasCosAdm(const char *pchrPtrCostoFinalMasCosAdm);
	void CostoPartida(const char *pchrPtrCostoPartida);
	void CostoUnitarioDolares(const char *pchrPtrCostoUnitarioDolares);
	void CostoTotalDolares(const char *pchrPtrCostoTotalDolares);
	void CveProveedor(const char *pchrPtrCveProveedor);
	void IdProveedor(const char *pchrPtrIdProveedor);
	void RazonSocial(const char *pchrPtrProveedor);
	const char *Clave();
	const char *Cantidad();
	const char *Peso();
	const char *PesoTotal();
	const char *CostoEnvio();
	const char *CostoUnitarioDolares();
	const char *CostoTotalDolares();
	const char *PrecioMasCostoEnvio();
	const char *CostoFinalPesos();
	const char *CostoFinalMasCosAdm();
	const char *CostoPartida();
	const char *CveProveedor();
	const char *IdProveedor();
	const char *RazonSocial();

	bool operator==(zProductoImportado *pzProdImportado);
	bool operator=(zProductoImportado *pzProdImportado);

	void AgregaCampos();

};


#endif
