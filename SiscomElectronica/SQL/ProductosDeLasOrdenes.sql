select sum(cantidad),
       cveproducto,
       precio
from ventas
where idventa in(1181142137,
		 1181147073,
		 1181700210)
group by cveProducto,
         precio,
	 idventa
order by idventa
