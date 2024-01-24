#ifndef __ZFACTURA_H__
#define __ZFACTURA_H__
#include <zSiscomRegistro.h>
class zCliente;
class zOrdenes;
class zFactura:public zSiscomRegistro
{
public:
	zFactura();
	void Cliente(zCliente *pzCliente);
	void FormaPago(zSiscomRegistro *);
	void MetodoPago(zSiscomRegistro *);
	void UsoFactura(zSiscomRegistro *);
	void Productos(zSiscomRegistros *pzSisRegsProductos);
	void Ordenes(zOrdenes *pzOrdenes);
	void Importe(const char *pchrPtrImporte);
	void Total(const char *pchrPtrTotal);
	void Iva(const char *pchrPtrIva);
	void TotalLetra(const char *pchrPtrImporteLetra);
	const char *Importe();
	const char *Total();
	float TotalFloat();
	const char *Iva();
	zSiscomRegistros *Productos();
};

#endif
