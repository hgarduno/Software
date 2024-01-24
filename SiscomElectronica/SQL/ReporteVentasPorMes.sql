select sum(cantidad),
	cveproducto,
	extract(month from fechahora)
from ventas
where fechahora::date>='2023-08-28' and 
	fechahora::date<='2023-12-31' and 
	 idexpendio=-1165857915 and 
	 edoventa in(0,2)
group by cveproducto,
	extract(month from fechahora)
order by 3,1 desc 
