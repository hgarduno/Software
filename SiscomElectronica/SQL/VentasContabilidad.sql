
select b.fechahora::date,
	b.cantidad,
	b.cveproducto,
	b.precio
from ordenesfacturadas as a
	inner join ventas as b using(idventa)
where b.cveproducto in (select cveproducto
			 from facturascompras inner join
			      compras using(numfactura))
order by cveproducto,
	 fechahora,
	 precio
