select cast(fechahora as time) as hora,
	importe,
	idventa
from ventas
where cast(fechahora as date)>='2007-01-29' 
order by fechahora
