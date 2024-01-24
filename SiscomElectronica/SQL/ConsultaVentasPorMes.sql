select sum(cantidad),
	cveproducto,
	extract(month from fechahora)
from ventas
where edoventa in(0,4) and 
	fechahora::date>='2018-01-01' and 
	fechahora::date<='2018-12-31'
group by cveproducto,
	 extract (month from fechahora )
order by 3 asc,cveproducto
