create or replace view ExistenciaExpendioBodegas as 
select 
	a.cveproducto,
	a.idexpendio,
	a.existencia,
       sum(b.existencia) as exbodegas
from existencias as a left outer  join materialbodega as b using(cveproducto)
group by a.existencia,
	 a.cveproducto,
	 a.idexpendio

