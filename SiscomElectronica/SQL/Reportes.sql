select  extract(mon from fechahora::date) as Mes,
	cveproducto,
	sum(cantidad) as ventas
from ventas 
where fechahora>='2018-01-01' and 
	fechahora<='2018-12-31'
group by mes,
	cveproducto
order by mes,
	ventas desc,
	cveproducto
	 

