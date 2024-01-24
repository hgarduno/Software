create table AlumnoServicio(
		idRegistroServicio	integer	unique,
		IdServicio		integer,
		IdPersona		integer references Personas(IdPersona),
		Comentarios		text,
		HoraEntrada		time,
		HoraSalida		time);
		
