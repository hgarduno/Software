create table Almacenistas(IdAlmacenista integer unique,
		      Clave    integer,
		      Abreviatura varchar(30));

create table NombreAlmacenista(IdAlmacenista integer references Almacenistas(IdAlmacenista),
			  IdPersona integer references Personas(IdPErsona));

create table DireccionAlmacenista(IdAlmacenista integer references Almacenistas(IdAlmacenista),
			     IdDireccion integer references Direcciones(IdDireccion));

create table TelefonoAlmacenista(IdAlmacenista integer references Almacenistas(IdAlmacenista),
			    IdTelefono integer references Telefonos(IdTelefono));

create table EstatusAlmacenista(IdAlmacenista integer references Almacenistas(IdAlmacenista),
			   IdEstaus integer references Estatus(IdEstatus));	
