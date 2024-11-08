#ifndef __ZPRODUCTOCOTIZAR_H__
#define __ZPRODUCTOCOTIZAR_H__
#include <zProducto.h>

class zSiscomRegistro;
class zProductoCotizar:public zProducto
{
public:
	zProductoCotizar(const char *pchrPtrCantidad,
			 const char *pchrPtrPrecioVenta,
			 zSiscomRegistro *pzSisRegProducto);
	zProductoCotizar(zSiscomRegistro *pzSisRegProducto);
	~zProductoCotizar();
	void IdConsecutivo(const char *pchrPtrIdConsecutivo);
	void IdConsecutivo(int pintIdConsecutivo);

	const char *Cantidad();
	const char *Precio();
	const char *Importe();
	const char *IdConsecutivo();
	int SePuedeVender();
	int SePuedeVenderDefProd();
	int EsProductoSiscom();

	void Cantidad(const char *pchrPtrCantidad);
	void Importe(const char *pchrPtrImporte);
	void Precio(const char *pchrPtrPrecio);
	void PrecioEspecial(const char *pchrPtrPrecioEspecial);

	void SePuedeVender(const char *pchrPtrSePuedeVender);
private:
	const unsigned char *SeTienePrecioEspecial(zSiscomRegistro *);
};

#endif
