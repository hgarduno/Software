#include <SqlContabilidad.h>
/*
 * Las funciones de los modulos de contabilidad
 * tendras seran relacionados a un proceso contable
 * mediante idProceso de la tabla ProcesoContabilidad
 * en este punto se toma por el tiempo, el proceso de
 * analisis sobre el proceso IdProceso=0
 */
void SqlProductosVendidosFacturados(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"							\n\
select b.fechahora::date,					\n\
	b.cantidad,						\n\
	b.cveproducto,						\n\
	b.precio,						\n\
	b.precio*b.cantidad as total				\n\
from ordenesfacturadas as a					\n\
	inner join ventas as b using(idventa)			\n\
--where b.cveproducto in (select cveproducto			\n\
--			 from facturascompras inner join	\n\
--			      compras using(numfactura)) and	\n\
--     idproceso=%s						\n\
order by cveproducto,						\n\
	 fechahora,						\n\
	 precio",
pSAgsSiscom->chrPtrArgConsulta[2]);
SiscomConsultaBaseAsignaArgumento("SqlVendidosFacturados",
				  lchrArrSql,
				  pSAgsSiscom);
}
void SqlComprasProductosVendidos(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"							\n\
select b.fecha::date,						\n\
       b.cantidad,						\n\
       b.cveproducto,						\n\
       b.precio,						\n\
       b.preciosiniva,						\n\
       0 as cuantostomo						\n\
from facturascompras as a inner join				\n\
      compras as b using(numfactura) 				\n\
--where b.cveproducto in(select cveproducto			\n\
--		       from ordenesfacturadas inner join	\n\
--		            ventas using (idventa)) and 	\n\
--      idProceso=%s						\n\
order by cveproducto,						\n\
	 fecha,							\n\
	 precio",
pSAgsSiscom->chrPtrArgConsulta[2]);
SiscomConsultaBaseAsignaArgumento("SqlComprasProductos",
				  lchrArrSql,
				  pSAgsSiscom);
}

void SqlInsertaResultadoContable(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion2A(
		pSAgsSiscom,
		"Resultados",
		"SqlResultados",
		SqlGeneraInsertaResultadoContable);
}

void SqlGeneraInsertaResultadoContable(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[1024];
for(;
	pLCSiscomPro2;
     pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
{
sprintf(lchrArrSQL,
	"insert into ResultadoContable values(%s,'%s',%s,%s,%s,%s,%s,%s);",
	SiscomObtenDato(pLCSiscomPro2,"IdProceso"),
	SiscomObtenDato(pLCSiscomPro2,"CveProducto"),
	SiscomObtenDato(pLCSiscomPro2,"Cantidad"),
	SiscomObtenDato(pLCSiscomPro2,"VentaTotal"),
	SiscomObtenDato(pLCSiscomPro2,"Ganancia"),
	SiscomObtenDato(pLCSiscomPro2,"Existencia"),
	SiscomObtenDato(pLCSiscomPro2,"ImporteExistencia"),
	SiscomObtenDato(pLCSiscomPro2,"EdoCalculo"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
}
