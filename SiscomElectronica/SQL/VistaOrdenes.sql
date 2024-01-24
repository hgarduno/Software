create or replace view sqlordenes
as
select count(idventa) ,
       cast(fechahora as date),
       idexpendio,
       edoventa
from  ventas
group by idventa,
         cast(fechahora as date),
	 idexpendio,
	 edoventa

