create table TipoProductos(IdTipoProducto integer unique,
			   Descripcion	varchar(128));

create table ProductoPorTipoProducto(CveProducto varchar(50) references Productos(CveProducto),
				     IdTipoProducto	integer references TipoProductos(IdTipoProducto),
				     IdProducto		integer unique,
				     primary key(CveProducto,IdTipoProducto));

create table DefinicionTiposProducto(IdProducto integer references ProductoPorTipoProducto(IdProducto),
				     CveProducto varchar(50) references Productos(CveProducto),
		 		     Cantidad	integer);

create table VentasPorTipoProducto(IdVenta integer,
				   IdProducto integer references ProductoPorTipoProducto(IdProducto),
				   Cantidad numeric(10,2),
				   Importe	numeric(10,2));

alter table ventas add column idproducto integer references ProductoPorTipoProducto(IdProducto);

