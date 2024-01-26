#include <zDescuento.h>
#include <zSiscomCampo.h>
#include <zSiscomDesarrollo4.h>

zDescuento::zDescuento(const char *pchrPtrIdDescuento,
	       const char *pchrPtrD1,
	       const char *pchrPtrD2,
	       const char *pchrPtrD3,
	       const char *pchrPtrD4,
	       const char *pchrPtrFecha)
{
LogSiscom("%x",this);
  (*this) << 
  new zSiscomCampo("iddescuentoempresa",(unsigned char *)pchrPtrIdDescuento)	<<
  new zSiscomCampo("d1",(unsigned char *)pchrPtrD1)			<<
  new zSiscomCampo("d2",(unsigned char *)pchrPtrD2)			<<
  new zSiscomCampo("d3",(unsigned char *)pchrPtrD3)			<<
  new zSiscomCampo("d4",(unsigned char *)pchrPtrD4)			<<
  new zSiscomCampo("fecha",(unsigned char *)pchrPtrFecha);

}


