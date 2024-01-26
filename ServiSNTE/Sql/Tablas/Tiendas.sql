create table Tiendas(IdTienda integer unique,
		     Nombre varchar(50),
		     Abreviatura varchar(15),
		     Siglas varchar(5));

create table ResponsableTienda(IdTienda integer references Tiendas(IdTienda),
			 IdPersona integer references Personas(IdPersona));

create table DireccionesTienda(IdTienda integer references Tiendas(IdTienda),
			     IdDireccion integer references Direcciones(IdDireccion));

create table TelefonosTienda(IdTienda integer references Tiendas(IdTienda),
			     IdTelefono integer references Telefonos(IdTelefono));

create table EstatusTienda(IdTienda integer references Tiendas(IdTienda),
		    IdEstatus integer references Estatus(IdEstatus));
-- Se agrega la tabla para almacenar La tienda local 
create table Tienda(IdTienda integer references Tiendas(IdTienda));
