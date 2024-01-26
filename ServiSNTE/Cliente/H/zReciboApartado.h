#ifndef __ZRECIBOAPARTADO_H__
#define __ZRECIBOAPARTADO_H__
#include <zSiscomRegistro.h>

class zReciboApartado:public zSiscomRegistro
{
 public:
    zReciboApartado();
	void Folio(const char *pchrPtrFolio);
	void Tienda(const char *pchrPtrTienda);
	void Fecha(const char *pchrPtrFecha);
	void Apartado(const char *pchrPtrApartado);
	void Cliente(const char *pchrPtrCliente);
	void Importe(const char *pchrPtrImporte);
	void ImporteLetra(const char *pchrPtrImporteLetra);
	void Concepto(const char *pchrPtrConcepto);
	void Elaboro(const char *pchrPtrElaboro);
	void FolioApartado(const char *pchrPtrFolioApartado);
};

#endif
