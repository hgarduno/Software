#include <SqlCorreos.h>

void SqlRegistraCorreoFisica(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				   "SisSQLPersona",
				   SqlInsertIntoCorreosFisica);
}

void SqlInsertIntoCorreosFisica(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"insert into Correos values(%s,0,'%s');",
	 SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	 SiscomObtenDato(pLCSiscomPro2,"Correo"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlRegistraCorreoMoral(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				   "SisSQLPersona",
				   SqlInsertIntoCorreosMoral);
}

void SqlInsertIntoCorreosMoral(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"insert into Correos values(0,%s,'%s');",
	 SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	 SiscomObtenDato(pLCSiscomPro2,"Correo"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
