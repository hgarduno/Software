select cveproducto,
	cantidad,
	existencia
from ventas as a inner join
	existencias as b using(cveproducto) left outer join
	productoportipoproducto as c using(cveproducto)
where fechahora::date>='2018-04-01' and 
	idtipoproducto is null 
union all
select cveproducto,
	cantidad,
	existencia
from ventas as a inner join
	existencias as b using(cveproducto) left outer join
	productoportipoproducto as c using(cveproducto)
where fechahora::date>='2018-04-01' and 
      idtipoproducto=0
union all
select cveproducto,
	0,
	existencia
from    existencias as a inner join
	definiciontiposproducto as b using(cveproducto)
where b.idproducto in(
		select b.idproducto 
		 from ventas inner join
		      productoportipoproducto as b using(cveproducto)
		 where fechahora::date='2018-04-01' and idtipoproducto in(1,2))
		 
		     
