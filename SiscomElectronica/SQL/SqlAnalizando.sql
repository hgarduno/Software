--explain analyze
--select a.*,
--               c.idtipoproducto,
--               b.importe as importeorden, 
--               d.existencia,
--               a.edoventa as idtipoorden,
--               f.nombre as escuela,
--               f.idescuela,
--               h.*
--        from ventas as a left outer join 
--             importeorden as b using(idventa) left outer join
--             productoportipoproducto as c using(cveproducto) inner join
--             existencias as d using(cveproducto) inner join
--             escuelaorden as e using(idventa)    inner join 
--             escuelas as f using(idescuela)      inner join
--             ordencliente as g using(idventa)    inner join
--             personas as h using(idpersona)
--              where idventa in(select distinct idventa
--                           from ventas 
--                           where edoventa=1 and 
--                                 fechahora::date>='2022-10-09' and 
--                                 fechahora::date<='2022-10-09')
--        order by a.fechahora desc,
--                 a.idconsecutivo asc

--EXPLAIN ANALYZE
-- select a.*,
--               c.idtipoproducto,
--               b.importe as importeorden, 
--               d.existencia,
--               a.edoventa as idtipoorden,
--               f.nombre as escuela,
--               f.idescuela,
--               h.*
--        from ventas as a left outer join 
--             importeorden as b using(idventa) left outer join
--             productoportipoproducto as c using(cveproducto) inner join
--             existencias as d using(cveproducto) inner join
--             escuelaorden as e using(idventa)    inner join 
--             escuelas as f using(idescuela)      inner join
--             ordencliente as g using(idventa)    inner join
--             personas as h using(idpersona)
--	 where fechahora::date>='2022-10-09' and 
--	       fechahora::date<='2022-10-09' and 
--	       a.edoventa=1
--        order by a.fechahora desc,
--                 a.idconsecutivo asc

--select a.*,
--               c.idtipoproducto,
--               b.importe as importeorden, 
--               d.existencia,
--               a.edoventa as idtipoorden,
--               f.nombre as escuela,
--               f.idescuela,
--               h.*
--        from ventas as a left outer join 
--             importeorden as b using(idventa) left outer join
--             productoportipoproducto as c using(cveproducto) inner join
--             existencias as d using(cveproducto) inner join
--             escuelaorden as e using(idventa)    inner join 
--             escuelas as f using(idescuela)      inner join
--             ordencliente as g using(idventa)    inner join
--             personas as h using(idpersona)
--             where a.edoventa=1               and
--                fechahora::date>='2022-10-09' and 
--              fechahora::date<='2022-10-09'
--        order by a.fechahora desc,
--                 a.idconsecutivo asc
select distinct b.*
from cotizacion as b inner join
     ventas as a using (idventa)
where a.edoventa=1 and 
	fechahora::date>='2022-10-09' and 
	fechahora::date<='2022-10-09'
