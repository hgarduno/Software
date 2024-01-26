create table Choferes(IdChofer integer unique,
		      Clave    integer,
		      Abreviatura varchar(30));

create table NombreChofer(IdChofer integer references Choferes(IdChofer),
			  IdPersona integer references Personas(IdPErsona));

create table DireccionChofer(IdChofer integer references Choferes(IdChofer),
			     IdDireccion integer references Direcciones(IdDireccion));

create table TelefonoChofer(IdChofer integer references Choferes(IdChofer),
			    IdTelefono integer references Telefonos(IdTelefono));

create table EstatusChofer(IdChofer integer references Choferes(IdChofer),
			   IdEstaus integer references Estatus(IdEstatus));	
