create table Existencia(IdProducto integer references productos(IdProducto),
			Existencia integer);
	

create table MotivosInventario(IdMotivoInventario integer unique,
			       Motivo	varchar(128));

create table Inventario(IdInventario integer unique,
			Fecha	date,
			IdMotivoInventario	integer references MotivosInventario(IdMotivoInventario));

create table DetalleInventario(IdInventario	integer references Inventario(IdInventario),
			       IdProducto 	integer references Productos(IdProducto),
			       Cantidad 	integer);

create table DetalleInventarioPaso(IdInventario	integer references Inventario(IdInventario),
			       IdProducto 	integer references Productos(IdProducto),
			       Cantidad 	integer);
			
