#ifndef __ZCOMPRAPARCIALIMPORTACION_H__
#define __ZCOMPRAPARCIALIMPORTACION_H__

#include <zSiscomRegistro.h> 

class zCompraImportacion;
class zCompraParcialImportacion:public zSiscomRegistro
{
public:
	zCompraParcialImportacion();
	void Parcial(zCompraImportacion *pzCompraI);
	void Compra(zCompraImportacion *pzCompraC);
};

#endif
