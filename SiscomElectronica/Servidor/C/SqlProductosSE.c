#include <SqlProductosSE.h>
#include <Cotizando4.h>
#include <ProductosSE.h>
#include <stdio.h>
#include <SiscomDesarrolloMacros.h>

int SqlDefinicionProductoSE(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[256];
sprintf(lchrArrSql,
	"select  *						\n\
	 from definiciontiposproducto as a inner join 		\n\
              existenciaexpendiobodegas as b using(cveproducto)	\n\
	where idproducto = %s 					\n\
	order by cveproducto",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdProducto",pSiscomOpePtrDato));
	

SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "DefinicionProducto%",
		   lchrArrSql);
return 0;
}


int SqlTiposProductoSE(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[256];
sprintf(lchrArrSql,
	"			\n\
	 select *		\n\
	 from tipoproductos");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "TiposProducto%",
		   lchrArrSql);
return 0;
}


int SqlProductosSiscomElectronica(SiscomOperaciones *pSiscomOpePtrDato)
{
  if(LlegoCriterioBusqueda(pSiscomOpePtrDato))
   SqlProductosSimilares(pSiscomOpePtrDato);
   else
   SqlProductosSE(pSiscomOpePtrDato);
return 0;
}

int SqlProductosSimilares(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[2048],
	lchrArrSql[2048];


sprintf(lchrArrSql,
	"									\n\
	select cveproducto,							\n\
	       dscproducto,							\n\
	       substring(dscproducto,1,50) as dsccorta,				\n\
	       existencia,							\n\
	       exbodegas,							\n\
	       precio,								\n\
	       caja,								\n\
	       estante,								\n\
	       idestante,							\n\
	       idcaja,								\n\
	       g.nombre								\n\
	from productos as a inner join 						\n\
	     existenciaexpendiobodegas as b using(cveproducto) inner join	\n\
	     precios as c using(cveproducto) left outer join			\n\
	     UbicacionProducto as d using(cveproducto) left outer join 		\n\
	     CajaMaterial as e using(idCaja) left outer join			\n\
	     Estante as f using(idestante) inner join 				\n\
	     personas as g using(idpersona)					\n\
	where c.nmbtipoprecio='DEFAULT' and					\n\
	      g.nombre='Publico En General' and					\n\
	      upper(cveproducto) like upper('%%%s%%')				\n\
	union									\n\
	select cveproducto,							\n\
		dscproducto,							\n\
	       substring(dscproducto,1,30) as dsccorta,				\n\
		existencia,							\n\
		exbodegas,							\n\
		precio,								\n\
		caja,								\n\
		estante,							\n\
		idestante,							\n\
		idcaja,								\n\
		g.nombre							\n\
	from productos as a inner join 						\n\
		existenciaexpendiobodegas as b using(cveproducto) inner join	\n\
	        precios as c using(cveproducto) left outer join			\n\
	        UbicacionProducto as d using(cveproducto) left outer join 	\n\
	        CajaMaterial as e using(idCaja) left outer join			\n\
		Estante as f using(idestante) inner join			\n\
		personas as g using(idpersona)					\n\
	where c.nmbtipoprecio='DEFAULT' and 					\n\
	       g.nombre='Publico En General' and				\n\
		upper(dscproducto) like upper('%%%s%%')				\n\
	order by cveproducto",
	SiscomCampoAsociadoEntradaOperacion("Envio","Criterio",pSiscomOpePtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","Criterio",pSiscomOpePtrDato));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "Productos%",
		   lchrArrSql);
}
int SqlProductosSE(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"									\n\
	select a.*,								\n\
	     	b.idtipoproducto, 						\n\
		b.idproducto,							\n\
		d.idcaja,							\n\
		d.caja,								\n\
		e.estante,							\n\
		e.idestante							\n\
	from productos as a left outer join 					\n\
	     productoportipoproducto as b using(cveproducto) left outer join	\n\
	     UbicacionProducto as c using(cveproducto) left outer join 		\n\
	     CajaMaterial as d using(IdCaja) left outer join			\n\
	     Estante as e  using(idestante)					\n\
	order by cveproducto");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "Productos%",
		   lchrArrSql);
}
int SqlDefinicionProducto(SiscomRegistroProL *pSiscomRegProLPtrProducto,
			  SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];
if(EsProductoPractica(pSiscomRegProLPtrProducto))
sprintf(lchrArrSql,
	"							\n\
select a.*,							\n\
	b.precio,						\n\
	a.cantidad*precio as importe,				\n\
	c.exbodegas,						\n\
	1 as SiCotiza,						\n\
	1 as SePuedeVender					\n\
from definiciontiposproducto as a inner join 			\n\
     precios as b using(cveproducto) inner join			\n\
     existenciaexpendiobodegas as c using(cveproducto)		\n\
where idpersona in(%s) and 					\n\
      idproducto in(select idproducto 				\n\
                    from productoportipoproducto 		\n\
		    where cveproducto ='%s')			\n\
order by a.ctid;",
SiElClienteEsNuloUsaPublicoGeneral(pSiscomOpePtrDato),
SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrProducto));
else
if(EsProductoKit(pSiscomRegProLPtrProducto)   ||
   EsProductoSiscom(pSiscomRegProLPtrProducto) ||
   EsCircuitoImpreso(pSiscomRegProLPtrProducto))
sprintf(lchrArrSql,
	"						\n\
select a.*,						\n\
	c.existencia,					\n\
	c.exbodegas,					\n\
	0 as precio,					\n\
	0 as importe,					\n\
	1 as SiCotiza,					\n\
	1 as SePuedeVender				\n\
from definiciontiposproducto as a inner join 		\n\
     precios as b using(cveproducto) inner join		\n\
     existenciaexpendiobodegas as c using(cveproducto) 	\n\
where idpersona in(%s) and 				\n\
      idproducto in(select idproducto 			\n\
                    from productoportipoproducto 	\n\
		    where cveproducto ='%s')		\n\
order by a.ctid;",
SiElClienteEsNuloUsaPublicoGeneral(pSiscomOpePtrDato),
SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrProducto));

SiscomConsultaSqlAArgumentoOperaciones(lchrArrSql,
				       "SqlDefinicionProducto",
				        lchrArrBuffer,
					pSiscomOpePtrDato);
}
