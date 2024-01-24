#ifndef __ZDIRECCION_H__
#define __ZDIRECCION_H__
#include <zSiscomRegistro.h>

class zDireccion:public zSiscomRegistro
{
public:
	zDireccion(const char *pchrPtrIdDireccion,
		   const char *pchrPtrCalle,
		   const char *pchrPtrNumero,
		   const char *pchrPtrNumeroInt,
		   const char *pchrPtrDelegacion,
		   const char *pchrPtrColonia,
		   const char *pchrPtrEstado,
		   const char *pchrPtrCP);
	zDireccion(zSiscomRegistro *pzSisRegDireccion);
	void Referencias(const char *pchrPtrReferencias);
	void Calle1(const char *);
	void Calle2(const char *);
	void IdDireccion0(const char *);
	const char *Calle();
	const char *Numero();
	const char *NumeroInt();
	const char *Delegacion();
	const char *Colonia();
	const char *CP();
	const char *Estado();
	const char *Calle1();
	const char *Calle2();
	const char *Referencias();
	const char *IdDireccion0();
	
static	zDireccion *Direccion(zSiscomRegistro *);

};

#endif
