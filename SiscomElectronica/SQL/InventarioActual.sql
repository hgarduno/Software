select cveproducto,
	cveproveedor,
	razonsocial::varchar(20),
	existencia,
	exbodegas
from productos as a inner join 
     existenciaexpendiobodegas as b using(cveproducto)  left outer join
     clavesproveedores as c using(cveproducto) left outer join
     empresas as d using(idempresa)
order by cveproducto
