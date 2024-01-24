create table AlumnoInscritoCurso(
			IdPersona	integer references personas(idPersona),
			IdCurso		integer references cursos(idCurso),
			Fecha		date,
			Hora		time,
			IdEstatus 	integer,
			Costo		numeric(7,2));
