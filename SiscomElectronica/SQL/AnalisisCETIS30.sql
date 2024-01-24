--  Productos Comprados por alumnos de CETIS 30

--select distinct cveproducto,precio
--from escuelaorden as a inner join
--	ventas as b using(idventa)
--where idescuela=1285146164 and 
--	fechahora::date>='2013-01-01' and 
--	fechahora::date<='2013-12-31' and 
--	a.idexpendio=-1165857915
--order by cveproducto

--   Importe ventas a estudiantes CETIS 30


--select sum(importe)
--from escuelaorden as a inner join
--	ventas as b using(idventa) 
--
--where idescuela=1285146164 and 
--	fechahora::date>='2013-01-01' and 
--	fechahora::date<='2013-12-31' and 
--	a.idexpendio=-1165857915

--  Ganancia En CETIS 30

--select sum((precio-costopromedioproducto(cveproducto,
--			     '2013-01-01',
--			     '2013-12-31'))*cantidad)
--from escuelaorden as a inner join
--	ventas as b using(idventa) 
--where idescuela=1285146164 and 
--	fechahora::date>='2013-01-01' and 
--	fechahora::date<='2013-12-31' and 
--	a.idexpendio=-1165857915  
--group by cveproducto
--order by cveproducto


-- Ordenes vendidas a estudiantes de CETIS 30

select count(*)
from escuelaorden
where idescuela=1285146164 and 
	idexpendio=-1165857915 and 
	fecha::date>='2013-01-01' and 
	fecha::date<='2013-12-31'
;

-- Ordenes vendidas a estudiantes de CETIS 30 por fecha

--select count(*),fecha::date
--from escuelaorden
--where idescuela=1285146164 and 
--	idexpendio=-1165857915 and 
--	fecha::date>='2013-01-01' and 
--	fecha::date<='2013-12-31'
--group by fecha::date
--order by 1 desc
