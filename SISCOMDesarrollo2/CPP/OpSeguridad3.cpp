#include <OpSeguridad3.h>

OpSeguridad3::OpSeguridad3(SiscomDatCom *pSisDatCom):
		SiscomOperaciones3(pSisDatCom)
{


}


void OpSeguridad3::Variable(
			   const char *pchrPtrModuloConsulta,
			   const char *pchrPtrIdExpendio,
			   const char *pchrPtrAplicacion,
			   const char *pchrPtrPantalla,
			   const char *pchrPtrPerfil,
			   const char *pchrPtrVariable,
			   SiscomRegistro3Lst *pSisReg3LstVariable)
{

SiscomEnvia(pchrPtrModuloConsulta,
	    pSisReg3LstVariable,
	    "%s%s%s%s%s%s",
	    "SiscomInfoVariable",
	    pchrPtrIdExpendio,
	    pchrPtrAplicacion,
	    pchrPtrPantalla,
	    pchrPtrPerfil,
	    pchrPtrVariable);


}
