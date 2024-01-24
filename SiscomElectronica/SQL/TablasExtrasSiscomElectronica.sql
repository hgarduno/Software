drop table DetallePractica;
drop table Practicas;
drop table Materias;
drop table Escuelas;

create table Escuelas(idEscuela integer primary key,
		      Nombre varchar(256));

create table Materias(idEscuela integer references Escuelas(idEscuela),
		      idMateria integer primary key,
		      Nombre varchar(256));


create table Practicas(idPractica integer primary key,
		       idMateria  integer references Materias(idMateria),
		       Nombre varchar(256));

create table DetallePractica(idPractica integer references Practicas(idPractica),
			     CveProducto varchar(25) references productos(CveProducto),
			     Cantidad numeric(7,2));


create table ClienteFrecuente(idDatoClienteF 	integer,
			      NumDias 		integer,
			      LimiteInferior	numeric(7,2),
			      LimiteSuperior	numeric(7,2),
			      Descuento		numeric(7,2),
			      idAutorizo	integer, 
			      idExpendio	integer,
			      primary key(LimiteInferior,LimiteSuperior,Descuento));

create table Inventario(CveProducto	varchar(25) references productos(CveProducto),
			Cantidad	numeric(7,2),
			idResponsable 	integer,
			idExpendio	integer,
			FechaRegistro	date,
			Hora		time,
			primary key (CveProducto,FechaRegistro));

create table CorteExistencia(
			CveProducto varchar(25) references productos(CveProducto),
			FechaHoraCorte timestamp without time zone,
			Existencia numeric(7,2)
			);
create table TransfiereMaterial(
			FechaHora timestamp without time zone,
			IdEmpresaOrigen integer ,
			IdEmpresaDestino integer,
			CveProducto varchar(25) references productos(CveProducto),
			Cantidad numeric(7,2),
			IdEmpleado integer);

create table Expendios(
			idEmpresa	integer references empresas(idEmpresa),
			PtoComAD		integer,
			DirIpSvrAD	varchar(30),
			BaseDatos       varchar(128));
