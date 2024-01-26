#ifndef __ZIMPRESIONRELACIONCHEQUESPAGAR_H__
#define __ZIMPRESIONRELACIONCHEQUESPAGAR_H__
#include <zImpresion.h>


class zRelacionChequesPagar;

class zImpresionRelacionChequesPagar:public zImpresion
{
public:
	zImpresionRelacionChequesPagar(zRelacionChequesPagar *pzLstPrecios);
	void Encabezado();
	zRelacionChequesPagar *RelacionChequesPagar();
private:
	zRelacionChequesPagar *zRelCheqPagar;	
private:
	zSiscomRegistro *RegistroEncabezado(const char *pchrPtrNombre,const char *pchrPtrDato);
};

#endif
