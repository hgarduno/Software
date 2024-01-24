insert into PasoPreciosExistencia(
select cveproducto,
	dscproducto,
	existencia+exbodegas as existencia,
	precio
from productos as a inner join
     existenciaexpendiobodegas as b using(cveproducto) inner join
     precios as c using(cveproducto)
where c.idpersona=1153257207  
order by cveproducto)
