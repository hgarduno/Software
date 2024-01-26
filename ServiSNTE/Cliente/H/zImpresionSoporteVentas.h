#ifndef __ZIMPRESIONSOPORTEVENTAS_H__
#define __ZIMPRESIONSOPORTEVENTAS_H__
#include <zImpresion.h>


class zSoporteVentas;

class zImpresionSoporteVentas:public zImpresion
{
public:
	zImpresionSoporteVentas(zSoporteVentas *pzLstPrecios);
	void Encabezado();
	zSoporteVentas *SoporteVentas();
private:
	zSoporteVentas *zSptVentas;	
private:
	zSiscomRegistro *RegistroEncabezado(const char *pchrPtrNombre,const char *pchrPtrDato);
};

#endif
