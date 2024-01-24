#ifndef __ZCOMPRACONTENEDOR_H__
#define __ZCOMPRACONTENEDOR_H__
#include <zSiscomRegistro.h>
class zCompraImportacion;
class zComprasImportacion;

class zCompraContenedor:public zSiscomRegistro
{
public:
	zCompraContenedor();

	void Factura(zCompraImportacion *);
	zCompraImportacion *Factura(int);
	zComprasImportacion *Facturas();

	void CostoDolar(const char *);
	void CostoAdministrativo(const char *);
	void CostoEnvio(const char *);

	const char *CostoDolar();
	const char *CostoAdministrativo();
	const char *CostoEnvio();

	void DatosEnvioFactura(int pintNFactura);

};

#endif
