select distinct '' as CveProducto,
	'' as DscProducto,
	0 as unidad,
	0 as idfamilia,
	fechahoracorte,
	0 as existencia,
	idexpendio,
	0 as cantidadvendida,
	0 as inventario,
	0 as cuadra

from corteexistencia inner join productos using(CveProducto)
where idExpendio=-1155218065;

