#ifndef __ZEMPLEO_H__
#define __ZEMPLEO_H__
#include <zSiscomRegistro.h>
class zDireccion;
class zPersona;
class zEmpresa;
class zOtrosIngresos;
class zEmpleo:public zSiscomRegistro
{
public:
	zEmpleo(const char *pchrPtrIdPersona);
	zEmpleo(zSiscomRegistro *pzSisRegEmpleo);
	void Jefe(zPersona *pzPersona);
	void Empresa(zEmpresa *pzEmpresa);
	void Puesto(const char *pchrPtrPuesto);
	void Sueldo(const char *pchrPtrSueldo);
	void Antiguedad(const char *pchrPtreAntiguedad);
	void OtrosIngresos(zOtrosIngresos *pzOtrosIng);
	void FrecuenciaPago(zSiscomRegistro *pzSisRegFrecPago);
	void FrecuenciaPago(const char *pchrPtrFrecPago);
	void TotalIngresos(const char *pchrPtrTotalIngresos);

	zPersona *Jefe();
	zEmpresa *Empresa();
};

#endif
