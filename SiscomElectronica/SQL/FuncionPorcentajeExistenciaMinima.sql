create or replace function PorExistenciaMinima(pfltExistencia real,
					       pfltExistenciaMin real)
		returns real as $$
declare
begin

	/*
	 * Existencia minima  100 
	   Existencia actual  x

	  ( Existencia actual )*100 /Existencia minima 
	 */

	if pfltExistenciaMin > 0
	then
	return (pfltExistencia*100)/pfltExistenciaMin;
	else
	 return -1.0;
	 end if;




end;
$$ language plpgsql;

create or replace view vporexistenciaminima
as
SELECT	porexistenciaminima((existencias.existencia+c.exbodegas),existencias.eximinima) as PorExiMinima,
	existencias.* 
from existencias inner join 
	existenciaexpendiobodegas as c on(existencias.cveproducto=c.cveproducto and 
					  existencias.idexpendio=c.idexpendio)

