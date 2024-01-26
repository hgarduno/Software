#ifndef __ZVENTAS_H__
#define __ZVENTAS_H__
#include <zSiscomRegistro.h>

class zVentas:public zSiscomRegistro
{
public:
	zVentas();
	zVentas(zSiscomRegistro *pzSisRegRegreso);
	const char *Nombre();
	const char *APaterno();
	const char *AMaterno();
	int Siguiente();
	const char *Importe();
	const char *Folio();
	const char *Fecha();
	const char *TipoVenta();
	const char *Financiadora();
	const char *Plazo();
	const char *Vencimiento();
	int NoVentas();
private:
	void OrdenesVendidas(zSiscomRegistro *);	
private:
	zSiscomRegistros *zSisRegsVentas;
	zSiscomRegistro *zSisRegVenta;
	zSiscomRegistro *zSisRegCliente;
};


#endif
