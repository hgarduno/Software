create table Objeto(idObjeto integer primary key,
		    NmbClase varchar(30));


create table Propiedades(idObjeto     integer references objeto(idObjeto),
			 idPropiedad  integer,
			 NmbPropiedad varchar(30),
		         primary key(idObjeto,idPropiedad));




create table aplicaciones(idAplicacion integer primary key,
			  NmbAplicacion varchar(50),
			  DscAplicacion varchar(256),
			  DirArchivosQT varchar(256));

create table Perfiles(idPerfil integer ,
		      idAplicacion integer references aplicaciones(idAplicacion),
		      NmbPerfil varchar(30),
		      DscPerfil varchar(128),
		      primary key(idAplicacion,NmbPerfil));


create table Pantalla(idPantalla          integer primary key,
		      idAplicacion        integer references aplicaciones(idAplicacion), 
		      NmbClase            varchar(30),
		      Archivo             varchar(30));
-- Se debe considerar incorporar las propiedades de la pantalla aqui 
-- es decir, caption etc.

create table ObjetosXPantalla(idPantalla         integer references pantalla(idPantalla),
			      idObjeto           integer references Objeto(idObjeto),
		      	      idPerfil           integer ,
			      idPropiedad        integer ,
			      ValorPropiedad     varchar(256));

--
--		

create table Usuarios(idUsuario integer primary key,
		      idAplicacion integer references aplicaciones(idAplicacion),
		      idPerfil integer ,
		      NmbUsuario varchar(30),
		      APaterno varchar(30),
		      AMaterno varchar(30));

create table Firmas(idUsuario integer references usuarios(idUsuario),
		    Firma   varchar(30) not null,
		    password varchar(30) not null);

