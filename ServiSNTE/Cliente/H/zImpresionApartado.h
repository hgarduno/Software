#ifndef __ZIMPRESIONAPARTADO_H__
#define __ZIMPRESIONAPARTADO_H__

class zSiscomRegistro;
class zReciboApartado;
class zImpresionApartado
{
public:
	zImpresionApartado();
	void Tienda(zSiscomRegistro *pzSisRegTienda);
	void Cliente(zSiscomRegistro *pzSisRegCliente);
	void Venta(zSiscomRegistro *pzSisRegVenta);
	void Recibo(zReciboApartado *pzRecibo);
	const char *Dato(const char *pchrPtrCampo);
private:
	zSiscomRegistro *zSisRegTienda;
	zSiscomRegistro *zSisRegCliente;
	zSiscomRegistro *zSisRegVenta;
	zReciboApartado *zRecibo;
private:
	const char *Cliente();
	const char *ImporteLetra();
};


#endif
