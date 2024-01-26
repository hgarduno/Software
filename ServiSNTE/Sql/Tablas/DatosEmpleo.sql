create table Empleo(IdEmpleo integer unique,
		    IdEmpresa integer references empresas(idempresa),
		    IdPersona integer references Personas(IdPersona) ,
		    primary key(IdEmpresa,IdPersona));

create table Jefes(IdEmpleo integer references Empleo(IdEmpleo),
		   IdPersona integer references Personas(IdPersona));

create table DatosEmpleo(IdEmpleo integer references empleo(IdEmpleo),
			 Antiguedad integer,
			 Puesto varchar(28),
			 Sueldo numeric(10,2),
			 FrecuenciaPago varchar(28));

create table OtrosIngresos(IdPersona integer references Personas(IdPersona),
			   Monto numeric(10,2),
			   Descripcion varchar(28));

		  
create table EmpresaGiro(IdEmpresa integer references empresas(idEmpresa) primary key,
			 Giro varchar(28));
