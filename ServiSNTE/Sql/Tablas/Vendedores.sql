create table Vendedores(IdVendedor integer unique,
			ClaveVendedor varchar(20) unique,
			Abreviatura varchar(15));

create table PersonaVendedor(IdVendedor integer references Vendedores(IdVendedor),
			IdPersona integer references Personas(IdPersona));

Create table TelefonoVendedor(IdVendedor integer references Vendedores(IdVendedor),
			      IdTelefono integer references Telefonos(IdTelefono));

create table TiendaVendedor(IdVendedor integer references Vendedores(IdVendedor),
			    IdTienda integer references Tiendas(IdTienda));

create table DireccionVendedor(IdVendedor integer references Vendedores(IdVendedor),
			       IdDireccion integer references Direcciones(IdDireccion));

create table EstatusVendedor(IdVendedor integer references Vendedores(IdVendedor),
			       IdEstatus integer references Estatus(IdEstatus));

