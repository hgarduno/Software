#ifndef __ZIMPRESIONSOPORTETRANSFERENCIAS_H__
#define __ZIMPRESIONSOPORTETRANSFERENCIAS_H__
#include <zImpresion.h>


class zSoporteTransferencias;

class zImpresionSoporteTransferencias:public zImpresion
{
public:
	zImpresionSoporteTransferencias(zSoporteTransferencias *pzLstPrecios);
	void Encabezado();
	zSoporteTransferencias *SoporteTransferencias();
private:
	zSoporteTransferencias *zSptTransferencias;	
private:
	zSiscomRegistro *RegistroEncabezado(const char *pchrPtrNombre,const char *pchrPtrDato);
};

#endif
