--select	a.RazonSocial,
--	b.FechaHora,
--	c.DscProducto,
--	b.cantidad,
--	b.Precio,
--	b.Importe
--	
--from	empresas as a 
--	inner join ventas as b on idEmpresa=idExpendio 
--	inner join productos as c using(CveProducto)
----where  idEmpresa=-1154974316;
--order by a.RazonSocial
--
--

select	a.RazonSocial,
	c.DscProducto,
	c.CveProducto,
	sum(b.Cantidad)
from	empresas as a
	inner join ventas as b on idEmpresa=idExpendio
	inner join productos as c using(CveProducto)
group by a.RazonSocial,
	 c.dscProducto,
	 c.CveProducto
order by a.RazonSocial
	
	
