create table TipoCompetencia(
				idTipoCompetencia		integer unique,
				Competencia			varchar(50),
				primary key (idTipoCompetencia,Competencia)
			    );


create table CatClase(
			idClase			integer unique,
			idTipoCompetencia 	integer references TipoCompetencia(idTipoCompetencia),	
			Clase	varchar(15),
			primary key (idClase,Clase));

create table Grupos(
			idGrupo	integer unique,
			idTipoCompetencia 	integer references TipoCompetencia(idTipoCompetencia),	
			EdadInf	integer,
			EdadSup	integer,
			Grupo	varchar(15)
			);
create table CatNivel( 	idClase integer references CatClase(idClase),
			idNivel	integer unique,
			Nivel	integer ,
			Descripcion	varchar(50),
			primary key (idNivel,Nivel));
create table Gimnasio(
			idGimnasio	integer unique,
			Nombre		varchar(75),
			primary key (Nombre));

create table Jueces(
			idPersona	integer references Personas(idPersona)

		    );

create table Entrenadores(
				idPersona	integer references Personas(idPersona) unique,
				idGimnasio	integer references Gimnasio(idGimnasio)
			 );
-- Al momento de registrar a un gimnasta en una competencia
-- se deberan actualizar los campos de entrenador, grupo, clase
-- nivel esto representara la ultima competencia en la que el 
-- gimnasta compitio.


create table Gimnasta(
			idPersona	integer references Personas(idPersona) unique,
			idGimnasio	integer	references Gimnasio(idGimnasio),
			idEntrenador	integer	references Personas(idPersona),
			idGrupo		integer references Grupos(idGrupo),
			idClase		integer references CatClase(idClase),
			idNivel		integer references CatNivel(idNivel),
			FechaNac	date);

create table Requerimiento(
				idRequerimiento	integer unique,
				Requerimiento	varchar(50),
				primary key (Requerimiento));

create table Obligatorios(
				idClase integer references CatClase(idClase),
				idNivel	integer references CatNivel(idNivel),
				idRequerimiento integer references Requerimiento(idRequerimiento));

create table Aparatos(
			idAparato	integer unique,
			Aparato		varchar(50),
			Descripcion	varchar(150),
			Orden		integer,
			primary key (idAparato,Aparato)
			);
create table AparatosCompetencia(
		idTipoCompetencia	integer references TipoCompetencia(idTipoCompetencia),
		idAparato	integer references Aparatos(idAparato) 
			);


create table Competencia(
		fecha			date,
		idCompetencia		integer unique,
		idTipoCompetencia 	integer references TipoCompetencia(idTipoCompetencia),
		Nombre		varchar(150),
		primary key (Nombre,fecha)
			);

create table DetalleCompetencia(
				idCompetencia integer references Competencia(idCompetencia),
				Descripcion	text,
				Bases		text,
				FecIniInsc	date,
				FecFinInsc	date
				);

create table Compitiendo(
				idCompetencia	integer references Competencia(idCompetencia),
				idGimnasta	integer references Gimnasta(idPersona),
				idGimnasioPQC	integer references Gimnasio(idGimnasio),
				idClase		integer references CatClase(idClase),
				idNivel		integer references CatNivel(idNivel),
				idGrupo		integer references Grupos(idGrupo),
				idEntrenador	integer references Entrenadores(idPersona),
				fechaRegistro	timestamp without time zone,
				primary key (idCompetencia,idGimnasta));


create table Calificaciones(
	idCompetencia			integer,
	idAparato			integer references Aparatos(idAparato),
	idGimnasta			integer,
	idJuezDificultad		integer,
	idJuezEjecucion			integer,
	Dificultad			numeric(5,3),
	Ejecucion			numeric(5,3),
	NotaFinal			numeric(5,3),
	FOREIGN KEY (idCompetencia, idGimnasta) REFERENCES Compitiendo,
	primary key (idCompetencia,idGimnasta,idAparato,idJuezDificultad,idJuezEjecucion));

create table Rondas(
		idRonda		integer unique,
		NmbRonda	varchar(50),
		idCompetencia	integer,
		primary key(NmbRonda,idCompetencia)
		);

create table DetalleRonda(
		idRonda		integer references Rondas(idRonda),
		idGimnasta	integer,
		idAparato	integer references Aparatos(idAparato),
		primary key (idGimnasta,idAparato));



