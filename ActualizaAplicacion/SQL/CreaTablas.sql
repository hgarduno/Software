create table Estaciones(
		DirIp varchar(15),
		PtoCom integer,
		DirTrabajo varchar(1024),
		Home varchar(256));


create table Archivos(
		Origen varchar(1024),
		Archivo varchar(1024) primary key,
		Comentario varchar(256));
		
