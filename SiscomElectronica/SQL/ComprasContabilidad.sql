select b.fecha::date,
       b.cantidad,
       b.cveproducto,
       b.precio,
       b.preciosiniva,
       0 as cuantostomo,
       b.numfactura
from facturascompras as a inner join
      compras as b using(numfactura) 
--where b.cveproducto in(select cveproducto
--		       from ordenesfacturadas inner join
--		            ventas using (idventa))

order by cveproducto,
	 fecha,
	 precio
