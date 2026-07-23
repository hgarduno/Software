select *
from importeorden as a  left outer join
	pagotransferencia as b using(idventa) left outer join
	pagotarjeta as c using(idventa)	left outer join 
	pagacon as d using(idventa) left outer join 
	pagocombinado as e using(idventa)
where fecha::date='2026-06-29';
	
