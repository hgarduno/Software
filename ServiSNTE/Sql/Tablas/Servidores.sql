create table maquinas(IdMaquina integer unique,
		      DirIp	varchar(20),
		      Puerto	integer,
		      PuertoRn  integer,
		      primary key (dirip,puerto,puertorn));
create table servidores(IdMaquina	integer references maquinas(idMaquina),
			TipoEquipo	varchar(28),
			descripcion	varchar(128),
			primary key(idMaquina,tipoequipo));
create table ServidorActivo(IdMaquina integer references maquinas(idMaquina) unique,
			    Activo integer);
