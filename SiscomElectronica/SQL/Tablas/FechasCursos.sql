create table FechasCursos(IdCurso integer references Cursos(IdCurso),
			  Fecha	date,
			  Duracion	integer,
			  Cupo		integer,
			  Disponibles	integer);
