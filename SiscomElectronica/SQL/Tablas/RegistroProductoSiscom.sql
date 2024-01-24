create table CompraProductosSiscom(IdCompra integer primary key,
	        		   Fecha date);

create table ProductosSiscomComprados(
		IdCompra integer references CompraProductosSiscom(IdCompra),
		IdProducto integer references ProductoPorTipoProducto(idProducto) ,
		cantidad float,
		unique(IdCompra,IdProducto));

create table DetalleCompraProductoSiscom(
			IdCompra integer,
			IdProducto integer,
			CveProducto varchar(50) references Productos(CveProducto),
			Cantidad float,
			foreign key(IdCompra,IdProducto) references ProductosSiscomComprados(IdCompra,IdProducto));



