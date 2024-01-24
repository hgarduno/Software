#include <SqlEmpleados.h>
void SqlEmpleados(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];

sprintf(lchrArrSql,
	"				\
select *				\
from firmas  inner join			\
     personas using(idPersona)");
SiscomLog("%s",lchrArrSql);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,
			       lchrArrSql);
}


void SqlInsertaSueldo(SArgsSiscom *pSAgsSiscom)
{
SiscomLog("");
SiscomGeneraInsercionActualizacion(
		pSAgsSiscom,
		"SqlSueldos",
		SqlGeneraInsertaSueldo);
}

void SqlActualizaSueldo(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(
		pSAgsSiscom,
		"SqlSueldos",
		SqlGeneraActualizaSueldo);
}

void SqlHistoricoSueldo(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(
		pSAgsSiscom,
		"SqlSueldos",
		SqlGeneraHistoricoSueldo);
}
void SqlGeneraInsertaSueldo(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into Sueldo values(%s,%s);",
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	SiscomObtenDato(pLCSiscomPro2,"Sueldo"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
void SqlGeneraActualizaSueldo(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"update Sueldos set Sueldo=%s where idpersona=%s;",
	SiscomObtenDato(pLCSiscomPro2,"Sueldo"),
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
void SqlGeneraHistoricoSueldo(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
char lchrArrFecha[25];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);
sprintf(lchrArrSQL,
	"insert into HistoricoSueldos values(%s,'%s',%s);",
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	lchrArrFecha,
	SiscomObtenDato(pLCSiscomPro2,"Sueldo"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}


