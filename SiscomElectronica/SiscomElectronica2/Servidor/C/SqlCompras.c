#include <SqlCompras.h>

void SqlHistoricoComprasExistenciaMinima(
			SArgsSiscom *pSArgsSiscom)
{
char lchrArrSql[2048];
sprintf(lchrArrSql,
	"									\
select										\
	h.fecha::date as fecha,							\
	h.fecha::time as hora ,							\
	h.CveProducto,								\
	i.existencia,								\
	h.precio as PrecioCompra, 						\
	h.cantidad,								\
	h.numfactura,								\
	a.Precio as PrecioVenta,  						\
	b.IdEmpresa as IdProveedor, 						\
	b.RazonSocial as Proveedor,						\
	0 as comprassemanterior,						\
	0 as ventastotalessemanterior,						\
	0 as cantidadvendidaactual						\
from   compras as h 								\
	left outer join precios as a on (h.CveProducto=a.CveProducto and	\
					 NmbTipoPrecio='DEFAULT') 		\
	left outer join empresas as b on(proveedor=b.idempresa)    		\
	left outer join existencias as i on(h.idexpendio=i.idexpendio and	\
	                                    h.cveproducto=i.cveproducto)	\
where 	h.CveProducto in (							\
			  select cveproducto					\
			  from    vporexistenciaminima				\
			  where poreximinima>=%s and 				\
			  poreximinima<=%s and 					\
			  idexpendio=%s)					\
			  	                               and		\
	h.idExpendio=%s								\
order by h.cveproducto,h.fecha desc						\
",
pSArgsSiscom->chrPtrArgConsulta[2],
pSArgsSiscom->chrPtrArgConsulta[3],
pSArgsSiscom->chrPtrArgConsulta[1],
pSArgsSiscom->chrPtrArgConsulta[1]);
SiscomConsultaBaseSinEnvio2(lchrArrSql,
			   pSArgsSiscom);
SiscomLog("%s",lchrArrSql);
}
void SqlHistoricoCompras(SArgsSiscom *pSArgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"									\n\
select										\n\
	h.fecha::date as fecha,							\n\
	h.fecha::time as hora ,							\n\
	h.CveProducto,								\n\
	i.existencia,								\n\
	h.precio as PrecioCompra, 						\n\
	h.cantidad,								\n\
	h.numfactura,								\n\
	a.Precio as PrecioVenta,  						\n\
	b.IdEmpresa as IdProveedor, 						\n\
	b.RazonSocial as Proveedor,						\n\
	0 as comprassemanterior,						\n\
	0 as ventastotalessemanterior,						\n\
	0 as cantidadvendidaactual						\n\
from   compras as h 								\n\
	left outer join precios as a on (h.CveProducto=a.CveProducto and	\n\
					 NmbTipoPrecio='DEFAULT') 		\n\
	left outer join empresas as b on(proveedor=b.idempresa)    		\n\
	left outer join existencias as i on(h.idexpendio=i.idexpendio and	\n\
	                                    h.cveproducto=i.cveproducto)	\n\
where 	h.CveProducto='%s'	and						\n\
	h.idExpendio=%s 	and						\n\
	a.idpersona in(select idpersona						\n\
                       from personas						\n\
                       where rfc='GENERAL')					\n\
order by h.fecha desc								\n\
",
pSArgsSiscom->chrPtrArgConsulta[2],
pSArgsSiscom->chrPtrArgConsulta[1]);
SiscomConsultaBaseSinEnvio2(lchrArrSql,
			   pSArgsSiscom);
/*SiscomContenidoProtocolo(pSArgsSiscom->LCSiscomPro2Regreso); */
}
void SqlComprasSemestreAnterior(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
int lintNRegRespuesta;
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
sprintf(lchrArrSql,
	"select sum(cantidad) as total	\n\
	 from compras 			\n\
	 where cveproducto='%s'	 and 	\n\
	       fecha::date>='%s' and 	\n\
	       fecha::date<='%s' and	\n\
	       idexpendio=%s",
	 pSAgsSiscom->chrPtrArgConsulta[2],
	 pSAgsSiscom->chrPtrArgConsulta[4],
	 pSAgsSiscom->chrPtrArgConsulta[5],
	 pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomConsultaBaseSinEnvio(
		lchrArrSql,
		pSAgsSiscom,
		&lintNRegRespuesta,
		&lLCSiscomPro2Reg);
SiscomAsignaDatoCampo2("comprassemanterior",
		        ObtenTotales(lLCSiscomPro2Reg),
			pSAgsSiscom->LCSiscomPro2Regreso);
			
}
void SqlVentasTotalesSemestreAnterior(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
int lintNRegRespuesta;
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
sprintf(lchrArrSql,
	"select sum(cantidad)	as total	\n\
	 from ventas 				\n\
	 where cveproducto='%s'	 and 		\n\
	       fechahora::date>='%s' and 	\n\
	       fechahora::date<='%s' and	\n\
	       idexpendio=%s",
	 pSAgsSiscom->chrPtrArgConsulta[2],
	 pSAgsSiscom->chrPtrArgConsulta[4],
	 pSAgsSiscom->chrPtrArgConsulta[5],
	 pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomConsultaBaseSinEnvio( lchrArrSql,
		pSAgsSiscom,
		&lintNRegRespuesta,
		&lLCSiscomPro2Reg);
SiscomAsignaDatoCampo2("ventastotalessemanterior",
		        ObtenTotales(lLCSiscomPro2Reg),
			pSAgsSiscom->LCSiscomPro2Regreso);
}
const char *ObtenTotales(LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
const char *lchrPtrRegreso;
lchrPtrRegreso=SiscomObtenDato(pLCSiscomPro2Dat,"total");
return lchrPtrRegreso[0] ? lchrPtrRegreso : "0.0";
}
