select sum(cantidad) as totalventas,
	cveproducto
from ventas
where fechahora::date>='2024-08-01' and 
      fechahora::date<='2025-01-31' and
      edoventa in(0,2,4,6,7,11)		and
      cveproducto in ('ZAPATAPUNTA-ROJA')
group by cveproducto
      			
