#include <SqlTelefonos.h>

void SqlRegistraTelefonoFisica(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				   "SisSQLPersona",
				   SqlInsertIntoTelefonosFisica);
}

void SqlInsertIntoTelefonosFisica(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"insert into Telefonos values(%s,0,'%s','');",
	 SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	 SiscomObtenDato(pLCSiscomPro2,"Telefono"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlRegistraTelefonoMoral(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				   "SisSQLPersona",
				   SqlInsertIntoTelefonosMoral);
}

void SqlInsertIntoTelefonosMoral(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"insert into Telefonos values(0,%s,'%s','');",
	 SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	 SiscomObtenDato(pLCSiscomPro2,"Telefono"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
