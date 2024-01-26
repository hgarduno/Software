create table TiposPersona(IdTipoPersona integer unique,
			 TipoPersona	varchar(28) primary key,
			 Descripcion	varchar(128));

create table PersonasPorTipoPersona(
			IdPersona integer references personas(IdPersona),
			IdTipoPersona integer references TiposPersona(IdTipoPersona));

create table Menus(IdMenu	integer unique,
		   Nombre	varchar(50),
		   Modulo	varchar(50),
		   Funcion	varchar(50));

create table PopupMenu(IdMenu	integer unique references Menus(IdMenu));

create table PopupMenuMenu(IdMenu integer references PopupMenu(IdMenu),
			   IdMenuOpcion  integer references Menus(IdMenu));

create table PropiedadesMenu(IdPropiedad	integer unique,
			     Nombre		varchar(25) primary key);


create table MenusPropiedades(IdMenu integer references Menus(IdMenu),
			      IdTipoPersona integer references TiposPersona(IdTipoPersona),
			      IdPropiedad integer references PropiedadesMenu(IdPropiedad),
			      Valor	varchar(50),
			      primary key(IdMenu,IdTipoPersona,IdPropiedad));


create table UsuariosSistema(IdPersona integer unique references Personas(IdPersona));
create table FirmasSistema(IdPersona integer references UsuariosSistema(IdPersona),
			   Usuario varchar(25),
			   Password varchar(50));
