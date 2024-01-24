select sum(importe),
	idescuela,
	nombre,
	fechahora::date
from ventas  as a inner join
     escuelaorden as b using(idventa) inner join
     escuelas as c using(idescuela)
where fechahora::date>='2017-05-01' and 
	fechahora::date<='2017-05-18'
group by idescuela,
	fechahora::date,
	nombre
order by fechahora::date ,1 desc ,nombre
