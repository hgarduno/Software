#include <SQLOrdenes.h>
void SQLOrdenVendida(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[2048];

sprintf(lchrArrSQL,
"									\
select	idfamilia,							\
	familia,							\
	b.idproducto,							\
	clave,								\
	d.dsc as dscproducto,						\
	cantidad,							\
	precio,								\
	total,								\
	idventa,							\
	a.idExpendio,							\
	c.existencia,							\
	b.idprecio,							\
	h.nombre as NmbPrecio,						\
	a.edoventa							\
from	ventas as a inner join 						\
	detalleventa as b using(idventa) inner join			\
	preciosproducto g on (b.idprecio=g.idprecio and			\
	                      b.idproducto=g.idproducto) inner join	\
	inventario as  c on (c.idproducto=b.idproducto) inner join	\
     	producto as d on (c.idproducto=d.idproducto) inner  join	\
     	famproducto as e on (c.idproducto=e.idproducto) inner join	\
     	familia as f using(idFamilia) inner join			\
	precios as h on (b.idprecio=h.idprecio)				\
where a.idventa=%s and							\
      a.idexpendio=%s							\
union									\
select	-1,								\
	'',								\
	0,								\
	'Orden',							\
	'',								\
	0,								\
	0,								\
 	importe,							\
 	0,								\
	0,								\
	0,								\
	0,								\
	'',								\
	0								\
from ventas								\
where idventa=%s and							\
      idexpendio=%s							\
order by 1 desc",
pSAgsSiscom->chrPtrArgConsulta[1],
pSAgsSiscom->chrPtrArgConsulta[2],
pSAgsSiscom->chrPtrArgConsulta[1],
pSAgsSiscom->chrPtrArgConsulta[2]);
EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}

void SQLOrdenesVendidas(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[1024];
sprintf(lchrArrSQL,
"									\n\
select	tipocliente as tipopersona,					\n\
	idEmpresa  as identificador,					\n\
	razonsocial,							\n\
	personas.idpersona,						\n\
	personas.nombre,						\n\
	personas.apaterno,						\n\
	personas.amaterno,						\n\
	idventa,							\n\
	fecha,								\n\
	importe,							\n\
	contactosempresa.idpersona as idcontacto,			\n\
	a.nombre as NomContacto,					\n\
	a.apaterno as ApatContacto,					\n\
	formapago.idformapago,						\n\
	formapago.nombre as formapago,					\n\
	diassigpago							\n\
from	ventas left outer join						\n\
	ventasfisicas using(idventa) left outer join			\n\
	ventasmorales using(idventa) left outer join			\n\
	personas using(idpersona)   left outer join			\n\
	empresas using(idempresa) left outer join 			\n\
	contactosempresa using(idempresa) left outer join		\n\
	personas as a on(						\n\
	     a.idpersona=contactosempresa.idpersona) inner join 	\n\
	formapago using(idformapago)					\n\
where idexpendio=%s and							\n\
      edoventa=%s   and	   						\n\
      fecha::date>='%s'  and						\n\
      fecha::date<='%s'							\n\
",
pSAgsSiscom->chrPtrArgConsulta[1],
pSAgsSiscom->chrPtrArgConsulta[4],
pSAgsSiscom->chrPtrArgConsulta[2],
pSAgsSiscom->chrPtrArgConsulta[3]);

SiscomLog("%s",lchrArrSQL);
	EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}
