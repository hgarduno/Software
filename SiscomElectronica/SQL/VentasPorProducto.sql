select sum(cantidad),
	cveproducto
from ventas
where fechahora::date>='2010-01-01' and 
	fechahora::date<='2011-01-18'
group by cveproducto
order by 2 desc
