#ifndef __ZIMPRESIONCUENTASPAGAR_H__
#define __ZIMPRESIONCUENTASPAGAR_H__
#include <zImpresion.h>


class zCuentasPagar;

class zImpresionCuentasPagar:public zImpresion
{
public:
	zImpresionCuentasPagar(zCuentasPagar *pzLstPrecios);
	void Encabezado();
	zCuentasPagar *CuentasPagar();
private:
	zCuentasPagar *zCtsPagar;	
private:
	zSiscomRegistro *RegistroEncabezado(const char *pchrPtrNombre,const char *pchrPtrDato);
};

#endif
