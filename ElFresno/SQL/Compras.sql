--select	a.RazonSocial,
--	b.Fecha,
--	c.DscProducto,
--	b.cantidad,
--	b.Precio,
--	b.Importe,
--	b.NumFactura
--	
--from	empresas as a 
--	inner join compras as b on idEmpresa=idExpendio 
--	inner join productos as c using(CveProducto)

select	a.RazonSocial,
	c.DscProducto,
	c.CveProducto,
	sum(b.Cantidad)
from	empresas as a
	inner join compras as b on idEmpresa=idExpendio
	inner join productos as c using(cveproducto)
group by a.RazonSocial,
	 c.DscProducto,
	 c.CveProducto

order by 1

