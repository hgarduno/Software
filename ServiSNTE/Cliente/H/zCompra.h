#ifndef __ZCOMPRA_H__
#define __ZCOMPRA_H__
#include <zSiscomRegistro.h>

class zOrden;
class zCompra:public zSiscomRegistro
{
  public:
  	zCompra();
	void IdCompra(const unsigned char *pchrPtrIdCompra);
	void IdProveedor(const unsigned char *pchrPtrIdTipoCompra);
	void IdTipoDocumento(const unsigned char *pchrPtrIdFinanciadora);
	void IdConcepto(const unsigned char *pchrPtrIdConcepto);
	void SerieFactura(const char *pchrPtrIdTiendaEntrega);
	void Folio(const char *pchrPtrFolio);
	void Fecha(const char *pchrPtrFecha);
	void Orden(zOrden *pzOrden);
};



#endif


