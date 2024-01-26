create table Productos(IdProducto integer unique,
		       NumProducto integer,
		       NombreProducto varchar(128),
		       Modelo varchar(50));
		       

create table ProductoCodigoBarras(CodigoBarras varchar(128) unique,
				  IdProducto integer references Productos(IdProducto));

create table ProductoProveedor(IdEmpresa integer references Empresas(IdEmpresa),
			       IdProducto integer references Productos(IdProducto));

create table EstatusProducto(IdProducto integer references Productos(IdPRoducto),
			     IdEstatus integer references Estatus(IdEstatus));

create table DepartamentoProducto(IdProducto integer references Productos(IdProducto),
				  IdDepartamento integer references Departamentos(IdDepartamento));

create table CostoBruto(IdCostobruto 	integer unique,
			CostoBruto 	numeric(12,2),
			CostoNeto 	numeric(12,2),
			IVA		numeric(12,2),
			Fecha		date,
			IdProducto integer references Productos(IdProducto),
			primary key(IdProducto,CostoBruto));

create table PrecioGeneral(IdPrecioGeneral 	integer unique,
			PrecioGeneral	numeric(12,2),
			PrecioSinIVA 	numeric(12,2),
			IVA		numeric(12,2),
			Fecha		date,
			IdProducto integer references Productos(IdProducto),
			primary key(IdProducto,PrecioGeneral));


create table PrecioForaneo(IdPrecioForaneo 	integer unique,
			   PrecioForaneo	numeric(12,2),
			   PrecioSinIva 	numeric(12,2),
			   IVA			numeric(12,2),
			   Fecha		date,
			   IdProducto integer references Productos(IdProducto),
			   primary key(IdProducto,PrecioForaneo));

create table DescuentoProducto(IdDescuentoProducto integer unique,
			       Descuento	numeric(5,2),
			       Fecha		date,
			       IdProducto integer references Productos(IdProducto));

create table UltimoPrecioGeneral(IdProducto integer references Productos(IdProducto),
				 IdPrecio integer references PrecioGeneral(IdPrecioGeneral));
create table UltimoPrecioForaneo(IdProducto integer references Productos(IdProducto),
				 IdPrecio integer references PrecioForaneo(IdPrecioForaneo));
create table UltimoCosto(IdProducto integer references Productos(IdProducto),
			 IdCosto integer references CostoBruto(IdCostoBruto));


