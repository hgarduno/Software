#include <SqlEmpresas.h>

void SqlRegistraEmpresa(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				   "SisSQLPersona",
				   SqlInsertIntoEmpresas);
}

void SqlInsertIntoEmpresas(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"insert into Empresas values('%s',%s,'%s');",
	 SiscomObtenDato(pLCSiscomPro2,"RazonSocial"),
	 SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	 SiscomObtenDato(pLCSiscomPro2,"RFC"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
