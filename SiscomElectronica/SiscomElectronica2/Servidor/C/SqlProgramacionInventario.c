#include <SqlProgramacionInventario.h>
#include <string.h>
void SqlRegistraProgramacionInventario(SArgsSiscom *pSAgsSiscom)
{
  SiscomInsercionActualizacionEntradaSubRegistroAArgumento(
  	pSAgsSiscom,
	"SqlProgramaInventario",
	SqlGenerandoRegistroProgramacionInventario);
}
void SqlGenerandoRegistroProgramacionInventario(
			const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
			SArgsSiscom *pSAgsSiscom,
			LCamposSiscomPro2 **pLCSiscomPro2Prim,
			LCamposSiscomPro2 **pLCSiscomPro2Act,
			int *pintPtrNRegistros)
{
char lchrArrSql[256];
char lchrArrIdInventario[25];
char lchrArrFechaInicio[25];
char lchrArrFechaFin[25];
SiscomObtenNumeroUnicoChar(lchrArrIdInventario);
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFechaInicio);
strcpy(lchrArrFechaFin,lchrArrFechaInicio);
sprintf(lchrArrSql,
	"insert into ProgramaInventario values(%s,%s,'%s','%s','%s');",
	SiscomCampoSubRegistroArgs(0,"idmotivo",pSAgsSiscom),
	lchrArrIdInventario,
	lchrArrFechaInicio,
	lchrArrFechaFin,
	SiscomCampoSubRegistroArgs(1,"Descripcion",pSAgsSiscom));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlInventariosProgramados(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"select *			\n\
	 from ProgramaInventario	\n\
	 where idmotivo!=0");
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}
