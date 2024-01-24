select sum(cantidad),cveproducto
from  ventas
where cveproducto in('PUNTB/B','PUNTB/C','PUNTC/C','PUNTAOSC1') and 
	fechahora>='2013-08-01' and 
	fechahora<='2013-12-31'
group by cveproducto
order by 1 desc

;


select sum(cantidad),cveproducto
from compras 
where cveproducto in('PUNTB/B','PUNTC/C','PUNTB/C','PUNTAOSC1') and 
	fecha>='2013-08-01' and 
	fecha<='2013-12-31'
group by cveproducto
order by 1 desc

