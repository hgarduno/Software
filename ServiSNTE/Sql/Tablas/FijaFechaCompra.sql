create table FijaFechaCompra(idProveedor integer references proveedores(IdEmpresa),
			     FechaHoy date,
			     FechaCompra	date,
			     primary key(IdProveedor,FechaCompra));
