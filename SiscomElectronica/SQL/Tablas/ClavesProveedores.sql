create table ClavesProveedores(IdEmpresa integer references Empresas(IdEmpresa),
			       CveProveedor varchar(50),
			       CveProducto  varchar(25),
			       Descripcion text,
			       primary key(IdEmpresa,CveProducto));
