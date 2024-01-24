#include <SqlDatosProductosPorFamilia.h>


void SqlProductosPorFamilia(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];

sprintf(lchrArrSql,
	"select idproducto,clave,dsc			\n\
	 from famproducto as a inner join		\n\
	      producto as b using(idproducto)		\n\
	 where idfamilia=%s 				\n\
	 order by idproducto",
	 pSAgsSiscom->chrPtrArgConsulta[1]);

SiscomConsultaBaseAsignaArgumento("SqlProductos",
				  lchrArrSql,
				  pSAgsSiscom);
}
void SqlPreciosProductosPorFamilia(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"select idproducto,				\n\
		idprecio,				\n\
		precio,					\n\
		a.cantidad,				\n\
		nombre,					\n\
		dsc,					\n\
		0 as porganancia			\n\
	 from preciosproducto as a inner join		\n\
	      precios as b using(idprecio)		\n\
	 where idproducto in(select idproducto		\n\
	 			from famproducto	\n\
				where idfamilia=%s)	\n\
	order by idproducto",
	 pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomConsultaBaseAsignaArgumento("SqlPreciosProducto",
				  lchrArrSql,
				  pSAgsSiscom);
}

void SqlUltimaCompraProducto(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"select a.*,b.razonsocial			\n\
	 from compras as a inner join			\n\
	      empresas as b using(idempresa)		\n\
	 where idproducto in(select idproducto		\n\
	 			from famproducto	\n\
				where idfamilia=%s)	\n\
	order by fecha					\n\
	",
	 pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomConsultaBaseAsignaArgumento("SqlUltimaCompra",
				  lchrArrSql,
				  pSAgsSiscom);
}
