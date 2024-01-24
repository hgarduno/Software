#include <SQLReportes.h>
void SQLReporteVentas(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[1024];
sprintf(lchrArrSQL,
"							\
select count(*) as ordenes,				\
       sum(importe) as total,				\
       fecha::date					\
from ventas						\
where fecha::date>='%s' and				\
      fecha::date<='%s'	and				\
      edoventa=0					\
group by fecha::date					\
union							\
select 0 as ordenes,					\
       sum(importe) as total,				\
       '2007-01-01' as Fecha				\
from ventas						\
where fecha::date>='%s' and				\
      fecha::date<='%s'					\
order by 3 desc						\
",
pSAgsSiscom->chrPtrArgConsulta[1],
pSAgsSiscom->chrPtrArgConsulta[2],
pSAgsSiscom->chrPtrArgConsulta[1],
pSAgsSiscom->chrPtrArgConsulta[2]);
	EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}

void SQLDetalleVentas(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[1024];
sprintf(lchrArrSQL,
"								\
select	c.idproducto,						\
	c.clave,						\
	c.dsc as dscproducto,					\
        sum(a.cantidad) as cantidad,				\
	sum(total)  as importe,					\
	b.precio						\
from detalleventa as a inner join preciosproducto as b		\
	on (a.idprecio=b.idprecio and 				\
	    a.idproducto=b.idproducto) inner join		\
     producto as c on (a.idproducto=c.idproducto) inner join	\
     ventas using(idventa)					\
where fecha::date>='%s' and					\
      fecha::date<='%s'						\
group by c.clave,						\
	c.dsc,							\
	b.precio,						\
	c.idproducto",
pSAgsSiscom->chrPtrArgConsulta[1],
pSAgsSiscom->chrPtrArgConsulta[2]);
EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);


}
