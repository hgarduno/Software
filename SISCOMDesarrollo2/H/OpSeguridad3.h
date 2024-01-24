#ifndef __OPSEGURIDAD3_H__
#define __OPSEGURIDAD3_H__

#include <SiscomOperaciones3.h>

class SiscomRegistro3Lst;
class SiscomDatCom;
class OpSeguridad3:public SiscomOperaciones3
{
public:
	OpSeguridad3(SiscomDatCom *);
	void  Variable(
		       const char *pchrPtrModuloConsulta,
		       const char *pchrPtrIdExpendio,
		       const char *pchrPtrAplicacion,
		       const char *pchrPtrPantalla,
		       const char *pchrPtrPerfil,
		       const char *pchrPtrVariable,
		       SiscomRegistro3Lst *);
};

#endif
