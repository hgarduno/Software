create table ActualizaSistema(
		IdActualizacion integer unique,
		Aplicar	integer,
		Fecha timestamp without time zone);
create table ArchivoActualizacion(
		IdActualizacion integer references ActualizaSistema(IdActualizacion),
		Arquitectura	varchar(20),
		Archivo	 varchar(512));

create table EstadosActualizacion(IdEstado integer unique,
				  Descripcion varchar(128));

create table MaquinasActualizadas(
	       IdActualizacion integer references ActualizaSistema(IdActualizacion),
	       IdMaquina integer references maquinas(idmaquina),
	       IdEstado	integer references EstadosActualizacion(IdEstado));
