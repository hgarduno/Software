create table Empresas(IdEmpresa 	integer unique,
		      RazonSocial	varchar(128),
		      RFC		varchar(15));

create table Proveedores(IdEmpresa integer references Empresas(IdEmpresa) unique);

create table Personas(IdPersona integer unique,
		      Nombre	varchar(28),
		      APaterno	varchar(28),
		      AMaterno	varchar(28),
		      RFC	varchar(15),
		      primary key (Nombre,APaterno));

create table ContactosEmpresa(IdEmpresa integer references Empresas(IdEmpresa),
			     IdPersona integer references Personas(IdPersona));

create table TelefonosEmpresa(IdEmpresa  integer references Empresas(IdEmpresa),
			     IdTelefono integer references Telefonos(IdTelefono),
			     Fecha 	 date);


create table DescuentosEmpresa(IdDescuentoEmpresa integer unique,
			       IdEmpresa	integer references Empresas(IdEmpresa),
			       d1 numeric(4,2),
			       d2 numeric(4,2),
			       d3 numeric(4,2),
			       d4 numeric(4,2),
			       Fecha	     date,
			       primary key(IdEmpresa,Fecha));

create table UltimoDescuentoEmpresa(IdEmpresa integer references Empresas(IdEmpresa),
				    IdDescuentoEmpresa integer references DescuentosEmpresa(IdDescuentoEmpresa));
				    


create table DireccionesEmpresa(IdEmpresa  integer references Empresas(IdEmpresa),
			     IdDireccion integer,
			     Fecha	 date);

create table PlazoEmpresa(IdEmpresa 	integer references Empresas(IdEmpresa),
		    	   Plazo	integer);

create table IvaEmpresa(IdEmpresa 	integer references Empresas(IdEmpresa),
		    	Iva integer);

create table EstatusEmpresa(IdEmpresa integer references Empresas(IdEmpresa),
			    IdEstatus integer references Estatus(IdEstatus));

create table ContactoEmpresa(IdEmpresa integer references Empresas(IdEmpresa),
			     Contacto varchar(128));
