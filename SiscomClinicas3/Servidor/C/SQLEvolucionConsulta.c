#include <SQLEvolucionConsulta.h>

void SQLRegistraEvolucionConsulta(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "Consultas",
				   SQLGeneraRegistroEvolucionConsulta);
}

void SQLGeneraRegistroEvolucionConsulta(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into EvolucionConsulta values(%s,%s,'%s',%s);",
	SiscomObtenDato(pLCSiscomPro2,"IdConsulta"),
	SiscomObtenDato(pLCSiscomPro2,"IdEmpleado"),
	SiscomObtenDato(pLCSiscomPro2,"Fecha"),
	SiscomObtenDato(pLCSiscomPro2,"IdEdo"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
