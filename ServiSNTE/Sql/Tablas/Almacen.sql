create table Almacen(IdAlmacen integer unique,
		            Nombre	varchar(56),
		            Descripcion varchar(128));

create table InventarioAlmacen(IdInventario integer unique,
			        Fecha	date,
			        IdMotivoInventario	integer 
			        references MotivosInventario(IdMotivoInventario));

create table DetalleInventarioAlmacen(IdInventario integer references 
				    InventarioAlmacen(IdInventario),
			        IdProducto 	integer references Productos(IdProducto),
			        Cantidad 	integer);

create table DetalleInventarioAlmacenPaso(IdInventario	integer references InventarioAlmacen(IdInventario),
			        IdProducto 	integer references Productos(IdProducto),
			        Cantidad 	integer);

create table ExistenciaAlmacen(IdProducto integer references Productos(IdProducto),
			        Existencia integer);


