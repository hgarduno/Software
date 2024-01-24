--- Miercoles 9 Febrero 2008
--- Queretaro

--- En esta tabla se almacenara la relacion entre
--- el perfil y la persona


--- Miercoles 19 de marzo 2008 Tepotzotlan Mexico
-- Antes de ejecutar este script se debera correr el que
-- crea las tablas del sistema de tiendas4

alter table perfiles add  constraint uni_perfil unique(idperfil);

create table PersonaPerfil(
		IdPersona	integer references Personas(IdPersona),
		IdPerfil	integer references Perfiles(idPerfil));	


create table Adicionales(
		idPersona	integer references Personas(IdPersona),
		RFC		varchar(15));


create table Servicios(
		idServicio	integer unique,
		Clave		varchar(30) primary key,
		Descripcion	varchar(150));


create table ServicioMedico(
		idPersona	integer references personas(idPersona),
		idServicio	integer unique,
		Clave		varchar(30),
		Descripcion	varchar(150),
		primary key(idPersona,Clave));

-- En esta tabla se almacenara la informacion de los
-- tipos de precios para los servicios generales y 
-- productos de la clinica



-- Jueves 21 de Febrero
-- Para el manejo de la farmacia se realiza la integracion
-- completa del sistema SiscomTiendas4 al programa de las clinicas
-- Para esto todo lo relacionado a los precios se debera tomar 
-- del sistema de tiendas por lo que la base de datos y lo refe-
-- rente a los precios es en la tabla Precio por lo que 
-- eliminaremos TipoPrecio, y antes de correr el scrip que
-- genera la base de datos de las clinicas se debera correr
-- el scrip para generar las tablas del sistema Tiendas4

--create table TipoPrecio(
--		idPrecio	integer unique,
--		Nombre		varchar(30) primary key,
--		Descripcion	varchar(150));

-- Se almacena la informacion de los distintos
-- precios que un medico podra manejar para los
-- servicios que brinde a los pacientes

create table PreciosServicio(
		idServicio	integer references Servicios(idServicio),
		idPrecio	integer references Precios(idPrecio),
		Precio		numeric(10,2),
		primary key(idServicio,IdPrecio));

create table PrecioServicioMedico(
		idServicio	integer references ServicioMedico(idServicio),
		idPrecio	integer references Precios(idPrecio),
		idPersona	integer references personas(idPersona),
		Precio numeric(10,2),
		primary key(idServicio,IdPrecio,IdPersona));

--Vista que se encarga de realizar el producto de los
--servicios y tipos de precio, esto se requiere para 
--realizar la insercion a la tabla de preciosservicio de
--los servicios que se registran y que no tiene precio


create or replace view TipoPrecioServicios as
select idprecio,idservicio
from servicios,precios ;

--Vista que se encarga de realizar el producto de los
-- servicios del medico y los tipos de precio que en
-- en la clinica se ofrecen

create or replace view TipoPrecioServiciosMedico as
select idprecio,idservicio,idpersona
from servicioMedico,precios ;


create table PerfilServicioMedico(
		idServicio	integer,
		idMedico	integer references personas(idpersona),
		primary key(idServicio,idMedico));

-- Para el inicio del proceso de desarrollo
-- del modulo de recepcion se requiere registrar
-- el perfil de paciente,
-- Para todo el proceso se debera considerar que
-- el idPerfil=2 es para los pacientes

insert into perfiles values(2,1,'Paciente','Paciente');
--insert into perfiles values(3,1,'Medicos','Atiende a los pacientes');

create table EstadoConsulta(
		idEstado	integer unique,
		Estado		varchar(30),
		primary key(Estado));

insert into EstadoConsulta values(1,'En Espera');
insert into EstadoConsulta values(2,'En Consulta');
insert into EstadoConsulta values(3,'Cobrada');
insert into EstadoConsulta values(4,'Revisada');
insert into EstadoConsulta values(5,'Consulta Expediente');
insert into EstadoConsulta values(6,'Cancelada');
insert into EstadoConsulta values(7,'Terminada');
insert into EstadoConsulta values(8,'Hospitalizado');

