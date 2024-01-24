select sum(importe),
	nombre
from ventas as a inner join 
     escuelaorden as b using (idventa) inner join
     escuelas as c using(idescuela)
where fechahora::date='2013-08-17'
group by nombre
order by 1 desc

