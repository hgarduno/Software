#ifndef __ZIMPRESIONLISTAPRECIOS_H__
#define __ZIMPRESIONLISTAPRECIOS_H__
#include <zImpresion.h>


class zListaPrecios;

class zImpresionListaPrecios:public zImpresion
{
public:
	zImpresionListaPrecios(zListaPrecios *pzLstPrecios,const char *pchrPtrNombre);
	void Encabezado(const char *pchrPtrNombre);
	zListaPrecios *ListaPrecios();
	zSiscomRegistro *RegistroEncabezado(const char *pchrPtrNombre,
				   const char *pchrPtrDato);
private:
	zListaPrecios *zLstPrecios;	
private:
};

#endif