create table Consulta(
		idConsulta	integer unique,
		idMedico	integer references Personas(idPersona),
		idEmpleado	integer references Personas(idPersona),
		idPaciente	integer references Personas(idPersona),
		Fecha		timestamp,
		idEstado	integer references EstadoConsulta(idEstado)
		);
-- En esta tabla, se almacenara la forma en la que
-- va cambiando de estado la consulta, se guarda quien realizo
-- el cambio de estado, la fecha hora en que se realizo etc.
-- En la tabla Consulta, solo se actualiza el ultimo estado, pero 
-- el historial de estados se almacenara en esta tabla
create table EvolucionConsulta(
		idConsulta	integer references Consulta(idConsulta),
		idEmpleado	integer references Personas(idPersona),
		Fecha		timestamp,
		idEstado	integer references EstadoConsulta(idEstado));
create table Recetas(
		idConsulta	integer references Consulta(idConsulta),
		Fecha		timestamp,
		Folio		varchar(25),
		Receta		text,
		primary key (idConsulta,folio));
create table Expediente(
		idConsulta	integer references Consulta(idConsulta),
		Fecha		timestamp,
		Observaciones	text,
		primary key(idConsulta));


create table MaterialServicioConsulta(
		idConsulta	integer references Consulta(idConsulta),
		idSerProd	integer,
		Precio		numeric(10,2),
		Cantidad	numeric(10,2),
		Importe		numeric(10,2));

-- Se requiere para el proceso de hospitalizacion, llevar el control
-- de que material y/o servicio brinda al paciente hospitalizado.
-- Es necesario saber quien lo registro asi como la fecha, en la 
-- cual se dio este proceso

alter table MaterialServicioConsulta 
      add idPrecio integer references Precios(IdPrecio);

alter table MaterialServicioConsulta  
      add constraint llave_idConsulta 
      primary key(idConsulta,idSerProd,idPrecio);

create table RegistroProductoServicio(
		idConsulta 	integer,
		idSerProd	integer,
		idPrecio	integer,
		idEmpleado	integer references Personas(IdPersona),
		Fecha		timestamp,
		Cantidad 	integer,
		foreign key (idConsulta,idSerprod,idPrecio) 
			references MaterialServicioConsulta(idConsulta,
							    idSerProd,
							    idPrecio));


------ Se requiere agregar la columna idPrecio MaterialServicioConsulta
------ Modificacion realizada 11 De Junio del 2008 Queretaro
------


-- por la misma razon antes mencionada se cambia la llave primaria, a la cual
-- se debera anexar el campo idPrecio.

ALTER TABLE registroproductoservicio 
      DROP constraint registroproductoservicio_idconsulta_fkey;
ALTER TABLE materialservicioconsulta 
      drop constraint llave_idconsulta;

alter table MaterialServicioConsulta  
	    add constraint llave_idConsulta 
	    primary key(idConsulta,idSerProd,idPrecio);

alter table registroproductoservicio 
      add Idprecio integer references Precios(idprecio);
alter table registroproductoservicio 
      add constraint  registroproductoservicio_idconsulta_fkey  
      foreign key (idConsulta,idserprod,idprecio) 
      references materialservicioconsulta(idConsulta,idserprod,idprecio);

--- AL momento de realizar estos cambios en un sistema con 
--- registros en estas tablas se debera iniciar la columna idPrecio con el precio general
--- antes de realizar el cambio de las llaves;


--- Despues de realizar una revision de la informacion que se pretende almacenar
--- en las tablas RegistroproductoServicio y MaterialServicioConsulta, se concluye
--- que es mejor anexar las columnas de Fecha, IdEmpleado a la tabla De MaterialServicioConsulta
--- ya que practicamente todas las operaciones de costos se realizan sobre esta tabla y 
--- la informacion de registroProductoServicio no se usa
--------------------------





-- Se necesita modificar la estrategia del control de la informacion
-- del material que se utilizara en el proceso de hospitalizacion.
-- Para lo que se crea la siguiente tabla.

create table Hospitalizacion(
		IdConsulta	integer references Consulta(IdConsulta),
		IdSerProd	integer,
		Precio		numeric(10,2),
		Cantidad	numeric(10,2),
		Importe		numeric(10,2),
		IdPrecio	integer references Precios(idprecio),
		Fecha 		timestamp,
		IdEmpleado	integer references Personas(idPersona));
