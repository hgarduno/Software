#include <SqlOrdenes.h>

void SqlAnexarOrdenContabilidad(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(
	pSAgsSiscom,
	"SqlOrdenes",
	SqlGeneraAnexarOrdenContabilidad);
}
void SqlGeneraAnexarOrdenContabilidad(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			      LCamposSiscomPro2 **pLCSiscomPro2Prim,
			      LCamposSiscomPro2 **pLCSiscomPro2Act,
			      int *pintPtrNRegistros)
{
char lchrArrSql[256];
LCamposSiscomPro2 *lLCSiscomPro2Dat=pLCSiscomPro2Dat;
for(;
	lLCSiscomPro2Dat;
    lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
{
sprintf(lchrArrSql,
	"insert into OrdenesFacturadas values(0,%s);",
	SiscomObtenDato(lLCSiscomPro2Dat,"idventa"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
}

void SqlOrdenesVendidas(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"				\n\
select idventa,				\n\
	fechahora,			\n\
	sum(importe) as total,		\n\
	0   	as \"IdExpendio\"	\n\
from ventas				\n\
where fechahora::date>='%s' and 	\n\
      fechahora::date<='%s' and 	\n\
      idexpendio=%s			\n\
group by idventa,			\n\
	 fechahora			\n\
order by fechahora",
	 pSAgsSiscom->chrPtrArgConsulta[2],
	 pSAgsSiscom->chrPtrArgConsulta[3],
	 pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}
void SqlDetalleOrden(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"select * 		\n\
	 from ventas		\n\
	 where idventa=%s",
	 pSAgsSiscom->chrPtrArgConsulta[2]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}
