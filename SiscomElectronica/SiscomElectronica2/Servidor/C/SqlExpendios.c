#include <SqlExpendios.h>


void SqlExpendios(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];

sprintf(lchrArrSql,
	"				\n\
	SELECT * 			\n\
	from expendios inner join 	\n\
	empresas using(idempresa);	\n\
");
SiscomLog("%s",lchrArrSql);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,
			       lchrArrSql);
}

void SqlInsertaExpendio(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				   "SqlExpendios",
				   SqlGeneraInsertaExpendio);
}
void SqlGeneraInsertaExpendio(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[512];
char lchrArrFechaHoy[35];
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
sprintf(lchrArrSql,
	"insert into Expendios values(%s,%s,'%s','%s');",
	 SiscomObtenDato(pLCSiscomPro2,"ExpendioId"),
	 SiscomObtenDato(pLCSiscomPro2,"Puerto"),
	 SiscomObtenDato(pLCSiscomPro2,"DireccionIp"),
	 SiscomObtenDato(pLCSiscomPro2,"Base"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}


void SqlActualizaExpendio(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				   "SqlExpendios",
				   SqlGeneraActualizaExpendio);
}
void SqlGeneraActualizaExpendio(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[512];
char lchrArrFechaHoy[35];
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
sprintf(lchrArrSql,
	"update expendios set ptocomad=%s, "
	"                    diripsvrad='%s', "
	"                    basedatos='%s' "
	"where idempresa=%s",
	 SiscomObtenDato(pLCSiscomPro2,"Puerto"),
	 SiscomObtenDato(pLCSiscomPro2,"DireccionIp"),
	 SiscomObtenDato(pLCSiscomPro2,"Base"),
	 SiscomObtenDato(pLCSiscomPro2,"ExpendioId"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
void SqlInsertaEmpresa(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				   "SqlExpendios",
				   SqlGeneraInsertaEmpresa);
}
void SqlGeneraInsertaEmpresa(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[512];
char lchrArrFechaHoy[35];
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
sprintf(lchrArrSql,
	"insert into Empresas values('%s',%s,'%s');",
	 SiscomObtenDato(pLCSiscomPro2,"RazonSocial"),
	 SiscomObtenDato(pLCSiscomPro2,"ExpendioId"),
	 SiscomObtenDato(pLCSiscomPro2,"RFC"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlActualizaEmpresa(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				   "SqlExpendios",
				   SqlGeneraActualizaEmpresa);
}
void SqlGeneraActualizaEmpresa(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[512];
char lchrArrFechaHoy[35];
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
sprintf(lchrArrSql,
	"update empresas set razonsocial='%s', "
	"                    rfc='%s' "
	"where idempresa=%s",
	 SiscomObtenDato(pLCSiscomPro2,"RazonSocial"),
	 SiscomObtenDato(pLCSiscomPro2,"RFC"),
	 SiscomObtenDato(pLCSiscomPro2,"ExpendioId"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
