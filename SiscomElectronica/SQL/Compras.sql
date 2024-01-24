select sum(cantidad),
	cveproducto,
	razonsocial,
	precio
from	compras inner join 
	empresas on idempresa=proveedor
where razonsocial!='Inventario' and fecha::date>='2018-01-01'
group by cveproducto,
	razonsocial,
	precio
order by cveproducto,precio
