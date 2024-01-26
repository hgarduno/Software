#ifndef __ZDIRECCION_H__
#define __ZDIRECCION_H__

#include <zSiscomRegistro.h>


class zDireccion:public zSiscomRegistro
{
public:
	zDireccion(const char *pchrPtrIdDireccion,
		 const char *pchrPtrCalle,
		 const char *pchrPtrNumInterior,
		 const char *pchrPtrNumExterior,
		 const char *pchrPtrColonia,
		 const char *pchrPtrDelegMunic,
		 const char *pchrPtrEstado,
		 const char *pchrPtrCodigoPostal,
		 const char *pchrPtrReferencias,
		 const char *pchrPtrIdPersona);
	zDireccion(zSiscomRegistro *pzSisRegDireccion);
	const char *IdDireccion(); 
	const char *Calle(); 
	const char *NumExterior();
	const char *NumInterior();
	const char *Colonia();
	const char *Delegacion();
	const char *Estado();
	const char *CodigoPostal();
	const char *Referencias();
	const char *IdPersona();
	int EsValida();
	
	void Calle(const char *pchrPtrCalle);
	void NumInterior(const char *pchrPtrNumInterior);
	void NumExterior(const char *pchrPtrNumExterior);
	void Colonia(const char *pchrPtrColonia);
	void Delegacion(const char *pchrPtrDelegMunic);
	void Estado(const char *pchrPtrEstado);
	void CodigoPostal(const char *pchrPtrCodigoPostal);
	void Referencias(const char *pchrPtrReferencias);
};

#endif
