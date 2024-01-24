--create or replace view ordenespordia
--as
--select distinct chrcveVenta ,
--       cast(dtefechaventa as date) as fecha
--from venta;

select count (chrcveventa) ,
       fecha
from ordenespordia
where fecha>='2006-01-01' and
      fecha<='2006-12-30'
group by fecha
order by fecha
