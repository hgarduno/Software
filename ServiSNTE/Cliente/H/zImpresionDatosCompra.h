#ifndef __ZIMPRESIONDATOSCOMPRA_H__
#define __ZIMPRESIONDATOSCOMPRA_H__
#include <zImpresion.h>


class zDatosCompra;

class zImpresionDatosCompra:public zImpresion
{
public:
	zImpresionDatosCompra(zDatosCompra *pzLstPrecios);
	void Departamento(zSiscomRegistro *pzSisRegDepartamento);
	zSiscomRegistro *Departamento();
	void Encabezado();
	zDatosCompra *DatosCompra();
private:
	zDatosCompra *zSopComp;	
	zSiscomRegistro *zSisRegDepartamento;
private:
	zSiscomRegistro *RegistroEncabezado(const char *pchrPtrNombre,const char *pchrPtrDato);
};

#endif
