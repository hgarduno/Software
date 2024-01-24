

create unique index indice_persona on personas(idpersona);

alter table escuelas add column idEmpresa integer references empresas;

create table PersonaNormalizada(idPersona	integer references personas(idPersona),
				Nombre		varchar(25),
				APaterno	varchar(25),
				AMaterno	varchar(25),
				unique(Nombre,APaterno,AMaterno)
				);


create table ClienteExpendio(
		idPersona integer references personas(idPersona),
		idEmpresa integer references empresas);

create table AlumnoEscuela(
		idPersona integer references personas(idPersona),
		idEscuela integer references escuelas(idEscuela));


create table GrupoAlumno(
		idPersona integer references personas(idPersona),
		Grupo varchar(25));

create table Sueldos(
		idPersona integer references personas(idPersona),
		Sueldo	   numeric(10,2));
create table HistoricoSueldos(
		idPersona  integer references personas(idpersona),
		fecha	   date,
		sueldo	   numeric(10,2));
