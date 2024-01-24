#include <SqlBodegas.h>
void SqlBodegas(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"				\n\
	SELECT * 			\n\
	from bodegas"); 
SiscomEjecutaConsultaYResponde(pSAgsSiscom,
			       lchrArrSql);
}


void SqlExistenciaProductoBodega(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"				\n\
	SELECT * 			\n\
	from materialbodega 		\n\
	where idbodega=%s and 		\n\
	      CveProducto='%s'",
pSAgsSiscom->chrPtrArgConsulta[2],
pSAgsSiscom->chrPtrArgConsulta[3]);
SiscomLog("%s",lchrArrSql);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,
			       lchrArrSql);
}

void SqlActualizaMaterialBodega(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				   "SqlBodegas",
				   SqlGeneraActualizaMaterialBodega);
}
void SqlGeneraActualizaMaterialBodega(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"update MaterialBodega set existencia=existencia-%s "
	 "where idbodega=%s and " 
	 "CveProducto='%s'",
	 SiscomObtenDato(pLCSiscomPro2,"Cantidad"),
	 SiscomObtenDato(pLCSiscomPro2,"idbodega"),
	 SiscomObtenDato(pLCSiscomPro2,"cveproducto"));

SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}


void SqlInsertaBodegaAExpendio(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				   "SqlBodegas",
				   SqlGeneraInsertaBodegaAExpendio);
}
void SqlGeneraInsertaBodegaAExpendio(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[512];
char lchrArrFechaHoy[35];
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
sprintf(lchrArrSql,
	"insert into BodegaAExpendio values(%s,%s,'%s',%s,%s,'%s');",
	 SiscomObtenDato(pLCSiscomPro2,"idbodega"),
	 SiscomObtenDato(pLCSiscomPro2,"idempresa"),
	 lchrArrFechaHoy,
	 SiscomObtenDato(pLCSiscomPro2,"IdEmpleado"),
	 SiscomObtenDato(pLCSiscomPro2,"Cantidad"),
	 SiscomObtenDato(pLCSiscomPro2,"cveproducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlInsertaInventarioBodega(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				   "SqlInventarioBodega",
				   SqlGeneraInsertaInventarioBodega);
}
void SqlGeneraInsertaInventarioBodega(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[512];
char lchrArrFechaHoy[35];
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
sprintf(lchrArrSql,
	"insert into InventarioBodega values(%s,'%s','%s',%s,%s,%s);",
	 SiscomObtenDato(pLCSiscomPro2,"idbodega"),
	 lchrArrFechaHoy,
	 SiscomObtenDato(pLCSiscomPro2,"cveproducto"),
	 SiscomObtenDato(pLCSiscomPro2,"Cantidad"),
	 SiscomObtenDato(pLCSiscomPro2,"existencia"),
	 SiscomObtenDato(pLCSiscomPro2,"IdEmpleado"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlActualizaExistenciaExpendio(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				   "SqlExpendio",
				   SqlGeneraActualizaExistenciaExpendio);
}
void SqlGeneraActualizaExistenciaExpendio(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"update existencias set existencia=existencia+%s "
	"where cveproducto='%s' and "
	"idexpendio=%s",
	 SiscomObtenDato(pLCSiscomPro2,"Cantidad"),
	 SiscomObtenDato(pLCSiscomPro2,"cveproducto"),
	 SiscomObtenDato(pLCSiscomPro2,"idempresa"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlActualizaExistenciaBodega(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				   "SqlInventarioBodega",
				   SqlGeneraActualizaExistenciaBodega);
}
void SqlGeneraActualizaExistenciaBodega(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"update MaterialBodega set existencia=%s "
	"where cveproducto='%s' and "
	"IdBodega=%s",
	 SiscomObtenDato(pLCSiscomPro2,"Cantidad"),
	 SiscomObtenDato(pLCSiscomPro2,"cveproducto"),
	 SiscomObtenDato(pLCSiscomPro2,"idbodega"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
