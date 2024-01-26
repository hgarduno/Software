#ifndef __ZIMPRESIONSOPORTECOMPRAS_H__
#define __ZIMPRESIONSOPORTECOMPRAS_H__
#include <zImpresion.h>


class zSoporteCompras;

class zImpresionSoporteCompras:public zImpresion
{
public:
	zImpresionSoporteCompras(zSoporteCompras *pzLstPrecios);
	void Encabezado();
	zSoporteCompras *SoporteCompras();
private:
	zSoporteCompras *zSopComp;	
private:
	zSiscomRegistro *RegistroEncabezado(const char *pchrPtrNombre,const char *pchrPtrDato);
};

#endif
