-- El centro de atencion debera tener una entrada en la 
-- tabla de direcciones (IdPersona)
---

drop table EstacionCentro;

drop table Asesores;
drop table Estaciones;
drop table CentroAtencion;

---- Por alguna extrana razon la tabla de ventas no tenia 
---  una columna en donde se almacenara el idCliente :)

alter table ventas add column idCliente integer references personas(idpersona);
create table CentroAtencion(
		idCentro	integer unique,
		Nombre		varchar(120),
		idPersona	integer);


create table Estaciones(
		idEstacion	integer unique,
		Estado		integer,
		Puerto		integer,
		Direccion	varchar(20),
		primary key (Puerto,Direccion));


create table Asesores(
		idEstacion	integer references Estaciones(idEstacion),
		idPersona	integer references Personas(idPersona));

create table EstacionCentro(
		idCentro	integer references CentroAtencion(idCentro),
		idEstacion	integer references Estaciones(idEstacion));


create table Pedidos(
		idVenta		integer references Ventas(idVenta),
		fecha		timestamp,
		idEntrego	integer references personas (idPersona),
		Observaciones	text);

alter table asesores add constraint unique_Asesor unique(idPersona);

create table Seguimiento(
		idCliente 	integer references Personas(idPersona),
		idAsesor	integer references Asesores(idPersona),
		Fecha		timestamp,
		Comentario	text,
		idPedido	integer references Ventas(idVenta));

insert into Direcciones(calle,referencias,idasentamiento,idpersona)
	    values('Autopista Mexico Qro KM 43',
	    	   'Caseta de cobro Tepotzotlan Mexico',
		   37328,
		   20);

insert into CentroAtencion(idCentro,Nombre,IdPersona)
	    values(0,'Gas Satelite Tepotzotlan',20);

insert into Estaciones(idEstacion,Estado,Puerto,Direccion)
	    values(0,0,5666,'127.0.0.1');

insert into Estaciones(idEstacion,Estado,Puerto,Direccion)
	    values(1,0,5667,'127.0.0.1');
insert into Estaciones(idEstacion,Estado,Puerto,Direccion)
	    values(2,0,5668,'127.0.0.1');


insert into Asesores(idEstacion,idPersona)
	    values(0,1);


insert into EstacionCentro(idCentro,idEstacion)
	    values(0,0);


insert into Seguimiento(idCliente,idAsesor,Fecha,Comentario,idPedido)
	    values(1205951827,
	    	   1,
		   '2008-09-21 0:20',
		   'Pidio algo para que se lo llevaran',
		   1205974180);


insert into Pedidos(idventa,fecha,identrego,observaciones) 
	    values (1205951988,'2008-09-21 12:00',1221821555,'Se entrego luego luego');
		
