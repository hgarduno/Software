create table DatosNacimiento(IdPersona integer references personas(IdPersona) primary key,
			     Curp varchar(20),
			     Estado	varchar(100),
			     Pais	varchar(20),
			     Sexo	varchar(12),
			     Fecha	date,
			     Nacionalidad varchar(20));

create table Identificacion(IdPersona	integer references personas(IdPersona) primary key,
			    Identificacion	varchar(20),
			    NoIdentificacion	varchar(20));


create table OtrosDatosPersonales(IdPersona integer references personas(IdPersona) primary key,
				  Ocupacion	varchar(20),
				  EstadoCivil	varchar(20),
				  Edad		integer);

